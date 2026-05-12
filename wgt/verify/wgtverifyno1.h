#pragma once

#include <QWidget>
#include <QScroller>
#include <QWidget>
#include "ui_wgtverifyno1.h"
#include "batchview.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo1Class; };
QT_END_NAMESPACE

class WgtVerifyNo1 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo1Class* ui;
public:
	WgtVerifyNo1(QWidget *parent = nullptr);
	~WgtVerifyNo1();
	void updateShow(bool isNew = true);
	bool updateVerifyData();
	bool back();
protected:
private:
	QScroller* mScroller;
	QScroller* mBatchScroller;
	QScroller* mListScroller;
	BatchView* mListBatchView = nullptr;
	QList<BatchView*> mBatchInfoList; // 批次列表
	QList<Artifact::BaseInfo> mBaseInfoList;
	bool mIsListMode = true; // 是否是列表模式
	int mBatchPageIndex = 1; // 批次页码
	int mListPageIndex = 1; // 列表页码
	int mBatchPageCount = 1; // 批次总页数
	int mListPageCount = 1; // 列表总页数
	Artifact::BatchInfo mCurrentBatchInfo; // 当前批次ID
	Artifact::BaseInfo mCurrentBaseInfo;
private:
	void updateBatchTable();
	void updateListTable();
	void clearBaseInfo();
	void showBaseInfo();
private slots:
	void on_pushButtonSCode_clicked();
	void on_pushButtonMode_clicked();

	void on_toolButtonBatchUpPage_clicked();
	void on_toolButtonBatchNextPage_clicked();
	void on_toolButtonListUpPage_clicked();
	void on_toolButtonListNextPage_clicked();
	void tableWidgetListCellClicked(int row, int column);
	void buttonListBackClicked(Artifact::BatchInfo batchInfo);

	void buttonClicked(Artifact::BatchInfo batchInfo);
};

