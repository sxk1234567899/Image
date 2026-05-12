#include "refreshviewlabel.h"
#include <QPainter>
#include <QDebug>
#include <QLinearGradient>
#include <QDateTime>
#include <QPixmap>
#include <QImage>
RefreshViewLabel::RefreshViewLabel(QWidget *parent)
	: QLabel(parent)
	, mTimer(new QTimer(this))
{
    mStepSize =10;
    mWidth = 87;
    mStartX = 0;
    setAlignment(Qt::AlignCenter);
	connect(mTimer, &QTimer::timeout, this, &RefreshViewLabel::refreshView);
}

RefreshViewLabel::~RefreshViewLabel()
{}

void RefreshViewLabel::paintEvent(QPaintEvent* event)
{
    // 调用基类的paintEvent
    QLabel::paintEvent(event);
    if(mIsAnimating)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        // 创建线性渐变（从左到右）
        QLinearGradient gradient(mStartX, 0, mStartX + mWidth, 0);
        gradient.setColorAt(0, QColor(0x8AB1FF)); // 中间颜色
        gradient.setColorAt(1.0, QColor(0x1563FF));
        gradient.setSpread(QGradient::ReflectSpread); // 设置渐变填充方式
        gradient.setCoordinateMode(QGradient::LogicalMode); // 设置坐标模式
        // 绘制长方形，填充线性渐变
        painter.setPen(Qt::NoPen); // 不绘制边框
        painter.setBrush(gradient);
        painter.setOpacity(0.8);
        // 绘制矩形
        painter.drawRect(mStartX, 0, mWidth, height());

        painter.end();
	}
    
}
void RefreshViewLabel::refreshView()
{
	mStartX += mStepSize;
    if (mStartX > width())
    {
        mStartX = 0;
    }
	update();
}
void RefreshViewLabel::setImage(QImage image)
{
    mImage = image.scaled(size(), Qt::KeepAspectRatio); 
    setPixmap(QPixmap::fromImage(mImage));
}
void RefreshViewLabel::startAnimation()
{
    if (!mTimer->isActive()) 
    {
        mTimer->start(50);
    }
	mIsAnimating = true;
    mStartX = 0; // 重置起始位置
	update(); // 触发重绘
}
void RefreshViewLabel::stopAnimation()
{
    if (mTimer->isActive()) {
        mTimer->stop();
    }
	mIsAnimating = false;
    mStartX = 0; // 重置起始位置
	update(); // 触发重绘
}