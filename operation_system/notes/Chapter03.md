# 第三章 第一节 内存

## 内存概念

内存是用于存放数据的硬件，程序执行前需要先放到内存中才能被CPU处理

于是：在多道程序环境下，系统中多个进程并发执行，多个程序的数据需要同时放到内存中，如何区分各个程序的数据需要放到什么地方？

方法：给内存的存储单元变地址，内存地址从0开始，每个地址对应一个存储单元

如果计算机”按字节编址“，则每个存储单元大小为一字节，1B，即8个二进制位

如果”按字编址“，每个存储单元大小为1个字，字长十六位的计算机中每个字的大小为16个二进制位。


![内存介绍1](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/内存介绍1.jpeg)

## 进程的运行原理：指令

![指令](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/指令.jpeg)

相对地址=逻辑地址，绝对地址=物理地址


## 从写程序到运行

![从写程序到运行](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/从写程序到运行.jpeg)

装入模块中的地址指的是“相对地址”，但是装入模块装入内存时，需要对指令中的地址进行处理。装入的三种方式（由三种不同的方法完成逻辑地址到物理地址的转换）：

1. 绝对装入 
2. 静态重定位
3. 动态重定位


### 绝对装入

在编译时，如果知道程序将放入内存中的哪个位置，编译程序将产生绝对地址的目标代码。装入程序按照装入模块中的地址，将程序和数据装入内存。

绝对装入只适用于单道程序环境。程序中使用的绝对地址可以在编译或汇编时给出，也可由程序猿直接赋予。

### 静态重定位

又称可重定位装入。编译、链接后的装入模块的地址都是从0开始的，指令中使用的地址、数据存放的地址都是相对于起始地址而言的逻辑地址。可根据内存的当前情况，将装入模块装入到内存的适当位置。装入时对地址进行“重定位”，将逻辑地址变换为物理地址。

静态重定位的特点是在一个作业装入内存时，必须分配其要求的全部内存空间，如果没有足够的内存，就不能装入该作业。作业一旦进入内存就不能再移动，也不能再申请内存空间。

### 动态重定位

动态重定位又称动态运行时装入。编译、链接后的装入模块的地址都是从0开始。装入程序把装入模块装入内存后，并不会立即把逻辑地址转换为物理地址，而是把地址转换推迟到程序真正要执行时才进行，这种方式需要一个重定位寄存器的支持。

采用动态重定位时允许程序在内存中发生移动。并且可以将程序分配到不连续的存储区中，在程序运行前只需装入它的部分代码即可投入运行，然后在程序运行期间，根据需要动态申请分配内存。


## 内存管理

* 操作系统负责内存的分配和回收

* 操作系统需要提供某种技术从逻辑上对内存空间进行扩充（虚拟内存）

* 操作系统需要提供地址转换功能，负责程序的逻辑地址和物理地址的转换

* 操作系统提供内存保护功能，保证各个进程在各自存储空间内运行，互不干扰

	内存保护两种方法：

	1. 在cpu中设置一堆上下限寄存器，存放进程的上下限地址。进程的指令要访问某个地址时，cpu检查是否越界

	2. 重定位寄存器（基址寄存器）和界地址寄存器（限长寄存器）进行越界检查，分别存放起始地址和长度

## 内存空间的扩充：覆盖和交换

![覆盖和交换](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/覆盖和交换.jpeg)

### 覆盖技术

思想：把程序分为多个段（多个模块）。常用的段常驻内存，不常用的段在需要时放入内存。需要常驻内存的段放在固定区，不常用的段放在覆盖区。内存中分为一个固定区和多个覆盖区。


![覆盖技术](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/覆盖技术.jpeg)










![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.PNG)
































