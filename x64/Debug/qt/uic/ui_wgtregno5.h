/********************************************************************************
** Form generated from reading UI file 'wgtregno5.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGNO5_H
#define UI_WGTREGNO5_H

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

class Ui_WgtRegNo5Class
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelImage;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_14;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *labelTexture;
    QLabel *labelRegTime;
    QLabel *labelLevel;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *labelAge;
    QLabel *labelAgency;
    QLabel *labelName;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelSize;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labelCarrier;
    QLabel *labelApplicant;
    QLabel *labelDevice;
    QLabel *labelExhibitionTitle;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *GridLayoutImageView;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonRegDelete;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonGoReg6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WgtRegNo5Class)
    {
        if (WgtRegNo5Class->objectName().isEmpty())
            WgtRegNo5Class->setObjectName("WgtRegNo5Class");
        WgtRegNo5Class->resize(1280, 598);
        WgtRegNo5Class->setMinimumSize(QSize(0, 0));
        WgtRegNo5Class->setMaximumSize(QSize(16777214, 16777215));
        verticalLayout_2 = new QVBoxLayout(WgtRegNo5Class);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(WgtRegNo5Class);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1278, 486));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(0, 260));
        widget_3->setMaximumSize(QSize(16777215, 260));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 10, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        labelImage = new QLabel(widget_3);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(279, 157));
        labelImage->setMaximumSize(QSize(279, 157));

        horizontalLayout->addWidget(labelImage);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label_14 = new QLabel(widget_4);
        label_14->setObjectName("label_14");
        label_14->setMinimumSize(QSize(100, 0));
        label_14->setMaximumSize(QSize(100, 16777215));
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_14, 3, 6, 1, 1);

        label = new QLabel(widget_4);
        label->setObjectName("label");
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 16777215));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 8);

        labelTexture = new QLabel(widget_4);
        labelTexture->setObjectName("labelTexture");
        labelTexture->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelTexture, 3, 1, 1, 1);

        labelRegTime = new QLabel(widget_4);
        labelRegTime->setObjectName("labelRegTime");
        labelRegTime->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelRegTime, 3, 7, 1, 1);

        labelLevel = new QLabel(widget_4);
        labelLevel->setObjectName("labelLevel");
        labelLevel->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelLevel, 5, 1, 1, 1);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        labelAge = new QLabel(widget_4);
        labelAge->setObjectName("labelAge");
        labelAge->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelAge, 4, 1, 1, 1);

        labelAgency = new QLabel(widget_4);
        labelAgency->setObjectName("labelAgency");
        labelAgency->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelAgency, 2, 7, 1, 1);

        labelName = new QLabel(widget_4);
        labelName->setObjectName("labelName");
        labelName->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelName, 1, 0, 1, 8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 7, 0, 1, 8);

        label_13 = new QLabel(widget_4);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(100, 0));
        label_13->setMaximumSize(QSize(100, 16777215));
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_13, 2, 6, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        labelSize = new QLabel(widget_4);
        labelSize->setObjectName("labelSize");
        labelSize->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelSize, 2, 1, 1, 1);

        label_7 = new QLabel(widget_4);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(100, 16777215));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_7, 2, 3, 1, 1);

        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(100, 0));
        label_8->setMaximumSize(QSize(100, 16777215));
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_8, 3, 3, 1, 1);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setMaximumSize(QSize(100, 16777215));
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 3, 1, 1);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setMaximumSize(QSize(100, 16777215));
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 3, 1, 1);

        labelCarrier = new QLabel(widget_4);
        labelCarrier->setObjectName("labelCarrier");
        labelCarrier->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelCarrier, 2, 4, 1, 1);

        labelApplicant = new QLabel(widget_4);
        labelApplicant->setObjectName("labelApplicant");
        labelApplicant->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelApplicant, 3, 4, 1, 1);

        labelDevice = new QLabel(widget_4);
        labelDevice->setObjectName("labelDevice");
        labelDevice->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelDevice, 4, 4, 1, 1);

        labelExhibitionTitle = new QLabel(widget_4);
        labelExhibitionTitle->setObjectName("labelExhibitionTitle");
        labelExhibitionTitle->setMaximumSize(QSize(16777215, 152));

        gridLayout->addWidget(labelExhibitionTitle, 5, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 5, 5, 1, 1);


        horizontalLayout->addWidget(widget_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);


        verticalLayout->addWidget(widget_3);

        GridLayoutImageView = new QGridLayout();
        GridLayoutImageView->setSpacing(6);
        GridLayoutImageView->setObjectName("GridLayoutImageView");

        verticalLayout->addLayout(GridLayoutImageView);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        widgetTool = new QWidget(WgtRegNo5Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_3 = new QHBoxLayout(widgetTool);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonRegDelete = new QPushButton(widgetTool);
        pushButtonRegDelete->setObjectName("pushButtonRegDelete");
        pushButtonRegDelete->setMinimumSize(QSize(370, 70));

        horizontalLayout_3->addWidget(pushButtonRegDelete);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonGoReg6 = new QPushButton(widgetTool);
        pushButtonGoReg6->setObjectName("pushButtonGoReg6");
        pushButtonGoReg6->setMinimumSize(QSize(370, 70));

        horizontalLayout_3->addWidget(pushButtonGoReg6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widgetTool);


        retranslateUi(WgtRegNo5Class);

        QMetaObject::connectSlotsByName(WgtRegNo5Class);
    } // setupUi

    void retranslateUi(QWidget *WgtRegNo5Class)
    {
        WgtRegNo5Class->setWindowTitle(QCoreApplication::translate("WgtRegNo5Class", "WgtRegNo5", nullptr));
        labelImage->setText(QString());
        label_2->setText(QCoreApplication::translate("WgtRegNo5Class", "\345\271\264\344\273\243\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("WgtRegNo5Class", "\347\231\273\350\256\260\346\227\266\351\227\264\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("WgtRegNo5Class", "\347\272\247\345\210\253\357\274\232", nullptr));
        labelTexture->setText(QCoreApplication::translate("WgtRegNo5Class", "\347\223\267\345\231\250", nullptr));
        labelRegTime->setText(QCoreApplication::translate("WgtRegNo5Class", "0000-00-00 00:00", nullptr));
        labelLevel->setText(QCoreApplication::translate("WgtRegNo5Class", "\344\272\214\347\272\247", nullptr));
        label_4->setText(QCoreApplication::translate("WgtRegNo5Class", "\350\264\250\345\234\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("WgtRegNo5Class", "\345\260\272\345\257\270\357\274\232", nullptr));
        labelAge->setText(QCoreApplication::translate("WgtRegNo5Class", "\346\270\205\344\273\243", nullptr));
        labelAgency->setText(QCoreApplication::translate("WgtRegNo5Class", "\351\241\272\344\271\211\351\211\264\345\256\232\347\253\231", nullptr));
        labelName->setText(QCoreApplication::translate("WgtRegNo5Class", "\346\270\205\344\271\276\351\232\206\351\235\222\350\212\261\347\223\267\347\223\266", nullptr));
        label_13->setText(QCoreApplication::translate("WgtRegNo5Class", "\347\231\273\350\256\260\347\273\204\347\273\207\357\274\232", nullptr));
        labelSize->setText(QCoreApplication::translate("WgtRegNo5Class", "\351\253\23040cm\343\200\201\347\233\264\345\276\20430cm", nullptr));
        label_7->setText(QCoreApplication::translate("WgtRegNo5Class", "\345\215\217 \350\277\220 \344\272\272 \357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("WgtRegNo5Class", "\347\224\263 \350\257\267 \344\272\272 \357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("WgtRegNo5Class", "\347\231\273\350\256\260\350\256\276\345\244\207\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("WgtRegNo5Class", "\345\261\225 \350\247\210 \345\220\215 \357\274\232", nullptr));
        labelCarrier->setText(QCoreApplication::translate("WgtRegNo5Class", "xx", nullptr));
        labelApplicant->setText(QCoreApplication::translate("WgtRegNo5Class", "xx", nullptr));
        labelDevice->setText(QCoreApplication::translate("WgtRegNo5Class", "\344\276\277\346\220\272", nullptr));
        labelExhibitionTitle->setText(QCoreApplication::translate("WgtRegNo5Class", "xxxxxxxx", nullptr));
        pushButtonRegDelete->setText(QCoreApplication::translate("WgtRegNo5Class", "\345\210\240\351\231\244\346\234\254\344\273\266\347\231\273\350\256\260", nullptr));
        pushButtonGoReg6->setText(QCoreApplication::translate("WgtRegNo5Class", "\347\241\256\350\256\244\344\277\235\345\255\230\346\234\254\344\273\266\347\231\273\350\256\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtRegNo5Class: public Ui_WgtRegNo5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGNO5_H
