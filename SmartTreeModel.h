#ifndef _TREE_MODEL_H
#define _TREE_MODEL_H

#include <QIcon>
#include <QVariantMap>
#include <QDateTime>
#include <QAbstractItemModel>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "smartgridcolumn.h"

#define DEFAULT_ID_FIELD "id"
#define DEFAULT_PID_FIELD "pid"
#define DEFAULT_TEXT_FIELD "text"
#define DEFAULT_ICON_FIELD "icon"
#define DEFAULT_TYPE_FIELD "type"

class SmartTreeItem
{
public:
	SmartTreeItem(SmartTreeItem *parent=NULL)
	{
		parentItem = parent;
		this->level = 0;
	}

	SmartTreeItem(const QVariantMap &data, SmartTreeItem *parent)
	{
		itemData = data;
		parentItem = parent;
		this->level = parent->level + 1;
	}

	~SmartTreeItem()
	{
		qDeleteAll(childItems);
	}

	void appendChild(SmartTreeItem *item)
	{
		childItems.append(item);
	}

	SmartTreeItem *child(int row)
	{
		return childItems.value(row);
	}

	int childCount() const
	{
		return childItems.count();
	}

	int columnCount() const
	{
		return itemData.count();
	}

	QVariant data(const QString &column) const
	{
		if (column.isEmpty())
		{
			return QVariant();
		}
		if (!itemData.contains(column))
		{
			return QVariant();
		}
		return itemData.value(column);
	}

	void setData(const QString &column, const QVariant &value)
	{
		if (!this->itemData.contains(column))
		{
			return;
		}
		//log_debug("Ready to update column:%s.", column.toStdString().c_str());
		if (this->itemData.value(column) != value)
		{
			this->changed = true;
		}
		switch (value.type())
		{
		case QVariant::Type::Int:
			this->itemData.insert(column, value.toInt());
			break;
		case QVariant::Type::Double:
			this->itemData.insert(column, value.toDouble());
			break;
		case QVariant::Type::String:
			this->itemData.insert(column, value.toString());
			break;
		case QVariant::Type::DateTime:
			this->itemData.insert(column, value.toDateTime());
			break;
		default:
			break;
		}
	}

	void setData(const QVariantMap &itemData)
	{
		this->itemData = itemData;
	}

	int row() const
	{
		if (parentItem)
		{
			return parentItem->childItems.indexOf(const_cast<SmartTreeItem*>(this));
		}

		return 0;
	}


	SmartTreeItem *parent()
	{
		return parentItem;
	}
	bool isChanged()
	{ 
		return this->changed; 
	}
	void resetFlag()
	{ 
		this->changed = false; 
	}
	void clear()
	{
		if (!childItems.isEmpty())
		{
			//deleteAll();
			childItems.clear();
		}
	}

	void removeAt(int row)
	{
		if (row<childItems.size())
		{
			childItems.removeAt(row);
		}
	}
	QVariantMap node(){ return this->itemData; }

	int getLevel(){ return this->level; }

private:
	int level=-1;
	SmartTreeItem *parentItem;
	QList<SmartTreeItem*> childItems;
	QVariantMap itemData;
	bool changed = false;
};

class SmartTreeModel : public QAbstractItemModel
{
public:
	SmartTreeModel(QObject *parent = NULL);
	~SmartTreeModel();
	
	QVariant data(const QModelIndex &index, int role) const;
	
	Qt::ItemFlags flags(const QModelIndex &index) const;
	
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	
	QModelIndex parent(const QModelIndex &index) const;
	
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	
	void createDemoData();
	
	void clearData();
	
	void setDataSet(const QList<QVariantMap> &itemList);
	
	void setDataSet(const QString &itemList);
	
	void appendColumn(const SmartGridColumn &column){ this->columnList.append(column); }
 	
	void clearColumn(){ this->columnList.clear(); }
 	
	void setColumnList(const QList<SmartGridColumn> &columns);
 	
	QList<SmartGridColumn> getColumns() const{ return this->columnList; }
 	
	QString columnNameEng(const int &columnIndex) const
	{
		if (columnIndex < this->columnList.size())
		{
			return this->columnList.at(columnIndex).getColumnNameEng();
		}
		return QString();
	}
	void setItemValue(const QModelIndex &index, const QVariantMap &itemData);

	QString getColumnNames() const;

	void setIdField(const QString &idField){ this->idField = idField; }

	void setPidField(const QString &pidField){ this->pidField = pidField; }

	void setTextField(const QString &textField){ this->textField = textField; }

	void setIconField(const QString &iconField){ this->iconField = iconField; }

	QString getIdField(){ return this->idField; }

	QString getPidField(){ return this->pidField; }

	QString getTextField(){ return this->textField; }

	QString getIconField(){ return this->iconField; }

	void setIdField(const int &colIndex){ this->idField = this->columnList.at(colIndex).getColumnNameEng(); }

	void setPidField(const int &colIndex){ this->pidField = this->columnList.at(colIndex).getColumnNameEng(); }

	void setTextField(const int &colIndex){ this->textField = this->columnList.at(colIndex).getColumnNameEng(); }

	void setIconField(const int &colIndex){ this->iconField = this->columnList.at(colIndex).getColumnNameEng(); }
	
	void getSelectedItem(const QModelIndex &index, QVariantMap &item);

	void enableEdit(){ m_readOnly = false; }

	void showAsTreeGrid(){ m_isTreeGrid = true; }

	void setHeaderIcon(int columnIndex, const QString &iconName);

	void appenChild(const QModelIndex &index, const QVariantMap &node);

	void removeMe(const QModelIndex &index);

	void removeMyChild(const QModelIndex &index);

public slots:
	int loadSub(const QModelIndex &index, const QList<QVariantMap> &itemList);

	void createTree(SmartTreeItem *topItem, const QList<QVariantMap> &itemList, int &totalItems);
private:
	bool					m_readOnly = true;
	bool					m_isTreeGrid = false;
	QList<QVariantMap> nodeList;
	
	QMap<int, QString> headerIconMap;

	SmartTreeItem *rootItem;
	
	QString idField;
	
	QString pidField;
	
	QString iconField;
	
	QString textField = "description";
	
	QList<SmartGridColumn> columnList;
};

#endif // _TREE_MODEL_H
