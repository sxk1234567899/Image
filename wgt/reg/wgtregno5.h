#pragma once
#include <QWidget>
#include <QScroller>
#include <QButtonGroup>
#include "ui_wgtregno5.h"
#include "wgtregno51.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtRegNo5Class; };
QT_END_NAMESPACE

class WgtRegNo5 : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtRegNo5Class* ui;
public:
	WgtRegNo5(QWidget *parent = nullptr);
	~WgtRegNo5();
    void updateShow();
	bool updateRegData();
protected:

private:
	QScroller* mScroller;
	QGridLayout* mGridLayout;
	QSpacerItem* mVSpacer;

	QHash<QString, WgtRegNo51*> mImageHash; //存储图片
	QHash<QString, QLabel*> mImageNameHash; //存储图片名称
	QButtonGroup* mButtonGroup;
private:
	void clearImage();
	void displayImages(QString imageName,const  QMap<QString, QImage>* imageList,bool isButton = true);
private slots:
	void buttonToggled(QAbstractButton* button, bool checked);
};

