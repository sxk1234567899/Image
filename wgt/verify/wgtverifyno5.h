#pragma once

#include <QWidget>
#include "ui_wgtverifyno5.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo5Class; };
QT_END_NAMESPACE

class WgtVerifyNo5 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo5Class* ui;
public:
	WgtVerifyNo5(QWidget *parent = nullptr);
	~WgtVerifyNo5();
    void updateShow();
    bool updateVerifyData();
signals:
	void verifyNo5Finished(QString number);
protected:
	void hideEvent(QHideEvent* event)override;
private:
	QTimer* mShowTimer;
	int rIndex1 = 0;
	int rIndex2 = 0;
	int vIndex1 = 0;
	int vIndex2 = 0;
private slots:
	void updateShowTimer();
};

