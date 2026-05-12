#pragma once

#include <QDialog>
#include "ui_wgtverifyno31.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo31Class; };
QT_END_NAMESPACE

class WgtVerifyNo31 : public QDialog
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo31Class* ui;
	enum RefImageType {
		None,
		Ref50,
		RefLeft,
		RefRight
	};
	RefImageType refImageType = None;
	QImage refImage;
public:
	WgtVerifyNo31(QWidget *parent = nullptr);
	~WgtVerifyNo31();
protected:
	void paintEvent(QPaintEvent* event) override;
private:
	QImage mRefmarkImage;
};

