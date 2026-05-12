#pragma once
#include <QtCore>
#include <QObject>
#include <QImage>
class LabelPrint  : public QObject
{
	Q_OBJECT

public:
	static LabelPrint* instance();
	static void destroy();
	bool printLabel(QString  fileName);
	bool initCom();
	bool open();
    bool close();
private:
	static LabelPrint* self;
	void* handle;
private:
	QStringList enumComList();
	bool bluetoothInit();
private:
	explicit LabelPrint();
	~LabelPrint();
	LabelPrint(const LabelPrint&) = delete;
	LabelPrint& operator=(const LabelPrint&) = delete;
};

