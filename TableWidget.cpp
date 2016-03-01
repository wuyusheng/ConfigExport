


//class include
#include "tablewidget.h"

//Qt lib include
#include <stdlib.h>
#include <QString>
#include <QVBoxLayout>
#include <QAction>
#include <QWindow>
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>
#include <QFileDialog>
#include <QStackedLayout> 
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QRadioButton>
#include <QGroupBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>


//Project include
#include "common.h"
#include "util.h"
#include "model.h"
#include "delegate.h"

#define TYPE_ALL	"All"
#define TYPE_YC		"YC"
#define TYPE_YX		"YX"
#define TYPE_YK		"YK"
#define TYPE_YM		"YM"
#define TYPE_SD		"SD"

QWSTableWidget::QWSTableWidget(QWidget *parent)
: QWidget(parent)
{
	init();
}

QWSTableWidget::~QWSTableWidget()
{

}

void QWSTableWidget::init()
{
	m_ui = new Ui_tabledetailwidget();
	m_ui->setupUi(this);

	m_pSqlTableModel = NULL;
	m_pointType = TYPE_ALL;
	m_deviceID = -1;

	m_ui->pointTypeCombox->addItem(QStringLiteral("全部"), TYPE_ALL);
	m_ui->pointTypeCombox->addItem(QStringLiteral("遥测量"), TYPE_YC);
	m_ui->pointTypeCombox->addItem(QStringLiteral("遥信量"), TYPE_YX);
	m_ui->pointTypeCombox->addItem(QStringLiteral("遥控量"), TYPE_YK);
	m_ui->pointTypeCombox->addItem(QStringLiteral("遥脉量"), TYPE_YM);
	m_ui->pointTypeCombox->addItem(QStringLiteral("设备定值"), TYPE_SD);

	connect(m_ui->pointTypeCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_pointTypeChanges(int)));
	connect(m_ui->btnCommitChanges, SIGNAL(pressed()), this, SLOT(slot_saveChanges()));
	connect(m_ui->btnExport, SIGNAL(pressed()), this, SLOT(slot_export()));
	connect(m_ui->btnAdd, SIGNAL(pressed()), this, SLOT(slot_addNewRow()));
	connect(m_ui->btnRollback, SIGNAL(pressed()), this, SLOT(slot_rollback()));
	connect(m_ui->btnDelete, SIGNAL(pressed()), this, SLOT(slot_deleteRow()));
}

void QWSTableWidget::updateFilter()
{
	if (!m_pPointSqlTableMode)
		return;

	QString filterStr = QString("PtType = '%1'").arg(m_pointType);
	if (m_pointType == "All")
		filterStr = "";

	if (m_deviceID != -1)
	{
		if (filterStr.isEmpty())
			filterStr = QString("DevID = %1").arg(m_deviceID);
		else
			filterStr += QString(" And DevID = %1").arg(m_deviceID);
	}

	m_pPointSqlTableMode->setFilter(filterStr);
}

/*
void QWSTableWidget::openTable(QString db, QString dataFilter)
{
	if (!m_pSqlTableModel)
	{
		CSysUtil::connectDatabase(db);
		QSqlDatabase dbconn = QSqlDatabase::database(db, true);
		m_pSqlTableModel = new QSqlTableModel(this, dbconn);
		setSqlModel(m_pSqlTableModel);
	}

	QStringList dataList = dataFilter.split(",");
	if (dataList.count() != 2)
	{
		qDebug() << "data filter count error, it is not 2.";
		return;
	}

	QString tableName = dataList.at(0);

	m_pSqlTableModel->setTable(tableName);
	m_pSqlTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	m_pSqlTableModel->setSort(0, Qt::AscendingOrder);
	m_pSqlTableModel->select();

	/*
	m_pSqlTableModel->removeColumn(2); // don't show the ID
	m_pSqlTableModel->removeColumn(7);
	m_pSqlTableModel->removeColumn(7);
	m_pSqlTableModel->removeColumn(7);

	m_pSqlTableModel->setHeaderData(0, Qt::Horizontal, QStringLiteral("点ID"));
	m_pSqlTableModel->setHeaderData(1, Qt::Horizontal, QStringLiteral("设备ID"));
	m_pSqlTableModel->setHeaderData(2, Qt::Horizontal, QStringLiteral("功能号"));
	m_pSqlTableModel->setHeaderData(3, Qt::Horizontal, QStringLiteral("信息号"));
	m_pSqlTableModel->setHeaderData(4, Qt::Horizontal, QStringLiteral("系数"));
	m_pSqlTableModel->setHeaderData(5, Qt::Horizontal, QStringLiteral("修正值"));
	m_pSqlTableModel->setHeaderData(6, Qt::Horizontal, QStringLiteral("附加值"));
	m_pSqlTableModel->setHeaderData(7, Qt::Horizontal, QStringLiteral("点描述"));

	updateFilter();
	*/
//}

void QWSTableWidget::openTable(QString tableString)
{
	QStringList dataList = tableString.split("#");
	if (dataList.count() != 2)
	{
		qDebug() << "data filter count error, it is not 2.";
		return;
	}

	QString tableName = dataList.at(0);

	m_pSqlTableModel->setTable(tableName);
	m_pSqlTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	m_pSqlTableModel->setSort(0, Qt::AscendingOrder);
	m_pSqlTableModel->select();
	
	if (tableName == DEVICE_TABLE_NAME)
	{
		bool bOk;
		m_deviceID = dataList.at(1).toInt(&bOk);
		if (!bOk)
			m_deviceID = -1;
	}
	else
		m_deviceID = -1;

	updateFilter();

	createDelegate(tableName);
}

void QWSTableWidget::setDatabaseAdapter(CDatabaseAdapter* pDatabaseAdapter)
{
	m_pDatabaseAdapter = pDatabaseAdapter;
}

void QWSTableWidget::createSqlModel()
{
	m_pSqlTableModel = new QSqlTableModel(this, m_pDatabaseAdapter->database());

	if (m_ui)
		m_ui->configTableView->setModel(m_pSqlTableModel);

	m_pPointSqlTableMode = new QSqlTableModel(this, m_pDatabaseAdapter->database());
	if (m_ui)
	{
		m_ui->pointTableView->setModel(m_pPointSqlTableMode);

		m_pPointSqlTableMode->setTable("TblPoint");
		m_pPointSqlTableMode->setEditStrategy(QSqlTableModel::OnManualSubmit);
		m_pPointSqlTableMode->setSort(0, Qt::AscendingOrder);
		m_pPointSqlTableMode->select();
	}
}

void QWSTableWidget::slot_saveChanges()
{
	bool bRel  = m_pPointSqlTableMode->submitAll();
	if (bRel)
		CSysUtil::infoMessage(QStringLiteral("保存数据成功！"));
	else
		CSysUtil::warnMessage(m_pPointSqlTableMode->lastError().text());
}

void QWSTableWidget::slot_pointTypeChanges(int index)
{
	QString comboxData = m_ui->pointTypeCombox->itemData(index).toString();
	m_pointType = comboxData.trimmed();
	updateFilter();
}

void QWSTableWidget::slot_export()
{
	CExportConfigDialog* pExportDlg = new CExportConfigDialog();
	pExportDlg->setDatabaseAdapter(m_pDatabaseAdapter);
	pExportDlg->exec();
}

void QWSTableWidget::slot_addNewRow()
{
	if (m_pPointSqlTableMode)
	{
		int nRowCount = m_pPointSqlTableMode->rowCount();
		m_pPointSqlTableMode->insertRow(nRowCount);

		QModelIndex index = m_pPointSqlTableMode->index(nRowCount, 0);
		m_ui->pointTableView->selectRow(nRowCount);
		m_ui->pointTableView->scrollTo(index);
	}
}

void QWSTableWidget::slot_rollback()
{
	if (m_pPointSqlTableMode)
		m_pPointSqlTableMode->revertAll();
}

void QWSTableWidget::slot_deleteRow()
{
	if (!m_pPointSqlTableMode)
		return;
	int nRow = m_ui->pointTableView->currentIndex().row();
	m_pPointSqlTableMode->removeRow(nRow);

	int ok = CSysUtil::confirmMessage(QStringLiteral("你确定删除当前行吗？"));
	if (ok == QMessageBox::Yes)
	{
		m_pPointSqlTableMode->submitAll();
	}
	else
		m_pPointSqlTableMode->revertAll();
}

void QWSTableWidget::createDelegate(QString tableName)
{
	if (tableName == PORT_TABLE_NAME)
	{
		m_pTableDelegate = new QWSTableDelegate(this);
		m_ui->configTableView->setItemDelegate(m_pTableDelegate);
	}
}
