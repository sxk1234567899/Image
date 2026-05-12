#pragma once

#include <QWidget>
#include "ui_wgtverifyno61.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo61Class; };
QT_END_NAMESPACE

class WgtVerifyNo61 : public QWidget
{
	Q_OBJECT

public:	
	Ui::WgtVerifyNo61Class* ui;
	QImage mImage;
	QString mImageName;
public:
	WgtVerifyNo61(QWidget *parent = nullptr);
	~WgtVerifyNo61();
	void setImage(const QImage& image, const QString& imageName);
private:
private slots:
	void on_toolButtonZoomIn_clicked();
};

