#pragma once
#include <QtCore>
#include <QtGui>
#include <QtMultimedia>
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
    QScopedPointer<NetCameraPrivate> d_ptr;

    QScopedPointer<QCamera> mCamera;
    QScopedPointer<QImageCapture> mImageCapture;
    QScopedPointer<QMediaCaptureSession> mCaptureSession;
    QCameraFormat mCameraFormat;
    QCameraFormat mVideoFormat;
    QVideoWidget* mVideoWidget;

    bool initLocalCamera();
private:
    NetCamera();
    ~NetCamera();
    NetCamera(const NetCamera&) = delete;
    NetCamera& operator=(const NetCamera&) = delete;

private slots:
    void processCapturedImage(int requestId, const QImage& img);
    void displayCaptureError(int id, QImageCapture::Error error, const QString& errorString);
};
