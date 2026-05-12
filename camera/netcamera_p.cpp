#include "netcamera.h"
#include "netcamera_p.h"
#include "l_sdk.h"
NetCameraPrivate::NetCameraPrivate(NetCamera* q)
	: QObject(nullptr)
    , q_ptr(q)
	, mThread(new QThread(this))
	, mTimer(new QTimer(this))

{
	id = 0;
	mThread->setObjectName("NetCameraThread");
	//mThread->setPriority(QThread::HighestPriority);
	this->moveToThread(mThread);
	mTimer->moveToThread(mThread);
    connect(mThread, &QThread::finished, this, &NetCameraPrivate::mQuit);
	connect(mTimer, &QTimer::timeout, this, &NetCameraPrivate::mGetVideoFrameData);
	connect(this, &NetCameraPrivate::initCamera, this, &NetCameraPrivate::mInitCamera);
	connect(this, &NetCameraPrivate::open, this, &NetCameraPrivate::mOpen,Qt::BlockingQueuedConnection);
    connect(this, &NetCameraPrivate::close, this, &NetCameraPrivate::mClose, Qt::QueuedConnection);
	connect(this, &NetCameraPrivate::getRequest, this, &NetCameraPrivate::mGetRequest, Qt::BlockingQueuedConnection);
    connect(this, &NetCameraPrivate::setRequest, this, &NetCameraPrivate::mSetRequest, Qt::BlockingQueuedConnection);
	mThread->start();


	QFile file(":/config/netcamera.json");
	if (file.open(QFile::ReadOnly))
	{
		QByteArray json = file.readAll();
		QJsonParseError error;
		mCmdJson = QJsonDocument::fromJson(json,&error).object();
		if (error.error != QJsonParseError::NoError)
		{
			qDebug() << "读取配置错误：" << error.errorString();
		}
		file.close();
	}

   
}

NetCameraPrivate::~NetCameraPrivate()
{
	close();
	mThread->quit();
	mThread->wait();
	l_sdk_discover_run(false);
	l_sdk_discover_close();
	l_sdk_logout(id);
	l_sdk_quit();
}

bool NetCameraPrivate::zoomIn()
{
	QJsonObject value = mImageConf["set_image"].toObject();
	int ezoom_value = value["ezoom_value"].toInt();
	if (ezoom_value <= 45)
	{
        ezoom_value += 5;
	}
	else
	{
		return true;
	}
    value["ezoom_value"] = ezoom_value;
    mImageConf["set_image"] = value;
	return setRequest(mImageConf);
}
bool NetCameraPrivate::zoomOut()
{
	QJsonObject value = mImageConf["set_image"].toObject();
	int ezoom_value = value["ezoom_value"].toInt();
	if (ezoom_value >=5)
	{
		ezoom_value -= 5;
	}
	else
	{
		return true;
	}
	value["ezoom_value"] = ezoom_value;
	mImageConf["set_image"] = value;
	return setRequest(mImageConf);
}
bool NetCameraPrivate::zoom(int zoom)
{
	QJsonObject value = mImageConf["set_image"].toObject();
	if (value["ezoom_value"].toInt() == zoom)
	{
		return true;
	}
	value["ezoom_value"] = zoom;
	mImageConf["set_image"] = value;
	bool ret = setRequest(mImageConf);
	if(ret)
	{
		QEventLoop loop;
		QTimer::singleShot(2000, &loop, &QEventLoop::quit); // 超时设置
		loop.exec();
	}
	qDebug() << "zoom:" << ret;
	return ret;
}
bool NetCameraPrivate::focusOnce()
{
	QJsonObject value = mImageConf["set_image"].toObject();
	value["focus_mode"] = 2;
	mImageConf["set_image"] = value;
	bool ret = setRequest(mImageConf);
	if (!ret)
	{
		return false;
	}
	QTimer::singleShot(500, this, [this]() {
		QJsonObject value = mImageConf["set_image"].toObject();
		value["focus_mode"] = 0;
		mImageConf["set_image"] = value;
		mSetRequest(mImageConf);
	});
	return ret;
}


bool NetCameraPrivate::manualFocusMode(bool isMode)
{
	// M系列: 通过 set_image 切换聚焦模式, focus_value 置0 (同 net_camera.cpp setFocus)
	QJsonObject imgValue = mImageConf["set_image"].toObject();
	imgValue["focus_mode"] = isMode ? 1 : 0;
	imgValue["focus_value"] = 0;
	mImageConf["set_image"] = imgValue;

	bool ret = setRequest(mImageConf);
	if (!ret)
	{
		return false;
	}
	/*获取部分图像参数范围*/
	mImageConf = mGetRequest(mCmdJson["get_image"].toObject());
	if (mImageConf.isEmpty())
	{
		qDebug() << "manualFocusMode: get_image error";
		return false;
	}
	mImageConf["set_image"] = mImageConf.take("get_image");
	mImageConf["cmd"] = "set_image";

	return ret;
}



bool NetCameraPrivate::manualFocusAdd()
{
	// M系列: 通过 set_image 的 focus_value=1 实现相对正向移动 (同 net_camera.cpp focusAdd)
	QJsonObject imgValue = mImageConf["set_image"].toObject();
	imgValue["focus_mode"] = 1;
	imgValue["focus_value"] = 1;
	mImageConf["set_image"] = imgValue;

	bool ret = setRequest(mImageConf);
	if (ret)
	{
		QEventLoop loop;
		QTimer::singleShot(50, &loop, &QEventLoop::quit);
		loop.exec();
		// 刷新当前参数
		mImageConf = mGetRequest(mCmdJson["get_image"].toObject());
		if (!mImageConf.isEmpty())
		{
			mImageConf["set_image"] = mImageConf.take("get_image");
			mImageConf["cmd"] = "set_image";
		}
	}
	qDebug() << "manualFocusAdd:" << ret;
	return ret;
}



bool NetCameraPrivate::manualFocusSub()
{
	// M系列: 通过 set_image 的 focus_value=-1 实现相对负向移动 (同 net_camera.cpp focusSub)
	QJsonObject imgValue = mImageConf["set_image"].toObject();
	imgValue["focus_mode"] = 1;
	imgValue["focus_value"] = -1;
	mImageConf["set_image"] = imgValue;

	bool ret = setRequest(mImageConf);
	if (ret)
	{
		QEventLoop loop;
		QTimer::singleShot(50, &loop, &QEventLoop::quit);
		loop.exec();
		// 刷新当前参数
		mImageConf = mGetRequest(mCmdJson["get_image"].toObject());
		if (!mImageConf.isEmpty())
		{
			mImageConf["set_image"] = mImageConf.take("get_image");
			mImageConf["cmd"] = "set_image";
		}
	}
	qDebug() << "manualFocusSub:" << ret;
	return ret;
}

bool NetCameraPrivate::manualFocusSet(int focus)
{
	QJsonObject value = mImageConf["set_image"].toObject();
	if (value["focus_value"].toInt() == focus)
	{
		return true;
	}
	value["focus_value"] = value;
	mImageConf["set_image"] = value;
	bool ret = setRequest(mImageConf);
	if (ret)
	{
		QEventLoop loop;
		QTimer::singleShot(2000, &loop, &QEventLoop::quit); // 超时设置
		loop.exec();
	}
	qDebug() << "manualFocusSet:" << ret;
	return ret;
}
bool NetCameraPrivate::setFlipLR()
{
	QJsonObject jsonData =  getRequest(mCmdJson["img_mirror_flip"].toObject());
	if (jsonData.contains("img_mirror_flip"))
	{
		
		mMirrorFlip = mCmdJson["set_img_mirror_flip"].toObject();
		QJsonObject value = mMirrorFlip["set_img_mirror_flip"].toObject();
		value["flip"] = jsonData["img_mirror_flip"].toObject()["flip"].toBool();
		value["mirror"] = !jsonData["img_mirror_flip"].toObject()["mirror"].toBool();
		mMirrorFlip["set_img_mirror_flip"] = value;
		return setRequest(mMirrorFlip);
	}
	return false;

}
bool NetCameraPrivate::setFlipUD()
{
	QJsonObject jsonData = getRequest(mCmdJson["img_mirror_flip"].toObject());
	if (jsonData.contains("img_mirror_flip"))
	{

		mMirrorFlip = mCmdJson["set_img_mirror_flip"].toObject();
		QJsonObject value = mMirrorFlip["set_img_mirror_flip"].toObject();
		value["flip"] = !jsonData["img_mirror_flip"].toObject()["flip"].toBool();
		value["mirror"] = jsonData["img_mirror_flip"].toObject()["mirror"].toBool();
		mMirrorFlip["set_img_mirror_flip"] = value;
		return setRequest(mMirrorFlip);
	}
	return false;
}
bool NetCameraPrivate::mInitCamera(NetCameraConf conf)
{
	l_sdk_discover_run(false);
	l_sdk_discover_close();
	l_sdk_logout(id);
	l_sdk_quit();
	l_sdk_init("");
	qDebug() << "初始化显微镜";
	mNetCameraConf = conf;
	mIsAvailable = false;
	QJsonObject loginJson = mCmdJson["login"].toObject();
	loginJson["ip"] = conf.ip;
	loginJson["port"] = conf.port;
	mCmdJson["login"] = loginJson;
	if (L_SUCC != l_sdk_login(&id, jsonToChar(loginJson)))
	{
		qDebug() << "NetCameraPrivate::mInitCamera::login failed";
		return false;
	}
	QThread::msleep(100);
	
	/*设置部分图像参数*/
	qDebug() << "NetCameraPrivate::mInitCamera::set_image" << mCmdJson["set_image"].toObject();
	mImageConf = mCmdJson["set_image"].toObject();
	QJsonObject imageValue = mImageConf["set_image"].toObject();
	imageValue["ezoom_value"] = conf.lowZoom;
	mImageConf["set_image"] = imageValue;
	if (!mSetRequest(mImageConf))
	{
		qDebug() << "NetCameraPrivate::mInitCamera::set_image error";
		return false;
	}
	/*获取部分图像参数范围*/
	mImageConf = mGetRequest(mCmdJson["get_image"].toObject());
	
	if (mImageConf.isEmpty())
	{
		qDebug() << "NetCameraPrivate::mInitCamera::get_image error";
		return false;
	}
	mImageConf["set_image"] = mImageConf.take("get_image"); // 删除旧key并获取value;
	mImageConf["cmd"] = "set_image";

	/*设置镜像参数*/
	mMirrorFlip = mCmdJson["set_img_mirror_flip"].toObject();
	QJsonObject value = mMirrorFlip["set_img_mirror_flip"].toObject();
	value["flip"] = conf.flipUD;
	value["mirror"] = conf.flipLR;
	mMirrorFlip["set_img_mirror_flip"] = value;
	if (!mSetRequest(mMirrorFlip))
	{
		qDebug() << "NetCameraPrivate::mInitCamera::::set_img_mirror_flip error";
		return false;
	}

	/*设置set_stream视频流信息*/
	qDebug() << "NetCameraPrivate::mInitCamera::::set_stream" << mCmdJson["set_stream"].toObject();
	if (!mSetRequest(mCmdJson["set_stream"].toObject()))
	{
        qDebug() << "NetCameraPrivate::mInitCamera::::set_stream error";
        return false;
	}


	/*设置自动白平衡*/
	if (!mSetRequest(mCmdJson["set_img_awb"].toObject()))
	{
		qDebug() << "NetCameraPrivate::mInitCamera::::set_stream error";
		return false;
	}

	/*设置自动曝光*/
	if (!mSetRequest(mCmdJson["set_img_meexposure"].toObject()))
	{
		qDebug() << "NetCameraPrivate::mInitCamera::::set_stream error";
		return false;
	}

	mIsAvailable = true;
	Q_Q(NetCamera);
	emit q->available(true);
	return true;
}
bool NetCameraPrivate::mOpen()
{
	/*开始流*/
	Q_Q(NetCamera);
	if (!mIsAvailable&& !mInitCamera(mNetCameraConf))
	{
		qDebug() << "NetCameraPrivate:mOpen:disconn";
		return false;
	}
	if (mIsStart)
	{
		return true;
	}
	if (!mSetRequest(mCmdJson["open_stream"].toObject()))
	{
        qDebug() << "NetCameraPrivate:mOpen:open_stream error";
		
        return false;
	}
	
	QJsonObject decJson =
	{
		{"pix_fmt", "RGB888"},
	};
	if (L_SUCC != l_sdk_dec_open(decId, jsonToChar(decJson)))
	{
		qDebug() << "NetCameraPrivate:mOpen:dec_open error";
		mIsAvailable = false;
		emit q->available(false);
		mIsStart = false;
        return false;
	}
	if (L_SUCC != l_sdk_dec_bind(decId, id, chnn, idx, 0))
	{
		l_sdk_dec_close(decId);
		qDebug()<<"NetCameraPrivate:mOpen:l_sdk_dec_bind error";
		mIsAvailable = false;
		emit q->available(false);
		mIsStart = false;
		return false;
	}
	mTimer->start(mReTime);
	mIsStart = true;
	return true;
}
bool NetCameraPrivate::mClose()
{
	/*停止流*/
	Q_Q(NetCamera);
	mIsStart = false;
	mTimer->stop();
	if (!mIsAvailable)
	{
		qDebug() << "mIsAvailable:" << mIsAvailable;
        return false;
	}
	if (!mSetRequest(mCmdJson["close_stream"].toObject()))
	{
		qDebug() << "NetCameraPrivate:mClose:close_stream error";
	}
	if (L_SUCC != l_sdk_dec_unbind(decId))
	{
		l_sdk_dec_close(decId);
		qDebug() << "l_sdk_dec_unbind error";
		//mIsAvailable = false;
		//emit q->available(false);
		//mIsStart = false;
	}
	if (L_SUCC != l_sdk_dec_close(decId))
	{
		qDebug() << "l_sdk_dec_close error";
		mIsAvailable = false;
		emit q->available(false);
		mIsStart = false;
	}
	QJsonObject value = mImageConf["set_image"].toObject();
	value["ezoom_value"] = mNetCameraConf.lowZoom;
	mImageConf["set_image"] = value;
	if (!mSetRequest(mImageConf))
	{
		qDebug() << "NetCameraPrivate:mClose:set_image error";
	}
	
	return true;
}
QJsonObject NetCameraPrivate::mGetRequest(const QJsonObject& requestJson)
{
	Q_Q(NetCamera);
	QJsonObject json;
	char* p_res = nullptr;
	/*获取stream视频流信息*/
	qDebug() << "NetCameraPrivate:mGetRequest：";
	qDebug().noquote()<<QString::fromUtf8(QJsonDocument( requestJson).toJson(QJsonDocument::Indented));
	bool isRequest = false;
	for (int i = 0; i < 2; i++)
	{
		if (L_SUCC == l_sdk_request(id, jsonToChar(requestJson), &p_res))
		{
			isRequest = true;
			break;
		}
		QThread::msleep(100);
	}
	if (!isRequest)
	{
		qDebug() << "NetCameraPrivate:mGetRequest error";
		mIsAvailable = false;
		emit q->available(false);
		mIsStart = false;
	}
	if (p_res != nullptr)
	{
		QByteArray rxData = QByteArray(p_res);
		json = charToJson(rxData);
		try
		{
			l_sdk_free(p_res);
		}
		catch (...)
		{

		}
	}
	QThread::msleep(100);
	qDebug() << "NetCameraPrivate:mGetRequest：back";
	qDebug().noquote() << QString::fromUtf8(QJsonDocument(json).toJson(QJsonDocument::Indented));
	return json;
}
bool NetCameraPrivate::mSetRequest(const QJsonObject& requestJson)
{
	/*获取stream视频流信息*/
	Q_Q(NetCamera);
	bool ret = true;
	int code = -1;
	char* p_res = nullptr;
	qDebug().noquote() << QString::fromUtf8(QJsonDocument(requestJson).toJson(QJsonDocument::Indented));
	bool isRequest = false;
	for (int i = 0; i < 2; i++)
	{
		if (L_SUCC == l_sdk_request(id, jsonToChar(requestJson), &p_res))
		{
			isRequest = true;
			break;
		}
		QThread::msleep(100);
	}
	if (!isRequest)
	{
		qDebug() << "NetCameraPrivate:mSetRequest error";
		
		//mClose();
		mIsAvailable = false;
		emit q->available(false);
		mIsStart = false;
		ret =  false;
	}
	if (p_res != nullptr)
	{
		QByteArray rxData = QByteArray(p_res);
		QJsonObject json = charToJson(rxData);
		if (json.contains("cmd"))
		{
			QString cmd = json["cmd"].toString();
			if (json[cmd].toObject().contains("code"))
			{
				code = json[cmd].toObject()["code"].toInt();
			}
		}
		try
		{
			l_sdk_free(p_res);
		}
		catch (...)
		{
			
		}
	}
	QThread::msleep(100);
	if (ret && (code == 0))
	{
		qDebug() << "NetCameraPrivate:mSetRequest true"<< code;
		return true;
	}
	mIsAvailable = false;
	emit q->available(false);
	mIsStart = false;
    return false;
}
void NetCameraPrivate::mGetVideoFrameData()
{
	static int takePhotoNum = 0;
	Q_Q(NetCamera);
	if(mIsStart)
	{
		l_md_data_t* p_md_data = NULL;
		if (L_SUCC == l_sdk_dec_get_md_data(decId, &p_md_data))
		{
			assert(NULL != p_md_data);
			if (NULL != p_md_data)
			{	//qDebug()<<"NetCameraPrivate:mGetVideoFrameData"<<p_md_data->w<<p_md_data->h;
				QImage img = QImage((uchar*)p_md_data->p_rgb, p_md_data->w, p_md_data->h, QImage::Format_RGB888).copy();
				l_sdk_dec_free_md_data(p_md_data);
				QVideoFrame frame = QVideoFrame(img.copy().scaled(1280, 720, Qt::KeepAspectRatio));
				emit videoFrameData(frame);
				if (isTakePictures && img.size() == QSize(3840, 2160) && takePhotoNum > 2)
				{
					takePhotoNum = 0;
					isTakePictures = false;
					qDebug() << "NetCameraPrivate:mGetVideoFrameData::picture";
					emit q->picture(img.copy());
					QJsonObject json = mCmdJson["set_stream"].toObject();
					QJsonObject value = json["set_stream"].toObject();
					value["wh"] = "1280*720";
					value["frame_rate"] = "25";
					json["set_stream"] = value;
					mSetRequest(json);
				}
				else if (isTakePictures && img.size() == QSize(3840, 2160))
				{
					takePhotoNum++;
				}

			}
		}
	}
}

void NetCameraPrivate::mQuit()
{
	mTimer->stop();
	delete mTimer;
	mTimer = nullptr;
}