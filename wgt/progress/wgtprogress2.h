#pragma once

#include <QWidget>
#include <QScroller>
#include "ui_wgtprogress2.h"
#include "regthread.h"
#include "verifythread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WgtProgress2Class; };
QT_END_NAMESPACE


class WgtProgress2 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtProgress2Class* ui;
public:
	WgtProgress2(QWidget *parent = nullptr);
	~WgtProgress2();
	void updateShow(bool isReg,QString number);
	void updateShow()
	{
		updateShow(mIsReg, mNumber);
	}
private:
	bool mIsReg = true; //是否登记
	QString mNumber =""; //登记编号
	QStringList mImageNames; //存储图片名称

	QScroller* mScroller;
private:
	void tabStatus(int row, ImageStatus stat);
private slots:
	void tableWidgetClicked(int row, int column);
};

