#include "wgtlogo.h"
#include "appconfig.h"
WgtLogo::WgtLogo(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtLogoClass())
{
	ui->setupUi(this);
	auto conf = AppConfig::instance()->netWorkServerConf();
	ui->lineEditUserName->setText(conf.username);
	ui->lineEditPassword->setText(conf.password);
}

WgtLogo::~WgtLogo()
{
	delete ui;
}

