#include "dlginfo.h"

DlgInfo::DlgInfo(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DlgInfoClass())
{
	ui->setupUi(this);
	
	setModal(true);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	ui->pushButtonYes->setDefault(false);
	ui->pushButtonYes->setAutoDefault(false);
	ui->pushButtonNo->setDefault(false);
	ui->pushButtonNo->setAutoDefault(false);
}

DlgInfo::~DlgInfo()
{
	QWidget* widget = qobject_cast<QWidget*>(this->parent());
	if (widget)
	{
		widget->activateWindow();
	}
	delete ui;
}
DlgInfo::DlgInfoResult DlgInfo::messageBox(QWidget* parent, QString title, QString message, QString buttonOK, QString buttonNo, bool isButtonNotShow)
{
	DlgInfoResult isOk = DlgInfoResult::Cancel;
	 DlgInfo info(parent);
     info.ui->labelTitle->setText(title);
     info.ui->labelContent->setText(message);
	 info.ui->pushButtonYes->setText(buttonOK);
	 info.ui->pushButtonNo->setText(buttonNo);
     info.ui->pushButtonNo->setVisible(isButtonNotShow);
	 info.ui->labelContent->setWordWrap(true);  // 启用自动换行
	 connect(info.ui->pushButtonYes, &QPushButton::clicked, [&]()
		 {
			 isOk = DlgInfoResult::OK;
		 });
     connect(info.ui->pushButtonNo, &QPushButton::clicked, [&]()
		 {
			 isOk = DlgInfoResult::No;
		 });
	 info.exec();
     return isOk;
}