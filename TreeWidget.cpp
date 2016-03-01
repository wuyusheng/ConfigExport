//class include
#include "treewidget.h"

//Qt lib include
#include <QTreeView>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QItemSelection>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


//Project include
#include "common.h"
#include "util.h"

#define  DATA_ROLE Qt::UserRole+100


QWSTreeWidget::QWSTreeWidget(QWidget* parent)
: QWidget(parent)
{
	init();
}

QWSTreeWidget::~QWSTreeWidget()
{

}

void QWSTreeWidget::init()
{
	m_treeModel = new SmartTreeModel(this);
	m_treeModel->appendColumn(SmartGridColumn(DEFAULT_ID_FIELD, QStringLiteral("工程")));
	m_treeModel->appendColumn(SmartGridColumn(DEFAULT_TEXT_FIELD, QStringLiteral("工程名")));
	m_treeModel->setIdField(0);
	m_treeModel->setTextField(1);
	m_treeModel->setPidField(DEFAULT_PID_FIELD);
	m_treeModel->setIconField(DEFAULT_ICON_FIELD);
	
	m_treeView = new QTreeView(this);
	m_treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_treeView->setHeaderHidden(true);

	QHBoxLayout* pLayout = new QHBoxLayout(this);
	pLayout->setMargin(0);
	pLayout->setSpacing(0);
	pLayout->addWidget(m_treeView);
	setLayout(pLayout);

	//register the model
	m_treeView->setModel(m_treeModel);
	m_treeView->expandAll();

	//selection changes shall trigger a slot
	QItemSelectionModel* selectionModel = m_treeView->selectionModel();
	connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
		this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));

}

void QWSTreeWidget::selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/)
{
	//get the text of the selected item
	const QModelIndex index = m_treeView->selectionModel()->currentIndex();
	QString selectedText = index.data(Qt::DisplayRole).toString();
	QString dataString = "";

	SmartTreeItem *item = static_cast<SmartTreeItem*>(index.internalPointer());
	if (item)
	{
		QString type = item->data(DEFAULT_TYPE_FIELD).toString();
		dataString = item->data(DEFAULT_ID_FIELD).toString();
	}

	QString showString = QString("%1, %2").arg(selectedText)
		.arg(dataString);

	emit sig_selectionChanged(showString, dataString);
}

void QWSTreeWidget::createProjectDataset()
{
	if (!m_pDatabaseAdapter || !m_treeModel)
		return;

	QSqlQuery sqlQuery = m_pDatabaseAdapter->sqlQuery();
	QString sql;
	bool bRel;

	QList<QVariantMap> recordList;

	//Project
	sql = "select ProjectName from TblProject";
	bRel = sqlQuery.exec(sql);
	QString strProjectName;
	if (bRel)
	{
		while (sqlQuery.next())
		{
			QVariantMap m;

			QString name = sqlQuery.value(0).toString();
			strProjectName = "TblProject#1";
			m.insert(DEFAULT_ID_FIELD, strProjectName);
			m.insert(DEFAULT_TEXT_FIELD, QStringLiteral("工程：") + name);
			m.insert(DEFAULT_PID_FIELD, QVariant());
			m.insert(DEFAULT_ICON_FIELD, ":/project.png");
			m.insert(DEFAULT_TYPE_FIELD, TYPE_PROJECT);
			recordList.append(m);
		}
	}

	//UC
	sql = "select UCID, UCName from TblUC";
	bRel = sqlQuery.exec(sql);
	QMap<int, QString> ucMap;
	if (bRel)
	{
		while (sqlQuery.next())
		{
			QVariantMap m;

			QString ucName = sqlQuery.value(1).toString();
			QString ucIDStr = "TblUC#" + sqlQuery.value(0).toString();

			m.insert(DEFAULT_ID_FIELD, ucIDStr);
			m.insert(DEFAULT_TEXT_FIELD, ucName);
			m.insert(DEFAULT_PID_FIELD, strProjectName);
			m.insert(DEFAULT_ICON_FIELD, ":/uc.png");
			m.insert(DEFAULT_TYPE_FIELD, TYPE_UC);
			recordList.append(m);
			ucMap.insert(sqlQuery.value(0).toInt(), ucIDStr);
		}
	}

	//PORT
	QMap<int, QString>::const_iterator it = ucMap.constBegin();
	QMap<int, QString> portMap;
	while (it != ucMap.constEnd())
	{
		sql = QString("select PortID from TblPort where UCID = %1").arg(it.key());
		bRel = sqlQuery.exec(sql);
		if (bRel)
		{
			while (sqlQuery.next())
			{
				QVariantMap m;

				QString portIDStr = "TblPort#" + sqlQuery.value(0).toString();
				m.insert(DEFAULT_ID_FIELD, portIDStr);
				m.insert(DEFAULT_TEXT_FIELD, QStringLiteral("端口-P%1").arg(sqlQuery.value(0).toInt()));
				m.insert(DEFAULT_PID_FIELD, it.value());
				m.insert(DEFAULT_ICON_FIELD, ":/port.png");
				m.insert(DEFAULT_TYPE_FIELD, TYPE_PORT);
				recordList.append(m);
				portMap.insert(sqlQuery.value(0).toInt(), portIDStr);
			}
		}
		++it;
	}

	//DEVICE
	it = portMap.constBegin();
	while (it != portMap.constEnd())
	{
		sql = QString("select DevID, Address, DevType, DevDsp from TblDevice where PortID = %1").arg(it.key());
		bRel = sqlQuery.exec(sql);
		if (bRel)
		{
			while (sqlQuery.next())
			{
				QVariantMap m;

				QString devID = "TblDevice#" + sqlQuery.value(0).toString();
				QString devAdd = sqlQuery.value(1).toString();
				QString devType = sqlQuery.value(2).toString();
				QString devDsp = sqlQuery.value(3).toString();

				m.insert(DEFAULT_ID_FIELD, devID);
				m.insert(DEFAULT_TEXT_FIELD, devAdd + " " + devType + " " + devDsp);
				m.insert(DEFAULT_PID_FIELD, it.value());
				m.insert(DEFAULT_ICON_FIELD, ":/device.png");
				m.insert(DEFAULT_TYPE_FIELD, TYPE_DEVICE);
				recordList.append(m);
			}
		}
		++it;
	}

	//Protocol
	QVariantMap m;
	QString strProtocolName = "TblProtocol#1";
	m.insert(DEFAULT_ID_FIELD, strProtocolName);
	m.insert(DEFAULT_TEXT_FIELD, QStringLiteral("协议管理"));
	m.insert(DEFAULT_PID_FIELD, strProjectName);
	m.insert(DEFAULT_ICON_FIELD, ":/protocol.png");
	m.insert(DEFAULT_TYPE_FIELD, TYPE_PROTOCOL);
	recordList.append(m);

	m_treeModel->setDataSet(recordList);
}
