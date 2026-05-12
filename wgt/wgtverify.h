#pragma once

#include <QWidget>
#include "ui_wgtverify.h"

#include "wgtverifyno1.h"
#include "wgtverifyno2.h"
#include "wgtverifyno3.h"
#include "wgtverifyno4.h"
#include "wgtverifyno5.h"
#include "wgtverifyno6.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyClass; };
QT_END_NAMESPACE
class WgtMain;
class WgtVerify : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtVerifyClass* ui;

	WgtVerifyNo1* mWgtVerifyNo1;
	WgtVerifyNo2* mWgtVerifyNo2;
	WgtVerifyNo3* mWgtVerifyNo3;
	WgtVerifyNo4* mWgtVerifyNo4;
	WgtVerifyNo5* mWgtVerifyNo5;
	WgtVerifyNo6* mWgtVerifyNo6;
public:
	WgtVerify(QWidget *parent = nullptr);
	~WgtVerify();
	void back();
	void newVerify();
	void continueVerify(int verifyNo);

	void showVerifyResult(QString number);
private:
	
	QStringList names;

	WgtMain* mWgtMain;
	const int mUpdateTime = 10;
private:
	void on_pushButtonGoVerify1_clicked();
private slots:
	void on_pushButtonGoVerify2_clicked(bool isNoSave = false);
	void on_pushButtonGoVerify3_clicked(bool isNoSave = false);
	void on_pushButtonGoVerify4_clicked(bool isNoSave = false);
	void on_pushButtonSkipSampling_clicked();
	void on_pushButtonGoVerify5_clicked(bool isNoSave = false);
	void on_pushButtonBackHome_clicked();
	void on_pushButtonReVerify_clicked();
};

