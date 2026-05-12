#include "nativemark.h"
#include <QMap>
#include <QList>
#include <QPoint>
#include <QPainter>
#include <QDebug>
#include <QRandomGenerator>

NativeMark::NativeMark(QObject *parent)
	: QObject(parent)
{}

NativeMark::~NativeMark()
{}

cv::Mat NativeMark::QImageToMat(const QImage& image)
{
    switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        return cv::Mat(image.height(), image.width(), CV_8UC4,
            const_cast<uchar*>(image.bits()),
            image.bytesPerLine()).clone();

    case QImage::Format_RGB888:
        return cv::Mat(image.height(), image.width(), CV_8UC3,
            const_cast<uchar*>(image.bits()),
            image.bytesPerLine()).clone();

    case QImage::Format_Indexed8:
        return cv::Mat(image.height(), image.width(), CV_8UC1,
            const_cast<uchar*>(image.bits()),
            image.bytesPerLine()).clone();

    default:
        return QImageToMat(image.convertToFormat(QImage::Format_RGB888));
    }
}

// cv::Mat 转 QImage
QImage NativeMark::MatToQImage(const cv::Mat& mat)
{
    switch (mat.type())
    {
    case CV_8UC1:
        return QImage(mat.data, mat.cols, mat.rows, mat.step,
            QImage::Format_Grayscale8);

    case CV_8UC3:
        return QImage(mat.data, mat.cols, mat.rows, mat.step,
            QImage::Format_RGB888).rgbSwapped();

    case CV_8UC4:
        return QImage(mat.data, mat.cols, mat.rows, mat.step,
            QImage::Format_ARGB32)/*.rgbSwapped()*/;

    default:
        qDebug() << "不支持的Mat类型: " << mat.type();
        return QImage();
    }
}

void NativeMark::markRegions(const QImage& image, QList<QImage>* outImage, int windowSize)
{
	cv::Mat inImage = QImageToMat(image);
    cv::Mat gray;
    cv::cvtColor(inImage, gray, cv::COLOR_BGR2GRAY);
    auto positions = findMaxEntropyRegions(gray, windowSize); 
	outImage->clear();
    for (int i = 0; i < positions.size(); i++)
    {
		QImage tempImg = image.copy();  // 每次创建原始图像的副本
        QPainter painter(&tempImg);
        painter.setRenderHint(QPainter::Antialiasing);
        // 绘制红色矩形
        painter.setPen(QPen(Qt::red, 10));
        painter.setBrush(Qt::transparent);
        /*画正方形*/
        painter.drawRect(positions[i].x()-192, positions[i].y()-108, 384, 216);
        painter.end();
        // 生成带序号的新文件名
        outImage->append(tempImg.copy());
    }
}

float NativeMark::calculateEntropy(cv::Mat& image)
{
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    cv::Mat hist;
    cv::calcHist(&image, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange);

    hist /= image.total();
    float entropy = 0;
    for (int i = 0; i < hist.rows; i++)
    {
        float prob = hist.at<float>(i);
        if (prob > 0)
        {
            entropy -= prob * log2(prob);
        }
    }
    return entropy;
}

QList<QPoint> NativeMark::findMaxEntropyRegions(cv::Mat& grayImg, int windowSize)
{
    QMap<qreal,QPoint> entropies;

    for (int y = 0; y < grayImg.rows; y += windowSize)
    {
        for (int x = 0; x < grayImg.cols; x += windowSize)
        {
            cv::Rect roi(x, y, windowSize, windowSize);
            if ((roi.x + roi.width > grayImg.cols)
                || (roi.y + roi.height > grayImg.rows))
            {
                continue;
            }

            cv::Mat window = grayImg(roi);
            float entropy = calculateEntropy(window);
            if (entropy > 0.2)
            {
                entropies[entropy] = QPoint(x, y);
            }
        }
    }
    QList<QPoint>  results;
	 //// 从最大开始
  //  QMap<qreal,QPoint>::iterator it = entropies.end();
  //  it--;
  //  while (it != entropies.begin())
  //  {
  //      results.push_back(it.value());
		//it--;
  //      if (results.size() >= 1)
  //      {
  //          break;
  //      }
  //  }
   
    /*随机取一个*/
    if (!entropies.isEmpty()) {
        int index = QRandomGenerator::global()->bounded(entropies.size());
        results.append(entropies.values().at(index));
    }
    return results;
}

