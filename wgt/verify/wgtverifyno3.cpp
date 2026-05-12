#include "wgtverifyno3.h"
#include "verifythread.h"
#include "usbcamera.h"
#include "dlgimageview.h"
#include "dlginfo.h"
#include "ringwait.h"
WgtVerifyNo3::WgtVerifyNo3(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo3Class())
	, mWgtVerifyNo31(new WgtVerifyNo31(this))
{
	ui->setupUi(this);
	ui->labelInfo->setText(QString("请您先进行全局拍摄，可以使用参照功能，将提供50%透明度或半边参考，\n辅助您进行二次拍摄对齐。"));
	ui->videoWidget->installEventFilter(this);
	ui->widgetRawImage->setEnableSelected(true);
	connect(ui->widgetRawImage, &ImageWidget::imageSelected, this, &WgtVerifyNo3::rawImageSelected, Qt::UniqueConnection);
	connect(ui->widgetVerifyImage, &ImageWidget::imageClicked, this, &WgtVerifyNo3::verifyimageClicked, Qt::UniqueConnection);
}

WgtVerifyNo3::~WgtVerifyNo3()
{
	delete ui;
}
bool WgtVerifyNo3::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == ui->videoWidget)
	{
		if ((event->type() == QEvent::WindowActivate && mWgtVerifyNo31->isActiveWindow())
			|| (event->type() == QEvent::WindowActivate && !mWgtVerifyNo31->isVisible())
			|| (event->type() == QEvent::Show))
		{
			mWgtVerifyNo31->setFixedSize(ui->videoWidget->size());
			mWgtVerifyNo31->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
			mWgtVerifyNo31->show();
			
		}
		if ((event->type() == QEvent::WindowDeactivate && !mWgtVerifyNo31->isActiveWindow())
			||(event->type()==QEvent::Hide))
		{
			mWgtVerifyNo31->hide();
			
		}
	}
	if (mWgtVerifyNo31->isVisible())
	{
		mWgtVerifyNo31->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
	}
	return QWidget::eventFilter(watched, event);
}
void WgtVerifyNo3::hideEvent(QHideEvent* event)
{
	ui->widgetRawImage->setImage(nullptr);
	ui->widgetVerifyImage->setImage(nullptr);
}
void WgtVerifyNo3::updateShow()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	if (USBCamera::instance()->start(ui->videoWidget))
	{
		connect(USBCamera::instance(), &USBCamera::picture, this, &WgtVerifyNo3::picture, Qt::UniqueConnection);
		mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(true);
	}
	else
	{
		DlgInfo::messageBox(this, "提示", "请检查USB摄像头是否正常连接！", "确定", "否", false);
		mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(false);
	}

	auto data = VerifyThread::instance();
	QString number = data->getVerifyNumber();
	if (!number.isEmpty())
	{
		QStringList list = data->getRawGlobalImage(number)->keys();
		for (int i = 0; i < list.size(); i++)
		{
			list[i] = gVerifyNameHeader + list[i];
		}
		ui->widgetVerifyImage->setNamelist(list);
		ui->widgetRawImage->setImage(data->getRawGlobalImage(number));
		ui->widgetVerifyImage->setImage(data->getGlobalImage(number));
		ui->widgetRawImage->updateImage();
		ui->widgetVerifyImage->updateImage();
		ui->spinBoxRaw->setValue(ui->widgetRawImage->getImageNum());
		ui->spinBoxVerify->setValue(ui->widgetVerifyImage->getImageNum());
		this->setEnabled(true);
	}
	else
	{
		ui->widgetRawImage->setImage(nullptr);
		ui->widgetVerifyImage->setImage(nullptr);
		this->setEnabled(false);
	}
}
bool WgtVerifyNo3::updateVerifyData()
{
	if (ui->spinBoxRaw->value() != ui->spinBoxVerify->value())
	{
		DlgInfo::messageBox(this, tr("警告"), tr("全局验证图片数量错误，\n请核对全局照片。"), tr("确定"), tr("删除"), false);
		return false;
	}
	USBCamera::instance()->stop();
	return true;

}
void WgtVerifyNo3::on_toolButtonPhoto_clicked()
{
	if (mImage.isNull() || mImageName.isEmpty())
	{
		return;
	}
	USBCamera::instance()->takePictures();
	mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(false);
}
void WgtVerifyNo3::on_toolButtonRefImage_clicked()
{
	switch (mWgtVerifyNo31->refImageType)
	{
	case WgtVerifyNo31::None:
		mWgtVerifyNo31->refImageType = WgtVerifyNo31::Ref50;
		break;
	case WgtVerifyNo31::Ref50:
		mWgtVerifyNo31->refImageType = WgtVerifyNo31::RefLeft;
		break;
	case WgtVerifyNo31::RefLeft:
		mWgtVerifyNo31->refImageType = WgtVerifyNo31::RefRight;
		break;
	case WgtVerifyNo31::RefRight:
		mWgtVerifyNo31->refImageType = WgtVerifyNo31::None;
		break;
	default:
		mWgtVerifyNo31->refImageType = WgtVerifyNo31::None;
		break;
	}
	mWgtVerifyNo31->refImage = mImage.scaled(mWgtVerifyNo31->size(), Qt::KeepAspectRatio);
	mWgtVerifyNo31->update();
	qDebug() << "refImageType:" << mWgtVerifyNo31->refImageType;
}
void WgtVerifyNo3::picture(QImage image)
{
	mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(true);
	auto data = VerifyThread::instance();
	if (image.size().width() != 3840 && image.size().height() != 2160)
	{
		qDebug() << "WgtRegNo2 : picture:image size:Auto to" << image.size();
		image = image.scaled(3840, 2160);
	}
	ImageInfo info;
	data->getRawImageInfo(mImageName, &info);
	QString key = gVerifyNameHeader+ mImageName;
	data->addGlobalImage(key, image.copy(), info.id);
	ui->widgetVerifyImage->updateImage();
	ui->spinBoxVerify->setValue(ui->widgetVerifyImage->getImageNum());
	mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(false);
}
void WgtVerifyNo3::rawImageSelected(QString name, QImage image)
{
	mImageName = name;
	mImage = image;
	auto data = VerifyThread::instance();
	QString gName = gVerifyNameHeader + mImageName;
	if (data->getGlobalImage()->contains(gName))
	{
		mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(false);
	}
	else
	{
		mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(true);
	}
	mWgtVerifyNo31->refImageType = WgtVerifyNo31::None;
	mWgtVerifyNo31->update();
}
void WgtVerifyNo3::verifyimageClicked(QString name, QImage image)
{
	DlgImageView* dlg = new DlgImageView(this);
	dlg->setImage(image, name);
	dlg->setDelete(true);
	dlg->exec();
	bool isDelete = dlg->isDelete();
	delete dlg;
	if (isDelete)
	{
		auto data = VerifyThread::instance();
		QString number = data->getVerifyNumber();
		if (data->deleteGlobalImage(number, name))
		{
			ui->widgetVerifyImage->updateImage();
			ui->spinBoxVerify->setValue(ui->widgetVerifyImage->getImageNum());
			if ((name) == (gVerifyNameHeader + mImageName))
			{
				mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(true);
			}
			else
			{
				mWgtVerifyNo31->ui->toolButtonPhoto->setEnabled(false);
			}
		}
		else
		{
			DlgInfo::messageBox(this, "提示", "删除图片失败！", "确定", "否", false);
		}
	}
	else
	{
		qDebug() << "WgtRegNo2::imageClicked: not delete";
	}
}