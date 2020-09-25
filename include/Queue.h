#ifndef _QUEUE_H_20200821
#define _QUEUE_H_20200821

#include <iostream>
#include "ArrayList.h"

template<typename T>
struct Queue
{
    Queue();
    Queue(unsigned int);
    ~Queue();

    bool enqueue(const T&);
    bool dequeue();

    private:
    bool full();
    bool empty();

    private:
    ArrayList<T> *_elems;
    unsigned int _head;
    unsigned int _tail;
    unsigned int _capacity;
};

template<typename T>
Queue<T>::Queue()
{
    _elems = new ArrayList<T>(10);
    _head = 0;
    _tail = 0;
    _capacity = 10;
}

template<typename T>
Queue<T>::Queue(unsigned int cap)
{
    _elems = new ArrayList<T>(cap);
    _head = 0;
    _tail = 0;
    _capacity = cap;
}

template<typename T>
Queue<T>::~Queue()
{
    delete _elems;
    _head = 0;
    _tail = 0;
    _capacity = 0;
}

template<typename T>
bool Queue<T>::full()
{
    return (_tail+1)%_capacity == _head;
}

template<typename T>
bool Queue<T>::empty()
{
    return _tail == _head;
}

template<typename T>
bool Queue<T>::enqueue(const T& elem)
{
    if(full())
    {
        return false;
    }
    _elems->insert(_tail, elem);
    _tail++;
    return true;
}

template<typename T>
bool Queue<T>::dequeue()
{
    if(empty())
    {
        return false;
    }
    _elems->remove(_head);
    _head++;
    return true;
}

#endif