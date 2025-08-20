# 天眼头追系统
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
