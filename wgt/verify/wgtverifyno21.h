#pragma once

#include <QWidget>
#include "ui_wgtverifyno21.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo21Class; };
QT_END_NAMESPACE

class WgtVerifyNo21 : public QWidget
{
	Q_OBJECT

public:
	WgtVerifyNo21(QWidget *parent = nullptr);
	~WgtVerifyNo21();
	void setImage(QImage image,QString name);
	void setLeftLineVisible(bool visible =false);
    void setRightLineVisible(bool visible= false);
private:
	Ui::WgtVerifyNo21Class *ui;
	QImage mImage;
	QString mImageName;
private slots:
	void on_toolButtonZoomIn_clicked();
};

