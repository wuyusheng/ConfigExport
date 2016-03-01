/*!
 * \class QWSMainWindow
 *
 * \ingroup GroupName
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note 
 *
 * \author WuYusheng
 *
 * \version 1.0
 *
 * \date 
 *
 * Contact: wuys_bj@163.com
 *
 */

//class include
#include "mainWindow.h"

//Qt lib
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

//project include
#include "common.h"
#include "util.h"


QWSMainWindow::QWSMainWindow()
{
	setWindowTitle(QStringLiteral("���ù������"));
	setMinimumSize(WINDOW_MIN_WIDHT, WINDOW_MIN_HEIGHT);

	init();
	connectSlots();
}

QWSMainWindow::~QWSMainWindow()
{
}

void QWSMainWindow::init()
{
	initMenu();
	initToolbar();
	initStatusbar();
	createWidget();
}

void QWSMainWindow::initMenu()
{
	m_fileMenu = menuBar()->addMenu(QStringLiteral("�ļ�(&F)"));
	m_fileNewAction = new QAction(QIcon(":/filenew.png"), QStringLiteral("�½�"), this);
	connect(m_fileNewAction, SIGNAL(triggered()), this, SLOT(slot_newProject()));

	m_fileOpenAction = new QAction(QIcon(":/open.png"), QStringLiteral("��"), this);
	connect(m_fileOpenAction, SIGNAL(triggered()), this, SLOT(slot_openProject()));

	m_fileSaveAction = new QAction(QIcon(":/save.png"), QStringLiteral("����"), this);
	connect(m_fileSaveAction, SIGNAL(triggered()), this, SLOT(slot_saveProject()));

	m_fileQuit = new QAction(QIcon(":/exit.png"), QStringLiteral("�˳�"), this);
	m_fileQuit->setShortcut(QKeySequence::Quit);
	connect(m_fileQuit, SIGNAL(triggered()), this, SLOT(close()));

	m_fileMenu->addAction(m_fileOpenAction);
	m_fileMenu->addSeparator();
	m_fileMenu->addAction(m_fileSaveAction);
	m_fileMenu->addSeparator();
	m_fileMenu->addAction(m_fileQuit);

	m_editMenu = menuBar()->addMenu(QStringLiteral("�༭(&E)"));
	
	m_layerMenu = menuBar()->addMenu(QStringLiteral("�鿴(&L)"));
	m_EditRefresh = new QAction(QIcon(":/refresh.png"), QStringLiteral("ˢ��"), this);
	m_EditRefresh->setShortcut(QKeySequence::Refresh);
	connect(m_EditRefresh, SIGNAL(triggered()), this, SLOT(slot_refresh()));

	m_helpMenu = menuBar()->addMenu(QStringLiteral("����(&D)"));
	m_helpMenu = menuBar()->addMenu(QStringLiteral("����(&N)"));
	m_helpMenu = menuBar()->addMenu(QStringLiteral("����(&O)"));

	m_helpMenu = menuBar()->addMenu(QStringLiteral("����(&H)"));
	QAction* aboutAction = new QAction(QIcon(":/about.png"), tr("About"), this);
	m_helpMenu->addAction(aboutAction);
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(slot_about()));
}

void QWSMainWindow::initToolbar()
{
	m_pToolBar = addToolBar(tr("Operator Toolbar"));
	m_pToolBar->addAction(m_fileNewAction);
	m_pToolBar->addAction(m_fileOpenAction);
	m_pToolBar->addAction(m_fileSaveAction);
	m_pToolBar->addSeparator();
	m_pToolBar->addAction(m_EditRefresh);

	m_pToolBar->addSeparator();
	m_pToolBar->addAction(m_fileQuit);
}

void QWSMainWindow::initStatusbar()
{
	m_pStatusBar = statusBar();
	m_pStatusBar->showMessage("Sytem Configuration Tools for Desktop v0.1 (c) 2015,  Design by Michael.Wu.");
}

void QWSMainWindow::createWidget()
{
	m_pDatabaseAdapater = new CDatabaseAdapter();

	m_pTreeWidget = new QWSTreeWidget(this);
	m_pTreeWidget->setDataseAdapter(m_pDatabaseAdapater);

	m_pTableWidget = new QWSTableWidget(this);
	m_pTableWidget->setDatabaseAdapter(m_pDatabaseAdapater);

	QDockWidget *dockWidget = new QDockWidget(QStringLiteral("���ù��̹���"), this);
	dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidget->setWidget(m_pTreeWidget);
	addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

	setCentralWidget(m_pTableWidget);
}

void QWSMainWindow::slot_treeItemChanges(QString itemText, QString dataStr)
{
	if (m_pStatusBar)
		m_pStatusBar->showMessage(itemText);

	if (m_pTableWidget)
	{
		//dataStr split with #,like "TblDevce#2"
		m_pTableWidget->openTable(dataStr);
	}
}

void QWSMainWindow::connectSlots()
{
	if (m_pTreeWidget)
		connect(m_pTreeWidget, SIGNAL(sig_selectionChanged(QString, QString)), this, SLOT(slot_treeItemChanges(QString, QString)));
}

void QWSMainWindow::slot_openProject()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("��ѡ��򿪹���"),".",
													QStringLiteral("�����ļ� (*.pro *.prj *.projx)"));
	if (!fileName.isEmpty())
	{
		m_projectFilePath = fileName;
		m_pDatabaseAdapater->openDatabase(fileName);

		if (m_pTreeWidget)
			m_pTreeWidget->createProjectDataset();

		if (m_pTableWidget)
			m_pTableWidget->createSqlModel();
	}
}

void QWSMainWindow::slot_saveProject()
{
	qDebug() << "save test";

}

void QWSMainWindow::slot_about()
{
	QMessageBox::about(this, QStringLiteral("����"), QStringLiteral("<p>ͨѶ������������ Version:1.0<br><br>&nbsp;&nbsp;&nbsp;&nbsp;----Michael Woo(wuys_bj@163.com)</p>"));
}

void QWSMainWindow::closeEvent(QCloseEvent * event)
{
	QMessageBox::StandardButton rel = QMessageBox::question(this, QStringLiteral("��ʾ"), QStringLiteral("��ȷ����Ҫ�˳���"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel);
	if (rel == QMessageBox::Ok)
	{
		m_pDatabaseAdapater->closeDatabase();
		event->accept();
	}
	else
		event->ignore();	
}

void QWSMainWindow::slot_refresh()
{
	if (m_pTreeWidget)
		m_pTreeWidget->createProjectDataset();
}

void QWSMainWindow::slot_newProject()
{
	m_pDatabaseAdapater = new CDatabaseAdapter;
	m_pDatabaseAdapater->createDatabase("D:/Projects/ConfigExport/project/wys.projx");

	slot_refresh();
}
