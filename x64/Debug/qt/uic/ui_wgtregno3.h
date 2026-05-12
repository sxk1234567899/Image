/********************************************************************************
** Form generated from reading UI file 'wgtregno3.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGNO3_H
#define UI_WGTREGNO3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <imagewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WgtRegNo3Class
{
public:
    QGridLayout *gridLayout;
    QSpinBox *spinBoxMarked;
    ImageWidget *widgetImage;
    ImageWidget *widgetImageMarked;
    QSpinBox *spinBoxGlobal;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBoxGMarked;
    QSpinBox *spinBoxAllMarked;
    QLabel *labelInfo;
    QLabel *labelInfoIcon;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelImage;
    QSpacerItem *verticalSpacer_4;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonMarked;
    QPushButton *pushButtonReMarked;
    QPushButton *pushButtonAutoMarked;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonGoReg4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonSkipSampling;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WgtRegNo3Class)
    {
        if (WgtRegNo3Class->objectName().isEmpty())
            WgtRegNo3Class->setObjectName("WgtRegNo3Class");
        WgtRegNo3Class->resize(1280, 784);
        WgtRegNo3Class->setMinimumSize(QSize(0, 0));
        WgtRegNo3Class->setMaximumSize(QSize(1280, 16777215));
        gridLayout = new QGridLayout(WgtRegNo3Class);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBoxMarked = new QSpinBox(WgtRegNo3Class);
        spinBoxMarked->setObjectName("spinBoxMarked");
        spinBoxMarked->setMinimumSize(QSize(220, 0));
        spinBoxMarked->setMaximumSize(QSize(220, 16777215));
        spinBoxMarked->setReadOnly(true);
        spinBoxMarked->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxMarked->setMaximum(999);

        gridLayout->addWidget(spinBoxMarked, 1, 2, 1, 1);

        widgetImage = new ImageWidget(WgtRegNo3Class);
        widgetImage->setObjectName("widgetImage");
        widgetImage->setMinimumSize(QSize(220, 0));
        widgetImage->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(widgetImage, 2, 0, 1, 1);

        widgetImageMarked = new ImageWidget(WgtRegNo3Class);
        widgetImageMarked->setObjectName("widgetImageMarked");
        widgetImageMarked->setMinimumSize(QSize(220, 0));
        widgetImageMarked->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(widgetImageMarked, 2, 2, 1, 1);

        spinBoxGlobal = new QSpinBox(WgtRegNo3Class);
        spinBoxGlobal->setObjectName("spinBoxGlobal");
        spinBoxGlobal->setMaximumSize(QSize(222, 16777215));
        spinBoxGlobal->setReadOnly(true);
        spinBoxGlobal->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxGlobal->setMaximum(999);

        gridLayout->addWidget(spinBoxGlobal, 1, 0, 1, 1);

        widget_2 = new QWidget(WgtRegNo3Class);
        widget_2->setObjectName("widget_2");
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, -1, 10, -1);
        spinBoxGMarked = new QSpinBox(widget_2);
        spinBoxGMarked->setObjectName("spinBoxGMarked");
        spinBoxGMarked->setMinimumSize(QSize(220, 0));
        spinBoxGMarked->setMaximumSize(QSize(300, 16777215));
        spinBoxGMarked->setReadOnly(true);
        spinBoxGMarked->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxGMarked->setMaximum(999);

        gridLayout_3->addWidget(spinBoxGMarked, 0, 2, 1, 1);

        spinBoxAllMarked = new QSpinBox(widget_2);
        spinBoxAllMarked->setObjectName("spinBoxAllMarked");
        spinBoxAllMarked->setMinimumSize(QSize(220, 0));
        spinBoxAllMarked->setMaximumSize(QSize(300, 16777215));
        spinBoxAllMarked->setReadOnly(true);
        spinBoxAllMarked->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxAllMarked->setMaximum(999);

        gridLayout_3->addWidget(spinBoxAllMarked, 1, 2, 1, 1);

        labelInfo = new QLabel(widget_2);
        labelInfo->setObjectName("labelInfo");

        gridLayout_3->addWidget(labelInfo, 0, 1, 2, 1);

        labelInfoIcon = new QLabel(widget_2);
        labelInfoIcon->setObjectName("labelInfoIcon");
        labelInfoIcon->setMinimumSize(QSize(60, 60));
        labelInfoIcon->setMaximumSize(QSize(60, 60));

        gridLayout_3->addWidget(labelInfoIcon, 0, 0, 2, 1);


        gridLayout_2->addLayout(gridLayout_3, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        labelImage = new QLabel(widget_2);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(832, 468));
        labelImage->setMaximumSize(QSize(832, 468));

        gridLayout_2->addWidget(labelImage, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 5, 0, 1, 1);


        gridLayout->addWidget(widget_2, 1, 1, 2, 1);

        widgetTool = new QWidget(WgtRegNo3Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_3 = new QHBoxLayout(widgetTool);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonMarked = new QPushButton(widgetTool);
        pushButtonMarked->setObjectName("pushButtonMarked");
        pushButtonMarked->setMinimumSize(QSize(240, 70));

        horizontalLayout_3->addWidget(pushButtonMarked);

        pushButtonReMarked = new QPushButton(widgetTool);
        pushButtonReMarked->setObjectName("pushButtonReMarked");
        pushButtonReMarked->setMinimumSize(QSize(240, 70));

        horizontalLayout_3->addWidget(pushButtonReMarked);

        pushButtonAutoMarked = new QPushButton(widgetTool);
        pushButtonAutoMarked->setObjectName("pushButtonAutoMarked");
        pushButtonAutoMarked->setMinimumSize(QSize(240, 70));

        horizontalLayout_3->addWidget(pushButtonAutoMarked);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonGoReg4 = new QPushButton(widgetTool);
        pushButtonGoReg4->setObjectName("pushButtonGoReg4");
        pushButtonGoReg4->setMinimumSize(QSize(240, 70));

        horizontalLayout_3->addWidget(pushButtonGoReg4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButtonSkipSampling = new QPushButton(widgetTool);
        pushButtonSkipSampling->setObjectName("pushButtonSkipSampling");
        pushButtonSkipSampling->setMinimumSize(QSize(100, 70));

        horizontalLayout_3->addWidget(pushButtonSkipSampling);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widgetTool, 3, 0, 1, 3);


        retranslateUi(WgtRegNo3Class);

        QMetaObject::connectSlotsByName(WgtRegNo3Class);
    } // setupUi

    void retranslateUi(QWidget *WgtRegNo3Class)
    {
        WgtRegNo3Class->setWindowTitle(QCoreApplication::translate("WgtRegNo3Class", "WgtRegNo3", nullptr));
        spinBoxMarked->setPrefix(QCoreApplication::translate("WgtRegNo3Class", "\345\267\262\346\240\207\350\256\260\345\233\276\357\274\232", nullptr));
        spinBoxGlobal->setPrefix(QCoreApplication::translate("WgtRegNo3Class", "\345\217\257\346\240\207\350\256\260\345\233\276\357\274\232", nullptr));
        spinBoxGMarked->setPrefix(QCoreApplication::translate("WgtRegNo3Class", "\345\217\257\346\240\207\350\256\260\345\205\250\345\261\200\345\233\276\357\274\232", nullptr));
        spinBoxAllMarked->setPrefix(QCoreApplication::translate("WgtRegNo3Class", "\345\267\262\346\240\207\350\256\260\345\233\276\346\200\273\346\225\260\357\274\232", nullptr));
        labelInfo->setText(QString());
        labelInfoIcon->setText(QString());
        labelImage->setText(QString());
        pushButtonMarked->setText(QCoreApplication::translate("WgtRegNo3Class", "\347\241\256\350\256\244\346\240\207\350\256\260", nullptr));
        pushButtonReMarked->setText(QCoreApplication::translate("WgtRegNo3Class", "\351\207\215\346\226\260\346\240\207\350\256\260", nullptr));
        pushButtonAutoMarked->setText(QCoreApplication::translate("WgtRegNo3Class", "\350\207\252\345\212\250\346\240\207\350\256\260", nullptr));
        pushButtonGoReg4->setText(QCoreApplication::translate("WgtRegNo3Class", "\344\270\213\344\270\200\346\255\245", nullptr));
        pushButtonSkipSampling->setText(QCoreApplication::translate("WgtRegNo3Class", "\350\267\263 \350\277\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtRegNo3Class: public Ui_WgtRegNo3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGNO3_H
