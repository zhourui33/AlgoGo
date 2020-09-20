#include <gtest/gtest.h>
#include "Stack.h"

TEST(test_stack, should_arraystack_push_pop_elem)
{
    ArrayStack<int> mon;
    ASSERT_TRUE(mon.push(1));
    ASSERT_TRUE(mon.push(2));
    ASSERT_TRUE(mon.pop());
    ASSERT_TRUE(mon.pop());
    ASSERT_FALSE(mon.pop());
}

TEST(test_stack, should_linkstack_push_pop_elem)
{
    LinkStack<int> mon;
    ASSERT_TRUE(mon.push(1));
    ASSERT_TRUE(mon.push(2));
    ASSERT_TRUE(mon.pop());
    ASSERT_TRUE(mon.pop());
    ASSERT_FALSE(mon.pop());
}