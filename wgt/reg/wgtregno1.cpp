#include "wgtregno1.h"
#include "usbcamera.h"
#include "regthread.h"
#include "networkserver.h"
#include "ringwait.h"
#include "dlginfo.h"
#include "netimageload.h"

WgtRegNo1::WgtRegNo1(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegNo1Class())

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


	//sxk：需求变更,隐藏控件
	ui->label_21->setVisible(false);
	ui->label_22->setVisible(false);
	ui->lineEditApplicant->setVisible(false);
	ui->lineEditCarrier->setVisible(false);
	

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
	connect(ui->tableWidgetList, &QTableWidget::cellClicked, this, &WgtRegNo1::tableWidgetListCellClicked);


	mListBatchView = new BatchView(ui->batchView);
	connect(mListBatchView, &BatchView::buttonClicked, this, &WgtRegNo1::buttonListBackClicked);

	ui->stackedWidget->setCurrentWidget(ui->pageBatch);
	ui->pushButtonMode->setText("    扫描模式  ");
	ui->pushButtonSCode->setText("刷 新");
	//updateBatchTable();
}

WgtRegNo1::~WgtRegNo1()
{
	delete ui;
}
void WgtRegNo1::updateShow(bool isNew)
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
bool WgtRegNo1::updateRegData()
{
	auto data = RegThread::instance();
	bool re = false;
	QString message;
	if (!NetworkServer::instance()->postArtifactsStatus(mCurrentBaseInfo.id, "进行中", &message))
	{
		if ((ui->stackedWidget->currentWidget() == ui->pageSCode)
			&&(message.contains("该标已完成")))
		{
			
		}
		else
		{
			DlgInfo::messageBox(this, tr("警告"), message, tr("确定"), tr("删除"), false);
			return false;
		}
	}
	if (data->getRegNumberList().indexOf(mCurrentBaseInfo.number)>=0)
	{
		re = data->updateRegData(mCurrentBaseInfo.number, mCurrentBaseInfo, mCurrentBatchInfo);
		data->setRegNumber(mCurrentBaseInfo.number);
	}
	else if (!mCurrentBaseInfo.number.isEmpty())
	{
       re = data->addNewRegData(mCurrentBaseInfo, mCurrentBatchInfo);
	}
	QModelIndexList sRows = ui->tableWidgetList->selectionModel()->selectedRows();
	int row = -1;
	if (sRows.size()== 1)
	{
		row = sRows[0].row();
	}
	if (row >= 0 && row < ui->tableWidgetList->rowCount())
	{
		QString temp;
		auto item = ui->tableWidgetList->item(row, 1);
		if (!NetworkServer::instance()->userInfo().nickname.isEmpty())
		{
			temp = NetworkServer::instance()->userInfo().nickname.mid(0, 8) + "\n";
			QFont font = item->font(); // 获取当前字体
			font.setFamily("Microsoft YaHei UI");
			font.setPixelSize(18); // 在现有字体基础上修改大小
			item->setFont(font); // 重新应用字体
		}
		temp += "进行中";
		item->setText(temp);
		item->setForeground(QBrush(QColor(0x00CA63)));/*绿色*/
	}
	if (!re)
	{
		DlgInfo::messageBox(this, tr("警告"), "保存本地数据库出现错误", tr("确定"), tr("删除"), false);
	}
	
    return re;
}
bool WgtRegNo1::back()
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

// 更新批次列表
void WgtRegNo1::updateBatchTable()
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
	QList<Artifact::BatchInfo> batchList = NetworkServer::instance()->getArtifactsBatchList(mBatchPageIndex, &jsonData,false,&message);
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
		BatchView *batch = new BatchView(this);
		batch->updateShow(batchInfo, true);
		
		//申请每一个批次的展览标题和批次信息
		ui->tableWidgetBatch->setCellWidget(i, 0, batch);
		ui->tableWidgetBatch->setRowHeight(i, 90);
		mBatchInfoList.append(batch);
		connect(batch, &BatchView::buttonClicked, this, &WgtRegNo1::buttonClicked);
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

// 更新文物列表信息
void WgtRegNo1::updateListTable()
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
	mBaseInfoList = NetworkServer::instance()->getArtifactsList(mCurrentBatchInfo.id,mListPageIndex, &jsonData,false,&message);
	if (mBaseInfoList.isEmpty())
	{
		DlgInfo::messageBox(this, tr("警告"), message, tr("确定"), tr("删除"), false);
		return;
	}
	// 清除之前的批次信息
	ui->tableWidgetList->setRowCount(mBaseInfoList.size());
	QTableWidgetItem* item;
	int i =0;
	for (auto info:  mBaseInfoList)
	{
		 if(info.stauts.contains("进行中", Qt::CaseSensitive))
		{
			 QString temp;
			 if (!info.deptName.isEmpty())
			 {
				 temp += info.deptName.mid(0, 8) + "\n";
			 }
			 /*显示昵称*/
			 if (!info.nickName.isEmpty())
			 {
				 temp += info.nickName.mid(0,8) + "\n";
			 }
			 temp += info.stauts;
			 
			item = new QTableWidgetItem(temp);
			item->setForeground(QBrush(QColor(0x00CA63)));/*绿色*/
			if (!info.nickName.isEmpty())
			{
				QFont font = item->font(); // 获取当前字体
				font.setFamily("Microsoft YaHei UI");
				font.setPixelSize(16); // 在现有字体基础上修改大小
				item->setFont(font); // 重新应用字体
			}
		}
		else
		{
			item = new QTableWidgetItem("未开始");
			item->setForeground(QBrush(QColor(0xF95353)));/*红色*/
		}
		ui->tableWidgetList->setItem(i, 0, new QTableWidgetItem(info.name));
		ui->tableWidgetList->setItem(i, 1, item);
		ui->tableWidgetList->setRowHeight(i, 100);
		i++;
	}

	for (int i = 0; i < ui->tableWidgetList->rowCount(); ++i)
	{
		if (ui->tableWidgetList->item(i, 1))
		{
			ui->tableWidgetList->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		}
	}
	/*显示总页数*/
	auto pageInfo = jsonData["data"].toObject()["list"].toObject()["pageInfo"].toObject();
	qDebug() << "WgtRegNo1::updateListTable";
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
void WgtRegNo1::clearBaseInfo()
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
void WgtRegNo1::showBaseInfo()
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
	for(QLineEdit * lineEdit:allLineEdits) 
	{
		if (lineEdit) 
		{ 
			lineEdit->setCursorPosition(0);
		}
	}
}
void WgtRegNo1::on_pushButtonSCode_clicked()
{
	if (ui->stackedWidget->currentWidget() == ui->pageSCode)
	{
		/*实现扫描解析功能*/
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

void WgtRegNo1::on_pushButtonMode_clicked()
{

	if (ui->stackedWidget->currentWidget() == ui->pageBatch|| ui->stackedWidget->currentWidget() == ui->pageList)
	{
		ui->stackedWidget->setCurrentWidget(ui->pageSCode);
		ui->pushButtonMode->setText("    列表模式  ");
		ui->pushButtonSCode->setText("扫一扫");
	}
	else if (ui->stackedWidget->currentWidget() == ui->pageSCode)
	{
		ui->stackedWidget->setCurrentWidget(ui->pageBatch);
		ui->pushButtonMode->setText("    扫描模式  ");
		ui->pushButtonSCode->setText("刷 新");
		updateBatchTable();
	}
}

void WgtRegNo1::on_toolButtonBatchUpPage_clicked()
{
	
	if (mBatchPageIndex > 1)
	{
		mBatchPageIndex--;
		updateBatchTable();
	}
}
void WgtRegNo1::on_toolButtonBatchNextPage_clicked()
{
	if (mBatchPageIndex < mBatchPageCount)
	{
		mBatchPageIndex++;
		updateBatchTable();
	}
}
void WgtRegNo1::on_toolButtonListUpPage_clicked()
{
	if (mListPageIndex > 1)
	{
		mListPageIndex--;
		updateListTable();
	}
}
void WgtRegNo1::on_toolButtonListNextPage_clicked()
{
	if (mListPageIndex < mListPageCount)
	{
		mListPageIndex++;
		updateListTable();
	}
}
void WgtRegNo1::tableWidgetListCellClicked(int row, int column)
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	if (row < mBaseInfoList.size())
	{
		mCurrentBaseInfo = mBaseInfoList[row];
		showBaseInfo();
	}
}
void WgtRegNo1::buttonListBackClicked(Artifact::BatchInfo batchInfo)
{
	ui->stackedWidget->setCurrentWidget(ui->pageBatch);
}

//点击查看的跳转
void WgtRegNo1::buttonClicked(Artifact::BatchInfo batchInfo)
{
	mListBatchView->updateShow(batchInfo, false);
	/*更新list*/
	mListPageIndex = 1;
	mCurrentBatchInfo = batchInfo;
	updateListTable();
	ui->stackedWidget->setCurrentWidget(ui->pageList);
	ui->tableWidgetList->clearSelection();
}
