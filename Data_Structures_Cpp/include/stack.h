#ifndef stack_
#define stack_

template<class T>
class stack{
    
public:
    virtual ~stack(){}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& top() const = 0;
    virtual void pop()  const = 0;
    virtual void push(const T& theElement)  =0;
}

# endif