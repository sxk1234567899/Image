#pragma once

#include <QDialog>
#include "ui_dlginput.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DlgInputClass; };
QT_END_NAMESPACE

class DlgInput : public QDialog
{
	Q_OBJECT

public:
	DlgInput(QWidget *parent = nullptr);
	~DlgInput();
	static bool inputBox(QWidget* parent, QString title, QString &message, QString buttonOK, QString buttonNo,bool isPassword = false);
private:
	Ui::DlgInputClass *ui;
};

