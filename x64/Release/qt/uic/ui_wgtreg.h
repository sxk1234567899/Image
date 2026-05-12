/********************************************************************************
** Form generated from reading UI file 'wgtreg.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREG_H
#define UI_WGTREG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtRegClass
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *WgtRegClass)
    {
        if (WgtRegClass->objectName().isEmpty())
            WgtRegClass->setObjectName("WgtRegClass");
        WgtRegClass->resize(1122, 673);
        gridLayout = new QGridLayout(WgtRegClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(WgtRegClass);
        stackedWidget->setObjectName("stackedWidget");

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(WgtRegClass);

        QMetaObject::connectSlotsByName(WgtRegClass);
    } // setupUi

    void retranslateUi(QWidget *WgtRegClass)
    {
        WgtRegClass->setWindowTitle(QCoreApplication::translate("WgtRegClass", "WgtBaseInfo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtRegClass: public Ui_WgtRegClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREG_H
