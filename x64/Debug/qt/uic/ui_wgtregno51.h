/********************************************************************************
** Form generated from reading UI file 'wgtregno51.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGNO51_H
#define UI_WGTREGNO51_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtRegNo51Class
{
public:
    QCheckBox *checkBoxSetMain;
    QLabel *labelImage;
    QToolButton *toolButtonZoomIn;
    QLabel *lableImageName;

    void setupUi(QWidget *WgtRegNo51Class)
    {
        if (WgtRegNo51Class->objectName().isEmpty())
            WgtRegNo51Class->setObjectName("WgtRegNo51Class");
        WgtRegNo51Class->resize(400, 275);
        WgtRegNo51Class->setMinimumSize(QSize(400, 275));
        WgtRegNo51Class->setMaximumSize(QSize(400, 275));
        checkBoxSetMain = new QCheckBox(WgtRegNo51Class);
        checkBoxSetMain->setObjectName("checkBoxSetMain");
        checkBoxSetMain->setGeometry(QRect(10, 10, 130, 30));
        checkBoxSetMain->setMinimumSize(QSize(130, 30));
        labelImage = new QLabel(WgtRegNo51Class);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(0, 0, 400, 225));
        labelImage->setMinimumSize(QSize(400, 225));
        labelImage->setMaximumSize(QSize(400, 225));
        toolButtonZoomIn = new QToolButton(WgtRegNo51Class);
        toolButtonZoomIn->setObjectName("toolButtonZoomIn");
        toolButtonZoomIn->setGeometry(QRect(340, 165, 50, 50));
        toolButtonZoomIn->setMinimumSize(QSize(50, 50));
        toolButtonZoomIn->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/zoom.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButtonZoomIn->setIcon(icon);
        toolButtonZoomIn->setIconSize(QSize(50, 50));
        lableImageName = new QLabel(WgtRegNo51Class);
        lableImageName->setObjectName("lableImageName");
        lableImageName->setGeometry(QRect(0, 225, 400, 50));
        lableImageName->setMinimumSize(QSize(400, 50));
        lableImageName->setMaximumSize(QSize(400, 50));
        lableImageName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelImage->raise();
        checkBoxSetMain->raise();
        toolButtonZoomIn->raise();
        lableImageName->raise();

        retranslateUi(WgtRegNo51Class);

        QMetaObject::connectSlotsByName(WgtRegNo51Class);
    } // setupUi

    void retranslateUi(QWidget *WgtRegNo51Class)
    {
        WgtRegNo51Class->setWindowTitle(QCoreApplication::translate("WgtRegNo51Class", "WgtRegNo51", nullptr));
        checkBoxSetMain->setText(QCoreApplication::translate("WgtRegNo51Class", "\350\256\276\344\270\272\344\270\273\345\233\276", nullptr));
        labelImage->setText(QString());
        toolButtonZoomIn->setText(QString());
        lableImageName->setText(QCoreApplication::translate("WgtRegNo51Class", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WgtRegNo51Class: public Ui_WgtRegNo51Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGNO51_H
