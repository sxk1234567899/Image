#include "wgtregno21.h"
#include <QPainter>
WgtRegNo21::WgtRegNo21(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::WgtRegNo21Class())
{
	ui->setupUi(this);
    // 设置为透明背景
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_NoSystemBackground, false);
    setAttribute(Qt::WA_TransparentForMouseEvents);  // 鼠标事件穿透到下层
    setStyleSheet("background-color: transparent;");
    ui->toolButtonCrosshair->setCheckable(true);
    ui->toolButtonCrosshair->setChecked(false);
}

WgtRegNo21::~WgtRegNo21()
{
	delete ui;
}

void WgtRegNo21::paintEvent(QPaintEvent* event)
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
        painter.drawRect(x / 2 - 40, y / 2 - 40, 80, 80);
        painter.end();
    }
    //QWidget::paintEvent(event);
}
