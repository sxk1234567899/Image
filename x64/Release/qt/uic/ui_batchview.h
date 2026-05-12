/********************************************************************************
** Form generated from reading UI file 'batchview.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHVIEW_H
#define UI_BATCHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatchViewClass
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *labelCreateTime;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QSpinBox *spinBoxRemaining;
    QSpinBox *spinBoxTotal;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelBatchName;
    QPushButton *pushButton;
    QLabel *labelTemp;

    void setupUi(QWidget *BatchViewClass)
    {
        if (BatchViewClass->objectName().isEmpty())
            BatchViewClass->setObjectName("BatchViewClass");
        BatchViewClass->resize(585, 78);
        BatchViewClass->setMinimumSize(QSize(585, 78));
        BatchViewClass->setMaximumSize(QSize(585, 78));
        gridLayout = new QGridLayout(BatchViewClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(BatchViewClass);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(15, 9, 15, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(80, 16777215));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        labelCreateTime = new QLabel(frame);
        labelCreateTime->setObjectName("labelCreateTime");

        horizontalLayout->addWidget(labelCreateTime);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        spinBoxRemaining = new QSpinBox(frame);
        spinBoxRemaining->setObjectName("spinBoxRemaining");
        spinBoxRemaining->setMinimumSize(QSize(50, 0));
        spinBoxRemaining->setMaximumSize(QSize(100, 16777215));
        spinBoxRemaining->setReadOnly(true);
        spinBoxRemaining->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxRemaining->setMinimum(0);
        spinBoxRemaining->setMaximum(99999);
        spinBoxRemaining->setValue(0);

        verticalLayout->addWidget(spinBoxRemaining);

        spinBoxTotal = new QSpinBox(frame);
        spinBoxTotal->setObjectName("spinBoxTotal");
        spinBoxTotal->setMinimumSize(QSize(50, 0));
        spinBoxTotal->setMaximumSize(QSize(100, 16777215));
        spinBoxTotal->setReadOnly(true);
        spinBoxTotal->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBoxTotal->setMaximum(99999);

        verticalLayout->addWidget(spinBoxTotal);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 2, 1);

        labelBatchName = new QLabel(frame);
        labelBatchName->setObjectName("labelBatchName");
        labelBatchName->setMinimumSize(QSize(350, 0));
        labelBatchName->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(labelBatchName, 0, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(90, 40));
        pushButton->setMaximumSize(QSize(90, 16777215));

        gridLayout_2->addWidget(pushButton, 0, 3, 2, 1);

        labelTemp = new QLabel(frame);
        labelTemp->setObjectName("labelTemp");
        labelTemp->setMinimumSize(QSize(1, 0));
        labelTemp->setMaximumSize(QSize(1, 50));

        gridLayout_2->addWidget(labelTemp, 0, 2, 2, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(BatchViewClass);

        QMetaObject::connectSlotsByName(BatchViewClass);
    } // setupUi

    void retranslateUi(QWidget *BatchViewClass)
    {
        BatchViewClass->setWindowTitle(QCoreApplication::translate("BatchViewClass", "BatchView", nullptr));
        label_4->setText(QCoreApplication::translate("BatchViewClass", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        labelCreateTime->setText(QCoreApplication::translate("BatchViewClass", "TextLabel", nullptr));
        spinBoxRemaining->setPrefix(QCoreApplication::translate("BatchViewClass", "\345\211\251\344\275\231\357\274\232", nullptr));
        spinBoxTotal->setPrefix(QCoreApplication::translate("BatchViewClass", "\346\200\273\346\225\260\357\274\232", nullptr));
        labelBatchName->setText(QCoreApplication::translate("BatchViewClass", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("BatchViewClass", "\346\237\245\347\234\213", nullptr));
        labelTemp->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BatchViewClass: public Ui_BatchViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHVIEW_H
