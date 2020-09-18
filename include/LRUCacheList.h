#ifndef _LRU_CACHE_LIST_H_
#define _LRU_CACHE_LIST_H_

#include "LinkList.h"

struct LRUCacheList
{
    LRUCacheList();
    LRUCacheList(unsigned int);
    ~LRUCacheList();

    void insert(int);
    void show() const;
    const LinkList<int>& debug();

    private:
    LinkList<int> _lru;
    unsigned int _capacity;
    unsigned int _size;
};

#endif