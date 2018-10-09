#include "gtest/gtest.h"

#include "LargestNumber.hpp"
#include "Print.hpp"

namespace {

TEST(LargestNumber, Test1)
{
    std::vector<int> sequence { 3, 30, 34, 5, 9 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::LargestNumber(sequence);
    std::cout << "Largest Number: " << result << std::endl;
    EXPECT_EQ(result, "9534330");
}

TEST(LargestNumber, Test2)
{
    std::vector<int> sequence { 54, 546, 548, 60 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto result = Sequence::LargestNumber(sequence);
    std::cout << "Largest Number: " << result << std::endl;
    EXPECT_EQ(result, "6054854654");
}

}
