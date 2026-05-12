/********************************************************************************
** Form generated from reading UI file 'wgtsetnetcamera.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTSETNETCAMERA_H
#define UI_WGTSETNETCAMERA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_WgtSetNetCameraClass
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButtonDlgClose;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEditLowZoom;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QLineEdit *lineEditHighZoom;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonYes;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *WgtSetNetCameraClass)
    {
        if (WgtSetNetCameraClass->objectName().isEmpty())
            WgtSetNetCameraClass->setObjectName("WgtSetNetCameraClass");
        WgtSetNetCameraClass->resize(600, 400);
        gridLayout = new QGridLayout(WgtSetNetCameraClass);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        toolButtonDlgClose = new QToolButton(WgtSetNetCameraClass);
        toolButtonDlgClose->setObjectName("toolButtonDlgClose");
        toolButtonDlgClose->setMinimumSize(QSize(40, 40));
        toolButtonDlgClose->setMaximumSize(QSize(40, 40));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        toolButtonDlgClose->setIcon(icon);
        toolButtonDlgClose->setIconSize(QSize(30, 30));

        gridLayout->addWidget(toolButtonDlgClose, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(WgtSetNetCameraClass);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 50));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        lineEditLowZoom = new QLineEdit(WgtSetNetCameraClass);
        lineEditLowZoom->setObjectName("lineEditLowZoom");
        lineEditLowZoom->setMinimumSize(QSize(0, 50));
        lineEditLowZoom->setSizeIncrement(QSize(0, 0));
        lineEditLowZoom->setMaxLength(32767);
        lineEditLowZoom->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEditLowZoom, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        label_2 = new QLabel(WgtSetNetCameraClass);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        lineEditHighZoom = new QLineEdit(WgtSetNetCameraClass);
        lineEditHighZoom->setObjectName("lineEditHighZoom");
        lineEditHighZoom->setMinimumSize(QSize(0, 50));
        lineEditHighZoom->setSizeIncrement(QSize(0, 0));
        lineEditHighZoom->setMaxLength(32767);
        lineEditHighZoom->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEditHighZoom, 2, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonYes = new QPushButton(WgtSetNetCameraClass);
        pushButtonYes->setObjectName("pushButtonYes");
        pushButtonYes->setMinimumSize(QSize(200, 70));
        pushButtonYes->setMaximumSize(QSize(200, 70));

        horizontalLayout->addWidget(pushButtonYes);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 4);


        retranslateUi(WgtSetNetCameraClass);
        QObject::connect(toolButtonDlgClose, &QToolButton::clicked, WgtSetNetCameraClass, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(WgtSetNetCameraClass);
    } // setupUi

    void retranslateUi(QDialog *WgtSetNetCameraClass)
    {
        WgtSetNetCameraClass->setWindowTitle(QCoreApplication::translate("WgtSetNetCameraClass", "WgtSetNetCamera", nullptr));
        toolButtonDlgClose->setText(QString());
        label->setText(QCoreApplication::translate("WgtSetNetCameraClass", "\344\275\216\345\200\215", nullptr));
        lineEditLowZoom->setInputMask(QString());
        label_2->setText(QCoreApplication::translate("WgtSetNetCameraClass", "\351\253\230\345\200\215", nullptr));
        lineEditHighZoom->setInputMask(QString());
        pushButtonYes->setText(QCoreApplication::translate("WgtSetNetCameraClass", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtSetNetCameraClass: public Ui_WgtSetNetCameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTSETNETCAMERA_H
