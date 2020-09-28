#include <gtest/gtest.h>
#include "BinarySearch.hpp"
#include <iostream>


TEST(test_binary_search, test_binary_search_find_correct_elem)
{
    int elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 0; i < sizeof(elems)/sizeof(int); ++i)
    {
        int pos = binary_search(elems, sizeof(elems)/sizeof(int), i);
        ASSERT_TRUE(pos == i);
    }
}

TEST(test_binary_search, test_binary_search_first_find_correct_elem)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_first(elems, sizeof(elems)/sizeof(int), 1);
    ASSERT_TRUE(pos == 1);
}

TEST(test_binary_search, test_binary_search_last_find_correct_elem)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_last(elems, sizeof(elems)/sizeof(int), 1);
    ASSERT_TRUE(pos == 4);
}

TEST(test_binary_search, test_binary_search_first_greater_or_equal_find_correct_elem)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_first_greater_or_equal(elems, sizeof(elems)/sizeof(int), 3);
    ASSERT_TRUE(pos == 5);
}

TEST(test_binary_search, test_binary_search_first_greater_or_equal_find_equal_elem)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_first_greater_or_equal(elems, sizeof(elems)/sizeof(int), 5);
    ASSERT_TRUE(pos == 5);
}

TEST(test_binary_search, test_binary_search_first_greater_or_equal_not_found)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_first_greater_or_equal(elems, sizeof(elems)/sizeof(int), 10);
    ASSERT_TRUE(pos == -1);
}

TEST(test_binary_search, test_binary_search_first_greater_or_equal_find_index_0)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_first_greater_or_equal(elems, sizeof(elems)/sizeof(int), -5);
    ASSERT_TRUE(pos == 0);
}

TEST(test_binary_search, test_binary_search_last_less_or_equal_find_correct_elem)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_last_less_or_equal(elems, sizeof(elems)/sizeof(int), 3);
    ASSERT_TRUE(pos == 4);
}

TEST(test_binary_search, test_binary_search_last_less_or_equal_find_last_elem)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_last_less_or_equal(elems, sizeof(elems)/sizeof(int), 20);
    ASSERT_TRUE(pos == 9);
}

TEST(test_binary_search, test_binary_search_last_less_or_equal_find_same_as_last)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_last_less_or_equal(elems, sizeof(elems)/sizeof(int), 9);
    ASSERT_TRUE(pos == 9);
}

TEST(test_binary_search, test_binary_search_last_less_or_equal_not_find)
{
    int elems[] = {0, 1, 1, 1, 1, 5, 6, 7, 8, 9};

    int pos = binary_search_last_less_or_equal(elems, sizeof(elems)/sizeof(int), -5);
    ASSERT_TRUE(pos == -1);
}