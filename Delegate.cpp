
#include "delegate.h"

#include <QSpinBox>

QWSTableDelegate::QWSTableDelegate(QObject *parent)
: QStyledItemDelegate(parent)
{
}

QWidget* QWSTableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem & option , const QModelIndex & index ) const
{
	QSpinBox *editor = new QSpinBox(parent);
	editor->setFrame(false);
	editor->setMinimum(0);
	editor->setMaximum(100);

	return editor;
}

void QWSTableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	int value = index.model()->data(index, Qt::EditRole).toInt();

	QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
	spinBox->setValue(value);
}

void QWSTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
	spinBox->interpretText();
	int value = spinBox->value();

	model->setData(index, value, Qt::EditRole);
}

void QWSTableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
	editor->setGeometry(option.rect);
}
