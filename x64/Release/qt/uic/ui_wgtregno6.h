/********************************************************************************
** Form generated from reading UI file 'wgtregno6.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGNO6_H
#define UI_WGTREGNO6_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtRegNo6Class
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonBtConnect;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonPrint;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonBackHome;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widgetCertificate;
    QGridLayout *gridLayout_2;
    QLabel *labelAgency;
    QLabel *labelGlobalNum;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelImage;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_12;
    QLabel *labelName;
    QLabel *labelRegTime;
    QLabel *labelHighNum;
    QLabel *label_11;
    QLabel *labelNumber;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_3;

    void setupUi(QWidget *WgtRegNo6Class)
    {
        if (WgtRegNo6Class->objectName().isEmpty())
            WgtRegNo6Class->setObjectName("WgtRegNo6Class");
        WgtRegNo6Class->resize(1280, 740);
        WgtRegNo6Class->setMinimumSize(QSize(1280, 740));
        WgtRegNo6Class->setMaximumSize(QSize(1280, 740));
        gridLayout = new QGridLayout(WgtRegNo6Class);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widgetTool = new QWidget(WgtRegNo6Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_3 = new QHBoxLayout(widgetTool);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButtonBtConnect = new QPushButton(widgetTool);
        pushButtonBtConnect->setObjectName("pushButtonBtConnect");
        pushButtonBtConnect->setMinimumSize(QSize(200, 70));

        horizontalLayout_3->addWidget(pushButtonBtConnect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonPrint = new QPushButton(widgetTool);
        pushButtonPrint->setObjectName("pushButtonPrint");
        pushButtonPrint->setMinimumSize(QSize(200, 70));

        horizontalLayout_3->addWidget(pushButtonPrint);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonBackHome = new QPushButton(widgetTool);
        pushButtonBackHome->setObjectName("pushButtonBackHome");
        pushButtonBackHome->setMinimumSize(QSize(200, 70));

        horizontalLayout_3->addWidget(pushButtonBackHome);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widgetTool, 1, 0, 1, 4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 3, 1, 1);

        widgetCertificate = new QWidget(WgtRegNo6Class);
        widgetCertificate->setObjectName("widgetCertificate");
        widgetCertificate->setMinimumSize(QSize(412, 612));
        widgetCertificate->setMaximumSize(QSize(412, 612));
        gridLayout_2 = new QGridLayout(widgetCertificate);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(6);
        gridLayout_2->setContentsMargins(15, 40, 15, 40);
        labelAgency = new QLabel(widgetCertificate);
        labelAgency->setObjectName("labelAgency");
        labelAgency->setWordWrap(true);

        gridLayout_2->addWidget(labelAgency, 6, 1, 1, 1);

        labelGlobalNum = new QLabel(widgetCertificate);
        labelGlobalNum->setObjectName("labelGlobalNum");
        labelGlobalNum->setWordWrap(true);
        labelGlobalNum->setOpenExternalLinks(true);

        gridLayout_2->addWidget(labelGlobalNum, 7, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        labelImage = new QLabel(widgetCertificate);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(150, 150));
        labelImage->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(labelImage);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 2);

        label_8 = new QLabel(widgetCertificate);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(110, 16777215));
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_8, 5, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_12, 2, 0, 1, 2);

        labelName = new QLabel(widgetCertificate);
        labelName->setObjectName("labelName");
        labelName->setScaledContents(false);
        labelName->setWordWrap(true);
        labelName->setOpenExternalLinks(false);

        gridLayout_2->addWidget(labelName, 3, 1, 1, 1);

        labelRegTime = new QLabel(widgetCertificate);
        labelRegTime->setObjectName("labelRegTime");
        labelRegTime->setWordWrap(true);

        gridLayout_2->addWidget(labelRegTime, 5, 1, 1, 1);

        labelHighNum = new QLabel(widgetCertificate);
        labelHighNum->setObjectName("labelHighNum");
        labelHighNum->setWordWrap(true);

        gridLayout_2->addWidget(labelHighNum, 8, 1, 1, 1);

        label_11 = new QLabel(widgetCertificate);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(110, 16777215));
        label_11->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_11, 8, 0, 1, 1);

        labelNumber = new QLabel(widgetCertificate);
        labelNumber->setObjectName("labelNumber");
        labelNumber->setWordWrap(true);

        gridLayout_2->addWidget(labelNumber, 4, 1, 1, 1);

        label = new QLabel(widgetCertificate);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(widgetCertificate);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(110, 16777215));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        label_9 = new QLabel(widgetCertificate);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(110, 16777215));
        label_9->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_9, 6, 0, 1, 1);

        label_10 = new QLabel(widgetCertificate);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(110, 16777215));
        label_10->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_10, 7, 0, 1, 1);

        label_3 = new QLabel(widgetCertificate);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(110, 16777215));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);


        gridLayout->addWidget(widgetCertificate, 0, 1, 1, 1);


        retranslateUi(WgtRegNo6Class);

        QMetaObject::connectSlotsByName(WgtRegNo6Class);
    } // setupUi

    void retranslateUi(QWidget *WgtRegNo6Class)
    {
        WgtRegNo6Class->setWindowTitle(QCoreApplication::translate("WgtRegNo6Class", "WgtRegNo6", nullptr));
        pushButtonBtConnect->setText(QCoreApplication::translate("WgtRegNo6Class", "\350\223\235\347\211\231\350\277\236\346\216\245", nullptr));
        pushButtonPrint->setText(QCoreApplication::translate("WgtRegNo6Class", "\346\211\223\345\215\260", nullptr));
        pushButtonBackHome->setText(QCoreApplication::translate("WgtRegNo6Class", "\350\277\224\345\233\236\344\270\273\351\241\265", nullptr));
        labelAgency->setText(QString());
        labelGlobalNum->setText(QString());
        labelImage->setText(QString());
        label_8->setText(QCoreApplication::translate("WgtRegNo6Class", "\347\231\273\350\256\260\346\227\266\351\227\264:", nullptr));
        labelName->setText(QString());
        labelRegTime->setText(QString());
        labelHighNum->setText(QString());
        label_11->setText(QCoreApplication::translate("WgtRegNo6Class", "\346\230\276\345\276\256\351\207\207\351\233\206:", nullptr));
        labelNumber->setText(QString());
        label->setText(QCoreApplication::translate("WgtRegNo6Class", "PD\344\276\277\346\220\272\347\231\273\350\256\260", nullptr));
        label_7->setText(QCoreApplication::translate("WgtRegNo6Class", "\347\274\226       \345\217\267:", nullptr));
        label_9->setText(QCoreApplication::translate("WgtRegNo6Class", "\347\231\273\350\256\260\346\234\272\346\236\204:", nullptr));
        label_10->setText(QCoreApplication::translate("WgtRegNo6Class", "\345\205\250\345\261\200\351\207\207\351\233\206:", nullptr));
        label_3->setText(QCoreApplication::translate("WgtRegNo6Class", "\345\220\215       \347\247\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtRegNo6Class: public Ui_WgtRegNo6Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGNO6_H
