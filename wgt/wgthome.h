#pragma once

#include <QWidget>
#include "ui_wgthome.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtHomeClass; };
QT_END_NAMESPACE

class WgtHome : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtHomeClass* ui;
public:
	WgtHome(QWidget *parent = nullptr);
	~WgtHome();

private slots:
	void netCameraAvailable(bool isAvailable);
};

