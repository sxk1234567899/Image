#include <QtSerialPort>
#include "labelprint.h"
#include "autoreplyprint.h"
#include "appconfig.h"
LabelPrint* LabelPrint::self = nullptr;

LabelPrint* LabelPrint::instance()
{
	static QMutex mutex;
	if (self == nullptr)
	{
		QMutexLocker locker(&mutex);
		if (self == nullptr)
		{
			self = new LabelPrint();
		}
	}
	return self;
}
void LabelPrint::destroy()
{
	if (self)
	{
		delete self;
		self = nullptr;
	}
}



LabelPrint::LabelPrint()
	: QObject(nullptr)
{}

LabelPrint::~LabelPrint()
{}
void OnBluetoothDeviceDiscovered(const char* device_name, const char* device_address, const void* private_data)
{
	qDebug()<<"device_name"<<device_name << "device_address"<<device_address;
}
bool LabelPrint::open()
{
	char buffer[0x1000];
	bool re = false;
	handle = nullptr;
	if ((CP_Port_EnumUsb(buffer, sizeof(buffer), NULL)>0)&&(strlen(buffer) > 0))
	{/*USB连接*/
		QByteArray usbAddr = QByteArray::fromRawData(buffer, strlen(buffer));
		handle = CP_Port_OpenUsb(usbAddr.constData(), 0);
        if (handle !=nullptr)
		{
			re = true;
		}
		else
		{
			CP_Port_Close(handle);
			re= false;
		}
	}
	else/*蓝牙连接通过串口访问*/
	{
		QStringList serialnameList = enumComList();
		QString serialname = AppConfig::instance()->labelPrintConf().com;
		if (!serialnameList.isEmpty() &&serialnameList.indexOf(serialname) >= 0)
		{
				handle =CP_Port_OpenCom(serialname.toStdString().c_str(), 115200, CP_ComDataBits_8, CP_ComParity_NoParity, CP_ComStopBits_One, CP_ComFlowControl_None, 0);
				if (handle != nullptr)
				{
                    re = true;
					
				}
				else
				{
					CP_Port_Close(handle);
					return false;
				}
		}
		else if(serialnameList.size() == 1)
		{
			handle = CP_Port_OpenCom(serialnameList[0].toStdString().c_str(), 115200, CP_ComDataBits_8, CP_ComParity_NoParity, CP_ComStopBits_One, CP_ComFlowControl_None, 0);
			if (handle != nullptr)
			{
				re = true;

			}
			else
			{
				CP_Port_Close(handle);
				return false;
			}
		}
		else
		{
			handle = nullptr;
			re = false;
		}
	}
	if (re)
	{
		CP_Port_ClearMemoryBufferData(handle);
		CP_Label_PageBegin(handle, 0, 0, 500, 800, CP_Label_Rotation_0);
		CP_Label_DrawBox(handle, 0, 0, 500, 800, 1, CP_Label_Color_Black);
	}
	return re;
}
bool LabelPrint::close()
{
	CP_Port_ClearMemoryBufferData(handle);
    CP_Port_Close(handle);
	handle = nullptr;
	return true;
}
bool LabelPrint::initCom()
{
	QStringList serialnameList = enumComList();
	bool re = false;
	QString printCom;
	for (auto serialname : serialnameList)
	{
		handle = CP_Port_OpenCom(serialname.toStdString().c_str(), 115200, CP_ComDataBits_8, CP_ComParity_NoParity, CP_ComStopBits_One, CP_ComFlowControl_None, 0);
        if (handle != nullptr)
		{
			CP_Port_ClearMemoryBufferData(handle);
			char buf[0x1000];
			unsigned int backLen =0;
			if(CP_Printer_GetPrinterFirmwareVersion(handle, buf,0x1000, &backLen)&&backLen > 0)
			{
				printCom = serialname;
				re = true;
				break;
			}
		}
	}
	if (re && (!printCom.isEmpty()))
	{
		LabelPrintConf conf = AppConfig::instance()->labelPrintConf();
		conf.com = printCom;
        AppConfig::instance()->setLabelPrintConf(conf);
	}
	return re;
}
bool LabelPrint::printLabel(QString fileName)
{
	bool re = false;
	if (!CP_Port_IsOpened(handle))
	{
		open();
	}
	if (CP_Port_IsOpened(handle))
	{
		QFile inputFile(fileName);
		if (inputFile.open(QIODevice::ReadOnly))
		{
			QByteArray inputFileData = inputFile.readAll();

			CP_Label_BackPaperToPrintPosition(handle);
			CP_Pos_PrintRasterImageFromData(handle, 400, 600, (const unsigned char*)inputFileData.data(), inputFileData.length(), CP_ImageBinarizationMethod_ErrorDiffusion, CP_ImageCompressionMethod_None);
			CP_Label_FeedPaperToTearPosition(handle);
			re = CP_Pos_QueryPrintResult(handle, 30000);
			inputFile.close();
		}
	}
	close();
	return re;
}

QStringList LabelPrint::enumComList()
{
	QStringList serialNameList;
	for(const QSerialPortInfo & info:QSerialPortInfo::availablePorts())
	{
		if (info.portName().startsWith("COM")&& info.description().contains("蓝牙"))
		{
			serialNameList << info.portName() ;
		}
	}
	return serialNameList;

}

bool LabelPrint::bluetoothInit()
{
	 return false;
}