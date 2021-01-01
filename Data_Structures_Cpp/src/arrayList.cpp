#include "arrayList.h"

template<class T>                       //构造函数
arrayList::arrayList(int initialCapacity){
    if(initialCapacity < 1){
        ostringstream s;
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
        ostringstream s;
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
        ostringstream s;
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
void arrayList<T>::output(ostream -> out) const{                      //把线性表插入输入流
    copy(element, element + listSize, ostream_iterator<T>(cout," "));
}

template<class T>   
ostream& operator<<(ostream& out, const arrayList<T>& x){           //重载运算符<<
    x.output(out);
    return out;
}