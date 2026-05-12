#pragma once

#include <QWidget>
#include "ui_wgtprogress.h"
#include "wgtprogress1.h"
#include "wgtprogress2.h"
#include "regthread.h"
#include "verifythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtProgressClass; };
QT_END_NAMESPACE

class WgtMain;
class WgtProgress : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtProgressClass* ui;
	WgtProgress1* mWgtProgress1;
	WgtProgress2* mWgtProgress2;
public:
	WgtProgress(QWidget *parent = nullptr);
	~WgtProgress();
	void initProgress();
	void back();
	
public slots:
	void regDataAdded(QString number); //登记数据添加
	void regDataUpdated(QString number); //登记数据更新
	void regDataDeleted(QString number);//登记数据删除

	void verifyDataAdded(QString number);//验证数据添加
    void verifyDataUpdated(QString number);//验证数据更新
    void verifyDataDeleted(QString number);//验证数据删除
private:
	QList<QString> mRegNumber; // 用于存储登记的编号
	RegThread* regData=nullptr; // 获取注册数据线程实例
    VerifyThread* verifyData=nullptr;
	WgtMain* mWgtMain;
	QTimer* mShowTimer;
private:
	int getImageSavedCount(const QStringList names, const QMap<QString, ImageInfo>* imageInfo)const;
private slots:
	void on_pushButtonReg_clicked();
	void on_pushButtonVerify_clicked();
	void tableWidgetRegcellClicked(int row, int column);
	void tableWidgetVerifycellClicked(int row, int column);

	void showUpdata();
};

