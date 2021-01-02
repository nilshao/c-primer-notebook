#include <iostream>
#include <string>

#include "arrayList.h"
#include "linearList.h"

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


        return 0;

}