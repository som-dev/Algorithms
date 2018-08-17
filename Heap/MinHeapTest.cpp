#include "gtest/gtest.h"

#include "MinHeap.hpp"

TEST(MinHeapTest, Test)
{
    MinHeap<int> minHeap;

    minHeap.add(8);
    minHeap.add(-3);
    minHeap.add(10);
    minHeap.add(1);
    minHeap.add(0);
    minHeap.add(-7);
    minHeap.add(12);
    minHeap.add(1);
    minHeap.add(4);

    EXPECT_EQ(minHeap.getMin(), -7);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), -3);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), 0);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), 1);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), 1);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), 4);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), 8);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), 10);
    minHeap.removeMin();
    EXPECT_EQ(minHeap.getMin(), 12);
    minHeap.removeMin();
}
