#pragma once

#include <QWidget>
#include <QScroller>
#include <QtMultimedia>
#include "ui_wgtverifyno6.h"
#include "wgtverifyno61.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtVerifyNo6Class; };
QT_END_NAMESPACE

class WgtVerifyNo6 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtVerifyNo6Class* ui;
public:
	WgtVerifyNo6(QWidget *parent = nullptr);
	~WgtVerifyNo6();
    void updateShow(QString number);
    bool updateVerifyData();
protected:
private:
	QScroller* mScroller;
	QGridLayout* mGridLayout;
	QSpacerItem* mVSpacer;

	QMediaPlayer* mPlayer;
	QAudioOutput* mAudioOutput;

	QHash<QString, WgtVerifyNo61*> mImageHash; //存储图片
	QHash<QString, QLabel*> mImageNameHash; //存储图片名称
private:
	void clearImage();
	void displayImages(QString imageName1, const  QMap<QString, QImage>* imageList1, QString imageName2, const  QMap<QString, QImage>* imageList2);
};

