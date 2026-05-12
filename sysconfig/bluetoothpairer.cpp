#include "bluetoothpairer.h"
#include <QDebug>
#include <QtCore>
//#include <windows.h>
//#include <bthdef.h>
//#include<bluetoothapis.h>
//#include <winsock.h>
//#include <ws2bth.h>
//#pragma comment(lib, "wsock32.lib")
//#pragma comment(lib, "bthprops.lib")
//#pragma comment(lib,"ws2_32.lib")
//#pragma warning(disable : 4995)

BluetoothPairer::BluetoothPairer(QObject *parent) : QObject(parent)
{
    // 初始化本地蓝牙设备
    m_localDevice = new QBluetoothLocalDevice(this);

    // 确保蓝牙已开启
    if (m_localDevice->isValid()) {
        if (m_localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff) {
            m_localDevice->powerOn(); // 开启蓝牙
        }
        // 设置为可发现模式
        m_localDevice->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    } else {
        qWarning() << "本地蓝牙设备不可用";
    }

    // 初始化设备发现代理
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_discoveryAgent->setLowEnergyDiscoveryTimeout(5000); // 低功耗设备扫描超时

    // 连接信号槽（Qt 6 兼容）
    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothPairer::onDeviceDiscovered);
    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BluetoothPairer::onDiscoveryFinished);
}

BluetoothPairer::~BluetoothPairer()
{
    stopDeviceDiscovery();
    delete m_discoveryAgent;
    delete m_localDevice;
}

void BluetoothPairer::startDeviceDiscovery()
{
    m_discoveredDevices.clear();
    if (m_discoveryAgent->isActive()) {
        m_discoveryAgent->stop();
    }
    qDebug() << "开始搜索蓝牙设备...";
    // 同时搜索经典蓝牙和低功耗蓝牙
    m_discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::ClassicMethod |
                            QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

void BluetoothPairer::stopDeviceDiscovery()
{
    if (m_discoveryAgent->isActive()) {
        m_discoveryAgent->stop();
        qDebug() << "已停止设备搜索";
    }
}

bool BluetoothPairer::pairWithDevice(const QBluetoothDeviceInfo&address, const QString& pin)
{
    if (!m_localDevice->isValid()) {
        qWarning() << "无法配对：本地蓝牙设备不可用";
        return false;
    }
    QProcess process;
    QEventLoop loop;
    QStringList cmd;
    QObject::connect(&process, &QProcess::finished, &loop, &QEventLoop::quit);
    QString btpairAppPath = QCoreApplication::applicationDirPath() + "/btpair.exe";
     cmd.clear();
     cmd << btpairAppPath;
     cmd << "-n\"" + address.name() + "\"";
     cmd<<"-p"+pin;
     process.startCommand(cmd.join(" "));
     loop.exec();
     QString output = process.readAll();
     if(!output.isEmpty())
     {
         qDebug() << "配对失败";
         return false;
     }
     qDebug() << "配对成功";

    /*创建串口*/
    QString btcomAppPath = QCoreApplication::applicationDirPath() + "/btcom.exe";
    
    cmd.clear();
    cmd << btcomAppPath;
    cmd << "-c";
    cmd << "-b\""+ address.address().toString() + "\"";
    cmd << "-s\"00001101-0000-1000-8000-00805F9B34FB\"";
    process.startCommand(cmd.join(" "));
    loop.exec();
    if(process.readAllStandardOutput().isEmpty())
    {
        qDebug() << "串口创建成功";
        return true;
    }
    else
    {
        qDebug() << "串口创建失败";
        return false;
    }
    // 发起配对请求  
}

bool BluetoothPairer::unpairDevice(const QBluetoothDeviceInfo&address)
{
    if (m_localDevice->isValid()) {
        m_localDevice->requestPairing(address.address(), QBluetoothLocalDevice::Unpaired);
        qDebug() << "发起取消配对请求：" << address.address().toString();
        return true;
    }
    return false;
}

void BluetoothPairer::onDeviceDiscovered(const QBluetoothDeviceInfo &info)
{
    // 去重添加设备
    if (!m_discoveredDevices.contains(info.address())) {
        qDebug() << "发现设备：" << info.name() << info.address().toString();
        m_discoveredDevices.insert(info.address());
        emit deviceDiscovered(info); // 发送发现设备信号
    }
}
void BluetoothPairer::onDiscoveryFinished()
{
    qDebug() << "设备搜索完成，共发现" << m_discoveredDevices.size() << "个设备";
    emit discoveryFinished();
}
