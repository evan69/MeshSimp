# MeshSimp 网格简化

<font size = 4 style="font-family:微软雅黑">

## 概述

本项目为网格简化，简单实现了Garland和Heckbert提出的基于边坍缩的网格简化算法。

## 编译环境

- 编译器：g++ (GCC) 4.8.1

- 操作系统：Windows 10(64bit)

## 功能及用法

- 执行make即可编译，执行make clean即可清除；

- 执行main.exe [input file] [output file] [alpha]可以实现网格简化，其中input file为输入的obj格式文件，output file为输出的obj格式文件，alpha为一个0到1之间的小数，表示简化比。简化比越小，简化程度越高。

	**注意：输入的obj文件每一行只能以注释符#、顶点记号v或面记号f开头**

## 效果

以dragon.obj为例

- 原图【大小：9342kb】

![](http://i.imgur.com/CbldvpD.png)

- 简化比为0.3【大小：2232kb】

![](http://i.imgur.com/uH63uY1.png)

- 简化比为0.05【大小：361kb】

![](http://i.imgur.com/e7s38if.png)

- 简化比为0.01【大小：81kb】

![](http://i.imgur.com/ctFsma1.png)

## 参考

- 计算机图形学课程课件

- Garland M., Heckbert P S., Surface simplification using quadric error matrix, Computer Graphics, 1997, 209-216.

</font>