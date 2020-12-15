# 第二章 第二节 处理机调度

## 调度，处理机调度的概念

有一堆任务要处理，但是资源有限，这些事情没办法同时处理，就需要确定某种规则来决定处理这些任务的顺序，这就是调度

在多道程序系统中，进程的数量往往多于处理机的个数，这样不可能同时并行地处理各个进程，处理机调度就是从就绪队列中按照一定的算法选择一个进程并将处理机分配给它运行，以实现进程的并发执行

## 调度的三个层次：高级调度。

由于内存空间有限，有时无法将用户提交的作业全部放入内存，因此就需要确定某种规则来决定将作业调入内存的顺序。

高级调度（作业调度）：按照一定的原则从外存上处于后备队列的作业中挑选一个（或多个）作业，给他们分配内存等必要资源，并建立相应的进程（建立pcb），以使他们获得竞争处理机的权利。

高级调度是外存与内存之间的调度，每个作业只调入一次，调出一次。掉入作业时会建立相应的pcb，调出时撤销pcb。高级调度主要是指掉入的问题，因为只有掉入时机需要操作系统来确定，但调出的时机必然是作业运行结束才调出。

## 调度的三个层次：中级调度

引入了虚拟存储技术之后，可将暂时不能运行的进程调至外存等待，等它重新具备了运行条件且内存又稍有空闲时，再重新调入内存。

这么做的目的是为了提高内存利用率和系统吞吐量。
暂时调到外存等待的进程状态为挂起状态。值得注意的是，PCB并不会一起调到外存，而是会常驻内存，pcb中会记录进程数据在外存中的存放位置，进程状态等信息，操作系统通过内存中的pcb来保持对各个进程的管理、监控，被挂起的进程pcb会被放到挂起队列中


中级调度（内存调度），就是要决定将哪个处于挂起状态的进程重新调入内存。
一个进程可能被多次调入调出内存，因此中级调度发生的频率要比高级调度更高。

进程的挂起态和七状态模型

## 调度的三个层次：

![七状态模型](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/七状态模型.png)


























![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.PNG)























