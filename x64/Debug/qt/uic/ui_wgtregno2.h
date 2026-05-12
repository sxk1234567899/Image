/********************************************************************************
** Form generated from reading UI file 'wgtregno2.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGNO2_H
#define UI_WGTREGNO2_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <imagewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WgtRegNo2Class
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QVideoWidget *videoWidget;
    QSpinBox *spinBox;
    ImageWidget *widgetImage;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonTop;
    QRadioButton *radioButtonBot;
    QRadioButton *radioButtonFrn;
    QRadioButton *radioButtonBak;
    QRadioButton *radioButtonLef;
    QRadioButton *radioButtonRgh;
    QRadioButton *radioButtonPar;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonGoReg3;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *WgtRegNo2Class)
    {
        if (WgtRegNo2Class->objectName().isEmpty())
            WgtRegNo2Class->setObjectName("WgtRegNo2Class");
        WgtRegNo2Class->resize(1280, 755);
        gridLayout = new QGridLayout(WgtRegNo2Class);
        gridLayout->setSpacing(20);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(WgtRegNo2Class);
        widget_2->setObjectName("widget_2");
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        videoWidget = new QVideoWidget(widget_2);
        videoWidget->setObjectName("videoWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoWidget->sizePolicy().hasHeightForWidth());
        videoWidget->setSizePolicy(sizePolicy);
        videoWidget->setMinimumSize(QSize(1040, 585));
        videoWidget->setMaximumSize(QSize(1040, 585));

        gridLayout_2->addWidget(videoWidget, 0, 0, 2, 1);


        gridLayout->addWidget(widget_2, 0, 0, 2, 1);

        spinBox = new QSpinBox(WgtRegNo2Class);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimumSize(QSize(220, 0));
        spinBox->setMaximumSize(QSize(220, 16777215));
        spinBox->setReadOnly(true);
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMaximum(1000);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        widgetImage = new ImageWidget(WgtRegNo2Class);
        widgetImage->setObjectName("widgetImage");
        widgetImage->setMinimumSize(QSize(220, 0));
        widgetImage->setMaximumSize(QSize(220, 16777215));

        gridLayout->addWidget(widgetImage, 1, 1, 1, 1);

        widgetTool = new QWidget(WgtRegNo2Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_3 = new QHBoxLayout(widgetTool);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        radioButtonTop = new QRadioButton(widgetTool);
        radioButtonTop->setObjectName("radioButtonTop");
        radioButtonTop->setMinimumSize(QSize(110, 60));
        radioButtonTop->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_2->addWidget(radioButtonTop);

        radioButtonBot = new QRadioButton(widgetTool);
        radioButtonBot->setObjectName("radioButtonBot");
        radioButtonBot->setMinimumSize(QSize(110, 60));
        radioButtonBot->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_2->addWidget(radioButtonBot);

        radioButtonFrn = new QRadioButton(widgetTool);
        radioButtonFrn->setObjectName("radioButtonFrn");
        radioButtonFrn->setMinimumSize(QSize(110, 60));
        radioButtonFrn->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_2->addWidget(radioButtonFrn);

        radioButtonBak = new QRadioButton(widgetTool);
        radioButtonBak->setObjectName("radioButtonBak");
        radioButtonBak->setMinimumSize(QSize(110, 60));
        radioButtonBak->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_2->addWidget(radioButtonBak);

        radioButtonLef = new QRadioButton(widgetTool);
        radioButtonLef->setObjectName("radioButtonLef");
        radioButtonLef->setMinimumSize(QSize(110, 60));
        radioButtonLef->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_2->addWidget(radioButtonLef);

        radioButtonRgh = new QRadioButton(widgetTool);
        radioButtonRgh->setObjectName("radioButtonRgh");
        radioButtonRgh->setMinimumSize(QSize(110, 60));
        radioButtonRgh->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_2->addWidget(radioButtonRgh);

        radioButtonPar = new QRadioButton(widgetTool);
        radioButtonPar->setObjectName("radioButtonPar");
        radioButtonPar->setMinimumSize(QSize(110, 60));
        radioButtonPar->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_2->addWidget(radioButtonPar);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonGoReg3 = new QPushButton(widgetTool);
        pushButtonGoReg3->setObjectName("pushButtonGoReg3");
        pushButtonGoReg3->setMinimumSize(QSize(240, 70));

        horizontalLayout_3->addWidget(pushButtonGoReg3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addWidget(widgetTool, 2, 0, 1, 2);


        retranslateUi(WgtRegNo2Class);

        QMetaObject::connectSlotsByName(WgtRegNo2Class);
    } // setupUi

    void retranslateUi(QWidget *WgtRegNo2Class)
    {
        WgtRegNo2Class->setWindowTitle(QCoreApplication::translate("WgtRegNo2Class", "WgtRegNo2", nullptr));
        spinBox->setPrefix(QCoreApplication::translate("WgtRegNo2Class", "\345\267\262\347\273\217\346\213\215\346\221\204\357\274\232", nullptr));
        radioButtonTop->setText(QCoreApplication::translate("WgtRegNo2Class", "\351\241\266", nullptr));
        radioButtonBot->setText(QCoreApplication::translate("WgtRegNo2Class", "\345\272\225", nullptr));
        radioButtonFrn->setText(QCoreApplication::translate("WgtRegNo2Class", "\345\211\215", nullptr));
        radioButtonBak->setText(QCoreApplication::translate("WgtRegNo2Class", "\345\220\216", nullptr));
        radioButtonLef->setText(QCoreApplication::translate("WgtRegNo2Class", "\345\267\246", nullptr));
        radioButtonRgh->setText(QCoreApplication::translate("WgtRegNo2Class", "\345\217\263", nullptr));
        radioButtonPar->setText(QCoreApplication::translate("WgtRegNo2Class", "\345\261\200\351\203\250", nullptr));
        pushButtonGoReg3->setText(QCoreApplication::translate("WgtRegNo2Class", "\344\270\213\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtRegNo2Class: public Ui_WgtRegNo2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGNO2_H
