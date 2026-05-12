
#include "ringwait.h"

RingWait::RingWait(QWidget* parent)
	: QDialog(parent)
	,mTimer(new QTimer(this))
{
	mOffset = 0;
	setModal(true);//阻止与其他窗口交互，必须先关闭当前窗口。
	setFixedSize(200, 200);
	//去掉标题栏 设置置顶 去掉任务栏图标
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);

	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground, true);

	connect(mTimer, &QTimer::timeout, [this]() {
		++mOffset;
		if (mOffset > 11)
		{
			mOffset = 0;
		}
		update();
	});
    mTimer->start(50);
}

RingWait::~RingWait()
{
	close();
	QWidget * widget = qobject_cast<QWidget*>(this->parent());
	if (widget)
	{
		widget->activateWindow();
	}
}


void RingWait::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	//启动反锯齿
	painter.setRenderHint(QPainter::Antialiasing, true);
	int width = this->width();
	int height = this->height();
	//画笔移动到中间
	painter.translate(width >> 1, height >> 1);

	int offsetDest = (width - 30) / 2;
	painter.setPen(Qt::NoPen);
	//计算小圆坐标
	for (int i = 0; i < 3; ++i) 
	{
		QPoint point(0, 0);
		painter.setBrush(QColor(50 + i * 50, 20 + i * 90, 40 + i * 5, 80 + i * 80));
		point.setX(offsetDest * qSin((-mOffset + i) * M_PI / 6));
		point.setY(offsetDest * qCos((-mOffset + i) * M_PI / 6));
		painter.drawEllipse(point.x() - 10, point.y() - 10, 20, 20);
	}
	for (int i = 0; i < 9; ++i) 
	{
		QPoint point(0, 0);
		painter.setBrush(QColor(255, 190 - i * 20, i * 15, 255 - i * 32));
		point.setX(offsetDest * qSin((-mOffset + i + 3) * M_PI / 6));
		point.setY(offsetDest * qCos((-mOffset + i + 3) * M_PI / 6));
		painter.drawEllipse(point.x() - 10, point.y() - 10, 20, 20);
	}
}
