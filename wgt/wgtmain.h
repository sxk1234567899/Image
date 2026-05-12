#pragma once

#include <QtWidgets/QWidget>
#include <QtMultimedia>
#include "ui_wgtmain.h"

#include "wgtbegan.h"
#include "wgtlogo.h"
#include "wgthome.h"

#include "wgtreg.h"
#include "wgtverify.h"
#include "wgtprogress.h"
#include "wgtset.h"



QT_BEGIN_NAMESPACE
namespace Ui { class WgtMainClass; };
QT_END_NAMESPACE
class UpdateThread : public QThread
{
    Q_OBJECT
public:
    UpdateThread(QObject* parent = nullptr);
    ~UpdateThread();
protected:
    void run() override;
signals:
    void usagePercent(int value);
    void estimatedChargeRemaining(QString value);
};
class WgtMain : public QWidget
{
    Q_OBJECT
public:
    Ui::WgtMainClass* ui;
    WgtBegan* mWgtBegin;
    WgtLogo* mWgtLogo;
    WgtHome* mWgtHome;
    WgtReg* mWgtReg;
    WgtVerify* mWgtVerify;
    WgtProgress* mWgtProgress;
    WgtSet* mWgtSet;

    QObject* backObject;
public:
    WgtMain(QWidget *parent = nullptr);
    ~WgtMain();
protected:
private:
 
    QTimer *mTimer;
    QMediaPlayer* mPlayer;
    QAudioOutput* mAudioOutput;

    UpdateThread* updateThread = nullptr;
private slots:
    void timerTick();

    void setWgtMainName(QString name);

    void on_pushButtonLogIn_clicked();

    void on_pushButtonLogOut_clicked();
    void on_pushButtonHome_clicked();
    void on_pushButtonBack_clicked();

    void on_pushButtonReg_clicked();
    void on_pushButtonVerify_clicked();
    void on_pushButtonProgress_clicked();
    void on_pushButtonSet_clicked();

    void on_NetworkServer_error(QString message);

};

