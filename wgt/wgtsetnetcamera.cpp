#include "wgtsetnetcamera.h"
#include "appconfig.h"
#include "dlgInfo.h"
#include <QIntValidator>
WgtSetNetCamera::WgtSetNetCamera(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::WgtSetNetCameraClass())
{
	ui->setupUi(this);
	setModal(true);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	ui->pushButtonYes->setDefault(false);
	ui->pushButtonYes->setAutoDefault(false);
	ui->lineEditLowZoom->setValidator(new QIntValidator(ui->lineEditLowZoom));
	ui->lineEditHighZoom->setValidator(new QIntValidator(ui->lineEditHighZoom));

	NetCameraConf conf = AppConfig::instance()->netCameraConf();
    ui->lineEditLowZoom->setText(QString::number(conf.lowZoom));
    ui->lineEditHighZoom->setText(QString::number(conf.highZoom));
}

WgtSetNetCamera::~WgtSetNetCamera()
{
	delete ui;
}

void WgtSetNetCamera::on_pushButtonYes_clicked()
{
    NetCameraConf conf = AppConfig::instance()->netCameraConf();
    conf.lowZoom = ui->lineEditLowZoom->text().toInt();
    conf.highZoom = ui->lineEditHighZoom->text().toInt();
    AppConfig::instance()->setNetCameraConf(conf);
	DlgInfo::messageBox(this, tr("保存显微镜参数"), tr("保存参数成功"), tr("确认"), tr("删除"), false);

}