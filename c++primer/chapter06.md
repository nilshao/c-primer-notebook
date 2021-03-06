## 6. 函数

### 6.1. 函数基础

一个典型的函数定义包括以下部分，返回类型，函数名字，由0个或多个形参组成的列表以及函数体。其中，形参以逗号隔开，形参的列表位于一对圆括号之内，函数执行的操作在块中说明，该块称为函数体。

通过调用运算符来执行参数，调用运算符的形式是一对圆括号，他作用于一个表达式，该表达式是函数或者指向函数的指针，圆括号之内是一个用逗号隔开的实参列表，我们用实参初始化函数的形参。调用表达式的类型是函数的返回类型。

函数的调用完成两项工作：一是用实参初始化函数对应的形参，二是将控制权转移给被调用函数，此时，主调函数的执行被暂时中断，被调函数开始执行。执行函数的第一步是隐式地定义并初始化他的形参，

当遇到return语句时函数结束执行过程，和函数调用一样，return语句也完成两项工作：一是返回return语句中的值（如过有），二是将控制权从被调函数转移回主调函数，函数的返回值可能作用于初始化调用表达式的结果，之后继续完成调用所在的表达式的剩余部分。

##### 函数调用

函数调用完成两项工作：一是用实参初始化函数的形参，二是将控制权转移给被调函数。此时，主调函数的执行被暂时中断，被调函数开始执行

##### 形参和实参

实参是形参的初始值，第一个实参初始化第一个形参，第二个实参初始化第二个形参，（用实参初始化函数的形参）以此类推。尽管实参与形参存在对应关系，但是没有规定实参的求值顺序，编译器可以任意可行的顺序对实参求值。

实参的类型必须与相对应的形参类型和数量匹配，因为函数调用规定实参数量与形参数量一致，所以形参一定会被初始化。

##### 函数的形参列表

函数的形参列表可以为空，但不可省略，要想定义一个不带形参的函数，最常用的办法是书写一个空的形参列表，也可以用void表示函数没有形参。

```C++
    void f1(){}
    void f2(void){}
```

任意两个形参都不能同名，而且函数最外层作用域中的局部变量也不能使用与函数形参一样的名字。形参名是可选的，但是由于我们无法使用未命名的形参，所以形参一般都应该有个名字。即使某个形参不被函数体使用，也必须提供实参。


##### 函数返回类型

大多数类型都能用作函数的返回类型，一种特殊的返回类型是void，它表示函数不能返回任何值，函数的返回类型不能是数组类型或函数类型。但是可以是指向数组和函数的指针，6.3.3中介绍如何定义一种特殊的函数，他的返回值是数组的指针或引用，6.7中介绍如何返回指向函数的指针。

#### 局部对象

局部对象：

自动对象：

局部静态对象：

在程序执行路径第一次经过对象定义语句时初始化，并且直到程序终止时蔡晓辉，此期间即使对象所在的函数结束执行也不会对他有影响

### 6.2. 参数传递

如前所述，每次调用函数时都会重新创建它的形参，并用传入的实参对形参进行初始化。和其他变量一样，形参的类型决定了形参和实参交互的方式，如果形参是引用类型，它将绑定到对应的实参上，否则，将实参的值拷贝后赋给形参。

当形参是引用类型时，我们说它对应的参数被引用传递或者函数被传引用调用，和其他引用一样，引用形参也是它绑定的对象的别名，也就是说，引用形参是它对应的实参的别名。当实参的值被拷贝给形参时，形参和实参是两个相互独立的对象，我们说这样的实参被值传递，或者函数被传值调用。

#### 6.2.1. 传值参数

当初始化一个非引用类型的变量时，初始值被拷贝给变量，此时，对变量的改动不会影响初始值。

##### 指针形参

指针的行为和其他非引用类型一样，当执行指针拷贝操作时，拷贝的是指针的值，拷贝之后，两个指针是不同的指针。因为值真实我们可以间接地访问它所指的对象，所以通过指针可以修改他所值对象的值。

#### 6.2.2. 传引用参数

回忆过去所学的知识，我们知道对于引用的操作实际上是作用在引用所引的对象上。引用形参的行为与之相似，通过使用引用形参，允许函数改变一个或多个实参的值，引用形参绑定初始化它的对象，所以函数体中被改变的是传入它的实参。

##### 使用引用避免拷贝

拷贝大的类类型对象或者容器对象比较低效，甚至有的类类型根本就不支持拷贝操作，当某种类型不支持拷贝操作时，函数只能通过引用形参访问该类型的对象。
举例：我们准备比较两个string长度，而string对象可能非常长，所以应该尽量避免直接拷贝他们，这时使用引用形参是比较明智的选择，而且比较长度无需改变string对象的内容。

##### 使用引用返回额外信息

一个函数只能返回一个值，然而有时函数需要同时返回多个值，引用形参为我们一次返回多个结果提供了有效的途径，举个例子，我们定义一个名为

！！！

#### const形参和实参

当形参是const时，要注意关于顶层const的讨论，如前所述，顶层const作用于对象本身。

和其他初始化过程一样，当用实参初始化形参时会忽略掉顶层const，换句话说，形参的顶层const被忽略掉了，当形参有顶层const时，传给他常量对象或者非常量对象都是可以的

##### 指针或引用形参与const

##### 尽量使用常量引用

把函数不会改变的形参定义成普通的引用是一种比较常见的错误。这么做会带给函数的调用者一种误导，即函数可以修改它的实参的值。此外，使用引用而非常量引用也会极大地限制函数所能接收的实参类型，例如我们不能把const对象，字面值或者需要类型转换的对象传递给普通的引用实参。例如：

```C++
    string::size_type find_char(string &s,char c, string::size_type &occurs);
```

则只能将find_char函数作用于string对象，类似下面这样的调用将在编译时发生错误

```
    find_char("hello world", 'o', ctr);
```

还有一个更难发觉的错误，假如其他函数正确地将他们的形参定义成常量引用，那么第二个版本的find_char无法在此类函数中正常使用，例子：我们希望在一个判断string对象是否是句子的函数中使用find_char:

```C++
bool is_sentence(const string &s){
    string::size_type ctr = 0;
    return find_char(s,'.',ctr)==s.size()-1 && ctr == 1;
}
```

如果find_char的第一个形参类型时string&，那么上面这条调用find_char的语句将在编译时发生错误，原因在于s是常量引用，但find_char被不正确地定义成只能接收普通引用。解决该问题的一种思路是修改is_sentence的形参类型，但只是转移了错误而已，结果是is_sentence函数的调用者只能接受非常量string对象。

正确的修改思路是改正find_char函数的形参，或者在is_sentence中定义一个string类型的变量，令其为s的副本，然后把这个string对象传递给find_char。

#### 数组形参

数组两个特殊性质对于我们定义和使用作用在数组上的函数有影响，这两个性质是不允许拷贝数组，以及使用数组时通常会将其转换成指针。因为不能拷贝数组，所以我们不能以值传递的方式使用数组参数，因为数组会被转换成指针，所以当我们为函数传递一个数组时，实际上给传递的是指向数组是指向数组首元素的指针。可以把形参写成类似数组的形式。

``` C++
    void print(const int*);
    void print(const int[]);
    void print(const int[10]);
```

#### main函数处理命令行选项

main函数是演示c++程序如何向函数传递数组的好例子。到目前为止，我们定义的main函数都只有空形参列表：

```C++
    int main(){}
```

然而，有时候我们确实需要给main函数传递实参，一种常见的情况是用户通过设置一组选项来确定函数所要执行的操作。例如，假定main函数位于可执行文件prog之内，我们可以像程序传递下面的选项：

```C++
    prog -d -o ofile data0
```

这些命令行选项通过两个可选的形参传递给main函数

```C++
    int main(int argc, char *argv[]){...}
```

第二个形参argv是一个数组，他的元素是指向c风格字符串的指针：第一个形参argc表示数组中字符串的数量，因为第二个形参是数组，所以main函数也可以定义成：

```C++
    int main(int argc, char **argv)
```

其中argv指向char*。
当实参传给main函数之后，argv的第一个元素指向程序的名字或者一个空字符串，接下来的元素依次传递命令行提供的实参。最后一个指针之后的元素值保证为0。

例子：argc等于5，argv则应包含如下的c风格字符串：

```c++
    argv[0] = "prog";
    argv[1] = "-d";
    argv[2] = "-o";
    argv[3] = "ofile";
    argv[4] = "data0";
    argv[5] = 0;
```

#### 含有可变形参的函数

有时无法提前预知应该向函数传递几个实参。例如我们想要编写代码输出程序产生的错误信息，此时最好用同一个函数实现该功能，以便对所有错误的处理能够整齐划一，然而错误信息的种类不同，所以调用错误输出函数时传递的实参也各不相同。

省略符形参，可以传递可变数量的实参，不过需要注意的是一般只用于与c函数交互的接口程序。

##### initializer_list形参

如果函数的实参数量未知但是全部实参的类型都相同，我们可以使用initializer_list类型的实参，用于表示某种特定类型的值的数组

### 6.3. 返回类型和return语句

两种形式

```C++
    return ;
    return expression;
```

### 6.4. 函数重载

如果同一作用域内的几个函数名字相同但形参列表不同，我们称之为重载函数，这些函数接受的形参类型不一样，但是执行的操作非常类似。调用这些函数时，编译器根据传递的实参类型推断想要的是哪个函数。函数的名字仅仅是让编译器知道它调用的是哪个函数，而函数重载可以在一定程度上减轻起名字记名字的负担。

##### 定义重载函数

有一种典型的数据库应用，需要创建几个不同的函数分别根据名字，电话，账户号码等信息查找记录，函数重载使得我们可以定义一组函数，它们的名字都是lookup，但是查找的依据不同，我们能通过以下形式中的任意一种调用lookup函数：

```C++
    Record lookup(const Account&);
    Record lookup(const Phone&);
    Record lookup(const Name&);
    Account acct;
    Phone phone;
    Record r1 = lookup(acct);
    Record r2 = lookup(phone);
```

其中，虽然我们定义的三个函数各不相同，但它们都有同一个名字。编译器根据实参的类型确定应该调用哪一个函数。对于重载的函数来说，它们应该在形参数量或形参类型上有所不同。在上面的代码中，虽然每个函数都只接受一个函数，但是参数的类型不同。不允许两个函数除了返回类型外其他所有的要素都相同，假设有两个函数，它们的形参列表一样但是返回类型不同，则第二个函数的声明是错误的。

```C++
    Record lookup(const Account&)
    bool lookup(const Account&)     //错误
```

##### 判断两个形参的类型是否相异

有的时候两个形参列表看起来不同但实际上相同，
！！！

##### 重载和const形参

顶层const不影响传入函数的对象，一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来：

```C++
    Record lookup(Phone);
    Record lookup(const Phone);

    Record lookup(Phone*);
    Record lookup(Phone* const);
```

在这两组函数声明中，每一组的第二个生命和第一个是一样的。另一方面，如果形参是某种类型的指针或引用，则通过区分其指向的是常量对象还是非常量对象可以实现函数重载，此时的const是底层的：

```C++

```

##### 调用重载的函数

定义了一组重载函数后，我们需要以合理的实参调用它们。函数匹配是指一个过程，在这个过程中我们把函数调用与一组重载函数中的某一个关联起来，函数匹配也叫重载确定。编译器首先将调用的实参与重载集合中每一个函数的形参进行比较，然后根据比较的结果决定到底调用哪个函数。

重载调用的三种结果：找到最佳匹配并调用，无匹配，二义性调用。

#### 重载与作用域

如果在内层作用域中声明函数名，他将隐藏外层作用域中声明的同名实体，在不同作用域中无法重载函数名。

### 6.5. 特殊用途语言特性

#### 默认实参

某些函数有这样一种形参，在函数的很多次调用中他们都被赋予一个相同的值，此时我们把这个反复出现的值称为函数的默认实参，调用含有默认实参的函数时，可以包含该实参，也可以省略该实参。

！！！ 一旦某个形参被赋予了默认值，他后面所有形参都必须有默认值。

##### 使用默认实参调用函数

想使用默认实餐，只要在调用函数的时候省略该实参。函数调用时实参按照其位置解析，默认实参负责填补函数调用缺少的尾部实参。（只能省略尾部实参）

##### 默认实参声明。

对于函数声明来说，通常的习惯是将其放在头文件中，并且一个函数只声明一次，但是对于多次声明同一个函数也是合法的，不过有一点需要注意，在给定的作用域中一个形参只能被赋予一次默认实参，换句话说，函数的后续声明只能为之前那些没有默认值的形参添加默认实参，切改形参右侧的所有形参都必须有默认值

##### 默认实参初始值

局部变量不能作为默认实参，声明必须出现在函数之外

#### 内联函数和constexpr

把小规模操作定义为函数有好处，但是一次函数调用包括一系列工作：调用前保存寄存器，并在返回时恢复，可能要拷贝实参，程序转向一个新的位置继续执行

##### 内联函数

将函数定义为内联函数（inline），通常就是将他在每个调用点上内联地展开，从而消除了函数运行时的开销。在函数返回类型前加上关键字inline

#### 调试帮助

assert和NDEBUG：

##### assert

在cassert头文件中

##### NDEBUG

### 6.6. 函数匹配

几个重载函数的形参数量相等以及某些形参的类型可以有其他类型转换得来时，重载调用问题。

```C++
    void f();
    void f(int);
    void f(double,double=3.14);
    void f(int, int);

    f(5.6);         //调用
```

##### 确定候选函数和可行函数

1. 选定本次调用对应的重载函数集，集合中的函数称为候选函数。

2. 考察本次调用提供的实参，然后从候选函数中选出能被这组实参调用的函数，称为候选函数

##### 寻找最佳匹配

3. 从可行函数中选择与本次调用最匹配函数，在此过程中逐一检查函数调用提供的实参，寻找形参类型与实参类型最匹配的那个可行函数。

基本思想是实参类型与形参类型越接近，他们匹配的越好。

### 6.7. 函数指针

函数指针指向的是函数而非对象，和其他指针一样，函数指针指向某种特定类型，函数的类型由它的返回类型和形参类型共同决定，与函数名无关。例如：

```C++
    bool lengthCompare(const string & , const string &);    //比较两个string对象的长度
```

该函数的类型是bool，要想声明一个可以指向该函数的指针，只需要用指针替换函数名即可。

```C++
    bool (*pf) (const string & , const string &)
    //pf指向一个函数，该函数的参数是两个const string的引用，返回值是bool类型
```

pf是指针，右侧是形参列表,表示pf指向的是函数，再观察左侧，发现函数的返回类型的布尔值，因此，pf就是一个指向函数的指针，其中该函数的参数是两个const string的引用，返回值是bool类型。

pf两端的括号必不可少，少了括号，pf是一个返回值为bool指针的的函数，返回值是bool*。

##### 使用函数指针

当我们