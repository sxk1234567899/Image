#include <QtConcurrent>
#include "wgtset.h"
#include "systemset.h"
#include "wifimanager.h"
#include "bluetoothpairer.h"
#include "usbcamera.h"
#include "netcamera.h"
#include "dlginfo.h"
#include "dlginput.h"
#include "ringwait.h"
#include "wgtmain.h"
#include "labelprint.h"
#include "wgtsetnetcamera.h"

WgtSet::WgtSet(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtSetClass())
	, mButtonSetGroup(new QButtonGroup(this))
	, mButtonSetNet(new QButtonGroup(this))
	, mShowTimer(new QTimer(this))
	, mNetworkSpeedTester(nullptr)
{
	ui->setupUi(this);
	mWgtMain = qobject_cast<WgtMain*>(this->parent());
	ui->pushButtonTestWifi->setVisible(false);
	ui->pushButtonTest4G->setVisible(false);
	ui->doubleSpinBoxWifiSpeed->setVisible(false);
	ui->doubleSpinBox4GSpeed->setVisible(false);
	ui->pushButtonNet->setCheckable(true);
	ui->pushButtonDevice->setCheckable(true);
	ui->pushButtonOther->setCheckable(true);
	ui->pushButtonLog->setCheckable(true);

	ui->sliderBrightness->setTracking(false); // 关闭滑动跟踪
	ui->sliderSysVolume->setTracking(false); // 关闭滑动跟踪
	mButtonSetGroup->addButton(ui->pushButtonNet, 0);
	mButtonSetGroup->addButton(ui->pushButtonDevice, 1);
	mButtonSetGroup->addButton(ui->pushButtonOther, 2);
	mButtonSetGroup->addButton(ui->pushButtonLog, 3);
	
	connect(mButtonSetGroup, &QButtonGroup::idClicked, this, &WgtSet::buttonSetGroupClicked);
	ui->stackedWidget->setCurrentIndex(0); // 默认显示第一个页面
	ui->pushButtonNet->setChecked(true); // 默认选中网络设置按钮

	ui->pushButtonWifi->setCheckable(true);
	ui->pushButton4G->setCheckable(true);
	ui->pushButtonTestWifi->setCheckable(true);
	mButtonSetNet->addButton(ui->pushButtonWifi, 0);
	mButtonSetNet->addButton(ui->pushButton4G, 1);
	ui->tableWidgetWifi->setAttribute(Qt::WA_AcceptTouchEvents);
	ui->tableWidgetWifi->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetWifi->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->tableWidgetWifi->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui->tableWidgetWifi->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	mScroller = QScroller::scroller(ui->tableWidgetWifi);
	mScroller->grabGesture(ui->tableWidgetWifi, QScroller::LeftMouseButtonGesture);
	ui->tableWidgetWifi->horizontalHeader()->hide();
	ui->tableWidgetWifi->verticalHeader()->hide();
	ui->tableWidgetWifi->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui->tableWidgetWifi->setSelectionMode(QAbstractItemView::NoSelection);
	//ui->tableWidgetWifi->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableWidgetWifi->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableWidgetWifi->setShowGrid(false);
	ui->tableWidgetWifi->setIconSize(QSize(42, 34));
	ui->tableWidgetWifi->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->tableWidgetWifi->setColumnCount(3);
	ui->tableWidgetWifi->setColumnWidth(0, 100);
	ui->tableWidgetWifi->setColumnWidth(1, 400);
	ui->tableWidgetWifi->setColumnWidth(2, 100);
	ui->tableWidgetWifi->setRowCount(0);
	mVersionInfo = AppConfig::instance()->versionInfo();
	QString deviceInfo;
    deviceInfo.append("设备名称\tE-M-TECH\n");
	deviceInfo.append("处 理 器\t"+ SystemSet::instance()->getCpuName()+"\n");
    deviceInfo.append("机带RAM\t16.0GB\n");
    deviceInfo.append("存储\t\t1.0TB\n");
	deviceInfo.append("设备ID\t\t"+ SystemSet::instance()->getUUID()+"\n");
    deviceInfo.append("软件版本\t"+ mVersionInfo.version + "\n");
	deviceInfo.append("编译时间\t"+ mVersionInfo.buildTime +"\n");
    deviceInfo.append("单位\t\t易元数字(北京)科技集团有限公司");

	ui->textBrowserDeviceInfo->setText(deviceInfo);
	ui->textBrowserDeviceInfo->setText(deviceInfo);
	ui->textBrowserChangelog ->setText(mVersionInfo.version + "\n"+ mVersionInfo.updateLog);


	//QString name4G = SystemSet::instance()->get4GNetName();
    //ui->label4GName->setText(name4G);
	//ui->label4GNameItem->setText(name4G);

	connect(ui->tableWidgetWifi, &QTableWidget::cellClicked, this, &WgtSet::tableWidgetWifiCellClicked);

	connect(mButtonSetNet, &QButtonGroup::idClicked, this, &WgtSet::buttonSetNetClicked);
	ui->pushButtonWifi->setChecked(true); // 默认选中WiFi按钮
	ui->stackedWidgetSetNet->setCurrentIndex(0); // 默认显示WiFi设置页面

	connect(ui->spinBoxSysVolume, &QSpinBox::valueChanged, ui->sliderSysVolume, &QSlider::setValue);
	connect(ui->sliderSysVolume, &QSlider::valueChanged, ui->spinBoxSysVolume, &QSpinBox::setValue);

	connect(ui->spinBoxBrightness, &QSpinBox::valueChanged, ui->sliderBrightness, &QSlider::setValue);
	connect(ui->sliderBrightness, &QSlider::valueChanged, ui->spinBoxBrightness, &QSpinBox::setValue);

	connect(mShowTimer,&QTimer::timeout,this,&WgtSet::updateUIShow);

	std::map<std::string, int> wlanMap;
	ui->checkBoxWifi->setChecked(true);
	WiFiManager::instance()->openWLAN(wlanMap);
	updateUIShow();

	
	

	float volume = SystemSet::instance()->getVolume();
	if (volume >= 0.0f)
	{
		ui->sliderSysVolume->setValue(static_cast<int>(volume * 100));
	}
	else
	{
		ui->sliderSysVolume->setValue(50);
		ui->spinBoxSysVolume->setValue(50);
		qDebug() << "System volume error";
	}
	int brightness = SystemSet::instance()->getScreenBrightness();
	if (brightness >= 0)
	{
		ui->sliderBrightness->setValue(brightness);
	}
	else
	{
		ui->sliderBrightness->setValue(50);
		qDebug() << "brightness error";
	}
}

WgtSet::~WgtSet()
{
	delete mNetworkSpeedTester;
	mNetworkSpeedTester = nullptr;
	delete ui;
}
void WgtSet::showEvent(QShowEvent* event)
{
	
	//mShowTimer->start(1000);
	updateUIShow();
	QWidget::showEvent(event);
}
void WgtSet::hideEvent(QHideEvent* event)
{
	QWidget::hideEvent(event);
	mShowTimer->stop();
	if (mNetworkSpeedTester)
	{
		delete mNetworkSpeedTester;
		mNetworkSpeedTester = nullptr;
		ui->pushButtonTestWifi->setChecked(false);
		ui->pushButtonTestWifi->setText("测速");
	}
}
void WgtSet::back()
{
	mShowTimer->stop();
	USBCamera::instance()->stop();
	NetCamera::instance()->stop();
}
void WgtSet::buttonSetGroupClicked(int id)
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	ui->stackedWidget->setCurrentIndex(id);
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents);
	if (id != 0)
	{
		if (mNetworkSpeedTester)
		{
			delete mNetworkSpeedTester;
			mNetworkSpeedTester = nullptr;
			ui->pushButtonTestWifi->setChecked(false);
			ui->pushButtonTestWifi->setText("测速");
		}
	}
	if (id == 1)
	{
		
	}
	else
	{
		NetCamera::instance()->stop();
		USBCamera::instance()->stop();
	}
	if (id == 2)
	{
		QScopedPointer<RingWait> rangWait(new RingWait(this));
		rangWait->show();
		float volume = SystemSet::instance()->getVolume();
		if (volume >= 0.0f)
		{
			ui->sliderSysVolume->setValue(static_cast<int>(volume * 100));
		}
		else
		{
			ui->sliderSysVolume->setValue(50);
			ui->spinBoxSysVolume->setValue(50);
			qDebug() << "System volume error";
		}
		int brightness = SystemSet::instance()->getScreenBrightness();
		if (brightness >= 0)
		{
			ui->sliderBrightness->setValue(brightness);
		}
		else
		{
			ui->sliderBrightness->setValue(50);
			qDebug() << "brightness error";
		}
	}
	
	
}

void WgtSet::buttonSetNetClicked(int id)
{
	ui->stackedWidgetSetNet->setCurrentIndex(id);
	updateUIShow();
	
}
void WgtSet::on_checkBoxWifi_toggled(bool checked)
{
	if (checked)
    {
        WiFiManager::instance()->openWLAN(wlanMap);
		updateUIShow();
    }
    else
    {
        WiFiManager::instance()->closeWLAN();
        updateUIShow();
    }
}
void WgtSet::on_pushButtonUpdateWifi_clicked()
{
	updateUIShow();
}
void WgtSet::on_pushButtonTestWifi_clicked(bool checked)
{
	if (checked)
	{
		ui->pushButtonTestWifi->setText("停止");
		mNetworkSpeedTester = new NetworkSpeedTester();
		mNetworkSpeedTester->setInterface("WLAN");  // 指定网卡名称
		connect(mNetworkSpeedTester, &NetworkSpeedTester::speedUpdated, ui->doubleSpinBoxWifiSpeed, &QDoubleSpinBox::setValue);
	}
	else
	{
		ui->pushButtonTestWifi->setText("测速");
		if (mNetworkSpeedTester)
		{
			delete mNetworkSpeedTester;
			mNetworkSpeedTester = nullptr;
		}
	}
}

void WgtSet::on_checkBox4g_toggled(bool checked)
{
	/*屏蔽信号*/
	ui->checkBox4g->blockSignals(true);
	if (!SystemSet::ctr4GNet(checked))
	{
		ui->checkBox4g->setChecked(false);
	}
	if (ui->checkBox4g->isChecked())
	{
		QScopedPointer<RingWait> rangWait(new RingWait(this));
		rangWait->show();
		QEventLoop loop;
		QTimer::singleShot(5000, &loop, &QEventLoop::quit); // 超时设置
		loop.exec();
	}
	updateUIShow();
   ui->checkBox4g->blockSignals(false);
}

void WgtSet::on_pushButtonUpdate4G_clicked()
{
	updateUIShow();
}

void WgtSet::on_pushButtonCheckUpdates_clicked()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	QNetworkRequest request(AppConfig::instance()->netWorkServerConf().updateUrl);
	// 发送POST请求
	QNetworkAccessManager networkManager;
	QNetworkReply* reply = networkManager.get(request, nullptr);
	// 使用事件循环等待请求完成
	QEventLoop loop;
	QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	QTimer::singleShot(10000, &loop, &QEventLoop::quit); // 超时设置
	loop.exec();
	// 检查网络错误
	if (reply->error() != QNetworkReply::NoError)
	{
		reply->deleteLater();
		DlgInfo::messageBox(this, QString("提示"), "已经是最新程序不需要更新", "确定", "取消", false);
        return;
	}
	QByteArray replyData = reply->readAll();
	qDebug()<< "检查更新结果:"<<replyData;
	QJsonParseError error;
	QJsonObject updateJson = QJsonDocument::fromJson(replyData, &error).object();
	if (error.error != QJsonParseError::NoError)
	{	
		qDebug() << "读取版本错误错误：" << error.errorString();
	}
	qDebug() << "updateJson: ";
	qDebug().noquote() << QString::fromUtf8(QJsonDocument(updateJson).toJson(QJsonDocument::Indented));
    if (updateJson.contains("version")&& updateJson["version"].toString()> mVersionInfo.version && updateJson.contains("download_url"))
	{ 
		QDir dir(QCoreApplication::applicationDirPath());
		dir.cdUp();
		if (!dir.exists("update")) {
			bool created = dir.mkpath("update"); // 创建目录（包括必要的父目录）
			if (created) {
				qDebug() << "bin目录创建成功";
			}
			else {
				qDebug() << "bin目录创建失败";
			}
		}
		dir.cd("update");
		QString updateFile = dir.absolutePath();
		QFile file(updateFile + "/update.json");
		qDebug() << "updateFile:" << updateFile;
		if (file.open(QFile::WriteOnly | QFile::Truncate))
		{
			QJsonDocument doc(updateJson);
			file.write(doc.toJson());
			file.close();
			if (DlgInfo::DlgInfoResult::OK == DlgInfo::messageBox(this, QString("提示"), "有新版本程序,是否需要更新", "更新", "取消"))
			{
				QProcess::startDetached(updateFile + "/update.exe");
				qApp->quit();
			}
		}
		else
		{
			DlgInfo::messageBox(this, QString("提示"), "已经是最新程序不需要更新", "确定", "取消", false);
			return;
		}
        
	}
	else
	{
		DlgInfo::messageBox(this, QString("提示"), "已经是最新程序不需要更新", "确定", "取消", false);
		return;
	}

}
void WgtSet::tableWidgetWifiCellClicked(int row, int column)
{
    std::string connectedWifi;
	int signalQuality;
	WiFiManager::instance()->queryInterface(connectedWifi, signalQuality);
	std::string wlanName = ui->tableWidgetWifi->item(row, 1)->text().toStdString();
	if (connectedWifi != wlanName)
	{
		
		QString password = "密码";
		if (DlgInput::inputBox(this, QString("请输入\"%1\"密码").arg(QString::fromStdString(wlanName)), password, "确定", "取消", true))
		{
			WiFiManager::instance()->passwordToConnectWLAN(wlanName, password.toStdString());
		}
		else
		{
			return;
		}
		QScopedPointer<RingWait> rangWait(new RingWait(this));
		rangWait->show();
		for(int i =0;i<10;i++)
		{
			WiFiManager::instance()->queryInterface(connectedWifi, signalQuality);
			if (connectedWifi == wlanName)
			{
				break;
			}
            QThread::msleep(500);
			QCoreApplication::processEvents();
		}
        rangWait->close();
		WiFiManager::instance()->queryInterface(connectedWifi, signalQuality);
		if (connectedWifi != wlanName)
		{
			DlgInfo::messageBox(this, "提示", "连接失败！", "确定", "", false);
		}
		updateUIShow();
	}
}
void WgtSet::updateUIShow()
{
	if (ui->checkBoxWifi->isChecked())
	{
		std::string connectedWifi;
		int signalQuality;
		WiFiManager::instance()->refreshWLAN(wlanMap);
		WiFiManager::instance()->queryInterface(connectedWifi, signalQuality);
		int typeCount[6]={0,0,0,0,0};
		if (!connectedWifi.empty())
		{
            ui->labelWifiName->setText(QString::fromStdString(connectedWifi));
			emit wifiConnectStatus(true, QString::fromStdString(connectedWifi));
		}
		else
		{
			ui->labelWifiName->setText("");
			emit wifiConnectStatus(false, "");
		}
		if (wlanMap.size() > 0)
		{
			ui->tableWidgetWifi->setRowCount(0);
			for (auto it = wlanMap.begin(); it != wlanMap.end(); ++it)
			{
				int row;
				if (it->first == connectedWifi)
				{
					row = 0; 
					typeCount[0] = 1;
					ui->tableWidgetWifi->insertRow(row);
					auto connectedItem = new QTableWidgetItem();
					connectedItem->setIcon(QIcon(":/image/ok1.png"));
					ui->tableWidgetWifi->setItem(row, 0, connectedItem);
				}
				else if (it->second > 0 && it->second <= 5)
				{
					typeCount[6-it->second]++;
					row = 0;
					for (int i = 0; i < 6-it->second; i++)
					{
						row += typeCount[i];
					}
					ui->tableWidgetWifi->insertRow(row);
				}
				else
				{
					row = ui->tableWidgetWifi->rowCount();
                    ui->tableWidgetWifi->insertRow(row);
				}
				ui->tableWidgetWifi->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(it->first)));
				auto wifiQualityItem = new QTableWidgetItem();
				wifiQualityItem->setIcon(QIcon(QString(":/image/wifiq%1.png").arg(it->second)));
				ui->tableWidgetWifi->setItem(row, 2, wifiQualityItem);
				ui->tableWidgetWifi->setRowHeight(row, 60);
			}
		}
	}
	else
	{
		ui->tableWidgetWifi->setRowCount(0);
	}

	QString name;
	quint32 quality;
    SystemSet::get4GNetName(name, quality);
	ui->checkBox4g->blockSignals(true);
	if (!name.isEmpty())
	{
		ui->label4GName->setText(name);
		ui->label4GNameItem->setText(name+"蜂窝数据");
		QPixmap pixmap(QString(":/image/wifiq%1.png").arg(quality));
		pixmap = pixmap.scaled(ui->label4GQuality->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
		ui->label4GQuality->setPixmap(pixmap);
		ui->label4GStatus->setVisible(true);
		ui->widget4gitem->setVisible(true);
		ui->checkBox4g->setChecked(true);
		emit net4GConnectStatus(true, name);
	}
	else
	{
		ui->checkBox4g->setChecked(false);
		ui->label4GName->setText("");
        ui->label4GNameItem->setText("");
        ui->label4GQuality->setPixmap(QPixmap(""));
		ui->widget4gitem->setVisible(false);
		emit net4GConnectStatus(false, "");
	}
	ui->checkBox4g->blockSignals(false);
    
}
void WgtSet::on_sliderSysVolume_valueChanged(int value)
{
	float volume = static_cast<float>(value) / 100.0f;
	if(!SystemSet::instance()->setVolume(volume))
	{
		qWarning() << "Failed to set system volume.";
		return;
	}
	qDebug() << "Volume:" << value;

}
void WgtSet::on_sliderBrightness_valueChanged(int value)
{
	SystemSet::instance()->setScreenBrightness(value);
	qDebug() << "Brightness:" << value;
}

void WgtSet::on_pushButtonNetConn_clicked()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents);
	while (true)
	{
		if (!NetCamera::instance()->start(ui->videoWidgetNet))
		{
			if (DlgInfo::DlgInfoResult::Cancel == DlgInfo::messageBox(this, "提示", "请检查显微镜连接是否正常后重试！", "重试", "否", false))
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}
void WgtSet::on_pushButtonNetCamSet_clicked()
{
	QString password = "密码";
	if (DlgInput::inputBox(this, QString("请输入管理员密码"), password, "确定", "取消", true)&& password=="135468")
	{
		QScopedPointer<WgtSetNetCamera> setNetCamera(new WgtSetNetCamera());
        setNetCamera->exec();
	}
	
}
void WgtSet::on_pushButtonUSBConn_clicked()
{
	QScopedPointer<RingWait> rangWait(new RingWait(this));
	rangWait->show();
	update();
	QCoreApplication::processEvents(QEventLoop::AllEvents);
	while (true)
	{
		if (!USBCamera::instance()->start(ui->videoWidgetUSB))
		{
			if (DlgInfo::DlgInfoResult::Cancel == DlgInfo::messageBox(this, "提示", "请检查USB摄像头是否正常连接后重试！", "重试", "", false))
			{

				break;
			}
		}
		else
		{
			break;
		}
	}

}

void WgtSet::on_pushButtonBtConnect_clicked()
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
void WgtSet::on_pushButtonTestPrint_clicked()
{
	ui->pushButtonTestPrint->setEnabled(false);
	QString mPrintFile = QString(":/image/testprint.png");
	if (!LabelPrint::instance()->printLabel(mPrintFile))
	{
		DlgInfo::messageBox(this, tr("警告"), "打印标签失败,请连接打印机后重新打印", tr("确定"), tr("删除"), false);
	}
	
    ui->pushButtonTestPrint->setEnabled(true);

}