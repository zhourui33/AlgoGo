#include <gtest/gtest.h>
#include "LinkList.h"

TEST(test_link_list, should_link_list_insert_behind_head)
{
    LinkList<int> mon;
    mon.insert(1);
    mon.insert(2);
    mon.insert(3);
    mon.insert(4);
    mon.insert(5);
    mon.insert(6);
    mon.show();
}

TEST(test_link_list, should_link_list_reverse_as_expect)
{
    LinkList<int> mon;
    mon.insert(1);
    mon.insert(2);
    mon.insert(3);
    mon.insert(4);
    mon.insert(5);
    mon.insert(6);
    mon.show();
    mon.reverse();
    mon.show();
    mon.reverse();
    mon.show();
}
