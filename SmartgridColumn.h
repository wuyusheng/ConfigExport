#ifndef _SMART_GRID_COLUMN_H
#define _SMART_GRID_COLUMN_H

#include <QIcon>
#include <QVariantMap>
#include <QDateTime>
#include <QAbstractItemModel>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#define DEFAULT_DATE_TIME_FORMAT_STR "yyyy-MM-dd HH:mm:ss"

#define DATA_TYPE_STRING 1
#define DATA_TYPE_INT_32 2
#define DATA_TYPE_DATETIME 3
#define DATA_TYPE_FLOAT 4
#define DATA_TYPE_BINARY 5
#define DATA_TYPE_INT_64 7
#define DATA_TYPE_DOUBLE 8

#define  NEW_ITEM		1
#define  UPDATED_ITEM	2
#define  DELETED_ITEM	3
#define  STATUS_KEY		"_status"

#define MENU_NOT_REF 0
#define MNEU_FROM_SEARCH 1
#define MNEU_SINGLE_FROM_COMBO 2
#define MNEU_MULTI_FROM_COMBO 3
#define MNEU_SINGLE_FILTER_COMBO 4
#define MNEU_MULTI_FILTER_COMBO  5

class SmartGridColumn
{
private:
	QString columnNameEng;
	QString columnNameChn;
	QVariant::Type dataType;
	int		smartSysDataType;
	bool isQueryField;
	bool isKey;
	int	 referenceFlag;
	bool notNull;
	int  columnOrder;
	int dataLength;
	QString menuName;
	QString refTable;
	QString tableName;
	QString refValueColumn;
	QString refDisplayColumn;
	QString filter;
	QVariantMap menuList;
public:
	SmartGridColumn();

	SmartGridColumn(const QString &columnNameEng);

	SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn);

	SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const QVariant::Type &dataType);

	SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const bool &isKey, const QVariant::Type &dataType);

	SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const QVariant::Type &dataType, const bool &isQueryField);

	SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const bool &isKey, const QVariant::Type &dataType, const bool &isQueryField);

	SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const bool &isKey, const QVariant::Type &dataType, const QString &refTable, const QString &refValueColumn, const QString &refDisplayColumn);

	~SmartGridColumn();
	void setTableName(const QString &value);
	QString getTableName() const;

	void setColumnNameEng(const QString &value);
	QString getColumnNameEng() const;

	void setColumnNameChn(const QString &value);
	QString getColumnNameChn() const;

	void setColumnOrder(const int &value);
	QString getColumnOrder() const;

	void setDataLength(const int &value);
	int getDataLength() const;

	void setColumnDataType(const QVariant::Type &value);
	QVariant::Type getColumnDataType() const;
	QVariant::Type int2VariantType(const int &typeId);

	int getSysDataType()const;
	void setSysDataType(int value) ;

	void setIsQueryField(const bool &value);
	bool getIsQueryField() const;

	void setIsKey(const bool &value);
	bool getIsKey() const;

	void setNotNull(const bool &value);
	bool isNotNull() const;

	int getReferenceFlag() const ;
	void setReferenceFlag(const int &referenceFlag);

	void setRefTable(const QString &value);
	QString getRefTable() const;
	void setRefValueColumnName(const QString &value);

	QString getRefValueColumnName() const;
	void setRefDisplayColumnName(const QString &value);

	QString getRefDisplayColumnName() const;

	void setMenuName(const QString &menuName);
	QString getMenuName() const;

	void setFilter(const QString &filter);
	QString getFilter() const;

	SmartGridColumn &operator = (const SmartGridColumn &par);
};

#endif // _SMART_GRID_COLUMN_H
