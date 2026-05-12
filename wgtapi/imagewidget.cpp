#include "imagewidget.h"
#include "artifact.h"
#include "appconfig.h"

ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
	, mImage(nullptr)
    , mIsLongPressZoom(true)
    , mIsEnableSelected(false)
	, mIsViewBtn(false)
	, mImageSize(187, 105)
	, mScrollArea(new  QScrollArea(this))
	, mImageWidget(new QWidget(this))
	, mImageButtonGroup(new QButtonGroup(this))
{
	this->setMaximumWidth(mImageSize.width() + 40);
	this->setMinimumWidth(mImageSize.width() +40);
	this->setObjectName("imageBrowsing");
    mScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	mScrollArea->setObjectName("imageBrowsingScrollArea");
	mImageWidget->setObjectName("imageBrowsingWidget");
	
	
	mWidgetVLayout = new QVBoxLayout(this);
	mWidgetVLayout->setObjectName("imageWidgetVLayout");
	this->setLayout(mWidgetVLayout);
	mWidgetVLayout->setContentsMargins(0, 0, 0, 0);
	mWidgetVLayout->setSpacing(0);
    mWidgetVLayout->addWidget(mScrollArea);
	mScrollArea->setMaximumWidth(mImageSize.width() +40);
	mScrollArea->setMaximumWidth(mImageSize.width() + 40);
    mScrollArea->setWidgetResizable(true);
	mScrollArea->setWidget(mImageWidget);
	mImageLayout = new QVBoxLayout(mImageWidget);
	mImageLayout->setObjectName("imageBrowsingLayout");
    mImageWidget->setLayout(mImageLayout);
    mImageLayout->setAlignment(Qt::AlignCenter);
	mImageLayout->setSpacing(10);
    mImageLayout->setContentsMargins(10,10,10,10);
	mVSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mImageLayout->addItem(mVSpacer);
	mScrollArea->setAttribute(Qt::WA_AcceptTouchEvents);
	/*设置触摸屏滚动和数据左键滑动*/
	mScroller = QScroller::scroller(mScrollArea);
	mScroller->grabGesture(mScrollArea, QScroller::LeftMouseButtonGesture);
	mScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏垂直滚动条
	mScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 隐藏水平滚动条
	connect(mImageButtonGroup, &QButtonGroup::buttonClicked, this, &ImageWidget::buttonClicked);
}

ImageWidget::~ImageWidget()
{}

void ImageWidget::setImage(const QMap<QString, QImage>* image)
{
	//qDebug() << QDateTime::currentDateTime() << "setImage";
	if (mImage != nullptr && mImage != image)
	{
		for  (auto it = mImageHash.begin(); it != mImageHash.end();)
		{
			mImageLayout->removeWidget(it.value());
            delete it.value();
            it = mImageHash.erase(it);
		}
		for (auto it = mImageView.begin(); it != mImageView.end();)
		{
            mImageLayout->removeWidget(it.key());
            delete it.key();
            it = mImageView.erase(it);
		}
	}

	mImage = image;
	updateImage();
	//qDebug() << QDateTime::currentDateTime() << "setImage end";
}
void ImageWidget::updateImage()
{

	if (mImage == nullptr)
	{
		return;
	}
   
	this->blockSignals(true);
	auto keys = mImage->keys();
    for (auto key : keys)
    {
		if (!mFilterName.isEmpty()&&!key.contains(mFilterName))
		{
			continue;
		}
		if (mImageHash.find(key) == mImageHash.end())
		{
			QToolButton* button = new QToolButton(this);
			button->setObjectName("imageBrowsingButton");
			button->setMaximumSize(mImageSize.width(), mImageSize.height() + 40);
			button->setMinimumSize(mImageSize.width(), mImageSize.height() + 40);
			if (mIsEnableSelected)
			{
				button->setCheckable(true);
				button->setChecked(false);
			}
            button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            button->setText(key);
			QImage image = mImage->value(key).copy();
			image = image.scaled(mImageSize, Qt::KeepAspectRatio);
			QPixmap pixmap = QPixmap::fromImage(image);
			button->setIcon(QIcon(pixmap));
			button->setIconSize(mImageSize);
			button->setText(Artifact::imageNameShow(key));
			/* 图像添加到列表*/
			mImageHash[key] = button;
			mImageButtonGroup->addButton(button);
			int index = mNameList.indexOf(key);
			if ((index < 0)|| (index >= mImageLayout->count()))
			{
				index = mImageLayout->count() - 1;
			}
			else if (mIsViewBtn)
			{
				index *= 2;
			}
			mImageLayout->insertWidget(index, button);

			if (mIsViewBtn)
			{
				QPushButton* viewBtn = new QPushButton(this);
				viewBtn->setObjectName("imageViewButton");
				viewBtn->setMinimumSize(QSize(mImageSize.width(), 50));
				viewBtn->setMaximumSize(QSize(mImageSize.width(), 50));
				viewBtn->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
				viewBtn->setIcon(QIcon(":/image/view.png"));
				viewBtn->setIconSize(QSize(25, 18));
				viewBtn->setText(tr("查看标记"));
				connect(viewBtn, &QPushButton::clicked, this, &ImageWidget::on_viewBtn_clicked);
				mImageView[viewBtn] = key;
				mImageLayout->insertWidget(index+1, viewBtn);
			}
		}
    }

	/*有被删除的照片*/
	for  (auto it = mImageHash.begin(); it != mImageHash.end();)
	{
		if ((mImage->find(it.key()) == mImage->end())
			|| (!mFilterName.isEmpty()&& !it.key().contains(mFilterName)))
		{
			mImageLayout->removeWidget(it.value());
			if (mIsViewBtn)
			{
				QPushButton* viewBtn = mImageView.key(it.key());
				mImageLayout->removeWidget(viewBtn);
				mImageView.remove(viewBtn);
				delete viewBtn;
			}
            delete it.value();
			it = mImageHash.erase(it);
		}
		else
		{
			it++;
		}
	}
	
	this->blockSignals(false);
	if (mIsEnableSelected && mImageHash.size() > 0)
	{
		mImageHash.begin().value()->click();
	}
} 
void ImageWidget::setImageSize(int width, int height)
{
	mImageSize = QSize(width, height);
}
void ImageWidget::setLongPressZoom(bool isLongPressZoom)
{
	mIsLongPressZoom = isLongPressZoom;
	if (mIsLongPressZoom)
	{

	}
}
void ImageWidget::setViewBtn(bool isViewBtn)
{
	mIsViewBtn = isViewBtn;

}
void ImageWidget::setEnableSelected(bool isEnableImage)
{
	mIsEnableSelected = isEnableImage;
	if  (mIsEnableSelected)
	{
		connect(mImageButtonGroup, &QButtonGroup::buttonToggled, this, &ImageWidget::buttonToggled,Qt::UniqueConnection);
	}
	else
	{
		disconnect(mImageButtonGroup, &QButtonGroup::buttonClicked, this, &ImageWidget::buttonClicked);
	}
}
void ImageWidget::setExclusive(bool exclusive)
{
	mImageButtonGroup->setExclusive(exclusive);
	if (exclusive)
	{
		mIsEnableSelected = true;
		
	}
}
int ImageWidget::getImageNum()
{
	return mImageHash.size();
}
void ImageWidget::setFilterName(QString name)
{
	mFilterName = name;
	updateImage();
}
void ImageWidget::setNamelist(QStringList list)
{
    mNameList = list;
	//updateImage();
}
void ImageWidget::selectFirstImage()
{
	if (mIsEnableSelected && mImageHash.size() > 0)
	{
		mImageHash.begin().value()->setChecked(false);
		mImageHash.begin().value()->toggle();
	}
	
}
void ImageWidget::buttonToggled(QAbstractButton* button, bool checked)
{
	QToolButton* toolButton = qobject_cast<QToolButton*>(button);
	QString key = Artifact::imageName(toolButton->text());
	if (mImage->contains(key)&&checked)
	{
		toolButton->setStyleSheet("border: 3px solid blue;");
		emit imageSelected(key, mImage->value(key).copy());
	}
	else
	{
		toolButton->setStyleSheet("");
		//qDebug() << "ImageWidget::buttonToggled" << key << "not found";
	}
}
void ImageWidget::buttonClicked(QAbstractButton* button)
{
	QToolButton* toolButton = qobject_cast<QToolButton*>(button);
	QString key = Artifact::imageName(toolButton->text());
	if (mImage->contains(key))
	{
		emit imageClicked(key, mImage->value(key).copy());
	}
	else
	{
		qDebug() << "ImageWidget::buttonToggled" << key << "not found";
	}
}
void ImageWidget::on_viewBtn_clicked()
{
	QPushButton* button = qobject_cast<QPushButton*>(sender());
	if(mImageView.find(button) != mImageView.end())
	{
		QString key = mImageView.value(button);
		if (mImage->find(key) != mImage->end())
		{
			emit imageView(key, mImage->value(key).copy());
		}
		else
		{
			qDebug() << "ImageWidget:on_selectedBtn_clicked:key error "<<key;
		}
	}
	else
	{
        qDebug() << "ImageWidget:on_selectedBtn_clicked:button error "<<button;
	}
	
}