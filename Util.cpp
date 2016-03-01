/*!
 * \class CSysUtil
 *
 * \ingroup GroupName
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note 
 *
 * \author Wu Yusheng(Michael.Woo)
 *
 * \version 1.0
 *
 * \date 十一月 2015
 *
 * Contact: wuys_bj@163.com
 *
 */

//class inclue
#include "util.h"


//lib inclue
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>


QString CSysUtil::gisHomeDir()
{
	QString strGISHome;
	QString sysHome = getenv("SMARTSYS_HOME");
	if (!sysHome.isEmpty())
	{
		strGISHome = sysHome + QDir::separator() + "bin" + QDir::separator() + "gis";
		QDir dirBin(strGISHome);
		if (!dirBin.exists())
		{
			strGISHome = sysHome + QDir::separator() + "binary" + QDir::separator() + "gis";
			QDir dirBinary(strGISHome);
			if (!dirBinary.exists())
			{
				strGISHome = QCoreApplication::applicationDirPath();;
			}
		}
	}

	return strGISHome;
}

bool CSysUtil::connectDatabase(QString dbName)
{
	if (dbName.isEmpty())
		return false;

	//获取是否存在有数据库连接  
	QSqlDatabase dbconn = QSqlDatabase::database(dbName, false);

	if (dbconn.isValid())//存在连接直接退出  
	{
		return false;
	}

	dbconn = QSqlDatabase::addDatabase("QODBC", dbName);
	QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access Database};DBQ=%1").arg(dbName);
	dbconn.setDatabaseName(dsn);
	//dbconn.setConnectOptions("SQL_ATTR_ACCESS_MODE=SQL_MODE_READ_ONLY;SQL_ATTR_TRACE=SQL_OPT_TRACE_ON"); // set ODBC options
	bool bRel = dbconn.open();
	if (!bRel)
		QMessageBox::information(NULL, "info", dbconn.lastError().text(), QMessageBox::Ok);
	//else
	//	QMessageBox::information(NULL, "info", "success.", QMessageBox::Ok);
	
	return bRel;
}