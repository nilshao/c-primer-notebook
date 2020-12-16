# 第二章 第二节 处理机调度

## 调度，处理机调度的概念

有一堆任务要处理，但是资源有限，这些事情没办法同时处理，就需要确定某种规则来决定处理这些任务的顺序，这就是调度

在多道程序系统中，进程的数量往往多于处理机的个数，这样不可能同时并行地处理各个进程，处理机调度就是从就绪队列中按照一定的算法选择一个进程并将处理机分配给它运行，以实现进程的并发执行

## 调度的三个层次：

## 高级调度。

由于内存空间有限，有时无法将用户提交的作业全部放入内存，因此就需要确定某种规则来决定将作业调入内存的顺序。

高级调度（作业调度）：按照一定的原则从外存上处于后备队列的作业中挑选一个（或多个）作业，给他们分配内存等必要资源，并建立相应的进程（建立pcb），以使他们获得竞争处理机的权利。

高级调度是外存与内存之间的调度，每个作业只调入一次，调出一次。掉入作业时会建立相应的pcb，调出时撤销pcb。高级调度主要是指掉入的问题，因为只有掉入时机需要操作系统来确定，但调出的时机必然是作业运行结束才调出。

## 中级调度

引入了虚拟存储技术之后，可将暂时不能运行的进程调至外存等待，等它重新具备了运行条件且内存又稍有空闲时，再重新调入内存。

这么做的目的是为了提高内存利用率和系统吞吐量。
暂时调到外存等待的进程状态为挂起状态。值得注意的是，PCB并不会一起调到外存，而是会常驻内存，pcb中会记录进程数据在外存中的存放位置，进程状态等信息，操作系统通过内存中的pcb来保持对各个进程的管理、监控，被挂起的进程pcb会被放到挂起队列中
 

中级调度（内存调度），就是要决定将哪个处于挂起状态的进程重新调入内存。
一个进程可能被多次调入调出内存，因此中级调度发生的频率要比高级调度更高。

进程的挂起态和七状态模型

![七状态模型](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/七状态模型.png)

### 低级调度

低级调度（进程调度），其主要任务是按照某种方法和策略从就绪队列中选取一个进程，将处理机分配给它。

进程调度是操作系统中最基本的一种调度，在一般的操作系统中都必须配置进程调度。

进程调度的频率很高，一般几十毫秒一次。

### 三层调度的联系、对比

![三层调度](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/三层调度.png)

## 进程调度的时机

进程调度（低级调度），就是按照某种算法从就绪队列中选择一个进程为其分配处理机

![进程调度的时机](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/进程调度的时机.png)

临界资源：一个时间段内只允许一个进程使用的资源，各进程需要互斥地访问临界资源。

内核程序临界区一般是用来访问某种内核数据结构的，比如进程的就绪队列（由各就绪进程的pcb组成）。

## 进程调度的方式

* 非剥夺调度方式/非抢占方式：只允许进程主动放弃处理机，在运行过程中即便有更紧迫的任务到达，当前进程依然会继续使用处理机，直到该进程终止或主动要求进入阻塞态。

	实现简单，系统开销小但是无法及时处理紧急任务，适合早起的批处理系统

* 剥夺调度方式/抢占方式：当一个进程正在处理机上执行时，如果有一个更重要或更紧迫的进程需要使用处理机，则立即暂停正在执行的进程，将处理机分配给更重要紧迫的那个进程

	可以优先处理更紧急的进程，也可以实现让各进程按时间片轮流执行的功能（通过时钟中断），适合于分时操作系统，实时操作系统。

## 进程的切换与过程

狭义的进程调度与进程切换

狭义的进程调度（补文字）

![进程的切换与过程](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/进程的切换与过程.png)

## 调度算法的评价指标

### CPU利用率

CPU忙碌的时间占比总时间的比例

利用率=忙碌时间/总时间

### 系统吞吐量

单位时间内完成作业的数量

系统吞吐量=总共完成了多少道作业/总共花了多少时间

### 周转时间

指从昨夜被提交到系统开始，到作业完成为止的这段时间间隔。

包括四个部分：作业在外存后备队列上等待作业调度（高级调度）的时间，进程在就绪队列上等待进程调度（低级调度）的时间，进程在cpu上执行的时间，进程等待io操作完成的时间。后三项在一个作业的整个处理过程中可能发生多次

（作业）周转时间 = 作业完成时间 - 作业提交时间

平均周转时间 = 各作业周转时间之和/作业数

### 带权周转

![带权周转](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/带权周转.png)

平均带权周转时间=各作业带权周转时间之和/作业数

### 等待时间

计算机希望自己的作业尽可能少的等待处理机

等待时间指的是进程/作业处于等待处理机状态时间之和，等待时间越长，用户满意度越低

对于进程来说，等待时间就是指进程建立之后等待被服务的时间之和，在等待I/O完成的期间其实进程也是在被服务的，所以不计入等待时间

对于作业来说，不仅要考虑建立进程后的等待时间，还要加上作业在外存后备队列中等待的时间。

一个作业总共需要被CPU服务多久，被I/O设备服务多久一般也是确定不变的，因此调度算法其实只会影响作业/进程的等待时间，当然，与前面指标相似，也有平均等待时间来评价整体性能

### 响应时间

从用户提交请求到首次产生相应所用的时间

### 总结

![调度算法的评价和指标](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/调度算法的评价和指标.png)

## 各种调度算法

先来先服务（FCFS），短作业优先（SJF），高响应比优先（HRRN）

对于每个算法，考虑：

* 算法思想，算法规则

* 适用于作业调度还是进程调度

* 抢占式，非抢占式

* 优缺点

* 是否会导致饥饿：某进程/作业长时间得不到服务

### First Come First Serve

* 思想，规则：公平，排队，先来先得

* 用于作业/进程调度：用于作业调度时，考虑的是哪个作业先到达后备队列，用于进程调度时，考虑的是哪个进程先到达就绪队列

* 非抢占

* 优点：公平、算法实现简单

* 缺点：排在长作业（进程）后面的短作业需要等待很长时间，带权周转时间很大，对短作业来说用户体验不好，即，FCFS算法对长作业有利，对短作业不利

* 是否会导致饥饿：不会

* 例题，计算：

![FCFS例题](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/FCFS例题.png)

### Shortest Job First

* 思想，规则：追求最少的平均等待时间，最少的平均周转时间，最少的平均带权周转时间

* 算法规则：最短的作业/进程优先得到服务（要求服务时间最短）

* 用于作业/进程调度：既可以用于作业调度，又可以进程调度，用于进程调度时称为短进程优先（SPF，shortest process first）

* SJF和SPF都是非抢占式算法，但是也有抢占式版本：最短剩余时间优先算法（SRTN，shortest remaining time next）

* 优点

* 缺点

* 是否会导致饥饿

* 例题

![SJF例题](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/SJF例题.png)

![SRTN例题1](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/SRTN例题1.png)

![SRTN例题2](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/SRTN例题2.png)

## 计算机















![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.PNG)























