#pragma once

#include <QWidget>
#include "ui_wgtverifyno3.h"
#include "wgtverifyno31.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo3Class; };
QT_END_NAMESPACE

class WgtVerifyNo3 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo3Class* ui;


public:
	WgtVerifyNo3(QWidget *parent = nullptr);
	~WgtVerifyNo3();
    void updateShow();
	bool updateVerifyData();
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;
	void hideEvent(QHideEvent* event)override;
private:
	WgtVerifyNo31 *mWgtVerifyNo31;
	QString mImageName;
	QImage mImage;
private slots:
	void on_toolButtonPhoto_clicked();
	void on_toolButtonRefImage_clicked();

	void picture(QImage image);
	void rawImageSelected(QString name, QImage image);
	void verifyimageClicked(QString name, QImage image);
};

