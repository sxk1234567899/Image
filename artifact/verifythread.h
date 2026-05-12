#pragma once

#include <QtCore>
#include <QImage>
#include <QThread>
#include "artifact.h"
#include "appconfig.h"

using namespace Artifact;

class VerifyData
{
public:
	int verifyNO=0;
	QString mainImageName;
	BaseInfo baseInfo;
	BatchInfo batchInfo;
	QMap<QString, QImage> globalImage;//  全局图片
	QMap<QString, QImage> lowImage;	//  低倍图片
	QMap<QString, QImage> highImage; //  高倍图片
	QMap<QString, ImageInfo> imageInfo; //  全局图片信息

    QMap<QString, QImage> rawGlobalImage;//  全局图片
    QMap<QString, QImage> rawMarkedImage;//  标记图片
    QMap<QString, QImage> rawLowImage;	//  低倍图片
    QMap<QString, QImage> rawHighImage; //  高倍图片
    QMap<QString, ImageInfo> rawImageInfo; //  全局图片信息
    enum VerifyStatus {
        Verify_LoadRawImage,
        Verify_Runing,
        Verify_UpData,
        Verify_Waiting,
        Verify_Finished,
    };
    VerifyStatus isVerifyFinished = Verify_LoadRawImage;
};


class VerifyDB;
class MinioS3Client;
class VerifyThread  : public QThread
{
	Q_OBJECT

public:
	static VerifyThread* instance();
	static void destroy();
    QString mVerifyRawImageDir;
public slots:
	bool addNewVerifyData(BaseInfo info, BatchInfo batchInfo);
    inline void startNewVerifyData()
    {
        mCurrNumber.clear();
    }
	bool updateVerifyData(QString number,BaseInfo info, BatchInfo batchInfo);
	inline bool updateVerifyData(BaseInfo info, BatchInfo batchInfo)
	{
		return updateVerifyData(mCurrNumber,info, batchInfo);
	}
    bool updateVerifyData(QString number = QString());

    bool updateVerifyResult(QString number);
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
    bool loadRawImageFinished(QString number);
    inline bool loadRawImageFinished()
    {
        return loadRawImageFinished(mCurrNumber);
    }
    bool verifyFinished(QString number);
    inline bool verifyFinished()
    {
        return verifyFinished(mCurrNumber);
    }

    bool setVerifyNo(QString number,int verifyNo);
    inline bool setVerifyNo(int verifyNo)
    {
        return setVerifyNo(mCurrNumber, verifyNo);
    }
    int getVerifyNo(QString number);
    inline int getVerifyNo()
    {
        return getVerifyNo(mCurrNumber);
    }
	QString getVerifyNumber();
	bool setVerifyNumber(QString number);
	QStringList getVerifyDataList();
	const VerifyData* getVerifyData(QString number,bool*isOk = nullptr)const;
    inline const VerifyData* getVerifyData(bool* isOk = nullptr)const
    {
		return getVerifyData(mCurrNumber, isOk);
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
	bool deleteVerifyData(QString number);
	inline bool deleteVerifyData()
	{
        return deleteVerifyData(mCurrNumber);
	}
public slots:
	//图片操作
	bool addGlobalImage(QString number, QString name, QImage image,int id);
	inline bool addGlobalImage(QString name, QImage image, int id)
	{
        return addGlobalImage(mCurrNumber, name, image,id);
	}
    bool addLowImage(QString number, QString name, QImage image, int id);
    inline bool addLowImage(QString name, QImage image, int id)
    {
        return addLowImage(mCurrNumber, name, image, id);
    }
    bool addHighImage(QString number, QString name, QImage image, int id);
    inline bool addHighImage(QString name, QImage image, int id)
    {
        return addHighImage(mCurrNumber, name, image,id);
    }
	bool deleteGlobalImage(QString number, QString name);
    inline bool deleteGlobalImage(QString name)
    {
        return deleteGlobalImage(mCurrNumber, name);
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

    /*原始登记图片*/
    bool addRawGlobalImage(QString number, QString name, QImage image, ImageInfo info);
    inline bool addRawGlobalImage(QString name, QImage image, ImageInfo info)
    {
        return addRawGlobalImage(mCurrNumber, name, image, info);
    }
    bool addRawMarkedImage(QString number, QString name, QImage image, ImageInfo info);
    inline bool addRawMarkedImage(QString name, QImage image, ImageInfo info)
    {
        return addRawMarkedImage(mCurrNumber, name, image, info);
    }
    bool addRawLowImage(QString number, QString name, QImage image, ImageInfo info);
    inline bool addRawLowImage(QString name, QImage image, ImageInfo info)
    {
        return addRawLowImage(mCurrNumber, name, image, info);
    }
    bool addRawHighImage(QString number, QString name, QImage image, ImageInfo info);
    inline bool addRawHighImage(QString name, QImage image, ImageInfo info)
    {
        return addRawHighImage(mCurrNumber, name, image,info);
    }
    bool deleteRawGlobalImage(QString number, QString name);
    inline bool deleteRawGlobalImage(QString name)
    {
        return deleteRawGlobalImage(mCurrNumber, name);
    }
    bool deleteRawMarkedImage(QString number, QString name);
    inline bool deleteRawMarkedImage(QString name)
    {
        return deleteRawMarkedImage(mCurrNumber, name);
    }
    bool deleteRawLowImage(QString number, QString name);
    inline bool deleteRawLowImage(QString name)
    {
        return deleteRawLowImage(mCurrNumber, name);
    }
    bool deleteRawHighImage(QString number, QString name);
    inline bool deleteRawHighImage(QString name)
    {
        return deleteRawHighImage(mCurrNumber, name);
    }
    bool deleteAllRawMarkImage(QString number);
    inline bool deleteAllRawMarkImage()
    {
        return deleteAllRawMarkImage(mCurrNumber);
    }
    bool updateRawImageInfo(QString number, QString imageName, ImageInfo info);
    inline bool updateRawImageInfo(QString imageName, ImageInfo info)
    {
        return updateRawImageInfo(mCurrNumber, imageName, info);
    }
    bool getRawImageInfo(QString number, QString imageName, ImageInfo* info)const;
    inline bool getRawImageInfo(QString imageName, ImageInfo* info)const
    {
        return getRawImageInfo(mCurrNumber, imageName, info);
    }

public:

	const QMap<QString, QImage>* getGlobalImage(QString number)const;
	inline const QMap<QString, QImage>* getGlobalImage()const
    {
        return getGlobalImage(mCurrNumber);
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

    const QMap<QString, QImage>* getRawGlobalImage(QString number)const;
    inline const QMap<QString, QImage>* getRawGlobalImage()const
    {
        return getRawGlobalImage(mCurrNumber);
    }
    const QMap<QString, QImage>* getRawMarkedImage(QString number)const;
    inline const QMap<QString, QImage>* getRawMarkedImage()const
    {
        return getRawMarkedImage(mCurrNumber);
    }
    const QMap<QString, QImage>* getRawLowImage(QString number)const;
    inline const QMap<QString, QImage>* getRawLowImage()const
    {
        return getRawLowImage(mCurrNumber);
    }
    const QMap<QString, QImage>* getRawHighImage(QString number)const;
    inline const QMap<QString, QImage>* getRawHighImage()const
    {
        return getRawHighImage(mCurrNumber);
    }

    const QMap<QString, ImageInfo>* geRawImageInfoList(QString number)const;
    inline const QMap<QString, ImageInfo>* geRawImageInfoList()const
    {
        return geRawImageInfoList(mCurrNumber);
    }
signals:
	void verifyDataAdded(QString number); //登记数据添加
	void verifyDataUpdated(QString number); //登记数据更新
	void verifyDataDeleted(QString number); //登记数据删除
	void imageAdded(QString number, QString name); //图片添加
	void imageDeleted(QString number, QString name); //图片删除 

    void showVerifyResult(QString number);

signals:
    void sigDeletedVerifyData(QString number);
    void sigUpDataFinished(QString number);
    void sigWaitEnd(QString number, BaseInfo baseInfo);

protected:
    void run() override;
private:
    static VerifyThread* self;

	QString mCurrNumber;
	QHash<QString, VerifyData*> verifyDataList;	//登记数据
	//QHash<QString, VerifyData*> saveDataList;	//保存数据需要通过进行上传
	//QHash<QString, VerifyData*> endDataList;	// 历史登记记录 浏览历史记录需要动态加载照片

	VerifyDB* verifyDB;
	MinioS3Client* mMinioUpload; // Minio上传
    NetCameraConf mNetCameraConf;
    QString mVerifyImageDir;
private:
	explicit VerifyThread();
	~VerifyThread();
	VerifyThread(const VerifyThread&) = delete;
    VerifyThread& operator=(const VerifyThread&) = delete;
    void doWork();
	bool addImage(QString number, QString name, QImage image, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap, int id,bool isUpload=true);
	bool deleteImage(QString number, QString name, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap);
    bool addRawImage(QString number, QString name, QImage image, ImageInfo info, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap);
    bool deleteRawImage(QString number, QString name, QMap<QString, ImageInfo>& imageMap, QMap<QString, QImage>& imageDataMap);
    QHash<QString, QString> infoStructToHash(const VerifyData* verifyData,bool isDel = false)const;
    QHash<QString, QString> imageInfoStructToHash(const ImageInfo imageInfo, bool isDel = false)const;

    void mDeleteVerifyData(QString number)
    {
        deleteVerifyData(number);
    }
private slots:
	void uploadFinished(Artifact::ImageInfo imageInfo);

    void upDataFinished(QString number);
    void waitEnd(QString number, BaseInfo baseInfo);
};

