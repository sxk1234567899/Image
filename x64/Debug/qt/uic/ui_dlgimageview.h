/********************************************************************************
** Form generated from reading UI file 'dlgimageview.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGIMAGEVIEW_H
#define UI_DLGIMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgImageViewClass
{
public:
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonQuit;
    QPushButton *pushButtonSwitch;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelImage;
    QPushButton *pushButtonZoomOut;
    QPushButton *pushButtonZoomIn;

    void setupUi(QDialog *DlgImageViewClass)
    {
        if (DlgImageViewClass->objectName().isEmpty())
            DlgImageViewClass->setObjectName("DlgImageViewClass");
        DlgImageViewClass->resize(1280, 800);
        DlgImageViewClass->setMinimumSize(QSize(1280, 800));
        DlgImageViewClass->setMaximumSize(QSize(1280, 800));
        pushButtonDelete = new QPushButton(DlgImageViewClass);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(1010, 20, 250, 70));
        pushButtonDelete->setMinimumSize(QSize(200, 70));
        pushButtonQuit = new QPushButton(DlgImageViewClass);
        pushButtonQuit->setObjectName("pushButtonQuit");
        pushButtonQuit->setGeometry(QRect(20, 20, 200, 70));
        pushButtonQuit->setMinimumSize(QSize(200, 70));
        pushButtonSwitch = new QPushButton(DlgImageViewClass);
        pushButtonSwitch->setObjectName("pushButtonSwitch");
        pushButtonSwitch->setGeometry(QRect(1010, 710, 250, 70));
        pushButtonSwitch->setMinimumSize(QSize(250, 70));
        scrollArea = new QScrollArea(DlgImageViewClass);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 1280, 800));
        scrollArea->setMinimumSize(QSize(1280, 800));
        scrollArea->setMaximumSize(QSize(1280, 800));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1280, 800));
        scrollAreaWidgetContents->setMinimumSize(QSize(1280, 800));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelImage = new QLabel(scrollAreaWidgetContents);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(1280, 800));

        gridLayout->addWidget(labelImage, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButtonZoomOut = new QPushButton(DlgImageViewClass);
        pushButtonZoomOut->setObjectName("pushButtonZoomOut");
        pushButtonZoomOut->setGeometry(QRect(1150, 480, 70, 70));
        pushButtonZoomOut->setMinimumSize(QSize(70, 70));
        pushButtonZoomOut->setMaximumSize(QSize(70, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/lowen.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonZoomOut->setIcon(icon);
        pushButtonZoomOut->setIconSize(QSize(70, 70));
        pushButtonZoomIn = new QPushButton(DlgImageViewClass);
        pushButtonZoomIn->setObjectName("pushButtonZoomIn");
        pushButtonZoomIn->setGeometry(QRect(1150, 210, 70, 70));
        pushButtonZoomIn->setMinimumSize(QSize(70, 70));
        pushButtonZoomIn->setMaximumSize(QSize(70, 70));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/hgten.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonZoomIn->setIcon(icon1);
        pushButtonZoomIn->setIconSize(QSize(70, 70));
        scrollArea->raise();
        pushButtonDelete->raise();
        pushButtonQuit->raise();
        pushButtonSwitch->raise();
        pushButtonZoomOut->raise();
        pushButtonZoomIn->raise();

        retranslateUi(DlgImageViewClass);

        QMetaObject::connectSlotsByName(DlgImageViewClass);
    } // setupUi

    void retranslateUi(QDialog *DlgImageViewClass)
    {
        DlgImageViewClass->setWindowTitle(QCoreApplication::translate("DlgImageViewClass", "DlgImageView", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("DlgImageViewClass", "\345\210\240\351\231\244\345\233\276\347\211\207", nullptr));
        pushButtonQuit->setText(QCoreApplication::translate("DlgImageViewClass", "\350\277\224\345\233\236", nullptr));
        pushButtonSwitch->setText(QCoreApplication::translate("DlgImageViewClass", "\345\210\207\346\215\242", nullptr));
        labelImage->setText(QString());
        pushButtonZoomOut->setText(QString());
        pushButtonZoomIn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DlgImageViewClass: public Ui_DlgImageViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGIMAGEVIEW_H
