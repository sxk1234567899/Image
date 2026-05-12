#pragma once
#include <QtCore>
#include <QtGui>
#include <QVideoWidget>
class NetCameraPrivate;

class NetCamera : public QObject
{
	Q_OBJECT

public:
	static NetCamera* instance();
	static  void destroy();
	bool isAvailable();
	bool start(QVideoWidget* widget);
	bool stop();
	bool zoom(int zoom); 
	bool focusOnce();
	bool manualFocusMode(bool isMode);
	bool manualFocusAdd();
    bool manualFocusSub();
    bool manualFocusSet(int focus);
	bool setFlipLR();
    bool setFlipUD();
	bool takePictures();

	void saveConfig();
signals:
	void picture(QImage image);
	void available(bool isAvailable);
private:
	static NetCamera* self;
	Q_DECLARE_PRIVATE(NetCamera)
	QScopedPointer<NetCameraPrivate> d_ptr; // 智能指针管理私有类实例

	QVideoWidget* mVideoWidget;
private:
	NetCamera();
	~NetCamera();
	NetCamera(const NetCamera&) = delete;
	NetCamera& operator=(const NetCamera&) = delete;
};