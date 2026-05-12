#include <QtConcurrent>
#include "regthread.h"
#include "appconfig.h"
#include "minios3client.h"
#include "networkserver.h"
#include "regdb.h"

RegThread* RegThread::self;
RegThread* RegThread::instance()
{
	static QMutex mutex;
	if (self == nullptr)
	{
		QMutexLocker locker(&mutex);
		if (self == nullptr)
		{
			self = new RegThread();
		}
	}
	return self;
}
void RegThread::destroy()
{
	if (self != nullptr)
	{
		delete self;
		self = nullptr;
	}
}

RegThread::RegThread()
	: QThread(nullptr)
{
	mRegImageDir = AppConfig::instance()->appConf().regImageDir;
	mNetCameraConf = AppConfig::instance()->netCameraConf();
	QString username = NetworkServer::instance()->userInfo().username;
	if (username.isEmpty())
	{
		username = "admin";
	}
	regDB = new REGDB(username);
	regDB->openDB();
	connect(this, &RegThread::deleteRegDB, regDB, &REGDB::deleteInfoData,Qt::BlockingQueuedConnection);
	mMinioUpload = new MinioS3Client();
	connect(mMinioUpload, &MinioS3Client::uploadFinished, this, &RegThread::uploadFinished);

	QList<QHash<QString, QVariant>>infoDataList;
	regDB->getInfoData(infoDataList);
    for (auto infoData : infoDataList)
	{ 
		RegData* regData = new RegData;
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
		batchInfo.id = infoData["batch_id"].toInt();
        batchInfo.code = infoData["batch_code"].toString();
        batchInfo.name = infoData["batch_name"].toString();
        batchInfo.applicant = infoData["batch_applicant"].toString();
        batchInfo.carrier = infoData["batch_carrier"].toString();
		batchInfo.exhibitionTitle = infoData["batch_exhibitionTitle"].toString();
		
		regData->baseInfo = info;
		regData->batchInfo = batchInfo;
        regData->regNO = infoData["reg_no"].toInt();
		regData->isRegFinished = infoData["is_finished"].toBool();
		regDataList.insert(regData->baseInfo.number, regData);
		QList<QHash<QString, QVariant>>imageDataList;
		regDB->getImageData(imageDataList, info.number);
        for (auto imageData : imageDataList) 
		{ 
            ImageInfo imageInfo;
			imageInfo.number = imageData["number"].toString();
			imageInfo.imageName = imageData["name"].toString();
			imageInfo.imageNetAddr = imageData["net_addr"].toString();
			imageInfo.imageLocalAddr = imageData["local_addr"].toString();
			imageInfo.status = (ImageStatus)imageData["status"].toInt();
			imageInfo.imageLocalDir = mRegImageDir;
			regDataList[imageInfo.number]->imageInfo[imageInfo.imageName] = imageInfo;
			if (imageInfo.imageName.startsWith("D_01_") && imageInfo.imageName.size() == 12)
			{
				regDataList[imageInfo.number]->globalImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("D_01_"))
			{
				regDataList[imageInfo.number]->markedImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("W_03_"))
			{
				regDataList[imageInfo.number]->lowImage[imageInfo.imageName] = QImage();
			}
			else if (imageInfo.imageName.startsWith("W_02_"))
			{
				regDataList[imageInfo.number]->highImage[imageInfo.imageName] = QImage();;
			}

			if (imageInfo.status == ImageStatus::unsaved)
			{
				mMinioUpload->addImage(imageInfo);
			}

			/*更新界面，防止卡顿*/
			QCoreApplication::processEvents();
        }
		regDataList[info.number]->regNO = 1;
		if ((regDataList[info.number]->highImage.size() > 0 )
			&& (regDataList[info.number]->highImage.size()==regDataList[info.number]->markedImage.size()))
		{
			regDataList[info.number]->regNO = 4;
		}
		else if (regDataList[info.number]->markedImage.size() > 0)
		{
			regDataList[info.number]->regNO = 3;
		}
		else if (regDataList[info.number]->globalImage.size() > 0)
		{
			regDataList[info.number]->regNO = 2;
		}
		
		/*更新界面，防止卡顿*/
		QCoreApplication::processEvents();
	}

	start();
}

RegThread::~RegThread()
{
	updateRegData();
	requestInterruption();
	quit();
	wait();
	for (auto it = regDataList.begin(); it != regDataList.end();)
	{
		delete it.value();
		it = regDataList.erase(it);
	}
	if (regDB)
	{
		delete regDB;
		regDB = nullptr;
	}
}
void RegThread::uploadFinished(Artifact::ImageInfo imageInfo)
{
	QString number = imageInfo.number;
	QString name = imageInfo.imageName;
	if(!regDataList.contains(number)|| !regDataList[number]->imageInfo.contains(name))
	{
		qDebug() << "RegThread::uploadFinished" << number << name << "not found";
		return;
	}
	regDataList[number]->imageInfo[name] = imageInfo;
	regDB->updateImageData(imageInfoStructToHash(imageInfo),number,name);
	emit regDataUpdated(number);
}
bool RegThread::addNewRegData(BaseInfo info , BatchInfo batchInfo)
{
	RegData* regData = new RegData;
    regData->baseInfo = info;
	regData->baseInfo.createTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    regData->batchInfo = batchInfo;
	regDataList.insert(regData->baseInfo.number, regData);
	mCurrNumber = regData->baseInfo.number;
    regDB->addInfoData(infoStructToHash(regData));
	emit regDataAdded(info.number);
	qDebug() << "RegThread::addNewRegData" << info.number << "added";
    return regDataList.contains(info.number);
}
bool RegThread::updateRegData(QString number, BaseInfo info,  BatchInfo batchInfo)
{
	if (!regDataList.contains(number))
	{
		return false;
	}
	regDataList[number]->baseInfo = info;
    regDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    regDataList[number]->batchInfo = batchInfo;
	regDataList[number]->regNO = 0;
	regDB->updateInfoData(infoStructToHash(regDataList[number]), number);
	qDebug() << "RegThread::updateRegData" << number << "updated";
	emit regDataUpdated(number);
	return true;  
}
bool RegThread::updateRegData(QString number)
{
	if (number.isEmpty())
	{
		number = mCurrNumber;
	}
	if (!regDataList.contains(number))
	{
		return false;
	}
	regDB->updateInfoData(infoStructToHash(regDataList[number]), number);
	return true;
}
BaseInfo RegThread::getBaseInfo(QString number)
{
	if (!regDataList.contains(number))
	{
		return BaseInfo();
	}
    return regDataList[number]->baseInfo;
}
BatchInfo RegThread::getBatchInfo(QString number)
{
	if (!regDataList.contains(number))
	{
		return BatchInfo();
	}
	return regDataList[number]->batchInfo;
}

bool RegThread::regFinished(QString number)
{
	if (!regDataList.contains(number))
	{
		return false;
	}
	regDataList[number]->isRegFinished = true;
	regDB->updateInfoData(infoStructToHash(regDataList[number]), number);
	emit regDataUpdated(number);
	return true;
}
bool RegThread::setRegNo(QString number, int regNo)
{
	if (!regDataList.contains(number))
	{
		return false;
	}
	regDataList[number]->regNO = regNo;
	return true;
}
int RegThread::getRegNo(QString number)
{
	if (!regDataList.contains(number))
	{
		return -1;
	}
	regDataList[number]->regNO = 1;
	if ((regDataList[number]->highImage.size() > 0)
		&& (regDataList[number]->highImage.size() == regDataList[number]->markedImage.size()))
	{
		regDataList[number]->regNO = 4;
	}
	else if (regDataList[number]->markedImage.size() > 0)
	{
		regDataList[number]->regNO = 3;
	}
	else if (regDataList[number]->globalImage.size() > 0)
	{
		regDataList[number]->regNO = 2;
	}
	return regDataList[number]->regNO;
}
QString RegThread::getRegNumber()
{
	return mCurrNumber;
}
bool RegThread::setRegNumber(QString number)
{
	if (!regDataList.contains(number))
    {
		return false;
    }
	mCurrNumber = number;
	return true;
    
}
QStringList RegThread::getRegNumberList()
{
	return regDataList.keys();
}
const RegData* RegThread::getRegData(QString number, bool* isOk)const
{
	if (!regDataList.contains(number))
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
	return regDataList[number];
}
bool RegThread::addMainImage(QString number, QString name)
{
	if (!regDataList.contains(number))
    {
		qDebug() << "RegThread::addMainImage" << number << name<<"error";
        return false;
    }
	regDataList[number]->mainImageName = name;
    regDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    return true;
}
QImage RegThread::getMainImage(QString number)
{
	if (!regDataList.contains(number))
    {
		qDebug() << "RegThread::getMainImage" << number << "error";
        return QImage();
    }
	if (!regDataList[number]->globalImage.contains(regDataList[number]->mainImageName))
	{
		qDebug()<< "RegThread::getMainImage" << regDataList[number]->mainImageName << "error";
		return QImage();
	}
    return regDataList[number]->globalImage.value(regDataList[number]->mainImageName);
}

QString RegThread::globalImageName(QString number, int index)
{
	if (!regDataList.contains(number))
	{
		return QString();
	}
	return QString::asprintf("D_01_%03d_", regDataList[mCurrNumber]->globalImage.size() + 1) + (gImgNameList[index]);

}
QString RegThread::markedImageName(QString number, QString globalImageName)
{
	if(!regDataList.contains(number))
	{
		return QString();
	}
	QString markedName;
	qint32 index = 1;
	while (true)
	{
		markedName = globalImageName + QString::asprintf("_M%02d", index++);
		if (!regDataList[number]->markedImage.contains(markedName))
		{
			break;
		}
	}
	return markedName;
}
QString RegThread::lowImageName(QString number, QString markImageName, bool isUnique)
{
	if (!regDataList.contains(number))
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
	if (isUnique&&regDataList[number]->lowImage.contains(lowName))
	{
		deleteLowImage(number, lowName);
	}
	return lowName;
}
QString RegThread::highImageName(QString number, QString lowImageName, bool isUnique)
{
	if( !regDataList.contains(number))
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
	if (isUnique&&regDataList[number]->highImage.contains(highName))
	{
		deleteHighImage(number, highName);
	}
	return highName;
}

bool RegThread::addImage(QString number, QString name, QImage image, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap, bool isUpload)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::addImage" << number << "number not exist";
		return false;
	}
	if (imageMap.contains(name))
	{
		qDebug() << "RegThread::addImage" << imageNameShow(name) << "already exist";
		return false;
	}
	ImageInfo imageInfo;
	imageInfo.number = number;
	imageInfo.imageName = name;
	imageInfo.status = ImageStatus::unsaved;
    imageInfo.imageLocalDir = mRegImageDir;
	imageInfo.imageLocalAddr = mRegImageDir;
	imageInfo.imageLocalAddr.append("/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz") + "__" + name + ".png");

	imageMap[name] = imageInfo;
	imageDataMap[name] = image.copy();
	regDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	emit imageAdded(number, name);
	emit regDataUpdated(number);
	qDebug() << "RegThread::addImage" << imageNameShow(name) << "added";
	regDB->addImageData(imageInfoStructToHash(imageInfo));
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
bool RegThread::deleteImage(QString number, QString name, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::deleteImage" << number << "number not exist";
		return false;
	}
	if (!imageMap.contains(name))
	{
		qDebug() << "RegThread::deleteImage" << imageNameShow(name) << "not exist";
		return false;
	}

	/*TODO 需要删除本地照片*/
	QFile::remove(imageMap[name].imageLocalAddr);
    regDB->deleteImageData(number,name);
	imageMap.remove(name);
	imageDataMap.remove(name);
	regDataList[number]->baseInfo.updateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	emit imageDeleted(number, name);
	emit regDataUpdated(number);
	qDebug() << "RegThread::deleteImage" << imageNameShow(name) << "deleted";
	return true;
}

bool RegThread::addGlobalImage(QString number, QString name, QImage image)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::addGlobalImage" << number << "number not exist";
		return false;
	}
	return addImage(number, name, image, regDataList[number]->imageInfo, regDataList[number]->globalImage);
}
bool RegThread::addMarkedImage(QString number, QString name, QImage image)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::addMarkedImage" << number << "number not exist";
		return false;
	}
	return addImage(number, name, image, regDataList[number]->imageInfo, regDataList[number]->markedImage);
}
bool RegThread::addLowImage(QString number, QString name, QImage image)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::addLowImage" << number << "number not exist";
		return false;
	}
	return addImage(number, name, image, regDataList[number]->imageInfo, regDataList[number]->lowImage);
}
bool RegThread::addHighImage(QString number, QString name, QImage image)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::addHighImage" << number << "number not exist";
		return false;
	}
	return addImage(number, name, image, regDataList[number]->imageInfo, regDataList[number]->highImage);
}
bool RegThread::deleteGlobalImage(QString number, QString name)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::deleteGlobalImage" << number << "number not exist";
		return false;
	}
	bool ret = deleteImage(number, name, regDataList[number]->imageInfo, regDataList[number]->globalImage);
	if (ret)
	{
		QStringList keys = regDataList[number]->markedImage.keys();
		for (auto key:keys)
		{
			if (!key.startsWith(name))
			{
				continue;
			}
			deleteMarkedImage(number, key);

		}
	}
	return ret;
}
bool RegThread::deleteMarkedImage(QString number, QString name)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::deleteMarkedImage" << number << "number not exist";
		return false;
	}
	bool ret = deleteImage(number, name, regDataList[number]->imageInfo, regDataList[number]->markedImage);

	if (ret)
	{
		
        lowImageName(number, name);
		highImageName(number, name);

	}
	return ret;
}
bool RegThread::deleteLowImage(QString number, QString name)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::deleteLowImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, regDataList[number]->imageInfo, regDataList[number]->lowImage);
}
bool RegThread::deleteHighImage(QString number, QString name)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::deleteHighImage" << number << "number not exist";
		return false;
	}
	return deleteImage(number, name, regDataList[number]->imageInfo, regDataList[number]->highImage);
}
bool RegThread::deleteAllMarkImage(QString number)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::deleteHighImage" << number << "number not exist";
		return false;
	}
	QList<ImageInfo> removeList;
	for (auto key : regDataList[number]->markedImage.keys())
	{
		removeList.append(regDataList[number]->imageInfo.take(key));
		regDB->deleteImageData(number, key);
	}
	for (auto key : regDataList[number]->lowImage.keys())
	{
		removeList.append(regDataList[number]->imageInfo.take(key));
		regDB->deleteImageData(number, key);
	}
	for (auto key : regDataList[number]->highImage.keys())
	{
		removeList.append(regDataList[number]->imageInfo.take(key));
		regDB->deleteImageData(number, key);
	}
	regDataList[number]->markedImage.clear();
	regDataList[number]->lowImage.clear();
	regDataList[number]->highImage.clear();
	auto futer = QtConcurrent::run([removeList]() {
		for (auto info : removeList)
		{
			QFile::remove(info.imageLocalAddr);
		}
		});
	return true;
}
bool RegThread::updateImageInfo(QString number, QString imageName, const ImageInfo info)
{
	if (!regDataList.contains(number))
	{
		qDebug()<< "RegThread::updateImageInfo" << number << "number not exist";
		return false;
	}
	if (!regDataList[number]->imageInfo.contains(imageName))
	{
		qDebug() << "RegThread::updateImageInfo" << imageName << "imageName not exist";
		return false;
	}
	regDataList[number]->imageInfo[imageName] = info;
	if (info.status == ImageStatus::unsaved)
	{
		mMinioUpload->addImage(info);
	}
	return true;
}
bool RegThread::getImageInfo(QString number, QString imageName,ImageInfo* info)const
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::updateImageInfo" << number << "number not exist";
		return false;
	}
	if (!regDataList[number]->imageInfo.contains(imageName))
	{
		qDebug() << "RegThread::updateImageInfo" << imageName << "imageName not exist";
		return false;
	}
	*info = regDataList[number]->imageInfo[imageName];
	return true;
}
bool RegThread::deleteRegData(QString number)
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::deleteRegData" << number << "number not exist";
		return false;
	}
	auto regData = regDataList.value(number);
	auto imageInfo = regData->imageInfo;
	NetworkServer::instance()->postArtifactsStatus(regData->baseInfo.id, "未开始");
	delete regData;
	regDataList.remove(number);
	/*需要删除本地照片*/
	auto futer = QtConcurrent::run([imageInfo]() {
		for(auto info:imageInfo)
		{
			QFile::remove(info.imageLocalAddr);
		}
	});
	regDB->deleteInfoData(number);
	emit regDataDeleted(number);
	return true;
}
const QMap<QString, QImage>* RegThread::getGlobalImage(QString number)const
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::getGlobalImage" << number << "number not exist";
		return nullptr;
	}
	for (auto data = regDataList[number]->globalImage.begin(); data != regDataList[number]->globalImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(regDataList[number]->imageInfo[data.key()].imageLocalAddr);
            if (!image.isNull())
			{
				data.value() = image;
			}
		}
		/*更新界面，防止卡顿*/
		QCoreApplication::processEvents();
	}
	return &(regDataList[number]->globalImage);
}
const QMap<QString, QImage>* RegThread::getMarkedImage(QString number)const
{
    if (!regDataList.contains(number))
    {
        qDebug() << "RegThread::getMarkedImage" << number << "number not exist";
        return nullptr;
    }
	for (auto data = regDataList[number]->markedImage.begin(); data != regDataList[number]->markedImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(regDataList[number]->imageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
		}
		/*更新界面，防止卡顿*/
		QCoreApplication::processEvents();
	}
	return &(regDataList[number]->markedImage);
}
const QMap<QString, QImage>* RegThread::getLowImage(QString number)const
{
    if (!regDataList.contains(number))
    {
        qDebug() << "RegThread::getLowImage" << number << "number not exist";
        return nullptr;
    }
	for (auto data = regDataList[number]->lowImage.begin(); data != regDataList[number]->lowImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(regDataList[number]->imageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
		}
		/*更新界面，防止卡顿*/
		QCoreApplication::processEvents();
	}
	return &(regDataList[number]->lowImage);
}
const QMap<QString, QImage>* RegThread::getHighImage(QString number)const
{
    if (!regDataList.contains(number))
    {
        qDebug() << "RegThread::getHighImage" << number << "number not exist";
        return nullptr;
    }
	for (auto data = regDataList[number]->highImage.begin(); data != regDataList[number]->highImage.end(); data++)
	{
		if (data.value().isNull())
		{
			QImage image = QImage(regDataList[number]->imageInfo[data.key()].imageLocalAddr);
			if (!image.isNull())
			{
				data.value() = image;
			}
		}
		/*更新界面，防止卡顿*/
		QCoreApplication::processEvents();
	}
	return &(regDataList[number]->highImage);
}


const QMap<QString, ImageInfo>* RegThread::geImageInfoList(QString number)const
{
	if (!regDataList.contains(number))
	{
		qDebug() << "RegThread::getGlobalImageInfo" << number << "number not exist";
		return nullptr;
	}
	return &(regDataList[number]->imageInfo);
}

QHash<QString, QString> RegThread::infoStructToHash(const RegData * regData, bool isDel)const
{
	QHash<QString, QString> infoHash;
	infoHash.insert("server_id", QString::number(regData->baseInfo.id));
	infoHash.insert("number", regData->baseInfo.number);
	infoHash.insert("name", regData->baseInfo.name);
    infoHash.insert("mainImage", regData->baseInfo.mainImageAddr);
	infoHash.insert("size", regData->baseInfo.size);
	infoHash.insert("texture", regData->baseInfo.texture);
	infoHash.insert("age", regData->baseInfo.age);
	infoHash.insert("level", regData->baseInfo.level);
	infoHash.insert("dept_id", QString::number(regData->baseInfo.deptId));
	infoHash.insert("reg_no", QString::number(regData->regNO));
	infoHash.insert("batch_id", QString::number(regData->batchInfo.id));
	infoHash.insert("batch_code", regData->batchInfo.code);
	infoHash.insert("batch_name", regData->batchInfo.name);
	infoHash.insert("batch_applicant", regData->batchInfo.applicant);
	infoHash.insert("batch_carrier", regData->batchInfo.carrier);
	infoHash.insert("batch_exhibitionTitle", regData->batchInfo.exhibitionTitle);
	infoHash.insert("is_finished", QString::number(regData->isRegFinished));
	infoHash.insert("create_time", regData->baseInfo.createTime);
	infoHash.insert("update_time", regData->baseInfo.updateTime);
	infoHash.insert("is_deleted",QString::number(isDel));
    return infoHash;
}
QHash<QString, QString> RegThread::imageInfoStructToHash(const ImageInfo imageInfo, bool isDel)const
{
	QHash<QString, QString> imageInfoHash;
	imageInfoHash["number"] = imageInfo.number;
	imageInfoHash["name"] = imageInfo.imageName;
	imageInfoHash["net_addr"] = imageInfo.imageNetAddr;
	imageInfoHash["local_addr"] = imageInfo.imageLocalAddr;
	imageInfoHash["status"] = QString::number(imageInfo.status);
	imageInfoHash["create_time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	imageInfoHash["is_deleted"] = QString::number(isDel);

	return imageInfoHash;
}

void RegThread::run()
{
	while (!isInterruptionRequested()) 
	{
		// 执行周期性工作
		doWork();
		// 短暂休眠，避免CPU占用过高
		QThread::msleep(100);
	}
}
void RegThread::doWork()
{
	for (auto i = regDataList.begin(); i != regDataList.end();)
	{
		if (!i.value()->isRegFinished)
		{
			i++;
			continue;
		}
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
			i++;
			continue;
		}
		QJsonObject jsonData;
        //jsonData.insert("weight", QString());
        jsonData.insert("artifact_category", 3);
        jsonData.insert("sampling_id", data->baseInfo.id);
		jsonData.insert("weight","0kg");
		QJsonArray aroundInfos;
        for (auto j = data->globalImage.begin(); j != data->globalImage.end(); ++j)
		{ 
			QJsonObject aroundInfo;
			QString part; 
			QString name = j.key();
			auto pos = j.key().split("_");
			if (pos.size() >= 4)
			{
				int index = gImgNameList.indexOf(pos[3]);
				if (index >= 0 && index < gImgShowNameList.size())
				{
					part = gImgShowNameList[index];
				}
			}

			aroundInfo.insert("part", part);
			aroundInfo.insert("img", data->imageInfo[name].imageNetAddr);
			aroundInfo.insert("attr", QJsonObject());
			QJsonArray samplingInfos;
			for (auto k = data->markedImage.begin(); k != data->markedImage.end(); k++)
			{
				if (!k.key().startsWith(name))
				{
					continue;
				}
				QJsonObject samplingInfo;
				QString markName = k.key();
				QString lowName = markName;
				lowName.replace("D_01_", "W_03_");
				QString highName = markName;
                highName.replace("D_01_", "W_02_");

                samplingInfo.insert("mark_point_image", data->imageInfo[k.key()].imageNetAddr);

				QJsonObject lowImageInfo;
                lowImageInfo.insert("img", data->imageInfo[lowName].imageNetAddr);
				QJsonObject lowAttr;
                lowAttr.insert("zoom", QString::number(mNetCameraConf.lowZoom));
				lowImageInfo.insert("attr", lowAttr);
				samplingInfo.insert("low_mag_image", lowImageInfo);

				QJsonObject highImageInfo;
                highImageInfo.insert("img", data->imageInfo[highName].imageNetAddr);
				QJsonObject highAttr;
				highAttr.insert("zoom", QString::number(mNetCameraConf.highZoom));
                highImageInfo.insert("attr", highAttr);
                samplingInfo.insert("high_mag_image", highImageInfo);		

                samplingInfos.append(samplingInfo);
			}
			aroundInfo.insert("samplingInfos", samplingInfos);
			
			aroundInfos.append(aroundInfo);
			
		}
		
        jsonData.insert("aroundInfos", aroundInfos);
		
		qDebug() << "RegThread::doWork:jsonData";
		qDebug().noquote() << QString::fromUtf8(QJsonDocument(jsonData).toJson(QJsonDocument::Indented));
		NetworkServer* networkServer = NetworkServer::instance();
		bool isOK =false;
		for (int i = 0; i < 3; i++)
		{
            isOK = networkServer->postArtifactUpData(jsonData);
			if (isOK)
			{
				qDebug() << "RegThread::doWork:putArtifactModifyData:success";
				break;
			}
		}
		/*if (isOK)
		{	
			networkServer->postArtifactsStatus(data->baseInfo.id, "已完成");	
		}*/
		if (isOK)
		{
			qDebug() << "RegThread::doWork:删除结束登记的数据";
			QString number = data->baseInfo.number;
			emit deleteRegDB(number);
			emit regDataDeleted(number);
			auto imageInfo = data->imageInfo.values();
			for (auto info : imageInfo)
			{
				QFile::remove(info.imageLocalAddr);
			}
			delete data;
			i = regDataList.erase(i);
		}
		else
		{
			i++;
		}
	}
}
