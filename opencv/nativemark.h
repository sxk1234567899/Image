#pragma once
#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>
class NativeMark  : public QObject
{
	Q_OBJECT

public:
	NativeMark(QObject *parent);
	~NativeMark();
	static cv::Mat QImageToMat(const QImage& image);
	static QImage MatToQImage(const cv::Mat& mat);
	static void markRegions(const QImage& image, QList<QImage>* outImage, int windowSize);
private:
	static float calculateEntropy(cv::Mat& image);
    static QList<QPoint> findMaxEntropyRegions(cv::Mat& grayImg, int windowSize);
    
};

