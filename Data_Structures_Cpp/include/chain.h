// chapter06
#ifndef chain_
#define chain_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "chainNode.h"
#include "linearList.h"
#include "myExceptions.h"

template<class T>
class chain : public linearList<T>{
protected:
    void checkIndex(int theIndex) const;        //若索引theIndex无效，则抛出异常
    chainNode<T>* firstNode;                                 //指向头节点的指针
    int listSize;                               //链表的元素个数
public:

    //构造函数，析构函数
    chain(int initialCapacity = 10);
    chain(const chain<T>&);
    chain(const std::vector<T>&);
    ~chain();

    //方法
    bool empty () const {return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

    //exercises
    void setSize(int theSize);
    void set(const int theIndex, const T& theElement);

    int lastIndexOf(const T& theElement);
    T& operator[](const int theIndex);
    bool operator!=(const chain<T>& list2);
    bool operator==(const chain<T>& list2);
};

template<class T>
chain<T>::chain(int initialCapacity){
    if(initialCapacity < 1){
        std::ostringstream s;
        s << "Initial Capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;

}

template<class T>
chain<T>::chain(const chain<T>& theList){           //拷贝构造
    listSize = theList.listSize;
    if(listSize ==0){
        firstNode = NULL;
        return;
    }
    chainNode<T>* sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode -> next;
    chainNode<T>* targetNode = firstNode;
    while(sourceNode){
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template<class T>
chain<T>::chain(const std::vector<T>& theVector){
    listSize = theVector.size();
    if(listSize ==0){
        firstNode = NULL;
        return;
    }
    firstNode = new chainNode<T>(theVector[0]);
    chainNode<T> *n = firstNode;
    for(int i = 0; i < listSize; ++i){
        n->element = theVector[i];
        if(i+1<listSize){
            chainNode<T> *m = new chainNode<T>;
            n->next = m;
        }else{
            n->next = NULL;
        }
    }

}


template<class T>
chain<T>::~chain(){
    while (firstNode != NULL){
        chainNode<T>* nextNode = firstNode->next;
    
    delete firstNode;
    firstNode = nextNode;
    }
}
template<class T>  
void chain<T>::checkIndex(int theIndex) const{
    if(theIndex < 0 || theIndex >= listSize){
        std::ostringstream s;
        s << "index = " << theIndex << "size = " <<listSize;
        throw illegalIndex(s.str());
    }
}
template<class T>
T& chain<T>::get(int theIndex) const{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for(int i = 0; i < theIndex; i++){
        currentNode = currentNode -> next;
    }
    return currentNode -> element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const{       //元素theElement首次出现时的索引
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode -> element!= theElement){
        currentNode = currentNode -> next;
        index++;
    }
    if(currentNode == NULL){    return -1;  }
    else{   return index;  }
}

template<class T>
void chain<T>::erase(int theIndex){
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    if(theIndex ==0 ){
        deleteNode = firstNode;
        firstNode = firstNode -> next;
    }else{
        chainNode<T>* p = firstNode;
        for(int i = 0; i< theIndex - 1; i++){   p = p -> next; }
        deleteNode = p -> next;
        p -> next = p -> next -> next;
    }
    listSize--;
    delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement){
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if(theIndex == 0)   {   firstNode = new chainNode<T>(theElement,firstNode); }
    else{
        chainNode<T>* p = firstNode;
        for(int i = 0; i< theIndex -1; i++){    p = p->next; }
        p->next = new chainNode<T>(theElement, p-> next);
    }
    listSize++;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
template<class T>
void chain<T>::output(std::ostream& out) const{
    for(chainNode<T>* currentNode = firstNode;
                        currentNode!= NULL;
                        currentNode = currentNode->next)
    std::cout << currentNode -> element << " ";

}

template<class T>
std::ostream& operator<<(std::ostream& out, const chain<T>& x)
    {x.output(out);return out;}

template<class T>
void chain<T>::setSize(int theSize){
    if(theSize <= listSize) return;
    std::cout << "i need to give new nodes: "<< theSize - listSize <<std::endl;

    T val;
    int insertTimes = theSize - listSize;
    for(int i=0; i< insertTimes; i++)
        this->insert(listSize , val);
}

template<class T>
void chain<T>::set(int theIndex, const T& theElement){
    checkIndex(theIndex);
    chainNode<T>* n = firstNode;
    for(int i=0; i<theIndex; i++){
        n = n -> next;
    }
    n->element = theElement;
}

//05
template<class T>
int chain<T>::lastIndexOf(const T& theElement){
    int lastIndex = -1;
    int currIndex = 0;
    chainNode<T>* n = firstNode;
    while(n){
        if(n->element == theElement){
            lastIndex = currIndex;
        }
        n = n-> next;
        currIndex++;
    }
    return lastIndex;
}

template<class T> 
T& chain<T>::operator[](const int theIndex){
    checkIndex(theIndex);
    return this->get(theIndex);
}
/*
template<class T>   
bool chain<T>::operator==(const chain<T>& list2){ 
    
    if(this->listSize != list2.listSize){ return false; }
    for(int i=0; i<list2.listSize; i++){
        if(this->get(i) != list2.get(i))  return false;
    }
    return true;
}
template<class T>   
bool chain<T>::operator!=(const chain<T>& list2){ 
    
    if(this->listSize != list2.listSize){ return true; }
    for(int i=0; i<list2.listSize; i++){
        if(this->get(i) != list2.get(i))  return true;
    }
    return false;
}
*/
#endif