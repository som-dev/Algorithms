#include "gtest/gtest.h"

#include "SlidingWindow.hpp"
#include "Print.hpp"

namespace {

TEST(SlidingWindow, K3)
{
    std::vector<int> sequence {1, 2, 3, 1, 4, 5, 2, 3, 6};
    Sequence::Print("Original Sequence:", sequence, std::cout);
    int K = 3;
    auto result = Sequence::SlidingWindowMax(sequence, K);
    std::vector<int> expectedOutput {3, 3, 4, 5, 5, 5, 6};
    Sequence::Print("SlidingWindowMax:", result, std::cout);
    ASSERT_EQ(result, expectedOutput);
}

TEST(SlidingWindow, K4)
{
    std::vector<int> sequence {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    Sequence::Print("Original Sequence:", sequence, std::cout);
    int K = 4;
    auto result = Sequence::SlidingWindowMax(sequence, K);
    std::vector<int> expectedOutput {10, 10, 10, 15, 15, 90, 90};
    Sequence::Print("SlidingWindowMax:", result, std::cout);
    ASSERT_EQ(result, expectedOutput);
}

}
