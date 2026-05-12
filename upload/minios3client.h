#pragma once

#include <QObject>
#include <QImage>
#include "artifact.h"
#include <QThread>
#include <miniocpp/client.h>
#include "config/appconfig.h"

using namespace minio::s3;
class MinioS3Client  : public QThread
{
	Q_OBJECT

public:
    static MinioS3Client* instance();
    static void destroy();
	explicit MinioS3Client();
	~MinioS3Client();
	void addImage(Artifact::ImageInfo imageInfo);
signals:
	void uploadFinished(Artifact::ImageInfo imageInfo);
protected:
	void run() override;
private:
	static MinioS3Client* self;
	QList<Artifact::ImageInfo> mImageInfoList;
    QMutex mMutex;
	Client *client;
	BucketExistsArgs bucketArgs;
	minio::creds::StaticProvider *provider;
	MinioConf conf;
private:
	void singleUploadImage(Artifact::ImageInfo imageInfo);
};

