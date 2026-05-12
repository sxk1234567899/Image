/********************************************************************************
** Form generated from reading UI file 'wgtregno41.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGNO41_H
#define UI_WGTREGNO41_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_WgtRegNo41Class
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButtonCrosshair;
    QToolButton *toolButtonFocus;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonManualFocus;
    QToolButton *toolButtonFocusAdd;
    QToolButton *toolButtonFocusSub;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *WgtRegNo41Class)
    {
        if (WgtRegNo41Class->objectName().isEmpty())
            WgtRegNo41Class->setObjectName("WgtRegNo41Class");
        WgtRegNo41Class->resize(850, 452);
        gridLayout = new QGridLayout(WgtRegNo41Class);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 20);
        toolButtonCrosshair = new QToolButton(WgtRegNo41Class);
        toolButtonCrosshair->setObjectName("toolButtonCrosshair");
        toolButtonCrosshair->setMinimumSize(QSize(127, 127));
        toolButtonCrosshair->setMaximumSize(QSize(127, 127));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/crosshair.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonCrosshair->setIcon(icon);
        toolButtonCrosshair->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonCrosshair, 1, 1, 1, 1);

        toolButtonFocus = new QToolButton(WgtRegNo41Class);
        toolButtonFocus->setObjectName("toolButtonFocus");
        toolButtonFocus->setMinimumSize(QSize(127, 127));
        toolButtonFocus->setMaximumSize(QSize(127, 127));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/focus.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonFocus->setIcon(icon1);
        toolButtonFocus->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonFocus, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 3, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 0, 0, -1);
        toolButtonManualFocus = new QToolButton(WgtRegNo41Class);
        toolButtonManualFocus->setObjectName("toolButtonManualFocus");
        toolButtonManualFocus->setMinimumSize(QSize(71, 60));
        toolButtonManualFocus->setMaximumSize(QSize(71, 60));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/image/4.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        toolButtonManualFocus->setIcon(icon2);
        toolButtonManualFocus->setIconSize(QSize(128, 96));
        toolButtonManualFocus->setCheckable(true);

        horizontalLayout_2->addWidget(toolButtonManualFocus);

        toolButtonFocusAdd = new QToolButton(WgtRegNo41Class);
        toolButtonFocusAdd->setObjectName("toolButtonFocusAdd");
        toolButtonFocusAdd->setMinimumSize(QSize(60, 60));
        toolButtonFocusAdd->setMaximumSize(QSize(60, 60));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonFocusAdd->setIcon(icon3);
        toolButtonFocusAdd->setIconSize(QSize(96, 96));

        horizontalLayout_2->addWidget(toolButtonFocusAdd);

        toolButtonFocusSub = new QToolButton(WgtRegNo41Class);
        toolButtonFocusSub->setObjectName("toolButtonFocusSub");
        toolButtonFocusSub->setMinimumSize(QSize(60, 60));
        toolButtonFocusSub->setMaximumSize(QSize(60, 60));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonFocusSub->setIcon(icon4);
        toolButtonFocusSub->setIconSize(QSize(96, 96));

        horizontalLayout_2->addWidget(toolButtonFocusSub);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 2);


        retranslateUi(WgtRegNo41Class);

        QMetaObject::connectSlotsByName(WgtRegNo41Class);
    } // setupUi

    void retranslateUi(QDialog *WgtRegNo41Class)
    {
        WgtRegNo41Class->setWindowTitle(QCoreApplication::translate("WgtRegNo41Class", "WgtVerifyNo31", nullptr));
        toolButtonCrosshair->setText(QCoreApplication::translate("WgtRegNo41Class", "PushButton", nullptr));
        toolButtonFocus->setText(QCoreApplication::translate("WgtRegNo41Class", "PushButton", nullptr));
        toolButtonManualFocus->setText(QString());
        toolButtonFocusAdd->setText(QString());
        toolButtonFocusSub->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtRegNo41Class: public Ui_WgtRegNo41Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGNO41_H
