#include "networkserver.h"
#include <QEventLoop>
#include <QTimer>
#include <QDebug>
#include <QMutexLocker>
NetworkServer* NetworkServer::self = nullptr;
NetworkServer* NetworkServer::instance()
{
    static QMutex mutex;
    if (self == nullptr)
    {
        QMutexLocker locker(&mutex);
        if (self == nullptr)
        {
            self = new NetworkServer();
        }
    }
	return self;
}
void NetworkServer::destroy()
{
    if (self)
    {
        delete self;
        self = nullptr;
	}
}

NetworkServer::NetworkServer()
	: QObject(nullptr)
	, mUrl("")
	, mToken("")
    , mUsername("")
    , mPassword("")
    , mTimer(new QTimer(this))
{
    connect(mTimer, &QTimer::timeout, this, &NetworkServer::refreshLogin);
}

NetworkServer::~NetworkServer()
{}
void NetworkServer::setUrl(const QString& url)
{
	mUrl = url;
}


//登录服务器获取token
bool NetworkServer::login(const QString& username, const QString& password, QString* message)
{
    mUsername = username;
    mPassword = password;
    isLogin = false;
    QNetworkRequest request(mUrl+"/api/login");

    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonData;
    jsonData["username"] = username;
    jsonData["password"] = password;
    // 将JSON对象转换为JSON文档并转换为字节数组
    QByteArray data = QJsonDocument(jsonData).toJson();

    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.post(request, data);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error()!= QNetworkReply::NoError) 
    {
        qDebug() << "NetworkServer::login POST请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
        return false; 
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::login POST 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return false;
    }
    if (message)
    {
        message->append(responseJson["message"].toString());
    }
    qDebug() << " NetworkServer::login";
    qDebug().noquote() << QString::fromUtf8(QJsonDocument(responseJson).toJson(QJsonDocument::Indented));
    if (responseJson.contains("success")&& responseJson["success"].toBool() == true)
    {
        mToken = responseJson["data"].toObject()["token"].toString();
        isLogin = true;
        mTimer->start(mTokenTimeOut);
        qDebug() << "NetworkServer::login" << "登录成功";
        mUserInfo = getUserInfo();
        return true;
    }

    return false;
}

//刷新登录状态
bool NetworkServer::refreshLogin()
{
    isLogin = false;
    QNetworkRequest request(mUrl + "/api/login");
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());

    QJsonObject jsonData;
    jsonData["username"] = mUsername;
    jsonData["password"] = mPassword;
    // 将JSON对象转换为JSON文档并转换为字节数组
    QByteArray data = QJsonDocument(jsonData).toJson();

    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.post(request, data);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "NetworkServer::login POST请求错误:" << reply->errorString();
        return false;
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::login POST 返回数据错误";
        return false;
    }
    qDebug() << " NetworkServer::refreshLogin";
    qDebug().noquote() << QString::fromUtf8(QJsonDocument(responseJson).toJson(QJsonDocument::Indented));
    if (responseJson.contains("success") && responseJson["success"].toBool() == true)
    {
        mToken = responseJson["data"].toObject()["token"].toString();
        isLogin = true;
        mUserInfo = getUserInfo();
        return true;
    }
    return false;
}

//从服务器获取用户信息
UserInfo NetworkServer::getUserInfo()
{
    UserInfo userInfo;
    if (!isLogin)
    {
        return userInfo;
    }
    QNetworkRequest request(mUrl + "/api/getUserInfo");
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());
    // 发送get请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.get(request, nullptr);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "NetworkServer::getArtifactsBatch POST请求错误:" << reply->errorString();
        return userInfo;
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << " NetworkServer::getArtifactsBatchList POST 返回数据错误";
        return userInfo;
    }
    if (!responseJson.contains("success") || !responseJson["success"].toBool())
    {
        qDebug() << " NetworkServer::getArtifactsBatchList 获取批次信息失败";
        return userInfo;
    }
    qDebug() << " NetworkServer::getUserInfo";
    qDebug().noquote() << QString::fromUtf8(QJsonDocument(responseJson).toJson(QJsonDocument::Indented));
    QJsonObject dataJson = responseJson["data"].toObject();
    userInfo.id = dataJson["id"].toInt();
    userInfo.username = dataJson["username"].toString();
    userInfo.nickname = dataJson["nickname"].toString();
    QJsonArray deptsData = dataJson["depts"].toArray();
    if (deptsData.size() > 0)
    {
        QJsonObject deptData = deptsData[0].toObject();
        userInfo.dept_id = deptData["id"].toInt();
        userInfo.unitName = deptData["name"].toString();
        userInfo.leader = deptData["leader"].toString();
        userInfo.phone = deptData["phone"].toString();
    }
    return userInfo;
}

//从服务器获取批次列表
QList<Artifact::BatchInfo> NetworkServer::getArtifactsBatchList(int page, QJsonObject* json, bool isValidates, QString* message)
{
    if (!isLogin)
    {
        return QList<Artifact::BatchInfo>();
    }
    QString url;
    if (isValidates)
    {
        url = mUrl + QString("/api/validates/batch?pageSize=20&page=1").arg(page);
    }
    else
    {
        url = mUrl + QString("/api/artifacts/batch?pageSize=20&page=%1").arg(page);
    }
    QNetworkRequest request(url);
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setRawHeader("Authorization", "Bearer "+mToken.toUtf8());
    // 发送get请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.get(request,nullptr);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::InternalServerError && reply->error() != QNetworkReply::NoError)
    {
        qDebug() << " NetworkServer::getArtifactsBatchList POST请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
        return QList<Artifact::BatchInfo>();
    }
    responseData = reply->readAll();
    reply->deleteLater();
	QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << " NetworkServer::getArtifactsBatchList POST 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return QList<Artifact::BatchInfo>();
	}
    if (json)
    {
        *json = responseJson;
    }
    if (message)
    {
        message->append(responseJson["message"].toString());
    }
    if (!responseJson.contains("success") || !responseJson["success"].toBool())
    {
        qDebug() << " NetworkServer::getArtifactsBatchList 获取批次信息失败";
        return QList<Artifact::BatchInfo>();
	}
    qDebug() << " NetworkServer::getArtifactsBatchList";
    qDebug().noquote() << QString::fromUtf8(QJsonDocument(responseJson).toJson(QJsonDocument::Indented));
	QList<Artifact::BatchInfo> batchList;
	QJsonArray dataArray = responseJson["data"].toObject()["items"].toArray();
    for (const QJsonValue& value : dataArray)
    {
        Artifact::BatchInfo batchInfo;
        QJsonObject batchObj = value.toObject();
        batchInfo.id = batchObj["id"].toInt();
		batchInfo.code = batchObj["artifact_code"].toString();
        batchInfo.name = batchObj["artifact_name"].toString();
        batchInfo.category = batchObj["artifact_category"].toInt();
        batchInfo.lastSampleTime = batchObj["last_sample_time"].toString();
		batchInfo.totalChecks = batchObj["total_checks"].toInt();
        batchInfo.applicant = batchObj["applicant"].toString();
        batchInfo.carrier = batchObj["carrier"].toString();
        batchInfo.exhibitionTitle = batchObj["exhibition_title"].toString();
        batchInfo.batchType = batchObj["batch_type"].toInt();
        batchInfo.applyType = batchObj["apply_type"].toInt();
        if (batchInfo.applyType = 1)
        {
            batchInfo.exhibitionTitle.clear();
        }
		batchInfo.uploadedCount = batchObj["uploaded_count"].toInt();
        batchList.append(batchInfo);
	}
   
    return batchList;
}


//从服务器获取文物列表
QList<Artifact::BaseInfo> NetworkServer::getArtifactsList(int batchId,int page, QJsonObject* json, bool isValidates, QString* message)
{
    if (!isLogin)
    {
        return QList<Artifact::BaseInfo>();
    }
    QString url;
    if (isValidates)
    {
        url = mUrl + QString("/api/validates/%1?pageSize=20&page=%2").arg(batchId).arg(page);
    }
    else
    {
        url = mUrl + QString("/api/artifacts/%1?pageSize=20&page=%2").arg(batchId).arg(page);
    }
    QNetworkRequest request(url);
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());
    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.get(request, nullptr);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::InternalServerError && reply->error() != QNetworkReply::NoError )
    {
        qDebug() << "NetworkServer::getArtifactsList POST请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
        return QList<Artifact::BaseInfo>();
    }
    responseData = reply->readAll();
    qDebug() << responseData;
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (json)
    {
        *json = responseJson;
    }
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::getArtifactsList POST 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return QList<Artifact::BaseInfo>();
    }
    if (message)
    {
        message->append(responseJson["message"].toString());
    }
    if (!responseJson.contains("code") || responseJson["code"].toInt()!=200)
    {
        qDebug() << "NetworkServer::getArtifactsList 获取批次信息失败";
        return QList<Artifact::BaseInfo>();
    }
    qDebug() << "NetworkServer::getArtifactsList ";
    qDebug().noquote() << QString::fromUtf8(QJsonDocument(responseJson).toJson(QJsonDocument::Indented));
    QList<Artifact::BaseInfo> infoList;
    QJsonArray dataArray = responseJson["data"].toObject()["list"].toObject()["items"].toArray();
    if (isValidates)/*验证字段*/
    {
        for (const QJsonValue& value : dataArray)
        {
            Artifact::BaseInfo info;
            QJsonObject infoObj = value.toObject();
            info.id = infoObj["id"].toInt();
            info.deptId = infoObj["dept_id"].toInt();
            info.number = infoObj["artifact_number"].toString();
            info.mainImageAddr = infoObj["main_image"].toString();
            info.name = infoObj["artifact_name"].toString();
            info.size = infoObj["size"].toString();
            info.age = infoObj["age"].toString();
            info.texture = infoObj["texture"].toString();
            info.level = infoObj["level"].toString();
            info.stauts = infoObj["inspect_status"].toString();
            info.unitId = infoObj["unit_id"].toInt();
            info.weight = infoObj["weight"].toInt();
            info.createTime = infoObj["created_at"].toString();
            info.updateTime = infoObj["updated_at"].toString();
            // info.result = infoObj["result"].toString();
            if (infoObj["unit"].isObject() && infoObj["unit"].toObject().contains("nickname"))
            {
                info.nickName = infoObj["unit"].toObject()["nickname"].toString();
            }
            else if (infoObj["operate"].isObject() && infoObj["operate"].toObject().contains("nickname"))
            {
                info.nickName = infoObj["operate"].toObject()["nickname"].toString();
            }
            if (infoObj["verify_result"].isObject())
            {
                info.verifyResult = infoObj["verify_result"].toObject()["verify_status"].toString();
            }
            infoList.append(info);
        }
    }
    else/*登记字段*/
    {
        for (const QJsonValue& value : dataArray)
        {
            Artifact::BaseInfo info;
            QJsonObject infoObj = value.toObject();
            info.id = infoObj["id"].toInt();
            info.deptId = infoObj["dept_id"].toInt();
            info.number = infoObj["artifact_number"].toString();
            info.mainImageAddr = infoObj["main_image"].toString();
            info.name = infoObj["artifact_name"].toString();
            info.size = infoObj["size"].toString();
            info.age = infoObj["age"].toString();
            info.texture = infoObj["texture"].toString();
            info.level = infoObj["level"].toString();
            info.stauts = infoObj["status"].toString();
            info.unitId = infoObj["unit_id"].toInt();
            info.weight = infoObj["weight"].toInt();
            // info.result = infoObj["result"].toString();
            if (infoObj["unit"].isObject() && infoObj["unit"].toObject().contains("nickname"))
            {
                info.nickName = infoObj["unit"].toObject()["nickname"].toString();
            }
            if (infoObj["unit"].isObject() && infoObj["unit"].toObject().contains("depts"))
            {
                auto depts = infoObj["unit"].toObject()["depts"].toArray();
                if (depts.size() > 0&& depts[0].toObject().contains("name"))
                {
                    info.deptName = depts[0].toObject()["name"].toString();
                }
            }
            infoList.append(info);
        }
    }
    
    return infoList;
}

//从服务器获取文物详情给验证用的
bool NetworkServer::getArtifactsDetailInfo(int id, QString number, QJsonObject* json, bool isValidates, QString* message)
{
    if (!isLogin)
    {
        return false;
    }
    QString url;
    if (isValidates)
    {
        // /api/validates/detail?id=52
        url = mUrl + QString("/api/validates/detail?id=%1").arg(id);
    }
    else
    {
        // /api/artifacts/detail?id=472&number=2025070423
        url = mUrl + QString("/api/artifacts/detail?number=%2").arg(number);
    }
    QNetworkRequest request(url);
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());
    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.get(request, nullptr);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::InternalServerError && reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "NetworkServer::getArtifactsDetailInfo POST请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
        emit networkServerError(reply->errorString());
        return false;
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::getArtifactsDetailInfo POST 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return false;
    }
    if (message)
    {
        message->append(responseJson["message"].toString());
    }
    qDebug() << "NetworkServer::getArtifactsDetailInfo ";
    qDebug().noquote() << QString::fromUtf8(QJsonDocument(responseJson).toJson(QJsonDocument::Indented));
    if (json)
    {
        *json = responseJson;
    }
    return true;
}

//从服务器获取文物详情给界面显示
bool NetworkServer::getArtifactsDetailInfo(int id, QString number, Artifact::BaseInfo* baseinfo, Artifact::BatchInfo* batchinfo, bool isValidates, QString* message)
{
    QJsonObject jsonData;
    if (!getArtifactsDetailInfo(id, number, &jsonData, isValidates, message))
    {
        return false;
    }
    if (baseinfo)
    {
        Artifact::BaseInfo info;
        QJsonObject infoObj = jsonData["data"].toObject()["detail"].toObject();
        info.id = infoObj["id"].toInt();
        info.deptId = infoObj["dept_id"].toInt();
        info.number = infoObj["artifact_number"].toString();
        info.mainImageAddr = infoObj["main_image"].toString();
        info.name = infoObj["artifact_name"].toString();
        info.size = infoObj["size"].toString();
        info.age = infoObj["age"].toString();
        info.texture = infoObj["texture"].toString();
        info.level = infoObj["level"].toString();
        info.stauts = infoObj["status"].toString();
        info.unitId = infoObj["unit_id"].toInt();
        info.weight = infoObj["weight"].toInt();
        // info.result = infoObj["result"].toString();
        if (infoObj["unit"].isObject() && infoObj["unit"].toObject().contains("nickname"))
        {
            info.nickName = infoObj["unit"].toObject()["nickname"].toString();
        }
        *baseinfo = info;
    }

    if (batchinfo)
    { 
        Artifact::BatchInfo info;
        QJsonObject batchObj = jsonData["data"].toObject()["batchInfo"].toObject();
        info.id = batchObj["id"].toInt();
        info.code = batchObj["artifact_code"].toString();
        info.name = batchObj["artifact_name"].toString();
        info.category = batchObj["artifact_category"].toInt();
        info.lastSampleTime = batchObj["last_sample_time"].toString();
        info.totalChecks = batchObj["total_checks"].toInt();
        info.applicant = batchObj["applicant"].toString();
        info.carrier = batchObj["carrier"].toString();
        info.exhibitionTitle = batchObj["exhibition_title"].toString();
        info.batchType = batchObj["batch_type"].toInt();
        info.applyType = batchObj["apply_type"].toInt();
        if (info.applyType = 1)
        {
            info.exhibitionTitle.clear();
        }
       *batchinfo = info;
    }
    return true;
}

//向服务器上传文物状态
bool NetworkServer::postArtifactsStatus(int id, QString status, QString* message,bool isValidates)
{
    if (!isLogin)
    {
        return false;
    }
    QString url = mUrl;
    url += isValidates ? "/api/validates/start_status" : "/api/artifacts/start_status";
    QNetworkRequest request(url);
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());
    QJsonObject jsonData;
    jsonData["artifact_id"] = id;
    jsonData["artifact_status"] = status;
    // 将JSON对象转换为JSON文档并转换为字节数组
    QByteArray data = QJsonDocument(jsonData).toJson();

    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.post(request, data);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::InternalServerError && reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "NetworkServer::postArtifactsStatus POST请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
        return false;
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::login POST 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return false;
    }
    qDebug() << "NetworkServer::postArtifactsStatus" << responseJson;
    if (responseJson.contains("message") && message!=nullptr)
    {
        *message = responseJson["message"].toString();
    }
    if (responseJson.contains("code") && responseJson["code"].toInt() == 200)
    {
        return true;
    }
    return false;
}

//向服务器上传文物信息
bool NetworkServer::postArtifactUpData(QJsonObject jsonData, bool isValidates, QString* message)
{
    if (!isLogin)
    {
        return false;
    }
    QString url = mUrl;
    url += isValidates ? "/api/validates/artifact_up_data" : "/api/artifacts/artifact_up_data";
    QNetworkRequest request(url);
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());

    // 将JSON对象转换为JSON文档并转换为字节数组
    QByteArray data = QJsonDocument(jsonData).toJson();
    qDebug()<<"postArtifactUpData:"<<data;
    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.post(request, data);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::InternalServerError && reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "NetworkServer::postArtifactUpData POST请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
        emit networkServerError(reply->errorString());
        return false;
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::postArtifactUpData POST 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return false;
    }
    if (message)
    {
        message->append(responseJson["message"].toString());
    }
    qDebug() << "NetworkServer::postArtifactUpData" << responseJson;
    if (responseJson.contains("success") && responseJson["success"].toBool() == true)
    {
        return true;
    }
    return false;
}

//向服务器上传修改后的文物信息
bool NetworkServer::putArtifactModifyData(int id,QJsonObject jsonData, bool isValidates, QString* message)
{
    if (!isLogin)
    {
        return false;
    }
    QString url;
    if (isValidates)
    {
        url = mUrl + QString("/api/validates/artifact_up_data/%1").arg(id);
    }
    else
    {
        url = mUrl + QString("/api/artifacts/artifact_up_data/%1").arg(id);
    }
    QNetworkRequest request(url);
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());

    // 将JSON对象转换为JSON文档并转换为字节数组
    QByteArray data = QJsonDocument(jsonData).toJson();

    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.put(request, data);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::InternalServerError && reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "NetworkServer::putArtifactModifyData 请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
       
        emit networkServerError(reply->errorString());
        return false;
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::postArtifactModifyData 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return false;
    }
    if (message)
    {
        message->append(responseJson["message"].toString());
    }
    qDebug() << "NetworkServer::login" << responseJson;
    if (responseJson.contains("success") && responseJson["success"].toBool() == true)
    {
        return true;
    }
    return false;
}



//从服务器获取验证用的文物标识图
QJsonObject NetworkServer::getValidatesArtifactFlagImg(QString number, QString* message)
{
    if (!isLogin)
    {
        return QJsonObject();
    }
    QNetworkRequest request(mUrl + QString("/api/validates/artifact/flag_img?number=%1").arg(number));
    // 设置请求头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + mToken.toUtf8());
    // 发送POST请求
    QNetworkAccessManager networkManager;
    QNetworkReply* reply = networkManager.get(request, nullptr);
    // 使用事件循环等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer::singleShot(60000, &loop, &QEventLoop::quit); // 超时设置
    loop.exec();
    // 处理响应
    QByteArray responseData;
    if (reply->error() != QNetworkReply::InternalServerError && reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "NetworkServer::getValidatesArtifactFlagImg get请求错误:" << reply->errorString();
        if (message)
        {
            message->append(reply->errorString());
        }
        return QJsonObject();
    }
    responseData = reply->readAll();
    reply->deleteLater();
    QJsonObject responseJson = QJsonDocument::fromJson(responseData).object();
    if (responseJson.isEmpty())
    {
        qDebug() << "NetworkServer::getValidatesArtifactFlagImg get 返回数据错误";
        if (message)
        {
            message->append(reply->errorString());
        }
        return  QJsonObject();
    }
    if (message)
    {
        message->append(responseJson["message"].toString());
    }
    if (!responseJson.contains("success") || !responseJson["success"].toBool())
    {
        qDebug() << "NetworkServer::getValidatesArtifactFlagImg 获取登记时信息失败";
        return  QJsonObject();
    }
    qDebug() << "NetworkServer::getValidatesArtifactFlagImg ";
    qDebug().noquote() << QString::fromUtf8(QJsonDocument(responseJson).toJson(QJsonDocument::Indented));
    return responseJson;
}