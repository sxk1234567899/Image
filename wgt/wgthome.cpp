#include "wgthome.h"
#include <QStorageInfo>
#include "usbcamera.h"
#include "netcamera.h"
WgtHome::WgtHome(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtHomeClass())
{
	ui->setupUi(this);

	connect(NetCamera::instance(), &NetCamera::available,this, &WgtHome::netCameraAvailable,Qt::QueuedConnection);
	netCameraAvailable(NetCamera::instance()->isAvailable());
}

WgtHome::~WgtHome()
{
	delete ui;
}
void WgtHome::netCameraAvailable(bool isAvailable)
{
	if (isAvailable)
	{
		ui->labelNetCamera->setText("已连：显微摄像");
		ui->labelNetCamera->setStyleSheet("color:#000");
	}
	else
	{
		ui->labelNetCamera->setText("未连：显微摄像");
		ui->labelNetCamera->setStyleSheet("color:#DE2600");
	}
}
