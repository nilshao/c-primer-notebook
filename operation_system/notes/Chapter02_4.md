# 第二章 第四节 死锁

## 死锁的概念

### 死锁的概念

在并发环境下，各个进程因为竞争资源而造成的一种互相等待对方手里的资源，导致各个进程都阻塞，都无法向前推进的现象，就是死锁。发生死锁后若无外力干涉，这些进程都将无法推进。

### 死锁，饥饿，死循环

死锁：“死锁概念”，至少是两个或以上的进程才能发生死锁，一定是在阻塞态

饥饿：可以是只有一个进程发生饥饿，长时间得不到资源，可能是在阻塞态，可能是在就绪态

死循环：程序执行过程中一直跳不出某个循环的现象。

### 死锁产生的必要条件

产生死锁必须同时满足以下四个条件：

1. 互斥条件：只有必须对互斥使用的资源争抢才会导致死锁

2. 不剥夺条件：进程所获得的资源在未使用完之前，不能由其他进程强行夺走，只能主动释放

3. 请求和保持条件：进程已经保持了至少一个资源，但又提出了新的资源请求，而该资源又被其他进程占有，此时请求进程被阻塞，但又对自己已有的资源保持不放

4. 循环等待条件：存在一种进程资源的循环等待链，链中的每一个进程已获得的资源同时被下一个进程所请求。

### 什么时候发生死锁：

1. 对系统资源的竞争。

![什么时候发生死锁](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/什么时候发生死锁.png)

### 死锁的处理策略

1. 预防死锁：破坏死锁产生的四个必要条件中的一个或几个

2. 避免死锁，用某种方法防止系统进入不安全状态

3. 死锁的检测和解除：允许死锁的发生，不过操作系统会负责检测出死锁的发生，然后采取某种措施解除死锁


### 预防死锁


























![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter2/.PNG)























