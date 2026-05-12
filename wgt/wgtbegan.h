#pragma once

#include <QWidget>
#include "ui_wgtbegan.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtBeganClass; };
QT_END_NAMESPACE

class WgtBegan : public QWidget
{
	Q_OBJECT

public:
	WgtBegan(QWidget *parent = nullptr);
	~WgtBegan();

private:
	Ui::WgtBeganClass *ui;
};

