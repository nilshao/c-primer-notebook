
#ifndef extendedLinearList_
#define extendedLinearList_
#include <iostream>
#include "linearList.h"

using namespace std;

template<class T>
class extendedLinearList : linearList<T> 
{
   public:
      virtual ~extendedLinearList() {}
      virtual void clear() = 0;
                  // empty the list
      virtual void push_back(const T& theElement) = 0;
                  // insert theElement at end of list
};
#endif

