/********************************************************************************
** Form generated from reading UI file 'wgtset.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTSET_H
#define UI_WGTSET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtSetClass
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetSetBtn;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonNet;
    QPushButton *pushButtonDevice;
    QPushButton *pushButtonOther;
    QPushButton *pushButtonLog;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *pageSetNet;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widgetNetSetBtn;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonWifi;
    QPushButton *pushButton4G;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *stackedWidgetSetNet;
    QWidget *pageWifi;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxWifi;
    QLabel *label;
    QLabel *labelWifiName;
    QDoubleSpinBox *doubleSpinBoxWifiSpeed;
    QPushButton *pushButtonTestWifi;
    QPushButton *pushButtonUpdateWifi;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidgetWifi;
    QWidget *page4G;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox4g;
    QLabel *label_2;
    QLabel *label4GName;
    QDoubleSpinBox *doubleSpinBox4GSpeed;
    QPushButton *pushButtonTest4G;
    QPushButton *pushButtonUpdate4G;
    QWidget *widget4GInfo;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget4gitem;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label4GStatus;
    QLabel *label4GNameItem;
    QLabel *label4GQuality;
    QSpacerItem *verticalSpacer_3;
    QWidget *pageSetDevice;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonNetConn;
    QLabel *label_3;
    QVideoWidget *videoWidgetNet;
    QSpacerItem *horizontalSpacer;
    QVideoWidget *videoWidgetUSB;
    QPushButton *pushButtonUSBConn;
    QLabel *label_4;
    QPushButton *pushButtonNetCamSet;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *pushButtonBtConnect;
    QPushButton *pushButtonTestPrint;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QWidget *pageOther;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QSlider *sliderBrightness;
    QLabel *label_8;
    QSpinBox *spinBoxBrightness;
    QSpinBox *spinBoxSysVolume;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSlider *sliderSysVolume;
    QWidget *pageLog;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBoxDeviceInfo;
    QVBoxLayout *verticalLayout_9;
    QTextBrowser *textBrowserDeviceInfo;
    QPushButton *pushButtonCheckUpdates;
    QGroupBox *groupBoxChangelog;
    QVBoxLayout *verticalLayout_8;
    QTextBrowser *textBrowserChangelog;

    void setupUi(QWidget *WgtSetClass)
    {
        if (WgtSetClass->objectName().isEmpty())
            WgtSetClass->setObjectName("WgtSetClass");
        WgtSetClass->resize(1302, 740);
        WgtSetClass->setMinimumSize(QSize(1280, 740));
        WgtSetClass->setMaximumSize(QSize(1302, 740));
        horizontalLayout = new QHBoxLayout(WgtSetClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        widgetSetBtn = new QWidget(WgtSetClass);
        widgetSetBtn->setObjectName("widgetSetBtn");
        widgetSetBtn->setMinimumSize(QSize(220, 0));
        widgetSetBtn->setMaximumSize(QSize(220, 16777215));
        verticalLayout = new QVBoxLayout(widgetSetBtn);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 10, 25, 10);
        pushButtonNet = new QPushButton(widgetSetBtn);
        pushButtonNet->setObjectName("pushButtonNet");
        pushButtonNet->setMinimumSize(QSize(170, 70));
        pushButtonNet->setMaximumSize(QSize(170, 70));

        verticalLayout->addWidget(pushButtonNet);

        pushButtonDevice = new QPushButton(widgetSetBtn);
        pushButtonDevice->setObjectName("pushButtonDevice");
        pushButtonDevice->setMinimumSize(QSize(170, 70));
        pushButtonDevice->setMaximumSize(QSize(170, 70));

        verticalLayout->addWidget(pushButtonDevice);

        pushButtonOther = new QPushButton(widgetSetBtn);
        pushButtonOther->setObjectName("pushButtonOther");
        pushButtonOther->setMinimumSize(QSize(170, 70));
        pushButtonOther->setMaximumSize(QSize(170, 70));

        verticalLayout->addWidget(pushButtonOther);

        pushButtonLog = new QPushButton(widgetSetBtn);
        pushButtonLog->setObjectName("pushButtonLog");
        pushButtonLog->setMinimumSize(QSize(170, 70));
        pushButtonLog->setMaximumSize(QSize(170, 70));

        verticalLayout->addWidget(pushButtonLog);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widgetSetBtn);

        stackedWidget = new QStackedWidget(WgtSetClass);
        stackedWidget->setObjectName("stackedWidget");
        pageSetNet = new QWidget();
        pageSetNet->setObjectName("pageSetNet");
        horizontalLayout_2 = new QHBoxLayout(pageSetNet);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetNetSetBtn = new QWidget(pageSetNet);
        widgetNetSetBtn->setObjectName("widgetNetSetBtn");
        widgetNetSetBtn->setMinimumSize(QSize(300, 0));
        widgetNetSetBtn->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(widgetNetSetBtn);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        pushButtonWifi = new QPushButton(widgetNetSetBtn);
        pushButtonWifi->setObjectName("pushButtonWifi");
        pushButtonWifi->setMinimumSize(QSize(250, 70));
        pushButtonWifi->setMaximumSize(QSize(260, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/wifi2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonWifi->setIcon(icon);
        pushButtonWifi->setIconSize(QSize(48, 32));

        verticalLayout_2->addWidget(pushButtonWifi);

        pushButton4G = new QPushButton(widgetNetSetBtn);
        pushButton4G->setObjectName("pushButton4G");
        pushButton4G->setMinimumSize(QSize(260, 70));
        pushButton4G->setMaximumSize(QSize(260, 70));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/net4g2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton4G->setIcon(icon1);
        pushButton4G->setIconSize(QSize(43, 34));

        verticalLayout_2->addWidget(pushButton4G);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addWidget(widgetNetSetBtn);

        stackedWidgetSetNet = new QStackedWidget(pageSetNet);
        stackedWidgetSetNet->setObjectName("stackedWidgetSetNet");
        pageWifi = new QWidget();
        pageWifi->setObjectName("pageWifi");
        verticalLayout_3 = new QVBoxLayout(pageWifi);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 30, -1, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        checkBoxWifi = new QCheckBox(pageWifi);
        checkBoxWifi->setObjectName("checkBoxWifi");
        checkBoxWifi->setMinimumSize(QSize(200, 0));
        checkBoxWifi->setMaximumSize(QSize(200, 16777215));
        checkBoxWifi->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        checkBoxWifi->setStyleSheet(QString::fromUtf8(""));
        checkBoxWifi->setChecked(true);

        horizontalLayout_4->addWidget(checkBoxWifi);

        label = new QLabel(pageWifi);
        label->setObjectName("label");
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        labelWifiName = new QLabel(pageWifi);
        labelWifiName->setObjectName("labelWifiName");
        labelWifiName->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_4->addWidget(labelWifiName);

        doubleSpinBoxWifiSpeed = new QDoubleSpinBox(pageWifi);
        doubleSpinBoxWifiSpeed->setObjectName("doubleSpinBoxWifiSpeed");
        doubleSpinBoxWifiSpeed->setMaximumSize(QSize(150, 16777215));
        doubleSpinBoxWifiSpeed->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        doubleSpinBoxWifiSpeed->setReadOnly(true);
        doubleSpinBoxWifiSpeed->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        doubleSpinBoxWifiSpeed->setMaximum(1000.000000000000000);
        doubleSpinBoxWifiSpeed->setValue(0.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBoxWifiSpeed);

        pushButtonTestWifi = new QPushButton(pageWifi);
        pushButtonTestWifi->setObjectName("pushButtonTestWifi");
        pushButtonTestWifi->setMinimumSize(QSize(60, 32));
        pushButtonTestWifi->setMaximumSize(QSize(60, 32));

        horizontalLayout_4->addWidget(pushButtonTestWifi);

        pushButtonUpdateWifi = new QPushButton(pageWifi);
        pushButtonUpdateWifi->setObjectName("pushButtonUpdateWifi");
        pushButtonUpdateWifi->setMinimumSize(QSize(60, 32));
        pushButtonUpdateWifi->setMaximumSize(QSize(60, 32));

        horizontalLayout_4->addWidget(pushButtonUpdateWifi);


        verticalLayout_3->addLayout(horizontalLayout_4);

        widget_2 = new QWidget(pageWifi);
        widget_2->setObjectName("widget_2");
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(50, 20, 50, 20);
        tableWidgetWifi = new QTableWidget(widget_2);
        tableWidgetWifi->setObjectName("tableWidgetWifi");

        gridLayout_4->addWidget(tableWidgetWifi, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget_2);

        stackedWidgetSetNet->addWidget(pageWifi);
        page4G = new QWidget();
        page4G->setObjectName("page4G");
        verticalLayout_4 = new QVBoxLayout(page4G);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, 30, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        checkBox4g = new QCheckBox(page4G);
        checkBox4g->setObjectName("checkBox4g");
        checkBox4g->setMinimumSize(QSize(200, 50));
        checkBox4g->setMaximumSize(QSize(200, 16777215));
        checkBox4g->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        checkBox4g->setStyleSheet(QString::fromUtf8(""));
        checkBox4g->setCheckable(true);
        checkBox4g->setChecked(false);

        horizontalLayout_5->addWidget(checkBox4g);

        label_2 = new QLabel(page4G);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(label_2);

        label4GName = new QLabel(page4G);
        label4GName->setObjectName("label4GName");

        horizontalLayout_5->addWidget(label4GName);

        doubleSpinBox4GSpeed = new QDoubleSpinBox(page4G);
        doubleSpinBox4GSpeed->setObjectName("doubleSpinBox4GSpeed");
        doubleSpinBox4GSpeed->setMaximumSize(QSize(150, 16777215));
        doubleSpinBox4GSpeed->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        doubleSpinBox4GSpeed->setReadOnly(true);
        doubleSpinBox4GSpeed->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        doubleSpinBox4GSpeed->setMaximum(1000.000000000000000);
        doubleSpinBox4GSpeed->setValue(0.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox4GSpeed);

        pushButtonTest4G = new QPushButton(page4G);
        pushButtonTest4G->setObjectName("pushButtonTest4G");
        pushButtonTest4G->setMinimumSize(QSize(120, 32));
        pushButtonTest4G->setMaximumSize(QSize(120, 32));

        horizontalLayout_5->addWidget(pushButtonTest4G);

        pushButtonUpdate4G = new QPushButton(page4G);
        pushButtonUpdate4G->setObjectName("pushButtonUpdate4G");
        pushButtonUpdate4G->setMinimumSize(QSize(60, 32));
        pushButtonUpdate4G->setMaximumSize(QSize(60, 32));

        horizontalLayout_5->addWidget(pushButtonUpdate4G);


        verticalLayout_4->addLayout(horizontalLayout_5);

        widget4GInfo = new QWidget(page4G);
        widget4GInfo->setObjectName("widget4GInfo");
        widget4GInfo->setMinimumSize(QSize(0, 563));
        verticalLayout_5 = new QVBoxLayout(widget4GInfo);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        widget4gitem = new QWidget(widget4GInfo);
        widget4gitem->setObjectName("widget4gitem");
        horizontalLayout_3 = new QHBoxLayout(widget4gitem);
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(30, -1, 30, -1);
        label4GStatus = new QLabel(widget4gitem);
        label4GStatus->setObjectName("label4GStatus");
        label4GStatus->setMinimumSize(QSize(30, 30));
        label4GStatus->setMaximumSize(QSize(30, 30));
        label4GStatus->setPixmap(QPixmap(QString::fromUtf8(":/image/ok1.png")));
        label4GStatus->setScaledContents(true);

        horizontalLayout_3->addWidget(label4GStatus);

        label4GNameItem = new QLabel(widget4gitem);
        label4GNameItem->setObjectName("label4GNameItem");

        horizontalLayout_3->addWidget(label4GNameItem);

        label4GQuality = new QLabel(widget4gitem);
        label4GQuality->setObjectName("label4GQuality");
        label4GQuality->setMinimumSize(QSize(40, 40));
        label4GQuality->setMaximumSize(QSize(40, 40));

        horizontalLayout_3->addWidget(label4GQuality);


        verticalLayout_5->addWidget(widget4gitem);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        verticalLayout_4->addWidget(widget4GInfo);

        stackedWidgetSetNet->addWidget(page4G);

        horizontalLayout_2->addWidget(stackedWidgetSetNet);

        stackedWidget->addWidget(pageSetNet);
        pageSetDevice = new QWidget();
        pageSetDevice->setObjectName("pageSetDevice");
        verticalLayout_6 = new QVBoxLayout(pageSetDevice);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName("verticalLayout_6");
        widget_3 = new QWidget(pageSetDevice);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(0, 400));
        widget_3->setMaximumSize(QSize(16777215, 500));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(20);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButtonNetConn = new QPushButton(widget_3);
        pushButtonNetConn->setObjectName("pushButtonNetConn");
        pushButtonNetConn->setMinimumSize(QSize(120, 60));
        pushButtonNetConn->setMaximumSize(QSize(120, 60));

        gridLayout_2->addWidget(pushButtonNetConn, 2, 2, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        videoWidgetNet = new QVideoWidget(widget_3);
        videoWidgetNet->setObjectName("videoWidgetNet");
        videoWidgetNet->setMinimumSize(QSize(480, 270));
        videoWidgetNet->setMaximumSize(QSize(480, 270));

        gridLayout_2->addWidget(videoWidgetNet, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 1, 1, 1);

        videoWidgetUSB = new QVideoWidget(widget_3);
        videoWidgetUSB->setObjectName("videoWidgetUSB");
        videoWidgetUSB->setMinimumSize(QSize(480, 270));
        videoWidgetUSB->setMaximumSize(QSize(480, 270));

        gridLayout_2->addWidget(videoWidgetUSB, 1, 4, 1, 2);

        pushButtonUSBConn = new QPushButton(widget_3);
        pushButtonUSBConn->setObjectName("pushButtonUSBConn");
        pushButtonUSBConn->setMinimumSize(QSize(120, 60));
        pushButtonUSBConn->setMaximumSize(QSize(120, 60));

        gridLayout_2->addWidget(pushButtonUSBConn, 2, 5, 1, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 4, 1, 1);

        pushButtonNetCamSet = new QPushButton(widget_3);
        pushButtonNetCamSet->setObjectName("pushButtonNetCamSet");
        pushButtonNetCamSet->setMinimumSize(QSize(120, 60));
        pushButtonNetCamSet->setMaximumSize(QSize(120, 60));

        gridLayout_2->addWidget(pushButtonNetCamSet, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 3, 1);


        verticalLayout_6->addWidget(widget_3);

        widget_4 = new QWidget(pageSetDevice);
        widget_4->setObjectName("widget_4");
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        pushButtonBtConnect = new QPushButton(widget_4);
        pushButtonBtConnect->setObjectName("pushButtonBtConnect");
        pushButtonBtConnect->setMinimumSize(QSize(170, 70));
        pushButtonBtConnect->setMaximumSize(QSize(170, 70));

        gridLayout->addWidget(pushButtonBtConnect, 1, 0, 1, 1);

        pushButtonTestPrint = new QPushButton(widget_4);
        pushButtonTestPrint->setObjectName("pushButtonTestPrint");
        pushButtonTestPrint->setMinimumSize(QSize(170, 70));
        pushButtonTestPrint->setMaximumSize(QSize(170, 70));

        gridLayout->addWidget(pushButtonTestPrint, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);


        verticalLayout_6->addWidget(widget_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        stackedWidget->addWidget(pageSetDevice);
        pageOther = new QWidget();
        pageOther->setObjectName("pageOther");
        gridLayout_3 = new QGridLayout(pageOther);
        gridLayout_3->setSpacing(20);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(20, 20, 20, 20);
        label_9 = new QLabel(pageOther);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        sliderBrightness = new QSlider(pageOther);
        sliderBrightness->setObjectName("sliderBrightness");
        sliderBrightness->setMinimumSize(QSize(0, 80));
        sliderBrightness->setMaximumSize(QSize(16777215, 80));
        sliderBrightness->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_3->addWidget(sliderBrightness, 3, 0, 1, 1);

        label_8 = new QLabel(pageOther);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        spinBoxBrightness = new QSpinBox(pageOther);
        spinBoxBrightness->setObjectName("spinBoxBrightness");
        spinBoxBrightness->setMinimumSize(QSize(0, 80));
        spinBoxBrightness->setMaximumSize(QSize(16777215, 80));
        spinBoxBrightness->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBoxBrightness->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        gridLayout_3->addWidget(spinBoxBrightness, 3, 1, 1, 1);

        spinBoxSysVolume = new QSpinBox(pageOther);
        spinBoxSysVolume->setObjectName("spinBoxSysVolume");
        spinBoxSysVolume->setMinimumSize(QSize(0, 80));
        spinBoxSysVolume->setMaximumSize(QSize(16777215, 80));
        spinBoxSysVolume->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBoxSysVolume->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxSysVolume->setMaximum(100);
        spinBoxSysVolume->setValue(50);

        gridLayout_3->addWidget(spinBoxSysVolume, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 4, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        sliderSysVolume = new QSlider(pageOther);
        sliderSysVolume->setObjectName("sliderSysVolume");
        sliderSysVolume->setMinimumSize(QSize(0, 80));
        sliderSysVolume->setMaximumSize(QSize(16777215, 80));
        sliderSysVolume->setMaximum(100);
        sliderSysVolume->setValue(50);
        sliderSysVolume->setOrientation(Qt::Orientation::Horizontal);
        sliderSysVolume->setInvertedAppearance(false);
        sliderSysVolume->setInvertedControls(false);
        sliderSysVolume->setTickPosition(QSlider::TickPosition::NoTicks);

        gridLayout_3->addWidget(sliderSysVolume, 1, 0, 1, 1);

        stackedWidget->addWidget(pageOther);
        pageLog = new QWidget();
        pageLog->setObjectName("pageLog");
        verticalLayout_7 = new QVBoxLayout(pageLog);
        verticalLayout_7->setSpacing(20);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(20, 20, 0, 0);
        groupBoxDeviceInfo = new QGroupBox(pageLog);
        groupBoxDeviceInfo->setObjectName("groupBoxDeviceInfo");
        verticalLayout_9 = new QVBoxLayout(groupBoxDeviceInfo);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(20, 50, 0, 0);
        textBrowserDeviceInfo = new QTextBrowser(groupBoxDeviceInfo);
        textBrowserDeviceInfo->setObjectName("textBrowserDeviceInfo");
        textBrowserDeviceInfo->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);

        verticalLayout_9->addWidget(textBrowserDeviceInfo);


        verticalLayout_7->addWidget(groupBoxDeviceInfo);

        pushButtonCheckUpdates = new QPushButton(pageLog);
        pushButtonCheckUpdates->setObjectName("pushButtonCheckUpdates");
        pushButtonCheckUpdates->setMinimumSize(QSize(200, 70));
        pushButtonCheckUpdates->setMaximumSize(QSize(200, 70));
        pushButtonCheckUpdates->setSizeIncrement(QSize(0, 0));

        verticalLayout_7->addWidget(pushButtonCheckUpdates);

        groupBoxChangelog = new QGroupBox(pageLog);
        groupBoxChangelog->setObjectName("groupBoxChangelog");
        groupBoxChangelog->setMinimumSize(QSize(0, 250));
        groupBoxChangelog->setMaximumSize(QSize(16777215, 250));
        verticalLayout_8 = new QVBoxLayout(groupBoxChangelog);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(20, 50, 0, 0);
        textBrowserChangelog = new QTextBrowser(groupBoxChangelog);
        textBrowserChangelog->setObjectName("textBrowserChangelog");
        textBrowserChangelog->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);

        verticalLayout_8->addWidget(textBrowserChangelog);


        verticalLayout_7->addWidget(groupBoxChangelog);

        stackedWidget->addWidget(pageLog);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(WgtSetClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WgtSetClass);
    } // setupUi

    void retranslateUi(QWidget *WgtSetClass)
    {
        WgtSetClass->setWindowTitle(QCoreApplication::translate("WgtSetClass", "WgtSet", nullptr));
        pushButtonNet->setText(QCoreApplication::translate("WgtSetClass", "\347\275\221\347\273\234", nullptr));
        pushButtonDevice->setText(QCoreApplication::translate("WgtSetClass", "\350\277\236\346\216\245", nullptr));
        pushButtonOther->setText(QCoreApplication::translate("WgtSetClass", "\345\205\266\344\273\226", nullptr));
        pushButtonLog->setText(QCoreApplication::translate("WgtSetClass", "\345\205\263\344\272\216", nullptr));
        pushButtonWifi->setText(QCoreApplication::translate("WgtSetClass", "  \345\267\262\345\274\200\345\220\257", nullptr));
        pushButton4G->setText(QCoreApplication::translate("WgtSetClass", "  \345\267\262\345\274\200\345\220\257", nullptr));
        checkBoxWifi->setText(QCoreApplication::translate("WgtSetClass", "\345\274\200\345\220\257\347\212\266\346\200\201", nullptr));
        label->setText(QCoreApplication::translate("WgtSetClass", "\345\267\262\350\277\236\346\216\245:", nullptr));
        labelWifiName->setText(QString());
        doubleSpinBoxWifiSpeed->setPrefix(QString());
        doubleSpinBoxWifiSpeed->setSuffix(QCoreApplication::translate("WgtSetClass", "KB/s", nullptr));
        pushButtonTestWifi->setText(QCoreApplication::translate("WgtSetClass", "\346\265\213\351\200\237", nullptr));
        pushButtonUpdateWifi->setText(QCoreApplication::translate("WgtSetClass", "\345\210\267\346\226\260", nullptr));
        checkBox4g->setText(QCoreApplication::translate("WgtSetClass", "\345\274\200\345\220\257\347\212\266\346\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("WgtSetClass", "\345\267\262\350\277\236\346\216\245:", nullptr));
        label4GName->setText(QCoreApplication::translate("WgtSetClass", "\344\270\255\345\233\275\347\247\273\345\212\250", nullptr));
        doubleSpinBox4GSpeed->setPrefix(QString());
        doubleSpinBox4GSpeed->setSuffix(QCoreApplication::translate("WgtSetClass", "KB/s", nullptr));
        pushButtonTest4G->setText(QCoreApplication::translate("WgtSetClass", "\346\265\213\350\257\225\351\200\237\345\272\246", nullptr));
        pushButtonUpdate4G->setText(QCoreApplication::translate("WgtSetClass", "\345\210\267\346\226\260", nullptr));
        label4GStatus->setText(QString());
        label4GNameItem->setText(QCoreApplication::translate("WgtSetClass", "\344\270\255\345\233\275\347\247\273\345\212\250\350\234\202\347\252\235\346\225\260\346\215\256", nullptr));
        label4GQuality->setText(QString());
        pushButtonNetConn->setText(QCoreApplication::translate("WgtSetClass", "\350\277\236\346\216\245", nullptr));
        label_3->setText(QCoreApplication::translate("WgtSetClass", "\346\230\276\345\276\256\346\221\204\345\203\217", nullptr));
        pushButtonUSBConn->setText(QCoreApplication::translate("WgtSetClass", "\350\277\236\346\216\245", nullptr));
        label_4->setText(QCoreApplication::translate("WgtSetClass", "\345\205\250\345\261\200\346\221\204\345\203\217", nullptr));
        pushButtonNetCamSet->setText(QCoreApplication::translate("WgtSetClass", "\351\205\215\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("WgtSetClass", "\346\240\207\347\255\276\346\211\223\345\215\260\346\234\272", nullptr));
        pushButtonBtConnect->setText(QCoreApplication::translate("WgtSetClass", "\350\223\235\347\211\231\350\277\236\346\216\245", nullptr));
        pushButtonTestPrint->setText(QCoreApplication::translate("WgtSetClass", "\346\265\213\350\257\225\346\211\223\345\215\260", nullptr));
        label_9->setText(QCoreApplication::translate("WgtSetClass", "\345\261\217\345\271\225\344\272\256\345\272\246", nullptr));
        label_8->setText(QCoreApplication::translate("WgtSetClass", "\351\237\263\351\207\217", nullptr));
        groupBoxDeviceInfo->setTitle(QCoreApplication::translate("WgtSetClass", "\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));
        textBrowserDeviceInfo->setHtml(QCoreApplication::translate("WgtSetClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:22px;\"><br /></p></body></html>", nullptr));
        pushButtonCheckUpdates->setText(QCoreApplication::translate("WgtSetClass", "\346\243\200\346\237\245\346\233\264\346\226\260", nullptr));
        groupBoxChangelog->setTitle(QCoreApplication::translate("WgtSetClass", "\346\233\264\346\226\260\346\227\245\345\277\227", nullptr));
        textBrowserChangelog->setHtml(QCoreApplication::translate("WgtSetClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:22px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtSetClass: public Ui_WgtSetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTSET_H
