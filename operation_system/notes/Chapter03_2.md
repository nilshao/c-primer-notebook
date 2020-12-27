# 第三章 第二节 虚拟内存

内存空间的扩充：覆盖技术，交换技术，**虚拟存储技术**

![虚拟存储技术](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/虚拟存储技术.jpeg)

## 传统存储管理方式的特征、缺点

![传统存储管理方式的特征缺点](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/传统存储管理方式的特征缺点.jpeg)

* 一次性：作业必须一次性全部装入内存后才能运行，造成两个问题
  * 作业很大时，不能全部装入内存，这样就导致大作业无法运行
  * 当大量作业要求运行时，内存也无法容纳所有作业，因此只有少量作业能运行，导致多道程序并发度下降
  
* 驻留性：一旦作业被装入内存，就会一直驻留在内存中，直至作业运行结束，事实上，在一个时间段内，只需要访问作业的一小部分数据即可，这就导致了内存中会驻留大量的、暂时用不到的数据，浪费了内存资源。

## 局部性原理

依据局部性原理，提出了虚拟内存技术。

**时间局部性：** 如果执行了程序中的某条指令，那么不久后这条指令很可能会再次执行，如果某个数据被访问过，不久之后可能会再次被访问（因为程序中存在大量循环）

**空间局部性：** 如果程序访问了某个存储单元，不久之后，其附近的存储单元可能被访问（因为很多数据在内存中是被连续存放的，程序的指令也是在内存中按顺序存放的）

**如何应用**局部性原理：**高速缓冲技术**，将近期会频繁访问的数据放到更高速的存储器中，暂时用不到的放在更低速的存储器中。




![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.PNG)

