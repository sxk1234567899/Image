#pragma once

#include <QDialog>
#include "ui_wgtregno41.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo41Class; };
QT_END_NAMESPACE

class WgtRegNo41 : public QDialog
{
	Q_OBJECT
public:
	Ui::WgtRegNo41Class* ui;
	bool mIsCrosshair = false;
public:
	WgtRegNo41(QWidget *parent = nullptr);
	~WgtRegNo41();
protected:
	void paintEvent(QPaintEvent* event) override;
private:
};

