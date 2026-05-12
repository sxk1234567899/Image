#pragma once
#include "netcamera.h"
#include <QVideoFrame>
#include "appconfig.h"
#define jsonToChar(json)  (QJsonDocument(json).toJson(QJsonDocument::Compact).data())
#define charToJson(str)  (QJsonDocument::fromJson(str).object())


class NetCameraPrivate  : public QObject
{
	Q_OBJECT
public:
	QJsonObject mCmdJson;
	QJsonObject mImageConf;
	QJsonObject mMirrorFlip;
	QAtomicInt isTakePictures = false;
	QAtomicInt mIsAvailable = false;
	QAtomicInt mIsStart = false;
public:
	NetCameraPrivate(NetCamera* q);
	~NetCameraPrivate();
public slots:
	bool zoomIn();
	bool zoomOut();
	bool zoom(int zoom);
	bool focusOnce();
	bool manualFocusMode(bool isMode);
	bool manualFocusAdd();
	bool manualFocusSub();
	bool manualFocusSet(int focus);
	bool setFlipLR();
	bool setFlipUD();
signals:
	bool initCamera(NetCameraConf conf);
	bool open();
	bool close();
	QJsonObject getRequest(const QJsonObject& requestJson);
	bool setRequest(const QJsonObject& requestJson);

	void videoFrameData(QVideoFrame videoFrame);
private:
	int id;
	// 以下参数保持为0即可
	int idx = 0; // 主码流
	int chnn = 0;
	// 解码器ID，从1开始
	int decId = 100;
	int picIdx = 64; // 图片流
    QString errorString;
	QThread* mThread = nullptr;
	QTimer* mTimer;
	const quint32 mReTime = 10;
	NetCameraConf mNetCameraConf;
	NetCamera* q_ptr;
	Q_DECLARE_PUBLIC(NetCamera)
private slots:
	bool mInitCamera(NetCameraConf conf);
	bool mOpen();
	bool mClose();

	QJsonObject mGetRequest(const QJsonObject& requestJson);
	bool mSetRequest(const QJsonObject& requestJson);

	void mGetVideoFrameData();

	void mQuit();
};

