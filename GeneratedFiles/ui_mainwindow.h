/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qqwsmainwindow.h>

QT_BEGIN_NAMESPACE

class Ui_GisWidgetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QQWSMainWindow *GisWidgetClass)
    {
        if (GisWidgetClass->objectName().isEmpty())
            GisWidgetClass->setObjectName(QStringLiteral("GisWidgetClass"));
        GisWidgetClass->resize(600, 400);
        menuBar = new QMenuBar(GisWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        mainToolBar = new QToolBar(GisWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        centralWidget = new QWidget(GisWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        statusBar = new QStatusBar(GisWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));

        retranslateUi(GisWidgetClass);

        QMetaObject::connectSlotsByName(GisWidgetClass);
    } // setupUi

    void retranslateUi(QQWSMainWindow *GisWidgetClass)
    {
        GisWidgetClass->setWindowTitle(QApplication::translate("GisWidgetClass", "GisWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class GisWidgetClass: public Ui_GisWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
