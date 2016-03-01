#ifndef __WS_EXPORT_DIALOG_H__
#define __WS_EXPORT_DIALOG_H__

//Qt include
#include <QString>
#include <QMessageBox>
#include <QDialog>

#include "databaseadapter.h"
#include "ui_exportdialog.h"


class CExportConfigDialog : public QDialog
{
	Q_OBJECT

public:
						CExportConfigDialog();
						~CExportConfigDialog();

	void				setDatabaseAdapter(CDatabaseAdapter* pDatabaseAdapter) { m_pDatabaseAdapter = pDatabaseAdapter; }


public slots:
	void				slot_selectAllChanged(bool status);
	void				slot_selectExportDir();

public:
	void				accept();

private:
	Ui_exportDialog*	m_ui;
	CDatabaseAdapter*	m_pDatabaseAdapter;
};

#endif // __WS_EXPORT_DIALOG_H__
