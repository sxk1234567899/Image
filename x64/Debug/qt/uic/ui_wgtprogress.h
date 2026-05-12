/********************************************************************************
** Form generated from reading UI file 'wgtprogress.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTPROGRESS_H
#define UI_WGTPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtProgressClass
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *WgtProgressClass)
    {
        if (WgtProgressClass->objectName().isEmpty())
            WgtProgressClass->setObjectName("WgtProgressClass");
        WgtProgressClass->resize(1170, 635);
        gridLayout = new QGridLayout(WgtProgressClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(WgtProgressClass);
        stackedWidget->setObjectName("stackedWidget");

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(WgtProgressClass);

        QMetaObject::connectSlotsByName(WgtProgressClass);
    } // setupUi

    void retranslateUi(QWidget *WgtProgressClass)
    {
        WgtProgressClass->setWindowTitle(QCoreApplication::translate("WgtProgressClass", "WgtProgress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtProgressClass: public Ui_WgtProgressClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTPROGRESS_H
