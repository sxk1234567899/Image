#include "netcamera.h"
#include "netcamera_p.h"
#include <QVideoSink>
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
	Q_D(NetCamera);
	auto conf = AppConfig::instance()->netCameraConf();
	d->initCamera(conf);
}
NetCamera::~NetCamera()
{
	d_ptr.reset();
}
bool NetCamera::isAvailable()
{
    Q_D(NetCamera);
	return d->mIsAvailable;
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
			connect(d, &NetCameraPrivate::videoFrameData, mVideoWidget->videoSink(), &QVideoSink::setVideoFrame);
			return true;
		}
	}
	return false;
}
bool NetCamera::stop()
{
	Q_D(NetCamera); 
	qDebug() << "NetCamera::stop";
	disconnect(d, &NetCameraPrivate::videoFrameData, nullptr, nullptr);
	disconnect(this, &NetCamera::picture, nullptr, nullptr);
	mVideoWidget = nullptr;
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
	if (!d->isTakePictures)
	{
		QJsonObject json = d->mCmdJson["set_stream"].toObject();
		QJsonObject value = json["set_stream"].toObject();
		value["wh"] = "3840*2160";
		value["frame_rate"] = "10";
		json["set_stream"] = value;
		d->isTakePictures = d->setRequest(json);
	}
	qDebug() << "NetCamera::takePictures" << d->isTakePictures;
	return d->isTakePictures;
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