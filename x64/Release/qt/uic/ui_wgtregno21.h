/********************************************************************************
** Form generated from reading UI file 'wgtregno21.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGNO21_H
#define UI_WGTREGNO21_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_WgtRegNo21Class
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButtonCrosshair;
    QToolButton *toolButtonPhoto;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *WgtRegNo21Class)
    {
        if (WgtRegNo21Class->objectName().isEmpty())
            WgtRegNo21Class->setObjectName("WgtRegNo21Class");
        WgtRegNo21Class->resize(893, 532);
        gridLayout = new QGridLayout(WgtRegNo21Class);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 20);
        toolButtonCrosshair = new QToolButton(WgtRegNo21Class);
        toolButtonCrosshair->setObjectName("toolButtonCrosshair");
        toolButtonCrosshair->setMinimumSize(QSize(127, 127));
        toolButtonCrosshair->setMaximumSize(QSize(127, 127));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/crosshair.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonCrosshair->setIcon(icon);
        toolButtonCrosshair->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonCrosshair, 0, 1, 1, 1);

        toolButtonPhoto = new QToolButton(WgtRegNo21Class);
        toolButtonPhoto->setObjectName("toolButtonPhoto");
        toolButtonPhoto->setMinimumSize(QSize(127, 127));
        toolButtonPhoto->setMaximumSize(QSize(127, 127));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/photo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonPhoto->setIcon(icon1);
        toolButtonPhoto->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonPhoto, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 2, 1);


        retranslateUi(WgtRegNo21Class);

        QMetaObject::connectSlotsByName(WgtRegNo21Class);
    } // setupUi

    void retranslateUi(QDialog *WgtRegNo21Class)
    {
        WgtRegNo21Class->setWindowTitle(QCoreApplication::translate("WgtRegNo21Class", "WgtRegNo21", nullptr));
        toolButtonCrosshair->setText(QCoreApplication::translate("WgtRegNo21Class", "PushButton", nullptr));
        toolButtonPhoto->setText(QCoreApplication::translate("WgtRegNo21Class", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtRegNo21Class: public Ui_WgtRegNo21Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGNO21_H
