/*!
 * \class 
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
 * \date Ê®ÔÂ 2015
 *
 * Contact: wuys_bj@163.com
 *
 */

#include <QtWidgets/QApplication>
#include <QTextCodec>

#include "mainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon("sysconfig.ico"));

	QWSMainWindow w;
	w.show();

	int rel = a.exec();

	return rel;
}
