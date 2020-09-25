#ifndef _STACK_H_20200919
#define _STACK_H_20200919

#include "ArrayList.h"
#include "LinkList.h"

template<typename T>
struct ArrayStack
{
    ArrayStack();
    ArrayStack(unsigned int);
    ~ArrayStack();

    bool pop();
    bool push(const T&);

    private:
    bool empty();
    private:
    ArrayList<T> _elems;
    unsigned int _size;
    unsigned int _capacity;
};

template<typename T>
ArrayStack<T>::ArrayStack() : _size(0), _capacity(10)
{
    
}

template<typename T>
ArrayStack<T>::ArrayStack(unsigned int cap) : _size(0), _capacity(cap)
{

}

template<typename T>
ArrayStack<T>::~ArrayStack()
{

}

template<typename T>
bool ArrayStack<T>::empty()
{
    return 0 == _size;
}

template<typename T>
bool ArrayStack<T>::push(const T& elem)
{
    _elems.insert(_size, elem);
    _size++;
    return true;
}

template<typename T>
bool ArrayStack<T>::pop()
{
    if(empty()) 
    {
        return false;
    }
    _elems.remove(_size - 1);
    _size--;
    return true;
}

template<typename T>
struct LinkStack
{
    LinkStack();
    ~LinkStack();

    bool pop();
    bool push(const T&);

    private:
    bool empty();
    private:
    LinkList<T> _elems;
    unsigned int _size;
};

template<typename T>
LinkStack<T>::LinkStack() : _size(0)
{

}

template<typename T>
LinkStack<T>::~LinkStack()
{

}

template<typename T>
bool LinkStack<T>::empty()
{
    return 0 == _size;
}

template<typename T>
bool LinkStack<T>::pop()
{
    if(empty())
    {
        return false;
    }
    _elems.removeLastN(_size);
    _size--;
    return true;
}

template<typename T>
bool LinkStack<T>::push(const T& elem)
{
    _elems.insert(elem);
    _size++;
    return true;
}


#endif