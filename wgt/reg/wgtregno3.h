#pragma once

#include <QWidget>
#include "ui_wgtregno3.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo3Class; };
QT_END_NAMESPACE

class WgtRegNo3 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtRegNo3Class* ui;
public:
	WgtRegNo3(QWidget *parent = nullptr);
	~WgtRegNo3();
    void updateShow();
	bool updateRegData();

protected:
	// 重写事件过滤器
	bool eventFilter(QObject* watched, QEvent* event) override;
	void hideEvent(QHideEvent* event)override;
private:
	bool mIsDrawing = false;
	QPoint mDrawMarkedPoint;
	QSet<QString> mMarkedList;
	QString mMarkedName;
	QImage mMarkedImage;
	QPixmap mMarkedPixmap;
private:
    void drawMarked();

private slots:
	void on_pushButtonMarked_clicked();
    void on_pushButtonReMarked_clicked();
	void on_pushButtonAutoMarked_clicked();
	void imageSelected(QString name, QImage image);
	void markedImageClicked(QString name, QImage image);
};

