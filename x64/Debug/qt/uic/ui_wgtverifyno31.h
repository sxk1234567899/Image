/********************************************************************************
** Form generated from reading UI file 'wgtverifyno31.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO31_H
#define UI_WGTVERIFYNO31_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo31Class
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButtonRefImage;
    QToolButton *toolButtonPhoto;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *WgtVerifyNo31Class)
    {
        if (WgtVerifyNo31Class->objectName().isEmpty())
            WgtVerifyNo31Class->setObjectName("WgtVerifyNo31Class");
        WgtVerifyNo31Class->resize(600, 400);
        gridLayout = new QGridLayout(WgtVerifyNo31Class);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 20);
        toolButtonRefImage = new QToolButton(WgtVerifyNo31Class);
        toolButtonRefImage->setObjectName("toolButtonRefImage");
        toolButtonRefImage->setMinimumSize(QSize(127, 127));
        toolButtonRefImage->setMaximumSize(QSize(127, 127));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/refImage.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonRefImage->setIcon(icon);
        toolButtonRefImage->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonRefImage, 1, 1, 1, 1);

        toolButtonPhoto = new QToolButton(WgtVerifyNo31Class);
        toolButtonPhoto->setObjectName("toolButtonPhoto");
        toolButtonPhoto->setMinimumSize(QSize(127, 127));
        toolButtonPhoto->setMaximumSize(QSize(127, 127));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/photo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonPhoto->setIcon(icon1);
        toolButtonPhoto->setIconSize(QSize(127, 127));

        gridLayout->addWidget(toolButtonPhoto, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 3, 1);


        retranslateUi(WgtVerifyNo31Class);

        QMetaObject::connectSlotsByName(WgtVerifyNo31Class);
    } // setupUi

    void retranslateUi(QDialog *WgtVerifyNo31Class)
    {
        WgtVerifyNo31Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo31Class", "WgtVerifyNo31", nullptr));
        toolButtonRefImage->setText(QCoreApplication::translate("WgtVerifyNo31Class", "PushButton", nullptr));
        toolButtonPhoto->setText(QCoreApplication::translate("WgtVerifyNo31Class", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo31Class: public Ui_WgtVerifyNo31Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO31_H
