#include "regdb.h"
#include "sqlitedriver.h"
#include "appconfig.h"

REGDB::REGDB(QString userName,QObject *parent)
	: QObject(parent)
{
	connectStatus = false;
	dbName = "reg_" + userName;
	infoDataTableName = "artifact_info";
	imageDataTableName = "artifact_image";

	dbDir = AppConfig::instance()->appConf().regDBDir;
	QDir dir(dbDir);
	if (!dir.exists(dbDir))
	{
		dir.mkdir(dbDir);
	}
}

REGDB::~REGDB()
{
	closeDB();
}

bool REGDB::openDB()
{
	connectStatus = true;
	sqliteDriver = new SQLiteDriver();
	sqliteDriver->setDbDir(dbDir);
	sqliteDriver->creatDbFile(dbName);
	connectStatus &= sqliteDriver->openDb(dbName);
	if (!connectStatus)
	{
		qDebug() << "RegDB::openDB" << dbName << "error" << sqliteDriver->getErrorSql();
		return false;
	}
	QList<QString> tableList;
	sqliteDriver->getTableList(&tableList);
	if (!tableList.contains(infoDataTableName))
	{
		creatInfoDataTable();
	}
	if (!tableList.contains(imageDataTableName))
	{
		creatImageDataTable();
	}
	QList<QHash<QString, QVariant>> infoData;
	QString sqlWhere = "where is_deleted = 0";
	sqliteDriver->getData(infoDataTableName, &infoData, sqlWhere);

	return true;
}
void REGDB::closeDB()
{
	connectStatus = false;
	sqliteDriver->closeDb();
	delete sqliteDriver;
	sqliteDriver = nullptr;
}
bool REGDB::addInfoData(QHash<QString, QString> infoData)
{

	if (infoData.size() >= 11)
	{
		deleteInfoData(infoData["number"]);
		return sqliteDriver->addData(infoDataTableName, infoData);
	}
	else
	{
		qDebug() << "RegDB::addInfoData" << "error" << "infoData size < 11";
		return false;
	}
}
bool REGDB::addImageData(QHash<QString, QString> infoData)
{
	if (infoData.size() >= 6)
	{
		return sqliteDriver->addData(imageDataTableName, infoData);
	}
	else
	{
		qDebug() << "RegDB::addImageData" << "error" << "infoData size < 6";
		return false;
	}
}

bool REGDB::updateInfoData(QHash<QString, QString> infoData, QString number)
{
    
	QString sqlWhere = "where number = '" + number + "'";
	return sqliteDriver->updateData(infoDataTableName, infoData, sqlWhere);
}
bool REGDB::updateImageData(QHash<QString, QString> infoData, QString number, QString name)
{
	QString sqlWhere = "where number = '" + number + "' and name = '" + name + "'";
	return sqliteDriver->updateData(imageDataTableName, infoData, sqlWhere);

}
bool REGDB::deleteInfoData(QString number)
{
	qDebug() << "deleteInfoData" << number;
	QString sqlWhere = "where number = '" + number + "'";
	if (sqliteDriver->delData(infoDataTableName, sqlWhere))
	{
		return sqliteDriver->delData(imageDataTableName, sqlWhere);
	}
	return false;
}
bool REGDB::deleteImageData(QString number,QString name)
{
	QString sqlWhere = "where name = '" + name + "'" + "and number = '" + number + "'";
    return sqliteDriver->delData(imageDataTableName, sqlWhere);
}
bool REGDB::getInfoData(QList<QHash<QString, QVariant>>& infoData)
{
	QString sqlWhere = "where is_deleted = 0";
    return sqliteDriver->getData(infoDataTableName, &infoData, sqlWhere);
}
bool REGDB::getImageData(QList<QHash<QString, QVariant>>& imageData, QString number)
{
    QString sqlWhere = "where is_deleted = 0 and number = '" + number + "'";
    return sqliteDriver->getData(imageDataTableName, &imageData, sqlWhere);
}
void REGDB::creatInfoDataTable()
{
	if (connectStatus)
	{
		QList<DBTable>data;
		data.append(DBTable{ "id" ,"INTEGER PRIMARY KEY AUTOINCREMENT" });
		data.append(DBTable{ "server_id","INTEGER NOT NULL" });					// 服务器id
		data.append(DBTable{ "number","TEXT NOT NULL" });						// 标的编号
		data.append(DBTable{ "name","TEXT NOT NULL" });						    //标的名称
		data.append(DBTable{ "mainImage","TEXT DEFAULT NULL" });				//文物主图
		data.append(DBTable{ "size","TEXT DEFAULT NULL" });						//标的尺寸
		data.append(DBTable{ "texture","TEXT DEFAULT NULL" });					//标的质地
		data.append(DBTable{ "age","TEXT DEFAULT NULL" });						//标的年代
		data.append(DBTable{ "level","TEXT DEFAULT NULL" });					//标的等级
		data.append(DBTable{ "dept_id","TEXT DEFAULT NULL" });					//标的登记设备
        data.append(DBTable{ "reg_no","INTEGER NOT NULL" });					//登记步骤
		data.append(DBTable{ "batch_id","TEXT DEFAULT NULL" });					//批次ID
        data.append(DBTable{ "batch_code","TEXT DEFAULT NULL" });				//批次编码
		data.append(DBTable{ "batch_name","TEXT DEFAULT NULL" });				//批次名称
		data.append(DBTable{ "batch_applicant","TEXT DEFAULT NULL" });			//申请人
		data.append(DBTable{ "batch_carrier","TEXT DEFAULT NULL" });			//携运人
		data.append(DBTable{ "batch_exhibitionTitle","TEXT DEFAULT NULL" });	//展览名称
		data.append(DBTable{ "is_finished","INTEGER NOT NULL" });
		data.append(DBTable{ "create_time","TEXT NOT NULL" });
		data.append(DBTable{ "update_time","TEXT DEFAULT NULL" });
		data.append(DBTable{ "is_deleted","INTEGER NOT NULL" });
		sqliteDriver->creatTable(dbName, infoDataTableName, data);
	}
}
void REGDB::creatImageDataTable()
{
	if (connectStatus)
	{
		QList<DBTable>data;
		data.append(DBTable{ "id" ,"INTEGER PRIMARY KEY AUTOINCREMENT" });
		data.append(DBTable{ "number","TEXT NOT NULL" });
		data.append(DBTable{ "name","INTEGER NOT NULL" });
		data.append(DBTable{ "net_addr","TEXT DEFAULT NULL" });
		data.append(DBTable{ "local_addr","TEXT DEFAULT NULL" });
		data.append(DBTable{ "status","INTEGER DEFAULT NULL" });
		data.append(DBTable{ "create_time","TEXT NOT NULL" });
		data.append(DBTable{ "update_time","TEXT DEFAULT NULL" });
		data.append(DBTable{ "is_deleted","INTEGER NOT NULL" });
		sqliteDriver->creatTable(dbName, imageDataTableName, data);
	}
}