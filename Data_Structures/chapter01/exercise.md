# chapter 01

## 1

```C++

#include <iostream>

void swap(int &x, int &y){
    int tmp = x;
    x=y;
    y=tmp;
}

int main(){
    int a = 10, b = 4;
    swap(a,b);
    std::cout << a << " " << b<< std::endl;

    return 0;
}

```

## 2
```C++

//exercise 2
template<typename T>
int count(T &x){
    int num=0;

    num = sizeof(x)/sizeof(x[0]);

    return num;
}

int main(){
    int a[5]={1,3,5,6,7};
    std::cout << count(a) <<std::endl;

    return 0;
}

```