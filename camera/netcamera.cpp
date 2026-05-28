#include "netcamera.h"
#include "netcamera_p.h"
#include "appconfig.h"

NetCamera* NetCamera::self = nullptr;

NetCamera* NetCamera::instance()
{
    static QMutex mutex;
    if (self == nullptr)
    {
        QMutexLocker locker(&mutex);
        if (self == nullptr)
        {
            self = new NetCamera();
        }
    }
    return self;
}

void NetCamera::destroy()
{
    delete self;
    self = nullptr;
}

NetCamera::NetCamera()
    : QObject(nullptr)
    , d_ptr(new NetCameraPrivate(this))
    , mVideoWidget(nullptr)
{
    initLocalCamera();

    Q_D(NetCamera);
    auto conf = AppConfig::instance()->netCameraConf();
    d->initCamera(conf);
}

NetCamera::~NetCamera()
{
    d_ptr.reset();
}

bool NetCamera::initLocalCamera()
{
    const QList<QCameraDevice> cameraDeviceList = QMediaDevices::videoInputs();
    if (cameraDeviceList.isEmpty())
    {
        qDebug() << "NetCamera: No camera device found";
        return false;
    }

    for (const auto& cameraDevice : cameraDeviceList)
    {
        qDebug() << "NetCamera: Found camera:" << cameraDevice.description();
    }

    for (const auto& cameraDevice : cameraDeviceList)
    {
        if (!cameraDevice.description().contains("48MP USB"))
        {
            mCamera.reset(new QCamera(cameraDevice, this));
            qDebug() << "NetCamera: Selected camera:" << cameraDevice.description();
            break;
        }
    }

    if (mCamera.isNull() && !cameraDeviceList.isEmpty())
    {
        mCamera.reset(new QCamera(cameraDeviceList.first(), this));
        qDebug() << "NetCamera: Fallback to first camera";
    }

    if (mCamera.isNull())
    {
        qDebug() << "NetCamera: No suitable camera found";
        return false;
    }

    const QList<QCameraFormat> formats = mCamera->cameraDevice().videoFormats();
    for (const QCameraFormat& format : formats)
    {
        if (format.resolution() == QSize(3840, 2160))
        {
            mCameraFormat = format;
        }
        if (format.resolution() == QSize(1280, 720))
        {
            mVideoFormat = format;
            mCamera->setCameraFormat(mVideoFormat);
        }
        qDebug() << "NetCamera format:" << format.resolution()
                 << "fps:" << format.maxFrameRate() << "-" << format.minFrameRate();
    }

    if (!mVideoFormat.resolution().isValid())
    {
        if (!mCameraFormat.resolution().isValid() && !formats.isEmpty())
        {
            mVideoFormat = formats.first();
            mCamera->setCameraFormat(mVideoFormat);
        }
        else
        {
            mVideoFormat = mCameraFormat;
            mCamera->setCameraFormat(mVideoFormat);
        }
    }

    mCaptureSession.reset(new QMediaCaptureSession(this));
    mImageCapture.reset(new QImageCapture(this));

    mCaptureSession->setCamera(mCamera.data());
    mCaptureSession->setImageCapture(mImageCapture.data());
    mImageCapture->setQuality(QImageCapture::VeryHighQuality);

    connect(mImageCapture.get(), &QImageCapture::errorOccurred,
            this, &NetCamera::displayCaptureError);
    connect(mImageCapture.get(), &QImageCapture::imageCaptured,
            this, &NetCamera::processCapturedImage);

    qDebug() << "NetCamera: Local camera initialized";
    return true;
}

bool NetCamera::isAvailable()
{
    Q_D(NetCamera);
    return !mCamera.isNull() || d->mIsAvailable;
}

bool NetCamera::start(QVideoWidget* widget)
{
    Q_D(NetCamera);
    if (widget == mVideoWidget && d->mIsStart)
    {
        return true;
    }
    if (widget)
    {
        if (d->open())
        {
            mVideoWidget = widget;
            mVideoWidget->setAspectRatioMode(Qt::KeepAspectRatio);
            // 使用本地Windows相机显示视频，替代原 videoFrameData 信号连接
            if (!mCamera.isNull() && !mCamera->isActive())
            {
                mCamera->setCameraFormat(mVideoFormat);
                mCamera->start();
            }
            mCaptureSession->setVideoOutput(widget);
            return true;
        }
    }
    return false;
}

bool NetCamera::stop()
{
    Q_D(NetCamera);
    qDebug() << "NetCamera::stop";
    disconnect(this, &NetCamera::picture, nullptr, nullptr);
    mVideoWidget = nullptr;
    if (!mCamera.isNull() && mCamera->isActive())
    {
        mCamera->stop();
    }
    d->close();
    return true;
}

bool NetCamera::zoom(int zoom)
{
    Q_D(NetCamera);
    return d->zoom(zoom);
}

bool NetCamera::focusOnce()
{
    Q_D(NetCamera);
    return d->focusOnce();
}

bool NetCamera::manualFocusMode(bool isMode)
{
    Q_D(NetCamera);
    return d->manualFocusMode(isMode);
}

bool NetCamera::manualFocusAdd()
{
    Q_D(NetCamera);
    return d->manualFocusAdd();
}

bool NetCamera::manualFocusSub()
{
    Q_D(NetCamera);
    return d->manualFocusSub();
}

bool NetCamera::manualFocusSet(int value)
{
    Q_D(NetCamera);
    return d->manualFocusSet(value);
}

bool NetCamera::setFlipLR()
{
    Q_D(NetCamera);
    return d->setFlipLR();
}

bool NetCamera::setFlipUD()
{
    Q_D(NetCamera);
    return d->setFlipUD();
}

bool NetCamera::takePictures()
{
    Q_D(NetCamera);
    if (!d->mIsAvailable)
    {
        return false;
    }
    if (!mCamera.isNull() && mCamera->isActive())
    {
        QThread::msleep(200);
        mCamera->setCameraFormat(mCameraFormat);
        mImageCapture->setResolution(mCameraFormat.resolution());
        mImageCapture->capture();
        return true;
    }
    return false;
}

void NetCamera::saveConfig()
{
    Q_D(NetCamera);
    if (d->mMirrorFlip.contains("set_img_mirror_flip"))
    {
        auto conf = AppConfig::instance()->netCameraConf();
        conf.flipLR = d->mMirrorFlip["set_img_mirror_flip"].toObject()["mirror"].toBool();
        conf.flipUD = d->mMirrorFlip["set_img_mirror_flip"].toObject()["flip"].toBool();
        AppConfig::instance()->setNetCameraConf(conf);
    }
}

void NetCamera::processCapturedImage(int requestId, const QImage& img)
{
    Q_UNUSED(requestId);
    QImage image = img.copy();
    mCamera->setCameraFormat(mVideoFormat);
    emit picture(image);
}

void NetCamera::displayCaptureError(int id, QImageCapture::Error error,
                                    const QString& errorString)
{
    Q_UNUSED(id);
    Q_UNUSED(error);
    qDebug() << "NetCamera capture error:" << errorString;
}
