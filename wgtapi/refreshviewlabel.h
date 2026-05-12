#pragma once

#include <QLabel>
#include <QTimer>
class RefreshViewLabel  : public QLabel
{
	Q_OBJECT

public:
	RefreshViewLabel(QWidget *parent);
	~RefreshViewLabel();
	void setStepSize(int stepSize) { mStepSize = stepSize; }
	void setWidth(int width) { mWidth = width; }
	void setImage(QImage image);
	void startAnimation();
	void stopAnimation();
protected:
	void paintEvent(QPaintEvent* event) override;

private:
	QTimer* mTimer;	
	int mStepSize;
	int mWidth;
	int mStartX;
	QImage mImage;
	bool mIsAnimating = false;
private slots:
	void refreshView();
};

