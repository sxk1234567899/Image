/********************************************************************************
** Form generated from reading UI file 'wgtverify.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFY_H
#define UI_WGTVERIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyClass
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *WgtVerifyClass)
    {
        if (WgtVerifyClass->objectName().isEmpty())
            WgtVerifyClass->setObjectName("WgtVerifyClass");
        WgtVerifyClass->resize(600, 400);
        gridLayout = new QGridLayout(WgtVerifyClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(WgtVerifyClass);
        stackedWidget->setObjectName("stackedWidget");

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(WgtVerifyClass);

        QMetaObject::connectSlotsByName(WgtVerifyClass);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyClass)
    {
        WgtVerifyClass->setWindowTitle(QCoreApplication::translate("WgtVerifyClass", "WgtVerify", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyClass: public Ui_WgtVerifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFY_H
