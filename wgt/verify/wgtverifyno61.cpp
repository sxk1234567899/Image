#include "wgtverifyno61.h"
#include "dlgimageview.h"
WgtVerifyNo61::WgtVerifyNo61(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo61Class())
{
	ui->setupUi(this);
}

WgtVerifyNo61::~WgtVerifyNo61()
{
	delete ui;
}

void WgtVerifyNo61::setImage(const QImage& image, const QString& imageName)
{
	mImage = image.copy();
	mImageName = imageName;
	ui->labelImage->setPixmap(QPixmap::fromImage(mImage.scaled(ui->labelImage->size(), Qt::KeepAspectRatio)));

	//ui->lableImageName->setText(mImageName);
}

void WgtVerifyNo61::on_toolButtonZoomIn_clicked()
{
	DlgImageView* dlg = new DlgImageView(this);
	dlg->setImage(mImage, mImageName);
	dlg->setDelete(false);
	dlg->exec();
	delete dlg;
}