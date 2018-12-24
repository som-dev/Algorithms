#include "gtest/gtest.h"

#include "SortByFrequency.hpp"
#include "Print.hpp"

namespace {

TEST(SortByFrequency, Test1)
{
    std::vector<int> sequence { 3, 2, 1, 9, 3, 10, 4, 3, 2, 5 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::SortByFrequency(sequence);
    Sequence::Print("Sorted Sequence:", result, std::cout);
    EXPECT_EQ(sequence.size(), result.size());
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 5);
    EXPECT_EQ(result[3], 9);
    EXPECT_EQ(result[4], 10);
    EXPECT_EQ(result[5], 2);
    EXPECT_EQ(result[6], 2);
    EXPECT_EQ(result[7], 3);
    EXPECT_EQ(result[8], 3);
    EXPECT_EQ(result[9], 3);
}

}
