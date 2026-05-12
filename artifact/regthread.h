#pragma once

#include <QtCore>
#include <QImage>
#include <QThread>
#include "artifact.h"
#include "appconfig.h"

using namespace Artifact;

class RegData
{
public:
	int regNO=0;
	QString mainImageName;
	BaseInfo baseInfo;
	BatchInfo batchInfo;
	QMap<QString, QImage> globalImage;//  全局图片
	QMap<QString, QImage> markedImage;//  标记图片
	QMap<QString, QImage> lowImage;	//  低倍图片
	QMap<QString, QImage> highImage; //  高倍图片
	QMap<QString, ImageInfo> imageInfo; //  全局图片信息
    bool isRegFinished=false;
};


class REGDB;
class MinioS3Client;
class RegThread  : public QThread
{
	Q_OBJECT

public:
	static RegThread* instance();
	static void destroy();

public slots:
    bool addNewRegData(BaseInfo info, BatchInfo batchInfo);
    inline void startNewRegData()
    {
        mCurrNumber.clear();
    }
	bool updateRegData(QString number,BaseInfo info, BatchInfo batchInfo);
	inline bool updateRegData(BaseInfo info, BatchInfo batchInfo)
	{
		return updateRegData(mCurrNumber,info, batchInfo);
	}
    bool updateRegData(QString number = QString());
	BaseInfo getBaseInfo(QString number);
	inline BaseInfo getBaseInfo()
	{
		return getBaseInfo(mCurrNumber);
	}
    BatchInfo getBatchInfo(QString number);
    inline BatchInfo getBatchInfo()
	{
		return getBatchInfo(mCurrNumber);
	}
    bool regFinished(QString number);
    inline bool regFinished()
    {
        return regFinished(mCurrNumber);
    }

    bool setRegNo(QString number,int regNo);
    inline bool setRegNo(int regNo)
    {
        return setRegNo(mCurrNumber, regNo);
    }
    int getRegNo(QString number);
    inline int getRegNo()
    {
        return getRegNo(mCurrNumber);
    }
	QString getRegNumber();
	bool setRegNumber(QString number);
	QStringList getRegNumberList();
	const RegData* getRegData(QString number,bool*isOk = nullptr)const;
    inline const RegData* getRegData(bool* isOk = nullptr)const
    {
		return getRegData(mCurrNumber, isOk);
	}
	bool addMainImage(QString number, QString name);
	inline bool addMainImage(QString name)
	{
        return addMainImage(mCurrNumber, imageNameShow(name));
	}
	QImage getMainImage(QString number);
    inline QImage getMainImage()
    {
        return getMainImage(mCurrNumber);
    }
	QString globalImageName(QString number, int index);
    inline QString globalImageName(int index)
    {
        return globalImageName(mCurrNumber, index);
    }
	QString markedImageName(QString number, QString globalImageName);
    inline QString markedImageName(QString globalImageName)
    {
        return markedImageName(mCurrNumber, globalImageName);
    }
	QString lowImageName(QString number, QString markImageName, bool isUnique = true);
    inline QString lowImageName(QString markImageName, bool isUnique = true)
    {
        return lowImageName(mCurrNumber, markImageName, isUnique);
    }
	QString highImageName(QString number, QString lowImageName, bool isUnique = true);
    inline QString highImageName(QString lowImageName, bool isUnique = true)
    {
        return highImageName(mCurrNumber, lowImageName, isUnique);
    }
	bool deleteRegData(QString number);
	inline bool deleteRegData()
	{
        return deleteRegData(mCurrNumber);
	}
public slots:
	//图片操作
	bool addGlobalImage(QString number, QString name, QImage image);
	inline bool addGlobalImage(QString name, QImage image)
	{
        return addGlobalImage(mCurrNumber, name, image);
	}
    bool addMarkedImage(QString number, QString name, QImage image);
    inline bool addMarkedImage(QString name, QImage image)
    {
        return addMarkedImage(mCurrNumber, name, image);
    }
    bool addLowImage(QString number, QString name, QImage image);
    inline bool addLowImage(QString name, QImage image)
    {
        return addLowImage(mCurrNumber, name, image);
    }
    bool addHighImage(QString number, QString name, QImage image);
    inline bool addHighImage(QString name, QImage image)
    {
        return addHighImage(mCurrNumber, name, image);
    }
	bool deleteGlobalImage(QString number, QString name);
    inline bool deleteGlobalImage(QString name)
    {
        return deleteGlobalImage(mCurrNumber, name);
    }
    bool deleteMarkedImage(QString number, QString name);
    inline bool deleteMarkedImage(QString name)
    {
        return deleteMarkedImage(mCurrNumber, name);
    }
    bool deleteLowImage(QString number, QString name);
    inline bool deleteLowImage(QString name)
    {
        return deleteLowImage(mCurrNumber, name);
    }
    bool deleteHighImage(QString number, QString name);
    inline bool deleteHighImage(QString name)
    {
        return deleteHighImage(mCurrNumber, name);
    }
    bool deleteAllMarkImage(QString number);
    inline bool deleteAllMarkImage()
    {
        return deleteAllMarkImage(mCurrNumber);
    }
	bool updateImageInfo(QString number, QString imageName,  ImageInfo info);
    inline bool updateImageInfo(QString imageName, ImageInfo info)
    {
        return updateImageInfo(mCurrNumber, imageName, info);
    }
	bool getImageInfo(QString number, QString imageName, ImageInfo *info)const;
    inline bool getImageInfo(QString imageName, ImageInfo *info)const
    {
        return getImageInfo(mCurrNumber, imageName, info);
    }

public:

	const QMap<QString, QImage>* getGlobalImage(QString number)const;
	inline const QMap<QString, QImage>* getGlobalImage()const
    {
        return getGlobalImage(mCurrNumber);
    }
    const QMap<QString, QImage>* getMarkedImage(QString number)const;
    inline const QMap<QString, QImage>* getMarkedImage()const
    {
        return getMarkedImage(mCurrNumber);
    }
    const QMap<QString, QImage>* getLowImage(QString number)const;
    inline const QMap<QString, QImage>* getLowImage()const
    {
        return getLowImage(mCurrNumber);
    }
    const QMap<QString, QImage>* getHighImage(QString number)const;
    inline const QMap<QString, QImage>* getHighImage()const
    {
        return getHighImage(mCurrNumber);
    }
	
	const QMap<QString, ImageInfo>* geImageInfoList(QString number)const;
    inline const QMap<QString, ImageInfo>* geImageInfoList()const
    {
        return geImageInfoList(mCurrNumber);
    }
signals:
	void regDataAdded(QString number); //登记数据添加
	void regDataUpdated(QString number); //登记数据更新
	void regDataDeleted(QString number); //登记数据删除
	void imageAdded(QString number, QString name); //图片添加
	void imageDeleted(QString number, QString name); //图片删除 

    void deleteRegDB(QString number);
protected:
    void run() override;
private:
    static RegThread* self;

	QString mCurrNumber;
	QHash<QString, RegData*> regDataList;	//登记数据
	//QHash<QString, RegData*> saveDataList;	//保存数据需要通过进行上传
	//QHash<QString, RegData*> endDataList;	// 历史登记记录 浏览历史记录需要动态加载照片

	REGDB* regDB;
	MinioS3Client* mMinioUpload; // Minio上传
    QString mRegImageDir;
    NetCameraConf mNetCameraConf;
   
private:
	explicit RegThread();
	~RegThread();
	RegThread(const RegThread&) = delete;
    RegThread& operator=(const RegThread&) = delete;
    void doWork();
	bool addImage(QString number, QString name, QImage image, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap,bool isUpload=true);
	bool deleteImage(QString number, QString name, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap);
    QHash<QString, QString> infoStructToHash(const RegData* regData,bool isDel = false)const;
    QHash<QString, QString> imageInfoStructToHash(const ImageInfo imageInfo, bool isDel = false)const;
private slots:
	void uploadFinished(Artifact::ImageInfo imageInfo);
};

