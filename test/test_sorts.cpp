#include <gtest/gtest.h>
#include <iostream>
#include "Sorts.hpp"

typedef void (*sort_fuc)(int[], int);

struct test_sorts : testing::Test
{
    void SORT_ARRAY_USING(sort_fuc sorter)
    {
        sorter(a, 10);
    } 
    void CHECK_SORT_RESULT_ASCEND()
    {
        bool sort_result = true;
        for(int i = 0; i < 10; ++i)
        {
            if(a[i] != i+1)
            {
                sort_result = false;
            }
        }
        ASSERT_TRUE(sort_result);
    }

    void SHOW()
    {
        for(auto i : a)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
    private:
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
};

TEST_F(test_sorts, should_array_ascend_when_using_bubble_sort)
{
    SORT_ARRAY_USING(bubble_sort);
    CHECK_SORT_RESULT_ASCEND();
}

TEST_F(test_sorts, should_array_ascend_when_using_insertion_sort)
{
    SORT_ARRAY_USING(insertion_sort);
    CHECK_SORT_RESULT_ASCEND();
}

TEST_F(test_sorts, should_array_ascend_when_using_selection_sort)
{
    SORT_ARRAY_USING(selection_sort);
    CHECK_SORT_RESULT_ASCEND();
}

TEST_F(test_sorts, should_array_ascend_when_using_merge_sort)
{
    SORT_ARRAY_USING(merge_sort);
    CHECK_SORT_RESULT_ASCEND();
}

TEST_F(test_sorts, should_array_ascend_when_using_quick_sort)
{
    SORT_ARRAY_USING(quick_sort);
    CHECK_SORT_RESULT_ASCEND();
}