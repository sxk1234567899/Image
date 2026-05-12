#include "wgtverifyno6.h"
#include "verifythread.h"
#include "ringwait.h"
#include "dlginfo.h"
#include "networkserver.h"
#include "netimageload.h"
WgtVerifyNo6::WgtVerifyNo6(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo6Class())
{
	mPlayer = new QMediaPlayer;
	mAudioOutput = new QAudioOutput;
	mPlayer->setAudioOutput(mAudioOutput); // 必须显式设置音频输出

	ui->setupUi(this);
	ui->scrollArea->setAttribute(Qt::WA_AcceptTouchEvents);
	ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏垂直滚动条
	ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏水平滚动条
	/*设置滚动区域*/
	mScroller = QScroller::scroller(ui->scrollArea);
	mScroller->grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);

	mGridLayout = ui->GridLayoutImageView;
	mVSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
	/*设置布局*/
	mGridLayout->setContentsMargins(10, 10, 10, 10);
	mGridLayout->setVerticalSpacing(40);
	mGridLayout->setHorizontalSpacing(20);
	mGridLayout->addItem(mVSpacer, 0, 0, 1, 2);
}

WgtVerifyNo6::~WgtVerifyNo6()
{
	delete ui;
}

void WgtVerifyNo6::updateShow(QString number)
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	clearImage();
	bool isOk = false;
	auto verifyObj = VerifyThread::instance();
	verifyObj->updateVerifyResult(number);
	auto verifyData = verifyObj->getVerifyData(number, &isOk);
	if (!isOk)
	{
		DlgInfo::messageBox(this, tr("警告"), "获取验证数据失败", tr("确定"), tr("删除"), false);
	}
	if (verifyData->isVerifyFinished != VerifyData::Verify_Finished)
    { 
        DlgInfo::messageBox(this, tr("警告"), "请验证完成再查看结果", tr("确定"), tr("取消"), false);
    }

	/*if(verifyData->globalImage.size()!=verifyData->rawGlobalImage.size())
    {
        DlgInfo::messageBox(this, tr("警告"), "全局图片验证数量错误", tr("确定"), tr("取消"), false);
    }
	if(verifyData->highImage.size()!=verifyData->rawHighImage.size())
    {
        DlgInfo::messageBox(this, tr("警告"), "显微图片验证数量错误", tr("确定"), tr("取消"), false);
    }*/

	if(verifyData->baseInfo.verifyResult =="通过")	
	{
		ui->labelVerifyResult->setText("比对完成，同一性验证通过");
		ui->labelVerifyResult->setStyleSheet("background-color: #00A741;");/*绿色*/
		mPlayer->setSource(QUrl("qrc:/sound/verification_passed.mp3"));
	}
	else
	{
		ui->labelVerifyResult->setText("比对完成，同一性验证不通过");
		ui->labelVerifyResult->setStyleSheet("background-color: #DE2600;");/*红色*/
		mPlayer->setSource(QUrl("qrc:/sound/verification_failed.mp3"));
		
	}
	mPlayer->play();
	ui->labelName->setText(verifyData->baseInfo.name);
	ui->labelSize->setText(verifyData->baseInfo.size);
	ui->labelTexture->setText(verifyData->baseInfo.texture);
	ui->labelAge->setText(verifyData->baseInfo.age);
	ui->labelLevel->setText(verifyData->baseInfo.level);
	if (verifyData->batchInfo.exhibitionTitle.isEmpty())
	{
		ui->labelExhibitionTitleKey->setVisible(false);
		ui->labelExhibitionTitle->setVisible(false);
	}
	else
	{
		ui->labelExhibitionTitleKey->setVisible(true);
		ui->labelExhibitionTitle->setVisible(true);
		ui->labelExhibitionTitle->setText(verifyData->batchInfo.exhibitionTitle);
	}
	
	ui->labelCarrier->setText(verifyData->batchInfo.carrier);
	ui->labelApplicant->setText(verifyData->batchInfo.applicant);
	ui->labelDevice->setText(gDeptName);
	ui->labelAgency->setText(verifyData->baseInfo.regAgency);
	ui->labelRegTime->setText(verifyData->baseInfo.createTime);
	ui->labelVerifyAgency->setText(NetworkServer::instance()->userInfo().unitName);
	ui->labelVerifyTime->setText(verifyData->baseInfo.verifyTime);
	//ui->labelImage->setScaledContents(true);
	ui->labelImage->setAlignment(Qt::AlignCenter);
	QImage image;
	if (verifyData->baseInfo.mainImage.isNull()&&!verifyData->baseInfo.mainImageAddr.isEmpty())
	{
		image = NetImageLoad::loadImageBlocking(verifyData->baseInfo.mainImageAddr);
	}
	else
	{
        image = verifyData->baseInfo.mainImage.copy().scaled(ui->labelImage->size(), Qt::KeepAspectRatio);
	}
	ui->labelImage->setPixmap(QPixmap::fromImage(image));


	/*显示全局视图*/
	auto rawGlobalImage = verifyObj->getRawGlobalImage(number);
	auto globalImage = verifyObj->getGlobalImage(number);
	auto keys = rawGlobalImage->keys();
	QMap<QString, QMap<QString, QImage>> imageList1;
	QMap<QString, QMap<QString, QImage>> imageList2;
	/*分类显示*/
	for (auto key : keys)
	{
		auto pos = key.split("_");
		if (pos.size() >= 4)
		{
			int index = gImgNameList.indexOf(pos[3]);
			if (index >= 0 && index < gImgShowNameList.size())
			{
				QImage tempImage1 = rawGlobalImage->value(key).copy().scaled(400, 225, Qt::KeepAspectRatio);
				QImage tempImage2 = globalImage->value(gVerifyNameHeader+key).copy().scaled(400, 225, Qt::KeepAspectRatio);
				imageList1[gImgShowNameList[index]][key] = tempImage1.copy();
				imageList2[gImgShowNameList[index]][gVerifyNameHeader + key] = tempImage2.copy();
			}
		}
	}
	/*添加新的图片和标签*/
	for (auto key : gImgShowNameList)
	{
		if (imageList2.contains(key) == false)
		{
			qDebug() << "No images found for key:" << key;
			continue; //如果没有图片则跳过
		}
		QString labelText1 = key.size() < 2 ? (key + "部登记图像") : (key + "登记图像");
		QString labelText2 = key.size() < 2 ? (key + "部验证图像") : (key + "验证图像");;
		displayImages(labelText1, &imageList1[key], labelText2,&imageList2[key]);
	}

	/*显示显微图*/
	displayImages("指纹点登记图像", verifyObj->getRawHighImage(number), "指纹点验证图像", verifyObj->getHighImage(number));



}
bool WgtVerifyNo6::updateVerifyData()
{
	return true;
}
void WgtVerifyNo6::clearImage()
{
	/*清除旧的图片*/
	for (auto it = mImageHash.begin(); it != mImageHash.end();)
	{
		mGridLayout->removeWidget(it.value());
		delete it.value();
		it = mImageHash.erase(it);
	}
	/*清除旧的标签*/
	for (auto it = mImageNameHash.begin(); it != mImageNameHash.end();)
	{
		mGridLayout->removeWidget(it.value());
		delete it.value();
		it = mImageNameHash.erase(it);
	}
	mGridLayout->removeItem(mVSpacer);
}

void WgtVerifyNo6::displayImages(QString imageName1, const  QMap<QString, QImage>* imageList1, QString imageName2, const  QMap<QString, QImage>* imageList2)
{
	mGridLayout->removeItem(mVSpacer);
	int row = mGridLayout->rowCount();
	QString labelText1 = imageName1;
	QString labelText2 = imageName2;
	labelText1 += QString::asprintf(" (%d)", imageList1->size());
	labelText2 += QString::asprintf(" (%d)", imageList2->size());
	QLabel* label1 = new QLabel(labelText1, this);
	QLabel* label2 = new QLabel(labelText2, this);
	label1->setObjectName("labelName");
	label2->setObjectName("labelName");
	mGridLayout->addWidget(label1, row, 0);
	mGridLayout->addWidget(label2, row, 1);
	mImageNameHash[labelText1] = label1;
	mImageNameHash[labelText2] = label2;
	row++;
	QList<QString> keys1 = imageList1->keys();
	QList<QString> keys2 = imageList2->keys();
	for (int i = 0; i < keys2.size(); i++)
	{
		auto imageName1 = keys1[i];
		auto imageName2 = keys2[i];
		auto image1 = imageList1->value(imageName1).copy();
		auto image2 = imageList2->value(imageName2).copy();
		WgtVerifyNo61* wgtVerifyNo611 = new WgtVerifyNo61(this);
		WgtVerifyNo61* wgtVerifyNo612 = new WgtVerifyNo61(this);
		wgtVerifyNo611->setImage(image1, Artifact::imageNameShow(imageName1));
		wgtVerifyNo612->setImage(image2, Artifact::imageNameShow(imageName2));
		mGridLayout->addWidget(wgtVerifyNo611, row, 0);
		mGridLayout->addWidget(wgtVerifyNo612, row, 1);
		mImageHash[imageName1] = wgtVerifyNo611;
		mImageHash[imageName2] = wgtVerifyNo612;
		row++;
	}
	mGridLayout->addItem(mVSpacer, row, 0, 1, 2);
}
