#include <QThread>
#include <QScreen>
#include "wgtmain.h"
#include "wgtbegan.h"
#include "networkserver.h"
#include "dlginfo.h"
#include "ringwait.h"
#include "systemset.h"
#include "usbcamera.h"
#include "netcamera.h"


UpdateThread:: UpdateThread(QObject *parent)
    : QThread(parent)
{
    start();
}
UpdateThread:: ~UpdateThread()
{
    requestInterruption();
    setTerminationEnabled(true);
    // 强制终止线程
    terminate();
    quit();
    wait();
}
void UpdateThread::run()
{
    while (!isInterruptionRequested())
    {
        // 获取所有存储设备信息
        QList<QStorageInfo> storages = QStorageInfo::mountedVolumes();
        qint64 totalSpace = 0;
        qint64 usedSpace = 0;
        foreach(const QStorageInfo & storage, storages)
        {
            if (storage.isValid() && storage.isReady())
            {
                if (!storage.isReadOnly())
                {
                    // 设置容量信息
                    qint64 totalSize = storage.bytesTotal();
                    qint64 freeSize = storage.bytesFree();
                    qint64 usedSize = totalSize - freeSize;
                    totalSpace += totalSize;
                    usedSpace += usedSize;
                }
            }
        }    
        emit usagePercent((double)usedSpace / totalSpace * 100);
        emit estimatedChargeRemaining(QString(" %1%  ").arg(SystemSet::instance()->getEstimatedChargeRemaining()));
        QThread::sleep(60);
    }
}




WgtMain::WgtMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WgtMainClass())
    , mWgtBegin(new WgtBegan(this))
    , mWgtLogo(new WgtLogo(this))
    , mWgtHome(new WgtHome(this))
    , mWgtReg(new WgtReg(this))
    , mWgtVerify(new WgtVerify(this))
    , mWgtProgress(new WgtProgress(this))
    , mWgtSet(new WgtSet(this))
    , mTimer(new QTimer(this))
    , backObject(nullptr)
{
    mPlayer = new QMediaPlayer;
    mAudioOutput = new QAudioOutput;
    mPlayer->setAudioOutput(mAudioOutput); // 必须显式设置音频输出
    mPlayer->setSource(QUrl("qrc:/sound/welcome.mp3"));//设置音频文件

    ui->setupUi(this);
    ui->stackedWidget->addWidget(mWgtLogo);
    ui->stackedWidget->addWidget(mWgtHome);

    ui->stackedWidget->addWidget(mWgtReg);
    ui->stackedWidget->addWidget(mWgtVerify);
    ui->stackedWidget->addWidget(mWgtProgress);
    ui->stackedWidget->addWidget(mWgtSet);
    connect(mWgtHome->ui->pushButtonSet, &QPushButton::clicked,this,&WgtMain::on_pushButtonSet_clicked,Qt::UniqueConnection);
    connect(mWgtLogo->ui->pushButtonSet, &QPushButton::clicked, this, &WgtMain::on_pushButtonSet_clicked, Qt::UniqueConnection);
    connect(mWgtSet->ui->spinBoxSysVolume, &QSpinBox::valueChanged,mWgtHome->ui->progressBarSound, &QProgressBar::setValue);
    connect(mWgtSet->ui->spinBoxBrightness, &QSpinBox::valueChanged,mWgtHome->ui->progressBarBrightness, &QProgressBar::setValue);
    mWgtHome->ui->progressBarSound->setValue(mWgtSet->ui->spinBoxSysVolume->value());
    mWgtHome->ui->progressBarBrightness->setValue(mWgtSet->ui->spinBoxBrightness->value());
    connect(mWgtSet, &WgtSet::wifiConnectStatus, [this](bool status, QString name) {
        if (status)
        {
            mWgtHome->ui->labelWifi->setText("已连："+ name);
            mWgtHome->ui->labelWifi->setStyleSheet("color:#000");
        }
        else
        {
            mWgtHome->ui->labelWifi->setText("未连：");
            mWgtHome->ui->labelWifi->setStyleSheet("color:#DE2600");
        }
        });
    connect(mWgtSet, &WgtSet::net4GConnectStatus, [this](bool status, QString name) {
        if (status)
        {
            mWgtHome->ui->label4g->setText("已连："+ name);
            mWgtHome->ui->label4g->setStyleSheet("color:#000");
        }
        else
        {
            mWgtHome->ui->label4g->setText("未连：");
            mWgtHome->ui->label4g->setStyleSheet("color:#DE2600");
        }
        });
    mWgtSet->updateUIShow();
    ui->widgetTopHome->setVisible(false);
    ui->labelLogInfo->setText("");
    ui->widgetTopQuit->setVisible(false);
    this->setWindowTitle("可移动文物数字登记验证系统");
    ui->labelName->setText("可移动文物数字登记验证系统—登录");
    ui->stackedWidget->setCurrentWidget(mWgtLogo);
    ui->widgetTop->setVisible(true);
    setWindowFlags(Qt::FramelessWindowHint);
   // setWindowFlags(windowFlags() | Qt::Dialog);
    //setWindowModality(Qt::ApplicationModal); //阻塞除当前窗体之外的所有的窗体
    this->setMinimumSize(1280, 800);
    this->setMaximumSize(1280, 800);
    mWgtBegin->setMinimumSize(1280, 800);
    mWgtBegin->setMaximumSize(1280, 800);


    mWgtBegin->setWindowFlags(Qt::FramelessWindowHint);
    mWgtBegin->setWindowFlags(mWgtBegin->windowFlags() | Qt::Dialog);
    mWgtBegin->setWindowModality(Qt::ApplicationModal); //阻塞除当前窗体之外的所有的窗体
    mWgtBegin->show();

    ui->dateEdit->setDate(QDate::currentDate());
    ui->timeEdit->setTime(QTime::currentTime());

    connect(mTimer, &QTimer::timeout, this, &WgtMain::timerTick);
    mTimer->start(500);

    QTimer::singleShot(3000, [this] {
        this->show();
        mWgtBegin->close();
        });
	qDebug() << this->size();   

    updateThread = new UpdateThread(this);
    connect(updateThread, &UpdateThread::usagePercent, mWgtHome->ui->progressBarMemory, &QProgressBar::setValue);
    connect(updateThread, &UpdateThread::estimatedChargeRemaining, ui->labelBatt, &QLabel::setText);

    connect(NetworkServer::instance(), &NetworkServer::networkServerError, this, &WgtMain::on_NetworkServer_error);

}

WgtMain::~WgtMain()
{
    delete ui;
}

void WgtMain::timerTick()
{
    ui->dateEdit->setDate(QDate::currentDate());
    ui->timeEdit->setTime(QTime::currentTime());
   
  
}
void WgtMain::setWgtMainName(QString name)
{
    ui->labelName->setText(name);
}
void WgtMain::on_pushButtonLogIn_clicked()
{
    qDebug() << "点击登录";
    QScopedPointer<RingWait> rangWait(new RingWait(this));
    rangWait->show();
    QString userName = mWgtLogo->ui->lineEditUserName->text();
    QString password = mWgtLogo->ui->lineEditPassword->text();
    qDebug() <<"账户"<< userName;
    qDebug() <<"密码"<< password;
    /*TODO:登录验证*/
    QString message;
    if (NetworkServer::instance()->login(userName, password,&message))
    {
        RegThread::instance();
        VerifyThread::instance();
        mWgtProgress->initProgress();
        auto userInfo = NetworkServer::instance()->userInfo();
        ui->labelLogInfo->setText(userInfo.unitName.mid(0,16- userInfo.nickname.size()) + " " + userInfo.nickname);

        auto conf = AppConfig::instance()->netWorkServerConf();
        conf.username = userName;
        conf.password = password;
        AppConfig::instance()->setNetworkServerConf(conf);
        on_pushButtonHome_clicked();

        mPlayer->play();
    }
    else
    {
        /*登录失败提示*/
        DlgInfo::messageBox(this, "登录失败", message, "确定", "", false);
        
    }
}

void WgtMain::on_pushButtonLogOut_clicked()
{
    USBCamera::instance()->stop();
    NetCamera::instance()->stop();
    qDebug() << "点击注销";
    ui->widgetTopQuit->setVisible(false);
    ui->widgetTopHome->setVisible(false);
    ui->labelName->setText("可移动文物数字登记验证系统—登录");
    ui->labelLogInfo->setText("");
    ui->stackedWidget->setCurrentWidget(mWgtLogo);
    ui->widgetTop->setStyleSheet(QString::fromUtf8(
        "#widgetTop{\n"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #0049DA, stop:1 #5D93FF);\n"
        "}"
    ));
    RegThread::destroy();
    VerifyThread::destroy();
}
void WgtMain::on_pushButtonHome_clicked()
{
    if ((ui->stackedWidget->currentWidget() == mWgtReg )
        && (mWgtReg->ui->stackedWidget->currentWidget() != mWgtReg->mWgtRegNo1)
        && (mWgtReg->ui->stackedWidget->currentWidget() != mWgtReg->mWgtRegNo6)
        && (!RegThread::instance()->getRegNumber().isEmpty()))
    {
        DlgInfo::DlgInfoResult result = DlgInfo::messageBox(this, tr("返回主页"), tr("当前有未完成的登记流程\n您希望是否保留至进度?"), tr("保留"), tr("删除"));
        if (DlgInfo::DlgInfoResult::No == result)
        {
            RegThread::instance()->deleteRegData();
        }
        else if (DlgInfo::DlgInfoResult::OK == result)
        {
            RegThread::instance()->updateRegData();
        }
        else
        {
            return;
        }
    }
    else if((ui->stackedWidget->currentWidget() == mWgtVerify) 
        && (mWgtVerify->ui->stackedWidget->currentWidget() != mWgtVerify->mWgtVerifyNo1)
        && (mWgtVerify->ui->stackedWidget->currentWidget() != mWgtVerify->mWgtVerifyNo2)
        && (!VerifyThread::instance()->getVerifyNumber().isEmpty())
        && (VerifyThread::instance()->getVerifyData()->isVerifyFinished <= VerifyData::Verify_Runing))
    {
        DlgInfo::DlgInfoResult result = DlgInfo::messageBox(this, tr("返回主页"), tr("当前有未完成的验证流程\n您希望是否保留至进度?"), tr("保留"), tr("删除"));
        if (DlgInfo::DlgInfoResult::No == result)
        {
            VerifyThread::instance()->deleteVerifyData();
        }
        else if (DlgInfo::DlgInfoResult::OK == result)
        {
            VerifyThread::instance()->updateVerifyData();
        }
        else
        {
            return;
        }
    }
    else if ((ui->stackedWidget->currentWidget() == mWgtVerify)
        && (mWgtVerify->ui->stackedWidget->currentWidget() == mWgtVerify->mWgtVerifyNo2))
    {
        VerifyThread::instance()->deleteVerifyData();
    }
    ui->widgetTopQuit->setVisible(true);
    ui->widgetTopHome->setVisible(false);
    ui->stackedWidget->setCurrentWidget(mWgtHome);
    ui->labelName->setText("可移动文物数字登记验证系统—首页");
    ui->widgetTop->setStyleSheet(QString::fromUtf8(
        "#widgetTop{\n"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #0049DA, stop:1 #5D93FF);\n"
        "}"
    ));
    USBCamera::instance()->stop();
    NetCamera::instance()->stop();
}
void WgtMain::on_pushButtonBack_clicked()
{
    qDebug() << "点击返回";
    if  (ui->stackedWidget->currentWidget() == mWgtReg)
    {
        mWgtReg->back();
    }
    else if (ui->stackedWidget->currentWidget() == mWgtVerify)
    {
        if (backObject == mWgtProgress)
        {
            backObject = nullptr;
            on_pushButtonProgress_clicked();
        }
        else
        {
            mWgtVerify->back();
        }
    }
    else if (ui->stackedWidget->currentWidget() == mWgtProgress)
    {
        mWgtProgress->back();
    }
    else if (ui->stackedWidget->currentWidget() == mWgtSet)
    {
        mWgtSet->back();
        ui->pushButtonHome->setVisible(true);
        ui->label->setVisible(true);
        if (backObject == mWgtLogo)
        {
            backObject = nullptr;
            on_pushButtonLogOut_clicked();
        }
        else
        {
            on_pushButtonHome_clicked();
        }
    }
}

void WgtMain::on_pushButtonReg_clicked()
{
    qDebug() << "点击注册";
    ui->widgetTopHome->setVisible(true);
    ui->widgetTopQuit->setVisible(true);
    if (ui->stackedWidget->currentWidget() == mWgtProgress)
    {
        mWgtReg->continueReg(RegThread::instance()->getRegNo());
    }
    else
    {
       //mWgtReg->ui->stackedWidget->setCurrentWidget(mWgtReg->mWgtRegNo6);
        RegThread::instance()->startNewRegData();
        mWgtReg->newReg();
    }
    ui->stackedWidget->setCurrentWidget(mWgtReg);
    ui->widgetTop->setStyleSheet(QString::fromUtf8(
        "#widgetTop{\n"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #0049DA, stop:1 #5D93FF);\n"
        "}"
    ));
}
void WgtMain::on_pushButtonVerify_clicked()
{
    qDebug() << "点击验证";
    ui->widgetTopHome->setVisible(true);
    ui->widgetTopQuit->setVisible(true);
    if (ui->stackedWidget->currentWidget() == mWgtProgress)
    {
        if (VerifyThread::instance()->getVerifyData()->isVerifyFinished == VerifyData::Verify_Finished)
        {
            backObject = mWgtProgress;
            mWgtVerify->showVerifyResult(VerifyThread::instance()->getVerifyNumber());
        }
        else
        {
            mWgtVerify->continueVerify(VerifyThread::instance()->getVerifyNo());
        }
    }
    else
    {
        VerifyThread::instance()->startNewVerifyData();
        mWgtVerify->newVerify();
    }
    ui->stackedWidget->setCurrentWidget(mWgtVerify);
    ui->widgetTop->setStyleSheet(QString::fromUtf8(
        "#widgetTop{\n"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #008E37, stop:1 #4EBB78);\n"
        "}"
    ));
}
void WgtMain::on_pushButtonProgress_clicked()
{
   qDebug() << "点击进度";
   ui->widgetTopHome->setVisible(true);
   ui->widgetTopQuit->setVisible(true);
   ui->stackedWidget->setCurrentWidget(mWgtProgress);
   ui->labelName->setText("进度管理");
   ui->widgetTop->setStyleSheet(QString::fromUtf8(
       "#widgetTop{\n"
       "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #0049DA, stop:1 #5D93FF);\n"
       "}"
   ));
}
void WgtMain::on_pushButtonSet_clicked()
{
    auto widget = sender();
    if (widget == mWgtLogo->ui->pushButtonSet)
    {
        backObject = mWgtLogo;
        ui->pushButtonHome->setVisible(false);
        ui->label->setVisible(false);
        ui->widgetTopHome->setVisible(true);
        ui->widgetTopQuit->setVisible(false);
    }
    else
    {
        ui->pushButtonHome->setVisible(true);
        ui->label->setVisible(true);
        ui->widgetTopHome->setVisible(true);
        ui->widgetTopQuit->setVisible(true);
    }
    qDebug() << "点击设置";
    ui->labelName->setText("可移动文物数字登记验证系统—设置");
    ui->stackedWidget->setCurrentWidget(mWgtSet);
    ui->widgetTop->setStyleSheet(QString::fromUtf8(
        "#widgetTop{\n"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #0049DA, stop:1 #5D93FF);\n"
        "}"
    ));
}

void WgtMain::on_NetworkServer_error(QString message)
{
    DlgInfo::messageBox(this, "警告", message, "确认","",false);
    return;
}