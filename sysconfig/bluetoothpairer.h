#ifndef BLUETOOTHPARER_H
#define BLUETOOTHPARER_H

#include <QObject>
#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothAddress>
#include <QBluetoothDeviceInfo>
#include <QSet>

class BluetoothPairer : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothPairer(QObject *parent = nullptr);
    ~BluetoothPairer() override;

    // 设备搜索控制
    void startDeviceDiscovery();
    void stopDeviceDiscovery();

    // 配对控制
    bool pairWithDevice(const QBluetoothDeviceInfo&address, const QString& pin);
    bool unpairDevice(const QBluetoothDeviceInfo&address);

    // 获取已发现设备列表（供外部访问）
    QSet<QBluetoothAddress> discoveredDevices() const { return m_discoveredDevices; }

signals:
    // 发现新设备
    void deviceDiscovered(const QBluetoothDeviceInfo &info);
    // 配对状态变化
    void pairingStatusChanged(const QBluetoothAddress &address, bool success);
    // 搜索完成
    void discoveryFinished();

private slots:
    // 设备发现处理
    void onDeviceDiscovered(const QBluetoothDeviceInfo &info);
    // 搜索完成处理
    void onDiscoveryFinished();

private:
    QBluetoothLocalDevice *m_localDevice = nullptr; // 本地蓝牙设备
    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent = nullptr; // 设备发现代理
    QSet<QBluetoothAddress> m_discoveredDevices; // 已发现设备地址集合
};

#endif // BLUETOOTHPARER_H
