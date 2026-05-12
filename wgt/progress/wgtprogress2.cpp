#include "wgtprogress2.h"

WgtProgress2::WgtProgress2(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtProgress2Class())
{
	ui->setupUi(this);
	/*初始化tableWidget表格*/
	ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	mScroller = QScroller::scroller(ui->tableWidget);
	mScroller->grabGesture(ui->tableWidget, QScroller::LeftMouseButtonGesture);

	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
	ui->tableWidget->verticalHeader()->hide();
	ui->tableWidget->setColumnCount(3);
	ui->tableWidget->setShowGrid(false);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->tableWidget->horizontalHeader()->setFixedHeight(80);
	ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "图片地址" << "状态" << "操作");
	ui->tableWidget->setColumnWidth(0, 700);
	ui->tableWidget->setColumnWidth(1, 150);
	ui->tableWidget->setColumnWidth(2, 150);

	connect(ui->tableWidget, &QTableWidget::cellClicked, this, &WgtProgress2::tableWidgetClicked);
}

WgtProgress2::~WgtProgress2()
{
	delete ui;
}

void WgtProgress2::updateShow(bool isReg, QString number)
{
	mIsReg = isReg;
	mNumber = number;
	mImageNames.clear();
	ui->tableWidget->setRowCount(0);
	if (isReg)
	{/*登记信息*/
		auto regObj = RegThread::instance();
		auto regData = regObj->getRegData(number);
		if (regData)
		{
			
			QString info = "名称：\n" + regData->baseInfo.name + "\n\n";
			info += "编号：\n" + number;
			ui->textBrowser->setPlainText(info);
			ui->tableWidget->setRowCount(regData->imageInfo.size());
			int row = 0;
			for (auto key : regData->imageInfo.keys())
			{
				mImageNames.append(key);
				ImageInfo info = regData->imageInfo[key];
				ui->tableWidget->setRowHeight(row, 80);
				ui->tableWidget->setItem(row, 0, new QTableWidgetItem(info.imageLocalAddr));
				tabStatus(row, info.status);
				row++;
			}
			for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
			{
				for (int j = 0; j < ui->tableWidget->columnCount(); j++)
				{
					if (ui->tableWidget->item(i, j))
					{
						ui->tableWidget->item(i, j)->setTextAlignment(Qt::AlignCenter);
					}
				}
			}
		}
	}
	else
	{/*验证信息*/
		auto verifyObj = VerifyThread::instance();
		auto verifyData = verifyObj->getVerifyData(number);
		if (verifyData)
		{

			QString info = "名称：\n" + verifyData->baseInfo.name + "\n\n";
			info += "编号：\n" + number;
			ui->textBrowser->setPlainText(info);
			ui->tableWidget->setRowCount(verifyData->imageInfo.size());
			int row = 0;
			for (auto key : verifyData->imageInfo.keys())
			{
				mImageNames.append(key);
				ImageInfo info = verifyData->imageInfo[key];
				ui->tableWidget->setRowHeight(row, 80);
				ui->tableWidget->setItem(row, 0, new QTableWidgetItem(info.imageLocalAddr));
				tabStatus(row, info.status);
				row++;
			}
			for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
			{
				for (int j = 0; j < ui->tableWidget->columnCount(); j++)
				{
					if (ui->tableWidget->item(i, j))
					{
						ui->tableWidget->item(i, j)->setTextAlignment(Qt::AlignCenter);
					}
				}
			}
		}
	}
}

void WgtProgress2::tabStatus(int row, ImageStatus stat)
{
	switch (stat)
	{
	case ImageStatus::saved:
	{
		auto item1 = new QTableWidgetItem("成功");
		item1->setForeground(QBrush(QColor(0x00AB22)));
		ui->tableWidget->setItem(row, 1, item1);
		break;
	}
	case ImageStatus::unsaved:
	{
		auto item1 = new QTableWidgetItem("进行中");
		item1->setForeground(QBrush(QColor(0xEAA200)));
		ui->tableWidget->setItem(row, 1, item1);
		break;
	}
	case ImageStatus::saveFailed:
	{
		auto item1 = new QTableWidgetItem("失败");
		item1->setForeground(QBrush(QColor(0xED0808)));
		ui->tableWidget->setItem(row, 1, item1);
		auto item2 = new QTableWidgetItem("重试上传");
		item2->setForeground(QBrush(QColor(0x1865FF)));
		ui->tableWidget->setItem(row, 2, item2);
		break;
	}
	default:
		break;
	}

}

void WgtProgress2::tableWidgetClicked(int row, int column)
{
	if (column == 2 && ui->tableWidget->item(row, column))
	{
		if (mIsReg)
		{
			auto regObj = RegThread::instance();
			ImageInfo info;
			if (regObj->getImageInfo(mNumber, mImageNames[row],&info))
			{
				info.status = ImageStatus::unsaved;
				regObj->updateImageInfo(mNumber, mImageNames[row], info);
                updateShow(true, mNumber);
			}
		}
		else
		{
			auto verifyObj = VerifyThread::instance();
			ImageInfo info;
			if (verifyObj->getImageInfo(mNumber, mImageNames[row], &info))
			{
				info.status = ImageStatus::unsaved;
				verifyObj->updateImageInfo(mNumber, mImageNames[row], info);
				updateShow(false, mNumber);
			}
		}
	}
}