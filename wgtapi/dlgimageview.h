#pragma once

#include <QDialog>
#include "ui_dlgimageview.h"
#include <QImage>
#include <QScroller>
QT_BEGIN_NAMESPACE
namespace Ui { class DlgImageViewClass; };
QT_END_NAMESPACE

class DlgImageView : public QDialog
{
	Q_OBJECT

public:
	DlgImageView(QWidget *parent = nullptr);
	~DlgImageView();
	void setImage(const QImage& image, const QString& imageName);
	void setImage(const QImage& image1, const QString& imageName1, const QImage& image2, const QString& imageName2);
	void setDelete(bool isDelete=false);
	bool isDelete();
protected:
	void paintEvent(QPaintEvent* event) override;

private:
	Ui::DlgImageViewClass *ui;
	QScroller* mScroller;
	QImage mImage;
	QString mImageName;
	QImage mImage2;
	QString mImageName2;
	quint8 mIsPaint = 0;
	bool mIsDelete = false;
private slots:	
	void on_pushButtonDelete_clicked();
	void on_pushButtonSwitch_clicked();
	void on_pushButtonQuit_clicked();
	void on_pushButtonZoomIn_clicked();
    void on_pushButtonZoomOut_clicked();
};

