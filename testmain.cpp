#include <windows.h>
#include <BluetoothAPIs.h>
#include <bthsdpdef.h>
#include <setupapi.h>
#include <initguid.h>
#include <devguid.h>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <string>

#pragma comment(lib, "bthprops.lib")
#pragma comment(lib, "setupapi.lib")

// 补充缺失的常量定义
#ifndef BLUETOOTH_AUTHENTICATION_METHOD_PIN
#define BLUETOOTH_AUTHENTICATION_METHOD_PIN 0x00000001
#endif

#ifndef MAX_PIN_LENGTH
#define MAX_PIN_LENGTH 16
#endif

// 蓝牙设备信息结构体
struct BluetoothDevice {
    BLUETOOTH_DEVICE_INFO info;
    std::wstring name;
    std::wstring address;
};

// 扫描附近的蓝牙设备
std::vector<BluetoothDevice> ScanBluetoothDevices(DWORD timeout = 5000) {
    std::vector<BluetoothDevice> devices;
    HBLUETOOTH_RADIO_FIND hRadioFind = NULL;
    HANDLE hRadio = NULL;
    BLUETOOTH_FIND_RADIO_PARAMS radioParams = { sizeof(BLUETOOTH_FIND_RADIO_PARAMS) };

    // 查找本地蓝牙适配器
    hRadioFind = BluetoothFindFirstRadio(&radioParams, &hRadio);
    if (hRadioFind == NULL) {
        printf("没有找到蓝牙适配器\n");
        return devices;
    }

    do {
        BLUETOOTH_DEVICE_SEARCH_PARAMS searchParams = { sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS) };
        searchParams.hRadio = hRadio;
        searchParams.fReturnAuthenticated = TRUE;
        searchParams.fReturnRemembered = TRUE;
        searchParams.fReturnUnknown = TRUE;
        searchParams.fReturnConnected = TRUE;
        searchParams.fIssueInquiry = TRUE;

        // 修复C4244警告：将ULONG转换为UCHAR，确保值在有效范围内
        unsigned long timeoutMultiplier = static_cast<unsigned long>(timeout / 1.28);
        searchParams.cTimeoutMultiplier = static_cast<UCHAR>(timeoutMultiplier > 255 ? 255 : timeoutMultiplier);

        HBLUETOOTH_DEVICE_FIND hDeviceFind = NULL;
        BLUETOOTH_DEVICE_INFO deviceInfo = { sizeof(BLUETOOTH_DEVICE_INFO) };

        // 查找蓝牙设备
        hDeviceFind = BluetoothFindFirstDevice(&searchParams, &deviceInfo);
        if (hDeviceFind == NULL) {
            continue;
        }

        do {
            BluetoothDevice dev;
            dev.info = deviceInfo;

            // 转换设备地址为字符串
            WCHAR addrStr[20];
            swprintf_s(addrStr, L"%02X:%02X:%02X:%02X:%02X:%02X",
                deviceInfo.Address.rgBytes[5],
                deviceInfo.Address.rgBytes[4],
                deviceInfo.Address.rgBytes[3],
                deviceInfo.Address.rgBytes[2],
                deviceInfo.Address.rgBytes[1],
                deviceInfo.Address.rgBytes[0]);
            dev.address = addrStr;

            // 设备名称
            dev.name = deviceInfo.szName;

            devices.push_back(dev);

        } while (BluetoothFindNextDevice(hDeviceFind, &deviceInfo));

        BluetoothFindDeviceClose(hDeviceFind);

    } while (BluetoothFindNextRadio(hRadioFind, &hRadio));

    BluetoothFindRadioClose(hRadioFind);
    CloseHandle(hRadio);

    return devices;
}

// PIN码回调函数 (适配不同SDK版本的结构体定义)
DWORD CALLBACK BluetoothPinCallbackEx(
    PVOID pParam,
    PBLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS pAuthParams
) {
    // 检查是否需要PIN码认证
    if (pAuthParams->authenticationMethod == BLUETOOTH_AUTHENTICATION_METHOD_PIN) {
        // 此处可以显示UI让用户输入PIN码
        const char* pin = "1234"; // 示例固定PIN码，实际应改为用户输入
        ULONG pinLength = static_cast<ULONG>(strlen(pin));

        if (pinLength > MAX_PIN_LENGTH) {
            pinLength = MAX_PIN_LENGTH;
        }

        // 适配结构体成员差异，使用正确的方式设置PIN码
        if (pAuthParams->pAuthData != NULL && pAuthParams->pAuthData->cbSize >= sizeof(BLUETOOTH_AUTHENTICATION_PIN_INFO)) {
            BLUETOOTH_AUTHENTICATION_PIN_INFO* pinInfo = reinterpret_cast<BLUETOOTH_AUTHENTICATION_PIN_INFO*>(pAuthParams->pAuthData);
            memcpy(pinInfo->pin, pin, pinLength);
            pinInfo->pinLength = pinLength;
        }

        return ERROR_SUCCESS;
    }
    return ERROR_SUCCESS;
}

// 配对蓝牙设备
BOOL PairBluetoothDevice(const BLUETOOTH_DEVICE_INFO& deviceInfo) {
    BLUETOOTH_DEVICE_INFO devInfo = deviceInfo;
    devInfo.dwSize = sizeof(BLUETOOTH_DEVICE_INFO);

    HBLUETOOTH_AUTHENTICATION_REGISTRATION hReg = NULL;
    BLUETOOTH_AUTHENTICATION_REGISTRATION_INFO regInfo = { 0 };
    regInfo.dwSize = sizeof(BLUETOOTH_AUTHENTICATION_REGISTRATION_INFO);
    regInfo.deviceInfo = devInfo;

    // 注册认证回调函数
    DWORD result = BluetoothRegisterForAuthenticationEx(
        &regInfo,
        &hReg,
        (PFN_AUTHENTICATION_CALLBACK_EX)BluetoothPinCallbackEx,
        NULL
    );

    if (result != ERROR_SUCCESS) {
        printf("注册认证回调失败: 0x%08X\n", result);
        return FALSE;
    }

    // 尝试配对设备
    result = BluetoothAuthenticateDeviceEx(
        NULL,
        NULL,
        &devInfo,
        NULL,
        0
    );

    // 取消注册回调
    BluetoothUnregisterAuthentication(hReg);

    if (result == ERROR_SUCCESS) {
        printf("设备配对成功\n");
        return TRUE;
    }
    else {
        printf("设备配对失败: 0x%08X\n", result);
        return FALSE;
    }
}

int main() {
    printf("正在扫描蓝牙设备...\n");
    std::vector<BluetoothDevice> devices = ScanBluetoothDevices();

    if (devices.empty()) {
        printf("未发现任何蓝牙设备\n");
        return 0;
    }

    printf("发现 %zu 个蓝牙设备:\n", devices.size());
    for (size_t i = 0; i < devices.size(); ++i) {
        printf("%zu. %ls (%ls)\n",
            i + 1,
            devices[i].name.c_str(),
            devices[i].address.c_str());
    }

    printf("请输入要配对的设备编号 (0 退出): ");
    int choice;
    scanf_s("%d", &choice);

    if (choice < 1 || static_cast<size_t>(choice) > devices.size()) {
        printf("退出程序\n");
        return 0;
    }

    printf("正在与设备配对...\n");
    PairBluetoothDevice(devices[choice - 1].info);

    return 0;
}
