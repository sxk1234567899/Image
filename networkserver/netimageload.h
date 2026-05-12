#pragma once
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QImageReader>
#include <QImage>
#include <QUrl>
#include <QObject>
#include <QThread>
#include "artifact.h"
class NetImageLoad  : public QObject
{
	Q_OBJECT

public:
	NetImageLoad(QObject *parent);
	~NetImageLoad();
	void loadImage(const QString& url);
	static QImage loadImageBlocking(const QString& url);
    static QImage loadImageInfoBlocking(Artifact::ImageInfo* info);
	static QList<QImage> loadImageListBlocking(QList<Artifact::ImageInfo*> infoList);
signals:
	void getImage(QImage image);
private:
	// 网络组件
	QNetworkAccessManager* mNetworkManager;
	QImage mImage;
	// 数据
	QUrl mCurrentUrl;
	QThread* mThread;
private slots:
	void onNetworkReplyFinished(QNetworkReply* reply);

};

