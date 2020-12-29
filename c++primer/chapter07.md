## 类

类的基本思想是数据抽象和封装，数据抽象是一种依赖于接口和实现分离的编程技术，类的接口包括用户所能执行的操作：类的实现则包括类的数据成员，负责接口实现的函数体以及定义类所需的各种私有函数。封装实现了类的接口和实现的分离。封装后的类隐藏了他的实现细节，也就是说，类的用户只能使用接口而无法访问实现部分。类想要实现数据抽象和封装，首先需要定一个抽象数据类型，在抽象数据类型中，由类的设计者负责考虑类的实现过程：使用该类的程序员则只需要抽象地思考类型做了什么，而无需了解类型的工作细节。

### 定义抽象数据类型

在第一章中使用的Sales_item类是一个抽象数据类型，我们通过他的接口来使用一个Sales_item对象。我们不能访问Sales_item对象的数据成员，实际上，我们甚至根本不知道这个类有哪些数据成员。与之相反，Sales_data类不是一个抽象数据类型，它允许类的用户直接访问它的数据成员，并且要求由用户来编写操作，。要想把Sales_data变成抽象数据类型。我们需要定义一些操作以供类的用户使用。一旦Sales_data定义了他自己的操作，我们就可以封装(隐藏)他的数据成员了。

#### 设计Sales_data类

我们最终目的是令Sales_data支持与Sales_item类完全一样的操作集合，Sales_item类有一个名为isbn的成员函数，并且支持+,=,+=,>>和<<运算符。我们将在14章学习如何自定义运算符，现在我们先为这些运算定义普通的函数形式。执行加法和IO的函数不作为Sales_data的成员，相反的，我们将其定义为普通函数：执行复合赋值运算的函数是成员函数，Sales_data类无需专门定义赋值运算。

综上所述，Sales_data的接口应包含以下操作：

+ 一个isbn成员函数，用于返回对象的ISBN编号
+ 一个combine成员函数，用于讲一个Sales_data对象加到另一个对象上
+ 一个名为add的函数，执行两个Sales_data对象的加法
+ 一个read函数，将数据从istream读入到Sales_data对象中
+ 一个print函数，将Sales_data对象的值输出到ostream

##### 使用改进的Sales_data类

在考虑如何实现我们的类之前，首先来看看应该如何使用上面这些接口函数，举个例子，我们使用这些函数编写书店程序的另外一个版本，其中不再使用Sales_item对象，而是使用Sales_data对象：

```C++
    Sales_data total;
    if(read(cin, total)){
        Sales_data trans;
        while(read(cin, trans)){
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(cout, total)<< endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else{
        cerr << "No data ?!" << endl;
    }
```

一开始我们定义了一个Sales_data对象用于保存实时的汇总信息，在if条件内部，调用read函数将第一条交易读入到total中，这里的条件部分与之前我们使用 >> 运算符的效果是一样的。 read函数返回它的流参数，而条件部分负责检查这个返回值，如果read函数失败，程序将直接跳转到else语句并输出一条错误信息。

如果检测到了读入数据，我们定义变量trans用于存放每一条交易。while语句的条件部分同样是检查read函数的返回值，只要输入操作成功，条件就被满足，意味着我们可以处理一条新的交易。

在while内部，我们分别调用total和trans的isbn成员以比较他们的ISBN编号。如果total和trans知识的是同一本书，我们调用

#### 定义改进的Sales_data类

##### 定义成员函数



#### 构造函数

每个类都分别定义了它的对象被初始化的方式，类通过一个或几个特殊的成员函数来控制其对象的初始化过程，这些函数叫构造函数，任务是初始化类对象的数据成员，无论何时只要类的对象被创建，就会执行构造函数。

构造函数的名字和类名相同，但是没有返回类型，除此之外类似于其他的函数，构造函数也有一个可能为空的参数列表和一个函数体。类可以包含多个构造函数，和其他重载函数差不多，不同的构造函数之间必须在参数数量或参数类型上有所区别。不同于其他成员函数，构造函数不能被声明成const的，当我们创建类的一个const对象时，知道构造函数完成初始化过程，对象才能真正取得其常量属性，因此，构造函数在const对象的构造过程中可以向其写值。

##### 合成的默认构造函数

##### 某些类不能依赖于合成的默认构造函数

合成的默认构造函数只适合很简单的类，比如这个Sales_data版本，对于一个普通的类来说，必须定义它自己的默认构造函数，三个原因：一是编译期只有在发现类不包含任何构造函数的情况下才会替我们生成一个默认的构造函数。

#### 拷贝，赋值和析构

除了定义类的对象如何初始化之外，类还需要控制拷贝，赋值和销毁对象时发生的行为，对象在几种情况下会被拷贝，如我们初始化变量以及以值的方式传递或返回一个对象等，当我们使用赋值运算符时会发生对象的赋值操作，当对象不再存在时将执行销毁操作，比如一个局部对象会在创建它的块结束时被销毁，当vector对象销毁时存储在其中的对象也会被销毁。

如果我们不主动定义这些操作，则编译器将替我们合成他们。

##### 某些类不能依赖于合成的版本

对于某些类来说合成的版本无法正常工作，特别是当类需要分配类对象之外的资源时，合成的版本常常会失效。12章将介绍C++程序是如何分配和管理动态内存的，13.1.4中我们将会看到，管理动态内存的类通常不能依赖与上述操作的合成版本。

### 访问控制与封装

我们已经定义了接口，但是没有封装，用户可以直达Sales_data对象的内部并且控制它的具体实现细节，用访问说明符加强类的封装性。

+ 定义在public说明符之后的成员在整个程序内可被访问，public成员定义类的接口
+ 定义在private说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，private部分封装(即隐藏了)类的实现细节

修改后的新形式：

```C++
class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(const std::string &s: bookNo(s)){}
    Sales_data(std::istream&);
    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data&);
private:
    double avg_price() const{
        return units_sold ? revenue/units_sold : 0;
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

一个类可以包含0个或多个访问说明符，而且对于某个访问说明符能出现多少次也没有严格规定，每个访问说明符指定了接下来的成员的访问级别，其有效范围直到出现下一个访问说明符或者到达类的结尾处为止。

##### class 和 struct 关键字

struct和class的默认访问权限不太一样。类可以在他的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于类定义的方式，如果我们使用struct关键字，则定义在第一个访问说明符之前的成员是public的，相反，如果是class关键字，这些成员是private的。因此当我们希望定义的类的所有成员是public时，使用struct，反之，如果希望成员是private的，使用class。

#### 友元

private的数据成员，print,add,read无法正常编译了，因为他们是类的一部分，但不是类的公有成员。类可以允许其他类或者函数访问他的非公有成员，方法是令其他类或者函数成为他的友元，如果类想把一个函数作为他的友元，只需要增加一条以friend关键字开始的函数声明语句。

```C++
class Sales_data{
//为 Sales_data 的非成员函数所做的友元声明
friend Sales_data add(const Sales_data& , const Sales_data&);
friend std::istream &read(std::istream&, Sales_data& );
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
    // ...
private:
    // ...
};
//Sales_data接口的非成员组成部分的声明
friend Sales_data add(const Sales_data& , const Sales_data&);
friend std::istream &read(std::istream&, Sales_data& );
friend std::ostream &print(std::ostream&, const Sales_data&);
```

友元声明只能出现在类定义的内部但是具体位置不限。

##### 友元的声明

### 类的其它特性

### 类的作用域

### 构造函数再探

### 类的静态成员