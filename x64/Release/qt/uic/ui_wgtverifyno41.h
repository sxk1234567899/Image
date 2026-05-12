/********************************************************************************
** Form generated from reading UI file 'wgtverifyno41.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO41_H
#define UI_WGTVERIFYNO41_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo41Class
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButtonRefImage;
    QToolButton *toolButtonFocus;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonManualFocus;
    QToolButton *toolButtonFocusAdd;
    QToolButton *toolButtonFocusSub;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *WgtVerifyNo41Class)
    {
        if (WgtVerifyNo41Class->objectName().isEmpty())
            WgtVerifyNo41Class->setObjectName("WgtVerifyNo41Class");
        WgtVerifyNo41Class->resize(600, 400);
        gridLayout = new QGridLayout(WgtVerifyNo41Class);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 20);
        toolButtonRefImage = new QToolButton(WgtVerifyNo41Class);
        toolButtonRefImage->setObjectName("toolButtonRefImage");
        toolButtonRefImage->setMinimumSize(QSize(127, 127));
        toolButtonRefImage->setMaximumSize(QSize(127, 127));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/refImage.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonRefImage->setIcon(icon);
        toolButtonRefImage->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonRefImage, 1, 1, 1, 1);

        toolButtonFocus = new QToolButton(WgtVerifyNo41Class);
        toolButtonFocus->setObjectName("toolButtonFocus");
        toolButtonFocus->setMinimumSize(QSize(127, 127));
        toolButtonFocus->setMaximumSize(QSize(127, 127));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/focus.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonFocus->setIcon(icon1);
        toolButtonFocus->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonFocus, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 0, 0, -1);
        toolButtonManualFocus = new QToolButton(WgtVerifyNo41Class);
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

        toolButtonFocusAdd = new QToolButton(WgtVerifyNo41Class);
        toolButtonFocusAdd->setObjectName("toolButtonFocusAdd");
        toolButtonFocusAdd->setMinimumSize(QSize(60, 60));
        toolButtonFocusAdd->setMaximumSize(QSize(60, 60));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonFocusAdd->setIcon(icon3);
        toolButtonFocusAdd->setIconSize(QSize(96, 96));

        horizontalLayout_2->addWidget(toolButtonFocusAdd);

        toolButtonFocusSub = new QToolButton(WgtVerifyNo41Class);
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


        retranslateUi(WgtVerifyNo41Class);

        QMetaObject::connectSlotsByName(WgtVerifyNo41Class);
    } // setupUi

    void retranslateUi(QDialog *WgtVerifyNo41Class)
    {
        WgtVerifyNo41Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo41Class", "WgtVerifyNo31", nullptr));
        toolButtonRefImage->setText(QCoreApplication::translate("WgtVerifyNo41Class", "PushButton", nullptr));
        toolButtonFocus->setText(QCoreApplication::translate("WgtVerifyNo41Class", "PushButton", nullptr));
        toolButtonManualFocus->setText(QString());
        toolButtonFocusAdd->setText(QString());
        toolButtonFocusSub->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo41Class: public Ui_WgtVerifyNo41Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO41_H
