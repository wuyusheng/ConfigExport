/********************************************************************************
** Form generated from reading UI file 'exportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIALOG_H
#define UI_EXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exportDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkSelectAll;
    QGridLayout *gridLayout;
    QCheckBox *checkPort;
    QCheckBox *checkYK;
    QCheckBox *checkZFYM;
    QCheckBox *checkDevice;
    QCheckBox *checkYM;
    QCheckBox *checkIP;
    QCheckBox *checkModbus;
    QCheckBox *checkDDYC;
    QCheckBox *checkDZ;
    QCheckBox *checkYC;
    QCheckBox *checkDDYX;
    QCheckBox *checkProtocol;
    QCheckBox *checkYX;
    QCheckBox *checkZFYK;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditExportPath;
    QPushButton *btnSelect;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *exportDialog)
    {
        if (exportDialog->objectName().isEmpty())
            exportDialog->setObjectName(QStringLiteral("exportDialog"));
        exportDialog->resize(472, 298);
        verticalLayout_2 = new QVBoxLayout(exportDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(exportDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        checkSelectAll = new QCheckBox(groupBox);
        checkSelectAll->setObjectName(QStringLiteral("checkSelectAll"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        checkSelectAll->setFont(font);
        checkSelectAll->setChecked(true);

        horizontalLayout_2->addWidget(checkSelectAll);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkPort = new QCheckBox(groupBox);
        checkPort->setObjectName(QStringLiteral("checkPort"));
        checkPort->setChecked(true);

        gridLayout->addWidget(checkPort, 0, 0, 1, 1);

        checkYK = new QCheckBox(groupBox);
        checkYK->setObjectName(QStringLiteral("checkYK"));
        checkYK->setChecked(true);

        gridLayout->addWidget(checkYK, 0, 1, 1, 1);

        checkZFYM = new QCheckBox(groupBox);
        checkZFYM->setObjectName(QStringLiteral("checkZFYM"));
        checkZFYM->setChecked(true);

        gridLayout->addWidget(checkZFYM, 0, 2, 1, 1);

        checkDevice = new QCheckBox(groupBox);
        checkDevice->setObjectName(QStringLiteral("checkDevice"));
        checkDevice->setChecked(true);

        gridLayout->addWidget(checkDevice, 1, 0, 1, 1);

        checkYM = new QCheckBox(groupBox);
        checkYM->setObjectName(QStringLiteral("checkYM"));
        checkYM->setChecked(true);

        gridLayout->addWidget(checkYM, 1, 1, 1, 1);

        checkIP = new QCheckBox(groupBox);
        checkIP->setObjectName(QStringLiteral("checkIP"));
        checkIP->setChecked(true);

        gridLayout->addWidget(checkIP, 1, 2, 1, 1);

        checkModbus = new QCheckBox(groupBox);
        checkModbus->setObjectName(QStringLiteral("checkModbus"));
        checkModbus->setChecked(true);

        gridLayout->addWidget(checkModbus, 2, 0, 1, 1);

        checkDDYC = new QCheckBox(groupBox);
        checkDDYC->setObjectName(QStringLiteral("checkDDYC"));
        checkDDYC->setChecked(true);

        gridLayout->addWidget(checkDDYC, 2, 1, 1, 1);

        checkDZ = new QCheckBox(groupBox);
        checkDZ->setObjectName(QStringLiteral("checkDZ"));
        checkDZ->setChecked(true);

        gridLayout->addWidget(checkDZ, 2, 2, 1, 1);

        checkYC = new QCheckBox(groupBox);
        checkYC->setObjectName(QStringLiteral("checkYC"));
        checkYC->setChecked(true);

        gridLayout->addWidget(checkYC, 3, 0, 1, 1);

        checkDDYX = new QCheckBox(groupBox);
        checkDDYX->setObjectName(QStringLiteral("checkDDYX"));
        checkDDYX->setChecked(true);

        gridLayout->addWidget(checkDDYX, 3, 1, 1, 1);

        checkProtocol = new QCheckBox(groupBox);
        checkProtocol->setObjectName(QStringLiteral("checkProtocol"));
        checkProtocol->setChecked(true);

        gridLayout->addWidget(checkProtocol, 3, 2, 1, 1);

        checkYX = new QCheckBox(groupBox);
        checkYX->setObjectName(QStringLiteral("checkYX"));
        checkYX->setChecked(true);

        gridLayout->addWidget(checkYX, 4, 0, 1, 1);

        checkZFYK = new QCheckBox(groupBox);
        checkZFYK->setObjectName(QStringLiteral("checkZFYK"));
        checkZFYK->setChecked(true);

        gridLayout->addWidget(checkZFYK, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(exportDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditExportPath = new QLineEdit(exportDialog);
        lineEditExportPath->setObjectName(QStringLiteral("lineEditExportPath"));

        horizontalLayout->addWidget(lineEditExportPath);

        btnSelect = new QPushButton(exportDialog);
        btnSelect->setObjectName(QStringLiteral("btnSelect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSelect->setIcon(icon);

        horizontalLayout->addWidget(btnSelect);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(exportDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(exportDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), exportDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), exportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(exportDialog);
    } // setupUi

    void retranslateUi(QWidget *exportDialog)
    {
        exportDialog->setWindowTitle(QApplication::translate("exportDialog", "\345\257\274\345\207\272\351\205\215\347\275\256\346\226\207\344\273\266", 0));
        groupBox->setTitle(QApplication::translate("exportDialog", "\345\257\274\345\207\272\351\205\215\347\275\256\347\261\273\345\236\213", 0));
        checkSelectAll->setText(QApplication::translate("exportDialog", "\345\205\250\351\200\211", 0));
        checkPort->setText(QApplication::translate("exportDialog", "\347\253\257\345\217\243\350\241\250", 0));
        checkYK->setText(QApplication::translate("exportDialog", "\351\201\245\346\216\247\350\241\250", 0));
        checkZFYM->setText(QApplication::translate("exportDialog", "\350\275\254\345\217\221\351\201\245\350\204\211\350\241\250", 0));
        checkDevice->setText(QApplication::translate("exportDialog", "\350\256\276\345\244\207\350\241\250", 0));
        checkYM->setText(QApplication::translate("exportDialog", "\351\201\245\350\204\211\350\241\250", 0));
        checkIP->setText(QApplication::translate("exportDialog", "IP\351\205\215\347\275\256\346\226\207\344\273\266", 0));
        checkModbus->setText(QApplication::translate("exportDialog", "ModBus\350\241\250", 0));
        checkDDYC->setText(QApplication::translate("exportDialog", "\350\260\203\345\272\246\351\201\245\346\265\213\350\241\250", 0));
        checkDZ->setText(QApplication::translate("exportDialog", "\345\256\232\345\200\274\350\241\250", 0));
        checkYC->setText(QApplication::translate("exportDialog", "\351\201\245\346\265\213\350\241\250", 0));
        checkDDYX->setText(QApplication::translate("exportDialog", "\350\260\203\345\272\246\351\201\245\344\277\241\350\241\250", 0));
        checkProtocol->setText(QApplication::translate("exportDialog", "\345\215\217\350\256\256\350\241\250", 0));
        checkYX->setText(QApplication::translate("exportDialog", "\351\201\245\344\277\241\350\241\250", 0));
        checkZFYK->setText(QApplication::translate("exportDialog", "\350\275\254\345\217\221\351\201\245\346\216\247\350\241\250", 0));
        label->setText(QApplication::translate("exportDialog", "\351\205\215\347\275\256\346\226\207\344\273\266\344\275\215\347\275\256\357\274\232", 0));
        btnSelect->setText(QApplication::translate("exportDialog", "\351\200\211\346\213\251", 0));
    } // retranslateUi

};

namespace Ui {
    class exportDialog: public Ui_exportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIALOG_H
