# CLAUDE.md

本文件为 Claude Code (claude.ai/code) 在此仓库中工作时提供指导。

## 项目概述

基于 Qt 6.11 C++17 的 Windows 桌面应用程序，用于可移动文物数字登记验证系统。使用 Visual Studio 2022（MSVC v145 工具链）构建，仅支持 x64。

## 构建命令

在安装了 **Qt VS Tools** 扩展的 Visual Studio 2022 中打开 `imgacqu.vcxproj`。项目引用 Qt 6.11.0_msvc2022_64。

- **Debug 构建**：在 VS 中选择 `Debug|x64` 进行构建
- **Release 构建**：在 VS 中选择 `Release|x64` 进行构建
- **运行**：输出目录通过生成后事件拷贝第三方 DLL——请从输出目录运行，而非项目根目录

没有命令行构建系统（无 CMake，源代码中也没有跟踪 qmake `.pro` 文件——`x64/` 下的 `.pro` 文件由 Qt VS Tools 自动生成）。

## 架构

### 应用程序生命周期（`main.cpp`）

`main()` 按顺序初始化各单例，创建 `QApplication`，加载全局 QSS 样式表（`rc/imgacqu.qss`），然后实例化 `WgtMain`。关闭时，单例通过 `aboutToQuit` 信号按依赖关系的逆序销毁。

### 页面导航

`WgtMain` 拥有一个 `QStackedWidget`，包含以下主页面：

| 页面 | 对应类 | 功能 |
|--------|-------|---------|
| 登录页 | `WgtLogo` | 登录界面（用户名/密码） |
| 首页 | `WgtHome` | 登录后的仪表盘 |
| 登记 | `WgtReg` | 6 步文物登记向导 |
| 验证 | `WgtVerify` | 6 步文物验证向导 |
| 进度 | `WgtProgress` | 进行中/已完成的任务列表 |
| 设置 | `WgtSet` | 系统设置、相机配置、网络配置 |

导航由 `WgtMain` 的按钮槽函数（如 `on_pushButtonReg_clicked` 等）控制，这些槽函数会处理诸如保留或丢弃正在进行中的工作流等状态。

### 登记与验证向导

两者都使用**步骤索引系统**（regNO / verifyNO，取值 1–6）来跟踪多步骤工作流中的当前位置：

- **登记步骤**：`wgtregno1`（选择批次/文物）→ `wgtregno2`（拍摄全局图片）→ `wgtregno3`（标记区域）→ `wgtregno4`（低倍拍摄）→ `wgtregno5`（高倍拍摄）→ `wgtregno6`（复核/完成）
- **验证步骤**：`wgtverifyno1`（选择待验证项）→ `wgtverifyno2`（加载原始数据）→ `wgtverifyno3`（全局图片比对）→ `wgtverifyno4`（低倍比对）→ `wgtverifyno5`（高倍比对）→ `wgtverifyno6`（结果/提交）

每个带编号变体的步骤组件（如 `wgtregno21`、`wgtregno41`）是对应基础步骤针对不同文物类别（立体/平面/便携）的变体。

### 相机系统

两种相机后端，均为带有 `instance()`/`destroy()` 的单例：

- **`USBCamera`** — USB UVC 相机，通过 Qt Multimedia（`QCamera` + `QImageCapture`）实现。支持左右/上下翻转和静态拍照。
- **`NetCamera`** — 网络/IP 相机，通过自定义 SDK（`third_lib/slncam`）实现。使用 PIMPL 惯用法（`NetCameraPrivate`）。支持变焦、对焦控制、左右/上下翻转和静态拍照。

两者均发出 `picture(QImage)` 信号。向导步骤通过连接这些信号来获取拍摄的图像帧。

### 后台线程

- **`RegThread`** — 单一的登记数据工作线程。在内存中以 `QHash<QString, RegData*>` 管理数据，通过 `REGDB` 持久化到 SQLite，并通过 `MinioS3Client` 将图片上传至 MinIO。与 UI 线程通过队列信号通信（`regDataAdded`、`regDataUpdated`、`imageAdded` 等）。
- **`VerifyThread`** — 单一的验证工作线程。模式类似，但额外加载"原始"（登记的原始）图片以进行逐项比对。内部有一个状态机（`VerifyStatus`：LoadRawImage → Runing → UpData → Waiting → Finished）。

两个线程各自拥有独立的 `MinioS3Client` 实例用于异步上传。

### 数据层

- **`sqlite/SqliteDriver`** — 自定义 SQLite 封装（非 Qt SQL）。直接使用 SQLite C API，配合 `DbPage` 助手实现分页查询。
- **`artifact/regdb`** / **`artifact/verifydb`** — 数据库访问对象，在后台线程中运行。
- **`artifact/artifact.h`** — 核心数据结构：`BaseInfo`（文物元数据）、`BatchInfo`（批次元数据）、`ImageInfo`（图片记录）。包含命名规范：图片文件名编码了拍摄方向（Top/Bot/Frn/Bak/Lef/Rgh/Par）并映射到中文显示名称。
- 图片命名格式：登记为 `{编号}_{时间戳}_{类别}_{方向}_{序号}.jpg`，验证为 `VRF_{编号}_{时间戳}_{类别}_{方向}_{序号}.jpg`。

### 网络层

- **`NetworkServer`** — 后端 API 的单例 REST 客户端。处理登录（基于 token）、文物列表/批次检索、详情查询、状态更新及数据上传。token 通过 30 分钟定时器自动刷新。
- **`MinioS3Client`** — 每线程一个的 S3 上传客户端，使用 minio-cpp SDK。运行自己的 `QThread` 事件循环，处理上传队列。每张图片上传完成时发出 `uploadFinished` 信号。

### 配置

`AppConfig` 单例加载 `rc/config/appconf.json`（构建时被拷贝到输出目录）。包含以下配置段：网络服务器 URL、相机设置、MinIO 凭证、标签打印机 COM 端口以及本地存储路径。设置可通过写回 JSON 文件进行持久化。

### 第三方库

位于 `third_lib/`（项目目录的同级目录）：
- **OpenCV** — 图片处理和分析
- **ZXing** — 条码/二维码读写
- **FFmpeg** — 视频解码（网络相机流）
- **minio-cpp** — S3 兼容对象存储上传
- **slncam** — 网络相机 SDK
- **autoreplyprint** — 标签打印机 SDK

### 资源文件

- `rc/main.qrc` — Qt 资源文件，打包图片、字体、音频、QSS 样式表和配置 JSON
- `rc/imgacqu.qss` — 全局 Qt 样式表
- `rc/image/` — UI 图标和图形（PNG 格式）
- `rc/config/appconf.json` — 默认应用配置
- `rc/config/netcamera.json` — 网络相机预设参数
