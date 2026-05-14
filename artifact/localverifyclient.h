#pragma once

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QProcess>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

class LocalVerifyClient : public QObject
{
    Q_OBJECT

public:
    static LocalVerifyClient* instance();
    static void destroy();

    bool verify(const QJsonObject& input, QJsonObject* output, QString* errorMessage = nullptr);

private:
    explicit LocalVerifyClient();
    ~LocalVerifyClient();
    LocalVerifyClient(const LocalVerifyClient&) = delete;
    LocalVerifyClient& operator=(const LocalVerifyClient&) = delete;

    QString findPython() const;

    static LocalVerifyClient* self;
    QString mPythonPath;
};
