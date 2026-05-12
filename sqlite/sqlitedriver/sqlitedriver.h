#pragma once
#pragma execution_character_set("utf-8")
#include <QDir>
#include <QDate>
#include <QDateTime>
#include <QFileInfo>
#include <QString>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QVariant>
#include<QDebug>

struct DBTable
{
	QString name;
	QString type;
};

class SQLiteDriver 
{

public:
	SQLiteDriver();
	~SQLiteDriver();
public:
	void setDbDir(QString dirPath);//设置数据库存放路径
	bool creatDbFile(QString dbName);//生成一个db文件
	bool openDb(QString dbName);//打开连接
	bool closeDb();//关闭连接
	QString getErrorSql();//获取错误的数据库语句

	bool queryExec(QString dbName, QString sqlStr);//执行sql语句，不获取结果
	bool queryExec(QString dbName, QString sqlStr, QList<QHash<QString, QVariant>>*data);//执行sql语句，并获取结果

	bool creatTable(QString dbName, QString tableName, QList<DBTable>& data);
	bool getTableList(QString dbName, QList<QString>* list);

	bool getData(QString dbName, QString tableName, QHash<QString, QVariant>* data, QString sqlWhere = ""); //获取数据
	bool getData(QString dbName, QString table, QList<QHash<QString, QVariant>>* data, QString sqlWhere = ""); //获取数据
	bool getData(QString dbName, QString tableName, QHash<QString, QString> columndata, QList<QHash<QString, QVariant>>* data, QString sqlWhere = ""); //获取数据

	bool addData(QString dbName, QString tableName, QHash<QString, QString> data);//增加
	bool delData(QString dbName, QString tableName, QString sqlWhere);//删除
	bool updateData(QString dbName, QString tableName, QHash<QString, QString> data, QString sqlWhere = "");//修改


	bool queryExec(QString sqlStr);//执行sql语句，不获取结果
	bool queryExec(QString sqlStr, QList<QHash<QString, QVariant>>* data);//执行sql语句，并获取结果
	bool creatTable(QString tableName, QList<DBTable>& data);
	bool getTableList(QList<QString>*list);

	bool getData(QString tableName, QHash<QString, QVariant>* data, QString sqlWhere = ""); //获取数据
	bool getData(QString tableName, QList<QHash<QString, QVariant>>* data, QString sqlWhere = ""); //获取数据
	bool getData(QString tableName, QHash<QString, QString> columndata, QList<QHash<QString, QVariant>>* data, QString sqlWhere = ""); //获取数据

	bool addData(QString tableName, QHash<QString, QString> data);//增加
	bool delData(QString tableName, QString sqlWhere);//删除
	bool updateData(QString tableName, QHash<QString, QString> data, QString sqlWhere = "");//修改

private:
	const QString dbFileFormat = "db";//定义数据文件格式
	QSqlDatabase db;
	QString dbFilePath;//数据库路径
	QString dbDir; //数据库文件夹
	QString databaseName;//数据库名字

	QString errorSqlText;//错误语句
private:
	void errorSql(QString sql);//错误打印
};
