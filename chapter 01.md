## 1. 第一章 开始

### 1.1. 编写一个简单的C++程序V

多个函数，其中1个必须是main函数。函数四个部分：返回类型，函数名，形参列表，函数体。main函数返回类型必须是int，函数返回值类型必须与函数的返回类型相容。

大多数系统中，main的返回值被用来指示状态。返回值0表明成功，非0的返回值的含义由系统定义，通常用来指出错误类型。

### 1.2. 初识输入输出

很多使用iosstream库，isstream和osstream分别表示输入流和输出流。一个流就是一个字符序列，是从IO设备读出或写入IO设备的。术语“流stream”想要表达的是，随着时间推移，字符是顺序生成或消耗的。

#### 1.2.1. 标准输入输出对象

4个IO对象，cin：标准输入。cout：标准输出。cerr：输出警告和错误消息，标准错误。clog：用于输出程序运行时的一般性信息。

#### 1.2.2. 一个使用IO库的程序

```C++
#include<iosstream>

int main(){
    std::cout<< "Enter 2 nums" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout<< "v1: "<<v1<<" v2: "<< v2<<std::endl;>
}

```

#### 1.2.3. 向流写入数据

略

#### 1.2.4. 使用标准库中的名字

std的命名空间(namespace)，::是作用域运算符

#### 1.2.5. 从流读取数据

输入运算符>>接收一个istream作为其左侧运算对象

### 1.3. 注释

略

### 1.4. 控制流

#### 1.4.1. while语句

```C++
while(condition)
    statement
```

前缀递增运算符(++i)

#### 1.4.2. for语句

#### 1.4.3. 读取数量不定的输入数据

```C++
#include <iostream>
int main(){
    int sum = 0, value = 0;
    while (std::cin >> value)
        sum += value;
    std::cout<< "sum is: " << sum << std::endl;
    return 0;
}
```

从标准输入读取下一个数，保存在value中。输入运算符返回其左侧运算对象，此例中是std::cin。使用istream对象作为条件时，其效果是检测流的状态，如果流是有效的，未遇到错误，则检测成功。若遇到文件结束符，或遇到无效输入时，istream对象变为无效，无效状态的istream对象会使条件变为假。

#### 1.4.4. if语句

### 1.5. 类简介

在C++中，我们通过定义一个类(class)来定义一个数据结构(data structure)。一个类定义了一个类型，以及与其关联的一组操作。三个问题：类名是什么，在哪里定义的，支持什么操作。

对于书店程序来说，假定类名Sales_item，头文件Sales_item.h中已经定义了这个类。使用标准库设施，必须包含相关头文件，类似的，也需要使用头文件来访问为自己的应用程序所定义的类，标准库头文件通常不带后缀。

#### 1.5.1. Sales_item类

Sales_item类定义了一个名为Sales_item的类型。与内置类型一样，我们可以定义类类型的变量。

```C++
    Sale_item item;
```

表达item是一个Sale_item类型的对象。除了定义Sales_item类型的变量之外，还可以：

+ 调用一个名为isbn的函数从一个Sales_item对象中提取ISBN书号
+ 用输入运算符(>>)和输出运算符(<<)读，写Sales_item类型的对象
+ 用赋值运算符(=)讲一个Sales_item对象的值赋予另一个Sales_item对象
+ 用加法运算符
+ 用复合赋值运算符

##### 读写Sales_item

##### Sales_item对象的加法

#### 1.5.2. 初识成员函数

将两个Sales_item对象相加的程序首先应该检查两个对象是否具有相同的ISBN：

```C++
#include <iostream>
#include "Sales_item.h"
int main(){
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if(item1.isbn() == item2.isbn()){
        std::cout<< item1+item2 << std::endl;
        return 0;
    }else{
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
}

```

##### 什么是成员函数？

```
    item1.isbn() == item2.isbn();
```

调用了名为isbn的成员函数，成员函数是定义为类的一部分的函数。使用点运算符来表达我们需要“名为item1的对象的isbn成员”。点运算符只能用于类类型的对象，其左侧运算对象必须是一个类类型的对象，右侧运算对象必须是该类型的一个成员名，运算结果为右侧运算对象指定的成员。当用点运算符访问一个成员函数时，通常我们是想调用该函数，我们使用调用运算符()，来调用一个函数，调用运算符是一对圆括号，里面放置实参列表（可能为空），本例中成员函数isbn不接受参数。

### 1.6. 书店程序

现在我们准备好完成书店程序：

我们需要从一个文件中读取销售记录，生成每本书的销售报告，显示售出册数，总销售额和平均售价，假设每个ISBN书豪的所有销售记录在文件中是聚在一起保存的。

我们的程序将每个ISBN所有数据合并起来，存入名为total的变量中，我们使用另一个名为trans