#include <gtest/gtest.h>
#include "LRUCacheList.h"
#include <iostream>

TEST(test_lru, should_insert_node_at_head_when_node_not_exist)
{
    LRUCacheList lru(5);
    lru.insert(1);
    lru.insert(2);
    lru.insert(3);
    lru.insert(4);
    lru.insert(5);
    //expect:5->4->3->2->1
    LinkList<int> expect;
    expect.insert(1);
    expect.insert(2);
    expect.insert(3);
    expect.insert(4);
    expect.insert(5);

    ASSERT_TRUE(lru.debug() == expect);
}

TEST(test_lru, should_delete_node_and_insert_at_head_when_node_exist)
{
    LRUCacheList lru(5);
    lru.insert(1);
    lru.insert(2);
    lru.insert(3);
    lru.insert(1);
    //expect:1->3->2
    LinkList<int> expect;
    expect.insert(2);
    expect.insert(3);
    expect.insert(1);

    ASSERT_TRUE(lru.debug() == expect);
}

TEST(test_lru, should_delete_last_node_and_insert_at_head_when_lrulist_full)
{
    LRUCacheList lru(5);
    lru.insert(1);
    lru.insert(2);
    lru.insert(3);
    lru.insert(4);
    lru.insert(5);
    lru.insert(6);
    //expect:6->5->4->3->2
    LinkList<int> expect;
    expect.insert(2);
    expect.insert(3);
    expect.insert(4);
    expect.insert(5);
    expect.insert(6);

    ASSERT_TRUE(lru.debug() == expect);
}