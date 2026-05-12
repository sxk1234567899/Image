#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include "artifact.h"

struct UserInfo
{
	int id;
	QString username;
	QString nickname;
	int dept_id;
    QString unitName;
	QString leader;
	QString phone;
};

class NetworkServer  : public QObject
{
	Q_OBJECT

public:
	static NetworkServer* instance();
	static void destroy();
	void setUrl(const QString& url);
	bool login(const QString& username, const QString& password,QString *message = nullptr);
	bool refreshLogin();
	inline UserInfo userInfo() { return mUserInfo;}
	QList<Artifact::BatchInfo> getArtifactsBatchList(int page, QJsonObject*json = nullptr,bool isValidates = false, QString* message = nullptr);
	QList<Artifact::BaseInfo> getArtifactsList(int batchId, int page, QJsonObject* json = nullptr, bool isValidates = false, QString* message = nullptr);
	bool getArtifactsDetailInfo(int id,QString number, QJsonObject* json, bool isValidates = false, QString* message = nullptr);
	bool getArtifactsDetailInfo(int id, QString number, Artifact::BaseInfo *baseinfo, Artifact::BatchInfo* batchinfo, bool isValidates = false, QString* message = nullptr);
	bool postArtifactsStatus(int id, QString status,QString * message = nullptr, bool isValidates = false);
	bool postArtifactUpData(QJsonObject jsonData, bool isValidates = false, QString* message = nullptr);
	bool putArtifactModifyData(int id,QJsonObject jsonData, bool isValidates = false, QString* message = nullptr);
	
	QJsonObject getValidatesArtifactFlagImg(QString number, QString* message = nullptr);
signals:
    void networkServerError(QString message);
private:
	QString mUsername;
	QString mPassword;
	QString mUrl;
	QString mToken;
	bool isLogin = false;

	static NetworkServer* self;

	int mTokenTimeOut = 1000 * 60 * 30;
	QTimer* mTimer;
	UserInfo mUserInfo;
private:
	explicit NetworkServer();
	~NetworkServer();
	NetworkServer(const NetworkServer&) = delete;
	NetworkServer& operator=(const NetworkServer&) = delete;

	UserInfo getUserInfo();
};

