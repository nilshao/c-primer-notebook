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

![计算机中存储器的层次结构](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/计算机中存储器的层次结构.jpeg)

（快表机构可以将近期经常访问的页表项副本放到更高速的联想寄存器中）基于局部性原理：
* 在程序装入时，把程序中很快用到的部分装入内存，暂时用不到的放到外存。  
* 在程序执行时，当所访问信息不在内存时，由操作系统负责将所需信息从外存调入内存，然后继续执行程序。
* 若内存空间不够，由操作系统负责将内存中暂时用不到的信息换出到外存
* 在操作系统的管理下，在用户看来似乎有一个比实际内存大得多的内存，这就是**虚拟内存**

易混淆知识点：

虚拟内存的**最大容量**是由计算机的地址结构（CPU寻址范围）确定的

虚拟内存的**实际容量**=min（内存和外存容量之和，CPU寻址范围）

**例题：**

某计算机是32位的，按字节编址，内存大小为512MB，外存大小为2GB，则虚拟内存的**最大容量**为2^32B = 4GB

虚拟内存的**实际容量**为min（2^32B, 512MB+2GB) = 2.5GB

即：实际的物理内存大小并没有变，只是在逻辑上进行了扩充

## 虚拟内存的特征

**多次性：** 无需在作业运行时一次性全部装入内存，而是允许被分成多次调入内存。

**对换性：** 在作业运行时无需一直常驻内存，而是允许在作业运行过程中，将作业换入、换出

**虚拟性：** 从逻辑上扩充了内存的容量，使用户看到的内存容量远大于实际的容量

## 如何实现虚拟内存技术

虚拟内存技术，允许一个作业分多次掉入内存，如果采用连续分配方式，会不方便实现，因此虚拟内存的实现建立在**离散分配**的内存管理方式基础上

相似：

![如何实现虚拟内存技术](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/如何实现虚拟内存技术.jpeg)

区别：

在程序执行的过程中，当所访问的信息不在内存时，由操作系统负责将所需信息从外存调入内存然后继续执行程序。-> “请求”调页或“请求”调段功能。

若内存不够，由操作系统负责将内存中暂时用不到的信息换出到外存。 -> 页面置换，段置换功能。

## 请求分页管理方式

请求分页存储管理和基本分页存储管理的主要区别：

1. 在程序执行过程中，当访问信息不在内存时，由操作系统负责将所需要的信息从外存调入内存，然后继续执行程序

    即：操作系统要提供**请求调页功能**，将缺失页面从外存调入到内存

2. 若内存空间不够，由操作系统负责将内存中暂时用不到的信息换出到外存。
    
    即：操作系统提供**页面置换功能**，将暂时用不到的页面换出到外存。

![请求分页管理方式](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/请求分页管理方式.jpeg)

### 页表机制

![页表机制](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/页表机制.jpeg)

### 缺页中断机构

![缺页中断机构](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/缺页中断机构.jpeg)

![缺页中断机构2](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/缺页中断机构2.jpeg)


### 地址变换机构

![地址变换机构](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/地址变换机构.png)

新增步骤：

1. 请求调页（查找页表项时进行判断）
2. 页面置换（需要时调入页面，但没有空闲内存块时进行
3. 需要修改请求页表中新增的表项

![地址变换机构2](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/地址变换机构2.png)

![请求分页中的地址变换过程](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/请求分页中的地址变换过程.png)

在具有快表机构的请求分页系统中，访问一个逻辑地址时，若发生缺页，则地址变换步骤：

查快表（未命中）-- 查慢表（发现未调入内存）-- 调页（调入的页面对应的表项会直接加入快表） -- 查快表（命中） -- 访问目标内存单元

### 总结

![请求分页管理方式](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/请求分页管理方式.png)

## 页面置换算法

回忆：”若内存空间不够，操作系统负责将内存中暂时用不到的信息换出到外存“ ————由页面置换算法来决定应该换出哪个页面

![页面置换算法](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/页面置换算法.png)

由于页面的换入和换出需要磁盘I/O，会有较大的开销，因此好的页面置换算法应该追求更少的缺页率

### 最佳置换算法OPT

![最佳置换算法OPT](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/最佳置换算法OPT.png)

整个过程**缺页中断**发生了**9**次，**页面置换**发生了**6**次。缺页时未必发生页面置换，若还有可用的空闲内存块，就不用进行页面置换。

缺页率 = 9/20 = 45%

最佳置换算法是无法实现的，因为实际上无法预知接下来会访问到哪个页面。

### 先进先出置换算法FIFO




## 页面分配策略


![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter3/.PNG)

