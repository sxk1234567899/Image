#pragma once

#include <QDialog>
#include "ui_wgtsetnetcamera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtSetNetCameraClass; };
QT_END_NAMESPACE

class WgtSetNetCamera : public QDialog
{
	Q_OBJECT

public:
	WgtSetNetCamera(QWidget *parent = nullptr);
	~WgtSetNetCamera();

private:
	Ui::WgtSetNetCameraClass *ui;
private slots:
	void on_pushButtonYes_clicked();
};

