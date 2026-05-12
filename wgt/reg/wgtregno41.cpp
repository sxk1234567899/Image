#include "wgtregNo41.h"
#include <QPainter>
WgtRegNo41::WgtRegNo41(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::WgtRegNo41Class())
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_NoSystemBackground, false);
	//setAttribute(Qt::WA_TransparentForMouseEvents);  // 鼠标事件穿透到下层
	setStyleSheet("background-color: transparent;");
    ui->toolButtonCrosshair->setCheckable(true);
    ui->toolButtonCrosshair->setChecked(false);
    ui->toolButtonManualFocus->setCheckable(true);
    ui->toolButtonManualFocus->setChecked(false);
    ui->toolButtonFocusAdd->setVisible(false);
    ui->toolButtonFocusSub->setVisible(false);
}

WgtRegNo41::~WgtRegNo41()
{
	delete ui;
}

void WgtRegNo41::paintEvent(QPaintEvent* event)
{
    if (mIsCrosshair)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        // 绘制红色矩形（带有动画效果）
        int x = this->width();
        int y = this->height();
        painter.setPen(QPen(Qt::red, 2));
        painter.setBrush(Qt::transparent);
        /*画十字*/
        painter.drawLine(0, y / 2, x, y / 2);
        painter.drawLine(x / 2, 0, x / 2, y);
        /*画正方形*/
        painter.setPen(QPen(Qt::red, 4));
        painter.drawRect(x / 2 - 48, y / 2 - 27, 96, 54);
        painter.end();
    }
}