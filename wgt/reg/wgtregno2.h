#pragma once
#include <QImage>
#include <QWidget>
#include "ui_wgtregno2.h"
#include <QLabel>
#include <QButtonGroup>
#include "wgtregno21.h"


QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo2Class; };
QT_END_NAMESPACE


class WgtRegNo2 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtRegNo2Class* ui;
public:
	WgtRegNo2(QWidget *parent = nullptr);
	~WgtRegNo2();
    void updateShow();
	bool updateRegData();
protected:
	bool eventFilter(QObject* obj, QEvent* event) override;  
	void hideEvent(QHideEvent* event)override;
private:
	QButtonGroup *mRadioButton;
	int mpIndex;
	WgtRegNo21 *mWgtRegNo21;

private:
    //void updateImage();
private slots:
	void on_toolButtonPhoto_clicked();
	void on_toolButtonCrosshair_clicked(bool checked);

	void radioButtonClicked(int id);

	void picture(QImage image);

	void imageClicked(QString name, QImage image);
};

