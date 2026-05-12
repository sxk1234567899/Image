#include "appconfig.h"

#define appVersionNo	(QString("02.00.26"))
#define dateVersionNo   (QLocale( QLocale::English ).toDate( QString(__DATE__).replace( "  ", " 0" ), "MMM dd yyyy").toString("yyyyMMdd")+QString( __TIME__).remove(":"))

AppConfig* AppConfig::self = nullptr;

AppConfig* AppConfig::instance()
{
	static QMutex mutex;
	if (self == nullptr)
	{
		QMutexLocker locker(&mutex);
		if (self == nullptr)
		{
			self = new AppConfig();
		}
	}
	return self;

}
void AppConfig::destroy()
{
	delete self;
	self = nullptr;
}
AppConfig::AppConfig()
	: QObject(nullptr)
{

	QString path = QCoreApplication::applicationDirPath();
	QDir dir(path);
	path.append("/sysconf");
	if (!dir.exists(path))
	{
		dir.mkdir(path);
	}
	QFile file;
	configFilePath = path + "/appconf.json";
	if (!file.exists(configFilePath))
	{
		qDebug() << "系统配置文件丢失，恢复为默认配置";
		file.setFileName(":/config/appconf.json");
		if (file.open(QFile::ReadOnly))
		{
			QByteArray json = file.readAll();
			QJsonParseError error;
			mConfJson = QJsonDocument::fromJson(json, &error).object();
			if (error.error != QJsonParseError::NoError)
			{
				mConfJson = QJsonObject();
				qDebug() << "读取系统默认配置错误：" << error.errorString();
			}
			file.close();
		}

		if (!mConfJson.isEmpty())
		{
			file.setFileName(configFilePath);
            if (file.open(QFile::ReadWrite))
			{ 
                QJsonDocument doc(mConfJson);
                file.write(doc.toJson());
                file.close();
			}
		}
	}
	else
	{
		file.setFileName(configFilePath);
		if (file.open(QFile::ReadOnly))
		{
			QByteArray json = file.readAll();
			QJsonParseError error;
			mConfJson = QJsonDocument::fromJson(json, &error).object();
			if (error.error != QJsonParseError::NoError)
			{
				mConfJson = QJsonObject();
				qDebug() << "读取系统配置错误：" << error.errorString();
			}
			file.close();
		}
	}
	qDebug() << "AppConfig::AppConfig ";
	qDebug().noquote() << QString::fromUtf8(QJsonDocument(mConfJson).toJson(QJsonDocument::Indented));

	mVersionInfo.version = appVersionNo;
	mVersionInfo.buildTime = dateVersionNo;
	QJsonObject versionJson;
	versionFilePath = QCoreApplication::applicationDirPath()+"/version_info.json";
	if (QFile::exists(versionFilePath))
	{
		QFile file(versionFilePath);
		if (file.open(QIODevice::ReadOnly))
		{
			QByteArray json = file.readAll();
			QJsonParseError error;
			versionJson = QJsonDocument::fromJson(json, &error).object();
			if (error.error != QJsonParseError::NoError)
			{
				qDebug() << "读取日志信息错误：" << error.errorString();
			}
			file.close();
		}
	}
	if (versionJson.contains("updateLog"))
	{
		mVersionInfo.updateLog = versionJson.value("updateLog").toString();
	}
}

AppConfig::~AppConfig()
{}
void AppConfig::saveConfig()
{
	QFile file(configFilePath);

    if (file.open(QFile::WriteOnly| QFile::Truncate))
    {
        QJsonDocument doc(mConfJson);
        file.write(doc.toJson());
        file.close();
    }
}
AppConf AppConfig::appConf()
{
	AppConf conf;
	QJsonObject json = mConfJson.value("app").toObject();
	conf.regDBDir = json.value("regDBDir").toString();
	conf.regImageDir = json.value("regImageDir").toString();
	conf.verifyDBDir = json.value("verifyDBDir").toString();
	conf.verifyImageDir = json.value("verifyImageDir").toString();
	conf.verifyRawImageDir = json.value("verifyRawImageDir").toString();
	/*转换为绝对路径*/
	QString dirPath = QCoreApplication::applicationDirPath();
	QDir dir(dirPath);
	dir.cdUp();
	dirPath = dir.absolutePath();
	bool isSave = false;
	QString path = QFileInfo(conf.regDBDir).canonicalFilePath();
	if (path.isEmpty())
	{
		conf.regDBDir = dirPath + "/data";
		if (!dir.exists(conf.regDBDir))
		{
			dir.mkdir(conf.regDBDir);
		}
		conf.regDBDir += "/reg";
		if (!dir.exists(conf.regDBDir))
		{
			dir.mkdir(conf.regDBDir);
		}
		conf.regDBDir += "/db";
		if (!dir.exists(conf.regDBDir))
		{
			dir.mkdir(conf.regDBDir);
		}
		json["regDBDir"] = conf.regDBDir;
		isSave = true;
	}
   
   path = QFileInfo(conf.regImageDir).canonicalFilePath();
   if (path.isEmpty())
   {

	   conf.regImageDir = dirPath + "/data";
	   if (!dir.exists(conf.regImageDir))
	   {
		   dir.mkdir(conf.regImageDir);
	   }
	   conf.regImageDir += "/reg";
	   if (!dir.exists(conf.regImageDir))
	   {
		   dir.mkdir(conf.regImageDir);
	   }
	   conf.regImageDir += "/image";
	   if (!dir.exists(conf.regImageDir))
	   {
		   dir.mkdir(conf.regImageDir);
	   }
	   json["regImageDir"] = conf.regImageDir;
       isSave = true;
   }
   path = QFileInfo(conf.verifyDBDir).canonicalFilePath();
   if (path.isEmpty())
   {

	   conf.verifyDBDir = dirPath + "/data";
	   if (!dir.exists(conf.verifyDBDir))
	   {
		   dir.mkdir(conf.verifyDBDir);
	   }
	   conf.verifyDBDir += "/verify";
	   if (!dir.exists(conf.verifyDBDir))
	   {
		   dir.mkdir(conf.verifyDBDir);
	   }
	   conf.verifyDBDir += "/db";
	   if (!dir.exists(conf.verifyDBDir))
	   {
		   dir.mkdir(conf.verifyDBDir);
	   }
       json["verifyDBDir"] = conf.verifyDBDir;
       isSave = true;
   }
   path = QFileInfo(conf.verifyImageDir).canonicalFilePath();
   if (path.isEmpty())
   {

	   conf.verifyImageDir = dirPath + "/data";
	   if (!dir.exists(conf.verifyImageDir))
	   {
		   dir.mkdir(conf.verifyImageDir);
	   }
	   conf.verifyImageDir += "/verify";
	   if (!dir.exists(conf.verifyImageDir))
	   {
		   dir.mkdir(conf.verifyImageDir);
	   }
	   conf.verifyImageDir += "/image";
	   if (!dir.exists(conf.verifyImageDir))
	   {
		   dir.mkdir(conf.verifyImageDir);
	   }
       json["verifyImageDir"] = conf.verifyImageDir;
       isSave = true;
   }
    path = QFileInfo(conf.verifyRawImageDir).canonicalFilePath();
    if (path.isEmpty())
    {

	   conf.verifyRawImageDir = dirPath + "/data";
	   if (!dir.exists(conf.verifyRawImageDir))
	   {
		   dir.mkdir(conf.verifyRawImageDir);
	   }
	   conf.verifyRawImageDir += "/verify";
	   if (!dir.exists(conf.verifyRawImageDir))
	   {
		   dir.mkdir(conf.verifyRawImageDir);
	   }
	   conf.verifyRawImageDir += "/raw_image";
	   if (!dir.exists(conf.verifyRawImageDir))
	   {
		   dir.mkdir(conf.verifyRawImageDir);
	   }
       json["verifyRawImageDir"] = conf.verifyRawImageDir;
       isSave = true;
    }

	if (isSave)
	{
        mConfJson["app"] = json;
        saveConfig();

	}
	return conf;
}
VersionInfo AppConfig::versionInfo()
{
	return mVersionInfo;
}
NetworkServerConf AppConfig::netWorkServerConf()
{
    NetworkServerConf conf;
	QJsonObject json = mConfJson.value("netWorkServer").toObject();
	conf.url = json.value("url").toString();
    conf.username = json.value("username").toString();
	conf.password = json.value("password").toString();
	conf.updateUrl = json.value("updateUrl").toString();
	return conf;
}
bool AppConfig::setNetworkServerConf(NetworkServerConf conf)
{
	QJsonObject json= mConfJson.value("netWorkServer").toObject();
    json["url"] = conf.url;
    json["username"] = conf.username;
    json["password"] = conf.password;
    json["updateUrl"] = conf.updateUrl;
    mConfJson["netWorkServer"] = json;
    saveConfig();
    return true;
}
NetCameraConf AppConfig::netCameraConf()
{
    NetCameraConf conf;
	QJsonObject json = mConfJson.value("netCamera").toObject();
    conf.ip = json.value("ip").toString();
    conf.port = json.value("port").toInt();
    conf.username = json.value("username").toString();
    conf.password = json.value("password").toString();
	conf.flipLR = json.value("flipLR").toBool();
    conf.flipUD = json.value("flipUD").toBool();
    conf.lowZoom = json.value("lowZoom").toInt();
    conf.highZoom = json.value("highZoom").toInt();
	if (conf.highZoom < 10)
	{
        conf.highZoom = 144;
	}
	return conf;
}
bool AppConfig::setNetCameraConf(NetCameraConf conf)
{
	QJsonObject json;
    json["ip"] = conf.ip;
    json["port"] = conf.port;
    json["username"] = conf.username;
    json["password"] = conf.password;
    json["flipLR"] = conf.flipLR;
    json["flipUD"] = conf.flipUD;
    json["lowZoom"] = conf.lowZoom;
	json["highZoom"] = conf.highZoom;
    mConfJson["netCamera"] = json;
    saveConfig();
	return true;
}
USBCameraConf AppConfig::usbCameraConf()
{
    USBCameraConf conf;
    QJsonObject json = mConfJson.value("usbCamera").toObject();
    conf.flipLR = json.value("flipLR").toBool();
    conf.flipUD = json.value("flipUD").toBool();
    return conf;
}
bool AppConfig::setUSBCameraConf(USBCameraConf conf)
{
    QJsonObject json;
    json["flipLR"] = conf.flipLR;
    json["flipUD"] = conf.flipUD;
    mConfJson["usbCamera"] = json;
    saveConfig();
	return true;
}
MinioConf AppConfig::minioConf()
{
	MinioConf conf;
	QJsonObject json = mConfJson.value("minio").toObject();
	conf.addr = json.value("addr").toString();
	conf.imageUrl = json.value("imageUrl").toString();
	conf.accessKey = json.value("accessKey").toString();
	conf.secretKey = json.value("secretKey").toString();
	conf.bucketKey = json.value("bucketKey").toString();
	conf.reUploadNum = json.value("reUploadNum").toInt();
	return conf;
}

LabelPrintConf AppConfig::labelPrintConf()
{
    LabelPrintConf conf;
	QJsonObject json = mConfJson.value("labelPrint").toObject();
	conf.com = json.value("com").toString();
	return conf;
}
bool AppConfig::setLabelPrintConf(LabelPrintConf conf)
{
    QJsonObject json;
    json["com"] = conf.com;
    mConfJson["labelPrint"] = json;
    saveConfig();
    return true;
}
