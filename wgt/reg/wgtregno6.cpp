#include "wgtregno6.h"
#include "regthread.h"
#include "networkserver.h"
#include "zxingqtwriter.hpp"
#include "bluetoothpairer.h"
#include "ringwait.h"
#include "labelprint.h"
#include <QPainter>
#include "dlginfo.h"
WgtRegNo6::WgtRegNo6(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegNo6Class())
{
	ui->setupUi(this);
	mPrintFile = QCoreApplication::applicationDirPath()+ "/printImage.png";
	mPrintImage = nullptr;
	QString number = "AB123456789";
	ui->labelName->setText("可移动文物数字登记验证系统");
	ui->labelNumber->setText(number);
	ui->labelRegTime->setText("2025-01-01 00:00:00");
	QImage image = ZXingQt::WriteBarcode(number, ZXing::BarcodeFormat::QRCode);
	image = image.scaled(ui->labelImage->size(), Qt::KeepAspectRatio);
	ui->labelImage->setPixmap(QPixmap::fromImage(image));
}

WgtRegNo6::~WgtRegNo6()
{
	delete ui;
}
void WgtRegNo6::updateShow()
{
	ui->pushButtonPrint->setEnabled(true);
	qDebug() << "WgtRegNo6::updateShow";
	auto regData = RegThread::instance();
	QString number = regData->getRegNumber();
	if (number.isEmpty())
	{
		qDebug() << "No registration data available.";
		return;
	}

	BaseInfo info = regData->getBaseInfo();
	ui->labelName->setText(info.name.mid(0,20));
	ui->labelNumber->setText(number);
	if (info.createTime.isEmpty())
	{
		ui->labelRegTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	}
	else
	{
		ui->labelRegTime->setText(info.createTime);
	}
	ui->labelAgency->setText(NetworkServer::instance()->userInfo().unitName);
	ui->labelGlobalNum->setText(QString::number(regData->getGlobalImage(number)->size()));
    ui->labelHighNum->setText(QString::number(regData->getHighImage(number)->size()));
	QImage image = ZXingQt::WriteBarcode(number, ZXing::BarcodeFormat::QRCode);
	image = image.scaled(ui->labelImage->size(), Qt::KeepAspectRatio);
    ui->labelImage->setPixmap(QPixmap::fromImage(image));
	qDebug() << "number:" << number;
}
bool WgtRegNo6::updateRegData()
{
	return true;
}
void WgtRegNo6::on_pushButtonBtConnect_clicked()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	ui->pushButtonBtConnect->setEnabled(false);
	QSharedPointer<BluetoothPairer> btPairer(new BluetoothPairer);
	QBluetoothDeviceInfo printAddress;
	bool isPair = false;
	QEventLoop loop;
	connect(btPairer.data(), &BluetoothPairer::deviceDiscovered, [&](const QBluetoothDeviceInfo& info) {
		if (info.name().startsWith("PRINTER"))
		{
			isPair = true;
			printAddress = info;
			btPairer->stopDeviceDiscovery();
			loop.quit();
		}
		});
	btPairer->startDeviceDiscovery();
	connect(btPairer.data(), &BluetoothPairer::discoveryFinished, [&]() {
		loop.quit();
		});
	loop.exec();
	if (!isPair)
	{
		DlgInfo::messageBox(this, tr("提示"), tr("没有扫描到标签打印机蓝牙!,请打开电源后重试"), tr("确定"), tr("取消"), false);
		ui->pushButtonBtConnect->setEnabled(true);
		return;
	}
	QString pin = "0000";
	if (btPairer->pairWithDevice(printAddress, pin))
	{
		LabelPrint::instance()->initCom();
		DlgInfo::messageBox(this, tr("提示"), QString("蓝牙(%1)连接成功,请打印标签").arg(printAddress.name()), tr("确定"), tr("取消"), false);
	}
	else
	{
		DlgInfo::messageBox(this, tr("提示"), tr("蓝牙连接失败"), tr("确定"), tr("取消"), false);
	}
	ui->pushButtonBtConnect->setEnabled(true);
}

void WgtRegNo6::on_pushButtonPrint_clicked()
{
	ui->pushButtonPrint->setEnabled(false);
	if (mPrintImage == nullptr)
	{
		delete mPrintImage;
	}
    mPrintImage = new QImage(400, 600, QImage::Format_Mono);
	QPainter painter(mPrintImage);
	this->ui->widgetCertificate->render(&painter, QPoint(0, 0), QRegion(6,6,400,600));
	QFile::remove(mPrintFile);
	mPrintImage->save(mPrintFile);
	if (!LabelPrint::instance()->printLabel(mPrintFile))
	{
		DlgInfo::messageBox(this, tr("警告"), "打印标签失败,请连接打印机后重新打印", tr("确定"), tr("删除"), false);
	}
	ui->pushButtonPrint->setEnabled(true);
}