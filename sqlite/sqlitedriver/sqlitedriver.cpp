#include "sqlitedriver.h"
SQLiteDriver::SQLiteDriver()
{
}

SQLiteDriver::~SQLiteDriver()
{
	closeDb();
}
void SQLiteDriver::setDbDir(QString dirPath)
{
	QDir dir;
	if (!dir.exists(dirPath))
	{
		dir.mkdir(dirPath);
	}
	dbDir = dirPath;
}
bool SQLiteDriver::creatDbFile(QString dbName)
{
	QString fileName = (dbDir + "/" + dbName + "." + dbFileFormat);
	QFile file(fileName);
	if (file.open(QIODevice::Append))
	{

		file.close();
	}
	else
	{
		return false;
	}
	return true;
}
bool SQLiteDriver::openDb(QString dbName)
{
	QString fileName = (dbDir + "/" + dbName + "." + dbFileFormat);
	if (!QFile::exists(fileName))
	{
		qDebug() << "SQLiteDriver::no db file";
		return false;//没有数据库文件
	}
	QFileInfo file(fileName);
	if (file.suffix() != dbFileFormat)
		return false;
	db = QSqlDatabase::database(dbName);
	if (!db.isValid())
	{
		db = QSqlDatabase::addDatabase("QSQLITE", dbName);
		db.setDatabaseName(fileName);
		db.setUserName("panpan");
		db.setPassword("123456");
		if (!db.open())
		{
            qDebug() << "SQLiteDriver::open db error" << getErrorSql();
			return false;
		}
	}
	dbFilePath = fileName;
	databaseName = dbName;
	return true;
}
bool SQLiteDriver::closeDb()
{
	if (databaseName.isEmpty())
		return true;
	if (!QFile::exists(dbFilePath))
	{
		return false;
	}
	db = QSqlDatabase::database(databaseName);
	if (!db.isValid())
	{
		return true;
	}
	db.close();
	db = QSqlDatabase::database();
	QSqlDatabase::removeDatabase(databaseName);
	databaseName = "";
	dbFilePath = "";
	errorSqlText = "";
	dbDir = "";
	return true;
}


void SQLiteDriver::errorSql(QString sql)
{
	errorSqlText = sql;
}

QString SQLiteDriver::getErrorSql()
{
	if (databaseName.isEmpty())
	{
		return "db  not setting";
	}
	return errorSqlText;
}

bool SQLiteDriver::queryExec(QString dbName, QString queryStr)
{
	if (databaseName.isEmpty())
	{
		if (!openDb(dbName))
		{
			return false;
		}
	}
	QSqlQuery query(QSqlDatabase::database(dbName, true));
	if (!query.exec(queryStr))
	{
		errorSql(queryStr);
		return false;
	}
	return  true;
}

bool SQLiteDriver::queryExec(QString dbName, QString queryStr, QList<QHash<QString, QVariant>>* data)
{
	data->clear();
	if (databaseName.isEmpty())
	{
		if (!openDb(dbName))
		{
			return false;
		}
	}
	QSqlQuery query(QSqlDatabase::database(dbName, true));
	if (!query.exec(queryStr))
	{
		errorSql(queryStr);
		return false;
	}
	QSqlRecord rec = query.record();
	while (query.next())
	{
		QHash<QString, QVariant> rowData;
		for (int i = 0; i < rec.count(); i++)
		{
			rowData[rec.fieldName(i)] = query.value(i);
			//QVariant::Type ty = query.value(i).type();
			//if (QVariant::Type::Date == ty)
			//{
			//    QDate temp = query.value(i).toDate();
			//    rowData[rec.fieldName(i)] = temp.toString("yyyy-MM-dd");
			//}
			//else if (QVariant::Type::Time == ty)
			//{
			//    QTime temp = query.value(i).toTime();
			//    rowData[rec.fieldName(i)] = temp.toString("hh:mm:ss");
			//}
			//else if (QVariant::Type::DateTime == ty)
			//{
			//    QDateTime temp = query.value(i).toDateTime();
			//    rowData[rec.fieldName(i)] = temp.toString("yyyy-MM-dd hh:mm:ss");
			//}
			//else
			//{
			//    //qDebug() << query.value(i).toString();
			//    rowData[rec.fieldName(i)] = query.value(i).toString();
			//}

		}
		data->append(rowData);
	}
	return  true;
}

bool SQLiteDriver::creatTable(QString dbName, QString tableName, QList<DBTable>& data)
{
	if (data.isEmpty())
		return false;
	QString queryStr = "create table " + tableName;
	QString valueStr = "(";
	QList<DBTable>::iterator it;
	for (it = data.begin(); it != data.end(); ++it)
	{
		valueStr += it->name + " " + it->type + ",";
	}
	valueStr = valueStr.left(valueStr.length() - 1);
	valueStr += ");";
	queryStr += valueStr;
	if (!queryExec(dbName, queryStr))
	{
		return false;
	}
	return true;
}

bool SQLiteDriver::getTableList(QString dbName, QList<QString>* list)
{
	QString queryStr = QString("SELECT name FROM sqlite_master WHERE type='table' order by name");
	QList<QHash<QString, QVariant>> data;
	if (!queryExec(dbName, queryStr, &data))
	{
		return false;
	}
	if (!data.isEmpty())
	{
		QList<QHash<QString, QVariant>>::iterator it;
		for (it = data.begin(); it != data.end(); ++it)
		{
			list->append(it->value("name").toString());
		}
	}
	return true;
}

bool SQLiteDriver::getData(QString dbName, QString tableName, QHash<QString, QVariant>* data, QString sqlWhere)
{
	data->clear();
	QList<QHash<QString, QVariant>> dataList;
	if (!getData(dbName, tableName, &dataList, sqlWhere))
	{
		return false;
	}
	if (dataList.count() > 0)
	{
		data = &dataList[0];
	}
	return true;
}

bool SQLiteDriver::getData(QString dbName, QString tableName, QList<QHash<QString, QVariant>>* data, QString sqlWhere)
{
	QString queryStr = "select * from " + tableName;
	if (!sqlWhere.isEmpty())
		queryStr += " " + sqlWhere;
	if (!queryExec(dbName, queryStr, data))
	{
		return  false;
	}
	return  true;
}

bool SQLiteDriver::getData(QString dbName, QString tableName, QHash<QString, QString> columndata, QList<QHash<QString, QVariant>>* data, QString sqlWhere)
{
	QString colunmStr;
	if (columndata.count() == 0)
		colunmStr = "*";
	else
	{
		QStringList keys = columndata.keys();
		for (auto key : keys)
		{
			QString column = QString("%1 AS `%2`").arg(key).arg(columndata[key]);
			if (!colunmStr.isEmpty())
				colunmStr += ",";
			colunmStr += column;
		}
	}
	QString queryStr = QString("SELECT %1 FROM %2 %3").arg(colunmStr).arg(tableName).arg(sqlWhere);
	if (!queryExec(dbName, queryStr, data))
	{
		return  false;
	}
	return  true;
}
bool SQLiteDriver::addData(QString dbName, QString tableName, QHash<QString, QString> data)
{
	if (data.isEmpty())
		return false;
	QString queryStr = "insert into " + tableName + " ";
	QString fieldStr = "(", valueStr = "values(";
	QHash<QString, QString>::iterator it;
	for (it = data.begin(); it != data.end(); ++it)
	{
		fieldStr += it.key() + ",";
		valueStr += "'" + it.value() + "',";
	}
	fieldStr = fieldStr.left(fieldStr.length() - 1);
	valueStr = valueStr.left(valueStr.length() - 1);
	fieldStr += ")";
	valueStr += ")";
	queryStr += fieldStr + " " + valueStr;
	if (!queryExec(dbName, queryStr))
	{
		qDebug() << "SQLiteDriver::addData:"<<queryStr;
        qDebug() << "SQLiteDriver::addData:" << getErrorSql();
		return false;
	}
	return true;
}

bool SQLiteDriver::delData(QString dbName, QString tableName, QString sqlWhere)
{
	QString queryStr = "delete from " + tableName;
	if (!sqlWhere.isEmpty())
		queryStr += " " + sqlWhere;
	if (!queryExec(dbName, queryStr))
	{
		return false;
	}
	return true;
}

bool SQLiteDriver::updateData(QString dbName, QString tableName, QHash<QString, QString> data, QString sqlWhere)
{
	QString queryStr = "update " + tableName + " ";
	QHash<QString, QString>::iterator it;
	QString setStr = "set ";
	for (it = data.begin(); it != data.end(); ++it)
	{
		setStr += it.key() + "='" + it.value() + "'";
		setStr += ",";
	}
	setStr = setStr.left(setStr.length() - 1);
	queryStr += setStr;
	if (!sqlWhere.isEmpty())
		queryStr += " " + sqlWhere;
	if (!queryExec(dbName, queryStr))
	{
		return false;
	}
	return true;
}


bool SQLiteDriver::queryExec(QString sqlStr)
{
	if (databaseName.isEmpty())
		return false;
	return  queryExec(databaseName, sqlStr);
}
bool SQLiteDriver::queryExec(QString sqlStr, QList<QHash<QString, QVariant>>* data)
{
	if (databaseName.isEmpty())
		return false;
	return  queryExec(databaseName, sqlStr, data);
}

bool SQLiteDriver::creatTable(QString tableName, QList<DBTable>& data)
{
	if (databaseName.isEmpty())
		return false;
	return  creatTable(databaseName, tableName, data);
}

bool SQLiteDriver::getTableList(QList<QString>* list)
{
	if (databaseName.isEmpty())
		return false;
	return  getTableList(databaseName, list);
}
bool SQLiteDriver::getData(QString tableName, QHash<QString, QVariant>* data, QString sqlWhere)
{
	if (databaseName.isEmpty())
		return false;
	return  getData(databaseName, tableName, data, sqlWhere);
}

bool SQLiteDriver::getData(QString tableName, QList<QHash<QString, QVariant>>* data, QString sqlWhere)
{
	if (databaseName.isEmpty())
		return false;
	return  getData(databaseName, tableName, data, sqlWhere);
}

bool SQLiteDriver::getData(QString tableName, QHash<QString, QString> columndata, QList<QHash<QString, QVariant>>* data, QString sqlWhere)
{
	if (databaseName.isEmpty())
		return false;
	return  getData(databaseName, tableName, columndata, data, sqlWhere);
}

bool SQLiteDriver::addData(QString tableName, QHash<QString, QString> data)
{
	if (databaseName.isEmpty())
		return false;
	return  addData(databaseName, tableName, data);
}

bool SQLiteDriver::delData(QString tableName, QString sqlWhere)
{
	if (databaseName.isEmpty())
		return false;
	return  delData(databaseName, tableName, sqlWhere);
}

bool SQLiteDriver::updateData(QString tableName, QHash<QString, QString> data, QString sqlWhere)
{
	if (databaseName.isEmpty())
		return false;
	return  updateData(databaseName, tableName, data, sqlWhere);
}

