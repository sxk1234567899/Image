#pragma once

#include <QWidget>
#include "ui_wgtreg.h"

#include "wgtregno1.h"
#include "wgtregno2.h"
#include "wgtregno3.h"
#include "wgtregno4.h"
#include "wgtregno5.h"
#include "wgtregno6.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegClass; };
QT_END_NAMESPACE

class WgtMain;

class WgtReg : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtRegClass* ui;
	WgtRegNo1* mWgtRegNo1;
	WgtRegNo2* mWgtRegNo2;
	WgtRegNo3* mWgtRegNo3;
	WgtRegNo4* mWgtRegNo4;
	WgtRegNo5* mWgtRegNo5;
	WgtRegNo6* mWgtRegNo6;
public:
	WgtReg(QWidget *parent = nullptr);
	~WgtReg();
	void back();
	void newReg();
	void continueReg(int regNo);
private:


	QStringList names;

	WgtMain* mWgtMain;


	const int mUpdateTime = 10;
private:
	void on_pushButtonGoReg1_clicked();
private slots:
	void on_pushButtonGoReg2_clicked(bool isNoSave = false);
	void on_pushButtonGoReg3_clicked(bool isNoSave = false);
	void on_pushButtonSkipSampling_clicked();
	void on_pushButtonGoReg4_clicked(bool isNoSave = false);
	void on_pushButtonGoReg5_clicked(bool isNoSave = false);
	void on_pushButtonGoReg6_clicked(bool isNoSave = false);
	void on_pushButtonRegDelete_clicked();
	void on_pushButtonBackHome_clicked();
	
};

