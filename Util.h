/*!
 * \file util.h
 * \date 2015/11/04 11:56
 *
 * \author Wu Yusheng (Michael.Woo)
 * Contact: wuys_bj@163.com
 *
 * \brief GIS通用函数
 *
 * TODO: 公用函数方法定义
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

	//获取gis的运行目录
	static QString				gisHomeDir();

	static bool					connectDatabase(QString dbName);

	static QString getIconFullName(QString &iconName)
	{
		QString SmartSysHome = QString(qgetenv("SMARTSYS_HOME"));
		return SmartSysHome.append("/data/images/").append(iconName);
	}

	static void warnMessage(const QString &text)
	{
		QMessageBox::warning(NULL, QStringLiteral("警告"), text);
	}
	static void infoMessage(const QString &text)
	{
		QMessageBox::information(NULL, QStringLiteral("消息"), text);
	}
	static void errorMessage(const QString &text)
	{
		QMessageBox::critical(NULL, QStringLiteral("错误"), text);
	}

	static int confirmMessage(const QString &text)
	{
		QMessageBox msgBox(QMessageBox::Question, QStringLiteral("询问"), text, QMessageBox::Yes | QMessageBox::Cancel);
		return msgBox.exec();
	}

};

#endif // __WS_UTIL_H__
