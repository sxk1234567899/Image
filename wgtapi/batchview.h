#pragma once

#include <QWidget>
#include "ui_batchview.h"
#include "artifact.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BatchViewClass; };
QT_END_NAMESPACE

class BatchView : public QWidget
{
	Q_OBJECT

public:
	BatchView(QWidget *parent = nullptr);
	~BatchView();
	void updateShow(const Artifact::BatchInfo& batchInfo, bool isList = true);
signals:
	void buttonClicked(Artifact::BatchInfo batchInfo);
private:
	Ui::BatchViewClass *ui;
	Artifact::BatchInfo mBatchInfo;
};

