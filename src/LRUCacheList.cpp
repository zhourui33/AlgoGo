#include "LRUCacheList.h"

LRUCacheList::LRUCacheList(): _capacity(10),_size(0)
{

}

LRUCacheList::LRUCacheList(unsigned int cap): _capacity(cap),_size(0)
{

}

LRUCacheList::~LRUCacheList()
{
    _capacity = 0;
    _size = 0;
}

void LRUCacheList::insert(int value)
{
    LinkNode<int> *node = _lru.find(value);
    if(node)
    {
        _lru.insert(value);
        _lru.remove(node);
    }
    else
    {
        if(_size < _capacity)
        {
            _lru.insert(value);
            _size++;
        }
        else
        {
            _lru.removeLastN(1);
            _lru.insert(value);
        }
    }    
}

void LRUCacheList::show() const
{
    _lru.show();
}

const LinkList<int>& LRUCacheList::debug()
{
    return _lru;
}