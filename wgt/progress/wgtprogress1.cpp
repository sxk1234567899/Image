#include "wgtprogress1.h"

WgtProgress1::WgtProgress1(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtProgress1Class())
{
	ui->setupUi(this);
	/*初始化登记tableWidgetReg表格*/
	ui->tableWidgetReg->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetReg->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetReg->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui->tableWidgetReg->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	mRegScroller = QScroller::scroller(ui->tableWidgetReg);
	mRegScroller->grabGesture(ui->tableWidgetReg, QScroller::LeftMouseButtonGesture);
	ui->tableWidgetReg->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableWidgetReg->setSelectionMode(QAbstractItemView::NoSelection);
	ui->tableWidgetReg->verticalHeader()->hide();
	ui->tableWidgetReg->setColumnCount(7);
	ui->tableWidgetReg->setShowGrid(false);
	ui->tableWidgetReg->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->tableWidgetReg->horizontalHeader()->setFixedHeight(80);
	ui->tableWidgetReg->setHorizontalHeaderLabels(QStringList() << "名称" << "全局图" << "标记图" << "指纹图" <<"状态" << "操" << "作");
	auto headerItem = ui->tableWidgetReg->horizontalHeaderItem(5);
	headerItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
	headerItem = ui->tableWidgetReg->horizontalHeaderItem(6);
	headerItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	ui->tableWidgetReg->setColumnWidth(0, 360);
	ui->tableWidgetReg->setColumnWidth(1, 100);
	ui->tableWidgetReg->setColumnWidth(2, 100);
	ui->tableWidgetReg->setColumnWidth(3, 100);
	ui->tableWidgetReg->setColumnWidth(4, 100);
	ui->tableWidgetReg->setColumnWidth(5, 120);
	ui->tableWidgetReg->setColumnWidth(6, 120);
	/*初始化验证tableWidgetReg表格*/
	ui->tableWidgetVerify->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetVerify->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetVerify->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui->tableWidgetVerify->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	mVerifyScroller = QScroller::scroller(ui->tableWidgetVerify);
	mVerifyScroller->grabGesture(ui->tableWidgetVerify, QScroller::LeftMouseButtonGesture);
	ui->tableWidgetVerify->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableWidgetVerify->setSelectionMode(QAbstractItemView::NoSelection);
	ui->tableWidgetVerify->verticalHeader()->hide();
	ui->tableWidgetVerify->setColumnCount(7);
	ui->tableWidgetVerify->setShowGrid(false);
	ui->tableWidgetVerify->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->tableWidgetVerify->horizontalHeader()->setFixedHeight(80);
	ui->tableWidgetVerify->setHorizontalHeaderLabels(QStringList() << "名称" << "验证时间↑" << "全局图" << "指纹图" << "状态" << "操" << "作");
	headerItem = ui->tableWidgetVerify->horizontalHeaderItem(5);
	headerItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
	headerItem = ui->tableWidgetVerify->horizontalHeaderItem(6);
	headerItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	
	ui->tableWidgetVerify->setColumnWidth(0, 320);
	ui->tableWidgetVerify->setColumnWidth(1, 140);
	ui->tableWidgetVerify->setColumnWidth(2, 100);
	ui->tableWidgetVerify->setColumnWidth(3, 100);
	ui->tableWidgetVerify->setColumnWidth(4, 100);
	ui->tableWidgetVerify->setColumnWidth(5, 120);
	ui->tableWidgetVerify->setColumnWidth(6, 120);

	mSortOrder = Qt::DescendingOrder;
	ui->tableWidgetVerify->sortByColumn(1, mSortOrder);
	connect(ui->tableWidgetVerify->horizontalHeader(), &QHeaderView::sectionClicked,this, &WgtProgress1::on_VerifyHeader_Clicked);
}

WgtProgress1::~WgtProgress1()
{
	delete ui;
}
void WgtProgress1::addRegItem(const QString& name, const QString& globalImg, const QString& markImg, const QString& hgtImg, const QString& status)
{
	int row =ui->tableWidgetReg->rowCount();
	ui->tableWidgetReg->insertRow(row);
	ui->tableWidgetReg->setRowHeight(row, 80);
	ui->tableWidgetReg->setItem(row, 0, new QTableWidgetItem(name));
	ui->tableWidgetReg->setItem(row, 1, new QTableWidgetItem(globalImg));
	ui->tableWidgetReg->setItem(row, 2, new QTableWidgetItem(markImg));
	ui->tableWidgetReg->setItem(row, 3, new QTableWidgetItem(hgtImg));
	ui->tableWidgetReg->setItem(row, 4, new QTableWidgetItem(status));
	if (status == "已完成")
	{ 
		ui->tableWidgetReg->item(row, 4)->setForeground(QBrush(QColor(0x00CA63)));/*绿色*/
	}
	else
	{
		ui->tableWidgetReg->item(row, 4)->setForeground(QBrush(QColor(0xF95353)));/*红色*/
	}
	auto item4 = new QTableWidgetItem("整组删除\n重新登记");
	item4->setForeground(QBrush(QColor(0x1865FF)));
	ui->tableWidgetReg->setItem(row, 5, item4);
	auto item5 = new QTableWidgetItem("查看进程");
	item5->setForeground(QBrush(QColor(0x1865FF)));
	ui->tableWidgetReg->setItem(row, 6, item5);

	for (int i = 0; i <ui->tableWidgetReg->columnCount(); ++i)
	{
		if (ui->tableWidgetReg->item(row, i))
		{
			ui->tableWidgetReg->item(row, i)->setTextAlignment(Qt::AlignCenter);
		}
	}

}
void WgtProgress1::addVerifyItem(const QString& number,const QString& name, const QString& batch, const QString& time, const QString& globalImg, const QString& hgtImg, const QString& status,const QString& imgStatus)
{
	int row =ui->tableWidgetVerify->rowCount();
	ui->tableWidgetVerify->insertRow(row);
	ui->tableWidgetVerify->setRowHeight(row, 80);
	ui->tableWidgetVerify->setItem(row, 0, new QTableWidgetItem(name));
	ui->tableWidgetVerify->item(row, 0)->setData(Qt::UserRole, number);
	ui->tableWidgetVerify->setItem(row, 1, new QTableWidgetItem(time));
	ui->tableWidgetVerify->item(row, 1)->setData(Qt::UserRole, batch);
	ui->tableWidgetVerify->setItem(row, 2, new QTableWidgetItem(globalImg)); 
	ui->tableWidgetVerify->setItem(row, 3, new QTableWidgetItem(hgtImg));
    ui->tableWidgetVerify->setItem(row, 4, new QTableWidgetItem(imgStatus));
	if (imgStatus == "已完成")
	{
		ui->tableWidgetVerify->item(row, 4)->setForeground(QBrush(QColor(0x00CA63)));/*绿色*/
	}
	else
	{
		ui->tableWidgetVerify->item(row, 4)->setForeground(QBrush(QColor(0xF95353)));/*红色*/
	}
	auto item5 = new QTableWidgetItem();
	item5->setText("整组删除\n重新验证");
	item5->setForeground(QBrush(QColor(0x1865FF)));
	ui->tableWidgetVerify->setItem(row, 5, item5);
	auto item6 = new QTableWidgetItem(status);
	if (status == "比对进行中")
	{
		item6->setForeground(QBrush(QColor((QRgb)0x000000)));
	}
	else
	{
		item6->setForeground(QBrush(QColor((QRgb)0x1865FF)));
	}
	ui->tableWidgetVerify->setItem(row, 6, item6);

	for (int i = 0; i <ui->tableWidgetVerify->columnCount(); ++i)
	{
		if (ui->tableWidgetVerify->item(row, i))
		{
			ui->tableWidgetVerify->item(row, i)->setTextAlignment(Qt::AlignCenter);
		}
	}
    if (ui->comboBoxBatch->findText(batch) == -1)
    {
        ui->comboBoxBatch->addItem(batch);
    }
	ui->tableWidgetVerify->sortByColumn(1, mSortOrder);
}
void WgtProgress1::updateRegItem(int row, const QString& name, const QString& globalImg, const QString& markImg, const QString& hgtImg, const QString& status)
{
	if (row < 0 || row >=ui->tableWidgetReg->rowCount())
	{
		return;
	}
	ui->tableWidgetReg->item(row, 0)->setText(name);
	ui->tableWidgetReg->item(row, 1)->setText(globalImg);
	ui->tableWidgetReg->item(row, 2)->setText(markImg);
	ui->tableWidgetReg->item(row, 3)->setText(hgtImg);
	ui->tableWidgetReg->item(row, 4)->setText(status);
	if (status == "已完成")
	{
		ui->tableWidgetReg->item(row, 4)->setForeground(QBrush(QColor(0x00CA63)));/*绿色*/
	}
	else
	{
		ui->tableWidgetReg->item(row, 4)->setForeground(QBrush(QColor(0xF95353)));/*红色*/
	}
}
void WgtProgress1::updateVerifyItem(const QString& number, const QString& name, const QString& batch, const QString& time, const QString& globalImg, const QString& hgtImg, const QString& status, const QString& imgStatus)
{
	int row = -1;
    for (int i = 0; i <ui->tableWidgetVerify->rowCount(); ++i)
	{
		if (ui->tableWidgetVerify->item(i, 0)->data(Qt::UserRole) == number)
		{
			row = i;
			break;
		}
	}
	if (row < 0 || row >=ui->tableWidgetVerify->rowCount())
	{
		return;
	}
	ui->tableWidgetVerify->item(row, 0)->setText(name);
	//ui->tableWidgetVerify->item(row, 0)->setData(Qt::UserRole, number);
	ui->tableWidgetVerify->item(row, 1)->setText(time);
	ui->tableWidgetVerify->item(row, 1)->setData(Qt::UserRole, batch);
	ui->tableWidgetVerify->item(row, 2)->setText(globalImg);
	ui->tableWidgetVerify->item(row, 3)->setText(hgtImg);
	ui->tableWidgetVerify->item(row, 4)->setText(imgStatus);
	if (imgStatus == "已完成")
	{
		ui->tableWidgetVerify->item(row, 4)->setForeground(QBrush(QColor(0x00CA63)));/*绿色*/
	}
	else
	{
		ui->tableWidgetVerify->item(row, 4)->setForeground(QBrush(QColor(0xF95353)));/*红色*/
	}
	if (status == "比对进行中")
	{
		ui->tableWidgetVerify->item(row, 6)->setForeground(QBrush(QColor((QRgb)0x000000)));
	}
	else
	{
		ui->tableWidgetVerify->item(row, 6)->setForeground(QBrush(QColor((QRgb)0x1865FF)));
	}
	ui->tableWidgetVerify->item(row, 6)->setText(status);
	ui->tableWidgetVerify->sortByColumn(1, mSortOrder);
}

void WgtProgress1::on_VerifyHeader_Clicked(int logicalIndex)
{
    if (logicalIndex == 1)
    {
		if (mSortOrder == Qt::AscendingOrder)
        {
			mSortOrder = Qt::DescendingOrder;
			ui->tableWidgetVerify->sortByColumn(1, mSortOrder);
			ui->tableWidgetVerify->horizontalHeaderItem(1)->setText("验证时间↑");
        
        }
        else
        {
            mSortOrder = Qt::AscendingOrder;
            ui->tableWidgetVerify->sortByColumn(1, mSortOrder);
			ui->tableWidgetVerify->horizontalHeaderItem(1)->setText("验证时间↓");
        }
    }
}

void WgtProgress1::on_comboBoxBatch_currentTextChanged(const QString& text)
{
	if (text.isEmpty() || text == "全部")
	{
		for (int i = 0; i <ui->tableWidgetVerify->rowCount(); ++i)
		{
			ui->tableWidgetVerify->showRow(i);
		}
	}
	else
	{
        for (int i = 0; i <ui->tableWidgetVerify->rowCount(); ++i)
        {
            if (ui->tableWidgetVerify->item(i, 1)->data(Qt::UserRole) == text)
            {
                ui->tableWidgetVerify->showRow(i);
            }
            else
            {
                ui->tableWidgetVerify->hideRow(i);
            }
        }
	}
}