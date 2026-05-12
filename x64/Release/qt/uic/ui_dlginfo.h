/********************************************************************************
** Form generated from reading UI file 'dlginfo.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGINFO_H
#define UI_DLGINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DlgInfoClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonYes;
    QPushButton *pushButtonNo;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelTitle;
    QToolButton *toolButtonDlgClose;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelContent;

    void setupUi(QDialog *DlgInfoClass)
    {
        if (DlgInfoClass->objectName().isEmpty())
            DlgInfoClass->setObjectName("DlgInfoClass");
        DlgInfoClass->resize(600, 400);
        DlgInfoClass->setMinimumSize(QSize(600, 400));
        DlgInfoClass->setMaximumSize(QSize(600, 400));
        gridLayout = new QGridLayout(DlgInfoClass);
        gridLayout->setSpacing(20);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 7);

        pushButtonYes = new QPushButton(DlgInfoClass);
        pushButtonYes->setObjectName("pushButtonYes");
        pushButtonYes->setMinimumSize(QSize(200, 70));
        pushButtonYes->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonYes, 4, 2, 1, 1);

        pushButtonNo = new QPushButton(DlgInfoClass);
        pushButtonNo->setObjectName("pushButtonNo");
        pushButtonNo->setMinimumSize(QSize(200, 70));
        pushButtonNo->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonNo, 4, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(26, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(26, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 1, 1, 1);

        labelTitle = new QLabel(DlgInfoClass);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(0, 50));
        labelTitle->setMaximumSize(QSize(16777215, 50));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelTitle, 2, 0, 1, 7);

        toolButtonDlgClose = new QToolButton(DlgInfoClass);
        toolButtonDlgClose->setObjectName("toolButtonDlgClose");
        toolButtonDlgClose->setMinimumSize(QSize(40, 40));
        toolButtonDlgClose->setMaximumSize(QSize(40, 40));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        toolButtonDlgClose->setIcon(icon);
        toolButtonDlgClose->setIconSize(QSize(30, 30));

        gridLayout->addWidget(toolButtonDlgClose, 0, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(543, 27, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(26, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 7);

        horizontalSpacer_5 = new QSpacerItem(27, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 5, 1, 2);

        labelContent = new QLabel(DlgInfoClass);
        labelContent->setObjectName("labelContent");
        labelContent->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelContent, 3, 0, 1, 7);


        retranslateUi(DlgInfoClass);
        QObject::connect(pushButtonYes, &QPushButton::clicked, DlgInfoClass, qOverload<>(&QDialog::close));
        QObject::connect(pushButtonNo, &QPushButton::clicked, DlgInfoClass, qOverload<>(&QDialog::close));
        QObject::connect(toolButtonDlgClose, &QToolButton::clicked, DlgInfoClass, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(DlgInfoClass);
    } // setupUi

    void retranslateUi(QDialog *DlgInfoClass)
    {
        DlgInfoClass->setWindowTitle(QCoreApplication::translate("DlgInfoClass", "Dialog", nullptr));
        pushButtonYes->setText(QCoreApplication::translate("DlgInfoClass", "PushButton", nullptr));
        pushButtonNo->setText(QCoreApplication::translate("DlgInfoClass", "PushButton", nullptr));
        labelTitle->setText(QCoreApplication::translate("DlgInfoClass", "TextLabel", nullptr));
        toolButtonDlgClose->setText(QString());
        labelContent->setText(QCoreApplication::translate("DlgInfoClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgInfoClass: public Ui_DlgInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGINFO_H
