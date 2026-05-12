/********************************************************************************
** Form generated from reading UI file 'wgtlogo.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTLOGO_H
#define UI_WGTLOGO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtLogoClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditUserName;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelPhone;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelTitle;
    QPushButton *pushButtonLogIn;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonSet;

    void setupUi(QWidget *WgtLogoClass)
    {
        if (WgtLogoClass->objectName().isEmpty())
            WgtLogoClass->setObjectName("WgtLogoClass");
        WgtLogoClass->resize(1920, 1080);
        verticalLayout = new QVBoxLayout(WgtLogoClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(WgtLogoClass);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 20);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        lineEditUserName = new QLineEdit(widget);
        lineEditUserName->setObjectName("lineEditUserName");
        lineEditUserName->setMinimumSize(QSize(400, 88));
        lineEditUserName->setMaximumSize(QSize(800, 88));
        lineEditUserName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEditUserName, 2, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        labelPhone = new QLabel(widget);
        labelPhone->setObjectName("labelPhone");
        labelPhone->setMinimumSize(QSize(27, 27));
        labelPhone->setMaximumSize(QSize(27, 27));
        labelPhone->setStyleSheet(QString::fromUtf8("image: url(:/image/phone_2x.png);"));

        horizontalLayout->addWidget(labelPhone);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 2, 1, 1);

        labelTitle = new QLabel(widget);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(800, 80));
        labelTitle->setMaximumSize(QSize(800, 80));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setBold(true);
        font.setItalic(false);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelTitle, 1, 1, 1, 2);

        pushButtonLogIn = new QPushButton(widget);
        pushButtonLogIn->setObjectName("pushButtonLogIn");
        pushButtonLogIn->setMinimumSize(QSize(400, 80));
        pushButtonLogIn->setMaximumSize(QSize(800, 80));

        gridLayout->addWidget(pushButtonLogIn, 4, 1, 1, 2);

        lineEditPassword = new QLineEdit(widget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setMinimumSize(QSize(400, 88));
        lineEditPassword->setMaximumSize(QSize(800, 88));
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);
        lineEditPassword->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEditPassword, 3, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pushButtonSet = new QPushButton(widget);
        pushButtonSet->setObjectName("pushButtonSet");
        pushButtonSet->setMinimumSize(QSize(70, 70));
        pushButtonSet->setMaximumSize(QSize(70, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/setting2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonSet->setIcon(icon);
        pushButtonSet->setIconSize(QSize(70, 70));

        horizontalLayout_2->addWidget(pushButtonSet);


        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 4);


        verticalLayout->addWidget(widget);


        retranslateUi(WgtLogoClass);

        QMetaObject::connectSlotsByName(WgtLogoClass);
    } // setupUi

    void retranslateUi(QWidget *WgtLogoClass)
    {
        WgtLogoClass->setWindowTitle(QCoreApplication::translate("WgtLogoClass", "WgtLogo", nullptr));
        lineEditUserName->setPlaceholderText(QCoreApplication::translate("WgtLogoClass", "\350\264\246\346\210\267", nullptr));
        labelPhone->setText(QString());
        label_3->setText(QCoreApplication::translate("WgtLogoClass", "\345\256\242\346\234\215\347\224\265\350\257\235\357\274\232010-53683609", nullptr));
        labelTitle->setText(QCoreApplication::translate("WgtLogoClass", "\350\264\246\346\210\267\345\257\206\347\240\201\347\231\273\345\275\225", nullptr));
        pushButtonLogIn->setText(QCoreApplication::translate("WgtLogoClass", "\347\231\273  \345\275\225", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("WgtLogoClass", "\345\257\206\347\240\201", nullptr));
        pushButtonSet->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtLogoClass: public Ui_WgtLogoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTLOGO_H
