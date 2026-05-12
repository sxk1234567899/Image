#include "wgtverifyno1.h"
#include "usbcamera.h"
#include "verifythread.h"
#include "networkserver.h"
#include "ringwait.h"
#include "dlginfo.h"
#include "netimageload.h"

WgtVerifyNo1::WgtVerifyNo1(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo1Class())

{
	ui->setupUi(this);

	ui->scrollArea->setAttribute(Qt::WA_AcceptTouchEvents);
	ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏垂直滚动条
	ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏水平滚动条
	/*设置滚动区域*/
	mScroller = QScroller::scroller(ui->scrollArea);
	mScroller->grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);

	ui->tableWidgetBatch->setAttribute(Qt::WA_AcceptTouchEvents);
	ui->tableWidgetBatch->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetBatch->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetBatch->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui->tableWidgetBatch->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    mBatchScroller = QScroller::scroller(ui->tableWidgetBatch);
	mBatchScroller->grabGesture(ui->tableWidgetBatch, QScroller::LeftMouseButtonGesture);
	
	ui->tableWidgetList->setAttribute(Qt::WA_AcceptTouchEvents);
	ui->tableWidgetList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui->tableWidgetList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	mListScroller = QScroller::scroller(ui->tableWidgetList);
	mListScroller->grabGesture(ui->tableWidgetList, QScroller::LeftMouseButtonGesture);
	ui->toolButtonBatchNextPage->setVisible(false);
	ui->toolButtonBatchUpPage->setVisible(false);
	ui->toolButtonListNextPage->setVisible(false);
	ui->toolButtonListUpPage->setVisible(false);
	
	ui->labelBatchPage->setText("");
	ui->labelListPage->setText("");

	/*初始化tableWidgetBatch*/
	ui->tableWidgetBatch->horizontalHeader()->hide();
	ui->tableWidgetBatch->verticalHeader()->hide();
	ui->tableWidgetBatch->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableWidgetBatch->setSelectionMode(QAbstractItemView::NoSelection);
	//ui->tableWidgetBatch->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableWidgetBatch->setShowGrid(false);
	ui->tableWidgetBatch->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->tableWidgetBatch->setColumnCount(1);
	ui->tableWidgetBatch->setColumnWidth(0, 585);
	ui->tableWidgetBatch->setRowCount(0);

	ui->tableWidgetList->horizontalHeader()->hide();
	ui->tableWidgetList->verticalHeader()->hide();
	ui->tableWidgetList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui->tableWidgetList->setSelectionMode(QAbstractItemView::NoSelection);
	ui->tableWidgetList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetList->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableWidgetList->setShowGrid(false);
	ui->tableWidgetList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->tableWidgetList->setColumnCount(2);
	ui->tableWidgetList->setColumnWidth(0, 360);
	ui->tableWidgetList->setColumnWidth(1, 160);
	ui->tableWidgetList->setRowCount(0);
	connect(ui->tableWidgetList, &QTableWidget::cellClicked, this, &WgtVerifyNo1::tableWidgetListCellClicked);


	mListBatchView = new BatchView(ui->batchView);
	connect(mListBatchView, &BatchView::buttonClicked, this, &WgtVerifyNo1::buttonListBackClicked);

	ui->stackedWidget->setCurrentWidget(ui->pageBatch);
	ui->pushButtonMode->setText("    扫描模式  ");
	ui->pushButtonSCode->setText("刷 新");
	//updateBatchTable();
}

WgtVerifyNo1::~WgtVerifyNo1()
{
	delete ui;
}
void WgtVerifyNo1::updateShow(bool isNew)
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	if (isNew)
	{
		clearBaseInfo();
		ui->stackedWidget->setCurrentWidget(ui->pageBatch);
		ui->pushButtonMode->setText("    扫描模式  ");
		ui->pushButtonSCode->setText("刷 新");
		updateBatchTable();

	}
	else
	{
		/*mCurrentBaseInfo = data->getBaseInfo();
		if (mCurrentBaseInfo.mainImage.isNull() && !mCurrentBaseInfo.mainImageAddr.isEmpty())
		{
			mCurrentBaseInfo.mainImage = NetImageLoad::loadImageBlocking(mCurrentBaseInfo.mainImageAddr);
		}
		ui->labelImage->clear();
		auto image = mCurrentBaseInfo.mainImage.scaled(ui->labelImage->size(), Qt::KeepAspectRatio);
		if (!image.isNull())
		{
			ui->labelImage->setPixmap(QPixmap::fromImage(image));
		}
		else
		{
			ui->labelImage->setText("没有可用主图");
		}
		ui->lineEditName->setText(mCurrentBaseInfo.name);
		ui->lineEditSize->setText(mCurrentBaseInfo.size);
		ui->lineEditTexture->setText(mCurrentBaseInfo.texture);
		ui->lineEditAge->setText(mCurrentBaseInfo.age);
		ui->lineEditLevel->setText(mCurrentBaseInfo.level);
		ui->lineEditDept->setText(gDeptName);
		ui->lineEditApplicant->setText(mCurrentBatchInfo.applicant);
		ui->lineEditCarrier->setText(mCurrentBatchInfo.carrier);
		ui->lineEditExhibitionTitle->setText(mCurrentBatchInfo.exhibitionTitle);*/
	}
	
}
bool WgtVerifyNo1::updateVerifyData()
{
	auto data = VerifyThread::instance();
	QString number = data->getVerifyNumber();
	bool re = false;
	
	if ((data->getVerifyDataList().indexOf(mCurrentBaseInfo.number) >= 0)
		&&(data->getVerifyData(mCurrentBaseInfo.number)->isVerifyFinished != VerifyData::Verify_Finished))
	{
		re = data->updateVerifyData(mCurrentBaseInfo.number, mCurrentBaseInfo, mCurrentBatchInfo);
		data->setVerifyNumber(mCurrentBaseInfo.number);
	}
	else if (!mCurrentBaseInfo.number.isEmpty())
	{
		re = data->addNewVerifyData(mCurrentBaseInfo, mCurrentBatchInfo);
	}
	else
	{
		return false;
	}
	//QModelIndexList sRows = ui->tableWidgetList->selectionModel()->selectedRows();
	//int row = -1;
	//if (sRows.size()== 1)
	//{
	//	row = sRows[0].row();
	//}
	//if (row >= 0 && row < ui->tableWidgetList->rowCount())
	//{
	//	QString temp;
	//	QLabel* item = qobject_cast<QLabel*>(ui->tableWidgetList->cellWidget(row, 1));
	//	QString itemStyle = "border-radius: 4px;";
	//	if (!NetworkServer::instance()->userInfo().nickname.isEmpty())
	//	{
	//		temp = NetworkServer::instance()->userInfo().nickname.mid(0, 8) + "\n";
	//		itemStyle.append("font: 18px \"Microsoft YaHei UI\";");
	//	}
	//	temp += "进行中";
	//	item->setText(temp);
	//	itemStyle.append("background-color: #F1F1F1;color: #00CA63;");/*绿色*/
 //       item->setStyleSheet(itemStyle);
	//}
	if (!re)
	{
		DlgInfo::messageBox(this, tr("警告"), "保存本地数据库出现错误", tr("确定"), tr("删除"), false);
	}
	return re;
}
bool WgtVerifyNo1::back()
{
	if (ui->stackedWidget->currentWidget() == ui->pageList)
	{
		ui->stackedWidget->setCurrentWidget(ui->pageBatch);
		ui->pushButtonMode->setText("    扫描模式  ");
		ui->pushButtonSCode->setText("刷 新");
		updateBatchTable();
		return true;
	}
	else if (ui->stackedWidget->currentWidget() == ui->pageSCode)
	{
		ui->stackedWidget->setCurrentWidget(ui->pageBatch);
		ui->pushButtonMode->setText("    扫描模式  ");
		ui->pushButtonSCode->setText("刷 新");
		updateBatchTable();
		return true;
	}
    return false;
}
void WgtVerifyNo1::updateBatchTable()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	QJsonObject jsonData;
	ui->tableWidgetBatch->setRowCount(0);
	ui->toolButtonBatchNextPage->setVisible(false);
	ui->toolButtonBatchUpPage->setVisible(false);
	update();
	QCoreApplication::processEvents();
	QString message = "接口请求失败,请联系管理员";
	QList<Artifact::BatchInfo> batchList = NetworkServer::instance()->getArtifactsBatchList(mBatchPageIndex, &jsonData,true,&message);
	if (batchList.isEmpty())
	{
		DlgInfo::messageBox(this, tr("警告"), message, tr("确定"), tr("删除"), false);
		return;
	}
	// 清除之前的批次信息
	ui->tableWidgetBatch->setRowCount(batchList.size());
	for (int i = 0; i < batchList.size(); ++i)
	{
		auto& batchInfo = batchList[i];
		BatchView* batch = new BatchView(this);
		batch->updateShow(batchInfo, true);
		ui->tableWidgetBatch->setCellWidget(i, 0, batch);
		ui->tableWidgetBatch->setRowHeight(i, 90);
		mBatchInfoList.append(batch);
		connect(batch, &BatchView::buttonClicked, this, &WgtVerifyNo1::buttonClicked);
		}
	for (int i = 0; i < ui->tableWidgetBatch->rowCount(); ++i)
	{
		for (int j = 0; j < ui->tableWidgetBatch->columnCount(); j++)
		{
			if (ui->tableWidgetBatch->item(i, j))
			{
				ui->tableWidgetBatch->item(i, j)->setTextAlignment(Qt::AlignCenter);
			}
		}
	}
	/*显示总页数*/
	auto pageInfo = jsonData["data"].toObject()["pageInfo"].toObject();
	mBatchPageCount = pageInfo["totalPage"].toInt();
	mBatchPageIndex = pageInfo["currentPage"].toInt();
	ui->labelBatchPage->setText(QString::asprintf("%d/%d", mBatchPageIndex, mBatchPageCount));
	if (mBatchPageCount == 1)
	{
		ui->toolButtonBatchNextPage->setVisible(false);
		ui->toolButtonBatchUpPage->setVisible(false);
	}
	else
	{
		ui->toolButtonBatchNextPage->setVisible(true);
		ui->toolButtonBatchUpPage->setVisible(true);
	}
}
void WgtVerifyNo1::updateListTable()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	QJsonObject jsonData;
	ui->tableWidgetList->setRowCount(0); 
	ui->toolButtonListNextPage->setVisible(false);
	ui->toolButtonListUpPage->setVisible(false);
	update();
	QCoreApplication::processEvents();
	QString message = "接口请求失败,请联系管理员";
	mBaseInfoList = NetworkServer::instance()->getArtifactsList(mCurrentBatchInfo.id, mListPageIndex, &jsonData,true,&message);
	if (mBaseInfoList.isEmpty())
	{
		DlgInfo::messageBox(this, tr("警告"), message, tr("确定"), tr("删除"), false);
		return;
	}
	
	// 清除之前的批次信息
	ui->tableWidgetList->setRowCount(mBaseInfoList.size());
	int i = 0;
	for (auto info : mBaseInfoList)
	{
		QLabel* item = new QLabel;
        item->setAlignment(Qt::AlignCenter);
		QString itemStyle = "border-radius: 4px;";
		if (info.stauts.contains("已完成", Qt::CaseSensitive))
		{
			item->setText(info.verifyResult);
			if (info.verifyResult == "通过")
			{

				itemStyle.append("background-color: #00CA63;");/*绿色*/
			}
			else
			{
				itemStyle.append("background-color: #F95353;");/*红色*/
			}
			itemStyle.append("color: #FFFFFF;");
		}
		else if (info.stauts.contains("进行中", Qt::CaseSensitive))
		{
			QString temp;
			if (!info.nickName.isEmpty())
			{
				temp = info.nickName.mid(0, 8) + "\n";
				itemStyle.append("font: 18px \"Microsoft YaHei UI\";");
			}
			temp += info.stauts;
			item->setText(temp);
			itemStyle.append("background-color: #F1F1F1;color: #00CA63;");/*绿色*/
		}
		else
		{
			item->setText("未开始");
			itemStyle.append("background-color: #F1F1F1;color: #F95353;");/*红色*/
		}
		ui->tableWidgetList->setItem(i, 0, new QTableWidgetItem(info.name));
        item->setStyleSheet(itemStyle);
		ui->tableWidgetList->setCellWidget(i, 1, item);
		ui->tableWidgetList->setRowHeight(i, 100);
		i++;
	}
	ui->tableWidgetList->style()->polish(ui->tableWidgetList->viewport());
	for (int i = 0; i < ui->tableWidgetList->rowCount(); ++i)
	{
		if (ui->tableWidgetList->item(i, 1))
		{
			ui->tableWidgetList->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		}
	}
	/*显示总页数*/
	auto pageInfo = jsonData["data"].toObject()["list"].toObject()["pageInfo"].toObject();
	qDebug() << "WgtVerifyNo1::updateListTable";
	qDebug().noquote() << QString::fromUtf8(QJsonDocument(pageInfo).toJson(QJsonDocument::Indented));
	mListPageCount = pageInfo["totalPage"].toInt();
	mListPageIndex = pageInfo["currentPage"].toInt();
	ui->labelListPage->setText(QString::asprintf("%d/%d", mListPageIndex, mListPageCount));
	if (mListPageCount == 1)
	{
		ui->toolButtonListNextPage->setVisible(false);
		ui->toolButtonListUpPage->setVisible(false);
	}
	else
	{
		ui->toolButtonListNextPage->setVisible(true);
		ui->toolButtonListUpPage->setVisible(true);
	}
}
void WgtVerifyNo1::clearBaseInfo()
{
	ui->lineEditName->setText(QString());
	ui->lineEditSize->setText(QString());
	ui->lineEditTexture->setText(QString());
	ui->lineEditAge->setText(QString());
	ui->lineEditLevel->setText(QString());
	ui->lineEditExhibitionTitle->setText(QString());
	ui->lineEditCarrier->setText(QString());
	ui->lineEditApplicant->setText(QString());
	ui->lineEditDept->setText(QString());
	ui->labelImage->clear();
	ui->tableWidgetList->clearSelection();
	mCurrentBaseInfo = BaseInfo();
}
void WgtVerifyNo1::showBaseInfo()
{
	ui->lineEditName->setText(mCurrentBaseInfo.name);
	ui->lineEditSize->setText(mCurrentBaseInfo.size);
	ui->lineEditTexture->setText(mCurrentBaseInfo.texture);
	ui->lineEditAge->setText(mCurrentBaseInfo.age);
	ui->lineEditLevel->setText(mCurrentBaseInfo.level);
	ui->lineEditDept->setText(gDeptName);
	ui->lineEditApplicant->setText(mCurrentBatchInfo.applicant);
	ui->lineEditCarrier->setText(mCurrentBatchInfo.carrier);
	if (mCurrentBatchInfo.exhibitionTitle.isEmpty())
	{
		ui->lineEditExhibitionTitle->setVisible(false);
		ui->labelExhibitionTitle->setVisible(false);
	}
	else
	{
		ui->lineEditExhibitionTitle->setVisible(true);
		ui->labelExhibitionTitle->setVisible(true);
		ui->lineEditExhibitionTitle->setText(mCurrentBatchInfo.exhibitionTitle);
	}
	update();
	QApplication::processEvents();
	mCurrentBaseInfo.mainImage = NetImageLoad::loadImageBlocking(mCurrentBaseInfo.mainImageAddr);
	ui->labelImage->setPixmap(QPixmap::fromImage(mCurrentBaseInfo.mainImage.copy().scaled(ui->labelImage->size(), Qt::KeepAspectRatio)));

	QList<QLineEdit*> allLineEdits = ui->scrollArea->findChildren<QLineEdit*>();
	// 遍历并操作这些QLineEdit（示例：打印对象名和内容）
	for (QLineEdit* lineEdit : allLineEdits)
	{
		if (lineEdit)
		{
			lineEdit->setCursorPosition(0);
		}
	}
}
void WgtVerifyNo1::on_pushButtonSCode_clicked()
{
	if (ui->stackedWidget->currentWidget() == ui->pageSCode)
	{
		/*TODO:实现扫描解析功能*/
		QScopedPointer<RingWait> rangWait(new RingWait(this));
		rangWait->show();
		QString number = ui->plainTextEdit->toPlainText();
		QRegularExpression regex("\\p{C}");
		// 将匹配到的不可见字符替换为空字符串
		number = number.replace(regex, "");
		QString message;
		if (!NetworkServer::instance()->getArtifactsDetailInfo(0, number, &mCurrentBaseInfo, &mCurrentBatchInfo, false, &message))
		{
			DlgInfo::messageBox(this, tr("警告"), message, tr("确定"), tr("删除"), false);
			clearBaseInfo();
			mCurrentBatchInfo = Artifact::BatchInfo();
		}
		else
		{
			showBaseInfo();
		}
		qDebug() << "regData:";
	}
	else if (ui->stackedWidget->currentWidget() == ui->pageBatch)
	{
		updateBatchTable();
        clearBaseInfo();
	}
	else if (ui->stackedWidget->currentWidget() == ui->pageList)
	{
        updateListTable();
		clearBaseInfo();
	}

}

void WgtVerifyNo1::on_pushButtonMode_clicked()
{

	if (ui->stackedWidget->currentWidget() == ui->pageBatch || ui->stackedWidget->currentWidget() == ui->pageList)
	{
		ui->stackedWidget->setCurrentWidget(ui->pageSCode);
		ui->pushButtonMode->setText("    列表模式  ");
		ui->pushButtonSCode->setText("扫一扫");
        clearBaseInfo();
	}
	else if (ui->stackedWidget->currentWidget() == ui->pageSCode)
	{
		ui->stackedWidget->setCurrentWidget(ui->pageBatch);
		ui->pushButtonMode->setText("    扫描模式  ");
		ui->pushButtonSCode->setText("刷 新");
		updateBatchTable();
	}
}

void WgtVerifyNo1::on_toolButtonBatchUpPage_clicked()
{
	
	if (mBatchPageIndex > 1)
	{
		mBatchPageIndex--;
		updateBatchTable();
	}
}
void WgtVerifyNo1::on_toolButtonBatchNextPage_clicked()
{
	if (mBatchPageIndex < mBatchPageCount)
	{
		mBatchPageIndex++;
		updateBatchTable();
	}
}
void WgtVerifyNo1::on_toolButtonListUpPage_clicked()
{
	if (mListPageIndex > 1)
	{
		mListPageIndex--;
		updateListTable();
	}
}
void WgtVerifyNo1::on_toolButtonListNextPage_clicked()
{
	if (mListPageIndex < mListPageCount)
	{
		mListPageIndex++;
		updateListTable();
	}
}
void WgtVerifyNo1::tableWidgetListCellClicked(int row, int column)
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	if (row < mBaseInfoList.size())
	{
		mCurrentBaseInfo = mBaseInfoList[row];
		showBaseInfo();
	}
}
void WgtVerifyNo1::buttonListBackClicked(Artifact::BatchInfo batchInfo)
{
	ui->stackedWidget->setCurrentWidget(ui->pageBatch);
}
void WgtVerifyNo1::buttonClicked(Artifact::BatchInfo batchInfo)
{
	mListBatchView->updateShow(batchInfo, false);
	/*更新list*/
	mListPageIndex = 1;
	mCurrentBatchInfo = batchInfo;
	updateListTable();
	ui->stackedWidget->setCurrentWidget(ui->pageList);
	ui->tableWidgetList->clearSelection();
}
