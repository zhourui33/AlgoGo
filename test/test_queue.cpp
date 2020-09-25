#include <gtest/gtest.h>
#include "Queue.h"

TEST(test_queue, should_enqueue_as_expect)
{
    Queue<int> fifo;
    fifo.enqueue(1);
    fifo.enqueue(2);
    fifo.enqueue(3);
    fifo.enqueue(4);
    fifo.enqueue(5);
}