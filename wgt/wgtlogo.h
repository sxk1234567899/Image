#pragma once

#include <QWidget>
#include "ui_wgtlogo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WgtLogoClass; };
QT_END_NAMESPACE

class WgtLogo : public QWidget
{
	Q_OBJECT
public:
	Ui::WgtLogoClass* ui;
public:
	WgtLogo(QWidget *parent = nullptr);
	~WgtLogo();

private:

};

