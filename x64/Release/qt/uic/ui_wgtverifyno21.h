/********************************************************************************
** Form generated from reading UI file 'wgtverifyno21.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO21_H
#define UI_WGTVERIFYNO21_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo21Class
{
public:
    QLabel *labelName;
    QLabel *labelImage;
    QToolButton *toolButtonZoomIn;
    QLabel *labelIcon;
    QLabel *labelLeftLine;
    QLabel *labelRightLine;

    void setupUi(QWidget *WgtVerifyNo21Class)
    {
        if (WgtVerifyNo21Class->objectName().isEmpty())
            WgtVerifyNo21Class->setObjectName("WgtVerifyNo21Class");
        WgtVerifyNo21Class->resize(420, 310);
        WgtVerifyNo21Class->setMinimumSize(QSize(420, 310));
        WgtVerifyNo21Class->setMaximumSize(QSize(420, 310));
        labelName = new QLabel(WgtVerifyNo21Class);
        labelName->setObjectName("labelName");
        labelName->setGeometry(QRect(0, 32, 420, 50));
        labelName->setMinimumSize(QSize(420, 50));
        labelName->setMaximumSize(QSize(420, 50));
        labelName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelImage = new QLabel(WgtVerifyNo21Class);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(10, 85, 400, 225));
        labelImage->setMinimumSize(QSize(400, 225));
        labelImage->setMaximumSize(QSize(400, 225));
        toolButtonZoomIn = new QToolButton(WgtVerifyNo21Class);
        toolButtonZoomIn->setObjectName("toolButtonZoomIn");
        toolButtonZoomIn->setGeometry(QRect(350, 240, 50, 50));
        toolButtonZoomIn->setMinimumSize(QSize(50, 50));
        toolButtonZoomIn->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/zoom.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonZoomIn->setIcon(icon);
        toolButtonZoomIn->setIconSize(QSize(50, 50));
        labelIcon = new QLabel(WgtVerifyNo21Class);
        labelIcon->setObjectName("labelIcon");
        labelIcon->setGeometry(QRect(195, 0, 30, 30));
        labelIcon->setMinimumSize(QSize(30, 30));
        labelIcon->setMaximumSize(QSize(30, 30));
        labelLeftLine = new QLabel(WgtVerifyNo21Class);
        labelLeftLine->setObjectName("labelLeftLine");
        labelLeftLine->setGeometry(QRect(0, 15, 195, 2));
        labelLeftLine->setMinimumSize(QSize(195, 2));
        labelLeftLine->setMaximumSize(QSize(195, 2));
        labelRightLine = new QLabel(WgtVerifyNo21Class);
        labelRightLine->setObjectName("labelRightLine");
        labelRightLine->setGeometry(QRect(225, 15, 195, 2));
        labelRightLine->setMinimumSize(QSize(195, 2));
        labelRightLine->setMaximumSize(QSize(195, 2));

        retranslateUi(WgtVerifyNo21Class);

        QMetaObject::connectSlotsByName(WgtVerifyNo21Class);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyNo21Class)
    {
        WgtVerifyNo21Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo21Class", "WgtVerifyNo21", nullptr));
        labelName->setText(QString());
        labelImage->setText(QString());
        toolButtonZoomIn->setText(QString());
        labelIcon->setText(QString());
        labelLeftLine->setText(QString());
        labelRightLine->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo21Class: public Ui_WgtVerifyNo21Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO21_H
