/*!
 * \file QWSMainWindow.h
 * \date 2015/10/30 11:21
 *
 * \author Wu Yusheng (Michael.Woo)
 * Contact: wuys_bj@163.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/
#ifndef __WS_QWSMainWindow_H__
#define __WS_QWSMainWindow_H__



//qt lib
#include <QMainWindow>
#include <QMenu>


//project inlcude
#include "treewidget.h"
#include "tablewidget.h"
#include "util.h"


class QWSMainWindow : public QMainWindow
{
	Q_OBJECT

public:
							QWSMainWindow();
							~QWSMainWindow();

private slots:
	void					slot_treeItemChanges(QString showString, QString data);
	void					slot_openProject();
	void					slot_saveProject();
	void					slot_about();
	void					slot_refresh();
	void					slot_newProject();

private:
	void					closeEvent(QCloseEvent * event);

	QMenu*					m_fileMenu;
	QMenu*					m_editMenu;
	QMenu*					m_layerMenu;
	QMenu*					m_helpMenu;

	QAction*				m_fileNewAction;
	QAction*				m_fileOpenAction;
	QAction*				m_fileSaveAction;
	QAction*				m_fileQuit;
	QAction*				m_EditRefresh;

	QToolBar*				m_pToolBar;
	QStatusBar*				m_pStatusBar;

	QWSTreeWidget*			m_pTreeWidget;
	QWSTableWidget*			m_pTableWidget;

	CDatabaseAdapter*		m_pDatabaseAdapater;

	QString					m_projectFilePath; //db file


	void					connectSlots();
	void					init();
	void					initMenu();
	void					initToolbar();
	void					initStatusbar();
	void					createWidget();
};


#endif // __WS_QWSMainWindow_H__