#include "wgtregno5.h"
#include "regthread.h"
#include "networkserver.h"
#include "ringwait.h"
WgtRegNo5::WgtRegNo5(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegNo5Class())
	, mButtonGroup(new QButtonGroup(this))
{
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
	mGridLayout->setVerticalSpacing(20);
	mGridLayout->setHorizontalSpacing(20);
	mGridLayout->addItem(mVSpacer, 0, 0, 1, 3);
	/*设置按钮组*/
	mButtonGroup->setObjectName("imageButtonGroup");
	connect(mButtonGroup, &QButtonGroup::buttonToggled, this, &WgtRegNo5::buttonToggled);
}

WgtRegNo5::~WgtRegNo5()
{
	delete ui;
}
void WgtRegNo5::updateShow()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	auto regData = RegThread::instance();
	QString number = regData->getRegNumber();
	if(number.isEmpty())
	{
		qDebug() << "No registration data available.";
		return;
	}
	clearImage();
	auto baseInfo = regData->getBaseInfo();
	auto batchInfo = regData->getBatchInfo();
	
	ui->labelName->setText(baseInfo.name);
	ui->labelSize->setText(baseInfo.size);
	ui->labelTexture->setText(baseInfo.texture);
	ui->labelAge->setText(baseInfo.age);
	ui->labelLevel->setText(baseInfo.level);
	if (batchInfo.exhibitionTitle.isEmpty())
	{
		ui->label_6->setVisible(false);
	}
	else
	{
		ui->label_6->setVisible(true);
	}
	ui->labelExhibitionTitle->setText(batchInfo.exhibitionTitle);
	ui->labelCarrier->setText(batchInfo.carrier);
	ui->labelApplicant->setText(batchInfo.applicant);
	ui->labelDevice->setText(gDeptName);
	ui->labelAgency->setText(NetworkServer::instance()->userInfo().unitName);
	ui->labelRegTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	//ui->labelImage->setScaledContents(true);
	ui->labelImage->setAlignment(Qt::AlignCenter);
	ui->labelImage->setPixmap(QPixmap::fromImage(baseInfo.mainImage.copy().scaled(ui->labelImage->size(), Qt::KeepAspectRatio)));
	/*显示全局视图*/
	auto globalImage = regData->getGlobalImage(number);
	auto keys = globalImage->keys();
	QMap<QString, QMap<QString, QImage>> imageList;
	/*分类显示*/
	for (auto key : keys)
	{
		auto pos = key.split("_");
		if (pos.size() >= 4)
		{
			int index = gImgNameList.indexOf(pos[3]);
			if (index >= 0 && index < gImgShowNameList.size())
			{
				QImage tempImage = globalImage->value(key).copy().scaled(400, 225, Qt::KeepAspectRatio);
				imageList[gImgShowNameList[index]][key] = tempImage.copy();
			}
		}
	}
	/*添加新的图片和标签*/
	for (auto key : gImgShowNameList)
	{
		if (imageList.contains(key) == false)
		{
			qDebug() << "No images found for key:" << key;
			continue; //如果没有图片则跳过
		}
		QString labelText = key.size() < 2 ? (key + "部视图") : (key + "视图");
		displayImages(labelText, &imageList[key]);
	}

	/*显示显微图*/
	displayImages("指纹点图像", regData->getHighImage(number),false);

	/*显示标记图*/
	displayImages("标记图像", regData->getMarkedImage(number), false);

	/*显示低分辨率图*/
	displayImages("低倍图", regData->getLowImage(number), false);
}
bool WgtRegNo5::updateRegData()
{

	return true;
}

void WgtRegNo5::clearImage()
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
void WgtRegNo5::displayImages(QString imageName,const  QMap<QString, QImage>* imageList, bool isButton)
{
	mGridLayout->removeItem(mVSpacer);
	int row = mGridLayout->rowCount();
	int col = 0;
	QString labelText = imageName;
	labelText += QString::asprintf(" (%d)", imageList->size());
	QLabel* label = new QLabel(labelText, this);
	label->setObjectName("labelName");
	mGridLayout->addWidget(label, row, 0, 1, 3);
	row++;
	mImageNameHash[labelText] = label;
	for (auto it = imageList->begin(); it != imageList->end();it++)
	{
		auto imageName = it.key();
		auto image = it.value().copy();
		WgtRegNo51* wgtRegNo51 = new WgtRegNo51(this);
		wgtRegNo51->setImage(image, Artifact::imageNameShow(imageName));
		mGridLayout->addWidget(wgtRegNo51, row, col);
		mImageHash[imageName] = wgtRegNo51;
		if (isButton)
		{
			mButtonGroup->addButton(wgtRegNo51->ui->checkBoxSetMain);
		}
		else
		{
			wgtRegNo51->ui->checkBoxSetMain->hide();
		}
		col++;
		if (col >= 3) //每行显示3个
		{
			row++;
			col = 0;
		}
	}
	mGridLayout->addItem(mVSpacer, row, 0, 1, 3);
}

void WgtRegNo5::buttonToggled(QAbstractButton* button, bool checked)
{
	QCheckBox* checkBox = qobject_cast<QCheckBox*>(button);
	WgtRegNo51* wgtRegNo51 = qobject_cast<WgtRegNo51*>(checkBox->parentWidget());
	if (wgtRegNo51)
	{
		qDebug() <<wgtRegNo51->mImageName;
		QString mainImageName = Artifact::imageName(wgtRegNo51->mImageName);
		auto regData = RegThread::instance();
		QString number = regData->getRegNumber();
		if (number.isEmpty()||!regData->getGlobalImage(number)->contains(mainImageName))
		{
			qDebug() << "No registration data available.";
			return;
		}
		regData->addMainImage(number, mainImageName);
		QImage mainImage = regData->getGlobalImage(number)->value(mainImageName).copy();
		mainImage = mainImage.scaled(ui->labelImage->size(), Qt::KeepAspectRatio);
		ui->labelImage->setPixmap(QPixmap::fromImage(mainImage));
	}
}
