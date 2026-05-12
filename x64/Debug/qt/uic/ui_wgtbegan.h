/********************************************************************************
** Form generated from reading UI file 'wgtbegan.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTBEGAN_H
#define UI_WGTBEGAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtBeganClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *WgtBeganClass)
    {
        if (WgtBeganClass->objectName().isEmpty())
            WgtBeganClass->setObjectName("WgtBeganClass");
        WgtBeganClass->resize(1920, 1080);
        gridLayout = new QGridLayout(WgtBeganClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(WgtBeganClass);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(WgtBeganClass);

        QMetaObject::connectSlotsByName(WgtBeganClass);
    } // setupUi

    void retranslateUi(QWidget *WgtBeganClass)
    {
        WgtBeganClass->setWindowTitle(QCoreApplication::translate("WgtBeganClass", "WgtBegan", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtBeganClass: public Ui_WgtBeganClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTBEGAN_H
