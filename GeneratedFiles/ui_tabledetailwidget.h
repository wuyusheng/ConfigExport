/********************************************************************************
** Form generated from reading UI file 'tabledetailwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEDETAILWIDGET_H
#define UI_TABLEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabledetailwidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *configTableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *pointTypeCombox;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QPushButton *btnExport;
    QPushButton *btnCommitChanges;
    QPushButton *btnRollback;
    QTableView *pointTableView;

    void setupUi(QWidget *tabledetailwidget)
    {
        if (tabledetailwidget->objectName().isEmpty())
            tabledetailwidget->setObjectName(QStringLiteral("tabledetailwidget"));
        tabledetailwidget->resize(934, 638);
        verticalLayout = new QVBoxLayout(tabledetailwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(tabledetailwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        configTableView = new QTableView(tab);
        configTableView->setObjectName(QStringLiteral("configTableView"));

        verticalLayout_2->addWidget(configTableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        pointTypeCombox = new QComboBox(tab_2);
        pointTypeCombox->setObjectName(QStringLiteral("pointTypeCombox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pointTypeCombox->sizePolicy().hasHeightForWidth());
        pointTypeCombox->setSizePolicy(sizePolicy);
        pointTypeCombox->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pointTypeCombox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAdd = new QPushButton(tab_2);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);

        horizontalLayout->addWidget(btnAdd);

        btnDelete = new QPushButton(tab_2);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelete->setIcon(icon1);

        horizontalLayout->addWidget(btnDelete);

        btnExport = new QPushButton(tab_2);
        btnExport->setObjectName(QStringLiteral("btnExport"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExport->setIcon(icon2);

        horizontalLayout->addWidget(btnExport);

        btnCommitChanges = new QPushButton(tab_2);
        btnCommitChanges->setObjectName(QStringLiteral("btnCommitChanges"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCommitChanges->setIcon(icon3);

        horizontalLayout->addWidget(btnCommitChanges);

        btnRollback = new QPushButton(tab_2);
        btnRollback->setObjectName(QStringLiteral("btnRollback"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRollback->setIcon(icon4);

        horizontalLayout->addWidget(btnRollback);


        verticalLayout_3->addLayout(horizontalLayout);

        pointTableView = new QTableView(tab_2);
        pointTableView->setObjectName(QStringLiteral("pointTableView"));

        verticalLayout_3->addWidget(pointTableView);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(tabledetailwidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(tabledetailwidget);
    } // setupUi

    void retranslateUi(QWidget *tabledetailwidget)
    {
        tabledetailwidget->setWindowTitle(QApplication::translate("tabledetailwidget", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("tabledetailwidget", "\345\217\202\346\225\260\351\205\215\347\275\256", 0));
        label->setText(QApplication::translate("tabledetailwidget", "\347\261\273\345\236\213\350\277\207\346\273\244\357\274\232", 0));
        btnAdd->setText(QApplication::translate("tabledetailwidget", "\346\226\260\345\242\236", 0));
        btnDelete->setText(QApplication::translate("tabledetailwidget", "\345\210\240\351\231\244", 0));
        btnExport->setText(QApplication::translate("tabledetailwidget", "\345\257\274\345\207\272", 0));
        btnCommitChanges->setText(QApplication::translate("tabledetailwidget", "\344\277\235\345\255\230", 0));
        btnRollback->setText(QApplication::translate("tabledetailwidget", "\345\233\236\346\273\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("tabledetailwidget", "\347\202\271\350\241\250\346\225\260\346\215\256\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class tabledetailwidget: public Ui_tabledetailwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEDETAILWIDGET_H
