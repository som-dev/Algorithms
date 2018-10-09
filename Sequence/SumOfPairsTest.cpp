#include "gtest/gtest.h"

#include "SumOfPairs.hpp"
#include "Print.hpp"

namespace {

TEST(SumOfPairs, Match)
{
    std::vector<int> sequence {1, 4, 45, 6, 10, -8};
    int targetSum = 16;
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::SumOfPairs(sequence, targetSum);
    std::vector<int> expectedOutput {6, 10};
    Sequence::Print("Output:", result, std::cout);
    ASSERT_EQ(result, expectedOutput);
}

TEST(SumOfPairs, NoMatch)
{
    std::vector<int> sequence {1, 4, 45, 6, 10, -8};
    int targetSum = 17;
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::SumOfPairs(sequence, targetSum);
    std::vector<int> expectedOutput { };
    Sequence::Print("Output:", result, std::cout);
    ASSERT_EQ(result, expectedOutput);
}

}
