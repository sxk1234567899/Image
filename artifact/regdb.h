#pragma once
#include <QtCore>
#include <QObject>
class SQLiteDriver;
class REGDB  : public QObject
{
	Q_OBJECT

public:
	REGDB(QString userName,QObject *parent=nullptr);
	~REGDB();
	bool openDB();
	void closeDB();
public slots:
	bool addInfoData(QHash<QString, QString> infoData);
	bool addImageData(QHash<QString, QString> infoData);

	bool updateInfoData(QHash<QString, QString> infoData, QString number);
	bool updateImageData(QHash<QString, QString> infoData, QString number, QString name);

	bool deleteInfoData(QString number);
	bool deleteImageData(QString number,QString name);

	bool getInfoData(QList<QHash<QString, QVariant>> &infoData);
    bool getImageData(QList<QHash<QString, QVariant>> &imageData,QString number);

	void creatInfoDataTable();
	void creatImageDataTable();




private:
	SQLiteDriver* sqliteDriver = nullptr;
	QString dbDir; //数据库文件夹
	QString dbName;//数据库名字
	QString infoDataTableName;
	QString imageDataTableName;
	bool connectStatus;
};

