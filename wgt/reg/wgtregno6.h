#pragma once

#include <QWidget>
#include "ui_wgtregno6.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo6Class; };
QT_END_NAMESPACE

class WgtRegNo6 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtRegNo6Class* ui;
public:
	WgtRegNo6(QWidget *parent = nullptr);
	~WgtRegNo6();
    void updateShow();
	bool updateRegData();
protected:
 
private:
	QImage mImage;
	QImage *mPrintImage;
	QString mPrintFile;
private slots:
	void on_pushButtonPrint_clicked();
	void on_pushButtonBtConnect_clicked();
};

