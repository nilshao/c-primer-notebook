#include <iostream>

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