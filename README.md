# 天眼头追系统

用头部动作控制无人机云台：操作者转动头部，远端摄像头跟着转动，一个人就能同时操控飞行器和任务载荷。

## 版本演进

| 版本 | 状态 | 头部姿态来源 | 系统链路 | 文档 |
|---|---|---|---|---|
| **V1** | ✅ 已完成（历史版本） | 自制头戴模块（MPU6050） | MPU6050 → Arduino → HC-05 蓝牙 → Arduino → PPM → 云台 | 本页下方「作品简介」起 |
| **V2** | 🚧 开发中（设计阶段） | Apple AirPods 头部追踪 | AirPods → MacBook / iPhone → Wi-Fi UDP → ESP32 → 云台 | [v2/README.md](v2/README.md) |
| **V3** | 🔬 研究中（可行性研究） | DJI Goggles 2 内置传感器（待研究） | DJI Goggles 2 → 获取方式待研究 → ESP32 → 云台 | [v3/README.md](v3/README.md) |

### V1：Arduino + MPU6050 头戴模块（2022–2023）

- 头戴端用 Arduino 读取 MPU6050 的俯仰和偏航角，通过 HC-05 蓝牙发送给接收端。
- 接收端把角度转换成 8 通道 PPM 信号，控制两轴或三轴云台。
- 配套 F550 六旋翼无人机、DJI NAZA 飞控、OpenTX 遥控器和 5.8 GHz 图传。
- 仓库中保留了全部源代码、3D 外壳模型、支撑材料和测试视频（见下方「仓库目录」）。V2、V3 不修改 V1 的源代码和硬件资料。

### V2：AirPods 头部追踪（开发中）

- 不再需要专用头戴硬件，改用 AirPods 内置的头部追踪传感器，通过开源项目 [AirTracker](https://github.com/crippler95/airtracker) 在 macOS 上获取 Yaw / Pitch / Roll。
- Python 上位机负责姿态解析、校准、滤波和映射；ESP32 工作在 SoftAP 模式，MacBook 直接连接它，通过 UDP 发送控制指令，不需要路由器。
- 新增 Gaming Mode：用头部侧倾（Roll）触发 Q / E 键，实现 FPS 游戏中的左右侧身。
- 模块化设计，各模块可以单独替换：Motion Input、Motion Processing、Gimbal Controller、Gaming Controller、Visualization、Configuration。
- **当前进度**：只在 MacBook 上运行 AirTracker，初步确认能实时追踪头部。UDP 接收、ESP32 通信、云台驱动、游戏按键映射等功能**都还没有实现**。

### V3：DJI Goggles 2 原生头部追踪（研究阶段）

> **V3 Status: Research / Feasibility Study**

- 研究能否直接读取 DJI Goggles 2 内置的头部姿态数据并用来控制第三方云台，这样 FPV 飞行时就不需要再戴 AirPods 或额外的 IMU 模块。
- 计划研究三个方向：USB-C 通信分析（优先，只读）、无线协议调研（只查文献）、内部软件评估（只评估，不改固件）。
- 如果可行，Goggles 2 将作为 V2 的一个可替换输入源，和 AirPods 共用后面的姿态处理与云台控制模块。
- **当前进度**：只完成了资料调研。目前已公开的开源项目都没有提到如何读取 Goggles 2 的头追数据，第三方能否读到**尚不确定**，也**没有做过任何硬件验证**。

## 仓库目录

```
SKY-EYES/
├── README.md                      # 项目主页（本文件）
├── sketch_jan09a.ino              # V1 头戴端程序
├── sky_eyes_slave.ino             # V1 接收端程序（PPM 输出）
├── master.stl / slave.stl / 无.stl  # V1 3D 打印外壳
├── 天眼头追系统支撑材料1.docx        # V1 支撑材料
├── 第一代数据采集模块开发板测试视频.mp4
├── 第二代数据采集模块与六旋翼无人机测试视频.mp4
├── v2/
│   └── README.md                  # V2 设计文档：AirPods 头部追踪
└── v3/
    └── README.md                  # V3 研究文档：DJI Goggles 2 头部追踪
```

---

> 以下是 V1 的原始项目介绍。

## 作品简介
本项目旨在开发一款创新性的无人机天眼头追系统，将人的头部与无人机云台摄像头及相关任务模块融为一体，极大地提高了操作效率。本项目的创新点在于使用移动头部来操控无人机云台和相关任务模块进行移动，区别于传统使用电位器滑轮进行操作，将人的眼睛与无人机云台摄像头及相关任务模块融为一体，实现了单人操作无人机及任务模块的功能。该系统由无人机平台、数据采集模块、图像发射模块和无人机操作装置四部分组成。数据采集模块采用Arduino nano 开发板搭配mpu6050电子陀螺仪模块、HC05蓝牙传感器模块等配件，实现数据采集与传输。无人机平台采用f550六旋翼无人机和DJI NAZA飞行器控制模块等设备。无人机操作装置和图像发射模块则分别使用opentx操作系统和能接收5.8Ghz图像传输信号的设备。


## 各系统组成部分
- 第一代数据采集模块（采用外置供电与有线连接）
  



- 第二代数据采集模块（采用内置供电与无线连接，包括数据采集模块主模块与数据采集模块从模块）
 
 
 
- F550六旋翼无人机（具备救援物质投放能力）
 


 
- 目标指示模块（包括激光指示与LED亮白光指示）
 
 

- 数据采集模块开发板
 
## 安装与使用

- 飞行器端
  飞行器端使用PWM信号控制的两轴或者三轴云台，系统默认输出PWM信号或PPM信号

  
- 地面端

  地面端分为两部分，遥控器模块和头戴模块

  头戴模块

  Arduino nano 33 BLE、mpu 6050、HC-05 蓝牙模块

  遥控模块

  Arduino nano 33 BLE 、HC-05 蓝牙模块


- 当硬件连接完成时,将连接好的开发板放入已经打印好的3D模型中

## 




# Sky Eye Head Tracking System

## Versions

| Version | Status | Head pose source | Docs |
|---|---|---|---|
| **V1** | ✅ Completed (legacy) | Custom head unit (Arduino + MPU6050 + HC-05) | This page |
| **V2** | 🚧 In development (design stage) | Apple AirPods via AirTracker → Wi-Fi UDP → ESP32 | [v2/README.md](v2/README.md) |
| **V3** | 🔬 Research / Feasibility Study | DJI Goggles 2 built-in sensors (not yet known if accessible) | [v3/README.md](v3/README.md) |

The sections below describe the original V1 system.

## Introduction
This project aims to develop an innovative UAV sky eye head tracking system, which integrates the human head with the UAV gimbal camera and related task modules, greatly improving the operation efficiency. The innovation of this project lies in using the movement of the head to control the movement of the UAV gimbal and related task modules. Different from the traditional operation using potentiometer pulleys, it integrates human eyes with the UAV gimbal camera and related task modules, realizing the function of single-person operation of the UAV and task modules. The system consists of four parts: UAV platform, data acquisition module, image transmission module and UAV operation device. The data acquisition module adopts Arduino nano development board with mpu6050 electronic gyroscope module, HC05 Bluetooth sensor module and other accessories to realize data acquisition and transmission. The UAV platform uses f550 hexacopter UAV and DJI NAZA flight control module and other equipment. The UAV operation device and image transmission module use opentx operating system and devices capable of receiving 5.8Ghz image transmission signals respectively.


## Components of Each System
- The first-generation data acquisition module (with external power supply and wired connection)
  



- The second-generation data acquisition module (with built-in power supply and wireless connection, including the main module of the data acquisition module and the slave module of the data acquisition module)
 
 
 
- F550 hexacopter UAV (with the ability to drop rescue materials)
 


 
- Target indication module (including laser indication and LED white light indication)
 
 

- Data acquisition module development board
 
## Installation and Use

- Aircraft end
  The aircraft end uses a two-axis or three-axis gimbal controlled by PWM signal, and the system outputs PWM signal or PPM signal by default.

  
- Ground end

  The ground end is divided into two parts: remote control module and head-wearing module

  Head-wearing module

  Arduino nano 33 BLE, mpu 6050, HC-05 Bluetooth module

  Remote control module

  Arduino nano 33 BLE, HC-05 Bluetooth module


- When the hardware connection is completed, put the connected development board into the printed 3D model
