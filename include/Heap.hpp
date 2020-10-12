#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <vector>
#include <iostream>

template<typename T>
struct Heap
{
    Heap();
    ~Heap();

    void insert(T);
    void pop_top();
    void sort();
    void print();

    private:
    void heapify(int pos, int size);

    private:
    std::vector<T> container;
};

template<typename T>
Heap<T>::Heap()
{

}

template<typename T>
Heap<T>::~Heap()
{
    
}

template<typename T>
void Heap<T>::insert(T data)
{
    container.push_back(data);
    int i = container.size() -1;
    while(i > 0 && container[i] > container[(i-1)/2])
    {
        std::swap(container[i], container[(i-1)/2]);
        i = (i-1)/2;
    }
}

template<typename T>
void Heap<T>::pop_top()
{
    if(0 == container.size()) return;
    std::swap(container[0], container[container.size()-1]);
    container.pop_back();
    heapify(0, container.size());
}

template<typename T>
void Heap<T>::heapify(int pos, int size)
{
    int maxpos = pos;
    do
    {
        pos = maxpos;
        if(pos*2+1 < size && container[pos*2+1] > container[pos])// 左子节点大于则交换
        {
            maxpos = pos*2+1;
        }
        if(pos*2+2 < size && container[pos*2+2] > container[maxpos])// 右子节点大则交换
        {
            maxpos = pos*2+2;
        }
        std::swap(container[maxpos], container[pos]);
    } while (maxpos != pos);
    
}

template<typename T>
void Heap<T>::sort()
{
    int k = container.size();
    for(int i = container.size()/2; i >=1; --i)
    {
        heapify(i, k);
    }
    while(k>1)
    {
        std::swap(container[0], container[k-1]);
        k--;
        heapify(0, k);
    }
}

template<typename T>
void Heap<T>::print()
{
    for(auto i : container)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

#endif