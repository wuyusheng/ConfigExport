#ifndef __SF_TABLEWIDGET_H__
#define __SF_TABLEWIDGET_H__

#include "util.h"

//qt lib
#include <QTableWidget>
#include "ui_tabledetailwidget.h"
#include "databaseadapter.h"
#include "exportdialog.h"

class QWSTableModel;
class QWSTableDelegate;
class QStandardItemModel;
class QSqlQueryModel;
class QRadioButton;
class QSqlTableModel;
class QGroupBox;


class QWSTableWidget : public QWidget
{
	Q_OBJECT

public:
							QWSTableWidget(QWidget* parent = 0);
							~QWSTableWidget();

	void					createSqlModel();
	void					openTable(QString tableString);
	void					updateFilter();
	

	void					setDatabaseAdapter(CDatabaseAdapter* pDatabaseAdapter);

public slots:
	void					slot_saveChanges();
	void					slot_pointTypeChanges(int index);
	void					slot_export();
	void					slot_addNewRow();
	void					slot_rollback();
	void					slot_deleteRow();

private:
	void					init();
	void					createDelegate(QString tableName);
	
	QSqlTableModel*			m_pSqlTableModel;
	QSqlTableModel*			m_pPointSqlTableMode;

	QWSTableDelegate*		m_pTableDelegate;

	CDatabaseAdapter*		m_pDatabaseAdapter;

	int						m_deviceID;
	QString					m_pointType;

	Ui_tabledetailwidget*	m_ui;
};


#endif // __SF_TABLEWIDGET_H__
