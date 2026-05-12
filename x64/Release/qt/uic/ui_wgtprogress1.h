/********************************************************************************
** Form generated from reading UI file 'wgtprogress1.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTPROGRESS1_H
#define UI_WGTPROGRESS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtProgress1Class
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetSetBtn;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonReg;
    QPushButton *pushButtonVerify;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *pageReg;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidgetReg;
    QWidget *pageVerify;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidgetVerify;
    QFrame *frameBatch;
    QHBoxLayout *horizontalLayout;
    QLabel *labelBatch;
    QComboBox *comboBoxBatch;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *WgtProgress1Class)
    {
        if (WgtProgress1Class->objectName().isEmpty())
            WgtProgress1Class->setObjectName("WgtProgress1Class");
        WgtProgress1Class->resize(992, 628);
        gridLayout = new QGridLayout(WgtProgress1Class);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widgetSetBtn = new QWidget(WgtProgress1Class);
        widgetSetBtn->setObjectName("widgetSetBtn");
        widgetSetBtn->setMinimumSize(QSize(250, 0));
        widgetSetBtn->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(widgetSetBtn);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        pushButtonReg = new QPushButton(widgetSetBtn);
        pushButtonReg->setObjectName("pushButtonReg");
        pushButtonReg->setMinimumSize(QSize(0, 70));
        pushButtonReg->setMaximumSize(QSize(16777215, 70));

        verticalLayout->addWidget(pushButtonReg);

        pushButtonVerify = new QPushButton(widgetSetBtn);
        pushButtonVerify->setObjectName("pushButtonVerify");
        pushButtonVerify->setMinimumSize(QSize(0, 70));
        pushButtonVerify->setMaximumSize(QSize(16777215, 70));

        verticalLayout->addWidget(pushButtonVerify);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(widgetSetBtn, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(WgtProgress1Class);
        stackedWidget->setObjectName("stackedWidget");
        pageReg = new QWidget();
        pageReg->setObjectName("pageReg");
        gridLayout_3 = new QGridLayout(pageReg);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidgetReg = new QTableWidget(pageReg);
        tableWidgetReg->setObjectName("tableWidgetReg");

        gridLayout_3->addWidget(tableWidgetReg, 0, 0, 1, 1);

        stackedWidget->addWidget(pageReg);
        pageVerify = new QWidget();
        pageVerify->setObjectName("pageVerify");
        gridLayout_2 = new QGridLayout(pageVerify);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidgetVerify = new QTableWidget(pageVerify);
        tableWidgetVerify->setObjectName("tableWidgetVerify");

        gridLayout_2->addWidget(tableWidgetVerify, 0, 0, 1, 2);

        frameBatch = new QFrame(pageVerify);
        frameBatch->setObjectName("frameBatch");
        frameBatch->setFrameShape(QFrame::Shape::StyledPanel);
        frameBatch->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frameBatch);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        labelBatch = new QLabel(frameBatch);
        labelBatch->setObjectName("labelBatch");
        labelBatch->setMinimumSize(QSize(120, 40));
        labelBatch->setMaximumSize(QSize(120, 40));
        labelBatch->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(labelBatch);

        comboBoxBatch = new QComboBox(frameBatch);
        comboBoxBatch->addItem(QString());
        comboBoxBatch->addItem(QString());
        comboBoxBatch->addItem(QString());
        comboBoxBatch->setObjectName("comboBoxBatch");
        comboBoxBatch->setMinimumSize(QSize(500, 40));

        horizontalLayout->addWidget(comboBoxBatch);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addWidget(frameBatch, 1, 0, 1, 1);

        stackedWidget->addWidget(pageVerify);

        gridLayout->addWidget(stackedWidget, 0, 2, 1, 1);


        retranslateUi(WgtProgress1Class);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WgtProgress1Class);
    } // setupUi

    void retranslateUi(QWidget *WgtProgress1Class)
    {
        WgtProgress1Class->setWindowTitle(QCoreApplication::translate("WgtProgress1Class", "WgtProgress1", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("WgtProgress1Class", "\347\231\273\350\256\260", nullptr));
        pushButtonVerify->setText(QCoreApplication::translate("WgtProgress1Class", "\351\252\214\350\257\201", nullptr));
        labelBatch->setText(QCoreApplication::translate("WgtProgress1Class", "\347\255\233\351\200\211\346\211\271\346\254\241\357\274\232", nullptr));
        comboBoxBatch->setItemText(0, QCoreApplication::translate("WgtProgress1Class", "\346\210\221\345\216\273\344\273\273\345\212\241\347\273\231\346\211\200\345\217\221\347\224\237\347\232\204", nullptr));
        comboBoxBatch->setItemText(1, QCoreApplication::translate("WgtProgress1Class", "QWRETHYJHFDGSA", nullptr));
        comboBoxBatch->setItemText(2, QCoreApplication::translate("WgtProgress1Class", "1234TYHFGDFSCXz", nullptr));

    } // retranslateUi

};

namespace Ui {
    class WgtProgress1Class: public Ui_WgtProgress1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTPROGRESS1_H
