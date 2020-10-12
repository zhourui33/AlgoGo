#include <gtest/gtest.h>
#include "Heap.hpp"

TEST(test_heap, test_heap_basic_op)
{
    Heap<int> hp;
    hp.insert(121);
    hp.insert(2);
    hp.insert(20);
    hp.insert(645);
    hp.insert(8923);
    hp.insert(33);
    hp.insert(6);
    hp.insert(202);
    hp.insert(243);
    hp.insert(198);
    hp.print();

    hp.pop_top();
    hp.print();

    hp.sort();
    hp.print();
}


