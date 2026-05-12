#include "minios3client.h"


MinioS3Client* MinioS3Client::self = nullptr;
MinioS3Client* MinioS3Client::instance()
{
	static QMutex mutex;
	if (self == nullptr)
	{
		QMutexLocker locker(&mutex);
		if (self == nullptr)
		{
			self = new MinioS3Client();
		}
	}
	return self;
}
void MinioS3Client::destroy()
{
	if (self)
	{
		delete self;
		self = nullptr;
	}
}
MinioS3Client::MinioS3Client()
	: QThread()

{
	conf = AppConfig::instance()->minioConf();
	BaseUrl base_url(conf.addr.toStdString());
	//2.2 Create credential provider.
	provider = new minio::creds::StaticProvider(conf.accessKey.toStdString(), conf.secretKey.toStdString());
	//2.2 Create S3 client.
	client = new Client(base_url, provider);
	bucketArgs.bucket = conf.bucketKey.toStdString();
	start();
}
	
	

MinioS3Client::~MinioS3Client()
{
	requestInterruption();
	quit();
	wait();
	delete client;
    delete provider;

}
void MinioS3Client::addImage(Artifact::ImageInfo imageInfo)
{
	if (imageInfo.status == Artifact::ImageStatus::saved)
	{
		qDebug() << "addImage ImageStatus::saved";
		return;
	}
	QMutexLocker locker(&mMutex);
	mImageInfoList.append(imageInfo);
}

void MinioS3Client::run()
{
	while (!isInterruptionRequested())
	{
		// 执行周期性工作
		if (!mImageInfoList.isEmpty())
		{
			mMutex.lock();
           auto imageInfo = mImageInfoList.takeFirst();
           mMutex.unlock();
		   singleUploadImage(imageInfo);
		   QThread::msleep(100);
		}
		else
		{
            QThread::msleep(1000);
		}
		// 短暂休眠，避免CPU占用过高
		
	}
}
void MinioS3Client::singleUploadImage(Artifact::ImageInfo imageInfo)
{
	Artifact::ImageInfo mImageInfo = imageInfo;
	QString imaegeNameObject = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz") + "__" + mImageInfo.imageName + ".png";
	
	for (int i = 0; i < conf.reUploadNum; i++)
	{
		
		//Check bucket exist or not
		BucketExistsResponse bucketResp = client->BucketExists(bucketArgs);
		if (!bucketResp)
		{
			mImageInfo.status = Artifact::ImageStatus::saveFailed;
			qDebug() << "MinioS3Client::singleUploadImage::bucketResp failed";
			break;
		}
		else if(!bucketResp.exist)
		{
			mImageInfo.status = Artifact::ImageStatus::saveFailed;
			qDebug() << "MinioS3Client::singleUploadImage::bucketResp.exist failed";
			break;
		}

		//2.4 upload
		// Create upload object arguments.
		UploadObjectArgs uploadArgs;
		
		uploadArgs.bucket = conf.bucketKey.toStdString();
		uploadArgs.object = imaegeNameObject.toStdString();
		uploadArgs.filename = mImageInfo.imageLocalAddr.toStdString();
		uploadArgs.content_type = "image/jpeg";
		UploadObjectResponse uploadResp = client->UploadObject(uploadArgs);
		if (!uploadResp)
		{
			mImageInfo.status = Artifact::ImageStatus::saveFailed;
			qDebug()<<"MinioS3Client::singleUploadImage::uploadResp failed";
		}
		else
		{
			mImageInfo.status = Artifact::ImageStatus::saved;
			mImageInfo.imageNetAddr = conf.imageUrl  + imaegeNameObject;
			break;		
		}
	}
	emit uploadFinished(mImageInfo);
}

