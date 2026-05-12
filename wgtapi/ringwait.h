#pragma once

#include <QtMath>
#include <QDialog>
#include <QPainter>
#include <QTimer>
#include <QPainterPath>

class RingWait : public QDialog
{
	Q_OBJECT
public:
	RingWait(QWidget* parent = nullptr);
	~RingWait();

protected:
	void paintEvent(QPaintEvent*);
private:
    QTimer* mTimer;
	int mOffset;
};

