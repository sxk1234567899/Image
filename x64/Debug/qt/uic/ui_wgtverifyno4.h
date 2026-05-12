/********************************************************************************
** Form generated from reading UI file 'wgtverifyno4.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO4_H
#define UI_WGTVERIFYNO4_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <imagewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo4Class
{
public:
    QGridLayout *gridLayout;
    ImageWidget *widgetRawImage;
    QStackedWidget *stackedWidgetView;
    QWidget *pageVideo;
    QGridLayout *gridLayout_4;
    QVideoWidget *videoWidget;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelInfoIcon;
    QLabel *labelInfo;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QWidget *pageImage;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_6;
    QLabel *labelImage;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelImageName;
    QSpacerItem *verticalSpacer_8;
    QSpinBox *spinBoxVerify;
    QSpinBox *spinBoxRaw;
    ImageWidget *widgetVerifyImage;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QStackedWidget *stackedWidgetBtn;
    QWidget *pagePhoto;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButtonLow;
    QRadioButton *radioButtonHgt;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonPhoto;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonGoVerify5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSkipSampling;
    QSpacerItem *horizontalSpacer_5;
    QWidget *pageToPhoto;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonGoPhoto;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *WgtVerifyNo4Class)
    {
        if (WgtVerifyNo4Class->objectName().isEmpty())
            WgtVerifyNo4Class->setObjectName("WgtVerifyNo4Class");
        WgtVerifyNo4Class->resize(1280, 765);
        WgtVerifyNo4Class->setMinimumSize(QSize(0, 0));
        WgtVerifyNo4Class->setMaximumSize(QSize(1280, 16777215));
        gridLayout = new QGridLayout(WgtVerifyNo4Class);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widgetRawImage = new ImageWidget(WgtVerifyNo4Class);
        widgetRawImage->setObjectName("widgetRawImage");
        widgetRawImage->setMinimumSize(QSize(220, 0));
        widgetRawImage->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(widgetRawImage, 1, 0, 1, 1);

        stackedWidgetView = new QStackedWidget(WgtVerifyNo4Class);
        stackedWidgetView->setObjectName("stackedWidgetView");
        stackedWidgetView->setLineWidth(0);
        pageVideo = new QWidget();
        pageVideo->setObjectName("pageVideo");
        gridLayout_4 = new QGridLayout(pageVideo);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        videoWidget = new QVideoWidget(pageVideo);
        videoWidget->setObjectName("videoWidget");
        videoWidget->setMinimumSize(QSize(832, 468));
        videoWidget->setMaximumSize(QSize(832, 468));

        gridLayout_4->addWidget(videoWidget, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelInfoIcon = new QLabel(pageVideo);
        labelInfoIcon->setObjectName("labelInfoIcon");
        labelInfoIcon->setMinimumSize(QSize(60, 30));
        labelInfoIcon->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(labelInfoIcon);

        labelInfo = new QLabel(pageVideo);
        labelInfo->setObjectName("labelInfo");

        horizontalLayout_2->addWidget(labelInfo);


        gridLayout_4->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_5, 1, 0, 1, 1);

        stackedWidgetView->addWidget(pageVideo);
        pageImage = new QWidget();
        pageImage->setObjectName("pageImage");
        gridLayout_3 = new QGridLayout(pageImage);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 1, 0, 1, 1);

        labelImage = new QLabel(pageImage);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(832, 468));
        labelImage->setMaximumSize(QSize(832, 468));

        gridLayout_3->addWidget(labelImage, 2, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 0, 1, 1);

        labelImageName = new QLabel(pageImage);
        labelImageName->setObjectName("labelImageName");
        labelImageName->setMinimumSize(QSize(0, 0));
        labelImageName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(labelImageName, 4, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_8, 5, 0, 1, 1);

        stackedWidgetView->addWidget(pageImage);

        gridLayout->addWidget(stackedWidgetView, 0, 1, 2, 1);

        spinBoxVerify = new QSpinBox(WgtVerifyNo4Class);
        spinBoxVerify->setObjectName("spinBoxVerify");
        spinBoxVerify->setMinimumSize(QSize(220, 0));
        spinBoxVerify->setMaximumSize(QSize(220, 16777215));
        spinBoxVerify->setReadOnly(true);
        spinBoxVerify->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxVerify->setMaximum(1000);

        gridLayout->addWidget(spinBoxVerify, 0, 2, 1, 1);

        spinBoxRaw = new QSpinBox(WgtVerifyNo4Class);
        spinBoxRaw->setObjectName("spinBoxRaw");
        spinBoxRaw->setMinimumSize(QSize(220, 0));
        spinBoxRaw->setMaximumSize(QSize(220, 16777215));
        spinBoxRaw->setReadOnly(true);
        spinBoxRaw->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxRaw->setMaximum(1000);

        gridLayout->addWidget(spinBoxRaw, 0, 0, 1, 1);

        widgetVerifyImage = new ImageWidget(WgtVerifyNo4Class);
        widgetVerifyImage->setObjectName("widgetVerifyImage");
        widgetVerifyImage->setMinimumSize(QSize(220, 0));
        widgetVerifyImage->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(widgetVerifyImage, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        widgetTool = new QWidget(WgtVerifyNo4Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_3 = new QHBoxLayout(widgetTool);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        stackedWidgetBtn = new QStackedWidget(widgetTool);
        stackedWidgetBtn->setObjectName("stackedWidgetBtn");
        stackedWidgetBtn->setMinimumSize(QSize(900, 0));
        pagePhoto = new QWidget();
        pagePhoto->setObjectName("pagePhoto");
        horizontalLayout_5 = new QHBoxLayout(pagePhoto);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        radioButtonLow = new QRadioButton(pagePhoto);
        radioButtonLow->setObjectName("radioButtonLow");
        radioButtonLow->setMinimumSize(QSize(200, 70));

        horizontalLayout_4->addWidget(radioButtonLow);

        radioButtonHgt = new QRadioButton(pagePhoto);
        radioButtonHgt->setObjectName("radioButtonHgt");
        radioButtonHgt->setMinimumSize(QSize(200, 70));
        radioButtonHgt->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_4->addWidget(radioButtonHgt);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        pushButtonPhoto = new QPushButton(pagePhoto);
        pushButtonPhoto->setObjectName("pushButtonPhoto");
        pushButtonPhoto->setMinimumSize(QSize(240, 70));
        pushButtonPhoto->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/photo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonPhoto->setIcon(icon);
        pushButtonPhoto->setIconSize(QSize(70, 70));

        horizontalLayout_5->addWidget(pushButtonPhoto);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        pushButtonGoVerify5 = new QPushButton(pagePhoto);
        pushButtonGoVerify5->setObjectName("pushButtonGoVerify5");
        pushButtonGoVerify5->setMinimumSize(QSize(240, 70));

        horizontalLayout_5->addWidget(pushButtonGoVerify5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButtonSkipSampling = new QPushButton(pagePhoto);
        pushButtonSkipSampling->setObjectName("pushButtonSkipSampling");
        pushButtonSkipSampling->setMinimumSize(QSize(100, 70));

        horizontalLayout_5->addWidget(pushButtonSkipSampling);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        stackedWidgetBtn->addWidget(pagePhoto);
        pageToPhoto = new QWidget();
        pageToPhoto->setObjectName("pageToPhoto");
        horizontalLayout_6 = new QHBoxLayout(pageToPhoto);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(182, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButtonGoPhoto = new QPushButton(pageToPhoto);
        pushButtonGoPhoto->setObjectName("pushButtonGoPhoto");
        pushButtonGoPhoto->setMinimumSize(QSize(500, 70));

        horizontalLayout_6->addWidget(pushButtonGoPhoto);

        horizontalSpacer_7 = new QSpacerItem(182, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        stackedWidgetBtn->addWidget(pageToPhoto);

        horizontalLayout_3->addWidget(stackedWidgetBtn);


        horizontalLayout->addWidget(widgetTool);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);


        retranslateUi(WgtVerifyNo4Class);

        stackedWidgetView->setCurrentIndex(0);
        stackedWidgetBtn->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WgtVerifyNo4Class);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyNo4Class)
    {
        WgtVerifyNo4Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo4Class", "WgtRegNo4", nullptr));
        labelInfoIcon->setText(QString());
        labelInfo->setText(QString());
        labelImage->setText(QString());
        labelImageName->setText(QString());
        spinBoxVerify->setPrefix(QCoreApplication::translate("WgtVerifyNo4Class", "\351\234\200\351\252\214\350\257\201\345\233\276\357\274\232", nullptr));
        spinBoxRaw->setPrefix(QCoreApplication::translate("WgtVerifyNo4Class", "\345\216\237\345\247\213\347\231\273\350\256\260\357\274\232", nullptr));
        radioButtonLow->setText(QCoreApplication::translate("WgtVerifyNo4Class", "\344\275\216\345\200\215", nullptr));
        radioButtonHgt->setText(QCoreApplication::translate("WgtVerifyNo4Class", "\351\253\230\345\200\215", nullptr));
        pushButtonPhoto->setText(QCoreApplication::translate("WgtVerifyNo4Class", "    \346\213\215 \346\221\204", nullptr));
        pushButtonGoVerify5->setText(QCoreApplication::translate("WgtVerifyNo4Class", "\344\270\213\344\270\200\346\255\245", nullptr));
        pushButtonSkipSampling->setText(QCoreApplication::translate("WgtVerifyNo4Class", "\350\267\263 \350\277\207", nullptr));
        pushButtonGoPhoto->setText(QCoreApplication::translate("WgtVerifyNo4Class", "\345\210\207\346\215\242\344\270\272\346\230\276\345\276\256\347\233\270\346\234\272\346\213\215\346\221\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo4Class: public Ui_WgtVerifyNo4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO4_H
