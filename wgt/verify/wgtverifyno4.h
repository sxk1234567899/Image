#pragma once

#include <QWidget>
#include "ui_wgtverifyno4.h"
#include "wgtverifyno41.h"
#include "appconfig.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo4Class; };
QT_END_NAMESPACE

class WgtVerifyNo4 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo4Class* ui;
public:
	WgtVerifyNo4(QWidget *parent = nullptr);
	~WgtVerifyNo4();
    void updateShow();
	bool updateVerifyData();
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;
	void hideEvent(QHideEvent* event)override;
private:
	WgtVerifyNo41* mWgtVerifyNo41;
	QString mRawHgtName;
	QImage mRawHgtImage;

    QString mRawLowName;
	QImage mRawLowImage;
	QString mLowName;
	QImage mLowImage;
	int mImageId;
    QString mRawMarkName;
    QImage mRawMarkImage;

	NetCameraConf netCameraConf;
	bool isHgtPhoto;
	bool isLowPhoto;
private:
	bool reconnectNetCamera();
private slots:
	void on_radioButtonLow_clicked();
	void on_radioButtonHgt_clicked();
	void on_pushButtonPhoto_clicked();
	void on_pushButtonGoPhoto_clicked();
	void on_pushButtonVerifyMode_toggled(bool checked);

	void on_toolButtonFocus_clicked();
	void on_toolButtonRefImage_clicked();
	void on_toolButtonManualFocus_clicked(bool checked);
	void on_toolButtonFocusAdd_clicked();
	void on_toolButtonFocusSub_clicked();
private slots:
	void picture(QImage image);

	void imageSelected(QString name, QImage image);
	void imageView(QString name, QImage image);
	void highImageClicked(QString name, QImage image);
};

