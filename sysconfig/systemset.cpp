#include "systemset.h"

#pragma comment(lib, "ole32.lib")  // COM 支持库


SystemSet* SystemSet::self = nullptr;
SystemSet* SystemSet::instance()
{
    static QMutex mutex;
    if(self == nullptr)
    {
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new SystemSet();
        }
	}
    return self;
}
void SystemSet::destroy()
{
    if (self) 
    {
        delete self;
        self = nullptr;
    }
}

SystemSet::SystemSet()
{
    // 初始化 COM 库
    if (!initializeCOM()) 
    {
	    mIsInitialized = false;
		qWarning() << "Failed to initialize COM library for audio endpoint volume.";
		return;
    }
	mIsInitialized = true;
    // 获取默认音频设备的音量控制接口
    mEndpointVolume = getDefaultAudioEndpoint();
    if (!mEndpointVolume) 
    {
        mIsInitialized = false;
        qWarning() << "Failed to get default audio endpoint volume.";
        uninitializeCOM();
        return;
	}

}
SystemSet::~SystemSet()
{
    // 释放 COM 资源
    uninitializeCOM();
}

// 初始化 COM 库
bool SystemSet::initializeCOM()
{
    if (TlsGetValue(TlsAlloc()) != nullptr)
    {
        qWarning() << "COM already initialized.";
        return true; // 如果已经初始化，则直接返回
    }
    
	// 使用 COINIT_MULTITHREADED 初始化 COM 库
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    return SUCCEEDED(hr);
}

// 释放 COM 资源
void SystemSet::uninitializeCOM()
{
    if (mEndpointVolume) 
    {
        mEndpointVolume->Release();
        mEndpointVolume = nullptr;
	}
	// 释放 COM 库
    CoUninitialize();
}

// 获取默认音频设备的音量控制接口
IAudioEndpointVolume* SystemSet::getDefaultAudioEndpoint()
{
    IMMDeviceEnumerator* deviceEnumerator = nullptr;
    IMMDevice* defaultDevice = nullptr;
    IAudioEndpointVolume* endpointVolume = nullptr;

    // 创建设备枚举器
    HRESULT hr = CoCreateInstance(
        __uuidof(MMDeviceEnumerator),
        nullptr,
        CLSCTX_INPROC_SERVER,
        __uuidof(IMMDeviceEnumerator),
        reinterpret_cast<void**>(&deviceEnumerator)
    );

    if (FAILED(hr)) return nullptr;

    // 获取默认音频渲染设备
    hr = deviceEnumerator->GetDefaultAudioEndpoint(
        eRender,                // 渲染设备（扬声器）
        eMultimedia,            // 多媒体角色
        &defaultDevice
    );

    if (FAILED(hr)) {
        deviceEnumerator->Release();
        return nullptr;
    }

    // 获取音量控制接口
    hr = defaultDevice->Activate(
        __uuidof(IAudioEndpointVolume),
        CLSCTX_INPROC_SERVER,
        nullptr,
        reinterpret_cast<void**>(&endpointVolume)
    );

    defaultDevice->Release();
    deviceEnumerator->Release();
    return endpointVolume;
}

// 设置系统音量（0.0f 到 1.0f 之间）
bool SystemSet::setVolume(float volumeLevel)
{
    if(!mIsInitialized) 
    {
        qWarning() << "SystemSet is not initialized.";
        return false;
	}
    if (volumeLevel < 0.0f) volumeLevel = 0.0f;
    if (volumeLevel > 1.0f) volumeLevel = 1.0f;

    if(mEndpointVolume == nullptr) 
    {
        mEndpointVolume = getDefaultAudioEndpoint();
        if (!mEndpointVolume) 
        {
            qWarning() << "Failed to get default audio endpoint volume.";
            return false;
        }
	}
 
    HRESULT hr = mEndpointVolume->SetMasterVolumeLevelScalar(volumeLevel, nullptr);
    mEndpointVolume->Release();
	mEndpointVolume = nullptr; // 释放接口指针，避免重复使用
    return SUCCEEDED(hr);
}

// 获取当前系统音量
float SystemSet::getVolume()
{
    if (!mIsInitialized)
    {
        qWarning() << "SystemSet is not initialized.";
        return -1.0f;
    }
    if (mEndpointVolume == nullptr)
    {
        mEndpointVolume = getDefaultAudioEndpoint();
        if (!mEndpointVolume)
        {
            qWarning() << "Failed to get default audio endpoint volume.";
            return -1.0f;
        }
    }

    float volumeLevel;
    HRESULT hr = mEndpointVolume->GetMasterVolumeLevelScalar(&volumeLevel);
    mEndpointVolume->Release();
	mEndpointVolume = nullptr; // 释放接口指针，避免重复使用
    return SUCCEEDED(hr) ? volumeLevel : -1.0f;
}

// 静音/取消静音系统音量
bool SystemSet::setMute(bool mute)
{
    if (!mIsInitialized) 
    {
        qWarning() << "SystemSet is not initialized.";
        return false;
	}
    if (mEndpointVolume == nullptr)
    {
        mEndpointVolume = getDefaultAudioEndpoint();
        if (!mEndpointVolume)
        {
            qWarning() << "Failed to get default audio endpoint volume.";
            return false;
        }
    }
    
    HRESULT hr = mEndpointVolume->SetMute(mute, nullptr);
    mEndpointVolume->Release();
	mEndpointVolume = nullptr; // 释放接口指针，避免重复使用
    return SUCCEEDED(hr);
}

// 获取当前静音状态
bool SystemSet::isMute()
{
    if (!mIsInitialized)
    {
        qWarning() << "SystemSet is not initialized.";
        return false;
    }
    if( mEndpointVolume == nullptr)
    {
        mEndpointVolume = getDefaultAudioEndpoint();
        if (!mEndpointVolume)
        {
            qWarning() << "Failed to get default audio endpoint volume.";
            return false;
        }
	}
    BOOL isMuted;
    HRESULT hr = mEndpointVolume->GetMute(&isMuted);
    mEndpointVolume->Release();
	mEndpointVolume = nullptr; // 释放接口指针，避免重复使用
    return SUCCEEDED(hr) ? isMuted : false;
}

// 设置屏幕亮度（0 到 100 之间）
bool SystemSet::setScreenBrightness(int brightness)
{
   
    QProcess process;
    QString cmd = QString("WMIC /NAMESPACE:\\\\root\\wmi PATH WmiMonitorBrightnessMethods WHERE \"Active = TRUE\" CALL WmiSetBrightness Brightness=%1 Timeout=0").arg(brightness);
    process.startCommand(cmd);
    process.waitForFinished();
    QByteArray data = process.readAllStandardOutput();
    QString result = QString::fromLocal8Bit(data);
   // qDebug() << result;
    if (result.contains("SUCCESS") || result.contains("成功"))
    {
        return true;
    }
    return false;
}

// 获取当前屏幕亮度
int SystemSet::getScreenBrightness()
{
    
    QProcess process;
    QString cmd = "WMIC /NAMESPACE:\\\\root\\wmi PATH WmiMonitorBrightness WHERE \"Active=TRUE\" GET CurrentBrightness"; 
    process.startCommand(cmd);
    process.waitForFinished();
    QString result = QString::fromLocal8Bit(process.readAllStandardOutput());
    //qDebug() << result;
    QString cleaned = result.simplified();
    // 按空格分割字符串
    QStringList parts = cleaned.split(' ');
    // 查找实际的亮度值（通常是第一个数字）
    for (const QString& part : parts) 
    {
        bool ok;
        int brightness = part.toInt(&ok);
        if (ok && brightness >= 0 && brightness <= 100) 
        {
            return brightness;
        }
    }
    return -1;
}

int SystemSet::getEstimatedChargeRemaining()
{
    QProcess process;
    QString cmd = "WMIC PATH Win32_Battery GET EstimatedChargeRemaining";
    process.startCommand(cmd);
    process.waitForFinished();
    QString result = QString::fromLocal8Bit(process.readAllStandardOutput());
    //qDebug() << result;
    QString cleaned = result.simplified();
    // 按空格分割字符串
    QStringList parts = cleaned.split(' ');
    // 查找实际的亮度值（通常是第一个数字）
    for (const QString& part : parts)
    {
        bool ok;
        int brightness = part.toInt(&ok);
        if (ok && brightness >= 0 && brightness <= 100)
        {
            return brightness;
        }
    }
    return 0;
}

QString SystemSet::getWmic(const QString& cmd)
{
    //获取cpu名称：wmic cpu get Name
   //获取cpu核心数：wmic cpu get NumberOfCores
   //获取cpu线程数：wmic cpu get NumberOfLogicalProcessors
   //查询cpu序列号：wmic cpu get processorid
   //查询主板序列号：wmic baseboard get serialnumber
   //查询BIOS序列号：wmic bios get serialnumber
   //查看硬盘：wmic diskdrive get serialnumber
    QString result;
    QProcess process;
    process.startCommand(cmd);
    process.waitForFinished();
    result = process.readAllStandardOutput();
    QStringList list = cmd.split(" ");
    result = result.remove(list.last(), Qt::CaseInsensitive);
    result = result.replace("\r", "");
    result = result.replace("\n", "");
    result = result.simplified();
    return result;
}
QString SystemSet::getCpuName()
{
    QString result;
    result = getWmic("wmic cpu get name");
    return result;
}
QString SystemSet::getUUID()
{
    QString result;
    result = getWmic("wmic csproduct get uuid");
    return result;
}
QString SystemSet::getBaseBoardId()
{
    QString result;
    result = getWmic("wmic baseboard get serialnumber");
    return result;
}
QString SystemSet::getDiskNum()
{
    QString result;
    result = getWmic("wmic diskdrive where index=0 get serialnumber");
    return result;
}
bool SystemSet::get4GNetName(QString& name, quint32& quality)
{
    /*
    *  名称                   : 手机网络 18
    描述            : Generic Mobile Broadband Adapter #18
    GUID                   : {A4ED827E-2C05-45A9-A1DE-664FDEA04B36}
    物理地址       : b8:82:95:56:5c:57
    额外的 PDP 上下文: 否(物理接口)
    父接口 Guid: 无父项
    状态                  : 已连接
    设备类型            : 移动宽带设备被嵌入到系统中
    移动电话类         : GSM
    设备 ID              : 869201062263862
    制造商           : Meig Smart
    型号                  : Meig Smart SLM720-NCN
    固件版本       : SLM720-NCN_4.0.7_EQ101
    提供商名称          : CHN-UNICOM
    漫游                : 不漫游
    信号                 : 83%
    RSSI / RSCP            : 26 (-61 dBm)
    */
    QString result;
    QProcess process;
    process.startCommand("netsh mbn show interfaces");
    process.waitForFinished();
    result = QString::fromLocal8Bit(process.readAllStandardOutput());
    QStringList list = result.split("\r\n");
    if (result.contains("已连接"))
    {
        for (QString& str : list)
        {
            if (str.contains("提供商名称"))
            {
                QStringList strList = str.split(":");
                if (strList.size() > 1)
                {
                    if (strList[1].contains("UNICOM", Qt::CaseInsensitive) || strList[1].contains("CUCC", Qt::CaseInsensitive))
                    {
                        name = "中国联通";
                    }
                    else if (strList[1].contains("MOBILE", Qt::CaseInsensitive) || strList[1].contains("CMCC", Qt::CaseInsensitive))
                    {
                        name = "中国移动";
                    }
                    else if (strList[1].contains("TELECOM", Qt::CaseInsensitive) || strList[1].contains("CTCC", Qt::CaseInsensitive))
                    {
                        name = "中国电信";
                    }
                    else if (strList[1].contains("BCTV", Qt::CaseInsensitive))
                    {
                        name = "中国广电";
                    }
                }
            }
            if (str.contains("信号"))
            {
                QStringList strList = str.split(":");
                if (strList.size() > 1)
                {
                    quality = strList[1].replace("%", "").toInt();
                    quality = std::ceil((double)quality / 20);
                }

            }
        }
        return true;
    }
    else
    {
        name = QString();
        quality = 0;
        return false;
    }
}
bool SystemSet::ctr4GNet(bool isOpen)
{
    QString result;
    QProcess process;
    process.startCommand("pnputil /enum-devices /class \"Net\"");
    process.waitForFinished();
    result = QString::fromLocal8Bit(process.readAllStandardOutput());
    QStringList list = result.split("\r\n\r\n");
    qDebug() << "SystemSet::ctr4GNet"<<result;
    QStringList net4gIdList;
    if (result.contains("Meig Smart SLM720-NCN"))
    {
        for (QString& str : list)
        {
            if (str.contains("Meig Smart SLM720-NCN"))
            {
                QStringList itmes = str.split("\r\n");
                for (QString& it : itmes)
                {
                    if (it.contains("实例 ID"))
                    {
                        QStringList strList = it.split(":");
                        if (strList.size() > 1)
                        {
                            net4gIdList.append(strList[1].replace(" ", ""));
                            break;
                        }
                    }
                }
                
            }
        }
    }
    if (net4gIdList.isEmpty())
    {
        return false;
    }
    qDebug() << "SystemSet::ctr4GNet"<< net4gIdList;
    if (isOpen)
    {
        for (QString& id : net4gIdList)
        {
            process.startCommand(QString("pnputil /enable-device \"%1\"").arg(id));
            process.waitForFinished();
            qDebug() << "SystemSet::ctr4GNet" << QString::fromLocal8Bit(process.readAllStandardOutput());
        }
      
    }
    else
    {
        for (QString& id : net4gIdList)
        {
            process.startCommand(QString("pnputil /disable-device \"%1\"").arg(id));
            process.waitForFinished();
            qDebug() << "SystemSet::ctr4GNet" << QString::fromLocal8Bit(process.readAllStandardOutput());
        }
    }
   return true;
}