#include <iostream>

template<typename T>
int inner_product(T &x, T &y){
    if(count(x)!=count(y)){
        std::cout << "Error!"<<std::endl;return 0;}
    int res = 0;
    for(int i=0; i<count(x); ++i){
        res += x[i]*y[i];
        std::cout << x[i]*y[i] <<" ";
    }
    return res;
}

int main(){

    int a[10]={1,3,5,7,9,2,4,6,8,0};
    int b[10]={4,2,3,4,6,3,4,2,3,4};

    std::cout << inner_product(a,b) <<std::endl;

    return 0;
}