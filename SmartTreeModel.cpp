//#include "elog.h"
//#include "locale_utils.h"
#include "SmartTreeModel.h"
#include "util.h"

SmartTreeModel::SmartTreeModel(QObject *parent)
: QAbstractItemModel(parent)
{
	this->rootItem = NULL;
	//createDemoData();
}

SmartTreeModel::~SmartTreeModel()
{
	delete this->rootItem;
}

void SmartTreeModel::createDemoData()
{
	this->clearData();
	this->columnList.clear();
	this->columnList.append(SmartGridColumn("id"));
	this->columnList.append(SmartGridColumn("pid"));
	this->columnList.append(SmartGridColumn("text"));
	this->idField = "id";
	this->pidField = "pid";
	this->setIdField(0);
	this->setTextField(2);

	this->rootItem = new SmartTreeItem();
	for (int i = 0; i < 10; i++)
	{
		QVariantMap row;
		row.insert(this->idField, (i + 1));
		row.insert("pid", 0);
		row.insert("text", QString("%1-分类").arg(i + 1));
		// 主结点下挂两个子节点
		SmartTreeItem *primary = new SmartTreeItem(row, this->rootItem);
		this->rootItem->appendChild(primary);

		for (int j = 0; j < 2; j++)
		{
			QMap<QString, QVariant> subRow;
			subRow.insert(this->idField, (j + 1));
			subRow.insert("pid", i + 1);
			subRow.insert("text", QString("%1-设备").arg(j + 1));
			primary->appendChild(new SmartTreeItem(subRow, primary));
		}
	}

}
void SmartTreeModel::clearData()
{
	beginRemoveRows(QModelIndex(), 0, this->rowCount());
	if (this->rootItem)
	{
		delete this->rootItem;
		this->rootItem = NULL;
	}
	this->nodeList.clear();
	endRemoveRows();
}

QVariant SmartTreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
 	if (index.column()>(this->columnList.size()-1))
 	{
 		return QVariant();
 	}
	SmartTreeItem *item = static_cast<SmartTreeItem*>(index.internalPointer());
	if (role == Qt::DecorationRole)
	{
		QString iconName = item->data(this->iconField).toString();
		if (iconName.isEmpty())
		{
			return QIcon(":/images/node.png");
		}
		else
		{
			if (iconName.startsWith(":/"))
			{
				return QIcon(iconName);
			}
			else
			{
				return QIcon(CSysUtil::getIconFullName(iconName));
			}
		}
	}
	if (role == Qt::DisplayRole)
	{
		if (!m_isTreeGrid && index.column()==0)
		{
			return item->data(textField);
		}
	}
	if (role == Qt::EditRole)
	{
		return item->data(this->columnList.at(index.column()).getColumnNameEng());
	}
	return QVariant();
}

Qt::ItemFlags SmartTreeModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;
	if (m_readOnly)
	{
		return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	}
	else
	{
		return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
	}
}

void SmartTreeModel::setHeaderIcon(int columnIndex, const QString &iconName)
{
	if (headerIconMap.contains(columnIndex))
	{
		headerIconMap[columnIndex] = iconName;
	}
	else
	{
		headerIconMap.insert(columnIndex, iconName);
	}
}

QVariant SmartTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (section < this->columnList.size())
	{
		
		if (orientation == Qt::Horizontal)
		{
			if (role == Qt::DisplayRole)
			{
				return this->columnList.at(section).getColumnNameChn();
			}
			if (role == Qt::DecorationRole &&headerIconMap.contains(section))
			{
				QString iconName = headerIconMap.value(section);
				if (iconName.startsWith(":/"))
				{
					return QIcon(iconName);
				}
				else
				{
					return QIcon(CSysUtil::getIconFullName(iconName));
				}
			}
		}
	}
	return QVariant();
}

QModelIndex SmartTreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	SmartTreeItem *parentItem;
	if (!parent.isValid())
	{
		parentItem = this->rootItem;
	}
	else
	{
		parentItem = static_cast<SmartTreeItem*>(parent.internalPointer());
	}

	SmartTreeItem *childItem = parentItem->child(row);
	if (childItem)
		return createIndex(row, column, childItem);
	else
		return QModelIndex();
}

QModelIndex SmartTreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	SmartTreeItem *childItem = static_cast<SmartTreeItem*>(index.internalPointer());
	SmartTreeItem *parentItem = childItem->parent();

	if (parentItem == this->rootItem)
		return QModelIndex();

	return createIndex(parentItem->row(), 0, parentItem);
}

int SmartTreeModel::rowCount(const QModelIndex &parent) const
{
	if (!this->rootItem)
	{
		return 0;
	}
	SmartTreeItem *parentItem;

	if (!parent.isValid())
		parentItem = this->rootItem;
	else
		parentItem = static_cast<SmartTreeItem*>(parent.internalPointer());
	//printf("sub node count:%d.\n", parentItem->childCount());
	return parentItem->childCount();
}

int SmartTreeModel::columnCount(const QModelIndex &parent) const
{
	if (this->rootItem)
	{
		if (m_isTreeGrid)
		{
			return columnList.size();
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

void SmartTreeModel::createTree(SmartTreeItem *topItem, const QList<QVariantMap> &itemList, int &totalItems)
{
	if (totalItems == itemList.size()) return;
	for (int i = 0; i < itemList.size(); i++)
	{
		//find for children
		if (itemList.at(i).value(this->pidField) == topItem->data(this->idField))
		{
			SmartTreeItem *childItem = new SmartTreeItem(itemList.at(i), topItem);
			topItem->appendChild(childItem);
			totalItems++;
		}
	}
	//
	for (int childIdx = 0; childIdx < topItem->childCount(); childIdx++)
	{
		this->createTree(topItem->child(childIdx), itemList, totalItems);
	}
	return;
}

void SmartTreeModel::setDataSet(const QList<QVariantMap> &itemList)
{
	this->clearData();
	if (itemList.isEmpty())
	{
		return;
	}
	this->beginInsertRows(QModelIndex(), 0, itemList.size()-1);
	if (this->idField.isEmpty() || this->pidField.isEmpty())
	{
		//log_error("Tree data must set id,pid field,otherwise hirecy data can not be extract from dataset.");
		return;
	}
	this->rootItem = new SmartTreeItem();
	int totalItems = 0;
	this->createTree(rootItem, itemList, totalItems);
	this->endInsertRows();
}

void SmartTreeModel::setDataSet(const QString &itemList)
{
	QJsonArray arr = QJsonDocument::fromJson(itemList.toUtf8()).array();
	QList<QVariantMap> items;
	for (int i = 0; i < arr.size();i++)
	{
		items.append(arr.at(i).toObject().toVariantMap());
	}

}

int SmartTreeModel::loadSub(const QModelIndex &index, const QList<QVariantMap> &itemList)
{
	SmartTreeItem *item = static_cast<SmartTreeItem*>(index.internalPointer());
	item->clear();
	int totalItems = 0;
	this->beginInsertRows(index, 0, itemList.size() - 1);
	createTree(item, itemList, totalItems);
	endInsertRows();
	/*if (!item)
	{
	log_error("Model index is empty,item is null.");
	return -1;
	}
	for (int i = 0; i < itemList.size();i++)
	{
	SmartTreeItem *childItem = new SmartTreeItem(itemList.at(i), item);
	item->appendChild(childItem);
	}*/
	return 0;
}

void SmartTreeModel::setColumnList(const QList<SmartGridColumn> &columns)
{
	this->columnList = columns;
}


void SmartTreeModel::setItemValue(const QModelIndex &index, const QVariantMap &itemData)
{
	if (itemData.isEmpty())
	{
		return;
	}
	//QStringList keys = itemData.keys();
	SmartTreeItem *item = static_cast<SmartTreeItem *>(index.internalPointer());
	item->setData(itemData);
}

QString SmartTreeModel::getColumnNames() const
{
	QString columNames;
	for (int i = 0; i < this->columnList.size(); i++)
	{
		columNames.append(this->columnList.at(i).getColumnNameEng());
		if (i < (this->columnList.size() - 1))
		{
			columNames.append(",");
		}
	}
	
	return columNames;
}

void SmartTreeModel::getSelectedItem(const QModelIndex &index, QVariantMap &item)
{
	if (!index.isValid())
	{
		return;
	}
	if (index.row() < this->rowCount() && index.column() < this->columnCount())
	{

		SmartTreeItem *itemPtr = static_cast<SmartTreeItem*>(index.internalPointer());
		item = itemPtr->node();
		return;
	}
}

void SmartTreeModel::appenChild(const QModelIndex &index,const QVariantMap &node)
{
	SmartTreeItem *parentItem = static_cast<SmartTreeItem*>(index.internalPointer());
	SmartTreeItem *item = new SmartTreeItem(node, parentItem);
	beginInsertRows(index, parentItem->childCount(), parentItem->childCount() + 1);
	parentItem->appendChild(item);
	endInsertRows();
}

void SmartTreeModel::removeMe(const QModelIndex &index)
{
	SmartTreeItem *parentItem = static_cast<SmartTreeItem*>(index.parent().internalPointer());
	if (!parentItem)
	{
		return;
	}
	int row = index.row();
	if (row<parentItem->childCount())
	{
		beginRemoveRows(index.parent(), row, row);
		parentItem->removeAt(row);
		endRemoveRows();
	}
}


void SmartTreeModel::removeMyChild(const QModelIndex &index)
{
	SmartTreeItem *parentItem = static_cast<SmartTreeItem*>(index.internalPointer());
	if (!parentItem)
	{
		return;
	}
	beginRemoveRows(index, 0, parentItem->childCount());
	parentItem->clear();
	endRemoveRows();
}