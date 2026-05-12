#include "wgtregno2.h"
#include "usbcamera.h"
#include "regthread.h"
#include "dlgimageview.h"
#include "dlginfo.h"
#include "ringwait.h"
WgtRegNo2::WgtRegNo2(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegNo2Class())
	, mWgtRegNo21(new WgtRegNo21(this))
{
	ui->setupUi(this);

	mRadioButton = new QButtonGroup(this);
    mRadioButton->addButton(ui->radioButtonTop, 0);
    mRadioButton->addButton(ui->radioButtonBot, 1);
    mRadioButton->addButton(ui->radioButtonFrn, 2);
    mRadioButton->addButton(ui->radioButtonBak, 3);
    mRadioButton->addButton(ui->radioButtonLef, 4);
    mRadioButton->addButton(ui->radioButtonRgh, 5);
    mRadioButton->addButton(ui->radioButtonPar, 6);
    connect(mRadioButton, &QButtonGroup::idClicked, this, &WgtRegNo2::radioButtonClicked);
	ui->radioButtonTop->setChecked(true);
	mpIndex = 0;
	connect(ui->widgetImage, &ImageWidget::imageClicked, this, &WgtRegNo2::imageClicked, Qt::UniqueConnection);
	ui->videoWidget->installEventFilter(this);
	this->installEventFilter(this);
}

WgtRegNo2::~WgtRegNo2()
{
	delete ui;
}
bool WgtRegNo2::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == ui->videoWidget)
	{
		if ((event->type() == QEvent::WindowActivate && mWgtRegNo21->isActiveWindow())
			|| (event->type() == QEvent::WindowActivate && !mWgtRegNo21->isVisible())
			|| (event->type() == QEvent::Show))
		{
			mWgtRegNo21->setFixedSize(ui->videoWidget->size());
			mWgtRegNo21->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
			mWgtRegNo21->show();
			
		}
		if ((event->type() == QEvent::WindowDeactivate && !mWgtRegNo21->isActiveWindow())
			||(event->type() == QEvent::Hide))
		{
			mWgtRegNo21->hide();
			
		}
	}
	if (mWgtRegNo21->isVisible())
	{
		mWgtRegNo21->move(ui->videoWidget->mapToGlobal(QPoint(0, 0)));
	}
    return QWidget::eventFilter(watched, event);
}
void WgtRegNo2::hideEvent(QHideEvent* event)
{
	ui->widgetImage->setImage(nullptr);
}
void WgtRegNo2::updateShow()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	auto data = RegThread::instance();
	QString number = data->getRegNumber();
	if (!number.isEmpty())
	{
		ui->widgetImage->setImage(data->getGlobalImage(number));
		ui->spinBox->setValue(ui->widgetImage->getImageNum());
		this->setEnabled(true);
	}
	else
	{
        ui->widgetImage->setImage(nullptr);
		DlgInfo::messageBox(this, "提示", "请先扫描登记号！", "确定", "否", false);

		this->setEnabled(false);
	}
	ui->radioButtonTop->click();
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	while (true)
	{
		if (!USBCamera::instance()->start(ui->videoWidget))
		{
			if (DlgInfo::DlgInfoResult::Cancel == DlgInfo::messageBox(this, "提示", "请检查USB摄像头是否正常连接后重试！", "重试", "否", false))
			{
				mWgtRegNo21->ui->toolButtonPhoto->setEnabled(false);
				break;
			}
		}
		else
		{
			mWgtRegNo21->ui->toolButtonPhoto->setEnabled(true);
			connect(USBCamera::instance(), &USBCamera::picture, this, &WgtRegNo2::picture, Qt::UniqueConnection);

			break;
		}
	}
}
bool WgtRegNo2::updateRegData()
{
	if (ui->spinBox->value() ==0)
	{
		DlgInfo::messageBox(this, tr("警告"), tr("登记过程至少需要拍摄一张全局照片，\n请拍摄全局照片。"), tr("确定"), tr("删除"), false);
		return false;
	}
	USBCamera::instance()->stop();
	ui->widgetImage->setImage(nullptr);
	return true;
}
void WgtRegNo2::on_toolButtonPhoto_clicked()
{
	USBCamera::instance()->takePictures();
	mWgtRegNo21->ui->toolButtonPhoto->setEnabled(false);
	//qDebug() << "WgtRegNo2::on_toolButtonPhoto_clicked: take picture";
}
void WgtRegNo2::on_toolButtonCrosshair_clicked(bool checked)
{
	mWgtRegNo21->mIsCrosshair = checked;
	mWgtRegNo21->update();
	//qDebug() << "WgtRegNo2::on_toolButtonCrosshair_clicked: Crosshair " << (checked ? "enabled" : "disabled");
}
void WgtRegNo2::radioButtonClicked(int id)
{
	//qDebug()<<"id:"<<id;
	mpIndex = id;
}

void WgtRegNo2::picture(QImage image)
{
	mWgtRegNo21->ui->toolButtonPhoto->setEnabled(true);
	auto data = RegThread::instance();
	QString number = data->getRegNumber();

	
	if (image.size().width() != 3840 && image.size().height() != 2160)
	{
		qDebug()<<"WgtRegNo2 : picture:image size:Auto to"<<image.size();
        image = image.scaled(3840, 2160);
	}
	QString key = data->globalImageName(number,mpIndex);
	data->addGlobalImage(number,key,image.copy());
	ui->widgetImage->updateImage();
	ui->spinBox->setValue(ui->widgetImage->getImageNum());
}
void WgtRegNo2::imageClicked(QString name, QImage image)
{
	DlgImageView* dlg = new DlgImageView(this);
	dlg->setImage(image, name);
	dlg->setDelete(true);
	dlg->exec();
	bool isDelete = dlg->isDelete();
	delete dlg;
	if (isDelete)
	{
		auto data = RegThread::instance();
		QString number = data->getRegNumber();
		if (data->deleteGlobalImage(number, name))
		{
			ui->widgetImage->updateImage();
			ui->spinBox->setValue(ui->widgetImage->getImageNum());
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
