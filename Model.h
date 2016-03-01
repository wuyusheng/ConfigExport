#ifndef __SF_MODEL_H__
#define __SF_MODEL_H__


//Qt lib
#include <QAbstractTableModel>
#include <QSqlTableModel>


class QWSTableModel : public QSqlTableModel
{
	Q_OBJECT

public:
							QWSTableModel(QObject* parent = 0);
							~QWSTableModel();


};



#endif // __SF_MODEL_H__
