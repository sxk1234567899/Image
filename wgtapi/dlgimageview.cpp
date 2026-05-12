#include "dlgimageview.h"
#include <QPainter>
#include <QScreen>
#include "dlginfo.h"
DlgImageView::DlgImageView(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DlgImageViewClass())
{
	ui->setupUi(this);
	setModal(true);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	ui->pushButtonSwitch->hide();
	ui->scrollArea->setAttribute(Qt::WA_AcceptTouchEvents);
	/*设置触摸屏滚动和数据左键滑动*/
	mScroller = QScroller::scroller(ui->scrollArea);
	mScroller->grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);
	ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏垂直滚动条
	ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏水平滚动条
}

DlgImageView::~DlgImageView()
{
	QWidget* widget = qobject_cast<QWidget*>(this->parent());
	if (widget)
	{
		widget->activateWindow();
	}
	delete ui;
}
void DlgImageView::paintEvent(QPaintEvent* event)
{
	ui->labelImage->clear();
	QSize size = ui->labelImage->size();
	QPixmap pixmap;
    if (mIsPaint==1)
    {
		pixmap = QPixmap::fromImage( mImage.copy().scaled(size, Qt::KeepAspectRatio));
	}
	else if (mIsPaint==2)
	{
		pixmap = QPixmap::fromImage(mImage2.copy().scaled(size, Qt::KeepAspectRatio));
	}
	ui->labelImage->setPixmap(pixmap);
	ui->labelImage->setAlignment(Qt::AlignCenter);
    QWidget::paintEvent(event);
}

void DlgImageView::setImage(const QImage& image, const QString& imageName)
{
	/*绘制图片为背景图*/
	mImage = image.copy();
	mImageName = imageName;
	mIsPaint = 1;
	ui->pushButtonSwitch->hide();
	update();
}
void DlgImageView::setImage(const QImage& image1, const QString& imageName1, const QImage& image2, const QString& imageName2)
{
	mImage = image1.copy();
	mImageName = imageName1;
	mImage2 = image2.copy();
	mImageName2 = imageName2;
	mIsPaint = 1;
	ui->pushButtonSwitch->setText(imageName1);
	ui->pushButtonSwitch->show();
	update();
	
}
void DlgImageView::setDelete(bool isDelete)
{
	if(isDelete)
	{
		ui->pushButtonDelete->show();
	}
	else
	{
		ui->pushButtonDelete->hide();
	}
}
bool DlgImageView::isDelete()
{
	return mIsDelete;
}

void DlgImageView::on_pushButtonDelete_clicked()
{
	
	if (DlgInfo::DlgInfoResult::OK == DlgInfo::messageBox(this, "删除图片", "确定要删除该图片吗?", "确定", "取消"))
	{
		mIsDelete = true;
		this->close();
	}
	else
	{
		mIsDelete = false;
	}
}
void DlgImageView::on_pushButtonSwitch_clicked()
{
	if(mIsPaint == 1)
	{
		mIsPaint = 2;
		ui->pushButtonSwitch->setText(mImageName2);
	}
	else if(mIsPaint == 2)
	{
		mIsPaint = 1;
		ui->pushButtonSwitch->setText(mImageName);
	}	
	update();
}
void DlgImageView::on_pushButtonQuit_clicked()
{
	mIsDelete = false;
	this->close();
}
void DlgImageView::on_pushButtonZoomIn_clicked()
{
	QSize size = ui->scrollAreaWidgetContents->size();
	size = size * 1.1;
	ui->scrollAreaWidgetContents->setMinimumSize(size);
	ui->scrollAreaWidgetContents->setMaximumSize(size);
	update();
}
void DlgImageView::on_pushButtonZoomOut_clicked()
{
	QSize size = ui->scrollAreaWidgetContents->size();
	size = size*0.9;
	ui->scrollAreaWidgetContents->setMinimumSize(size);
	ui->scrollAreaWidgetContents->setMaximumSize(size);
	size = ui->scrollAreaWidgetContents->size();
	if (size.width() <= this->width() || size.height() <= this->height())
	{
		ui->scrollAreaWidgetContents->setMinimumSize(this->size());
		ui->scrollAreaWidgetContents->setMaximumSize(this->size());
	}
	update();
}