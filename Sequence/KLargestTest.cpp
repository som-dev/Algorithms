#include "gtest/gtest.h"

#include "KLargest.hpp"
#include "Print.hpp"

namespace {

TEST(KLargest, TopFourUniqueNumbers)
{
    std::vector<int> sequence { 99, 14, 12, 1, 3, 20, 42, 96, 7, 39, 87, 97, 90, 98, 80, 54 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    int K = 4;
    auto result = Sequence::KLargest(sequence, K);
    Sequence::Print("K Largest :", result, std::cout);
    ASSERT_EQ(result.size(), K);
    EXPECT_EQ(result[0], 96);
    EXPECT_EQ(result[1], 97);
    EXPECT_EQ(result[2], 98);
    EXPECT_EQ(result[3], 99);
}

TEST(KLargest, TopFourDuplicateNumbers)
{
    std::vector<int> sequence { 99, 14, 12, 1, 3, 20, 42, 99, 7, 39, 87, 97, 90, 99, 80, 54 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    int K = 4;
    auto result = Sequence::KLargest(sequence, K);
    Sequence::Print("K Largest :", result, std::cout);
    ASSERT_EQ(result.size(), K);
    EXPECT_EQ(result[0], 97);
    EXPECT_EQ(result[1], 99);
    EXPECT_EQ(result[2], 99);
    EXPECT_EQ(result[3], 99);
}

}
