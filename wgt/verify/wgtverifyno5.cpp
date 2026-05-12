#include "wgtverifyno5.h"
#include "verifythread.h"
#include "ringwait.h"
WgtVerifyNo5::WgtVerifyNo5(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo5Class())
	, mShowTimer(new QTimer(this))
{
	ui->setupUi(this);
	connect(mShowTimer, &QTimer::timeout, this, &WgtVerifyNo5::updateShowTimer);
	

}

WgtVerifyNo5::~WgtVerifyNo5()
{
	delete ui;
}

void WgtVerifyNo5::updateShow()
{
	rIndex1 = 0;
	rIndex2 = 0;
	vIndex1 = 0;
	vIndex2 = 0;
	updateShowTimer();
	ui->labelRawImage->startAnimation();
    ui->labelVerifyImage->startAnimation();
	VerifyThread::instance()->getGlobalImage();
    VerifyThread::instance()->getHighImage();
	VerifyThread::instance()->getRawGlobalImage();
	VerifyThread::instance()->getRawHighImage();
	mShowTimer->start(4000);
	VerifyThread::instance()->verifyFinished();
}
bool WgtVerifyNo5::updateVerifyData()
{
	mShowTimer->stop();
	ui->labelRawImage->stopAnimation();
	ui->labelVerifyImage->stopAnimation();
	return true;
}
void WgtVerifyNo5::hideEvent(QHideEvent* event)
{
	mShowTimer->stop();
	ui->labelRawImage->stopAnimation();
	ui->labelVerifyImage->stopAnimation();
}
void WgtVerifyNo5::updateShowTimer()
{
	const VerifyData* verifyData = VerifyThread::instance()->getVerifyData();
	if (verifyData == nullptr)
	{
		return;
	}
	if (verifyData->isVerifyFinished == VerifyData::Verify_Finished)
	{
		emit verifyNo5Finished(verifyData->baseInfo.number);
		return;
	}
	auto gKeys = verifyData->globalImage.keys();
    auto hKeys = verifyData->highImage.keys();
	if (vIndex1 < gKeys.size())
	{
		ui->labelVerifyImage->setImage(verifyData->globalImage[gKeys[vIndex1]].copy());
		ui->labelRawImage->setImage(verifyData->rawGlobalImage[gKeys[rIndex1].remove(gVerifyNameHeader)].copy());
		vIndex1++;
	}
	else if (vIndex2 < hKeys.size())
	{
		ui->labelVerifyImage->setImage(verifyData->highImage[hKeys[vIndex2]].copy());
		ui->labelRawImage->setImage(verifyData->rawHighImage[hKeys[rIndex2].remove(gVerifyNameHeader)].copy());
		vIndex2++;
	}
	else
	{
		vIndex1 = 0;
		vIndex2 = 0;
	}
}