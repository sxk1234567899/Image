#include "dlginput.h"

DlgInput::DlgInput(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DlgInputClass())
{
	ui->setupUi(this);
	setModal(true);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	ui->pushButtonYes->setDefault(false);
	ui->pushButtonYes->setAutoDefault(false);
	ui->pushButtonNo->setDefault(false);
	ui->pushButtonNo->setAutoDefault(false);
	
}

DlgInput::~DlgInput()
{
	QWidget* widget = qobject_cast<QWidget*>(this->parent());
	if (widget)
	{
		widget->activateWindow();
	}
	delete ui;
}

bool DlgInput::inputBox(QWidget* parent, QString title, QString& message, QString buttonOK, QString buttonNo, bool isPassword)
{
	bool isOk = false;
	DlgInput info(parent);
	info.ui->labelTitle->setText(title);
	info.ui->lineEdit->setPlaceholderText(message);
	if (isPassword)
	{
		info.ui->lineEdit->setEchoMode(QLineEdit::Password);
	}
	info.ui->pushButtonYes->setText(buttonOK);
	info.ui->pushButtonNo->setText(buttonNo);
	connect(info.ui->pushButtonYes, &QPushButton::clicked, [&]()
		{
			isOk = true;
            message = info.ui->lineEdit->text();
		});
	connect(info.ui->pushButtonNo, &QPushButton::clicked, [&]()
		{
			isOk = false;
            message = info.ui->lineEdit->text();
		});
	info.exec();
	return isOk;
}