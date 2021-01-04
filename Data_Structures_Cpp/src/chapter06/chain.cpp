#include <iostream>
#include <string>
#include <vector>

#include "chain.h"
#include "chainNode.h"
#include "arrayList.h"
#include "extendedChain.h"

void Exercise(int const n){
    std::cout << "-------------"<< "Question "<< n  << "-------------" << std::endl;
}
template<class T> 
void arrayList2Chain(arrayList<T> const & theArray,chain<T>& theChain){
    
    for(int i=0; i< theArray.size(); i++){
        T ele = theArray.get(i);
        theChain.insert(theChain.size(), ele);
    }

}

template<class T> 
void Chain2arrayList(chain<T>const & theChain,arrayList<T> & theArray){
    
    for(int i=0; i< theChain.size(); i++){
        T ele = theChain.get(i);
        theArray.insert(theArray.size(), ele);
    }

}
/*
template<class T>
extendedChain<T> meld(extendedChain<T> m1, extendedChain<T> m2){
    extendedChain<T> m;
    
    int min = (m1.size() < m2.size())? m1.size() : m2.size();
    for(int i = 0; i < min; ++i){
        std::cout<< " "<< m1[i] << " " << m2[i];
        std::cout << " " << m.size() ;
        m.push_back(m1[i]);
        std::cout << " " << m.size() <<std::endl;

        m.push_back(m2[i]);
        std::cout << m <<std::endl;
    }
    return m;
} 
*/
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
    Exercise(05);
    L.insert(L.size(),'b');
    std::cout <<"vector L: "<< L << std::endl;
    int lastIndex;
    lastIndex = L.lastIndexOf('b');
    std::cout << "last index of char 'b' is: " << lastIndex << std::endl;
    lastIndex = L.lastIndexOf('?');
    std::cout << "last index of char '?' is: " << lastIndex << std::endl;

    //06
    Exercise(06);
    std::cout <<"test overload operator [], L[1] = '" <<  L[1] <<"'"<<std::endl;

    //07, 08
    Exercise(07);
    std::vector<char> v1 = {'a','b','k','c','e','h','b'};
    std::vector<char> v2 = {'a','b','*','c','e','h','b'};
    chain<char> L1(v1);
    chain<char> L2(v2);
    std::cout << "chain l is: " << L <<std::endl;
    std::cout << "chain l1 is: "<< L1 <<std::endl;
    std::cout << "chain l2 is: "<< L2 <<std::endl;
  
    std::cout << "test overload operator ==," << "L == L1? " << (L == L1) << std::endl;
    std::cout << "test overload operator ==," << "L == L2? " << (L == L2) << std::endl;
    std::cout << "test overload operator !=," << "L != L1? " << (L != L1) << std::endl;
    std::cout << "test overload operator !=," << "L != L2? " << (L != L2) << std::endl;

    //09
    Exercise(9);
    std::vector<char> w1 = {'a','b','c','d','e','f','g'};
    std::vector<char> w2 = {'a','b','c','d','e','f','g'};
    std::vector<char> w3 = {'a','b','d','c','e','h','b'};
    std::vector<char> w4 = {'a','b','c'};

    chain<char> Word1(w1);
    chain<char> Word2(w2);
    chain<char> Word3(w3);
    chain<char> Word4(w4);
    std::cout << "word1 is: "<< Word1 << std::endl;
    std::cout << "word2 is: "<< Word2 << std::endl;
    std::cout << "word3 is: "<< Word3 << std::endl;
    std::cout << "word4 is: "<< Word4 << std::endl;
    std::cout << "w1 < w2? " << (w1<w2) << std::endl;
    std::cout << "w2 < w3? " << (w2<w3) << std::endl;
    std::cout << "w3 < w2? " << (w3<w2) << std::endl;
    std::cout << "w4 < w1? " << (w4<w1) << std::endl;
    std::cout << "w1 < w4? " << (w1<w4) << std::endl;


    //10 swap
    
    Exercise(10);
    std::vector<char> v3 = {'a','b','k','c','e','h','b'};
    std::vector<char> v4 = {'g','d','h','e','k','b','l'};
    chain<char> L3(v3);
    chain<char> L4(v4);
    std::cout << L3 << std::endl;
    std::cout << L4 << std::endl;
    L3.swap(L4);
    std::cout << L3 << std::endl;
    std::cout << L4 << std::endl;

    //11: arrayList to chain
    Exercise(11);

    arrayList<char> f(5);
    f.insert(0,'e');
    f.insert(0,'d');
    f.insert(0,'c');
    f.insert(0,'b');
    f.insert(0,'a');

    std::cout << "arrayList f is: " << f << std::endl;
    chain<char> f_chain(10);
    arrayList2Chain(f,f_chain);
    std::cout <<"changed to chain: "<<f_chain<<std::endl;
    std::cout <<f_chain.size()<<std::endl;

    arrayList<char> f_array(10);
    Chain2arrayList(f_chain,f_array);
    std::cout <<"changed to array: "<<f_array<<std::endl;
 //   std::cout <<f_chain.size()<<std::endl;

    chain<char> f_chain_2(10);
    f_chain_2.arrayList2Chain(f_array);
    std::cout << f_chain_2 << std::endl;

    //14
    Exercise(14);
    std::cout <<"the list before left shift: " << f_chain_2 << std::endl;
    f_chain_2.leftShift(1) ;
    std::cout <<"the list after left shift for 1 position: "<< f_chain_2 <<std::endl;
    f_chain_2.leftShift(5) ;
    std::cout <<"the list after left shift too much! "<< f_chain_2 <<std::endl;

    //reverse 1:迭代

    //reverse 2:递归

    //17
    Exercise(17);
    std::vector<char> va = {'a','c','e','g','i'};
    std::vector<char> vb = {'b','d','f','h','j','k','l'};
    extendedChain<char> a(va);
    extendedChain<char> b(vb);

    extendedChain<char> m1(10);
    std::cout << "vector a is: " << a << std::endl;
    std::cout << "vector b is: " << b << std::endl;
    std::cout << "vector m is: " << m1 << std::endl;

    Exercise(18);
    chain<char> c1(va);
    chain<char> c2(vb);
    std::cout << "chain 1 is: "<< c1 <<std::endl;
    std::cout << "chain 2 is: "<< c2 <<std::endl;
    std::cout << c1.meld(c2) << std::endl;

}