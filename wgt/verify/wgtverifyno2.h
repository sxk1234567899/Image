#pragma once

#include <QWidget>
#include <QScroller>
#include "ui_wgtverifyno2.h"
#include "wgtverifyno21.h"
#include "config/appconfig.h"
#include "verifythread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo2Class; };
QT_END_NAMESPACE

class WgtVerifyNo2 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo2Class* ui;
public:
	WgtVerifyNo2(QWidget *parent = nullptr);
	~WgtVerifyNo2();
    void updateShow(bool isNew = true);
	bool updateVerifyData();
protected:
	void hideEvent(QHideEvent* event)override;
private:
	QList< WgtVerifyNo21 *> wgtVerifyNo21List;
	QScroller* mScroller;
	MinioConf minioConf;
private:
};

