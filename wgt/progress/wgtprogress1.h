#pragma once

#include <QWidget>
#include "ui_wgtprogress1.h"
#include <QScroller>
QT_BEGIN_NAMESPACE
namespace Ui { class WgtProgress1Class; };
QT_END_NAMESPACE

class WgtProgress1 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtProgress1Class* ui;
	QList<QString> mBatchList;
public:
	WgtProgress1(QWidget *parent = nullptr);
	~WgtProgress1();
	void addRegItem(const QString& name, const QString& globalImg, const QString& markImg, const QString& hgtImg, const QString& status);
	void addVerifyItem(const QString& number,const QString& name, const QString& batch, const QString& time, const QString& globalImg, const QString& hgtImg, const QString& status, const QString& imgStatus);
	void updateRegItem(int row, const QString& name, const QString& globalImg, const QString& markImg, const QString& hgtImg, const QString& status);
	void updateVerifyItem(const QString& number, const QString& name, const QString& batch, const QString& time, const QString& globalImg, const QString& hgtImg, const QString& status, const QString& imgStatus);
private:
	QScroller* mRegScroller;
	QScroller* mVerifyScroller;
	Qt::SortOrder mSortOrder = Qt::DescendingOrder;
private slots:
	void on_VerifyHeader_Clicked(int logicalIndex);
	void on_comboBoxBatch_currentTextChanged(const QString& text);
};

