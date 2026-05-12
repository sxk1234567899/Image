#pragma once
#include <QtCore>
#include <QtMultimedia>
#include <QVideoWidget>

class USBCamera  : public QObject
{
	Q_OBJECT

public:
	static USBCamera* instance();
	static void destroy();
	bool init();
	bool isAvailable();
	bool start(QVideoWidget* widget);
	bool stop();
	void setFlipLR();
	void setFlipUD();
	bool  takePictures();

	void saveConfig();
signals:
	void picture(QImage image);
private:
	QScopedPointer<QCamera> mCamera;
	QScopedPointer<QImageCapture> mImageCapture;
	QScopedPointer<QMediaCaptureSession> mCaptureSession;
	QCameraFormat mCameraFormat;
	QCameraFormat mVideoFormat;
	QVideoWidget* mVideoWidget;
	bool mIsFlipLR;
    bool mIsFlipUD;
	static USBCamera* self;
private :
	explicit USBCamera();
	~USBCamera();
	USBCamera(const USBCamera&) = delete;
    USBCamera& operator=(const USBCamera&) = delete;
private slots:
	void processCapturedImage(int requestId, const QImage& img);
	void displayCaptureError(int id, const QImageCapture::Error error, const QString& errorString);
};
