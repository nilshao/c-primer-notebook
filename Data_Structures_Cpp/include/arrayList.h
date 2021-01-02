#ifndef arrayList_
#define arrayList_

#include "arrayList.h"
#include "linearList.h"
#include <iostream>
#include<sstream>
#include<string>
#include<algorithm>

template<class T>
class arrayList: public linearList<T> {
    private:
        int arrayLength = 0;

    public:
        arrayList(int){};
        arrayList(const arrayList<T>&){};
        ~arrayList(){};

        //方法
        void changeLength1D(T*& a, int oldLength, int newLength){
        bool empty() const {return listSize == 0;}
        int size() const {return listSize;}
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(std::ostream &out) const;

        //其他方法
        int capacity() const {return arrayLength;}

    protected:
        void checkIndex(int theIndex) const;        //若索引theIndex无效，则抛出异常
        T* element;                                 //存储线性表元素的一维数组
        int arrayLength;                            //一维数组的容量
        int listSize;                               //线性表的元素个数

}

template<class T>                       //构造函数
arrayList::arrayList(int initialCapacity){
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
arrayList::arrayList(const arrayList<T>& theList){                  //拷贝构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = theList.element;
    copy(theList.element, theList.element + listSize, element);
}

~arrayList::arrayList(){
    delete [] element
}

template<class T>   
void changeLength1D(T*& a, int oldLength, int newLength){
    if(newLength < 0)
        throw illegalParameterValue("new length must be >=0");
    T* temp = new T[newLength];
    int number = min(oldLength,newLength);
    copy(a, a+number, temp);
    delete[] a;
    a = temp;
}

template<class T>   
bool arrayList<T>::empty() const {return listSize == 0;}

template<class T>   
int arrayList<T>::size() const {return listSize;}

template<class T>  
void arrayList<T>::checkIndex(int theIndex) const{
    if(theIndex < 0 || theIndex >= listSize){
        std::ostringstream s;
        s << "index = " << theIndex << "size = " <<listSize;
        throw illegalIndex(s.str);
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
        changeLength1D(element, arrayLength, 2* arrayLength);
        arrayLength *= 2;
    }

    //把元素依次向右移动一个位置
    copy_backward(element + theIndex, element + listSize, element + listSize + 1);

    element[theIndex] = theElement;
    listSize ++;

}

template<class T>
void arrayList<T>::output(std::ostream -> out) const{                      //把线性表插入输入流
    copy(element, element + listSize, ostream_iterator<T>(cout," "));
}

template<class T>   
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x){           //重载运算符<<
    x.output(out);
    return out;
}





#endif
