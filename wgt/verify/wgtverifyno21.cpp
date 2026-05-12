#include "wgtverifyno21.h"
#include "dlgimageview.h"
WgtVerifyNo21::WgtVerifyNo21(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WgtVerifyNo21Class())
{
	ui->setupUi(this);
}

WgtVerifyNo21::~WgtVerifyNo21()
{
	delete ui;
}
void WgtVerifyNo21::setImage(QImage image, QString name)
{
	mImage = image;
	mImageName = name;
	QPixmap pixmap = QPixmap::fromImage(image.scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
	ui->labelImage->setAlignment(Qt::AlignCenter);
	ui->labelImage->setPixmap(pixmap);
    ui->labelName->setText(name);
}
void WgtVerifyNo21::setLeftLineVisible(bool visible)
{
    ui->labelLeftLine->setVisible(visible);
}
void WgtVerifyNo21::setRightLineVisible(bool visible)
{
    ui->labelRightLine->setVisible(visible);
}

void WgtVerifyNo21::on_toolButtonZoomIn_clicked()
{
	DlgImageView* dlg = new DlgImageView(this);
	dlg->setImage(mImage, mImageName);
	dlg->setDelete(false);
	dlg->exec();
	delete dlg;
}