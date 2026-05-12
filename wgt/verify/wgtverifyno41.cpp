#include "wgtverifyno41.h"
#include <QPainter>
WgtVerifyNo41::WgtVerifyNo41(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::WgtVerifyNo41Class())
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_NoSystemBackground, false);
	setAttribute(Qt::WA_TransparentForMouseEvents);  // 鼠标事件穿透到下层
	setStyleSheet("background-color: transparent;");
    refImage = QImage(":/image/reftest.jpg");
	mRefmarkImage = QImage(":/image/refmark.png");
	mRefmarkImage = mRefmarkImage.scaled(98,37, Qt::KeepAspectRatio);
}

WgtVerifyNo41::~WgtVerifyNo41()
{
	delete ui;
}

void WgtVerifyNo41::paintEvent(QPaintEvent* event)
{
	if (refImageType == None)
	{
		return;
	}
	QPainter painter(this);
	QRect rect(refImage.rect());
	int halfWidth = refImage.width() / 2;
	if (refImageType == WgtVerifyNo41::Ref50)
	{
		// 设置透明度：50%（alpha=128） 0.0-1.0 范围，0.5 即 50%
		painter.setOpacity(0.5); 	
	}
	else if (refImageType == WgtVerifyNo41::RefLeft)
	{
		rect.setWidth(halfWidth);
	}
	else if (refImageType == WgtVerifyNo41::RefRight)
	{
		rect.setLeft(halfWidth);
		rect.setWidth(halfWidth);
	}
	painter.drawImage(rect, refImage, rect);
	painter.setOpacity(1);
	QPoint point = ui->toolButtonRefImage->pos();
    point.setX(point.x() + ui->toolButtonRefImage->width() / 2 - mRefmarkImage.width() / 2);
    point.setY(point.y() - mRefmarkImage.height());
	painter.drawImage(point, mRefmarkImage);
	painter.setPen(QPen(Qt::red, 6));
	painter.setBrush(Qt::transparent);
	painter.drawRect(refImage.rect());
	painter.end();
}