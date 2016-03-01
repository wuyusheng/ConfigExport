#include "SmartGridColumn.h"

SmartGridColumn::SmartGridColumn()
{

}
SmartGridColumn::SmartGridColumn(const QString &columnNameEng){
	this->columnNameEng = columnNameEng;
	this->columnNameChn = columnNameEng;
	this->dataType = QVariant::Type::String;
}
SmartGridColumn::SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn){
	this->columnNameEng = columnNameEng;
	this->columnNameChn = columnNameChn;
	this->dataType = QVariant::Type::String;
}

SmartGridColumn::SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const QVariant::Type &dataType){
	this->columnNameEng = columnNameEng;
	this->columnNameChn = columnNameChn;
	this->dataType = dataType;
}

SmartGridColumn::SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const bool &isKey, const QVariant::Type &dataType){
	this->columnNameEng = columnNameEng;
	this->columnNameChn = columnNameChn;
	this->isKey = isKey;
	this->dataType = dataType;
}

SmartGridColumn::SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const QVariant::Type &dataType, const bool &isQueryField){
	this->columnNameEng = columnNameEng;
	this->columnNameChn = columnNameChn;
	this->dataType = dataType;
	this->isQueryField = isQueryField;
}

SmartGridColumn::SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const bool &isKey, const QVariant::Type &dataType, const bool &isQueryField){
	this->columnNameEng = columnNameEng;
	this->columnNameChn = columnNameChn;
	this->isKey = isKey;
	this->dataType = dataType;
	this->isQueryField = isQueryField;
}

SmartGridColumn::SmartGridColumn(const QString &columnNameEng, const QString &columnNameChn, const bool &isKey, const QVariant::Type &dataType, const QString &refTable, const QString &refValueColumn, const QString &refDisplayColumn)
{
	this->columnNameEng = columnNameEng;
	this->columnNameChn = columnNameChn;
	this->isKey = isKey;
	this->dataType = dataType;
	this->refTable = refTable;
	this->refValueColumn = refValueColumn;
	this->refDisplayColumn = refDisplayColumn;
}

SmartGridColumn::~SmartGridColumn()
{

}

void SmartGridColumn::setTableName(const QString &value)
{
	this->tableName = value;
}

QString SmartGridColumn::getTableName() const
{
	return  this->tableName;
}

//设置列英文名
void SmartGridColumn::setColumnNameEng(const QString &value)
{
	this->columnNameEng = value;
}
QString SmartGridColumn::getColumnNameEng() const
{
	return this->columnNameEng;
}
//列中文名
void SmartGridColumn::setColumnNameChn(const QString &value)
{
	this->columnNameChn = value;
}
QString SmartGridColumn::getColumnNameChn() const
{
	return this->columnNameChn;
}

//列序号
void SmartGridColumn::setColumnOrder(const int &value)
{
	this->columnOrder = value;
}
QString SmartGridColumn::getColumnOrder() const
{
	return this->columnOrder;
}


void SmartGridColumn::setDataLength(const int &value)
{
	dataLength = value;
}
int SmartGridColumn::getDataLength() const
{
	return dataLength;
}


//数据类型
void SmartGridColumn::setColumnDataType(const QVariant::Type &value)
{
	this->dataType = value;
}

QVariant::Type SmartGridColumn::int2VariantType(const int &typeId)
{
	switch (typeId)
	{
	case DATA_TYPE_STRING:
		return QVariant::Type::String;
		break;
	case DATA_TYPE_INT_32:
		return QVariant::Type::Int;
		break;

	case DATA_TYPE_INT_64:
	case DATA_TYPE_DATETIME:
		return QVariant::Type::DateTime;
		break;
	case DATA_TYPE_BINARY:
		return QVariant::Type::Bool;
		break;
	case DATA_TYPE_FLOAT:
	case DATA_TYPE_DOUBLE:
		return QVariant::Type::Double;
		break;
	default:
		break;
	}
	return QVariant::Type::String;
}

void SmartGridColumn::setSysDataType(int value)
{
	smartSysDataType = value;
}

int SmartGridColumn::getSysDataType() const
{
	return smartSysDataType;
}

QVariant::Type SmartGridColumn::getColumnDataType() const 
{ 
	return this->dataType; 
}
//是否查询条件
void SmartGridColumn::setIsQueryField(const bool &value){
	this->isQueryField = value;
}

bool SmartGridColumn::getIsQueryField() const 
{ 
	return this->isQueryField; 
}
//是否主键
void SmartGridColumn::setIsKey(const bool &value)
{
	this->isKey = value;
}
bool SmartGridColumn::getIsKey() const 
{ 
	return this->isKey;
}

void SmartGridColumn::setNotNull(const bool &value)
{
	this->notNull = value;
}

bool SmartGridColumn::isNotNull() const
{
	return this->notNull;
}

//引用标记
int SmartGridColumn::getReferenceFlag() const
{ 
	return referenceFlag;
};
void SmartGridColumn::setReferenceFlag(const int &referenceFlag) 
{ 
	this->referenceFlag = referenceFlag;
};

//引用表名
void SmartGridColumn::setRefTable(const QString &value)
{
	this->refTable = value;
}
QString SmartGridColumn::getRefTable() const
{ 
	return this->refTable; 
}
//引用值列名
void SmartGridColumn::setRefValueColumnName(const QString &value)
{
	this->refValueColumn = value;
}
QString SmartGridColumn::getRefValueColumnName() const 
{ 
	return this->refValueColumn; 
}
//引用显示值列名
void SmartGridColumn::setRefDisplayColumnName(const QString &value)
{
	this->refDisplayColumn = value;
}
QString SmartGridColumn::getRefDisplayColumnName() const { return this->refDisplayColumn; }

//菜单名
void SmartGridColumn::setMenuName(const QString &menuName)
{
	this->menuName = menuName;
}
QString SmartGridColumn::getMenuName() const
{ 
	return this->menuName; 
}

//菜单名
void SmartGridColumn::setFilter(const QString &filter)
{
	this->filter = filter;
}
QString SmartGridColumn::getFilter() const
{ 
	return this->filter; 
}

SmartGridColumn & SmartGridColumn::operator = (const SmartGridColumn &par)
{
	if (this == &par)
	{
		return *this;
	}
	columnNameEng = par.columnNameEng;
	columnNameChn = par.columnNameChn;
	dataType = par.dataType;
	isKey = par.isKey;
	refTable = par.refTable;
	referenceFlag = par.referenceFlag;
	refValueColumn = par.refValueColumn;
	refDisplayColumn = par.refDisplayColumn;
	menuName = par.menuName;
	isQueryField = par.isQueryField;
	return *this;
}
