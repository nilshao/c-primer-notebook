#include <iostream>
#include <string>

#include <vector>

#include "chain.h"
#include "chainNode.h"
#include "myExceptions.h"

int main(){
    chain<char> L;

    L.insert(0,'e');
    L.insert(0,'d');
    L.insert(0,'c');
    L.insert(0,'b'); 
    L.insert(0,'a');

    std::cout << "original vector L is: " << L << std::endl;
    L.insert(0,'f');
    L.insert(3,'g');
    L.insert(7,'h');
    L.erase(0); 
    L.erase(4);
    std::cout << "changed vector L is: " << L << std::endl;
    
    std::cout << "test get:" << L.get(1)<<std::endl;
/*
    std::cout << "the Size of vector L is: " << L.size()<<std::endl;

    L.setSize(10);
    std::cout << "changed vector L size is: " << L.size() << std::endl;

    L.setSize(8);
    std::cout << "changed vector L size while less than listsize is: " << L.size() << std::endl;
*/
    L.set(2,'k');
    std::cout << "legal set method, L changed to: " << L << std::endl;

    try{ L.set(100,'#'); }
    catch(illegalIndex e){
        std::cout << "ilegal set method, L throw an error: ";
        e.outputMessage();
    }
    //04

    //05
    L.insert(L.size(),'b');
    std::cout <<"vector L: "<< L << std::endl;
    int lastIndex;
    lastIndex = L.lastIndexOf('b');
    std::cout << "last index of char 'b' is: " << lastIndex << std::endl;
    lastIndex = L.lastIndexOf('?');
    std::cout << "last index of char '?' is: " << lastIndex << std::endl;

    //06
    std::cout <<"test overload operator [], L[1] = '" <<  L[1] <<"'"<<std::endl;

    //07
    std::vector<char> v = {'a','b','c','d','e'};
    chain<char> L2(v);
    std::cout << L2 <<std::endl;







}