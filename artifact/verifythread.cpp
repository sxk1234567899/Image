#include <QtConcurrent>
#include "verifythread.h"
#include "appconfig.h"
#include "minios3client.h"
#include "networkserver.h"
#include "verifydb.h"
VerifyThread* VerifyThread::self;
VerifyThread* VerifyThread::instance()
{
	static QMutex mutex;
	if (self == nullptr)
	{
		QMutexLocker locker(&mutex);
		if (self == nullptr)
		{
			self = new VerifyThread();
		}
	}
	return self;
}
void VerifyThread::destroy()
{
	if (self != nullptr)
	{
		delete self;
		self = nullptr;
	}
}

VerifyThread::VerifyThread()
	: QThread(nullptr)
{
	connect(this, &VerifyThread::sigDeletedVerifyData, this, &VerifyThread::mDeleteVerifyData, Qt::BlockingQueuedConnection);
	connect(this, &VerifyThread::sigUpDataFinished, this, &VerifyThread::upDataFinished,Qt::BlockingQueuedConnection);
	connect(this, &VerifyThread::sigWaitEnd, this, &VerifyThread::waitEnd, Qt::BlockingQueuedConnection);
	
	
	auto appConfig = AppConfig::instance()->appConf();
	mNetCameraConf = AppConfig::instance()->netCameraConf();
	mVerifyImageDir = appConfig.verifyImageDir;
	mVerifyRawImageDir = appConfig.verifyRawImageDir;
	QString username = NetworkServer::instance()->userInfo().username;
	if (username.isEmpty())
	{
		username = "admin";
	}
	mMinioUpload = new MinioS3Client();
	connect(mMinioUpload, &MinioS3Client::uploadFinished, this, &VerifyThread::uploadFinished);

	verifyDB = new VerifyDB(username);
	verifyDB->openDB();
	

	QList<QHash<QString, QVariant>>infoDataList;
	verifyDB->getInfoData(infoDataList);
    for (auto infoData : infoDataList)
	{ 
		VerifyData* verifyData = new VerifyData;
		BaseInfo info;
		BatchInfo batchInfo;
		info.id = infoData["server_id"].toInt();
        info.number = infoData["number"].toString();
		info.name = infoData["name"].toString();
        info.mainImageAddr = infoData["mainImage"].toString();
		info.size = infoData["size"].toString();
		info.texture = infoData["texture"].toString();
		info.age = infoData["age"].toString();
        info.level = infoData["level"].toString();
		info.deptId = infoData["dept_id"].toInt();
		info.createTime = infoData["create_time"].toString();
        info.updateTime = infoData["update_time"].toString(); 
		info.regAgency = infoData["reg_agency"].toString();
		info.verifyTime = infoData["verify_time"].toString();
		batchInfo.id = infoData["batch_id"].toInt();
        batchInfo.code = infoData["batch_code"].toString();
        batchInfo.name = infoData["batch_name"].toString();
        batchInfo.applicant = infoData["batch_applicant"].toString();
        batchInfo.carrier = infoData["batch_carrier"].toString();
		batchInfo.exhibitionTitle = infoData["batch_exhibitionTitle"].toString();
		verifyData->baseInfo = info;
		verifyData->batchInfo = batchInfo;
        verifyData->verifyNO = infoData["verify_no"].toInt();
		verifyData->isVerifyFinished = (VerifyData::VerifyStatus)infoData["verify_status"].toInt();
		verifyDataList.insert(verifyData->baseInfo.number, verifyData);
		QList<QHash<QString, QVariant>>imageDataList;
		/*加载验证照片信息*/
		verifyDB->getImageData(imageDataList, info.number);
        for (auto imageData : imageDataList) 
		{ 
            ImageInfo imageInfo;
			imageInfo.id = imageData["image_id"].toInt();
			imageInfo.number = imageData["number"].toString();
			imageInfo.imageName = imageData["name"].toString();
			imageInfo.imageNetAddr = imageData["net_addr"].toString();
			imageInfo.imageLocalAddr = imageData["local_addr"].toString();
			imageInfo.status = (ImageStatus)imageData["status"].toInt();
			imageInfo.imageLocalDir = mVerifyImageDir;
			verifyDataList[imageInfo.number]->imageInfo[imageInfo.imageName] = imageInfo;

			if (imageInfo.imageName.startsWith("VRF_D_01_") && imageInfo.imageName.size() == 16)
			{
				verifyDataList[imageInfo.number]->globalImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("VRF_W_03_"))
			{
				verifyDataList[imageInfo.number]->lowImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("VRF_W_02_"))
			{
				verifyDataList[imageInfo.number]->highImage[imageInfo.imageName] = QImage();
			}

			if (imageInfo.status == ImageStatus::unsaved)
			{
				mMinioUpload->addImage(imageInfo);
			}

			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
        }

		/*加载原始照片信息*/
		verifyDB->getRawImageData(imageDataList, info.number);
		for (auto imageData : imageDataList)
		{
			ImageInfo imageInfo;
			imageInfo.id = imageData["image_id"].toInt();
			imageInfo.number = imageData["number"].toString();
			imageInfo.imageName = imageData["name"].toString();
			imageInfo.imageNetAddr = imageData["net_addr"].toString();
			imageInfo.imageLocalAddr = imageData["local_addr"].toString();
			imageInfo.status = (ImageStatus)imageData["status"].toInt();
			imageInfo.imageLocalDir = mVerifyRawImageDir;
			verifyDataList[imageInfo.number]->rawImageInfo[imageInfo.imageName] = imageInfo;
			if (imageInfo.imageName.startsWith("D_01_") && imageInfo.imageName.size() == 12)
			{
				verifyDataList[imageInfo.number]->rawGlobalImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("D_01_"))
			{
				verifyDataList[imageInfo.number]->rawMarkedImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("W_03_"))
			{
				verifyDataList[imageInfo.number]->rawLowImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("W_02_"))
			{
				verifyDataList[imageInfo.number]->rawHighImage[imageInfo.imageName] = QImage();;
			}

			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}

		verifyDataList[info.number]->verifyNO = 1;
		if (verifyDataList[info.number]->globalImage.size() != verifyDataList[info.number]->rawGlobalImage.size())
		{
			verifyDataList[info.number]->verifyNO = 2;
		}
		else
		{
			verifyDataList[info.number]->verifyNO = 3;
		}
	}
	start();
}

VerifyThread::~VerifyThread()
{
	updateVerifyData();
	requestInterruption();
	quit();
	wait();
	for (auto it = verifyDataList.begin(); it != verifyDataList.end();)
	{
		delete it.value();
		it = verifyDataList.erase(it);
	}
	if (verifyDB)
	{
		delete verifyDB;
		verifyDB = nullptr;
	}
}


void VerifyThread::uploadFinished(Artifact::ImageInfo imageInfo)
{
	QString number = imageInfo.number;
	QString name = imageInfo.imageName;
	if(!verifyDataList.contains(number)|| !verifyDataList[number]->imageInfo.contains(name))
	{
		qDebug() << "VerifyThread::uploadFinished" << number << name << "not found";
		return;
	}
	verifyDataList[number]->imageInfo[name] = imageInfo;
	verifyDB->updateImageData(imageInfoStructToHash(imageInfo), number,name);
	emit verifyDataUpdated(number);
}
bool VerifyThread::addNewVerifyData(BaseInfo info , BatchInfo batchInfo)
{
	if (verifyDataList.contains(info.number))
	{
		deleteVerifyData(info.number);
	}
	VerifyData* verifyData = new VerifyData;
    verifyData->baseInfo = info;
	if (info.createTime.isEmpty())
	{
		verifyData->baseInfo.createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

	}
	verifyData->batchInfo = batchInfo;
	verifyDataList.insert(verifyData->baseInfo.number, verifyData);
	mCurrNumber = verifyData->baseInfo.number;
    verifyDB->addInfoData(infoStructToHash(verifyData));
	emit verifyDataAdded(info.number);
	qDebug() << "VerifyThread::addNewVerifyData" << info.number << "added";
    return verifyDataList.contains(info.number);
}
bool VerifyThread::updateVerifyData(QString number, BaseInfo info,  BatchInfo batchInfo)
{
	if (!verifyDataList.contains(number))
	{
		return false;
	}
	verifyDataList[number]->baseInfo = info;
    verifyDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    verifyDataList[number]->batchInfo = batchInfo;
	verifyDataList[number]->verifyNO = 0;
	verifyDB->updateInfoData(infoStructToHash(verifyDataList[number]), number);
	qDebug() << "VerifyThread::updateVerifyData" << number << "updated";
	emit verifyDataUpdated(number);
	return true;  
}
bool VerifyThread::updateVerifyData(QString number)
{
	if (number.isEmpty())
	{
		number = mCurrNumber;
	}
	if (!verifyDataList.contains(number))
	{
		return false;
	}
	verifyDB->updateInfoData(infoStructToHash(verifyDataList[number]), number);
	emit verifyDataUpdated(number);
	return true;
}
bool VerifyThread::updateVerifyResult(QString number)
{
	QJsonObject jsonData;
	if (!verifyDataList.contains(number))
	{
		return false;
	}
	auto verifyData = verifyDataList[number];
	if (NetworkServer::instance()->getArtifactsDetailInfo(verifyData->baseInfo.id, verifyData->baseInfo.number, &jsonData, true))
	{
		if (jsonData["code"].toInt() == 200 && jsonData["success"].isBool())
		{
			Artifact::BaseInfo info = verifyData->baseInfo;
			QJsonObject infoObj = jsonData["data"].toObject()["details"].toObject();
			info.id = infoObj["id"].toInt();
			info.deptId = infoObj["dept_id"].toInt();
			info.number = infoObj["artifact_number"].toString();
			info.mainImageAddr = infoObj["main_image"].toString();
			info.name = infoObj["artifact_name"].toString();
			info.size = infoObj["size"].toString();
			info.age = infoObj["age"].toString();
			info.texture = infoObj["texture"].toString();
			info.level = infoObj["level"].toString();
			info.stauts = infoObj["status"].toString();
			info.unitId = infoObj["unit_id"].toInt();
			info.weight = infoObj["weight"].toInt();

			info.remarks = infoObj["remarks"].toString();
			info.createTime = infoObj["created_at"].toString();
			info.updateTime = infoObj["updated_at"].toString();
			info.verifyTime	= infoObj["updated_at"].toString();
			QJsonArray deptsData = infoObj["unit"].toObject()["depts"].toArray();
			if (deptsData.size() > 0)
			{
				QJsonObject deptData = deptsData[0].toObject();
				info.regAgency = deptData["name"].toString();
			}
			if (jsonData["data"].toObject()["verifyResult"].isObject())
			{
				info.verifyResult = jsonData["data"].toObject()["verifyResult"].toObject()["verify_status"].toString();
			}
			else
			{
				info.verifyResult = "未验证";
			}
			waitEnd(info.number,info);
			return true;
		}
	}
	return false;
}
BaseInfo VerifyThread::getBaseInfo(QString number)
{
	if (!verifyDataList.contains(number))
	{
		return BaseInfo();
	}
    return verifyDataList[number]->baseInfo;
}
BatchInfo VerifyThread::getBatchInfo(QString number)
{
	if (!verifyDataList.contains(number))
	{
		return BatchInfo();
	}
	return verifyDataList[number]->batchInfo;
}
bool VerifyThread::loadRawImageFinished(QString number)
{
	if (!verifyDataList.contains(number))
	{
		return false;
	}
	verifyDataList[number]->isVerifyFinished = VerifyData::Verify_Runing;
	updateVerifyData(number);
	return true;
}
bool VerifyThread::verifyFinished(QString number)
{
	if (!verifyDataList.contains(number))
	{
		return false;
	}
	verifyDataList[number]->isVerifyFinished = VerifyData::Verify_UpData;
	updateVerifyData(number);
	return true;
}
void VerifyThread::upDataFinished(QString number)
{
	if (!verifyDataList.contains(number))
	{
		return ;
	}
	verifyDataList[number]->isVerifyFinished = VerifyData::Verify_Waiting;
	updateVerifyData(number);
}
void VerifyThread::waitEnd(QString number,BaseInfo baseInfo)
{ 
	if (!verifyDataList.contains(number))
	{
		return;
	}
    verifyDataList[number]->baseInfo = baseInfo;
	verifyDataList[number]->isVerifyFinished = VerifyData::Verify_Finished;
	if (baseInfo.verifyTime.isEmpty())
	{
		verifyDataList[number]->baseInfo.verifyTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	}
	updateVerifyData(number);
	emit showVerifyResult(number);
}
bool VerifyThread::setVerifyNo(QString number, int verifyNo)
{
	if (!verifyDataList.contains(number))
	{
		return false;
	}
	verifyDataList[number]->verifyNO = verifyNo;
	return true;
}
int VerifyThread::getVerifyNo(QString number)
{
	if (!verifyDataList.contains(number))
	{
		return -1;
	}
	verifyDataList[number]->verifyNO = 1;
	if (verifyDataList[number]->rawGlobalImage.size() > 0)
	{
		if ((verifyDataList[number]->rawGlobalImage.size() == verifyDataList[number]->globalImage.size())
			&&(verifyDataList[number]->rawMarkedImage.size() > 0))
		{
			
            verifyDataList[number]->verifyNO = 3;
		}
		else
		{
            verifyDataList[number]->verifyNO = 2;
		}
	}
	return verifyDataList[number]->verifyNO;
}
QString VerifyThread::getVerifyNumber()
{
	return mCurrNumber;
}
bool VerifyThread::setVerifyNumber(QString number)
{
	if (!verifyDataList.contains(number))
    {
		return false;
    }
	mCurrNumber = number;
	return true;
    
}
QStringList VerifyThread::getVerifyDataList()
{
	return verifyDataList.keys();
}
const VerifyData* VerifyThread::getVerifyData(QString number, bool* isOk)const
{
	if (!verifyDataList.contains(number))
	{
		if(isOk)
		{
			*isOk = false;
		}
		return nullptr;
	}
	if (isOk)
	{
		*isOk = true;
	}
	return verifyDataList[number];
}
bool VerifyThread::addMainImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
    {
		qDebug() << "VerifyThread::addMainImage" << number << name<<"error";
        return false;
    }
	verifyDataList[number]->mainImageName = name;
    verifyDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    return true;
}
QImage VerifyThread::getMainImage(QString number)
{
	if (!verifyDataList.contains(number))
    {
		qDebug() << "VerifyThread::getMainImage" << number << "error";
        return QImage();
    }
	if (!verifyDataList[number]->globalImage.contains(verifyDataList[number]->mainImageName))
	{
		qDebug()<< "VerifyThread::getMainImage" << verifyDataList[number]->mainImageName << "error";
		return QImage();
	}
    return verifyDataList[number]->globalImage.value(verifyDataList[number]->mainImageName);
}

QString VerifyThread::globalImageName(QString number, int index)
{
	if (!verifyDataList.contains(number))
	{
		return QString();
	}
	return QString::asprintf("D_01_%03d_", verifyDataList[mCurrNumber]->globalImage.size() + 1) + (gImgNameList[index]);

}
QString VerifyThread::lowImageName(QString number, QString markImageName, bool isUnique)
{
	if (!verifyDataList.contains(number))
	{
		return QString();
	}
	QString lowName = markImageName;
	if (lowName.startsWith("D_01_"))
	{
		lowName.replace("D_01_", "W_03_");
	}
	else if (lowName.startsWith("W_02_"))
	{
		lowName.replace("W_02_", "W_03_");
	}
	/*已经存在低倍则需要先删除再添加*/
	if (isUnique&&verifyDataList[number]->lowImage.contains(lowName))
	{
		lowName = QString();
	}
	return lowName;
}
QString VerifyThread::highImageName(QString number, QString lowImageName, bool isUnique)
{
	if( !verifyDataList.contains(number))
	{
		return QString();
	}
	QString highName = lowImageName;
	if(highName.startsWith("W_03_"))
	{
		highName.replace("W_03_", "W_02_");
	}
	else if(highName.startsWith("D_01_"))
	{
		highName.replace("D_01_", "W_02_");
	}
	/*已经存在高倍则需要先删除再添加*/
	if (isUnique&&verifyDataList[number]->highImage.contains(highName))
	{
		highName = QString();
	}
	return highName;
}

bool VerifyThread::addImage(QString number, QString name, QImage image, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap, int id,bool isUpload)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addImage" << number << "number not exist";
		return false;
	}
	if (imageMap.contains(name))
	{
		qDebug() << "VerifyThread::addImage" << imageNameShow(name) << "already exist";
		return false;
	}
	ImageInfo imageInfo;
	imageInfo.id = id;
	imageInfo.number = number;
	imageInfo.imageName = name;
	imageInfo.status = ImageStatus::unsaved;
	imageInfo.imageLocalDir = mVerifyImageDir;
	imageInfo.imageLocalAddr = mVerifyImageDir;
	imageInfo.imageLocalAddr.append("/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz") + "__" + name + ".png");

	imageMap[name] = imageInfo;
	imageDataMap[name] = image.copy();
	verifyDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	emit imageAdded(number, name);
	emit verifyDataUpdated(number);
	verifyDB->addImageData(imageInfoStructToHash(imageInfo));
	qDebug() << "VerifyThread::addImage" << imageNameShow(name) << "added";
	/*保存到本地*/
	/*第一步:保持照的到本地*/
	QFuture<void> future = QtConcurrent::run([this, &imageMap, name, isUpload, imageInfo, image]() {
		if (image.save(imageInfo.imageLocalAddr))
		{
			if (isUpload)
			{
				mMinioUpload->addImage(imageInfo);
			}
		}
		else
		{
			imageMap[name].status = ImageStatus::saveFailed;
		}
		});
	return true;
}
bool VerifyThread::deleteImage(QString number, QString name, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteImage" << number << "number not exist";
		return false;
	}
	if (!imageMap.contains(name))
	{
		qDebug() << "VerifyThread::deleteImage" << imageNameShow(name) << "not exist";
		return false;
	}
	/*TODO 需要删除本地照片*/
	QFile::remove(imageMap[name].imageLocalAddr);
	verifyDB->deleteImageData(number, name);
	imageMap.remove(name);
	imageDataMap.remove(name);
	verifyDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	emit imageDeleted(number, name);
	emit verifyDataUpdated(number);
	qDebug() << "VerifyThread::deleteImage" << imageNameShow(name) << "deleted";
	return true;
}
bool VerifyThread::addRawImage(QString number, QString name, QImage image, ImageInfo info, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addRawImage" << number << "number not exist";
		return false;
	}
	if (imageMap.contains(name))
	{
		qDebug() << "VerifyThread::addRawImage" << imageNameShow(name) << "already exist";
		return false;
	}
	imageMap[name] = info;
	imageMap[name].status = ImageStatus::saved;
	imageDataMap[name] = image.copy();
	verifyDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	//emit imageAdded(number, name);
	//emit verifyDataUpdated(number);
	verifyDB->addRawImageData(imageInfoStructToHash(imageMap[name]));
	qDebug() << "VerifyThread::addRawImage" << imageNameShow(name) << "added";
	/*保存到本地*/
	/*第一步:保持照的到本地*/
	QFuture<void> future = QtConcurrent::run([this, info, image]() {
		image.save(info.imageLocalAddr);
		});
	return true;
}
bool VerifyThread::deleteRawImage(QString number, QString name, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteRawImage" << number << "number not exist";
		return false;
	}
	if (!imageMap.contains(name))
	{
		qDebug() << "VerifyThread::deleteRawImage" << imageNameShow(name) << "not exist";
		return false;
	}
	QFile::remove(imageMap[name].imageLocalAddr);
    verifyDB->deleteRawImageData(number, name);
	imageMap.remove(name);
	imageDataMap.remove(name);
	verifyDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	//emit imageDeleted(number, name);
	//emit verifyDataUpdated(number);
	qDebug() << "VerifyThread::deleteRawImage" << imageNameShow(name) << "deleted";
	return true;
}

bool VerifyThread::addGlobalImage(QString number, QString name, QImage image, int id)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addGlobalImage" << number << "number not exist";
		return false;
	}
	return addImage(number, name, image, verifyDataList[number]->imageInfo, verifyDataList[number]->globalImage,id);
}

bool VerifyThread::addLowImage(QString number, QString name, QImage image, int id)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addLowImage" << number << "number not exist";
		return false;
	}
	return addImage(number, name, image, verifyDataList[number]->imageInfo, verifyDataList[number]->lowImage, id);
}
bool VerifyThread::addHighImage(QString number, QString name, QImage image, int id)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addHighImage" << number << "number not exist";
		return false;
	}
	return addImage(number, name, image, verifyDataList[number]->imageInfo, verifyDataList[number]->highImage, id);
}
bool VerifyThread::deleteGlobalImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteGlobalImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, verifyDataList[number]->imageInfo, verifyDataList[number]->globalImage);
}

bool VerifyThread::deleteLowImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteLowImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, verifyDataList[number]->imageInfo, verifyDataList[number]->lowImage);
}
bool VerifyThread::deleteHighImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteHighImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, verifyDataList[number]->imageInfo, verifyDataList[number]->highImage);
}
bool VerifyThread::deleteAllMarkImage(QString number)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteHighImage" << number << "number not exist";
		return false;
	}
	QList<ImageInfo> removeList;
	for (auto key : verifyDataList[number]->rawMarkedImage.keys())
	{
		removeList.append(verifyDataList[number]->rawImageInfo.take(key));
		verifyDB->deleteRawImageData(number, key);
	}
	for (auto key : verifyDataList[number]->rawLowImage.keys())
	{
		removeList.append(verifyDataList[number]->rawImageInfo.take(key));
		verifyDB->deleteRawImageData(number, key);
	}
	for (auto key : verifyDataList[number]->rawHighImage.keys())
	{
		removeList.append(verifyDataList[number]->rawImageInfo.take(key));
		verifyDB->deleteRawImageData(number, key);
	}
	verifyDataList[number]->rawMarkedImage.clear();
	verifyDataList[number]->rawLowImage.clear();
	verifyDataList[number]->rawHighImage.clear();
	for (auto key : verifyDataList[number]->lowImage.keys())
	{
		removeList.append(verifyDataList[number]->imageInfo.take(key));
        verifyDB->deleteImageData(number, key);
	}
	for (auto key : verifyDataList[number]->highImage.keys())
	{
		removeList.append(verifyDataList[number]->imageInfo.take(key));
		verifyDB->deleteImageData(number, key);
	}
	verifyDataList[number]->lowImage.clear();
	verifyDataList[number]->highImage.clear();
	auto futer = QtConcurrent::run([removeList]() {
		for (auto info : removeList)
		{
			QFile::remove(info.imageLocalAddr);
		}
		});
	return true;
}
bool VerifyThread::updateImageInfo(QString number, QString imageName, const ImageInfo info)
{
	if (!verifyDataList.contains(number))
	{
		qDebug()<< "VerifyThread::updateImageInfo" << number << "number not exist";
		return false;
	}
	if (!verifyDataList[number]->imageInfo.contains(imageName))
	{
		qDebug() << "VerifyThread::updateImageInfo" << imageName << "imageName not exist";
		return false;
	}
	verifyDataList[number]->imageInfo[imageName] = info;
	if (info.status == ImageStatus::unsaved)
	{
		mMinioUpload->addImage(info);
	}
	return true;
}
bool VerifyThread::getImageInfo(QString number, QString imageName,ImageInfo* info)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::updateImageInfo" << number << "number not exist";
		return false;
	}
	if (!verifyDataList[number]->imageInfo.contains(imageName))
	{
		qDebug() << "VerifyThread::updateImageInfo" << imageName << "imageName not exist";
		return false;
	}
	*info = verifyDataList[number]->imageInfo[imageName];
	return true;
}


/*y原始图片*/
bool VerifyThread::addRawGlobalImage(QString number, QString name, QImage image, ImageInfo info)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addGlobalImage" << number << "number not exist";
		return false;
	}
	return addRawImage(number, name, image, info, verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawGlobalImage);
}
bool VerifyThread::addRawMarkedImage(QString number, QString name, QImage image, ImageInfo info)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addMarkedImage" << number << "number not exist";
		return false;
	}
	return addRawImage(number, name, image, info,verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawMarkedImage);
}
bool VerifyThread::addRawLowImage(QString number, QString name, QImage image, ImageInfo info)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addLowImage" << number << "number not exist";
		return false;
	}
	return addRawImage(number, name, image,info, verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawLowImage);
}
bool VerifyThread::addRawHighImage(QString number, QString name, QImage image, ImageInfo info)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::addHighImage" << number << "number not exist";
		return false;
	}
	return addRawImage(number, name, image,info, verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawHighImage);
}
bool VerifyThread::deleteRawGlobalImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteGlobalImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawGlobalImage);
}
bool VerifyThread::deleteRawMarkedImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteMarkedImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawMarkedImage);
}
bool VerifyThread::deleteRawLowImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteLowImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawLowImage);
}
bool VerifyThread::deleteRawHighImage(QString number, QString name)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteHighImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, verifyDataList[number]->rawImageInfo, verifyDataList[number]->rawHighImage);
}
bool VerifyThread::deleteAllRawMarkImage(QString number)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteHighImage" << number << "number not exist";
		return false;
	}
	for (auto key : verifyDataList[number]->rawMarkedImage.keys())
	{
		verifyDataList[number]->imageInfo.remove(key);
	}
	for (auto key : verifyDataList[number]->rawLowImage.keys())
	{
		verifyDataList[number]->imageInfo.remove(key);
	}
	for (auto key : verifyDataList[number]->lowImage.keys())
	{
		verifyDataList[number]->imageInfo.remove(key);
	}
	for (auto key : verifyDataList[number]->rawHighImage.keys())
	{
		verifyDataList[number]->imageInfo.remove(key);
	}
	for (auto key : verifyDataList[number]->highImage.keys())
	{
		verifyDataList[number]->imageInfo.remove(key);
	}
	verifyDataList[number]->rawMarkedImage.clear();
	verifyDataList[number]->rawLowImage.clear();
	verifyDataList[number]->rawHighImage.clear();
	verifyDataList[number]->lowImage.clear();
	verifyDataList[number]->highImage.clear();
	return true;
}
bool VerifyThread::updateRawImageInfo(QString number, QString imageName, const ImageInfo info)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::updateImageInfo" << number << "number not exist";
		return false;
	}
	if (!verifyDataList[number]->rawImageInfo.contains(imageName))
	{
		qDebug() << "VerifyThread::updateImageInfo" << imageName << "imageName not exist";
		return false;
	}
	verifyDataList[number]->rawImageInfo[imageName] = info;
	return true;
}
bool VerifyThread::getRawImageInfo(QString number, QString imageName, ImageInfo* info)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::updateImageInfo" << number << "number not exist";
		return false;
	}
	if (!verifyDataList[number]->rawImageInfo.contains(imageName))
	{
		qDebug() << "VerifyThread::updateImageInfo" << imageName << "imageName not exist";
		return false;
	}
	*info = verifyDataList[number]->rawImageInfo[imageName];
	return true;
}


bool VerifyThread::deleteVerifyData(QString number)
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::deleteVerifyData" << number << "number not exist";
		return false;
	}
	auto verifyData = verifyDataList.value(number);
	auto imageInfo = verifyData->imageInfo;
	imageInfo.insert(verifyData->rawImageInfo);
	//NetworkServer::instance()->postArtifactsStatus(verifyData->baseInfo.id, "未开始",nullptr,true);
	delete verifyData;
	verifyDataList.remove(number);
	/*需要删除本地照片*/
	auto futer = QtConcurrent::run([imageInfo]() {
		for (auto info : imageInfo)
		{
			QFile::remove(info.imageLocalAddr);
		}
		});
    verifyDB->deleteInfoData(number);
	emit verifyDataDeleted(number);
	
	return true;
}
const QMap<QString, QImage>* VerifyThread::getGlobalImage(QString number)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::getGlobalImage" << number << "number not exist";
		return nullptr;
	}
	for (auto data = verifyDataList[number]->globalImage.begin(); data != verifyDataList[number]->globalImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(verifyDataList[number]->imageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}
	}
	return &(verifyDataList[number]->globalImage);
}
const QMap<QString, QImage>* VerifyThread::getLowImage(QString number)const
{
    if (!verifyDataList.contains(number))
    {
        qDebug() << "VerifyThread::getLowImage" << number << "number not exist";
        return nullptr;
    }
	for (auto data = verifyDataList[number]->lowImage.begin(); data != verifyDataList[number]->lowImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(verifyDataList[number]->imageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}
	}
    return &(verifyDataList[number]->lowImage);
}
const QMap<QString, QImage>* VerifyThread::getHighImage(QString number)const
{
    if (!verifyDataList.contains(number))
    {
        qDebug() << "VerifyThread::getHighImage" << number << "number not exist";
        return nullptr;
    }
    for (auto data = verifyDataList[number]->highImage.begin(); data != verifyDataList[number]->highImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(verifyDataList[number]->imageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}
	}
    return &(verifyDataList[number]->highImage);
}


const QMap<QString, ImageInfo>* VerifyThread::geImageInfoList(QString number)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::getGlobalImageInfo" << number << "number not exist";
		return nullptr;
	}
	return &(verifyDataList[number]->imageInfo);
}

const QMap<QString, QImage>* VerifyThread::getRawGlobalImage(QString number)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::getGlobalImage" << number << "number not exist";
		return nullptr;
	}
	for (auto data = verifyDataList[number]->rawGlobalImage.begin(); data != verifyDataList[number]->rawGlobalImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(verifyDataList[number]->rawImageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}	
	}
	return &(verifyDataList[number]->rawGlobalImage);
}
const QMap<QString, QImage>* VerifyThread::getRawMarkedImage(QString number)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::getLowImage" << number << "number not exist";
		return nullptr;
	}
	for (auto data = verifyDataList[number]->rawMarkedImage.begin(); data != verifyDataList[number]->rawMarkedImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(verifyDataList[number]->rawImageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}
	}
	return &(verifyDataList[number]->rawMarkedImage);
}
const QMap<QString, QImage>* VerifyThread::getRawLowImage(QString number)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::getLowImage" << number << "number not exist";
		return nullptr;
	}
	for (auto data = verifyDataList[number]->rawLowImage.begin(); data != verifyDataList[number]->rawLowImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(verifyDataList[number]->rawImageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}
	}
	return &(verifyDataList[number]->rawLowImage);
}
const QMap<QString, QImage>* VerifyThread::getRawHighImage(QString number)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::getHighImage" << number << "number not exist";
		return nullptr;
	}
	for (auto data = verifyDataList[number]->rawHighImage.begin(); data != verifyDataList[number]->rawHighImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(verifyDataList[number]->rawImageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
		}
	}
	return &(verifyDataList[number]->rawHighImage);
}


const QMap<QString, ImageInfo>* VerifyThread::geRawImageInfoList(QString number)const
{
	if (!verifyDataList.contains(number))
	{
		qDebug() << "VerifyThread::getGlobalImageInfo" << number << "number not exist";
		return nullptr;
	}
	return &(verifyDataList[number]->rawImageInfo);
}


QHash<QString, QString> VerifyThread::infoStructToHash(const VerifyData * verifyData, bool isDel)const
{
	QHash<QString, QString> infoHash;
	infoHash.insert("server_id", QString::number(verifyData->baseInfo.id));
	infoHash.insert("number", verifyData->baseInfo.number);
	infoHash.insert("name", verifyData->baseInfo.name);
	infoHash.insert("size", verifyData->baseInfo.size);
	infoHash.insert("texture", verifyData->baseInfo.texture);
	infoHash.insert("age", verifyData->baseInfo.age);
	infoHash.insert("level", verifyData->baseInfo.level);
	infoHash.insert("dept_id", QString::number(verifyData->baseInfo.deptId));
	infoHash.insert("verify_no", QString::number(verifyData->verifyNO));
	infoHash.insert("batch_id", QString::number(verifyData->batchInfo.id));
	infoHash.insert("batch_code", verifyData->batchInfo.code);
	infoHash.insert("batch_name", verifyData->batchInfo.name);
	infoHash.insert("batch_applicant", verifyData->batchInfo.applicant);
	infoHash.insert("batch_carrier", verifyData->batchInfo.carrier);
	infoHash.insert("batch_exhibitionTitle", verifyData->batchInfo.exhibitionTitle);
	infoHash.insert("reg_agency", verifyData->baseInfo.regAgency);
	infoHash.insert("verify_status", QString::number(verifyData->isVerifyFinished));
    infoHash.insert("verify_result", verifyData->baseInfo.verifyResult);
    infoHash.insert("verify_time", verifyData->baseInfo.verifyTime);
	infoHash.insert("create_time", verifyData->baseInfo.createTime);
	infoHash.insert("update_time", verifyData->baseInfo.updateTime);
	infoHash.insert("is_deleted",QString::number(isDel));
	qDebug() << "VerifyThread::infoStructToHash" << infoHash;
    return infoHash;
}
QHash<QString, QString> VerifyThread::imageInfoStructToHash(const ImageInfo imageInfo, bool isDel)const
{
	QHash<QString, QString> imageInfoHash;
	imageInfoHash["image_id"] = QString::number(imageInfo.id);
	imageInfoHash["number"] = imageInfo.number;
	imageInfoHash["name"] = imageInfo.imageName;
	imageInfoHash["net_addr"] = imageInfo.imageNetAddr;
	imageInfoHash["local_addr"] = imageInfo.imageLocalAddr;
	imageInfoHash["status"] = QString::number(imageInfo.status);
	imageInfoHash["create_time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	imageInfoHash["is_deleted"] = QString::number(isDel);

	return imageInfoHash;
}

void VerifyThread::run()
{
	while (!isInterruptionRequested()) 
	{
		// 执行周期性工作
		doWork();
		// 短暂休眠，避免CPU占用过高
		QThread::msleep(100);
	}
}
void VerifyThread::doWork()
{

	static int count = 0;
	if (count % 60 == 0)
	{

		for (auto i = verifyDataList.begin(); i != verifyDataList.end();)
		{
			/*验证时间超过31天删除*/
			QDateTime verifyTime = QDateTime::fromString(i.value()->baseInfo.verifyTime, "yyyy-MM-dd hh:mm:ss");
			if (verifyTime.daysTo(QDateTime::currentDateTime()) > 31)
			{
				auto number = i.key();
				i++;
				qDebug() << "VerifyThread::删除数据" << number;
				emit sigDeletedVerifyData(number);
			}
			else
			{
				i++;
			}
		}
	}
	for (auto i = verifyDataList.begin(); i != verifyDataList.end();i++)
	{
		if (i.value()->isVerifyFinished == VerifyData::Verify_UpData)
		{/*上传数据*/
			//qDebug() << "VerifyThread::上传数据";
			/*登记结束*/
			const auto data = i.value();
			bool isAllSaved = true;
			for (auto imageInfo : data->imageInfo)
			{
				if (imageInfo.status != saved)
				{
					isAllSaved = false;
					break;
				}
			}
			if (!isAllSaved)
			{
				continue;
			}
			QJsonObject jsonData;
			//jsonData.insert("weight", QString());
			jsonData.insert("artifact_category", 3);
			jsonData.insert("sampling_id", data->baseInfo.id);
			jsonData.insert("weight", "0kg");
			QJsonArray aroundInfos;
			for (auto j = data->globalImage.begin(); j != data->globalImage.end(); ++j)
			{
				QJsonObject aroundInfo;
				QString part;
				QString name = j.key();
				auto pos = j.key().split("_");
				if (pos.size() >= 4)
				{
					int index = gImgNameList.indexOf(pos[4]);
					if (index >= 0 && index < gImgShowNameList.size())
					{
						part = gImgShowNameList[index];
					}
				}

				aroundInfo.insert("part", part);
				aroundInfo.insert("img", data->imageInfo[name].imageNetAddr);
				aroundInfo.insert("attr", QJsonObject());
				aroundInfo.insert("selected_id", data->imageInfo[name].id);
				aroundInfos.append(aroundInfo);
			}

			jsonData.insert("aroundInfos", aroundInfos);

			if(!data->rawMarkedImage.isEmpty())
			{
				QJsonArray inspectInfos;
				for (auto k = data->rawMarkedImage.begin(); k != data->rawMarkedImage.end(); k++)
				{
					QJsonObject inspectInfo;
					QString tempName = k.key();
					tempName.replace("D_01_", "W_03_");;
					QString lowName = gVerifyNameHeader + tempName;
					QString highName = lowName;
					highName.replace("W_03_", "W_02_");
					inspectInfo.insert("selected_id", data->rawImageInfo[k.key()].id);
					inspectInfo.insert("mark_point_image", data->rawImageInfo[k.key()].imageNetAddr);

					QJsonObject lowImageInfo;
					lowImageInfo.insert("img", data->imageInfo[lowName].imageNetAddr);
					QJsonObject lowAttr;
					lowAttr.insert("zoom", QString::number(mNetCameraConf.lowZoom));
					lowImageInfo.insert("attr", lowAttr);
					inspectInfo.insert("low_mag_image", lowImageInfo);

					QJsonObject highImageInfo;
					highImageInfo.insert("img", data->imageInfo[highName].imageNetAddr);
					QJsonObject highAttr;
					highAttr.insert("zoom", QString::number(mNetCameraConf.highZoom));
					highImageInfo.insert("attr", highAttr);
					inspectInfo.insert("high_mag_image", highImageInfo);

					inspectInfos.append(inspectInfo);
				}

				jsonData.insert("inspectInfos", inspectInfos);
			}


			qDebug() << "VerifyThread::doWork:jsonData";
			qDebug().noquote() << QString::fromUtf8(QJsonDocument(jsonData).toJson(QJsonDocument::Indented));
			bool isOK = false;
			for (int i = 0; i < 3; i++)
			{
				isOK = NetworkServer::instance()->postArtifactUpData(jsonData,true);
				if (isOK)
				{
					break;
				}
			}
			if (isOK)
			{
				
				//NetworkServer::instance()->postArtifactsStatus(data->baseInfo.id, "已完成",nullptr,true);
				emit sigUpDataFinished(data->baseInfo.number);
			}
		}
		else if (i.value()->isVerifyFinished == VerifyData::Verify_Waiting &&count%30 == 0)
		{ /*获取验证结果*/
			qDebug() << "VerifyThread::获取验证结果";
            QJsonObject jsonData;
			if (NetworkServer::instance()->getArtifactsDetailInfo(i.value()->baseInfo.id, i.value()->baseInfo.number, &jsonData, true))
			{
				if (jsonData["code"].toInt() == 200 && jsonData["success"].isBool())
				{
					Artifact::BaseInfo info;
					QJsonObject infoObj = jsonData["data"].toObject()["details"].toObject();
					info.id = infoObj["id"].toInt();
					info.deptId = infoObj["dept_id"].toInt();
					info.number = infoObj["artifact_number"].toString();
					info.mainImageAddr = infoObj["main_image"].toString();
					info.name = infoObj["artifact_name"].toString();
					info.size = infoObj["size"].toString();
					info.age = infoObj["age"].toString();
					info.texture = infoObj["texture"].toString();
					info.level = infoObj["level"].toString();
					info.stauts = infoObj["status"].toString();
					info.unitId = infoObj["unit_id"].toInt();
					info.weight = infoObj["weight"].toInt();
					
					info.remarks = infoObj["remarks"].toString();
					info.createTime = infoObj["created_at"].toString();
					info.updateTime = infoObj["updated_at"].toString();

					QJsonArray deptsData = infoObj["unit"].toObject()["depts"].toArray();
					if (deptsData.size() > 0)
					{
						QJsonObject deptData = deptsData[0].toObject();
						info.regAgency = deptData["name"].toString();		
					}
					if (jsonData["data"].toObject()["verifyResult"].isObject())
					{
						info.verifyResult = jsonData["data"].toObject()["verifyResult"].toObject()["verify_status"].toString();
					}
					else
					{
                        info.verifyResult = "未验证";
					}
					
					if (info.verifyResult != "未验证" && info.verifyResult != "验证中" &&info.number == i.key())
					{
						emit sigWaitEnd(i.key(), info);
					}
				}
			}
		}
	}
	count++;
}
