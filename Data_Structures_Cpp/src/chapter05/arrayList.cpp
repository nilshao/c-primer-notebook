#include <iostream>
#include <string>

#include "arrayList.h"
#include "linearList.h"
#include "myExceptions.h"
void Exercise(const int n){
    std::cout << "-------------"<< "Question "<< n  << "-------------" << std::endl;
}
int main(){
    
    linearList<double> *x = new arrayList<double>(20);
    arrayList<int> y(2), z;
    
       // test capacity
    std::cout << "Capacity of x, y and z = "
        << ((arrayList<double>*) x)->capacity() << ", "
        << y.capacity() << ", "
        << z.capacity() << std::endl;


   // test size
    std::cout << "Initial size of x, y, and z = "
        << x->size() << ", "
        << y.size() << ", "
        << z.size() << std::endl;

    //02
    Exercise(2);
    arrayList<char> f(5);
    f.insert(0,'e');
    f.insert(0,'d');
    f.insert(0,'c');
    f.insert(0,'b');
    f.insert(0,'a');
    std::cout <<"original arrayList is: "<< f <<std::endl;
    f.insert(0,'f');
    f.insert(3,'g');
    f.insert(7,'h');
    f.erase(0);
    f.erase(4);
    std::cout <<"changed arrayList is: "<< f <<std::endl;

    //03
 //   Exercise(3);

    //04
 //   Exercise(4);
    //05

    //06


    //07
    Exercise(07);
    std::cout << "vector f is: "<< f << std::endl;
    std::cout << "output using overloaded[]: ";
    for(int i =0; i<f.size(); i++){
        std::cout << f[i]<<" ";
    }
    std::cout <<std::endl;

    //08
    Exercise(8);
    y.insert(0,3);
    y.insert(0,2);
    y.insert(0,1);
    arrayList<int> y1(2);
    y1.insert(0,3);
    y1.insert(0,2);
    y1.insert(0,1);
    bool flag1 = (y == y1);
    bool flag2 = (y != y1);
    
    std::cout << "vector y is: "<< y <<std::endl;
    std::cout << "vector y1 is: "<< y1 <<std::endl;
    std::cout << "equeality is: "<< flag1 << std::endl;
    //09
    Exercise(9);
    std::cout << "inequeality is: "<< flag2 << std::endl;
    
    //11
    y.push_back(4);
    std::cout << "vector y after push_back is: "<< y <<std::endl;
    //12
    Exercise(12);
    std::cout << "vector y is: "<< y <<std::endl;
    y.pop_back();
    std::cout << "vector y after pop_back is: "<< y <<std::endl;
    
    //14
    std::cout << "vector y is: " << y << std::endl;
    std::cout << "vector y's capacity is: " ;


    return 0;

}