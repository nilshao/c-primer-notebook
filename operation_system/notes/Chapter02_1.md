# 第二章 第一节 进程和线程

## 进程的定义，组成，组织方式，特征

* 在计算机发展史上，“进程”是为了解决什么问题而被引入的？

* 每个进程由哪些部分组成

* 系统中各个进程之间是如何被组织起来的？

* 相比于程序，进程有哪些特征

## 进程的定义，进程与程序

程序：就是一个指令序列

早期的计算机只支持单道程序，内存：程序的代码放在程序段内，低地址，程序运行过程处理的数据放在数据段内（如变量），高地址。

**多道程序技术：** 引入多道程序技术后：内存中同时放入多道程序，各个程序的代码，运算数据存放的位置不同，操作系统如何找到各个程序的存放位置？


**PCB：** 系统为每个运行的程序配置一个数据结构，称为进程控制块（PCB），用来描述进程的各种信息（如程序代码存放位置）

为了方便操作系统管理，完成各个程序并发执行，引入了进程、进程实体的概念。PCB、程序段、数据段三部分构成进程实体（进程映像），一般情况下，我们把进程实体就简称为进程，例如，所谓创建进程，实质上是创建进程实体中的PCB；而撤销进程，实质上是撤销进程实体中的PCB。

PCB是进程存在的唯一标志！！！

进程的典型定义方式：“动态性”

1. 进程是程序的一次执行过程

2. 进程是一个程序及其数据在处理机上顺序执行时所发生的活动

3. 进程是具有独立功能的程序在数据集合上运行的过程，它是系统进行资源分配和调度的一个独立单位

引入进程实体的概念后，可把进程定义为：进程是进程实体的运行过程，是系统进行资源分配和调度的一个独立单位。

严格来说，进程实体和进程并不一样，进程实体是静态的，进程则是动态的，不过一般也不区分。

### PCB的组成：

进程描述信息

![PCB组成](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/PCB组成.jpeg)

进程标识符PID：当进程被创建时，操作系统会为该进程分配一个唯一的、不重复的ID，用于区分不同的进程（类似于身份证号）

寄存器值：当进程切换时需要把进程当前的运行情况记录下来保存在PCB中，如程序计数器的值表示当前程序执行到哪一句

## 进程的组织

在一个系统中通常有数十数百个PCB，如何有效组织多个线程

![进程的组织方式](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/进程的组织方式.jpeg)







![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.png)






















