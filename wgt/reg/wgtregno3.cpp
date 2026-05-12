#include "wgtregno3.h"
#include <QMouseEvent>
#include <QPainter>
#include "dlginfo.h"
#include "regthread.h"
#include "dlgimageview.h"
#include "opencv/nativemark.h"
#include "ringwait.h"
WgtRegNo3::WgtRegNo3(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegNo3Class())
{
	ui->setupUi(this);
	ui->labelImage->installEventFilter(this);
    ui->pushButtonMarked->setEnabled(false);
    ui->pushButtonReMarked->setEnabled(false);
    mIsDrawing = true;
    ui->widgetImage->setEnableSelected(true);
    connect(ui->widgetImage, &ImageWidget::imageSelected, this, &WgtRegNo3::imageSelected, Qt::UniqueConnection);
    connect(ui->widgetImageMarked, &ImageWidget::imageClicked, this, &WgtRegNo3::markedImageClicked, Qt::UniqueConnection);
    ui->labelInfo->setText(QString("选择要标记的图片后\n双击需要标记的点可以实现图片的标记工作"));
    mMarkedName = "";
    ui->pushButtonGoReg4->setEnabled(false);

    //sxk:隐藏修改格式
    ui->pushButtonReMarked->setVisible(false);
    ui->pushButtonSkipSampling->setVisible(false);


}

WgtRegNo3::~WgtRegNo3()
{
	delete ui;
}
bool WgtRegNo3::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui->labelImage)
    {
        switch (event->type()) 
        {
        case QEvent::MouseButtonDblClick:
        {
            if (!mIsDrawing)
            {
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                if (mouseEvent->button() == Qt::LeftButton)
                {
                    mIsDrawing = true;
                    mDrawMarkedPoint = mouseEvent->pos();
                    drawMarked();
                }
            }
            break;
        }
        case QEvent::MouseMove:
        case QEvent::MouseButtonPress:
        { 
            if(mIsDrawing)
            {
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                mDrawMarkedPoint = mouseEvent->pos();
                drawMarked();
            }
            break;
        }
        default:
            break;
        }
    }
    // 其他事件继续传递
    return QWidget::eventFilter(watched, event);
}
void WgtRegNo3::hideEvent(QHideEvent* event)
{
    ui->widgetImage->setImage(nullptr);
    ui->widgetImageMarked->setImage(nullptr);
}
void WgtRegNo3::updateShow()
{
    QScopedPointer<RingWait> rangWait(new RingWait(this));
    rangWait->show();
    auto data = RegThread::instance();
    QString number = data->getRegNumber();
    mMarkedList.clear();
    if (!number.isEmpty())
    {
        ui->widgetImage->setImage(data->getGlobalImage(number));
        ui->widgetImageMarked->setImage(data->getMarkedImage(number));
        ui->spinBoxGlobal->setValue(ui->widgetImage->getImageNum());
        ui->spinBoxMarked->setValue(ui->widgetImageMarked->getImageNum());
        for (auto& key : data->getMarkedImage(number)->keys())
        {
            mMarkedList.insert(key.mid(0,12));
        }
        ui->spinBoxGMarked->setValue(ui->spinBoxGlobal->value());
        ui->spinBoxAllMarked->setValue(data->getMarkedImage(number)->size());
        this->setEnabled(true);
        if (ui->spinBoxAllMarked->value() > 0)
        {
            ui->pushButtonGoReg4->setEnabled(true);
        }
    }
    else
    {
        ui->widgetImage->setImage(nullptr);
        ui->widgetImageMarked->setImage(nullptr);
        this->setEnabled(false);
    }
   
}
bool WgtRegNo3::updateRegData()
{
    bool ret = false;
   if(ui->spinBoxAllMarked->value()>0)
   {
       ui->widgetImage->setImage(nullptr);
       ui->widgetImageMarked->setImage(nullptr);
       ret = true;
   }
   else
   {
       DlgInfo::messageBox(this, tr("警告"), tr("进行拍摄指纹前至少需要标记一张全局照片，\n请您标记后再试。\n或者按\"跳过\""), tr("确定"), tr("删除"), false);

   }
    return ret;
}
void WgtRegNo3::drawMarked()
{
    if (!ui->labelImage)
    {
        return;
    }
    // 创建一个QPixmap作为缓冲区
    ui->labelImage->clear();
    ui->labelImage->setPixmap(mMarkedPixmap);
    QPixmap pixmap = ui->labelImage->grab();
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    // 绘制红色矩形
    painter.setPen(QPen(Qt::red, 4));
    painter.setBrush(Qt::transparent);
    /*画正方形*/
    painter.drawRect(mDrawMarkedPoint.x()-48, mDrawMarkedPoint.y() - 27, 96, 54);
    /*画十字*/
    painter.setPen(QPen(Qt::red, 2));
    painter.drawLine(mDrawMarkedPoint.x(), mDrawMarkedPoint.y() - 10, mDrawMarkedPoint.x(), mDrawMarkedPoint.y() + 10);
    painter.drawLine(mDrawMarkedPoint.x()-10, mDrawMarkedPoint.y(), mDrawMarkedPoint.x()+10, mDrawMarkedPoint.y() );
    painter.end();
    ui->labelImage->setPixmap(pixmap);
    ui->pushButtonMarked->setEnabled(true);
    ui->pushButtonReMarked->setEnabled(true);
}
void WgtRegNo3::on_pushButtonMarked_clicked()
{
    if  (mMarkedName.isEmpty())
    {
        DlgInfo::messageBox(this, "提示", "请选择照片并且做标记！", "确定", "否", false);
        return;
    }
    ui->pushButtonMarked->setEnabled(false);
    ui->pushButtonReMarked->setEnabled(false);
    QImage image = mMarkedImage.copy();
    int  pointX = mDrawMarkedPoint.x()* image.width()/mMarkedPixmap.size().width();
    int  pointY = mDrawMarkedPoint.y() * image.height() / mMarkedPixmap.size().height();
    int  markedWidth = image.width() / mMarkedPixmap.size().width() * 96;
    int  markedHeight = image.height() / mMarkedPixmap.size().height() * 54;
    qDebug()<<"mDrawMarkedPoint"<<mDrawMarkedPoint;
    qDebug()<<"point"<<pointX<< pointY;
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    // 绘制红色矩形
    painter.setPen(QPen(Qt::red, 10));
    painter.setBrush(Qt::transparent);
    /*画正方形*/
    painter.drawRect(pointX - (markedWidth / 2), pointY - (markedHeight/2), markedWidth, markedHeight);
    painter.end();
    auto data = RegThread::instance();
    QString number = data->getRegNumber();
    QString key=data->markedImageName(number, mMarkedName);
    data->addMarkedImage(number,key,image.copy());
    ui->widgetImageMarked->updateImage();
    ui->labelImage->clear();
    mMarkedList.insert(mMarkedName);
    ui->spinBoxMarked->setValue(ui->widgetImageMarked->getImageNum());
    ui->spinBoxGMarked->setValue(ui->spinBoxGlobal->value());
    ui->spinBoxAllMarked->setValue(data->getMarkedImage(number)->size());
    /*可以重复标记同一张图片*/
    ui->labelImage->setPixmap(mMarkedPixmap);
    mIsDrawing = false;
    ui->pushButtonGoReg4->setEnabled(true);
}
void WgtRegNo3::on_pushButtonReMarked_clicked()
{
    mIsDrawing = false;
    ui->labelImage->clear();
    ui->labelImage->setPixmap(mMarkedPixmap);
    ui->pushButtonMarked->setEnabled(false);
    ui->pushButtonReMarked->setEnabled(false);
}
void WgtRegNo3::on_pushButtonAutoMarked_clicked()
{
    if( mMarkedName.isEmpty())
    {
        DlgInfo::messageBox(this, "提示", "请选择照片后再做自动标记！", "确定", "否", false);
        return;
	}
	QImage image = mMarkedImage.copy();
	
    QList<QImage> outImage;
    NativeMark::markRegions(image, &outImage, 100);
	RegThread* data = RegThread::instance();
	QString number = data->getRegNumber();

    for(auto & img : outImage)
    {
		QString key = data->markedImageName(number, mMarkedName);
        data->addMarkedImage(number, key, img.copy());
	}
    mMarkedList.insert(mMarkedName);
    ui->widgetImageMarked->updateImage();
    ui->spinBoxMarked->setValue(ui->widgetImageMarked->getImageNum());
    ui->spinBoxGMarked->setValue(ui->spinBoxGlobal->value());
    ui->spinBoxAllMarked->setValue(data->getMarkedImage(number)->size());
    /*可以重复标记同一张图片*/
    ui->labelImage->clear();
    ui->labelImage->setPixmap(mMarkedPixmap);
    mIsDrawing = false;
    ui->pushButtonGoReg4->setEnabled(true);
}

void WgtRegNo3::imageSelected(QString name, QImage image)
{
    ui->labelImage->setMinimumSize(QSize(832, 468));
    ui->labelImage->setMaximumSize(QSize(832, 468));
    mMarkedName = name;
    mMarkedImage = image.copy();
    ui->labelImage->clear();
    image = image.scaled(ui->labelImage->size(), Qt::KeepAspectRatio);
    mMarkedPixmap = QPixmap::fromImage(image);
    ui->labelImage->setPixmap(mMarkedPixmap);
    ui->labelImage->setFixedSize(mMarkedPixmap.size());
    mIsDrawing =  false;
    ui->widgetImageMarked->setFilterName(name);
    ui->spinBoxMarked->setValue(ui->widgetImageMarked->getImageNum());


}

void WgtRegNo3::markedImageClicked(QString name, QImage image)
{
    DlgImageView* dlg = new DlgImageView(this);
    dlg->setImage(image, name);
    dlg->setDelete(true);
    dlg->exec();
    bool isDelete = dlg->isDelete();
    delete dlg;
    if (isDelete)
    {
        auto data = RegThread::instance();
        QString number = data->getRegNumber();
        if (data->deleteMarkedImage(number, name))
        {
            ui->widgetImageMarked->updateImage();
            ui->spinBoxMarked->setValue(ui->widgetImageMarked->getImageNum());
            if (ui->spinBoxMarked->value() == 0)
            {
                QString temp  = name.mid(0, 12);
                mMarkedList.remove(temp);
            }
            ui->spinBoxGMarked->setValue(ui->spinBoxGlobal->value());
            ui->spinBoxAllMarked->setValue(data->getMarkedImage(number)->size());

        }
        else
        {
            DlgInfo::messageBox(this, "提示", "删除图片失败！", "确定", "否", false);
        }
    }
    else
    {
        qDebug() << "WgtRegNo3::imageClicked: not delete";
    }
}