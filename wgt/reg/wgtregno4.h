#pragma once

#include <QWidget>
#include "ui_wgtregno4.h"
#include "wgtregno41.h"
#include "appconfig.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo4Class; };
QT_END_NAMESPACE

class WgtRegNo4 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtRegNo4Class* ui;
public:
	WgtRegNo4(QWidget *parent = nullptr);
	~WgtRegNo4();
    void updateShow();
	bool updateRegData();
protected:
	bool eventFilter(QObject* obj, QEvent* event) override;
	void hideEvent(QHideEvent* event)override;
	
private:
	QString mPhotoName;
	bool isHgtPhoto;
	bool isLowPhoto;
	WgtRegNo41* mWgtRegNo41;
	QString mlowImgName;
	QImage mLowImage;
	NetCameraConf netCameraConf;
private:
	bool reconnectNetCamera();
private slots:
	void on_radioButtonLow_clicked();
	void on_radioButtonHgt_clicked();
	void on_pushButtonPhoto_clicked();
    void on_pushButtonGoPhoto_clicked();

	void on_toolButtonCrosshair_clicked(bool checked);
	void on_toolButtonFocus_clicked();

	void on_toolButtonManualFocus_clicked(bool checked);
	void on_toolButtonFocusAdd_clicked();
	void on_toolButtonFocusSub_clicked();
private slots:
	void picture(QImage image);

	void imageSelected(QString name, QImage image);
	void imageView(QString name, QImage image);
	void highImageClicked(QString name, QImage image);
};

