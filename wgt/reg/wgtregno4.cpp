#include "dlginfo.h"
#include "wgtregno4.h"
#include "regthread.h"
#include "netcamera.h"
#include "dlgimageview.h"
#include "ringwait.h"

WgtRegNo4::WgtRegNo4(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegNo4Class())
	, mWgtRegNo41(new WgtRegNo41(this))
{
	ui->setupUi(this);

	ui->radioButtonLow->setIcon(QIcon(":/image/low.png"));
	ui->radioButtonLow->setIconSize(QSize(40, 40));
	ui->radioButtonHgt->setIcon(QIcon(":/image/hgten.png"));
	ui->radioButtonHgt->setIconSize(QSize(40, 40));
	ui->radioButtonLow->setChecked(true);

	ui->pushButtonGoPhoto->setIcon(QIcon(":/image/microscope.png"));
	ui->pushButtonGoPhoto->setIconSize(QSize(40, 40));

	ui->labelInfo->setText("请您先用低倍进行视野定位，\n画面清晰后切换为高倍，将激活拍摄按键，\n"
		"点击拍摄将保存【低倍定位图】与【高倍显微图】。");
	ui->widgetImageMarked->setViewBtn(true);
	ui->widgetImageMarked->setEnableSelected(true);
	connect(ui->widgetImageMarked, &ImageWidget::imageView, this, &WgtRegNo4::imageView);
	connect(ui->widgetImageMarked, &ImageWidget::imageSelected, this, &WgtRegNo4::imageSelected);
	connect(ui->widgetHighImage, &ImageWidget::imageClicked, this, &WgtRegNo4::highImageClicked);

	ui->videoWidget->installEventFilter(this);

	ui->stackedWidgetView->setCurrentWidget(ui->pageVideo);
	ui->stackedWidgetBtn->setCurrentWidget(ui->pagePhoto);
	ui->radioButtonLow->setEnabled(false);
	ui->radioButtonHgt->setEnabled(false);
	ui->pushButtonPhoto->setEnabled(false);
	isHgtPhoto = false;
	isLowPhoto = false;
	netCameraConf = AppConfig::instance()->netCameraConf();
}

WgtRegNo4::~WgtRegNo4()
{
	delete ui;
}

bool WgtRegNo4::eventFilter(QObject* watched, QEvent* event)
{ 
	if (watched == ui->videoWidget)
	{

		if ((event->type() == QEvent::WindowActivate && mWgtRegNo41->isActiveWindow())
			|| (event->type() == QEvent::WindowActivate && !mWgtRegNo41->isVisible())
			|| (event->type() == QEvent::Show))
		{
			mWgtRegNo41->setFixedSize(ui->videoWidget->size());
			mWgtRegNo41->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
			mWgtRegNo41->show();
		}
		if ((event->type() == QEvent::WindowDeactivate && !mWgtRegNo41->isActiveWindow())
			|| (event->type() == QEvent::Hide))
		{
			mWgtRegNo41->hide();
		}

	}
	if (mWgtRegNo41->isVisible())
	{
		mWgtRegNo41->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
	}
	return QWidget::eventFilter(watched, event);
}
void WgtRegNo4::hideEvent(QHideEvent* event)
{
	ui->widgetImageMarked->setImage(nullptr);
	ui->widgetHighImage->setImage(nullptr);
}
void WgtRegNo4::updateShow()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	netCameraConf = AppConfig::instance()->netCameraConf();
	//qDebug() << QDateTime::currentDateTime()<<"更新界面";
	auto data = RegThread::instance();
	QString number = data->getRegNumber();
	ui->widgetImageMarked->setEnabled(true);
	on_pushButtonGoPhoto_clicked();
	if (!number.isEmpty())
	{
		QStringList list = data->getMarkedImage(number)->keys();
		for (int i = 0; i < list.size(); i++)
		{
			list[i] = list[i].replace("D_01_", "W_02_");
		}
		ui->widgetHighImage->setNamelist(list);
		//qDebug() << QDateTime::currentDateTime() << "开始widgetHighImage";
		ui->widgetImageMarked->setImage(data->getMarkedImage(number));
	    //qDebug() << QDateTime::currentDateTime() << "更新widgetImageMarked";
		ui->widgetHighImage->setImage(data->getHighImage(number));
		//qDebug() << QDateTime::currentDateTime() << "更新widgetHighImage";
		ui->spinBoxMarked->setValue(ui->widgetImageMarked->getImageNum());
        ui->spinBoxHigh->setValue(ui->widgetHighImage->getImageNum());
	}
	else
	{
        ui->widgetImageMarked->setImage(nullptr);
        ui->widgetHighImage->setImage(nullptr);
        ui->spinBoxMarked->setValue(0);
        ui->spinBoxHigh->setValue(0);
		ui->widgetImageMarked->setImage(nullptr);
        ui->widgetHighImage->setImage(nullptr);
		ui->widgetTool->setEnabled(false);
		mWgtRegNo41->setEnabled(false);
		return;
	}
	
	//qDebug() << QDateTime::currentDateTime() << "界面数据完成";
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents);
	//qDebug() << QDateTime::currentDateTime() << "打开显微镜";
	reconnectNetCamera();
}
bool WgtRegNo4::updateRegData()
{
	if (ui->spinBoxMarked->value() != ui->spinBoxHigh->value())
	{
		DlgInfo::messageBox(this, tr("提示"), tr("还有未拍摄的标记图，\n请完成全部指纹图拍摄，再点击下一步。"), tr("确定"), tr("删除"), false);
		return false;
	}
	NetCamera::instance()->stop();
	ui->widgetImageMarked->setImage(nullptr);
	ui->widgetHighImage->setImage(nullptr);
	return true;
}
bool WgtRegNo4::reconnectNetCamera()
{
	qDebug() << QDateTime::currentDateTime() << "重新连接显微镜";
	bool ret = false;	
	static bool isWidgetImageMarked = false;
	isWidgetImageMarked = ui->widgetImageMarked->isEnabled();
	while (true)
	{
		if (!NetCamera::instance()->start(ui->videoWidget))
		{
			if (DlgInfo::DlgInfoResult::Cancel == DlgInfo::messageBox(this, "提示", "请检查显微镜连接是否正常后重试！", "重试", "否", false))
			{
				ui->widgetImageMarked->setEnabled(false);
				ui->widgetTool->setEnabled(false);
				mWgtRegNo41->setEnabled(false);
				ret = false;
				break;
			}
		}
		else
		{
			ui->widgetImageMarked->setEnabled(isWidgetImageMarked);
			mWgtRegNo41->setEnabled(true);
            ui->widgetTool->setEnabled(true);
			connect(NetCamera::instance(), &NetCamera::picture, this, &WgtRegNo4::picture, Qt::UniqueConnection); 
			ret = true;
			break;
		}
	}
	return ret;
}
void WgtRegNo4::on_radioButtonLow_clicked()
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
	auto data = RegThread::instance();
	QString lowName = data->lowImageName(mPhotoName, false);
	if (data->getLowImage()->contains(lowName))
	{
		ui->radioButtonLow->setEnabled(false);
		ui->radioButtonHgt->setEnabled(false);	
	}
	else
	{
		ui->radioButtonHgt->setEnabled(true);
		ui->radioButtonLow->setEnabled(false);
	}
	ui->pushButtonPhoto->setEnabled(false);
	ui->widgetImageMarked->setEnabled(true);
}
void WgtRegNo4::on_radioButtonHgt_clicked()
{
	ui->radioButtonLow->setIcon(QIcon(":/image/lowen.png"));
	ui->radioButtonHgt->setIcon(QIcon(":/image/hgt.png"));
	ui->labelInfo->setText("请您先用低倍进行视野定位，\n画面清晰后切换为高倍，将激活拍摄按键，\n"
		"点击拍摄将保存【低倍定位图】与【高倍显微图】。");
	ui->widgetImageMarked->setEnabled(false);
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
	
}
void WgtRegNo4::on_pushButtonPhoto_clicked()
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
	ui->widgetImageMarked->setEnabled(false);
	ui->widgetHighImage->setEnabled(false);
	ui->radioButtonHgt->setEnabled(false);
	ui->radioButtonLow->setEnabled(false);
}
void WgtRegNo4::on_pushButtonGoPhoto_clicked()
{
	ui->stackedWidgetView->setCurrentWidget(ui->pageVideo);
	ui->stackedWidgetBtn->setCurrentWidget(ui->pagePhoto);
}

void WgtRegNo4::on_toolButtonCrosshair_clicked(bool checked)
{
	mWgtRegNo41->mIsCrosshair = checked;
	mWgtRegNo41->update();
}
void WgtRegNo4::on_toolButtonFocus_clicked()
{
	ui->widgetTool->setEnabled(false);
	mWgtRegNo41->ui->toolButtonFocus->setEnabled(false);
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
	mWgtRegNo41->ui->toolButtonFocus->setEnabled(true);
}

void WgtRegNo4::on_toolButtonManualFocus_clicked(bool checked)
{
	qDebug() << "WgtRegNo4 : on_toolButtonManualFocus_clicked:checked" << checked;

	if (checked)
	{
		mWgtRegNo41->ui->toolButtonFocusAdd->setVisible(true);
        mWgtRegNo41->ui->toolButtonFocusSub->setVisible(true);
        NetCamera::instance()->manualFocusMode(true);
	}
	else
	{
		mWgtRegNo41->ui->toolButtonFocusAdd->setVisible(false);
        mWgtRegNo41->ui->toolButtonFocusSub->setVisible(false);
        NetCamera::instance()->manualFocusMode(false);
	}
}
void WgtRegNo4::on_toolButtonFocusAdd_clicked()
{
	qDebug() << "WgtRegNo4 : on_toolButtonFocusAdd_clicked";
    NetCamera::instance()->manualFocusAdd();
}
void WgtRegNo4::on_toolButtonFocusSub_clicked()
{
	qDebug() << "WgtRegNo4 : on_toolButtonFocusSub_clicked";
    NetCamera::instance()->manualFocusSub();
}

void WgtRegNo4::picture(QImage image)
{
	auto data = RegThread::instance();
	QString number = data->getRegNumber();
	/*低倍照片*/
	if (isLowPhoto)
	{
		qDebug() << "低倍照片";
		mlowImgName = data->lowImageName(number, mPhotoName,false);
		mLowImage = image;
		if (mLowImage.size().width() != 3840 && mLowImage.size().height() != 2160)
		{
			qDebug() << "WgtRegNo4 : picture:image size:Auto to" << image.size();
			mLowImage = mLowImage.scaled(3840, 2160);
		}
		
		if (!NetCamera::instance()->zoom(netCameraConf.highZoom))
		{
			if (reconnectNetCamera())
			{
				qDebug()<<"WgtRegNo4 : picture:zoom:Auto to" << netCameraConf.highZoom;
				NetCamera::instance()->zoom(netCameraConf.highZoom);
			}
		}
		ui->pushButtonPhoto->setEnabled(true);
		ui->radioButtonHgt->setEnabled(false);
		ui->radioButtonLow->setEnabled(true);
		isLowPhoto = false;
		qDebug() << "WgtRegNo4 : picture:低倍照片 end";
	}
	/*高倍照片*/
	if(isHgtPhoto)
	{
		
		QString highImageName = data->highImageName(number, mPhotoName);
		
		if (image.size().width() != 3840 && image.size().height() != 2160)
		{
			qDebug() << "WgtRegNo4 : picture:image size:Auto to" << image.size();
			image = image.scaled(3840, 2160);
		}
		data->addHighImage(number, highImageName, image.copy());
		data->addLowImage(number, mlowImgName, mLowImage);
		ui->widgetHighImage->updateImage();
		ui->spinBoxHigh->setValue(ui->widgetHighImage->getImageNum());
		isHgtPhoto =false;
		ui->pushButtonPhoto->setEnabled(false);
		ui->widgetImageMarked->setEnabled(true);
		ui->widgetHighImage->setEnabled(true);
		qDebug() << "WgtRegNo4 : picture:高倍照片 end";
	}
	
}

void WgtRegNo4::imageSelected(QString name, QImage image)
{
	ui->widgetTool->setEnabled(false);
	mPhotoName = name;
	qDebug() << "WgtRegNo4 : imageSelected:name:" << name;
	ui->radioButtonHgt->setChecked(false);
	ui->radioButtonLow->setChecked(true);
	isHgtPhoto = false;
	isLowPhoto = false;
	ui->pushButtonPhoto->setEnabled(false);
	on_radioButtonLow_clicked();
	ui->widgetTool->setEnabled(true);
}
void WgtRegNo4::imageView(QString name, QImage image)
{
	ui->stackedWidgetView->setCurrentWidget(ui->pageImage);
	ui->stackedWidgetBtn->setCurrentWidget(ui->pageToPhoto);
	QPixmap pixmap = QPixmap::fromImage(image.scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
	ui->labelImage->setPixmap(pixmap);
	ui->labelImage->setFixedSize(pixmap.size());
    ui->labelImageName->setText(Artifact::imageNameShow(name));
}

void WgtRegNo4::highImageClicked(QString name, QImage image)
{
	auto data = RegThread::instance();
	QString number = data->getRegNumber();
	if (number.isEmpty())
	{
		qDebug() << "WgtRegNo4::highImageClicked: no registration data available";
		return;
	}
	QString lowName = data->lowImageName(number,name,false);
	QImage lowImage = data->getLowImage(number)->value(lowName).copy();
	DlgImageView* dlg = new DlgImageView(this);
	dlg->setImage(image, "查看关联低倍", lowImage, "查看关联高倍");
	dlg->setDelete(true);
	dlg->exec();
	bool isDelete = dlg->isDelete();
	delete dlg;
	if (isDelete)
	{
		auto data = RegThread::instance();
		QString number = data->getRegNumber();
		data->deleteLowImage(number, lowName);
		if (data->deleteHighImage(number, name))
		{
			ui->widgetHighImage->updateImage();
			ui->spinBoxHigh->setValue(ui->widgetHighImage->getImageNum());

			if (lowName == data->lowImageName(mPhotoName, false))
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