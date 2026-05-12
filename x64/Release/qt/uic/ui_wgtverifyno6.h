/********************************************************************************
** Form generated from reading UI file 'wgtverifyno6.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO6_H
#define UI_WGTVERIFYNO6_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo6Class
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonBackHome;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonReVerify;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QLabel *labelVerifyResult;
    QSpacerItem *horizontalSpacer_12;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelImage;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_9;
    QLabel *labelName;
    QLabel *labelVerifyTime;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *labelVerifyAgency;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_14;
    QLabel *labelSize;
    QLabel *labelTexture;
    QLabel *label;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelLevel;
    QLabel *labelRegTime;
    QLabel *labelAge;
    QLabel *labelAgency;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *labelExhibitionTitleKey;
    QLabel *labelCarrier;
    QLabel *labelApplicant;
    QLabel *labelDevice;
    QLabel *labelExhibitionTitle;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *GridLayoutImageView;

    void setupUi(QWidget *WgtVerifyNo6Class)
    {
        if (WgtVerifyNo6Class->objectName().isEmpty())
            WgtVerifyNo6Class->setObjectName("WgtVerifyNo6Class");
        WgtVerifyNo6Class->resize(1060, 609);
        gridLayout_2 = new QGridLayout(WgtVerifyNo6Class);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 10, 0, 0);
        widgetTool = new QWidget(WgtVerifyNo6Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_3 = new QHBoxLayout(widgetTool);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButtonBackHome = new QPushButton(widgetTool);
        pushButtonBackHome->setObjectName("pushButtonBackHome");
        pushButtonBackHome->setMinimumSize(QSize(370, 70));

        horizontalLayout_3->addWidget(pushButtonBackHome);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonReVerify = new QPushButton(widgetTool);
        pushButtonReVerify->setObjectName("pushButtonReVerify");
        pushButtonReVerify->setMinimumSize(QSize(370, 70));

        horizontalLayout_3->addWidget(pushButtonReVerify);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(widgetTool, 2, 0, 1, 1);

        scrollArea = new QScrollArea(WgtVerifyNo6Class);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1058, 487));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 55));
        widget->setMaximumSize(QSize(16777215, 55));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        labelVerifyResult = new QLabel(widget);
        labelVerifyResult->setObjectName("labelVerifyResult");
        labelVerifyResult->setMinimumSize(QSize(658, 55));
        labelVerifyResult->setMaximumSize(QSize(658, 55));
        labelVerifyResult->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(labelVerifyResult);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(0, 260));
        widget_3->setMaximumSize(QSize(16777215, 260));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 10, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        labelImage = new QLabel(widget_3);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(279, 157));
        labelImage->setMaximumSize(QSize(279, 157));

        horizontalLayout_2->addWidget(labelImage);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 3, 5, 1, 1);

        labelName = new QLabel(widget_4);
        labelName->setObjectName("labelName");
        labelName->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelName, 2, 0, 1, 8);

        labelVerifyTime = new QLabel(widget_4);
        labelVerifyTime->setObjectName("labelVerifyTime");
        labelVerifyTime->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelVerifyTime, 5, 7, 1, 1);

        label_16 = new QLabel(widget_4);
        label_16->setObjectName("label_16");
        label_16->setMinimumSize(QSize(100, 0));
        label_16->setMaximumSize(QSize(100, 16777215));
        label_16->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_16, 6, 6, 1, 1);

        label_15 = new QLabel(widget_4);
        label_15->setObjectName("label_15");
        label_15->setMinimumSize(QSize(100, 0));
        label_15->setMaximumSize(QSize(100, 16777215));
        label_15->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_15, 5, 6, 1, 1);

        labelVerifyAgency = new QLabel(widget_4);
        labelVerifyAgency->setObjectName("labelVerifyAgency");
        labelVerifyAgency->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelVerifyAgency, 6, 7, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 8, 0, 1, 8);

        label_14 = new QLabel(widget_4);
        label_14->setObjectName("label_14");
        label_14->setMinimumSize(QSize(100, 0));
        label_14->setMaximumSize(QSize(100, 16777215));
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_14, 4, 6, 1, 1);

        labelSize = new QLabel(widget_4);
        labelSize->setObjectName("labelSize");
        labelSize->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelSize, 3, 1, 1, 1);

        labelTexture = new QLabel(widget_4);
        labelTexture->setObjectName("labelTexture");
        labelTexture->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelTexture, 4, 1, 1, 1);

        label = new QLabel(widget_4);
        label->setObjectName("label");
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 16777215));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label, 6, 0, 1, 1);

        label_13 = new QLabel(widget_4);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(100, 0));
        label_13->setMaximumSize(QSize(100, 16777215));
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_13, 3, 6, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 2, 1, 1);

        labelLevel = new QLabel(widget_4);
        labelLevel->setObjectName("labelLevel");
        labelLevel->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelLevel, 6, 1, 1, 1);

        labelRegTime = new QLabel(widget_4);
        labelRegTime->setObjectName("labelRegTime");
        labelRegTime->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelRegTime, 4, 7, 1, 1);

        labelAge = new QLabel(widget_4);
        labelAge->setObjectName("labelAge");
        labelAge->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelAge, 5, 1, 1, 1);

        labelAgency = new QLabel(widget_4);
        labelAgency->setObjectName("labelAgency");
        labelAgency->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelAgency, 3, 7, 1, 1);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        label_7 = new QLabel(widget_4);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(100, 16777215));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_7, 3, 3, 1, 1);

        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(100, 0));
        label_8->setMaximumSize(QSize(100, 16777215));
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_8, 4, 3, 1, 1);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setMaximumSize(QSize(100, 16777215));
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_5, 5, 3, 1, 1);

        labelExhibitionTitleKey = new QLabel(widget_4);
        labelExhibitionTitleKey->setObjectName("labelExhibitionTitleKey");
        labelExhibitionTitleKey->setMinimumSize(QSize(100, 0));
        labelExhibitionTitleKey->setMaximumSize(QSize(100, 16777215));
        labelExhibitionTitleKey->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(labelExhibitionTitleKey, 6, 3, 1, 1);

        labelCarrier = new QLabel(widget_4);
        labelCarrier->setObjectName("labelCarrier");
        labelCarrier->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelCarrier, 3, 4, 1, 1);

        labelApplicant = new QLabel(widget_4);
        labelApplicant->setObjectName("labelApplicant");
        labelApplicant->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelApplicant, 4, 4, 1, 1);

        labelDevice = new QLabel(widget_4);
        labelDevice->setObjectName("labelDevice");
        labelDevice->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelDevice, 5, 4, 1, 1);

        labelExhibitionTitle = new QLabel(widget_4);
        labelExhibitionTitle->setObjectName("labelExhibitionTitle");
        labelExhibitionTitle->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelExhibitionTitle, 6, 4, 1, 1);


        horizontalLayout_2->addWidget(widget_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);


        verticalLayout->addWidget(widget_3);

        GridLayoutImageView = new QGridLayout();
        GridLayoutImageView->setSpacing(6);
        GridLayoutImageView->setObjectName("GridLayoutImageView");

        verticalLayout->addLayout(GridLayoutImageView);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 1);


        retranslateUi(WgtVerifyNo6Class);

        QMetaObject::connectSlotsByName(WgtVerifyNo6Class);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyNo6Class)
    {
        WgtVerifyNo6Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo6Class", "WgtVerifyNo6", nullptr));
        pushButtonBackHome->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\350\277\224\345\233\236\344\270\273\351\241\265", nullptr));
        pushButtonReVerify->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\351\207\215\346\226\260\351\252\214\350\257\201\346\234\254\344\273\266", nullptr));
        labelVerifyResult->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\346\257\224\345\257\271\345\256\214\346\210\220\357\274\214\345\205\250\345\261\200\347\233\270\344\274\274\345\272\246 99%\357\274\214\346\214\207\347\272\271\347\202\271\347\233\270\344\274\274\345\272\24699%", nullptr));
        labelImage->setText(QString());
        labelName->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\346\270\205\344\271\276\351\232\206\351\235\222\350\212\261\347\223\267\347\223\266", nullptr));
        labelVerifyTime->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\351\241\272\344\271\211\351\211\264\345\256\232\347\253\231", nullptr));
        label_16->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\346\234\254\346\254\241\351\252\214\350\257\201\347\273\204\347\273\207\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\346\234\254\346\254\241\351\252\214\350\257\201\346\227\266\351\227\264\357\274\232", nullptr));
        labelVerifyAgency->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\351\241\272\344\271\211\351\211\264\345\256\232\347\253\231", nullptr));
        label_14->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\347\231\273\350\256\260\346\227\266\351\227\264\357\274\232", nullptr));
        labelSize->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\351\253\23040cm\343\200\201\347\233\264\345\276\20430cm", nullptr));
        labelTexture->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\347\223\267\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\347\272\247\345\210\253\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\347\231\273\350\256\260\347\273\204\347\273\207\357\274\232", nullptr));
        labelLevel->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\344\272\214\347\272\247", nullptr));
        labelRegTime->setText(QCoreApplication::translate("WgtVerifyNo6Class", "0000-00-00 00:00", nullptr));
        labelAge->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\346\270\205\344\273\243", nullptr));
        labelAgency->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\351\241\272\344\271\211\351\211\264\345\256\232\347\253\231", nullptr));
        label_4->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\350\264\250\345\234\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\345\260\272\345\257\270\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\345\271\264\344\273\243\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\345\215\217 \350\277\220 \344\272\272 \357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\347\224\263 \350\257\267 \344\272\272 \357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\347\231\273\350\256\260\350\256\276\345\244\207\357\274\232", nullptr));
        labelExhibitionTitleKey->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\345\261\225 \350\247\210 \345\220\215 \357\274\232", nullptr));
        labelCarrier->setText(QCoreApplication::translate("WgtVerifyNo6Class", "xx", nullptr));
        labelApplicant->setText(QCoreApplication::translate("WgtVerifyNo6Class", "xx", nullptr));
        labelDevice->setText(QCoreApplication::translate("WgtVerifyNo6Class", "\344\276\277\346\220\272", nullptr));
        labelExhibitionTitle->setText(QCoreApplication::translate("WgtVerifyNo6Class", "xxxxxxxx", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo6Class: public Ui_WgtVerifyNo6Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO6_H
