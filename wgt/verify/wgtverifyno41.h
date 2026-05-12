#pragma once

#include <QDialog>
#include "ui_wgtverifyno41.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo41Class; };
QT_END_NAMESPACE

class WgtVerifyNo41 : public QDialog
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo41Class* ui;
	enum RefImageType {
		None,
		Ref50,
		RefLeft,
		RefRight
	};
	RefImageType refImageType = None;
	QImage refImage;
public:
	WgtVerifyNo41(QWidget *parent = nullptr);
	~WgtVerifyNo41();
protected:
	void paintEvent(QPaintEvent* event) override;
private:
	QImage mRefmarkImage;
};

