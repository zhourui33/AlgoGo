#include <gtest/gtest.h>
#include "ArrayList.h"

TEST(test_array_list, init_array_list_with_default_capacity_50)
{
    ArrayList<int> money;
    ASSERT_EQ(money.size(), 0);
    ASSERT_EQ(money.capacity(), 50);
    ASSERT_TRUE(money.empty());
}

TEST(test_array_list, should_capacity_equal_para_given_constructor)
{
    ArrayList<int> daysPerMon(12);
    ASSERT_EQ(daysPerMon.capacity(), 12);
}

TEST(test_array_list, should_size_increase_when_insert_elem)
{
    ArrayList<int> daysPerMon(12);
    ASSERT_EQ(daysPerMon.size(), 0);

    daysPerMon.insert(0, 31);
    ASSERT_EQ(daysPerMon.size(), 1);
    ASSERT_FALSE(daysPerMon.empty());
}

TEST(test_array_list, should_size_decrease_when_remove_elem)
{
    ArrayList<int> daysPerMon(12);
    
    daysPerMon.insert(0, 31);
    daysPerMon.insert(1, 28);
    daysPerMon.insert(2, 31);
    daysPerMon.insert(3, 30);
    ASSERT_EQ(daysPerMon.size(), 4);

    daysPerMon.remove(0);
    ASSERT_EQ(daysPerMon.size(), 3);
}

TEST(test_array_list, should_get_value_by_quote_way)
{
    ArrayList<int> daysPerMon(12);
    
    daysPerMon.insert(0, 31);
    ASSERT_EQ(daysPerMon[0], 31);
}