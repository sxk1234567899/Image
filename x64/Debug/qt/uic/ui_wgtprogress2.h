/********************************************************************************
** Form generated from reading UI file 'wgtprogress2.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTPROGRESS2_H
#define UI_WGTPROGRESS2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtProgress2Class
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QTableWidget *tableWidget;

    void setupUi(QWidget *WgtProgress2Class)
    {
        if (WgtProgress2Class->objectName().isEmpty())
            WgtProgress2Class->setObjectName("WgtProgress2Class");
        WgtProgress2Class->resize(761, 550);
        gridLayout = new QGridLayout(WgtProgress2Class);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(WgtProgress2Class);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(250, 0));
        textBrowser->setMaximumSize(QSize(250, 16777215));
        textBrowser->setOpenLinks(true);

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        tableWidget = new QTableWidget(WgtProgress2Class);
        tableWidget->setObjectName("tableWidget");

        gridLayout->addWidget(tableWidget, 0, 1, 1, 1);


        retranslateUi(WgtProgress2Class);

        QMetaObject::connectSlotsByName(WgtProgress2Class);
    } // setupUi

    void retranslateUi(QWidget *WgtProgress2Class)
    {
        WgtProgress2Class->setWindowTitle(QCoreApplication::translate("WgtProgress2Class", "WgtProgress2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtProgress2Class: public Ui_WgtProgress2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTPROGRESS2_H
