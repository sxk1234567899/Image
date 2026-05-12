/********************************************************************************
** Form generated from reading UI file 'wgtverifyno1.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO1_H
#define UI_WGTVERIFYNO1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo1Class
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetTool;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonMode;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonSCode;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonGoVerify2;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *pageSCode;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCode2d;
    QLabel *labelInfo;
    QPlainTextEdit *plainTextEdit;
    QWidget *pageBatch;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButtonBatchUpPage;
    QLabel *labelBatchPage;
    QToolButton *toolButtonBatchNextPage;
    QSpacerItem *horizontalSpacer_6;
    QTableWidget *tableWidgetBatch;
    QWidget *pageList;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButtonListUpPage;
    QLabel *labelListPage;
    QToolButton *toolButtonListNextPage;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidgetList;
    QWidget *batchView;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout_2;
    QLabel *labelImage;
    QLabel *label_14;
    QLineEdit *lineEditName;
    QLabel *label_17;
    QLineEdit *lineEditSize;
    QLabel *label_16;
    QLineEdit *lineEditTexture;
    QLabel *label_18;
    QLineEdit *lineEditAge;
    QLabel *label_15;
    QLineEdit *lineEditLevel;
    QLabel *label_21;
    QLineEdit *lineEditCarrier;
    QLabel *label_22;
    QLineEdit *lineEditApplicant;
    QLabel *label_12;
    QLineEdit *lineEditDept;
    QLabel *label_13;
    QLabel *labelExhibitionTitle;
    QLineEdit *lineEditExhibitionTitle;

    void setupUi(QWidget *WgtVerifyNo1Class)
    {
        if (WgtVerifyNo1Class->objectName().isEmpty())
            WgtVerifyNo1Class->setObjectName("WgtVerifyNo1Class");
        WgtVerifyNo1Class->resize(1280, 690);
        WgtVerifyNo1Class->setMinimumSize(QSize(0, 0));
        WgtVerifyNo1Class->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(WgtVerifyNo1Class);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widgetTool = new QWidget(WgtVerifyNo1Class);
        widgetTool->setObjectName("widgetTool");
        widgetTool->setMinimumSize(QSize(0, 110));
        widgetTool->setMaximumSize(QSize(16777215, 110));
        horizontalLayout = new QHBoxLayout(widgetTool);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonMode = new QPushButton(widgetTool);
        pushButtonMode->setObjectName("pushButtonMode");
        pushButtonMode->setMinimumSize(QSize(300, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/switchg.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonMode->setIcon(icon);
        pushButtonMode->setIconSize(QSize(31, 30));

        horizontalLayout->addWidget(pushButtonMode);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButtonSCode = new QPushButton(widgetTool);
        pushButtonSCode->setObjectName("pushButtonSCode");
        pushButtonSCode->setMinimumSize(QSize(300, 70));

        horizontalLayout->addWidget(pushButtonSCode);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButtonGoVerify2 = new QPushButton(widgetTool);
        pushButtonGoVerify2->setObjectName("pushButtonGoVerify2");
        pushButtonGoVerify2->setMinimumSize(QSize(300, 70));

        horizontalLayout->addWidget(pushButtonGoVerify2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widgetTool, 1, 0, 1, 2);

        stackedWidget = new QStackedWidget(WgtVerifyNo1Class);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        pageSCode = new QWidget();
        pageSCode->setObjectName("pageSCode");
        verticalLayout = new QVBoxLayout(pageSCode);
        verticalLayout->setSpacing(30);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelCode2d = new QLabel(pageSCode);
        labelCode2d->setObjectName("labelCode2d");
        labelCode2d->setMinimumSize(QSize(76, 76));
        labelCode2d->setMaximumSize(QSize(76, 76));

        horizontalLayout_2->addWidget(labelCode2d);

        labelInfo = new QLabel(pageSCode);
        labelInfo->setObjectName("labelInfo");
        labelInfo->setMaximumSize(QSize(16777215, 152));

        horizontalLayout_2->addWidget(labelInfo);


        verticalLayout->addLayout(horizontalLayout_2);

        plainTextEdit = new QPlainTextEdit(pageSCode);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        stackedWidget->addWidget(pageSCode);
        pageBatch = new QWidget();
        pageBatch->setObjectName("pageBatch");
        gridLayout_3 = new QGridLayout(pageBatch);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(15, -1, 15, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        toolButtonBatchUpPage = new QToolButton(pageBatch);
        toolButtonBatchUpPage->setObjectName("toolButtonBatchUpPage");
        toolButtonBatchUpPage->setMinimumSize(QSize(52, 52));
        toolButtonBatchUpPage->setMaximumSize(QSize(52, 52));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/jleft.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonBatchUpPage->setIcon(icon1);
        toolButtonBatchUpPage->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(toolButtonBatchUpPage);

        labelBatchPage = new QLabel(pageBatch);
        labelBatchPage->setObjectName("labelBatchPage");
        labelBatchPage->setMinimumSize(QSize(52, 0));
        labelBatchPage->setMaximumSize(QSize(52, 16777215));

        horizontalLayout_3->addWidget(labelBatchPage);

        toolButtonBatchNextPage = new QToolButton(pageBatch);
        toolButtonBatchNextPage->setObjectName("toolButtonBatchNextPage");
        toolButtonBatchNextPage->setMinimumSize(QSize(52, 52));
        toolButtonBatchNextPage->setMaximumSize(QSize(52, 52));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/jright.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonBatchNextPage->setIcon(icon2);
        toolButtonBatchNextPage->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(toolButtonBatchNextPage);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        tableWidgetBatch = new QTableWidget(pageBatch);
        tableWidgetBatch->setObjectName("tableWidgetBatch");

        gridLayout_3->addWidget(tableWidgetBatch, 0, 0, 1, 1);

        stackedWidget->addWidget(pageBatch);
        pageList = new QWidget();
        pageList->setObjectName("pageList");
        gridLayout_2 = new QGridLayout(pageList);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(20, -1, 20, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, -1, 10, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        toolButtonListUpPage = new QToolButton(pageList);
        toolButtonListUpPage->setObjectName("toolButtonListUpPage");
        toolButtonListUpPage->setMinimumSize(QSize(52, 52));
        toolButtonListUpPage->setMaximumSize(QSize(52, 52));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/jup.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonListUpPage->setIcon(icon3);
        toolButtonListUpPage->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(toolButtonListUpPage);

        labelListPage = new QLabel(pageList);
        labelListPage->setObjectName("labelListPage");
        labelListPage->setMinimumSize(QSize(52, 0));
        labelListPage->setMaximumSize(QSize(52, 16777215));
        labelListPage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(labelListPage);

        toolButtonListNextPage = new QToolButton(pageList);
        toolButtonListNextPage->setObjectName("toolButtonListNextPage");
        toolButtonListNextPage->setMinimumSize(QSize(52, 52));
        toolButtonListNextPage->setMaximumSize(QSize(52, 52));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/jdown.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonListNextPage->setIcon(icon4);
        toolButtonListNextPage->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(toolButtonListNextPage);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout_3, 1, 0, 1, 1);

        tableWidgetList = new QTableWidget(pageList);
        tableWidgetList->setObjectName("tableWidgetList");

        gridLayout_2->addWidget(tableWidgetList, 1, 1, 1, 1);

        batchView = new QWidget(pageList);
        batchView->setObjectName("batchView");
        batchView->setMinimumSize(QSize(0, 78));
        batchView->setMaximumSize(QSize(16777215, 78));

        gridLayout_2->addWidget(batchView, 0, 0, 1, 2);

        stackedWidget->addWidget(pageList);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        scrollArea = new QScrollArea(WgtVerifyNo1Class);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, -182, 621, 780));
        formLayout_2 = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setHorizontalSpacing(20);
        formLayout_2->setVerticalSpacing(20);
        formLayout_2->setContentsMargins(20, 20, 20, 20);
        labelImage = new QLabel(scrollAreaWidgetContents_2);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(320, 180));
        labelImage->setMaximumSize(QSize(320, 180));
        labelImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, labelImage);

        label_14 = new QLabel(scrollAreaWidgetContents_2);
        label_14->setObjectName("label_14");
        label_14->setMinimumSize(QSize(90, 40));
        label_14->setMaximumSize(QSize(16777215, 40));
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, label_14);

        lineEditName = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setMinimumSize(QSize(0, 40));
        lineEditName->setMaximumSize(QSize(16777215, 40));
        lineEditName->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditName->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditName);

        label_17 = new QLabel(scrollAreaWidgetContents_2);
        label_17->setObjectName("label_17");
        label_17->setMinimumSize(QSize(90, 40));
        label_17->setMaximumSize(QSize(16777215, 40));
        label_17->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::ItemRole::LabelRole, label_17);

        lineEditSize = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditSize->setObjectName("lineEditSize");
        lineEditSize->setMinimumSize(QSize(0, 40));
        lineEditSize->setMaximumSize(QSize(16777215, 40));
        lineEditSize->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditSize->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEditSize);

        label_16 = new QLabel(scrollAreaWidgetContents_2);
        label_16->setObjectName("label_16");
        label_16->setMinimumSize(QSize(90, 40));
        label_16->setMaximumSize(QSize(16777215, 40));
        label_16->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::ItemRole::LabelRole, label_16);

        lineEditTexture = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditTexture->setObjectName("lineEditTexture");
        lineEditTexture->setMinimumSize(QSize(0, 40));
        lineEditTexture->setMaximumSize(QSize(16777215, 40));
        lineEditTexture->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditTexture->setReadOnly(true);

        formLayout_2->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEditTexture);

        label_18 = new QLabel(scrollAreaWidgetContents_2);
        label_18->setObjectName("label_18");
        label_18->setMinimumSize(QSize(90, 40));
        label_18->setMaximumSize(QSize(16777215, 40));
        label_18->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(4, QFormLayout::ItemRole::LabelRole, label_18);

        lineEditAge = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditAge->setObjectName("lineEditAge");
        lineEditAge->setMinimumSize(QSize(0, 40));
        lineEditAge->setMaximumSize(QSize(16777215, 40));
        lineEditAge->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditAge->setReadOnly(true);

        formLayout_2->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEditAge);

        label_15 = new QLabel(scrollAreaWidgetContents_2);
        label_15->setObjectName("label_15");
        label_15->setMinimumSize(QSize(90, 40));
        label_15->setMaximumSize(QSize(16777215, 40));
        label_15->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(5, QFormLayout::ItemRole::LabelRole, label_15);

        lineEditLevel = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditLevel->setObjectName("lineEditLevel");
        lineEditLevel->setMinimumSize(QSize(0, 40));
        lineEditLevel->setMaximumSize(QSize(16777215, 40));
        lineEditLevel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditLevel->setReadOnly(true);

        formLayout_2->setWidget(5, QFormLayout::ItemRole::FieldRole, lineEditLevel);

        label_21 = new QLabel(scrollAreaWidgetContents_2);
        label_21->setObjectName("label_21");
        label_21->setMinimumSize(QSize(90, 40));
        label_21->setMaximumSize(QSize(16777215, 40));
        label_21->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(7, QFormLayout::ItemRole::LabelRole, label_21);

        lineEditCarrier = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditCarrier->setObjectName("lineEditCarrier");
        lineEditCarrier->setMinimumSize(QSize(0, 40));
        lineEditCarrier->setMaximumSize(QSize(16777215, 40));
        lineEditCarrier->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditCarrier->setReadOnly(true);

        formLayout_2->setWidget(7, QFormLayout::ItemRole::FieldRole, lineEditCarrier);

        label_22 = new QLabel(scrollAreaWidgetContents_2);
        label_22->setObjectName("label_22");
        label_22->setMinimumSize(QSize(90, 40));
        label_22->setMaximumSize(QSize(16777215, 40));
        label_22->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(8, QFormLayout::ItemRole::LabelRole, label_22);

        lineEditApplicant = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditApplicant->setObjectName("lineEditApplicant");
        lineEditApplicant->setMinimumSize(QSize(0, 40));
        lineEditApplicant->setMaximumSize(QSize(16777215, 40));
        lineEditApplicant->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditApplicant->setReadOnly(true);

        formLayout_2->setWidget(8, QFormLayout::ItemRole::FieldRole, lineEditApplicant);

        label_12 = new QLabel(scrollAreaWidgetContents_2);
        label_12->setObjectName("label_12");
        label_12->setMinimumSize(QSize(90, 40));
        label_12->setMaximumSize(QSize(16777215, 40));
        label_12->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(9, QFormLayout::ItemRole::LabelRole, label_12);

        lineEditDept = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditDept->setObjectName("lineEditDept");
        lineEditDept->setMinimumSize(QSize(0, 40));
        lineEditDept->setMaximumSize(QSize(16777215, 40));
        lineEditDept->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditDept->setReadOnly(true);

        formLayout_2->setWidget(9, QFormLayout::ItemRole::FieldRole, lineEditDept);

        label_13 = new QLabel(scrollAreaWidgetContents_2);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(90, 40));
        label_13->setMaximumSize(QSize(16777215, 152));
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, label_13);

        labelExhibitionTitle = new QLabel(scrollAreaWidgetContents_2);
        labelExhibitionTitle->setObjectName("labelExhibitionTitle");
        labelExhibitionTitle->setMinimumSize(QSize(90, 40));
        labelExhibitionTitle->setMaximumSize(QSize(16777215, 40));
        labelExhibitionTitle->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(10, QFormLayout::ItemRole::LabelRole, labelExhibitionTitle);

        lineEditExhibitionTitle = new QLineEdit(scrollAreaWidgetContents_2);
        lineEditExhibitionTitle->setObjectName("lineEditExhibitionTitle");
        lineEditExhibitionTitle->setMinimumSize(QSize(0, 40));
        lineEditExhibitionTitle->setMaximumSize(QSize(16777215, 40));
        lineEditExhibitionTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditExhibitionTitle->setReadOnly(true);

        formLayout_2->setWidget(10, QFormLayout::ItemRole::FieldRole, lineEditExhibitionTitle);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);


        retranslateUi(WgtVerifyNo1Class);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(WgtVerifyNo1Class);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyNo1Class)
    {
        WgtVerifyNo1Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo1Class", "WgtRegNo1", nullptr));
        pushButtonMode->setText(QCoreApplication::translate("WgtVerifyNo1Class", "    \345\210\227\350\241\250\346\250\241\345\274\217  ", nullptr));
        pushButtonSCode->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\346\211\253\344\270\200\346\211\253", nullptr));
        pushButtonGoVerify2->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\344\270\213\344\270\200\346\255\245", nullptr));
        labelCode2d->setText(QString());
        labelInfo->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\350\257\267\346\202\250\346\211\253\346\217\217\351\234\200\350\246\201\347\231\273\350\256\260\347\211\251\347\232\204\344\272\214\347\273\264\347\240\201\357\274\214\n"
"\346\211\253\347\247\222\345\256\214\346\210\220\345\220\216\345\260\206\346\230\276\347\244\272\345\237\272\346\234\254\344\277\241\346\201\257\343\200\202", nullptr));
        plainTextEdit->setPlaceholderText(QCoreApplication::translate("WgtVerifyNo1Class", "\346\211\253\346\217\217\350\257\206\345\210\253\345\214\272", nullptr));
        toolButtonBatchUpPage->setText(QString());
        labelBatchPage->setText(QString());
        toolButtonBatchNextPage->setText(QCoreApplication::translate("WgtVerifyNo1Class", "...", nullptr));
        toolButtonListUpPage->setText(QCoreApplication::translate("WgtVerifyNo1Class", "...", nullptr));
        labelListPage->setText(QString());
        toolButtonListNextPage->setText(QCoreApplication::translate("WgtVerifyNo1Class", "...", nullptr));
        labelImage->setText(QString());
        label_14->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\345\220\215   \347\247\260", nullptr));
        lineEditName->setPlaceholderText(QString());
        label_17->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\345\260\272   \345\257\270", nullptr));
        lineEditSize->setPlaceholderText(QString());
        label_16->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\350\264\250   \345\234\260", nullptr));
        lineEditTexture->setPlaceholderText(QString());
        label_18->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\345\271\264   \344\273\243", nullptr));
        lineEditAge->setPlaceholderText(QString());
        label_15->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\347\272\247   \345\210\253", nullptr));
        lineEditLevel->setPlaceholderText(QString());
        label_21->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\345\215\217\350\277\220\344\272\272", nullptr));
        lineEditCarrier->setPlaceholderText(QString());
        label_22->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\347\224\263\350\257\267\344\272\272", nullptr));
        lineEditApplicant->setPlaceholderText(QString());
        label_12->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\350\256\276   \345\244\207", nullptr));
        lineEditDept->setPlaceholderText(QString());
        label_13->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\345\233\276   \347\211\207", nullptr));
        labelExhibitionTitle->setText(QCoreApplication::translate("WgtVerifyNo1Class", "\345\261\225\350\247\210\345\220\215", nullptr));
        lineEditExhibitionTitle->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo1Class: public Ui_WgtVerifyNo1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO1_H
