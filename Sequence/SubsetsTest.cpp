#include "gtest/gtest.h"

#include "Subsets.hpp"
#include "Print.hpp"

namespace {

TEST(Subsets, Simple)
{
    std::set<int> sequence { 1, 2, 3 };
    Sequence::Print("Original Sequence:", sequence, std::cout);
    auto results = Sequence::Subsets(sequence);
    for (auto result : results)
    {
      Sequence::Print("Subsequence", result, std::cout);
    }
    ASSERT_EQ(results.size(), 8);
    std::set<std::set<int>> expected_results {
        { }, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}
    };
    for (auto expected_set : expected_results)
    {
        ASSERT_EQ(results.count(expected_set), 1);
    }
}

}
