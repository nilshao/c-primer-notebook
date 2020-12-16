# 第二章 第三节 进程同步

## 进程同步

回顾：进程有异步性的特征，各并发执行的进程以各自独立，不可预知的速度向前推进。

![进程同步问题](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/进程同步问题.png)

## 进程互斥

![临界资源访问](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/临界资源访问.png)

为了实现对临界资源的互斥访问，同时保证整体性能，需要遵循以下原则：

1. 空闲让进：临界区空闲时，可以允许一个请求进入临界区的进程立即进入临界区


2. 忙则等待：
































![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.PNG)
































