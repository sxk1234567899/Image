#pragma once

#include <QWidget>
#include <QButtonGroup>
#include <QScroller>
#include "ui_wgtset.h"
#include "networkspeedtester.hpp"
#include "appconfig.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WgtSetClass; };
QT_END_NAMESPACE

class WgtMain;
class WgtSet : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtSetClass* ui;
public:
	WgtSet(QWidget *parent = nullptr);
	~WgtSet();
	void back();
public slots:
	void updateUIShow();
signals:
	void wifiConnectStatus(bool status,QString name);
	void net4GConnectStatus(bool status,QString name);
protected:
	void showEvent(QShowEvent* event)override;
	void hideEvent(QHideEvent* event)override;
private:
	QButtonGroup* mButtonSetGroup; // 按钮组，用于管理设置按钮
	QButtonGroup* mButtonSetNet; // 按钮组，用于管理其他按钮
	QScroller* mScroller;
	QTimer* mShowTimer;
	NetworkSpeedTester *mNetworkSpeedTester;
	std::map<std::string, int> wlanMap;
	VersionInfo mVersionInfo;
	WgtMain* mWgtMain;
private slots:
	void tableWidgetWifiCellClicked(int row, int column);
	
private slots:
	void buttonSetGroupClicked(int id);
	void buttonSetNetClicked(int id);	

	void on_sliderSysVolume_valueChanged(int value);
	void on_sliderBrightness_valueChanged(int value);

	void on_pushButtonNetConn_clicked();
	void on_pushButtonUSBConn_clicked();
	void on_pushButtonNetCamSet_clicked();


	void on_pushButtonBtConnect_clicked();
	void on_pushButtonTestPrint_clicked();

	void on_checkBoxWifi_toggled(bool checked);
	void on_pushButtonUpdateWifi_clicked();
	void on_pushButtonTestWifi_clicked(bool checked);

	void on_checkBox4g_toggled(bool checked);
	void on_pushButtonUpdate4G_clicked();
	

	void on_pushButtonCheckUpdates_clicked();
};

