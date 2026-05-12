/********************************************************************************
** Form generated from reading UI file 'wgtverifyno61.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTVERIFYNO61_H
#define UI_WGTVERIFYNO61_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtVerifyNo61Class
{
public:
    QLabel *labelImage;
    QToolButton *toolButtonZoomIn;

    void setupUi(QWidget *WgtVerifyNo61Class)
    {
        if (WgtVerifyNo61Class->objectName().isEmpty())
            WgtVerifyNo61Class->setObjectName("WgtVerifyNo61Class");
        WgtVerifyNo61Class->resize(400, 225);
        WgtVerifyNo61Class->setMinimumSize(QSize(400, 225));
        WgtVerifyNo61Class->setMaximumSize(QSize(400, 225));
        labelImage = new QLabel(WgtVerifyNo61Class);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(0, 0, 400, 225));
        labelImage->setMinimumSize(QSize(400, 225));
        labelImage->setMaximumSize(QSize(400, 225));
        toolButtonZoomIn = new QToolButton(WgtVerifyNo61Class);
        toolButtonZoomIn->setObjectName("toolButtonZoomIn");
        toolButtonZoomIn->setGeometry(QRect(340, 165, 50, 50));
        toolButtonZoomIn->setMinimumSize(QSize(50, 50));
        toolButtonZoomIn->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/zoom.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonZoomIn->setIcon(icon);
        toolButtonZoomIn->setIconSize(QSize(50, 50));

        retranslateUi(WgtVerifyNo61Class);

        QMetaObject::connectSlotsByName(WgtVerifyNo61Class);
    } // setupUi

    void retranslateUi(QWidget *WgtVerifyNo61Class)
    {
        WgtVerifyNo61Class->setWindowTitle(QCoreApplication::translate("WgtVerifyNo61Class", "WgtVerifyNo61", nullptr));
        labelImage->setText(QString());
        toolButtonZoomIn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WgtVerifyNo61Class: public Ui_WgtVerifyNo61Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTVERIFYNO61_H
