#include <iostream>
//size
template<typename T>
int size(T &x){
    int num=0;

    num = sizeof(x)/sizeof(x[0]);

    return num;
}

//exercise 2
template<typename T>
int count(T &x, const int val){
    int num=0,res=0;

    num = sizeof(x)/sizeof(x[0]);
    for(int i=0; i<num; i++){
        if(x[i]==val){
            res++;
        }
    }
    return res;
}

//exercise 3
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

//exercise 4
template<typename T>
int inner_product(T &x, T &y){
    if(size(x)!=size(y)){
        std::cout << "Error!"<<std::endl;return 0;}
    int res = 0;
    for(int i=0; i<size(x); ++i){
        res += x[i]*y[i];
        std::cout << x[i]*y[i] <<" ";
    }
    return res;
}



//print array
template<typename T>
void print_array(const T&x)
{
    for(int i=0;i<sizeof(x)/sizeof(x[0]);i++){
        std::cout <<x[i]<<" ";
    }
    std::cout << std::endl;
}

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    std::cout << "size: " << size(a) <<std::endl;
    std::cout << "count of 2: "<<count(a,2)<<std::endl;
    print_array(a);

    fill(a,0,5,2);
    std::cout << "count of 2: "<<count(a,2)<<std::endl;

   // print_array(a);

    int b[10]={4,2,3,4,6,3,4,2,3,4};
    print_array(b);
    std::cout << inner_product(a,b) <<std::endl;
    return 0;
}