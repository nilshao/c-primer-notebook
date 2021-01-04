#ifndef arrayList_
#define arrayList_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "arrayList.h"
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

template<class T>
class arrayList: public linearList<T> {
    private:
      //  int arrayLength = 0;

    public:
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() {delete [] element;}

        //方法
        bool empty() const {return listSize == 0;}
        int size() const {return listSize;}
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(std::ostream &out) const;

        //重载操作符
     //   std::ostream& operator<<(std::ostream& out, const arrayList<T> &theList);
        T& operator[](const int);
        bool operator==(const arrayList<T>&);
        bool operator!=(const arrayList<T>&);

        //iterator
        class iterator;
        iterator begin() {return iterator(element);}
        iterator end() {return iterator(element + listSize);}

        // iterator for arrayList
        class iterator 
        {
        public:
            // typedefs required by C++ for a bidirectional iterator
            typedef bidirectional_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference ;

            // constructor
            iterator(T* thePosition = 0) {position = thePosition;}

            // dereferencing operators
            T& operator*() const {return *position;}
            T* operator->() const {return &*position;}

            // increment
            iterator& operator++()   // preincrement
                    {++position; return *this;}
            iterator operator++(int) // postincrement
                    {iterator old = *this;
                    ++position;
                    return old;
                    }

            // decrement
            iterator& operator--()   // predecrement
                    {--position; return *this;}
            iterator operator--(int) // postdecrement
                    {iterator old = *this;
                    --position;
                    return old;
                    }

            // equality testing
            bool operator!=(const iterator right) const
                  {return position != right.position;}
            bool operator==(const iterator right) const
                  {return position == right.position;}
         protected:
            T* position;
      };  // end of iterator class



        //其他方法
        int capacity() const {return arrayLength;}
        void push_back(const T& theElement);
        void pop_back();

    protected:
        void checkIndex(int theIndex) const;        //若索引theIndex无效，则抛出异常
        T* element;                                 //存储线性表元素的一维数组
        int arrayLength;                            //一维数组的容量
        int listSize;                               //线性表的元素个数

};

template<class T>                       //构造函数
arrayList<T>::arrayList(int initialCapacity){
    if(initialCapacity < 1){
        std::ostringstream s;
        s << "Inital Capacity = " << initialCapacity << "Must be > 0" ;
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template<class T>                                   
arrayList<T>::arrayList(const arrayList<T>& theList){                  //拷贝构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = theList.element;
    copy(theList.element, theList.element + listSize, element);
}

template<class T>  
void arrayList<T>::checkIndex(int theIndex) const{
    if(theIndex < 0 || theIndex >= listSize){
        std::ostringstream s;
        s << "index = " << theIndex << "size = " <<listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>   
T& arrayList<T>::get(int theIndex) const{
    checkIndex(theIndex);
    return element[theIndex];
}

template<class T>   
int arrayList<T>::indexOf(const T& theElement) const{
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    if(theIndex == listSize){   
        return -1; 
    }else{
        return theIndex;
    }
}

template<class T>   
void arrayList<T>::erase(int theIndex){
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

template<class T>   
void arrayList<T>::insert(int theIndex, const T& theElement){       //在索引theIndex处插入元素theElement
    if(theIndex < 0 || theIndex > listSize){
        std::ostringstream s;
        s << "index = " << theIndex << "size = " << listSize;
        throw illegalIndex(s.str());
    }

    //有效索引，确定数组是否已满
    if(listSize == arrayLength){        //数组空间已满，数组长度倍增
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    //把元素依次向右移动一个位置
    copy_backward(element + theIndex, element + listSize, element + listSize + 1);

    element[theIndex] = theElement;
    listSize ++;

}

template<class T>
void arrayList<T>::output(std::ostream& out) const{                      //把线性表插入输入流
    copy(element, element + listSize, ostream_iterator<T>(cout," "));
}

template<class T>   
std::ostream& operator<<(std::ostream& out, const arrayList<T>& theList){           //重载运算符<<
    theList.output(out);
    return out;
}

template<class T> 
T& arrayList<T>::operator[](const int theIndex){
    if(theIndex < 0 || theIndex > this->listSize){
        std::ostringstream s;
        s << "index = " << theIndex << "size = " << this->listSize;
        throw illegalIndex(s.str());
    }
    return this->get(theIndex);
}

template<class T>   
bool arrayList<T>::operator==(const arrayList<T>& list2){ 
    
    if(this->listSize != list2.listSize){ return false; }
    for(int i=0; i<list2.listSize; i++){
        if(this->get(i) != list2.get(i))  return false;
    }
    return true;
}
template<class T>   
bool arrayList<T>::operator!=(const arrayList<T>& list2){ 
    
    if(this->listSize != list2.listSize){ return true; }
    for(int i=0; i<list2.listSize; i++){
        if(this->get(i) != list2.get(i))  return true;
    }
    return false;
}

template<class T>   
void arrayList<T>::push_back(const T& theElement){

    //有效索引，确定数组是否已满
    if(listSize == arrayLength){        //数组空间已满，数组长度倍增
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    //把元素依次向右移动一个位置
    copy_backward(element + listSize, element + listSize, element + listSize + 1);

    element[listSize] = theElement;
    listSize ++;
}
    

template<class T>   
void arrayList<T>::pop_back(){

    checkIndex(listSize-1);
    element[--listSize].~T();

}


#endif
