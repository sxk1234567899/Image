#include "usbcamera.h"
#include "appconfig.h"

USBCamera* USBCamera::self =nullptr;

USBCamera* USBCamera::instance()
{
	static QMutex mutex;
	if  (self==nullptr)
	{
		QMutexLocker locker(&mutex);
		if  (self==nullptr)
		{
			self = new USBCamera();
		}
	}
    return self;
}
void USBCamera::destroy()
{
	if (self)
	{
		delete self;
		self = nullptr;
	}
}
USBCamera::USBCamera()
	: QObject(nullptr)
	, mVideoWidget(nullptr)
{
	init();
}

USBCamera::~USBCamera()
{}
bool USBCamera::init()
{
	QList<QCameraDevice> cameraDeviceList = QMediaDevices::videoInputs();
	if (cameraDeviceList.isEmpty())
	{
		qDebug() << "No camera device found";
		
		return false;
	}
	for (auto& cameraDevice : cameraDeviceList)
	{
		//qDebug() << cameraDevice.id();
		//qDebug() << cameraDevice.description();
		if (cameraDevice.description().contains("48MP USB"))
		{
			mCamera.reset(new QCamera(cameraDevice, this));
			const QList<QCameraFormat> formats = cameraDevice.videoFormats();
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
				qDebug() << format.resolution();
				qDebug() << format.maxFrameRate() << format.minFrameRate();
			}
		}
	}
	if (mCamera.isNull() && cameraDeviceList.size() != 0)
	{
		mCamera.reset(new QCamera(QMediaDevices::defaultVideoInput(), this));
	}
	if (mCamera.isNull())
	{
		qDebug() << "No camera found";
		return false;
	}
	mCaptureSession.reset(new QMediaCaptureSession(this));
	mImageCapture.reset(new QImageCapture(this));

	mCaptureSession->setCamera(mCamera.data());
	mCaptureSession->setImageCapture(mImageCapture.data());
	mImageCapture->setQuality(QImageCapture::VeryHighQuality);

	connect(mImageCapture.get(), &QImageCapture::errorOccurred, this, &USBCamera::displayCaptureError);
	connect(mImageCapture.get(), &QImageCapture::imageCaptured, this, &USBCamera::processCapturedImage);
	return true;
}
bool USBCamera::isAvailable()
{
	return !mCamera.isNull();
}
bool USBCamera::start(QVideoWidget* widget)
{
	qDebug() << "USBCamera start";
	if (widget == mVideoWidget && !mCamera.isNull()&&mCamera->isActive())
	{
        return true;
	}
	if (mCamera.isNull()&& !init())
	{
		return false;	
	}
	if (!mCamera.isNull() && !mCamera->isActive() && widget)
	{
		mCamera->setCameraFormat(mVideoFormat);
		mCamera->start();
		mVideoWidget = widget;
		mCaptureSession->setVideoOutput(widget);
		mVideoWidget->setAspectRatioMode(Qt::KeepAspectRatio);
		return true;
	}
    return false;
}
bool  USBCamera::stop()
{
	qDebug() << "USBCamera stop"; 
    if (!mCamera.isNull() && mCamera->isActive())
    {
		mVideoWidget = nullptr;
		this->disconnect(this, &USBCamera::picture, nullptr, nullptr);
        mCamera->stop();
		return true;
    }
    return false;
}
void USBCamera::setFlipLR()
{
	mIsFlipLR = !mIsFlipLR;
}
void USBCamera::setFlipUD()
{
    mIsFlipUD = !mIsFlipUD;
}
bool USBCamera::takePictures()
{
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
void USBCamera::saveConfig()
{

}
void USBCamera::processCapturedImage(int requestId, const QImage& img)
{
	Q_UNUSED(requestId);
	static quint8 num = 0;
	QImage image = img.copy();
	mCamera->setCameraFormat(mVideoFormat);
	emit picture(image);
}

void USBCamera::displayCaptureError(int id, const QImageCapture::Error error,
	const QString& errorString)
{
	Q_UNUSED(id);
	Q_UNUSED(error);

}
