/********************************************************************************
** Form generated from reading UI file 'wgtverifyno5.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO5_H
#define UI_WGTVERIFYNO5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <refreshviewlabel.h>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo5Class
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonBackHome;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelInfo2;
    RefreshViewLabel *labelRawImage;
    RefreshViewLabel *labelVerifyImage;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelInfo1;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *WgtVerifyNo5Class)
    {
        if (WgtVerifyNo5Class->objectName().isEmpty())
            WgtVerifyNo5Class->setObjectName("WgtVerifyNo5Class");
        WgtVerifyNo5Class->resize(1280, 667);
        gridLayout_2 = new QGridLayout(WgtVerifyNo5Class);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetTool = new QWidget(WgtVerifyNo5Class);
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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(widgetTool, 2, 0, 1, 1);

        widget = new QWidget(WgtVerifyNo5Class);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 300));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 6, 3, 1);

        labelInfo2 = new QLabel(widget);
        labelInfo2->setObjectName("labelInfo2");
        labelInfo2->setMinimumSize(QSize(0, 50));
        labelInfo2->setMaximumSize(QSize(16777215, 50));
        labelInfo2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelInfo2, 2, 2, 1, 3);

        labelRawImage = new RefreshViewLabel(widget);
        labelRawImage->setObjectName("labelRawImage");
        labelRawImage->setMinimumSize(QSize(592, 333));
        labelRawImage->setMaximumSize(QSize(592, 333));

        gridLayout->addWidget(labelRawImage, 3, 2, 1, 1);

        labelVerifyImage = new RefreshViewLabel(widget);
        labelVerifyImage->setObjectName("labelVerifyImage");
        labelVerifyImage->setMinimumSize(QSize(592, 333));
        labelVerifyImage->setMaximumSize(QSize(592, 333));

        gridLayout->addWidget(labelVerifyImage, 3, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 4, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        labelInfo1 = new QLabel(widget);
        labelInfo1->setObjectName("labelInfo1");
        labelInfo1->setMinimumSize(QSize(430, 55));
        labelInfo1->setMaximumSize(QSize(430, 50));
        labelInfo1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelInfo1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);


        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 2, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 5, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 5, 3, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(WgtVerifyNo5Class);

        QMetaObject::connectSlotsByName(WgtVerifyNo5Class);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyNo5Class)
    {
        WgtVerifyNo5Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo5Class", "WgtVerifyNo5", nullptr));
        pushButtonBackHome->setText(QCoreApplication::translate("WgtVerifyNo5Class", "\350\277\224\345\233\236\344\270\273\351\241\265", nullptr));
        labelInfo2->setText(QCoreApplication::translate("WgtVerifyNo5Class", "\346\202\250\345\217\257\344\273\245\347\273\247\347\273\255\347\255\211\345\276\205\357\274\214\346\210\226\350\200\205\347\250\215\345\220\216\345\234\250\350\277\233\345\272\246\347\256\241\347\220\206\346\237\245\350\257\242", nullptr));
        labelRawImage->setText(QString());
        labelVerifyImage->setText(QString());
        labelInfo1->setText(QCoreApplication::translate("WgtVerifyNo5Class", "\346\257\224\345\257\271\344\270\255\357\274\214\350\257\267\347\250\215\345\220\216\342\200\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo5Class: public Ui_WgtVerifyNo5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO5_H
