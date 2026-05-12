#pragma once
#include <QtCore>
#include <QObject>
class SQLiteDriver;
class VerifyDB  : public QObject
{
	Q_OBJECT

public:
	VerifyDB(QString userName,QObject *parent=nullptr);
	~VerifyDB();
	bool openDB();
	void closeDB();
	bool addInfoData(QHash<QString, QString> infoData);
	bool addImageData(QHash<QString, QString> infoData);
    bool addRawImageData(QHash<QString, QString> infoData);

	bool updateInfoData(QHash<QString, QString> infoData, QString number);
	bool updateImageData(QHash<QString, QString> infoData, QString number, QString name);
    bool updateRawImageData(QHash<QString, QString> infoData, QString number, QString name);

	bool deleteInfoData(QString number);
	bool deleteImageData(QString number, QString name);
    bool deleteRawImageData(QString number, QString name);

	bool getInfoData(QList<QHash<QString, QVariant>> &infoData);
    bool getImageData(QList<QHash<QString, QVariant>> &imageData,QString number);
	bool getRawImageData(QList<QHash<QString, QVariant>> &imageData,QString number);

	void creatInfoDataTable();
	void creatImageDataTable();
	void createRawImageDataTable();



private:
	SQLiteDriver* sqliteDriver = nullptr;
	QString dbDir; //数据库文件夹
	QString dbName;//数据库名字
	QString infoDataTableName;
	QString imageDataTableName;
	QString rawImageDataTableName;
	bool connectStatus;
};

