#include "localverifyclient.h"

LocalVerifyClient* LocalVerifyClient::self = nullptr;

LocalVerifyClient* LocalVerifyClient::instance()
{
    if (!self)
    {
        self = new LocalVerifyClient();
    }
    return self;
}

void LocalVerifyClient::destroy()
{
    if (self)
    {
        delete self;
        self = nullptr;
    }
}

LocalVerifyClient::LocalVerifyClient()
{
    mPythonPath = findPython();
    qDebug() << "LocalVerifyClient: Python path:" << mPythonPath;
}

LocalVerifyClient::~LocalVerifyClient()
{
}

QString LocalVerifyClient::findPython() const
{
    QString appDir = QCoreApplication::applicationDirPath();
    QStringList searchPaths;
    // 部署环境：embedded Python (artreg_python)
    searchPaths << appDir + "/artreg_python/python/python.exe";
    // 开发环境：venv (artreg_python)
    searchPaths << appDir + "/../../artreg_python/venv/Scripts/python.exe";
    searchPaths << appDir + "/../artreg_python/venv/Scripts/python.exe";
    searchPaths << appDir + "/artreg_python/venv/Scripts/python.exe";
    // 开发环境：venv (verify_python, 旧)
    searchPaths << appDir + "/../../verify_python/venv/Scripts/python.exe";
    searchPaths << appDir + "/../verify_python/venv/Scripts/python.exe";
    searchPaths << appDir + "/verify_python/venv/Scripts/python.exe";
    // 部署环境：embedded Python (verify_python, 旧)
    searchPaths << appDir + "/verify_python/python/python.exe";

    for (const auto& path : searchPaths)
    {
        QFileInfo fi(path);
        if (fi.exists())
        {
            return QDir::toNativeSeparators(fi.absoluteFilePath());
        }
    }

    // 兜底：系统 PATH 中的 python
    return "python";
}

bool LocalVerifyClient::verify(const QJsonObject& input, QJsonObject* output, QString* errorMessage)
{
    if (mPythonPath.isEmpty())
    {
        if (errorMessage) *errorMessage = "Python not found";
        return false;
    }

    // Locate the CLI script relative to the application
    QString appDir = QCoreApplication::applicationDirPath();
    QStringList scriptPaths;
    // 部署环境 (artreg_python)
    scriptPaths << appDir + "/artreg_python/verify_cli.py";
    // 开发环境 (artreg_python)
    scriptPaths << appDir + "/../../artreg_python/verify_cli.py";
    scriptPaths << appDir + "/../artreg_python/verify_cli.py";
    // 开发环境 (verify_python, 旧)
    scriptPaths << appDir + "/../../verify_python/verify_cli.py";
    scriptPaths << appDir + "/../verify_python/verify_cli.py";
    scriptPaths << appDir + "/verify_python/verify_cli.py";

    QString scriptPath;
    for (const auto& path : scriptPaths) 
    {
        QFileInfo fi(path);
        if (fi.exists())
        {
            scriptPath = fi.absoluteFilePath();
            break;
        }
    }

    if (scriptPath.isEmpty())
    {
        if (errorMessage) *errorMessage = "verify_cli.py not found";
        return false;
    }

    QProcess process;
    process.start(mPythonPath, {scriptPath});

    if (!process.waitForStarted(10000))
    {
        if (errorMessage) *errorMessage = "Failed to start Python process: " + process.errorString();
        return false;
    }

    // Write input JSON to stdin
    QJsonDocument inputDoc(input);
    QByteArray inputData = inputDoc.toJson(QJsonDocument::Compact);
    process.write(inputData);
    process.closeWriteChannel();

    // Wait for completion (max 120 seconds for all image pairs)
    if (!process.waitForFinished(120000))
    {
        process.kill();
        if (errorMessage) *errorMessage = "Python process timed out";
        return false;
    }

    // Check for errors
    if (process.exitCode() != 0)
    {
        QString errOutput = QString::fromUtf8(process.readAllStandardError());
        if (errorMessage) *errorMessage = "Python process exited with code " + QString::number(process.exitCode()) + ": " + errOutput;
        return false;
    }

    // Parse stdout JSON
    QByteArray outputData = process.readAllStandardOutput();
    QJsonParseError parseError;
    QJsonDocument outputDoc = QJsonDocument::fromJson(outputData, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        if (errorMessage) *errorMessage = "Failed to parse Python output: " + parseError.errorString();
        return false;
    }

    if (!outputDoc.isObject())
    {
        if (errorMessage) *errorMessage = "Python output is not a JSON object";
        return false;
    }

    *output = outputDoc.object();

    if ((*output)["code"].toInt() != 200)
    {
        if (errorMessage) *errorMessage = (*output)["message"].toString();
        return false;
    }

    return true;
}
