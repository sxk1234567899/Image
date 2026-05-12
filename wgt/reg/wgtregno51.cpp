#include "wgtregno51.h"
#include "dlgimageview.h"
WgtRegNo51::WgtRegNo51(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtRegNo51Class())
{
	ui->setupUi(this);
}

WgtRegNo51::~WgtRegNo51()
{
	delete ui;
}
void WgtRegNo51::setImage(const QImage& image, const QString& imageName)
{
	mImage = image.copy();
	mImageName = imageName;
	ui->labelImage->setPixmap(QPixmap::fromImage(mImage.scaled(ui->labelImage->size(), Qt::KeepAspectRatio)));
	ui->checkBoxSetMain->setChecked(false);
	ui->lableImageName->setText(mImageName);
}
void WgtRegNo51::on_toolButtonZoomIn_clicked()
{
	DlgImageView* dlg = new DlgImageView(this);
	dlg->setImage(mImage, mImageName);
	dlg->setDelete(false);	
	dlg->exec();
	delete dlg;
}
