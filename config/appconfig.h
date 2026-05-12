#pragma once
#include <QtCore>
#include <QObject>

struct AppConf
{
	QString regDBDir;
	QString regImageDir;
    QString verifyDBDir;
	QString verifyRawImageDir;
	QString verifyImageDir;
};
struct VersionInfo
{
	QString version;
	QString buildTime;
	QString updateLog;	
};
struct MinioConf
{
	QString addr;
	QString imageUrl;
	QString accessKey;
	QString secretKey;
	QString bucketKey;
	int reUploadNum;
};
struct NetworkServerConf
{
	QString url;
	QString username;
	QString password;
	QString updateUrl;
};
struct NetCameraConf
{
	QString ip;
	int port;
	QString username;
	QString password;
	bool flipLR;
	bool flipUD;
	int lowZoom;
    int highZoom;
};

struct USBCameraConf
{
	bool flipLR;
	bool flipUD;
};

struct LabelPrintConf
{ 
	QString com;
};

class AppConfig  : public QObject
{
	Q_OBJECT

public:
    static AppConfig* instance();
	static void destroy();
	AppConf appConf();
	VersionInfo versionInfo();
	NetworkServerConf netWorkServerConf();
	bool setNetworkServerConf(NetworkServerConf conf);
	NetCameraConf netCameraConf();
	bool setNetCameraConf(NetCameraConf conf);
	USBCameraConf usbCameraConf();
	bool setUSBCameraConf(USBCameraConf conf);
	MinioConf minioConf();

	LabelPrintConf labelPrintConf();
	bool setLabelPrintConf(LabelPrintConf conf);
	void saveConfig();
private:
	static AppConfig* self;
	QJsonObject mConfJson;
	QString configFilePath;
	QString versionFilePath;
	VersionInfo mVersionInfo;
private:
	explicit AppConfig();
	~AppConfig();
	AppConfig(const AppConfig&) = delete;
	AppConfig& operator=(const AppConfig&) = delete;
};

