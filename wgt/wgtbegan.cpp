#include "wgtbegan.h"

WgtBegan::WgtBegan(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtBeganClass())
{
	ui->setupUi(this);
	ui->label->setPixmap(QPixmap(":/image/began.png"));
	ui->label->setScaledContents(true);  // 自动拉伸填充（可能变形）
}

WgtBegan::~WgtBegan()
{
	delete ui;
}

