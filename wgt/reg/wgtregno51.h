#pragma once

#include <QWidget>
#include "ui_wgtregno51.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo51Class; };
QT_END_NAMESPACE

class WgtRegNo51 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtRegNo51Class* ui;
	QImage mImage;
	QString mImageName;
public:
	WgtRegNo51(QWidget *parent = nullptr);
	~WgtRegNo51();
	void setImage(const QImage& image, const QString& imageName);
signals:

private slots:
	void on_toolButtonZoomIn_clicked();
};

