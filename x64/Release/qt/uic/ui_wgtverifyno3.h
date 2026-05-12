/********************************************************************************
** Form generated from reading UI file 'wgtverifyno3.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO3_H
#define UI_WGTVERIFYNO3_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
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

class Ui_WgtVerifyNo3Class
{
public:
    QGridLayout *gridLayout;
    QSpinBox *spinBoxRaw;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QVideoWidget *videoWidget;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelInfoIcon;
    QLabel *labelInfo;
    QSpacerItem *verticalSpacer_4;
    QSpinBox *spinBoxVerify;
    ImageWidget *widgetRawImage;
    ImageWidget *widgetVerifyImage;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonGoVerify4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WgtVerifyNo3Class)
    {
        if (WgtVerifyNo3Class->objectName().isEmpty())
            WgtVerifyNo3Class->setObjectName("WgtVerifyNo3Class");
        WgtVerifyNo3Class->resize(1280, 729);
        gridLayout = new QGridLayout(WgtVerifyNo3Class);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBoxRaw = new QSpinBox(WgtVerifyNo3Class);
        spinBoxRaw->setObjectName("spinBoxRaw");
        spinBoxRaw->setMinimumSize(QSize(220, 0));
        spinBoxRaw->setMaximumSize(QSize(220, 16777215));
        spinBoxRaw->setReadOnly(true);
        spinBoxRaw->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxRaw->setMaximum(1000);

        gridLayout->addWidget(spinBoxRaw, 0, 0, 1, 1);

        widget_2 = new QWidget(WgtVerifyNo3Class);
        widget_2->setObjectName("widget_2");
        widget_2->setMaximumSize(QSize(832, 16777215));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        videoWidget = new QVideoWidget(widget_2);
        videoWidget->setObjectName("videoWidget");
        videoWidget->setMinimumSize(QSize(832, 468));
        videoWidget->setMaximumSize(QSize(832, 468));

        gridLayout_2->addWidget(videoWidget, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelInfoIcon = new QLabel(widget_2);
        labelInfoIcon->setObjectName("labelInfoIcon");
        labelInfoIcon->setMinimumSize(QSize(60, 30));
        labelInfoIcon->setMaximumSize(QSize(60, 30));
        labelInfoIcon->setScaledContents(false);
        labelInfoIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(labelInfoIcon);

        labelInfo = new QLabel(widget_2);
        labelInfo->setObjectName("labelInfo");

        horizontalLayout_2->addWidget(labelInfo);


        gridLayout_2->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 5, 0, 1, 1);


        gridLayout->addWidget(widget_2, 0, 1, 2, 1);

        spinBoxVerify = new QSpinBox(WgtVerifyNo3Class);
        spinBoxVerify->setObjectName("spinBoxVerify");
        spinBoxVerify->setMinimumSize(QSize(220, 0));
        spinBoxVerify->setMaximumSize(QSize(220, 16777215));
        spinBoxVerify->setReadOnly(true);
        spinBoxVerify->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxVerify->setMaximum(1000);

        gridLayout->addWidget(spinBoxVerify, 0, 2, 1, 1);

        widgetRawImage = new ImageWidget(WgtVerifyNo3Class);
        widgetRawImage->setObjectName("widgetRawImage");
        widgetRawImage->setMinimumSize(QSize(220, 0));
        widgetRawImage->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(widgetRawImage, 1, 0, 1, 1);

        widgetVerifyImage = new ImageWidget(WgtVerifyNo3Class);
        widgetVerifyImage->setObjectName("widgetVerifyImage");
        widgetVerifyImage->setMinimumSize(QSize(220, 0));
        widgetVerifyImage->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(widgetVerifyImage, 1, 2, 1, 1);

        widgetTool = new QWidget(WgtVerifyNo3Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_3 = new QHBoxLayout(widgetTool);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButtonGoVerify4 = new QPushButton(widgetTool);
        pushButtonGoVerify4->setObjectName("pushButtonGoVerify4");
        pushButtonGoVerify4->setMinimumSize(QSize(240, 70));

        horizontalLayout_3->addWidget(pushButtonGoVerify4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widgetTool, 2, 0, 1, 3);


        retranslateUi(WgtVerifyNo3Class);

        QMetaObject::connectSlotsByName(WgtVerifyNo3Class);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyNo3Class)
    {
        WgtVerifyNo3Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo3Class", "WgtVerifyNo3", nullptr));
        spinBoxRaw->setPrefix(QCoreApplication::translate("WgtVerifyNo3Class", "\345\216\237\345\247\213\347\231\273\350\256\260\357\274\232", nullptr));
        labelInfoIcon->setText(QString());
        labelInfo->setText(QString());
        spinBoxVerify->setPrefix(QCoreApplication::translate("WgtVerifyNo3Class", "\351\234\200\351\252\214\350\257\201\345\233\276\357\274\232", nullptr));
        pushButtonGoVerify4->setText(QCoreApplication::translate("WgtVerifyNo3Class", "\344\270\213\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo3Class: public Ui_WgtVerifyNo3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO3_H
