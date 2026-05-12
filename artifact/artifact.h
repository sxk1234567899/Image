#pragma once
#include <QtCore>
#include<QImage>
namespace Artifact
{ 
	const QString gVerifyNameHeader = "VRF_";
	const QStringList gImgShowNameList = QStringList() << "顶" << "底" << "前" << "后" << "左" << "右" << "局部";
	const QStringList gImgNameList = QStringList() << "Top" << "Bot" << "Frn" << "Bak" << "Lef" << "Rgh" << "Par";
	const QString gDeptName = "便携设备 ";
	struct BatchInfo
	{
		int id;						//批次ID
		QString code;				//批次编码
		QString name;				//批次名称
		int category = 0;			//文物艺术品类型分类：1立体 2平面 3便携
		QString lastSampleTime;		//同步时间
		int totalChecks = 0;		//批量传入总数
		QString applicant;			//申请人
		QString carrier;			//携运人
		QString exhibitionTitle;	//展览名称
		int batchType;			//事项类型:1临时出境;2复进境
		int applyType;			//申请类型:1一般申请;2展览申请
		int uploadedCount = 0;		//已经传入数量

	};
	struct BaseInfo
	{
		int id;
		int deptId;
		QString number;				 //标的编号
		QString mainImageAddr;			 //文物主图
		QImage mainImage;
		QString name;				 // 标的名称
		QString size;				 //标的尺寸
		QString age;				 //  年龄
		QString texture;			 // 标的质地
		QString level;				 // 级别
		QString stauts;				 //'未开始','进行中','已完成'
		QString verifyResult;		 ////验证状态：通过、未通过、未验证
		QString remarks;			// 备注
		QString result;				// 验证结果
		int unitId;					 //采样单位
		int weight;					 //重量
        QString nickName;
		QString deptName;

		QString regAgency;
		QString createTime;
		QString updateTime;
		QString verifyTime;
	};
	enum ImageStatus
	{
		saved,		// 已保存
		unsaved,	// 未保存
		saveFailed,	// 保存失败
	};
	struct ImageInfo
	{
		QString number;					// 标的编号
		int id;
		QString imageName;				// 图片名称
		QString imageLocalDir;			// 图片本地目录
		QString imageLocalAddr;			// 图片路径	
		QString imageNetAddr;			// 图片网络地址
		ImageStatus status = unsaved;	// 图片状态
	};

	static QString  imageNameShow(QString name)
	{
		QString ret = name;
		auto pos = name.split("_");

		if (pos.size() >= 4)
		{
			if (name.startsWith(gVerifyNameHeader))
			{
				int index = gImgNameList.indexOf(pos[4]);
				if (index >= 0 && index < gImgShowNameList.size())
				{
					pos[4] = gImgShowNameList[index];
				}
			}
			else
			{
				int index = gImgNameList.indexOf(pos[3]);
				if (index >= 0 && index < gImgShowNameList.size())
				{
					pos[3] = gImgShowNameList[index];
				}
			}
			ret = pos.join("_");
		}
		return ret;
	}
	static QString  imageName(QString showName)
	{
		QString ret = showName;
		auto pos = showName.split("_");
		if (pos.size() >= 4)
		{
			if (showName.startsWith(gVerifyNameHeader))
			{
				int index = gImgShowNameList.indexOf(pos[4]);
				if (index >= 0 && index < gImgNameList.size())
				{
					pos[4] = gImgNameList[index];
				}
			}
			int index = gImgShowNameList.indexOf(pos[3]);
			if (index >= 0 && index < gImgNameList.size())
			{
				pos[3] = gImgNameList[index];
			}
			ret = pos.join("_");
		}
		return ret;
	}
}