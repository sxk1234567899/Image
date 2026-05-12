/********************************************************************************
** Form generated from reading UI file 'wgtmain.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTMAIN_H
#define UI_WGTMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtMainClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetTopHome;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonHome;
    QLabel *label;
    QPushButton *pushButtonBack;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *labelName;
    QSpacerItem *horizontalSpacer;
    QLabel *labelLogInfo;
    QWidget *widgetTopQuit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPushButton *pushButtonLogOut;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QLabel *labelBatt;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *WgtMainClass)
    {
        if (WgtMainClass->objectName().isEmpty())
            WgtMainClass->setObjectName("WgtMainClass");
        WgtMainClass->resize(1280, 800);
        verticalLayout = new QVBoxLayout(WgtMainClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTop = new QWidget(WgtMainClass);
        widgetTop->setObjectName("widgetTop");
        widgetTop->setMinimumSize(QSize(0, 60));
        widgetTop->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(widgetTop);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        widgetTopHome = new QWidget(widgetTop);
        widgetTopHome->setObjectName("widgetTopHome");
        widgetTopHome->setMinimumSize(QSize(210, 0));
        horizontalLayout_2 = new QHBoxLayout(widgetTopHome);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonHome = new QPushButton(widgetTopHome);
        pushButtonHome->setObjectName("pushButtonHome");
        pushButtonHome->setMinimumSize(QSize(100, 60));
        pushButtonHome->setMaximumSize(QSize(100, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonHome->setIcon(icon);
        pushButtonHome->setIconSize(QSize(31, 28));

        horizontalLayout_2->addWidget(pushButtonHome);

        label = new QLabel(widgetTopHome);
        label->setObjectName("label");
        label->setMinimumSize(QSize(1, 32));
        label->setMaximumSize(QSize(1, 32));

        horizontalLayout_2->addWidget(label);

        pushButtonBack = new QPushButton(widgetTopHome);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setMinimumSize(QSize(100, 60));
        pushButtonBack->setMaximumSize(QSize(100, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/backicon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonBack->setIcon(icon1);
        pushButtonBack->setIconSize(QSize(33, 30));

        horizontalLayout_2->addWidget(pushButtonBack);

        label_3 = new QLabel(widgetTopHome);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(1, 32));
        label_3->setMaximumSize(QSize(1, 32));

        horizontalLayout_2->addWidget(label_3);


        horizontalLayout->addWidget(widgetTopHome);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        labelName = new QLabel(widgetTop);
        labelName->setObjectName("labelName");
        labelName->setMinimumSize(QSize(400, 0));
        labelName->setMaximumSize(QSize(400, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font.setBold(true);
        font.setItalic(false);
        labelName->setFont(font);
        labelName->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(labelName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelLogInfo = new QLabel(widgetTop);
        labelLogInfo->setObjectName("labelLogInfo");
        labelLogInfo->setMinimumSize(QSize(300, 0));
        labelLogInfo->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font1.setBold(false);
        font1.setItalic(false);
        labelLogInfo->setFont(font1);
        labelLogInfo->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(labelLogInfo);

        widgetTopQuit = new QWidget(widgetTop);
        widgetTopQuit->setObjectName("widgetTopQuit");
        horizontalLayout_3 = new QHBoxLayout(widgetTopQuit);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widgetTopQuit);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(1, 32));
        label_2->setMaximumSize(QSize(1, 32));

        horizontalLayout_3->addWidget(label_2);

        pushButtonLogOut = new QPushButton(widgetTopQuit);
        pushButtonLogOut->setObjectName("pushButtonLogOut");
        pushButtonLogOut->setMinimumSize(QSize(100, 60));
        pushButtonLogOut->setMaximumSize(QSize(100, 60));

        horizontalLayout_3->addWidget(pushButtonLogOut);

        label_4 = new QLabel(widgetTopQuit);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(1, 32));
        label_4->setMaximumSize(QSize(1, 32));

        horizontalLayout_3->addWidget(label_4);


        horizontalLayout->addWidget(widgetTopQuit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        timeEdit = new QTimeEdit(widgetTop);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setMinimumSize(QSize(100, 30));
        timeEdit->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        timeEdit->setFont(font2);
        timeEdit->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        timeEdit->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);
        timeEdit->setReadOnly(true);
        timeEdit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        verticalLayout_2->addWidget(timeEdit);

        dateEdit = new QDateEdit(widgetTop);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setMinimumSize(QSize(100, 30));
        dateEdit->setMaximumSize(QSize(100, 30));
        dateEdit->setFont(font2);
        dateEdit->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        dateEdit->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        dateEdit->setReadOnly(true);
        dateEdit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        verticalLayout_2->addWidget(dateEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        labelBatt = new QLabel(widgetTop);
        labelBatt->setObjectName("labelBatt");
        labelBatt->setMinimumSize(QSize(48, 32));
        labelBatt->setMaximumSize(QSize(48, 32));

        horizontalLayout->addWidget(labelBatt);


        verticalLayout->addWidget(widgetTop);

        stackedWidget = new QStackedWidget(WgtMainClass);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(WgtMainClass);

        QMetaObject::connectSlotsByName(WgtMainClass);
    } // setupUi

    void retranslateUi(QWidget *WgtMainClass)
    {
        WgtMainClass->setWindowTitle(QCoreApplication::translate("WgtMainClass", "WgtMain", nullptr));
        pushButtonHome->setText(QString());
        label->setText(QString());
        pushButtonBack->setText(QString());
        label_3->setText(QString());
        labelName->setText(QCoreApplication::translate("WgtMainClass", "\345\217\257\347\247\273\345\212\250\346\226\207\347\211\251\346\225\260\345\255\227\347\231\273\350\256\260\351\252\214\350\257\201\347\263\273\347\273\237\342\200\224\342\200\224\351\246\226\351\241\265", nullptr));
        labelLogInfo->setText(QCoreApplication::translate("WgtMainClass", "\345\274\240\344\270\211", nullptr));
        label_2->setText(QString());
        pushButtonLogOut->setText(QCoreApplication::translate("WgtMainClass", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        label_4->setText(QString());
        timeEdit->setDisplayFormat(QCoreApplication::translate("WgtMainClass", "hh:mm", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("WgtMainClass", "yyyy-MM-dd", nullptr));
        labelBatt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtMainClass: public Ui_WgtMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTMAIN_H
