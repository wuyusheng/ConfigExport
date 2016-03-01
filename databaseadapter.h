#ifndef __WS_DATABASE_ADAPTER_H__
#define __WS_DATABASE_ADAPTER_H__

//Qt include
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>

class CDatabaseAdapter
{
public:
					CDatabaseAdapter();
					~CDatabaseAdapter();

	bool			createDatabase(QString dbPath);
	bool			openDatabase(QString dbPath);
	void			closeDatabase();
	QSqlQuery		sqlQuery() { return m_query; }
	QSqlDatabase	database() { return m_database; }

private:
	QSqlDatabase	m_database;
	QSqlQuery		m_query;
};

#endif // __WS_DATABASE_ADAPTER_H__
