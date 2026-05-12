/********************************************************************************
** Form generated from reading UI file 'wgthome.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTHOME_H
#define UI_WGTHOME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtHomeClass
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButtonReg;
    QPushButton *pushButtonVerify;
    QPushButton *pushButtonProgress;
    QPushButton *pushButtonSet;
    QWidget *widgetSave;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QProgressBar *progressBarMemory;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetNet;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *labelWifi;
    QLabel *label4g;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widgetDevice;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *labelUSBCamera;
    QLabel *labelNetCamera;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widgetSys;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QProgressBar *progressBarSound;
    QLabel *label_5;
    QProgressBar *progressBarBrightness;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QWidget *WgtHomeClass)
    {
        if (WgtHomeClass->objectName().isEmpty())
            WgtHomeClass->setObjectName("WgtHomeClass");
        WgtHomeClass->resize(1280, 817);
        WgtHomeClass->setMinimumSize(QSize(0, 0));
        WgtHomeClass->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(WgtHomeClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(50);
        gridLayout->setContentsMargins(20, 50, 20, 50);
        pushButtonReg = new QPushButton(WgtHomeClass);
        pushButtonReg->setObjectName("pushButtonReg");
        pushButtonReg->setMinimumSize(QSize(0, 0));
        pushButtonReg->setMaximumSize(QSize(16777215, 16777215));
        pushButtonReg->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        pushButtonReg->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/register.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonReg->setIcon(icon);
        pushButtonReg->setIconSize(QSize(250, 150));

        gridLayout->addWidget(pushButtonReg, 0, 0, 1, 2);

        pushButtonVerify = new QPushButton(WgtHomeClass);
        pushButtonVerify->setObjectName("pushButtonVerify");
        pushButtonVerify->setMinimumSize(QSize(0, 0));
        pushButtonVerify->setMaximumSize(QSize(16777215, 16777215));
        pushButtonVerify->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        pushButtonVerify->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/validate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonVerify->setIcon(icon1);
        pushButtonVerify->setIconSize(QSize(250, 150));

        gridLayout->addWidget(pushButtonVerify, 0, 2, 1, 2);

        pushButtonProgress = new QPushButton(WgtHomeClass);
        pushButtonProgress->setObjectName("pushButtonProgress");
        pushButtonProgress->setMinimumSize(QSize(0, 0));
        pushButtonProgress->setMaximumSize(QSize(16777215, 16777215));
        pushButtonProgress->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        pushButtonProgress->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/pace.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonProgress->setIcon(icon2);
        pushButtonProgress->setIconSize(QSize(250, 150));

        gridLayout->addWidget(pushButtonProgress, 1, 0, 1, 2);

        pushButtonSet = new QPushButton(WgtHomeClass);
        pushButtonSet->setObjectName("pushButtonSet");
        pushButtonSet->setMinimumSize(QSize(0, 0));
        pushButtonSet->setMaximumSize(QSize(16777215, 16777215));
        pushButtonSet->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        pushButtonSet->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/setting.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonSet->setIcon(icon3);
        pushButtonSet->setIconSize(QSize(250, 150));

        gridLayout->addWidget(pushButtonSet, 1, 2, 1, 2);

        widgetSave = new QWidget(WgtHomeClass);
        widgetSave->setObjectName("widgetSave");
        widgetSave->setMinimumSize(QSize(0, 0));
        widgetSave->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(widgetSave);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 30, 20, 20);
        label = new QLabel(widgetSave);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        progressBarMemory = new QProgressBar(widgetSave);
        progressBarMemory->setObjectName("progressBarMemory");
        progressBarMemory->setMinimumSize(QSize(0, 40));
        progressBarMemory->setMaximumSize(QSize(16777215, 80));
        progressBarMemory->setValue(24);
        progressBarMemory->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(progressBarMemory);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalSpacer = new QSpacerItem(40, 1, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widgetSave, 2, 0, 1, 1);

        widgetNet = new QWidget(WgtHomeClass);
        widgetNet->setObjectName("widgetNet");
        widgetNet->setMinimumSize(QSize(0, 0));
        widgetNet->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(widgetNet);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 30, 20, 20);
        label_2 = new QLabel(widgetNet);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        labelWifi = new QLabel(widgetNet);
        labelWifi->setObjectName("labelWifi");

        verticalLayout_2->addWidget(labelWifi);

        label4g = new QLabel(widgetNet);
        label4g->setObjectName("label4g");

        verticalLayout_2->addWidget(label4g);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 1, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widgetNet, 2, 1, 1, 1);

        widgetDevice = new QWidget(WgtHomeClass);
        widgetDevice->setObjectName("widgetDevice");
        widgetDevice->setMinimumSize(QSize(0, 0));
        widgetDevice->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(widgetDevice);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(20, 30, 20, 20);
        label_3 = new QLabel(widgetDevice);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(label_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        labelUSBCamera = new QLabel(widgetDevice);
        labelUSBCamera->setObjectName("labelUSBCamera");

        verticalLayout_3->addWidget(labelUSBCamera);

        labelNetCamera = new QLabel(widgetDevice);
        labelNetCamera->setObjectName("labelNetCamera");

        verticalLayout_3->addWidget(labelNetCamera);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalSpacer_3 = new QSpacerItem(40, 1, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addWidget(widgetDevice, 2, 2, 1, 1);

        widgetSys = new QWidget(WgtHomeClass);
        widgetSys->setObjectName("widgetSys");
        widgetSys->setMinimumSize(QSize(0, 0));
        widgetSys->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_4 = new QVBoxLayout(widgetSys);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(20, 20, 20, 20);
        label_4 = new QLabel(widgetSys);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(label_4);

        progressBarSound = new QProgressBar(widgetSys);
        progressBarSound->setObjectName("progressBarSound");
        progressBarSound->setMinimumSize(QSize(0, 40));
        progressBarSound->setMaximumSize(QSize(16777215, 80));
        progressBarSound->setValue(24);
        progressBarSound->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(progressBarSound);

        label_5 = new QLabel(widgetSys);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(label_5);

        progressBarBrightness = new QProgressBar(widgetSys);
        progressBarBrightness->setObjectName("progressBarBrightness");
        progressBarBrightness->setMinimumSize(QSize(0, 40));
        progressBarBrightness->setMaximumSize(QSize(16777215, 80));
        progressBarBrightness->setValue(24);
        progressBarBrightness->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(progressBarBrightness);

        horizontalSpacer_4 = new QSpacerItem(40, 1, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_4);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_7);


        gridLayout->addWidget(widgetSys, 2, 3, 1, 1);


        retranslateUi(WgtHomeClass);

        QMetaObject::connectSlotsByName(WgtHomeClass);
    } // setupUi

    void retranslateUi(QWidget *WgtHomeClass)
    {
        WgtHomeClass->setWindowTitle(QCoreApplication::translate("WgtHomeClass", "WgtHome", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("WgtHomeClass", "\347\231\273\350\256\260", nullptr));
        pushButtonVerify->setText(QCoreApplication::translate("WgtHomeClass", "\351\252\214\350\257\201", nullptr));
        pushButtonProgress->setText(QCoreApplication::translate("WgtHomeClass", "\350\277\233\345\272\246", nullptr));
        pushButtonSet->setText(QCoreApplication::translate("WgtHomeClass", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("WgtHomeClass", "\345\255\230\345\202\250", nullptr));
        label_2->setText(QCoreApplication::translate("WgtHomeClass", "\347\275\221\347\273\234", nullptr));
        labelWifi->setText(QCoreApplication::translate("WgtHomeClass", "\345\267\262\350\277\236\357\274\232TP-Link_01", nullptr));
        label4g->setText(QCoreApplication::translate("WgtHomeClass", "\345\267\262\350\277\236\357\274\232\344\270\255\345\233\275\347\247\273\345\212\2504G", nullptr));
        label_3->setText(QCoreApplication::translate("WgtHomeClass", "\350\277\236\346\216\245", nullptr));
        labelUSBCamera->setText(QCoreApplication::translate("WgtHomeClass", "\345\267\262\350\277\236\357\274\232\345\205\250\346\231\257\346\221\204\345\203\217", nullptr));
        labelNetCamera->setText(QCoreApplication::translate("WgtHomeClass", "\345\267\262\350\277\236\357\274\232\346\230\276\345\276\256\346\221\204\345\203\217", nullptr));
        label_4->setText(QCoreApplication::translate("WgtHomeClass", "\351\237\263\351\207\217", nullptr));
        progressBarSound->setFormat(QCoreApplication::translate("WgtHomeClass", "%p", nullptr));
        label_5->setText(QCoreApplication::translate("WgtHomeClass", "\344\272\256\345\272\246", nullptr));
        progressBarBrightness->setFormat(QCoreApplication::translate("WgtHomeClass", "%p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtHomeClass: public Ui_WgtHomeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTHOME_H
