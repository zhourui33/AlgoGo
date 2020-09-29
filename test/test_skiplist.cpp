#include <gtest/gtest.h>
#include "SkipList.hpp"


TEST(test_skip_list, test_skip_list_insert)
{
    SkipList skiplist;
    skiplist.insert(100);
    skiplist.insert(50);
    skiplist.insert(75);
    skiplist.insert(25);
    skiplist.insert(0);
    skiplist.insert(5);
}

TEST(test_skip_list, test_skip_list_erase)
{
    SkipList skiplist;
    skiplist.insert(100);
    skiplist.insert(50);
    skiplist.insert(75);
    skiplist.insert(25);
    skiplist.insert(0);
    skiplist.insert(5);

    skiplist.erase(75);

    ASSERT_TRUE(skiplist.find(75) == nullptr);
}

TEST(test_skip_list, test_skip_list_find)
{
    SkipList skiplist;
    skiplist.insert(100);
    skiplist.insert(50);
    skiplist.insert(75);
    skiplist.insert(25);
    skiplist.insert(0);
    skiplist.insert(5);

    ASSERT_TRUE(skiplist.find(75)->data == 75);
}