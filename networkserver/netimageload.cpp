#include "netimageload.h"
#include <QTimer>
#include <QtConcurrent>

NetImageLoad::NetImageLoad(QObject *parent)
	: QObject(parent)
    , mThread(new QThread(this))
{
    moveToThread(mThread);
    mThread->start();
    QTimer::singleShot(0, this, [this]()
    {
        mNetworkManager = new QNetworkAccessManager(this);
        connect(mNetworkManager, &QNetworkAccessManager::finished, this, &NetImageLoad::onNetworkReplyFinished);

    });
}

NetImageLoad::~NetImageLoad()
{}
void NetImageLoad::loadImage(const QString& url)
{
    mCurrentUrl = url;
    QMetaObject::invokeMethod(this, [this]()
    {
        // 发送网络请求
        QNetworkRequest request(mCurrentUrl);
        request.setTransferTimeout(10000); // 设置超时时间为 10 秒
        mNetworkManager->get(request);
    });
    
}
QImage NetImageLoad::loadImageBlocking(const QString& url)
{
    QNetworkRequest request(url);
    // 发送POST请求
    QNetworkAccessManager networkManager;
    networkManager.setTransferTimeout(2*60*1000); // 2min超时

    request.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);
    QNetworkReply* reply = networkManager.get(request, nullptr);
    
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(2 * 60 * 1000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QImage image;
    // 检查网络错误
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "loadImageBlocking"<<reply->errorString();
        reply->deleteLater();
        return image;
    }
    // 使用 QImageReader 处理响应数据
    QImageReader reader(reply);
    // 预读取图像信息
    if (!reader.canRead())
    {
        reply->deleteLater();
        return image;
    }
    // 读取并显示图像
    image = reader.read();
    return image;
}
QImage NetImageLoad::loadImageInfoBlocking(Artifact::ImageInfo* info)
{
    QImage image;
    if (info->status == Artifact::saved)
    {
        image.load(info->imageLocalAddr);
    }
    else
    {

    
        image = loadImageBlocking(info->imageNetAddr);
        if (image.isNull())
        {
            info->status = Artifact::saveFailed;
            qDebug() << info->imageName << "saveFailed";
        }
        else
        {
            info->status = Artifact::saved;
            image.save(info->imageLocalAddr);
        }
    }
    return image;
}
QList<QImage> NetImageLoad::loadImageListBlocking(QList<Artifact::ImageInfo*> infoList)
{
    return QtConcurrent::blockingMapped(infoList, &NetImageLoad::loadImageInfoBlocking);
}

void NetImageLoad::onNetworkReplyFinished(QNetworkReply* reply)
{
    QImage image;
    // 检查网络错误
    if (reply->error() != QNetworkReply::NoError)
    {
        reply->deleteLater();
        return;
    }
    // 使用 QImageReader 处理响应数据
    QImageReader reader(reply);
    // 预读取图像信息
    if (!reader.canRead()) 
    {
        reply->deleteLater();
        return;
    }
    // 读取并显示图像
    mImage = reader.read();
    emit getImage(mImage.copy());
    reply->deleteLater();
}
