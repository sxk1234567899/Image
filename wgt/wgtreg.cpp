#include "wgtreg.h"
#include "wgtmain.h"
#include "dlgInfo.h"
#include "ringwait.h"
#include "usbcamera.h"
#include "netcamera.h"
WgtReg::WgtReg(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegClass())
	, mWgtRegNo1(new WgtRegNo1(this))
	, mWgtRegNo2(new WgtRegNo2(this))
	, mWgtRegNo3(new WgtRegNo3(this))
	, mWgtRegNo4(new WgtRegNo4(this))
	, mWgtRegNo5(new WgtRegNo5(this))
	, mWgtRegNo6(new WgtRegNo6(this))
{
	ui->setupUi(this);
	mWgtMain = qobject_cast<WgtMain*>(this->parent());
	
    ui->stackedWidget->addWidget(mWgtRegNo1);
	ui->stackedWidget->addWidget(mWgtRegNo2);
	ui->stackedWidget->addWidget(mWgtRegNo3);
	ui->stackedWidget->addWidget(mWgtRegNo4);
	ui->stackedWidget->addWidget(mWgtRegNo5);
	ui->stackedWidget->addWidget(mWgtRegNo6);

	names<< "第一步：基本信息确认"
		<< "第二步：全局图拍摄" 
		<< "第三步：指纹点标记" 
		<< "第四步：指纹点拍摄" 
		<< "第五步：打印凭证" 
		<< "第五步：打印凭证";


	ui->stackedWidget->setCurrentIndex(0);
}

WgtReg::~WgtReg()
{
	delete ui;
}
void WgtReg::back()
{
	
	if (ui->stackedWidget->currentWidget() == mWgtRegNo2)
	{
		DlgInfo::DlgInfoResult result = DlgInfo::messageBox(this, tr("返回主页"), tr("当前有未完成的登记流程\n您希望是否保留至进度?"), tr("保留"), tr("删除"));
		if (DlgInfo::DlgInfoResult::No == result)
		{
			RegThread::instance()->deleteRegData();
		}
		else if (DlgInfo::DlgInfoResult::OK == result)
		{
			RegThread::instance()->updateRegData();
		}
		else
		{
			return;
		}
	}
	NetCamera::instance()->stop();
	USBCamera::instance()->stop();
	int  index = ui->stackedWidget->currentIndex();
	if (ui->stackedWidget->currentWidget() == mWgtRegNo6)
	{
		on_pushButtonGoReg1_clicked();
	}
	else if (index > 0)
	{
		index--;
		if (ui->stackedWidget->currentWidget() == mWgtRegNo5 
			&& RegThread::instance()->getMarkedImage()->isEmpty())
		{
			index--;
		}
		continueReg(index);
	}
	else if ((index == 0) 
		&& (!mWgtRegNo1->back()) 
		&& (mWgtMain != nullptr))
	{

		mWgtMain->ui->pushButtonHome->clicked();
	}
}
void WgtReg::newReg()
{
	on_pushButtonGoReg1_clicked();
}
void WgtReg::continueReg(int regNo)
{
	if (regNo == 0)
	{
		ui->stackedWidget->setCurrentWidget(mWgtRegNo1);
		update();
		QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
		mWgtRegNo1->updateShow(false);
		if (mWgtMain)
		{
			mWgtMain->ui->labelName->setText(names[0]);
		}
	}
	else if (regNo == 1)
	{
		on_pushButtonGoReg2_clicked(true);
	}
	else if (regNo == 2)
	{
		on_pushButtonGoReg3_clicked(true);
	}
	else if (regNo == 3)
	{
		on_pushButtonGoReg4_clicked(true);
	}
	else if (regNo == 4)
	{
		on_pushButtonGoReg5_clicked(true);
	}
	else if (regNo == 5)
	{
		on_pushButtonGoReg6_clicked(true);
	}
}
void WgtReg::on_pushButtonGoReg1_clicked()
{
	ui->stackedWidget->setCurrentWidget(mWgtRegNo1);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtRegNo1->updateShow();
	RegThread::instance()->setRegNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[0]);
	}
}
void WgtReg::on_pushButtonGoReg2_clicked(bool isNoSave)
{

	if (!isNoSave && !mWgtRegNo1->updateRegData())
	{
		//DlgInfo::messageBox(this, tr("警告"), tr("您选择文物艺术品正在登记中或已登记，\n请您核对后再试。"), tr("确定"), tr("删除"), false);
		return;
	}
	ui->stackedWidget->setCurrentWidget(mWgtRegNo2);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtRegNo2->updateShow();
	RegThread::instance()->setRegNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[1]);
	}
}
void WgtReg::on_pushButtonGoReg3_clicked(bool isNoSave)
{
	if (!isNoSave && !mWgtRegNo2->updateRegData())
	{     
		return;

	}
	ui->stackedWidget->setCurrentWidget(mWgtRegNo3);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtRegNo3->updateShow();
	RegThread::instance()->setRegNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[2]);
	}
}
void WgtReg::on_pushButtonSkipSampling_clicked()
{
	RegThread::instance()->deleteAllMarkImage();
	on_pushButtonGoReg5_clicked(true);
	/*初始化显示*/
	mWgtRegNo3->ui->widgetImage->setImage(nullptr);
	mWgtRegNo3->ui->widgetImageMarked->setImage(nullptr);
	mWgtRegNo4->ui->widgetImageMarked->setImage(nullptr);
	mWgtRegNo4->ui->widgetHighImage->setImage(nullptr);
}
void WgtReg::on_pushButtonGoReg4_clicked(bool isNoSave)
{
	if (!isNoSave && !mWgtRegNo3->updateRegData())
	{     
		return;
	}
    ui->stackedWidget->setCurrentWidget(mWgtRegNo4);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtRegNo4->updateShow();
	RegThread::instance()->setRegNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[3]);
	}
}
void WgtReg::on_pushButtonGoReg5_clicked(bool isNoSave)
{
	if (!isNoSave&&!mWgtRegNo4->updateRegData())
	{
		return;
	}
    ui->stackedWidget->setCurrentWidget(mWgtRegNo5);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtRegNo5->updateShow();
	RegThread::instance()->setRegNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[4]);
	}
}

void WgtReg::on_pushButtonGoReg6_clicked(bool isNoSave)
{
	if (!isNoSave && !mWgtRegNo5->updateRegData())
	{
		return;
	}

	ui->stackedWidget->setCurrentWidget(mWgtRegNo6);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtRegNo6->updateShow();
	RegThread::instance()->setRegNo(ui->stackedWidget->currentIndex());

	/*TODO:启动上传任务*/
	RegThread* regThread = RegThread::instance();
	regThread->regFinished();
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[5]);
	}
}

void WgtReg::on_pushButtonRegDelete_clicked()
{
	
	if (DlgInfo::DlgInfoResult::OK == DlgInfo::messageBox(this, tr("删除本件登记"), tr("确定删除本件的登记信息吗。"), tr("确定"), tr("取消")))
	{
		QScopedPointer<RingWait> rangWait(new RingWait(this));
		rangWait->show();
		RegThread::instance()->deleteRegData();
		if (mWgtMain != nullptr)
		{
			mWgtMain->ui->stackedWidget->setCurrentWidget(mWgtMain->mWgtHome);
		}
	}
}
void WgtReg::on_pushButtonBackHome_clicked()
{
	if (mWgtRegNo6->updateRegData())
	{
		
	}
	RegThread* regThread = RegThread::instance();
	regThread->startNewRegData();
	if (mWgtMain != nullptr)
	{
		
		mWgtMain->ui->pushButtonHome->clicked();
	}
}