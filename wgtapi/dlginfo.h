#pragma once

#include <QWidget>
#include "ui_dlginfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class dlgInfoClass; };
QT_END_NAMESPACE

class DlgInfo : public QDialog
{
	Q_OBJECT
public:
	enum class DlgInfoResult
	{
		OK,
		No,
		Cancel
	};
public:
	DlgInfo(QWidget *parent = nullptr);
	~DlgInfo();
	static DlgInfoResult messageBox(QWidget* parent, QString title, QString message, QString buttonOK,QString buttonNo,bool isButtonNotShow = true);
private:
	Ui::DlgInfoClass *ui;
};

