#include "gtest/gtest.h"

#include "NextLargerElement.hpp"
#include "Print.hpp"

namespace {

TEST(NextLargerElement, Test1)
{
    std::vector<int> sequence { 1, 3, 2, 4 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::NextLargerElement(sequence);
    Sequence::Print("Next Larger Element:", result, std::cout);
    ASSERT_EQ(result.size(), sequence.size());
    EXPECT_EQ(result[0], 3);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], -1);
}

TEST(NextLargerElement, Test2)
{
    std::vector<int> sequence { 4, 5, 2, 25 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::NextLargerElement(sequence);
    Sequence::Print("Next Larger Element:", result, std::cout);
    ASSERT_EQ(result.size(), sequence.size());
    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 25);
    EXPECT_EQ(result[2], 25);
    EXPECT_EQ(result[3], -1);
}

TEST(NextLargerElement, Test3)
{
    std::vector<int> sequence { 13, 7, 6, 12 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::NextLargerElement(sequence);
    ASSERT_EQ(result.size(), sequence.size());
    EXPECT_EQ(result[0], -1);
    EXPECT_EQ(result[1], 12);
    EXPECT_EQ(result[2], 12);
    EXPECT_EQ(result[3], -1);
}

TEST(NextLargerElement, DecreasingOnly)
{
    std::vector<int> sequence { 9, 7, 5, 3 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::NextLargerElement(sequence);
    Sequence::Print("Next Larger Element:", result, std::cout);
    ASSERT_EQ(result.size(), sequence.size());
    EXPECT_EQ(result[0], -1);
    EXPECT_EQ(result[1], -1);
    EXPECT_EQ(result[2], -1);
    EXPECT_EQ(result[3], -1);
}

TEST(NextLargerElement, IncreasingOnly)
{
    std::vector<int> sequence { 0, 1, 2, 3 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::NextLargerElement(sequence);
    Sequence::Print("Next Larger Element:", result, std::cout);
    ASSERT_EQ(result.size(), sequence.size());
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], -1);
}

}
