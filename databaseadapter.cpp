
#include "databaseadapter.h"

//class inclue
#include "util.h"
#include "common.h"


//lib inclue
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

CDatabaseAdapter::CDatabaseAdapter()
{

}

CDatabaseAdapter::~CDatabaseAdapter()
{
	m_database.close();
}

bool CDatabaseAdapter::openDatabase(QString dbPath)
{
	if (dbPath.isEmpty())
		return false;

	//获取是否存在有数据库连接  
	m_database = QSqlDatabase::database(dbPath, false);

	if (m_database.isValid())//存在连接直接退出  
	{
		return false;
	}

	m_database = QSqlDatabase::addDatabase("QODBC", dbPath);
	QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access Database};DBQ=%1").arg(dbPath);
	m_database.setDatabaseName(dsn);
	//dbconn.setConnectOptions("SQL_ATTR_ACCESS_MODE=SQL_MODE_READ_ONLY;SQL_ATTR_TRACE=SQL_OPT_TRACE_ON"); // set ODBC options
	bool bRel = m_database.open();
	if (!bRel)
		QMessageBox::information(NULL, "info", m_database.lastError().text(), QMessageBox::Ok);

	m_query = QSqlQuery(m_database);

	return bRel;
}

void CDatabaseAdapter::closeDatabase()
{
	m_database.close();
}

bool CDatabaseAdapter::createDatabase(QString dbPath)
{
	bool bRel = QFile::copy(TEMPLATE_PROJECT, dbPath);
	QDir dir;
	dir.mkdir(dbPath);
	if (!bRel)
	{
		CSysUtil::warnMessage(QStringLiteral("新建的工程已经存在，请重新命名新工程！"));
		return false;
	}

	m_database = QSqlDatabase::addDatabase("QODBC", dbPath);
	QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access Database};DBQ=%1").arg(dbPath);
	m_database.setDatabaseName(dsn);

	bRel = m_database.open();
	if (!bRel)
		QMessageBox::information(NULL, "info", m_database.lastError().text(), QMessageBox::Ok);

	m_query = QSqlQuery(m_database);

	bRel = m_query.exec(DEVICE_DDL);
	if (!bRel){
		CSysUtil::infoMessage("create project failed.");
	}

	bRel = m_query.exec(DIAODU_DDL);
	if (!bRel){
		CSysUtil::infoMessage("create project failed.");
	}

	bRel = m_query.exec(MODBUS_DDL);
	if (!bRel){
		CSysUtil::infoMessage("create project failed.");
	}

	bRel = m_query.exec(POINT_DDL);
	if (!bRel){
		CSysUtil::infoMessage("create project failed.");
	}

	bRel = m_query.exec(PORT_DDL);
	if (!bRel){
		CSysUtil::infoMessage("create project failed.");
	}

	bRel = m_query.exec(PROJECT_DDL);
	if (!bRel){
		CSysUtil::infoMessage("create project failed.");
	}
	QFileInfo info(dbPath);
	QString projName = info.baseName();
	m_query.exec(QString("insert into TblProject (ID, ProjectName) values (1, '%1')").arg(projName));

	bRel = m_query.exec(UC_DDL);
	if (!bRel){
		CSysUtil::infoMessage("create project failed.");
	}
	
	return true;
}
