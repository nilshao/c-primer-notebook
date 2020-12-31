#include <iostream>

template<typename T>
void fill(T &x, int start, int end, int val){
    int limit=0;
    limit = sizeof(x)/sizeof(x[0]);

    if(start>limit || end >limit || start>limit){
        std::cout << "Out of Range!!" << std::endl;
        return ;
    }
    for(int i = start; i < end; i++){
        x[i] = val;
    } 
}

int main(){

    int a[10]={1,3,5,7,9,2,4,6,8,0};

    fill(a,2,6,100);

    return 0;
}

