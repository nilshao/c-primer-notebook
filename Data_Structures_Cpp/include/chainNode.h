#ifndef chainNode_
#define chainNode_

#include "myExceptions.h"

template<class T>
struct chainNode{
    //element
    T element;
    chainNode<T> *next;

    //方法
    chainNode(){};
    chainNode(const T& element){this->element = element;}
    chainNode(const T& element, chainNode<T>* next)
        {this->element = element; this->next = next;}
};

#endif