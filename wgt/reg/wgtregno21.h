#pragma once

#include <QDialog>
#include "ui_wgtregno21.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo21Class; };
QT_END_NAMESPACE

class WgtRegNo21 : public QDialog
{
	Q_OBJECT
public:
	Ui::WgtRegNo21Class* ui;
	bool mIsCrosshair = false;
public:
	WgtRegNo21(QWidget *parent = nullptr);
	~WgtRegNo21();
protected:
	void paintEvent(QPaintEvent* event) override;
private:

private slots:
};

