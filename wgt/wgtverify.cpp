#include "wgtverify.h"
#include "wgtmain.h"
#include "dlginfo.h"
#include "usbcamera.h"
#include "netcamera.h"
#include "ringwait.h"
WgtVerify::WgtVerify(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyClass())
	, mWgtVerifyNo1(new WgtVerifyNo1(this))
	, mWgtVerifyNo2(new WgtVerifyNo2(this))
	, mWgtVerifyNo3(new WgtVerifyNo3(this))
	, mWgtVerifyNo4(new WgtVerifyNo4(this))
	, mWgtVerifyNo5(new WgtVerifyNo5(this))
	, mWgtVerifyNo6(new WgtVerifyNo6(this))
{
	ui->setupUi(this);

	mWgtMain = qobject_cast<WgtMain*>(this->parent());

	ui->stackedWidget->addWidget(mWgtVerifyNo1);
	ui->stackedWidget->addWidget(mWgtVerifyNo2);
	ui->stackedWidget->addWidget(mWgtVerifyNo3);
    ui->stackedWidget->addWidget(mWgtVerifyNo4);
	ui->stackedWidget->addWidget(mWgtVerifyNo5);
	ui->stackedWidget->addWidget(mWgtVerifyNo6);

	names << "第一步：待验证信息确认"
		<< "第一步：待验证信息确认"
		<< "第二步：拍摄全局验证图片"
		<< "第三步：拍摄指纹验证图片"
		<< "第四步：一致性比对"
		<< "一致性比对结果";

    ui->stackedWidget->setCurrentIndex(0);

	connect(mWgtVerifyNo5->ui->pushButtonBackHome, &QPushButton::clicked, this, &WgtVerify::on_pushButtonBackHome_clicked,Qt::UniqueConnection);
	connect(mWgtVerifyNo6->ui->pushButtonBackHome, &QPushButton::clicked, this, &WgtVerify::on_pushButtonBackHome_clicked, Qt::UniqueConnection);
	connect(mWgtVerifyNo5, &WgtVerifyNo5::verifyNo5Finished, this, &WgtVerify::showVerifyResult);
	/*connect(VerifyThread::instance(), &VerifyThread::showVerifyResult, [this](QString number) {
		if (ui->stackedWidget->currentWidget() == mWgtVerifyNo5)
		{
            showVerifyResult(number);
		}
		});*/
}

WgtVerify::~WgtVerify()
{
	delete ui;
}
void WgtVerify::back()
{
	bool isDelete = false;
	if (ui->stackedWidget->currentWidget() == mWgtVerifyNo2)
	{
		VerifyThread::instance()->deleteVerifyData();
	}
	if (ui->stackedWidget->currentWidget() == mWgtVerifyNo3)
	{
		DlgInfo::DlgInfoResult result = DlgInfo::messageBox(this, tr("返回主页"), tr("当前有未完成的验证流程\n您希望是否保留至进度?"), tr("保留"), tr("删除"));
		if (DlgInfo::DlgInfoResult::No == result)
		{
			VerifyThread::instance()->deleteVerifyData();
			isDelete = true;
		}
		else if (DlgInfo::DlgInfoResult::OK == result)
		{
			VerifyThread::instance()->updateVerifyData();
			isDelete = false;
			
		}
		else
		{
			return;
		}
	}
	NetCamera::instance()->stop();
	USBCamera::instance()->stop();
	int  index = ui->stackedWidget->currentIndex();
	if (index == 1||index == 2 || index == 4|| index == 5)
	{
		continueVerify(0);

	}
	else if(index == 3)
	{
		continueVerify(2);
	}
	else if ((index == 0) 
		&& (!mWgtVerifyNo1->back()) 
		&& (mWgtMain != nullptr))
	{
        mWgtMain->ui->pushButtonHome->clicked();
	}
	
}
void WgtVerify::newVerify()
{
	on_pushButtonGoVerify1_clicked();
}
void WgtVerify::continueVerify(int verifyNo)
{
	if (verifyNo == 0)
	{
		ui->stackedWidget->setCurrentWidget(mWgtVerifyNo1);
		update();
		QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
		mWgtVerifyNo1->updateShow(false);
		if (mWgtMain)
		{
			mWgtMain->ui->labelName->setText(names[0]);
		}
	}
	else if (verifyNo == 1)
	{
		on_pushButtonGoVerify2_clicked(true);
	}
	else if (verifyNo == 2)
	{
		on_pushButtonGoVerify3_clicked(true);
	}
	else if (verifyNo == 3)
	{
		on_pushButtonGoVerify4_clicked(true);
	}
	else if (verifyNo == 4)
	{
		on_pushButtonGoVerify5_clicked(true);
	}
}
void WgtVerify::showVerifyResult(QString number)
{
	mWgtVerifyNo6->updateShow(number);
	ui->stackedWidget->setCurrentWidget(mWgtVerifyNo6);
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[5]);
	}
}
void WgtVerify::on_pushButtonGoVerify1_clicked()
{
	ui->stackedWidget->setCurrentWidget(mWgtVerifyNo1);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtVerifyNo1->updateShow();
	VerifyThread::instance()->setVerifyNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[0]);
	}
}
void WgtVerify::on_pushButtonGoVerify2_clicked(bool isNoSave)
{
	if (!isNoSave && !mWgtVerifyNo1->updateVerifyData())
	{
		return;
	}
	ui->stackedWidget->setCurrentWidget(mWgtVerifyNo2);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtVerifyNo2->updateShow();
	VerifyThread::instance()->setVerifyNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[1]);
	}
}
void WgtVerify::on_pushButtonGoVerify3_clicked(bool isNoSave)
{
	if (!isNoSave && !mWgtVerifyNo2->updateVerifyData())
	{
		return;
	}

	ui->stackedWidget->setCurrentWidget(mWgtVerifyNo3);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtVerifyNo3->updateShow();
	VerifyThread::instance()->setVerifyNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[2]);
	}
}
void WgtVerify::on_pushButtonGoVerify4_clicked(bool isNoSave)
{
	if (!isNoSave && !mWgtVerifyNo3->updateVerifyData())
	{
		return;
	}

	if (!VerifyThread::instance()->getRawMarkedImage()->isEmpty())
	{
		ui->stackedWidget->setCurrentWidget(mWgtVerifyNo4);
		update();
		QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
		/*有显微图时不能跳过*/
		mWgtVerifyNo4->ui->pushButtonSkipSampling->setVisible(false);
		mWgtVerifyNo4->updateShow();
		VerifyThread::instance()->setVerifyNo(ui->stackedWidget->currentIndex());
		if (mWgtMain)
		{
			mWgtMain->ui->labelName->setText(names[3]);
		}
	}
	else
	{
		on_pushButtonSkipSampling_clicked();
	}
}
void WgtVerify::on_pushButtonSkipSampling_clicked()
{
	VerifyThread::instance()->deleteAllMarkImage();
	on_pushButtonGoVerify5_clicked(true);
	mWgtVerifyNo4->ui->widgetRawImage->setImage(nullptr);
	mWgtVerifyNo4->ui->widgetVerifyImage->setImage(nullptr);
}
void WgtVerify::on_pushButtonGoVerify5_clicked(bool isNoSave)
{
	if (!isNoSave && !mWgtVerifyNo4->updateVerifyData())
	{
		return;
	}
	ui->stackedWidget->setCurrentWidget(mWgtVerifyNo5);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents | QEventLoop::WaitForMoreEvents, 100);
	mWgtVerifyNo5->updateShow();
	VerifyThread::instance()->setVerifyNo(ui->stackedWidget->currentIndex());
	if (mWgtMain)
	{
		mWgtMain->ui->labelName->setText(names[4]);
	}
}
void WgtVerify::on_pushButtonBackHome_clicked()
{
	if (mWgtMain != nullptr)
	{
		mWgtMain->ui->pushButtonHome->clicked();

	}
}

void WgtVerify::on_pushButtonReVerify_clicked()
{
	DlgInfo::DlgInfoResult result = DlgInfo::messageBox(this, tr("重新验证本件"), tr("确定是否重新验证本件?"), tr("确定"), tr("取消"));
	if (DlgInfo::DlgInfoResult::OK == result)
	{
		BaseInfo baseInfo = VerifyThread::instance()->getBaseInfo();
		BatchInfo batchInfo = VerifyThread::instance()->getBatchInfo();
		VerifyThread::instance()->deleteVerifyData();
		VerifyThread::instance()->addNewVerifyData(baseInfo, batchInfo);
		on_pushButtonGoVerify2_clicked(true);
	}
}