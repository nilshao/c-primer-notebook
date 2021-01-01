#include <iostream>
#include "arrayList.h"

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
        void checkIndex(int theIndex) const;
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(ostream &out) const;

        //其他方法
        int capacity() const {return arrayLength;}

    protected:
        void checkIndex(int theIndex) const;        //若索引theIndex无效，则抛出异常
        T* element;                                 //存储线性表元素的一维数组
        int arrayLength;                            //一维数组的容量
        int listSize;                               //线性表的元素个数

}