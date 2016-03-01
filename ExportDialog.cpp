
#include "exportdialog.h"

//class inclue
#include "util.h"
#include "common.h"


//lib inclue
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>


CExportConfigDialog::CExportConfigDialog()
{
	m_ui = new Ui_exportDialog();
	m_ui->setupUi(this);

	connect(m_ui->checkSelectAll, SIGNAL(clicked(bool)), this, SLOT(slot_selectAllChanged(bool)));
	connect(m_ui->btnSelect, SIGNAL(pressed()), this, SLOT(slot_selectExportDir()));

	m_ui->lineEditExportPath->setText(QDir::currentPath() + "/output/");
}

CExportConfigDialog::~CExportConfigDialog()
{

}

void CExportConfigDialog::accept()
{
	QString filePath = m_ui->lineEditExportPath->text().trimmed();
	QDir dir;
	dir.mkdir(filePath);
	filePath += "%1";

	QSqlQuery query;
	QString sql;
	bool bRel;
	//1）>>>>>> YC >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkYC->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1 where PtType = '%2'";
		bRel = query.exec(sql.arg(POINT_TABLE_NAME).arg("YC"));
		if (bRel)
		{
			QFile file(filePath.arg("yc"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << "\n";

			sql = "select PtID, DevID, FUN, INF, Ratio, Revise, Append from %1 where PtType = '%2'";
			query.exec(sql.arg(POINT_TABLE_NAME).arg("YC"));
			while (query.next())
			{
				outdata << query.value(0).toInt() << " ";
				outdata << query.value(1).toInt() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << " ";
				outdata << query.value(4).toInt() << " ";
				outdata << query.value(5).toInt() << " ";
				outdata << query.value(6).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出遥测量配置错误"));
	}
	

	//2）>>>>>> YX >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkYX->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1 where PtType = '%2'";
		bRel = query.exec(sql.arg(POINT_TABLE_NAME).arg("YX"));
		if (bRel)
		{
			QFile file(filePath.arg("yx"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << "\n";

			sql = "select PtID, DevID, FUN, INF, Append from %1 where PtType = '%2'";
			query.exec(sql.arg(POINT_TABLE_NAME).arg("YX"));
			while (query.next())
			{
				outdata << query.value(0).toInt() << " ";
				outdata << query.value(1).toInt() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << " ";
				outdata << query.value(4).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出遥信量配置错误"));
	}
	

	//3）>>>>>> YK >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkYK->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1 where PtType = '%2'";
		bRel = query.exec(sql.arg(POINT_TABLE_NAME).arg("YK"));
		if (bRel)
		{
			QFile file(filePath.arg("yk"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << "\n";

			sql = "select PtID, DevID, FUN, INF, Append from %1 where PtType = '%2'";
			query.exec(sql.arg(POINT_TABLE_NAME).arg("YK"));
			while (query.next())
			{
				outdata << query.value(0).toInt() << " ";
				outdata << query.value(1).toInt() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << " ";
				outdata << query.value(4).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出遥控量配置错误"));
	}
	

	//4）>>>>>> YM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkYM->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1 where PtType = '%2'";
		bRel = query.exec(sql.arg(POINT_TABLE_NAME).arg("YM"));
		if (bRel)
		{
			QFile file(filePath.arg("ym"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << "\n";

			sql = "select PtID, DevID, FUN, INF, Append from %1 where PtType = '%2'";
			query.exec(sql.arg(POINT_TABLE_NAME).arg("YM"));
			while (query.next())
			{
				outdata << query.value(0).toInt() << " ";
				outdata << query.value(1).toInt() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << " ";
				outdata << query.value(4).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出遥脉量配置错误"));
	}

	//5）>>>>>> PORT >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkPort->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1";
		bRel = query.exec(sql.arg(PORT_TABLE_NAME));
		if (bRel)
		{
			QFile file(filePath.arg("port"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << "\n";

			QString ucSql = QString("select UCID, UCName from %1").arg(UC_TABLE_NAME);
			query.exec(ucSql);
			QString ucName;
			QMap<int, QString> mapUC;
			while (query.next())
			{
				mapUC.insert(query.value(0).toInt(), query.value(1).toString());
			}

			sql = "select * from %1";
			query.exec(sql.arg(PORT_TABLE_NAME));
			while (query.next())
			{
				QMap<int, QString>::iterator it = mapUC.find(query.value(1).toInt());

				QString ucName = it.value();

				outdata << query.value(0).toInt() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << " ";
				outdata << query.value(4).toString() << " ";
				outdata << ucName << " ";
				outdata << query.value(5).toInt() << " ";
				outdata << query.value(6).toInt() << " ";
				outdata << query.value(7).toInt() << " ";
				outdata << query.value(8).toInt() << " ";
				outdata << query.value(9).toInt() << " ";
				outdata << query.value(10).toInt() << " ";
				outdata << query.value(11).toInt() << " ";
				outdata << query.value(12).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出端口配置错误"));
	}


	//6）>>>>>> DEVICE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkDevice->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1";
		bRel = query.exec(sql.arg(DEVICE_TABLE_NAME));
		if (bRel)
		{
			QFile file(filePath.arg("device"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << " ";

			QString projectSql = QString("select OfflineTime, CheckTime, LbTime from %1").arg(PROJECT_TABLE_NAME);
			query.exec(projectSql);
			if (query.next())
			{
				outdata << query.value(0).toInt() << " ";
				outdata << query.value(1).toInt() << " ";
				outdata << query.value(2).toInt() << "\n";
			}

			sql = "select DevID, PortID, Address, LbOption from %1";
			query.exec(sql.arg(DEVICE_TABLE_NAME));
			while (query.next())
			{
				outdata << query.value(0).toInt() << " ";
				outdata << query.value(1).toInt() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出设备配置错误"));
	}

	//6）>>>>>> BLOCK MDPOINT >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkModbus->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1";
		bRel = query.exec(sql.arg(MD_TABLE_NAME));
		if (bRel)
		{
			QFile file(filePath.arg("block"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << "\n";

			sql = "select * from %1";
			query.exec(sql.arg(MD_TABLE_NAME));
			while (query.next())
			{
				outdata << query.value(1).toInt() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << " ";
				outdata << query.value(4).toInt() << " ";
				outdata << query.value(5).toInt() << " ";
				outdata << query.value(6).toInt() << " ";
				outdata << query.value(7).toInt() << " ";
				outdata << query.value(8).toInt() << " ";
				outdata << query.value(9).toInt() << " ";
				outdata << query.value(10).toInt() << " ";
				outdata << query.value(11).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出ModBus配置错误"));
	}

	//7）>>>>>> PROTOCOL >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (m_ui->checkProtocol->isChecked())
	{
		query = m_pDatabaseAdapter->sqlQuery();
		sql = "select count(*) from %1";
		bRel = query.exec(sql.arg(PROTOCOL_TABLE_NAME));
		if (bRel)
		{
			QFile file(filePath.arg("protocol.txt"));

			if (!file.open(QIODevice::WriteOnly | QIODevice::Text/* | QIODevice::Append*/))
			{
				CSysUtil::errorMessage(QStringLiteral("导出文件时失败!"));
				return;
			}
			QTextStream outdata(&file);
			if (query.next())
				outdata << query.value(0).toInt() << "\n";

			sql = "select * from %1";
			query.exec(sql.arg(PROTOCOL_TABLE_NAME));
			while (query.next())
			{
				outdata << query.value(0).toInt() << " ";
				outdata << query.value(1).toString() << " ";
				outdata << query.value(2).toInt() << " ";
				outdata << query.value(3).toInt() << "\n";
			}

			file.close();
		}
		else
			CSysUtil::errorMessage(QStringLiteral("导出协议配置错误"));
	}

	CSysUtil::infoMessage(QStringLiteral("配置文件导出结束."));
	QDialog::accept();
}

void CExportConfigDialog::slot_selectAllChanged(bool bChecked)
{
	m_ui->checkPort->setChecked(bChecked);
	m_ui->checkDevice->setChecked(bChecked);
	m_ui->checkModbus->setChecked(bChecked);
	m_ui->checkYC->setChecked(bChecked);
	m_ui->checkYX->setChecked(bChecked);
	m_ui->checkYK->setChecked(bChecked);
	m_ui->checkYM->setChecked(bChecked);
	m_ui->checkDDYC->setChecked(bChecked);
	m_ui->checkDDYX->setChecked(bChecked);
	m_ui->checkZFYK->setChecked(bChecked);
	m_ui->checkZFYM->setChecked(bChecked);
	m_ui->checkIP->setChecked(bChecked);
	m_ui->checkDZ->setChecked(bChecked);
	m_ui->checkProtocol->setChecked(bChecked);
}

void CExportConfigDialog::slot_selectExportDir()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		QDir::currentPath(),
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	
	if (dir.isEmpty())
		m_ui->lineEditExportPath->setText(QDir::currentPath() + "/output/");
	else
		m_ui->lineEditExportPath->setText(dir + "/output/");
}
