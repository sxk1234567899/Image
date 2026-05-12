#include "batchview.h"

BatchView::BatchView(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::BatchViewClass())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, [this]()
		{
			emit buttonClicked(mBatchInfo);
		});
}

BatchView::~BatchView()
{
	delete ui;
}
void BatchView::updateShow(const Artifact::BatchInfo& batchInfo, bool isList)
{
	mBatchInfo = batchInfo;
	ui->labelBatchName->setText(batchInfo.name);
	ui->labelCreateTime->setText(batchInfo.lastSampleTime);
	ui->spinBoxTotal->setValue(batchInfo.totalChecks);
	ui->spinBoxRemaining->setValue(batchInfo.totalChecks - batchInfo.uploadedCount);
	if(isList)
	{
		ui->pushButton->setText("查看");
	}
	else
	{
		ui->pushButton->setText("返回");
	}
}
