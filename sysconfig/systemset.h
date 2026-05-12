#pragma once
#include <QtCore>
#include <Windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
class SystemSet
{

public:
	static SystemSet* instance();
	static void destroy();
	// 设置系统音量（0.0f 到 1.0f 之间）
	bool setVolume(float volumeLevel);

	// 获取当前系统音量
	float getVolume();

	// 静音/取消静音系统音量
	bool setMute(bool mute);

	// 获取当前静音状态
	bool isMute();

	// 设置屏幕亮度（0 到 100 之间）
	static bool setScreenBrightness(int brightness);

	// 获取当前屏幕亮度
	static int getScreenBrightness();

	static int getEstimatedChargeRemaining();


	static QString getWmic(const QString& cmd);
	static QString getCpuName();
	static QString getUUID();
	static QString getBaseBoardId();
	static QString getDiskNum();

	static bool get4GNetName(QString &name, quint32 &quality);
	static bool ctr4GNet(bool isOpen);

private:
	SystemSet();
	~SystemSet();
	SystemSet(const SystemSet&) = delete;
	SystemSet& operator=(const SystemSet&) = delete;
	// 初始化 COM 库
	bool initializeCOM();
	// 释放 COM 资源
	void uninitializeCOM();
	// 获取默认音频设备的音量控制接口
	IAudioEndpointVolume* getDefaultAudioEndpoint();
	IAudioEndpointVolume* mEndpointVolume = nullptr; // 音频端点音量接口
	bool mIsMute = false; // 静音状态
	bool mIsInitialized = false; // 是否已初始化
	static SystemSet* self; // 单例实例
};



