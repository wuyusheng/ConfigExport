
#ifndef __SF_TREEWIDGET_H__
#define __SF_TREEWIDGET_H__



//qt lib
#include <QWidget>

#include "smarttreemodel.h"
#include "util.h"
#include "databaseadapter.h"



class QTreeView;
class QStandardItemModel;
class QItemSelection;

#define TYPE_PROJECT	"project"
#define TYPE_UC			"uc"
#define TYPE_PORT		"port"
#define TYPE_DEVICE		"device"
#define TYPE_PROTOCOL	"protocol"


class QWSTreeWidget : public QWidget
{
	Q_OBJECT

public:
								QWSTreeWidget(QWidget *parent = 0);
								~QWSTreeWidget();


	void						createProjectDataset();
	void						setDataseAdapter(CDatabaseAdapter* pDatabaseAdapter) { m_pDatabaseAdapter = pDatabaseAdapter; }

signals:
	void						sig_selectionChanged(QString text, QString data);


private slots:
	void						selectionChangedSlot(const QItemSelection & newSelection, const QItemSelection & oldSelection);

private:
	void						init();


	QTreeView*					m_treeView;
	SmartTreeModel*				m_treeModel;
	CDatabaseAdapter*			m_pDatabaseAdapter;
};

#endif // __SF_TREEWIDGET_H__


