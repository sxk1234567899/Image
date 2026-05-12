#include "wgtprogress.h"
#include "wgtmain.h"
#include "dlginfo.h"

WgtProgress::WgtProgress(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtProgressClass())
	, mWgtProgress1(new WgtProgress1(this))
	, mWgtProgress2(new WgtProgress2(this))
	, mShowTimer(new QTimer(this))
{
	ui->setupUi(this);
	mWgtMain = qobject_cast<WgtMain*>(this->parent());
	ui->stackedWidget->addWidget(mWgtProgress1);
	ui->stackedWidget->addWidget(mWgtProgress2);
	ui->stackedWidget->setCurrentWidget(mWgtProgress1);
	mWgtProgress1->ui->pushButtonReg->setCheckable(true);
	mWgtProgress1->ui->pushButtonVerify->setCheckable(true);
	mWgtProgress1->ui->stackedWidget->setCurrentWidget(mWgtProgress1->ui->pageReg);
	mWgtProgress1->ui->pushButtonReg->setChecked(true);
	mWgtProgress1->ui->pushButtonVerify->setChecked(false);

	connect(mWgtProgress1->ui->tableWidgetReg, &QTableWidget::cellClicked, this, &WgtProgress::tableWidgetRegcellClicked);
	connect(mWgtProgress1->ui->tableWidgetVerify, &QTableWidget::cellClicked, this, &WgtProgress::tableWidgetVerifycellClicked);
	
	connect(mShowTimer, &QTimer::timeout, this, &WgtProgress::showUpdata);
}

WgtProgress::~WgtProgress()
{
	delete ui;
}
void WgtProgress::initProgress()
{
	mWgtProgress1->ui->tableWidgetReg->setRowCount(0);
    mWgtProgress1->ui->tableWidgetVerify->setRowCount(0);
	mRegNumber.clear();
	mWgtProgress1->ui->comboBoxBatch->clear();
    mWgtProgress1->ui->comboBoxBatch->addItem(tr("全部"));
	regData = RegThread::instance();
	connect(regData, &RegThread::regDataAdded, this, &WgtProgress::regDataAdded,Qt::UniqueConnection);
	connect(regData, &RegThread::regDataUpdated, this, &WgtProgress::regDataUpdated, Qt::UniqueConnection);
	connect(regData, &RegThread::regDataDeleted, this, &WgtProgress::regDataDeleted, Qt::UniqueConnection);

	auto numberList = regData->getRegNumberList();
	for (auto number : numberList)
	{
		regDataAdded(number);
	}

	verifyData = VerifyThread::instance();
	connect(verifyData, &VerifyThread::verifyDataAdded, this, &WgtProgress::verifyDataAdded, Qt::UniqueConnection);
	connect(verifyData, &VerifyThread::verifyDataUpdated, this, &WgtProgress::verifyDataUpdated, Qt::UniqueConnection);
	connect(verifyData, &VerifyThread::verifyDataDeleted, this, &WgtProgress::verifyDataDeleted, Qt::UniqueConnection);

	numberList = verifyData->getVerifyDataList();
	for (auto number : numberList)
	{
		verifyDataAdded(number);
	}
}
void WgtProgress::back()
{
	if (ui->stackedWidget->currentWidget() != mWgtProgress1)
	{
		ui->stackedWidget->setCurrentWidget(mWgtProgress1);
		mShowTimer->stop();
	}
	else if (mWgtMain != nullptr)
	{

		mWgtMain->ui->pushButtonHome->clicked();
		mShowTimer->stop();
	}
}

void WgtProgress::on_pushButtonReg_clicked()
{
	mWgtProgress1->ui->pushButtonReg->setChecked(true);
	mWgtProgress1->ui->pushButtonVerify->setChecked(false);
	mWgtProgress1->ui->stackedWidget->setCurrentWidget(mWgtProgress1->ui->pageReg);
}
void WgtProgress::on_pushButtonVerify_clicked()
{
	mWgtProgress1->ui->pushButtonReg->setChecked(false);
	mWgtProgress1->ui->pushButtonVerify->setChecked(true);
	mWgtProgress1->ui->stackedWidget->setCurrentWidget(mWgtProgress1->ui->pageVerify);
}

void WgtProgress::tableWidgetRegcellClicked(int row, int column)
{
	// 处理注册表格单元格点击事件
	qDebug() << "Reg cell clicked at row:" << row << ", column:" << column;
	qDebug() << mWgtProgress1->ui->tableWidgetReg->item(row, column)->text();
	if (column == 0)/*点击名字，切换到操作进度界面*/
	{
		auto regInfo = regData->getRegData(mRegNumber[row]);
		bool isSaved = false;
		for (auto imageInfo=regInfo->imageInfo.begin(); imageInfo != regInfo->imageInfo.end(); imageInfo++)
		{
			if (imageInfo.value().status == ImageStatus::saveFailed)
			{
				isSaved = true;
				break;
			}	
		}
		if (!regInfo->isRegFinished || isSaved)
		{
			regData->setRegNumber(mRegNumber[row]);
			if (mWgtMain)
			{
				mWgtMain->mWgtHome->ui->pushButtonReg->click();
			}
		}
		else if (regInfo->isRegFinished)
		{
			DlgInfo::messageBox(this, tr("提示"), tr("登记已完成,图片正在上传中,请稍后"), tr("确定"), tr("删除"), false);
			
		}

	}
	else if (column == 5)/*点击操作，删除整组*/
	{
		qDebug() << "Delete group at row:" << row;
		regData->deleteRegData(mRegNumber[row]);
       //mRegNumber.removeAt(row);
		//initProgress();
	}
	else if (column == 6)/*点击查看进程*/
	{
		qDebug() << "View process at row:" << row;
		mWgtProgress2->updateShow(true, mRegNumber[row]);
		ui->stackedWidget->setCurrentWidget(mWgtProgress2);
		mShowTimer->start(200);
	}
}
void WgtProgress::tableWidgetVerifycellClicked(int row, int column)
{
	// 处理验证表格单元格点击事件
	auto text = mWgtProgress1->ui->tableWidgetVerify->item(row, column)->text();
	QString number = mWgtProgress1->ui->tableWidgetVerify->item(row, 0)->data(Qt::UserRole).toString();
	qDebug() << "Verify cell clicked at row:" << row << ", column:" << column<<"text:"<<text;
	if (column == 0)/*点击名字，切换到操作进度界面*/
	{
		auto verifyInfo = verifyData->getVerifyData(number);
		bool isSaved = false;
		for (auto imageInfo = verifyInfo->imageInfo.begin(); imageInfo != verifyInfo->imageInfo.end(); imageInfo++)
		{
			if (imageInfo.value().status == ImageStatus::saveFailed)
			{
				isSaved = true;
				break;
			}
		}
		if ((verifyInfo->isVerifyFinished <= VerifyData::Verify_Runing)|| isSaved)
		{
			verifyData->setVerifyNumber(number);
			if (mWgtMain)
			{
				mWgtMain->mWgtHome->ui->pushButtonVerify->click();
			}
		}
		else if (verifyInfo->isVerifyFinished == VerifyData::Verify_UpData)
		{
			DlgInfo::messageBox(this, tr("提示"), tr("验证已完成,图片正在上传中,请稍后"), tr("确定"), tr("删除"), false);

		}
	}
	else if (column == 5)/*点击操作，删除整组*/
	{
		if (text.contains("整组删除"))
		{
			qDebug() << "Delete group at row:" << row;
			
			verifyData->deleteVerifyData(number);
			//mVerifyNumber.removeAt(row);
            //initProgress();
		}
	}
	else if (column == 6)/*点击查看进程*/
	{
		if (text == "查看进程")
		{
			qDebug() << "View process at row:" << row;
			mWgtProgress2->updateShow(false, number);
			ui->stackedWidget->setCurrentWidget(mWgtProgress2);
			mShowTimer->start(200);
		}
		else if (text == "比对结果")
		{
			verifyData->setVerifyNumber(number);
			if (mWgtMain)
			{
				mWgtMain->mWgtHome->ui->pushButtonVerify->click();
			}
		}
		
	}
}

int WgtProgress::getImageSavedCount(const QStringList names, const QMap<QString, ImageInfo>* imageInfo)const
{
	int savedCount = 0;
	for (const auto& key : names)
	{
		if (imageInfo->contains(key))
		{
			if (imageInfo->value(key).status == ImageStatus::saved)
			{
				savedCount++;
			}
		}
	}
	return savedCount;
}
void WgtProgress::regDataAdded(QString number)
{
	const RegData* info = regData->getRegData(number);
	if (info)
	{
		int savedCount = 0;
		bool isSaved = false;
		savedCount = getImageSavedCount(info->globalImage.keys(), &info->imageInfo);
		if (savedCount == info->globalImage.size())
		{ 
			isSaved =true;
		}
		else
		{
			isSaved = false;
		}
		QString globalImg = QString::asprintf("%d/%d", savedCount, info->globalImage.size());

		savedCount = getImageSavedCount(info->markedImage.keys(), &info->imageInfo);
		if (savedCount == info->markedImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		QString markImg = QString::asprintf("%d/%d", savedCount, info->markedImage.size());

		savedCount = getImageSavedCount(info->highImage.keys(), &info->imageInfo);
		if (savedCount == info->highImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		QString hgtImg = QString::asprintf("%d/%d", savedCount, info->highImage.size());

		savedCount = getImageSavedCount(info->lowImage.keys(), &info->imageInfo);
		if (savedCount == info->lowImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		hgtImg += QString::asprintf("\n%d/%d", savedCount, info->lowImage.size());
		mRegNumber.append(number);
		QString status = "未完成";
		if (isSaved && info->isRegFinished)
		{
            status = "已完成";
		}
		mWgtProgress1->addRegItem(info->baseInfo.name, globalImg, markImg, hgtImg, status);
	}
	else
	{
		qDebug() << "WgtProgress::regDataAdded: No data found for number" << number;
	}

}
void WgtProgress::regDataUpdated(QString number)
{
	const RegData* info = regData->getRegData(number);
	if (info)
	{
		int savedCount = 0;
		bool isSaved = false;
		savedCount = getImageSavedCount(info->globalImage.keys(), &info->imageInfo);
		if (savedCount == info->globalImage.size())
		{
			isSaved = true;
		}
		else
		{
			isSaved = false;
		}
		QString globalImg = QString::asprintf("%d/%d", savedCount, info->globalImage.size());

		savedCount = getImageSavedCount(info->markedImage.keys(), &info->imageInfo);
		if (savedCount == info->markedImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		QString markImg = QString::asprintf("%d/%d", savedCount, info->markedImage.size());

		savedCount = getImageSavedCount(info->highImage.keys(), &info->imageInfo);
		if (savedCount == info->highImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		QString hgtImg = QString::asprintf("%d/%d", savedCount, info->highImage.size());

		savedCount = getImageSavedCount(info->lowImage.keys(), &info->imageInfo);
		if (savedCount == info->lowImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		hgtImg += QString::asprintf("\n%d/%d", savedCount, info->lowImage.size());
		QString status = "未完成";
		if (isSaved && info->isRegFinished)
		{
			status = "已完成";
		}
		int row = mRegNumber.indexOf(number);
		if( row >= 0)
		{
			mWgtProgress1->updateRegItem(row, info->baseInfo.name, globalImg, markImg, hgtImg, status);
		}
		else
		{
			qDebug() << "WgtProgress::regDataUpdated: No existing row for number" << number;
		}
	}
	else
	{
		qDebug() << "WgtProgress::regDataAdded: No data found for number" << number;
	}
}
void WgtProgress::regDataDeleted(QString number)
{
	int row = mRegNumber.indexOf(number);
	if( row >= 0&& row< mWgtProgress1->ui->tableWidgetReg->rowCount())
	{
		mRegNumber.removeAt(row);
		mWgtProgress1->ui->tableWidgetReg->removeRow(row);
	}
	
}

void WgtProgress::verifyDataAdded(QString number)
{
	const VerifyData* info = verifyData->getVerifyData(number);
	if (info)
	{
		int savedCount = 0;
		bool isSaved = false;
		savedCount = getImageSavedCount(info->globalImage.keys(), &info->imageInfo);
		if (savedCount == info->globalImage.size())
		{
			isSaved = true;
		}
		else
		{
			isSaved = false;
		}
		QString globalImg = QString::asprintf("%d/%d", savedCount, info->globalImage.size());


		savedCount = getImageSavedCount(info->highImage.keys(), &info->imageInfo);
		if (savedCount == info->highImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		QString hgtImg = QString::asprintf("%d/%d", savedCount, info->highImage.size());


		savedCount = getImageSavedCount(info->lowImage.keys(), &info->imageInfo);
		if (savedCount == info->lowImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		hgtImg += QString::asprintf("\n%d/%d", savedCount, info->lowImage.size());
		QString status;
		if (info->isVerifyFinished <VerifyData::Verify_Waiting)
		{
			status = "查看进程";
		}
		else if (info->isVerifyFinished == VerifyData::Verify_Finished)
		{
			status = "比对结果";
		}
		else
		{
			status = "比对进行中";
		}

		QString imgStatus = "未完成";
		if (isSaved && info->isVerifyFinished >VerifyData::Verify_Runing)
		{
			imgStatus = "已完成";
		}
		mWgtProgress1->addVerifyItem(number,info->baseInfo.name, info->batchInfo.name, info->baseInfo.verifyTime,globalImg, hgtImg, status, imgStatus);

	}
	else
	{
		qDebug() << "WgtProgress::regDataAdded: No data found for number" << number;
	}
}
void WgtProgress::verifyDataUpdated(QString number)
{
	const VerifyData* info = verifyData->getVerifyData(number);
	if (info)
	{
		int savedCount = 0;
		bool isSaved = false;
		savedCount = getImageSavedCount(info->globalImage.keys(), &info->imageInfo);
		if (savedCount == info->globalImage.size())
		{
			isSaved = true;
		}
		else
		{
			isSaved = false;
		}
		QString globalImg = QString::asprintf("%d/%d", savedCount, info->globalImage.size());

		savedCount = getImageSavedCount(info->highImage.keys(), &info->imageInfo);
		if (savedCount == info->highImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		QString hgtImg = QString::asprintf("%d/%d", savedCount, info->highImage.size());

		savedCount = getImageSavedCount(info->lowImage.keys(), &info->imageInfo);
		if (savedCount == info->lowImage.size())
		{
			isSaved &= true;
		}
		else
		{
			isSaved = false;
		}
		hgtImg += QString::asprintf("\n%d/%d", savedCount, info->lowImage.size());
		QString status;
		if (info->isVerifyFinished < VerifyData::Verify_Waiting)
		{
			status = "查看进程";
		}
		else if (info->isVerifyFinished == VerifyData::Verify_Finished)
		{
			status = "比对结果";
		}
		else
		{
			status = "比对进行中";
		}
		QString imgStatus = "未完成";
		if (isSaved && info->isVerifyFinished > VerifyData::Verify_Runing)
		{
			imgStatus = "已完成";
		}
		
		mWgtProgress1->updateVerifyItem(number, info->baseInfo.name,info->batchInfo.name, info->baseInfo.verifyTime, globalImg, hgtImg, status, imgStatus);
		
	}
	else
	{
		qDebug() << "WgtProgress::regDataAdded: No data found for number" << number;
	}
}
void WgtProgress::verifyDataDeleted(QString number)
{
	int row = -1;
	for (int i = 0; i < mWgtProgress1->ui->tableWidgetVerify->rowCount(); ++i)
	{
		if (mWgtProgress1->ui->tableWidgetVerify->item(i, 0)->data(Qt::UserRole) == number)
		{
			row = i;
			break;
		}
	}
	if (row >= 0 && row < mWgtProgress1->ui->tableWidgetVerify->rowCount())
	{
		mWgtProgress1->ui->tableWidgetVerify->removeRow(row);
	}
}

void WgtProgress::showUpdata()
{
	if (ui->stackedWidget->currentWidget() == mWgtProgress2)
	{
		mWgtProgress2->updateShow();
	}
}