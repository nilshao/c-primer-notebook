# 第二章 第三节 进程同步

## 进程同步

回顾：进程有异步性的特征，各并发执行的进程以各自独立，不可预知的速度向前推进。因此需要进程进程同步解决这种异步问题。有的进程之间需要相互配合地完成工作，各进程的工作推进需要遵循一定的先后顺序

“同步”也可称为直接制约关系

## 进程互斥

对临界资源的访问需要互斥地进行，即同一时间段内只能允许一个进程访问该资源，对临界资源的互斥访问分为四个部分：

![临界资源访问](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/临界资源访问.png)

为了实现对临界资源的互斥访问，同时保证整体性能，需要遵循以下原则：

1. 空闲让进：临界区空闲时，可以允许一个请求进入临界区的进程立即进入临界区


2. 忙则等待：当已有进程进入临界区时，其他试图进入临界区的进程必须等待

3. 有限等待：对请求访问的进程，应保证能在有限时间内进入临界区（保证不会饥饿）

4. 让权等待：当进程不能进入临界区时，应立即释放处理机，防止进程忙等待


## 进程互斥的软件实现

单标志法，双标志先检查，双标志后检查，peterson算法

每个方法考虑：

1. 各个算法的思想、原理

2. 结合“实现互斥的四个逻辑部分”，理解各个算法在进入区，退出区都做了什么

3. 结合“实现互斥的四个原则”，分析各个算法的缺陷

### 单标志法

思想：两个进程在访问完临界区后会把使用临界区的权限转交给另一个进程，也就是说每一个进程进入临界区的权限只能被另一个进程赋予

psuedo code:

![单标志法](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/单标志法.png)
































![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.PNG)
































