# 第四章 第一节 

## 文件管理简介

作为系统资源的系统管理者，文件管理是操作系统提供的功能之一。
文件内部，文件之间如何组织？怎么能方便用户、应用程序使用文件？文件数据怎么存放在外存上？

### 文件的属性：

* 文件名：同一目录下不能有重名文件

* 标识符：一个系统内各个文件标识符唯一，对用户来说无可读性，只是操作系统使用的

* 类型

* 位置：文件存放路径，在外存中的地址

* 大小，创建时间，上次修改时间

* 保护信息：对文件进行保护的访问控制

### 文件内部数据怎样组织起来？

无结构文件，又称流式文件

有结构文件

![文件组织结构](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/文件组织结构.png)

### 文件之间的组织

“目录”

### 操作系统应该向上提供哪些共呢蝈 

创建文件，读文件，写文件，打开文件，关闭文件，删除文件

几个基本操作可以组成更复杂的操作，比如复制文件

### 文件如何存在外存？

和内存被分为内存块类似，外存也会被分为块/磁盘块/物理块，每个磁盘块大小相等，每块一般包含2的整数幂个地址。文件逻辑地址也可以被分为逻辑块号，块内地址。操作系统将逻辑地址转换为外存内的物理地址 

### 其他功能

文件共享，文件保护

## 文件的逻辑结构

逻辑结构：在用户看起来，文件内部数据结构如何组织起来

### 无结构文件

又称流式文件

### 有结构文件

又称记录式文件，由一组相似的记录组成，每一条记录又由若干个数据项组成。一般来说每条记录又一个数据项可以作为关键字，根据各条记录长度又可以分为定长记录和可变长记录。

 ![有结构文件逻辑结构](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/有结构文件逻辑结构.png)




### 顺序文件

文件中的记录一个接一个地顺序排列，分顺序存储和链式存储。顺序文件一般指物理上顺序存储的顺序文件，增加/删除一个记录比较困难

顺序文件：串结构，记录之间的顺序与关键字无关，通常按存入时间决定顺序；顺序结构：记录之间的顺序按照关键字排列。

能否随机存取，快速查找：

![顺序文件随机存取快速查找](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/顺序文件随机存取快速查找.png)


### 索引文件

对于可变长记录文件需要快速查找，如何解决？建立索引表加快文件检索速度，文件中的这些记录在物理上可以离散的存放。索引表本身是鼎昌的顺序文件 

### 索引顺序文件

索引文件的缺点：每个记录都对应一个索引表项，因此索引表可能太大。改进：**一组记录**对应一个索引表项，“分组的思想”




![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/.jpeg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/.jpg)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/.JPG)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/.png)

![](https://github.com/nilshao/cpp-notebook/raw/master/operation_system/images/chapter4/.PNG)
































