/********************************************************************************
** Form generated from reading UI file 'dlginput.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGINPUT_H
#define UI_DLGINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DlgInputClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButtonDlgClose;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonNo;
    QSpacerItem *verticalSpacer;
    QLabel *labelTitle;
    QPushButton *pushButtonYes;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DlgInputClass)
    {
        if (DlgInputClass->objectName().isEmpty())
            DlgInputClass->setObjectName("DlgInputClass");
        DlgInputClass->resize(600, 400);
        DlgInputClass->setMinimumSize(QSize(600, 400));
        DlgInputClass->setMaximumSize(QSize(600, 400));
        gridLayout = new QGridLayout(DlgInputClass);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        horizontalSpacer_2 = new QSpacerItem(11, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        toolButtonDlgClose = new QToolButton(DlgInputClass);
        toolButtonDlgClose->setObjectName("toolButtonDlgClose");
        toolButtonDlgClose->setMinimumSize(QSize(40, 40));
        toolButtonDlgClose->setMaximumSize(QSize(40, 40));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        toolButtonDlgClose->setIcon(icon);
        toolButtonDlgClose->setIconSize(QSize(30, 30));

        gridLayout->addWidget(toolButtonDlgClose, 0, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(518, 27, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(11, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(57, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 5, 1, 2);

        pushButtonNo = new QPushButton(DlgInputClass);
        pushButtonNo->setObjectName("pushButtonNo");
        pushButtonNo->setMinimumSize(QSize(200, 70));
        pushButtonNo->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonNo, 4, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 54, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 7);

        labelTitle = new QLabel(DlgInputClass);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(0, 50));
        labelTitle->setMaximumSize(QSize(16777215, 50));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelTitle, 2, 0, 1, 7);

        pushButtonYes = new QPushButton(DlgInputClass);
        pushButtonYes->setObjectName("pushButtonYes");
        pushButtonYes->setMinimumSize(QSize(200, 70));
        pushButtonYes->setMaximumSize(QSize(200, 70));

        gridLayout->addWidget(pushButtonYes, 4, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(578, 26, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 7);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(578, 27, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 7);

        lineEdit = new QLineEdit(DlgInputClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 50));
        lineEdit->setMaximumSize(QSize(16777215, 50));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEdit, 3, 2, 1, 4);

        QWidget::setTabOrder(lineEdit, pushButtonYes);
        QWidget::setTabOrder(pushButtonYes, pushButtonNo);
        QWidget::setTabOrder(pushButtonNo, toolButtonDlgClose);

        retranslateUi(DlgInputClass);
        QObject::connect(toolButtonDlgClose, &QToolButton::clicked, DlgInputClass, qOverload<>(&QDialog::close));
        QObject::connect(pushButtonYes, &QPushButton::clicked, DlgInputClass, qOverload<>(&QDialog::close));
        QObject::connect(pushButtonNo, &QPushButton::clicked, DlgInputClass, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(DlgInputClass);
    } // setupUi

    void retranslateUi(QDialog *DlgInputClass)
    {
        DlgInputClass->setWindowTitle(QCoreApplication::translate("DlgInputClass", "DlgInput", nullptr));
        toolButtonDlgClose->setText(QString());
        pushButtonNo->setText(QCoreApplication::translate("DlgInputClass", "PushButton", nullptr));
        labelTitle->setText(QCoreApplication::translate("DlgInputClass", "TextLabel", nullptr));
        pushButtonYes->setText(QCoreApplication::translate("DlgInputClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgInputClass: public Ui_DlgInputClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGINPUT_H
