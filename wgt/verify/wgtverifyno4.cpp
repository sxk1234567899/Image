#include "wgtverifyno4.h"
#include "netcamera.h"
#include "dlgimageview.h"
#include "verifythread.h"
#include "dlginfo.h"
#include "ringwait.h"
WgtVerifyNo4::WgtVerifyNo4(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo4Class())
	, mWgtVerifyNo41(new WgtVerifyNo41(this))
{
	ui->setupUi(this);
	ui->radioButtonLow->setIcon(QIcon(":/image/low.png"));
	ui->radioButtonLow->setIconSize(QSize(40, 40));
	ui->radioButtonHgt->setIcon(QIcon(":/image/hgten.png"));
	ui->radioButtonHgt->setIconSize(QSize(40, 40));
	ui->radioButtonLow->setChecked(true);

	ui->pushButtonGoPhoto->setIcon(QIcon(":/image/microscope.png"));
	ui->pushButtonGoPhoto->setIconSize(QSize(40, 40));

	ui->labelInfo->setText(QString("现在请您对指纹点拍摄，您可以使用参照功能，为了便于位置确认，参照默认"
		"\n使用登记时低倍位置图片，您矫正位置后点击切换高倍即可"));
	ui->videoWidget->installEventFilter(this);

	ui->widgetRawImage->setViewBtn(true);
	ui->widgetRawImage->setEnableSelected(true);

	connect(ui->widgetRawImage, &ImageWidget::imageView, this, &WgtVerifyNo4::imageView);
	connect(ui->widgetRawImage, &ImageWidget::imageSelected, this, &WgtVerifyNo4::imageSelected);
	connect(ui->widgetVerifyImage, &ImageWidget::imageClicked, this, &WgtVerifyNo4::highImageClicked);

	ui->stackedWidgetView->setCurrentWidget(ui->pageVideo);
	ui->stackedWidgetBtn->setCurrentWidget(ui->pagePhoto);
	ui->radioButtonLow->setEnabled(false);
	ui->radioButtonHgt->setEnabled(false);
	ui->pushButtonPhoto->setEnabled(false);
	isHgtPhoto = false;
	isLowPhoto = false;
	netCameraConf = AppConfig::instance()->netCameraConf();
}

WgtVerifyNo4::~WgtVerifyNo4()
{
	delete ui;
}
bool WgtVerifyNo4::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == ui->videoWidget)
	{
		
		if ((event->type() == QEvent::WindowActivate && mWgtVerifyNo41->isActiveWindow())
			|| (event->type() == QEvent::WindowActivate && !mWgtVerifyNo41->isVisible())
			|| (event->type()==QEvent::Show))
		{
			mWgtVerifyNo41->setFixedSize(ui->videoWidget->size());
			mWgtVerifyNo41->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
			mWgtVerifyNo41->show();
		}
		if ((event->type() == QEvent::WindowDeactivate && !mWgtVerifyNo41->isActiveWindow())
			||(event->type()==QEvent::Hide))
		{
			mWgtVerifyNo41->hide();
		}
	}
	if (mWgtVerifyNo41->isVisible())
	{
		mWgtVerifyNo41->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
	}
	return QWidget::eventFilter(watched, event);
}
void WgtVerifyNo4::hideEvent(QHideEvent* event)
{
	ui->widgetRawImage->setImage(nullptr);
	ui->widgetVerifyImage->setImage(nullptr);
}
void WgtVerifyNo4::updateShow()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	netCameraConf = AppConfig::instance()->netCameraConf();
	auto data = VerifyThread::instance();
	QString number = data->getVerifyNumber();
	ui->widgetRawImage->setEnabled(true);
	on_pushButtonGoPhoto_clicked();
	if (!number.isEmpty())
	{
		QStringList list = data->getRawHighImage(number)->keys();
		for (int i = 0; i < list.size(); i++)
		{
			list[i] = gVerifyNameHeader+list[i];
		}
		ui->widgetVerifyImage->setNamelist(list);
		ui->widgetRawImage->setImage(data->getRawHighImage(number));
		ui->widgetVerifyImage->setImage(data->getHighImage(number));
		ui->spinBoxRaw->setValue(ui->widgetRawImage->getImageNum());
		ui->spinBoxVerify->setValue(ui->widgetVerifyImage->getImageNum());
		this->setEnabled(true);
	}
	else
	{
		ui->widgetRawImage->setImage(nullptr);
		ui->widgetVerifyImage->setImage(nullptr);
		ui->spinBoxRaw->setValue(0);
		ui->spinBoxVerify->setValue(0);
		ui->widgetTool->setEnabled(false);
        ui->widgetRawImage->setEnabled(false);
        ui->widgetVerifyImage->setEnabled(false);
		mWgtVerifyNo41->setEnabled(false);	
		return;

	}
	
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents);
	reconnectNetCamera();
}
bool WgtVerifyNo4::updateVerifyData()
{
	if (ui->spinBoxRaw->value() != ui->spinBoxVerify->value())
	{
		DlgInfo::messageBox(this, tr("提示"), tr("还有未拍摄的标记图，\n请完成全部指纹图拍摄，再点击下一步。"), tr("确定"), tr("删除"), false);
		return false;
	}
	NetCamera::instance()->stop();
	ui->widgetRawImage->setImage(nullptr);
	ui->widgetVerifyImage->setImage(nullptr);
	return true;
}
bool WgtVerifyNo4::reconnectNetCamera()
{
	bool ret = false;
	static bool isWidgetRawMarked = false;
	isWidgetRawMarked = ui->widgetRawImage->isEnabled();
	while (true)
	{
		if (!NetCamera::instance()->start(ui->videoWidget))
		{
			if (DlgInfo::DlgInfoResult::Cancel == DlgInfo::messageBox(this, "提示", "请检查显微镜连接是否正常后重试！", "重试", "否", false))
			{
				ui->widgetRawImage->setEnabled(false);
				ui->widgetTool->setEnabled(true);
				mWgtVerifyNo41->setEnabled(false);
				ret = false;
				break;
			}
		}
		else
		{
			ui->widgetRawImage->setEnabled(isWidgetRawMarked);
			mWgtVerifyNo41->setEnabled(true);
			ui->widgetTool->setEnabled(true);
			connect(NetCamera::instance(), &NetCamera::picture, this, &WgtVerifyNo4::picture, Qt::UniqueConnection);
			ret = true;
			break;
		}
	}
	return ret;
}
void WgtVerifyNo4::on_radioButtonLow_clicked()
{
	ui->radioButtonLow->setIcon(QIcon(":/image/low.png"));
	ui->radioButtonHgt->setIcon(QIcon(":/image/hgten.png"));
	ui->labelInfo->setText("请您先用低倍进行视野定位，\n"
		"画面清晰后切换为高倍，将激活拍摄按键，\n"
		"点击拍摄将保存【低倍定位图】与【高倍显微图】。");
	if (!NetCamera::instance()->zoom(netCameraConf.lowZoom))
	{
		if (reconnectNetCamera())
		{
            NetCamera::instance()->zoom(netCameraConf.lowZoom);
		}
	}
	auto data = VerifyThread::instance();
	QString lowName = gVerifyNameHeader+mRawLowName;
	if (data->getLowImage()->contains(lowName))
	{
		ui->radioButtonLow->setEnabled(false);
		ui->radioButtonHgt->setEnabled(false);
		ui->pushButtonPhoto->setEnabled(false);
	}
	else
	{
		ui->radioButtonHgt->setEnabled(true);
		ui->radioButtonLow->setEnabled(false);
		ui->pushButtonPhoto->setEnabled(false);
	}
	ui->widgetRawImage->setEnabled(true);
	mWgtVerifyNo41->refImageType = WgtVerifyNo41::None;
	mWgtVerifyNo41->update();
}
void WgtVerifyNo4::on_radioButtonHgt_clicked()
{
	ui->radioButtonLow->setIcon(QIcon(":/image/lowen.png"));
	ui->radioButtonHgt->setIcon(QIcon(":/image/hgt.png"));
	ui->labelInfo->setText("请您先用低倍进行视野定位，\n画面清晰后切换为高倍，将激活拍摄按键，\n"
		"点击拍摄将保存【低倍定位图】与【高倍显微图】。");
	ui->widgetRawImage->setEnabled(false);
	isLowPhoto = true;
	if (!NetCamera::instance()->takePictures())
	{
		if (reconnectNetCamera())
		{
            NetCamera::instance()->takePictures();
		}
	}
	ui->radioButtonHgt->setEnabled(false);
	ui->radioButtonLow->setEnabled(false);
	mWgtVerifyNo41->refImageType = WgtVerifyNo41::None;
	mWgtVerifyNo41->update();

}
void WgtVerifyNo4::on_pushButtonPhoto_clicked()
{
	isHgtPhoto = true;
	if (!NetCamera::instance()->takePictures())
	{
		if (reconnectNetCamera())
		{
            NetCamera::instance()->takePictures();
		}
	}
	ui->pushButtonPhoto->setEnabled(false);
	ui->widgetRawImage->setEnabled(false);
	ui->widgetVerifyImage->setEnabled(false);
	ui->radioButtonHgt->setEnabled(false);
	ui->radioButtonLow->setEnabled(false);
}
void WgtVerifyNo4::on_pushButtonGoPhoto_clicked()
{
	ui->stackedWidgetView->setCurrentWidget(ui->pageVideo);
	ui->stackedWidgetBtn->setCurrentWidget(ui->pagePhoto);
}

void WgtVerifyNo4::on_toolButtonFocus_clicked()
{
	ui->widgetTool->setEnabled(false);
	mWgtVerifyNo41->ui->toolButtonFocus->setEnabled(false);
	if (!NetCamera::instance()->focusOnce())
	{
		if (reconnectNetCamera())
		{
            NetCamera::instance()->focusOnce();
		}
	}
	QEventLoop loop;
	QTimer::singleShot(5000, &loop, &QEventLoop::quit); // 超时设置
	loop.exec();
	ui->widgetTool->setEnabled(true);
	mWgtVerifyNo41->ui->toolButtonFocus->setEnabled(true);
}
void WgtVerifyNo4::on_toolButtonRefImage_clicked()
{
	switch (mWgtVerifyNo41->refImageType)
	{
	case WgtVerifyNo41::None:
		mWgtVerifyNo41->refImageType = WgtVerifyNo41::Ref50;
		break;
	case WgtVerifyNo41::Ref50:
		mWgtVerifyNo41->refImageType = WgtVerifyNo41::RefLeft;
		break;
	case WgtVerifyNo41::RefLeft:
		mWgtVerifyNo41->refImageType = WgtVerifyNo41::RefRight;
		break;
	case WgtVerifyNo41::RefRight:
		mWgtVerifyNo41->refImageType = WgtVerifyNo41::None;
		break;
	default:
		mWgtVerifyNo41->refImageType = WgtVerifyNo41::None;
		break;
	}
	if (isHgtPhoto)
	{
		mWgtVerifyNo41->refImage = mRawHgtImage.copy();
	}
	else
	{
		mWgtVerifyNo41->refImage = mRawLowImage.copy();
	}
	mWgtVerifyNo41->refImage = mWgtVerifyNo41->refImage.scaled(mWgtVerifyNo41->size(), Qt::KeepAspectRatio);
	mWgtVerifyNo41->update();
	qDebug() << "refImageType:" << mWgtVerifyNo41->refImageType;
}


void WgtVerifyNo4::on_toolButtonManualFocus_clicked(bool checked)
{
	qDebug() << "WgtRegNo4 : on_toolButtonManualFocus_clicked:checked" << checked;

	if (checked)
	{
		mWgtVerifyNo41->ui->toolButtonFocusAdd->setVisible(true);
		mWgtVerifyNo41->ui->toolButtonFocusSub->setVisible(true);
		NetCamera::instance()->manualFocusMode(true);
	}
	else
	{
		mWgtVerifyNo41->ui->toolButtonFocusAdd->setVisible(false);
		mWgtVerifyNo41->ui->toolButtonFocusSub->setVisible(false);
		NetCamera::instance()->manualFocusMode(false);
	}
}
void WgtVerifyNo4::on_toolButtonFocusAdd_clicked()
{
	qDebug() << "WgtRegNo4 : on_toolButtonFocusAdd_clicked";
	NetCamera::instance()->manualFocusAdd();
}
void WgtVerifyNo4::on_toolButtonFocusSub_clicked()
{
	qDebug() << "WgtRegNo4 : on_toolButtonFocusSub_clicked";
	NetCamera::instance()->manualFocusSub();
}

void WgtVerifyNo4::picture(QImage image)
{
	auto data = VerifyThread::instance();
	QString number = data->getVerifyNumber();
	/*低倍照片*/
	if (isLowPhoto)
	{
		qDebug() << "低倍照片";
		mLowName = gVerifyNameHeader +mRawLowName;
		mLowImage = image;
		if (mLowImage.size().width() != 3840 && mLowImage.size().height() != 2160)
		{
			qDebug() << "WgtRegNo4 : picture:image size:Auto to" << mLowImage.size();
			mLowImage = image.scaled(3840, 2160);
		}
		if (!NetCamera::instance()->zoom(netCameraConf.highZoom))
		{
			if (reconnectNetCamera())
			{
                NetCamera::instance()->zoom(netCameraConf.highZoom);
			}
		}
		ui->pushButtonPhoto->setEnabled(true);
		ui->widgetRawImage->setEnabled(false);
		ui->radioButtonHgt->setEnabled(false);
		ui->radioButtonLow->setEnabled(true);
		isLowPhoto = false;
		qDebug() << "WgtRegNo4 : picture:低倍照片 end";
	}
	if (isHgtPhoto)/*高倍照片*/
	{

		QString hgtName = gVerifyNameHeader + mRawHgtName;
		if (image.size().width() != 3840 && image.size().height() != 2160)
		{
			qDebug() << "WgtRegNo4 : picture:image size:Auto to" << image.size();
			image = image.scaled(3840, 2160);
		}
		data->addHighImage(number, hgtName, image.copy(),mImageId);
		data->addLowImage(number, mLowName, mLowImage, mImageId);
		qDebug() << "addHighImage"<<number<<hgtName;
		qDebug() << "addLowImage"<< number<<mLowName;
		ui->widgetVerifyImage->updateImage();
		ui->spinBoxVerify->setValue(ui->widgetVerifyImage->getImageNum());
		isHgtPhoto = false;
		ui->pushButtonPhoto->setEnabled(false);
		ui->widgetVerifyImage->setEnabled(true);
		ui->widgetRawImage->setEnabled(true);
		qDebug() << "WgtRegNo4 : picture:高倍照片 end";
	}

}

void WgtVerifyNo4::imageSelected(QString name, QImage image)
{
	ui->widgetTool->setEnabled(false);
	mRawHgtName = name;
	mRawHgtImage = image.copy();

	mRawLowName = name.replace("W_02_", "W_03_");;
	auto verifyData = VerifyThread::instance();
	ImageInfo info;
	if (verifyData->getRawImageInfo(mRawHgtName, &info))
	{
		mImageId = info.id;
	}
	if (verifyData->getRawLowImage()->contains(mRawLowName))
	{
		mRawLowImage = verifyData->getRawLowImage()->value(name).copy();
	}

	mRawMarkName = name.replace("W_03_", "D_01_");
	if (verifyData->getRawMarkedImage()->contains(mRawMarkName))
	{
		mRawMarkImage = verifyData->getRawMarkedImage()->value(mRawMarkName).copy();
	}
	ui->radioButtonHgt->setChecked(false);
	ui->radioButtonLow->setChecked(true);
	isHgtPhoto = false;
	isLowPhoto = false;
	ui->pushButtonPhoto->setEnabled(false);
	on_radioButtonLow_clicked();
	mWgtVerifyNo41->refImageType = WgtVerifyNo41::None;
	mWgtVerifyNo41->update();
	ui->widgetTool->setEnabled(true);
}
void WgtVerifyNo4::imageView(QString name, QImage image)
{
	auto rawMarkedImage = VerifyThread::instance()->getRawMarkedImage();
	auto mName = name.replace("W_02_", "D_01_");
	if (rawMarkedImage->contains(mName))
	{
		ui->stackedWidgetView->setCurrentWidget(ui->pageImage);
		ui->stackedWidgetBtn->setCurrentWidget(ui->pageToPhoto);
		QPixmap pixmap = QPixmap::fromImage(rawMarkedImage->value(name).copy().scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
		ui->labelImage->setPixmap(pixmap);
		ui->labelImage->setFixedSize(pixmap.size());
		ui->labelImageName->setText(Artifact::imageNameShow(name));
	}
	
}

void WgtVerifyNo4::highImageClicked(QString name, QImage image)
{
	auto data = VerifyThread::instance();
	QString number = data->getVerifyNumber();
	if (number.isEmpty())
	{
		qDebug() << "WgtRegNo4::highImageClicked: no registration data available";
		return;
	}
	QString highName = name;
	QString lowName = name.replace("VRF_W_02_", "VRF_W_03_");
	QImage lowImage = data->getLowImage(number)->value(lowName).copy();
	DlgImageView* dlg = new DlgImageView(this);
	dlg->setImage(image.copy(), "查看关联低倍", lowImage, "查看关联高倍");
	dlg->setDelete(true);
	dlg->exec();
	bool isDelete = dlg->isDelete();
	delete dlg;
	if (isDelete)
	{
		data->deleteLowImage(number, lowName);
		if (data->deleteHighImage(number, highName))
		{
			ui->widgetVerifyImage->updateImage();
			ui->spinBoxVerify->setValue(ui->widgetVerifyImage->getImageNum());
			if ((lowName) == (gVerifyNameHeader + mRawLowName))
			{
				ui->radioButtonLow->setEnabled(true);
				ui->radioButtonHgt->setEnabled(true);
			}
		}
		else
		{

			DlgInfo::messageBox(this, "提示", "删除图片失败！", "确定", "否", false);
		}
	}
	else
	{
		qDebug() << "WgtRegNo4::imageClicked: not delete";
	}
}