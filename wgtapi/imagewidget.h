#pragma once
#include <QtCore>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QToolButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QScroller>
class ImageWidget  : public QWidget
{
	Q_OBJECT

public:
	ImageWidget(QWidget *parent);
	~ImageWidget();
	void setImage(const QMap<QString, QImage> *image);
    void updateImage();
	void setImageSize(int width, int height);
	void setLongPressZoom(bool isLongPressZoom);
	void setViewBtn(bool isViewBtn);
	void setEnableSelected(bool isEnableImage);
	void setExclusive(bool exclusive);
	int getImageNum();
	void setFilterName(QString name);
	void setNamelist(QStringList list);
	void selectFirstImage();
signals:
	void imageSelected(QString name,QImage image);
	void imageView(QString name,QImage image);
	void imageClicked(QString name, QImage image);
private:
	const QMap<QString, QImage> *mImage;
	QMap<QString, QToolButton*> mImageHash;
	QMap<QPushButton* ,QString> mImageView;
    QScrollArea* mScrollArea;
    QWidget* mImageWidget;
	QVBoxLayout* mWidgetVLayout;
	QVBoxLayout* mImageLayout;
	QButtonGroup* mImageButtonGroup;
	QSpacerItem* mVSpacer;       //垂直弹簧
	QScroller* mScroller;
    bool mIsLongPressZoom;
	bool mIsViewBtn;
	bool mIsEnableSelected;
	QSize mImageSize;
private :
	QString mFilterName = QString();
	QStringList mNameList = QStringList();
private slots:
	void buttonToggled(QAbstractButton* button, bool checked);
	void buttonClicked(QAbstractButton* button);
	void on_viewBtn_clicked();

};

