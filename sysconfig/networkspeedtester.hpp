#pragma once

#include <QProcess>
#include <QTimer>
#include <QMap>
#include <QDebug>
#include <QThread>
class NetworkSpeedTester : public QObject 
{
    Q_OBJECT
public:
    explicit NetworkSpeedTester() : QObject(nullptr) 
        ,thread(new QThread)
    {
        this->setObjectName("NetworkSpeedTester");
        thread->setObjectName("NetworkSpeedTesterThread");
        moveToThread(thread);
        thread->start();
        QTimer::singleShot(10, [this]() {
            timer = new QTimer();
            connect(timer, &QTimer::timeout, this, &NetworkSpeedTester::updateSpeed);
            timer->start(1000);  // 每秒更新一次
        });
        
    }
    ~NetworkSpeedTester()
    {
        thread->quit();
        thread->wait();
        delete timer;
        delete thread;
        qDebug() << "NetworkSpeedTester::~NetworkSpeedTester()";
    }
    // 设置要监测的网卡名称（如 "eth0" 或 "en0"）
    void setInterface(const QString interfaceName) 
    {
        QTimer::singleShot(0, [this, interfaceName]() {
            this->interfaceName = interfaceName;
            previousBytes = 0;
            currentSpeed = 0;
            });
    }

    // 获取当前网速（单位：KB/s）
    double getSpeed() const 
    {
        return currentSpeed;
    }

signals:
    void speedUpdated(double speed);  // 网速更新信号

private slots:
    void updateSpeed() 
    {
        if (interfaceName.isEmpty()) return;

        qint64 currentBytes = getBytesReceived();
        if (previousBytes > 0) {
            // 计算差值（KB/s）
            currentSpeed = (currentBytes - previousBytes) / 1024.0;
            emit speedUpdated(currentSpeed);
        }
        previousBytes = currentBytes;
    }

private:
    QString interfaceName;
    qint64 previousBytes = 0;
    double currentSpeed = 0;
    QTimer* timer;
    QThread *thread;
    // 根据平台获取网卡接收的字节数
    qint64 getBytesReceived() 
    {
        // Windows 实现（使用 powershell）
        QProcess process;
        process.start("powershell", QStringList()
            << "-command"
            << QString("(Get-NetAdapterStatistics -Name '%1').ReceivedBytes").arg(interfaceName));
        process.waitForFinished();
        QString output = process.readAllStandardOutput().trimmed();
        return output.toLongLong();
    }
};
