#include <QtConcurrent>
#include "wgtverifyno2.h"
#include "verifythread.h"
#include "networkServer.h"
#include "ringwait.h"
#include "netimageload.h"
#include "dlginfo.h"
WgtVerifyNo2::WgtVerifyNo2(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo2Class())
{
	ui->setupUi(this);
	ui->scrollArea->setAttribute(Qt::WA_AcceptTouchEvents);
	ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏垂直滚动条
	ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏水平滚动条
	/*设置滚动区域*/
	mScroller = QScroller::scroller(ui->scrollArea);
	mScroller->grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);
	minioConf = AppConfig::instance()->minioConf();
}
void WgtVerifyNo2::hideEvent(QHideEvent * event)
{
	for (auto verifyNo21 = wgtVerifyNo21List.begin(); verifyNo21 != wgtVerifyNo21List.end();)
	{
		ui->horizontalLayoutImageView->removeWidget(*verifyNo21);
		delete* verifyNo21;
		verifyNo21 = wgtVerifyNo21List.erase(verifyNo21);
	}
}
WgtVerifyNo2::~WgtVerifyNo2()
{
	delete ui;
}
void WgtVerifyNo2::updateShow(bool isNew)
{
	if (!isNew)
	{
		return;
	}
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	for (auto verifyNo21 = wgtVerifyNo21List.begin(); verifyNo21 != wgtVerifyNo21List.end();)
	{
		ui->horizontalLayoutImageView->removeWidget(*verifyNo21);
		delete* verifyNo21;
		verifyNo21 = wgtVerifyNo21List.erase(verifyNo21);
	}
	ui->pushButtonGoVerify3->setEnabled(false);
	VerifyThread *verifyObj=VerifyThread::instance();
	NetworkServer *network = NetworkServer::instance();
	auto baseInfo = verifyObj->getBaseInfo();
	auto batchInfo = verifyObj->getBatchInfo();
	quint32 count = 1;

	ui->labelName->setText(baseInfo.name);
	ui->labelSize->setText(baseInfo.size);
	ui->labelTexture->setText(baseInfo.texture);
	ui->labelAge->setText(baseInfo.age);
	ui->labelLevel->setText(baseInfo.level);
	if (batchInfo.exhibitionTitle.isEmpty())
	{
		ui->labelExhibitionTitleKey->setVisible(false);
		ui->labelExhibitionTitle->setVisible(false);
	}
	else
	{
		ui->labelExhibitionTitleKey->setVisible(true);
		ui->labelExhibitionTitle->setVisible(true);
		ui->labelExhibitionTitle->setText(batchInfo.exhibitionTitle);
	}
	ui->labelCarrier->setText(batchInfo.carrier);
	ui->labelApplicant->setText(batchInfo.applicant);
	ui->labelDevice->setText(gDeptName);
	ui->labelAgency->setText(network->userInfo().unitName);
	ui->labelRegTime->setText(baseInfo.createTime);
	ui->labelImage->setPixmap(QPixmap::fromImage(baseInfo.mainImage.copy().scaled(ui->labelImage->size(), Qt::KeepAspectRatio)));
	ui->labelImage->setAlignment(Qt::AlignmentFlag::AlignCenter);
	if(verifyObj->getVerifyData()->isVerifyFinished == VerifyData::Verify_LoadRawImage)
	{ 
		auto jsonData = network->getValidatesArtifactFlagImg(baseInfo.number);
		if (jsonData.isEmpty())
		{
			DlgInfo::messageBox(this, "警告","获取标记图失败", "确定", "", false);
			return;
		}
		auto globalImageArray = jsonData.value("data").toObject()["selected_around"].toArray();
		auto samplingImageArray = jsonData.value("data").toObject()["selected_sampling"].toArray();
		QList<ImageInfo*> imageInfoList;
		for (auto globalImage : globalImageArray)
		{
			auto data = globalImage.toObject();
			ImageInfo *info = new ImageInfo;
			info->number = baseInfo.number;
			info->id = data.value("id").toInt();
			QString part = data.value("part").toString();
			int index = Artifact::gImgShowNameList.indexOf(part);
			index = index >= 0 ? index : 0;
			info->imageName = verifyObj->globalImageName(baseInfo.number, index);
			info->imageNetAddr = data.value("image").toString();
			info->imageLocalDir = verifyObj->mVerifyRawImageDir;
			info->imageLocalAddr = verifyObj->mVerifyRawImageDir;
			info->imageLocalAddr.append("/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz"));
			info->imageLocalAddr.append("__" + info->imageName);
			info->imageLocalAddr.append(".png");
			if (info->imageNetAddr.startsWith(minioConf.imageUrl) && !info->imageNetAddr.endsWith("-s"))
			{
				info->imageNetAddr += "-s";
			}
			imageInfoList.append(info);
		}
		count = 1;
		for (auto samplingImage : samplingImageArray)
		{
			auto data = samplingImage.toObject();
			if (data.contains("mark_point_image"))
			{/*标记图*/
				ImageInfo *markInfo = new ImageInfo;
				markInfo->id = data.value("id").toInt();
				markInfo->number = baseInfo.number;
				markInfo->imageNetAddr = data.value("mark_point_image").toString();
				QStringList temps = markInfo->imageNetAddr.split(QRegularExpression("[/.]"));
				if (temps.size() > 2)
				{
					markInfo->imageName = temps[temps.size() - 2];
					int index = markInfo->imageName.indexOf("D_01_");
					if (index > 0)
					{
						markInfo->imageName = markInfo->imageName.mid(index, 16);
					}
					else
					{
						markInfo->imageName = QString("D_01_001_Top_M%1").arg(count, 2, 10, QChar('0'));
					}
				}
				else
				{
					markInfo->imageName = QString("D_01_001_Top_M%1").arg(count, 2, 10, QChar('0'));
				}
				markInfo->imageLocalDir = verifyObj->mVerifyRawImageDir;
				markInfo->imageLocalAddr = verifyObj->mVerifyRawImageDir;
				markInfo->imageLocalAddr.append("/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz"));
				markInfo->imageLocalAddr.append("__" + markInfo->imageName);
				markInfo->imageLocalAddr.append(".png");
				if (markInfo->imageNetAddr.startsWith(minioConf.imageUrl) && !markInfo->imageNetAddr.endsWith("-s"))
				{
					markInfo->imageNetAddr += "-s";
				}
				imageInfoList.append(markInfo);
			}	
			if (data.contains("low_mag_image"))
			{/*低倍图*/
				ImageInfo *lowInfo = new ImageInfo;
				lowInfo->id = data.value("id").toInt();
				lowInfo->number = baseInfo.number;
				lowInfo->imageNetAddr = data.value("low_mag_image").toObject()["img"].toString();
				QStringList temps = lowInfo->imageNetAddr.split(QRegularExpression("[/.]"));
				if (temps.size() > 2)
				{
					lowInfo->imageName = temps[temps.size() - 2];
					int index = lowInfo->imageName.indexOf("W_03_");
					if (index > 0)
					{
						lowInfo->imageName = lowInfo->imageName.mid(index, 16);
					}
					else
					{
						lowInfo->imageName = QString("W_03_001_Top_M%1").arg(count, 2, 10, QChar('0'));
					}
				}
				else
				{
					lowInfo->imageName = QString("W_03_001_Top_M%1").arg(count, 2, 10, QChar('0'));
				}
				lowInfo->imageLocalDir = verifyObj->mVerifyRawImageDir;
				lowInfo->imageLocalAddr = verifyObj->mVerifyRawImageDir;
				lowInfo->imageLocalAddr.append("/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz"));
				lowInfo->imageLocalAddr.append("__" + lowInfo->imageName);
				lowInfo->imageLocalAddr.append(".png");
				if (lowInfo->imageNetAddr.startsWith(minioConf.imageUrl) && !lowInfo->imageNetAddr.endsWith("-s"))
				{
					lowInfo->imageNetAddr += "-s";
				}
				imageInfoList.append(lowInfo);
			}
			if (data.contains("high_mag_image"))
			{/*高倍图*/
				ImageInfo *highInfo = new ImageInfo;
				highInfo->id = data.value("id").toInt();
				highInfo->number = baseInfo.number;
				highInfo->imageNetAddr = data.value("high_mag_image").toObject()["img"].toString();
				QStringList temps = highInfo->imageNetAddr.split(QRegularExpression("[/.]"));
				if (temps.size() > 2)
				{
					highInfo->imageName = temps[temps.size() - 2];
					int index = highInfo->imageName.indexOf("W_02_");
					if (index > 0)
					{
						highInfo->imageName = highInfo->imageName.mid(index, 16);
					}
					else
					{
						highInfo->imageName = QString("W_02_001_Top_M%1").arg(count, 2, 10, QChar('0'));
					}
				}
				else
				{
					highInfo->imageName = QString("W_02_001_Top_M%1").arg(count, 2, 10, QChar('0'));
				}
				highInfo->imageLocalDir = verifyObj->mVerifyRawImageDir;
				highInfo->imageLocalAddr = verifyObj->mVerifyRawImageDir;
				highInfo->imageLocalAddr.append("/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz"));
				highInfo->imageLocalAddr.append("__" + highInfo->imageName);
				highInfo->imageLocalAddr.append(".png");
				if (highInfo->imageNetAddr.startsWith(minioConf.imageUrl) && !highInfo->imageNetAddr.endsWith("-s"))
				{
					highInfo->imageNetAddr += "-s";
				}
				imageInfoList.append(highInfo);
			}
			count++;
		}

		/*多线程现在照片*/
		QList<QImage> imageList;
		bool isDownloads = true;
		while (true)
		{
			isDownloads = true;
			QFuture<QList<QImage>> future = QtConcurrent::run([=]() {
				return NetImageLoad::loadImageListBlocking(imageInfoList);
				});
			/*事件循环等待*/
			while (!future.isFinished())
			{
				QCoreApplication::processEvents();
				QThread::msleep(50);
			}
			imageList = future.result();
			for (int i = 0; i < imageList.size(); i++)
			{
				if (imageList[i].isNull()&&QUrl(imageInfoList[i]->imageNetAddr).isValid())
				{
					isDownloads = false;
					break;
				}
			}
			if(isDownloads)
			{
				break;
			}
			else if(DlgInfo::DlgInfoResult::Cancel == DlgInfo::messageBox(this, "提示", "验证对比图片下载失败,是否重试！", "重试", "否", false))
			{
				break;
			}
		}

		/*更新数据到内存*/
		for (int i = 0; i < imageInfoList.size(); i++)
		{ 
			auto imageInfo = *imageInfoList[i];
			if(imageInfo.imageName.startsWith("D_01_") && imageInfo.imageName.size() == 12)
			{
				verifyObj->addRawGlobalImage(baseInfo.number, imageInfo.imageName, imageList[i], imageInfo);
			}
			else if (imageInfo.imageName.startsWith("D_01_"))
			{
				verifyObj->addRawMarkedImage(baseInfo.number, imageInfo.imageName, imageList[i], imageInfo);
			}
			else if (imageInfo.imageName.startsWith("W_03_"))
			{
				verifyObj->addRawLowImage(baseInfo.number, imageInfo.imageName, imageList[i], imageInfo);
			}
			else if (imageInfo.imageName.startsWith("W_02_"))
			{
				verifyObj->addRawHighImage(baseInfo.number, imageInfo.imageName, imageList[i], imageInfo);
			}
		}
		verifyObj->loadRawImageFinished(baseInfo.number);
	}
	
	auto globalImageMap = verifyObj->getRawGlobalImage();
	for (auto gImageIt= globalImageMap->begin(); gImageIt != globalImageMap->end(); gImageIt++)
    {
		WgtVerifyNo21* verifyNo21 = new WgtVerifyNo21(this);
		QString part = "顶";
		auto pos = gImageIt.key().split("_");
		if (pos.size() >= 4)
		{
			int index = gImgNameList.indexOf(pos[3]);
			part = gImgShowNameList[index];
		}
		verifyNo21->setImage(gImageIt.value(), part.size() < 2 ? (part + "部视图") : (part + "视图"));
		ui->horizontalLayoutImageView->addWidget(verifyNo21);
		wgtVerifyNo21List.append(verifyNo21);
		/*更新界面，防止卡顿*/
		QCoreApplication::processEvents();
    }
	
	auto highImageMap = verifyObj->getRawHighImage();
	count = 1;
	for (auto hImageIt= highImageMap->begin(); hImageIt != highImageMap->end(); hImageIt++)
    { 
		WgtVerifyNo21* verifyNo21 = new WgtVerifyNo21(this);
		verifyNo21->setImage(hImageIt.value(), QString("指纹点图像%1").arg(count));
		ui->horizontalLayoutImageView->addWidget(verifyNo21);
		wgtVerifyNo21List.append(verifyNo21);
		count++;
		/*更新界面，防止卡顿*/
		QCoreApplication::processEvents();
    }
	if (wgtVerifyNo21List.isEmpty() == false)
	{
		(*wgtVerifyNo21List.begin())->setLeftLineVisible(false);
		(*wgtVerifyNo21List.rbegin())->setRightLineVisible(false);
	}
	ui->pushButtonGoVerify3->setEnabled(true);
}
bool WgtVerifyNo2::updateVerifyData()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	if (VerifyThread::instance()->getVerifyData()->isVerifyFinished == VerifyData::Verify_LoadRawImage)
	{
		DlgInfo::messageBox(this, "警告", "获取验证原始图片失败,不能进行下一步", "确定", "", false);
		return false;
	}
	QString message;
	if (!NetworkServer::instance()->postArtifactsStatus(VerifyThread::instance()->getBaseInfo().id, "进行中", &message, true))
	{
		DlgInfo::messageBox(this, tr("警告"), message, tr("确定"), tr("删除"), false);
		return false;
	}
	return true;
}