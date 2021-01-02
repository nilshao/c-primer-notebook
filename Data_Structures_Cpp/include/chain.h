// chapter06
#ifndef chain_
#define chain_

#include <iostream>
#include "chainNode.h"

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
    ~chain();

    //方法
    bool empty () const {return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

}

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
chain<T>::~chain(){
    while (firstNode != NULL){
        chainNode<T>* nextNode = firstNode->next;
    
    delete firstNode;
    firstNode = nextNode;
    }
}

template<class T>
T& chain<T>::get(index)


template<class T>
void chain<T>::insert(int theIndex, const T& theElement){
    
}

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




#endif