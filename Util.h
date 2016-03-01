/*!
 * \file util.h
 * \date 2015/11/04 11:56
 *
 * \author Wu Yusheng (Michael.Woo)
 * Contact: wuys_bj@163.com
 *
 * \brief GISͨ�ú���
 *
 * TODO: ���ú�����������
 *
 * \note
*/

#ifndef __WS_UTIL_H__
#define __WS_UTIL_H__

//Qt include
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "ui_exportdialog.h"


class CSysUtil
{

public:

	//��ȡgis������Ŀ¼
	static QString				gisHomeDir();

	static bool					connectDatabase(QString dbName);

	static QString getIconFullName(QString &iconName)
	{
		QString SmartSysHome = QString(qgetenv("SMARTSYS_HOME"));
		return SmartSysHome.append("/data/images/").append(iconName);
	}

	static void warnMessage(const QString &text)
	{
		QMessageBox::warning(NULL, QStringLiteral("����"), text);
	}
	static void infoMessage(const QString &text)
	{
		QMessageBox::information(NULL, QStringLiteral("��Ϣ"), text);
	}
	static void errorMessage(const QString &text)
	{
		QMessageBox::critical(NULL, QStringLiteral("����"), text);
	}

	static int confirmMessage(const QString &text)
	{
		QMessageBox msgBox(QMessageBox::Question, QStringLiteral("ѯ��"), text, QMessageBox::Yes | QMessageBox::Cancel);
		return msgBox.exec();
	}

};

#endif // __WS_UTIL_H__
