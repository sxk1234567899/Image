#include <QtWidgets/QApplication>
#include "wgtmain.h"
#include "usbcamera.h"
#include "netcamera.h"
#include "appconfig.h"
#include "regthread.h"
#include "verifythread.h"
#include "networkserver.h"
#include "systemset.h"
#include "wifimanager.h"


void init()
{ 
    /*初始化全局配置*/
    AppConfig* appConf = AppConfig::instance();

    /*初始化相机*/
    NetCamera::instance();
    USBCamera::instance();
    NetworkServer::instance()->setUrl(appConf->netWorkServerConf().url);

}

void destroy()
{
    NetCamera::instance()->stop();
    USBCamera::instance()->stop();

    NetCamera::destroy();
    USBCamera::destroy();
    RegThread::destroy();
    VerifyThread::destroy();
    AppConfig::destroy();
    NetworkServer::destroy();
	SystemSet::destroy();
}

int main(int argc, char *argv[])
{
    SystemSet::instance();
	WiFiManager::instance();

    // 优先使用 OpenGL ES（移动平台）或桌面 OpenGL
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setVersion(3, 3); // 要求 OpenGL 3.3 或更高
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
    // 允许在没有合适硬件支持时使用软件渲染
    QGuiApplication::setAttribute(Qt::AA_UseSoftwareOpenGL, false);
    QApplication app(argc, argv);
  
    // 获取当前线程（主线程）
    QThread* mainThread = QThread::currentThread();

    // 设置线程优先级（高于普通优先级）
    mainThread->setPriority(QThread::HighPriority);
    init();
    /*加载全局样式表*/
    QFile file(":/imgacqu.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        file.close();
        qApp->setStyleSheet(qss);
    }

    QTranslator translator;
    if (translator.load("qt_zh_CN.qm", QLibraryInfo::path(QLibraryInfo::TranslationsPath)))
    {
        app.installTranslator(&translator);
    }

    // 配置 SSL
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_2); // 直接指定使用 TLS 1.2
    QSslConfiguration::setDefaultConfiguration(sslConfig);

    WgtMain window;
    window.setAttribute(Qt::WA_AcceptTouchEvents);
    window.show();

    /*释放全局单一实例*/
    qApp->connect(qApp, &QApplication::aboutToQuit, [](){destroy();});
    // 验证优先级设置
    qDebug() << "主线程优先级:" << mainThread->priority();
    return app.exec();
}
