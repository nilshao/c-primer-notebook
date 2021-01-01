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