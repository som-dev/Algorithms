#include "gtest/gtest.h"

#include "MergeOverlap.hpp"
#include "Print.hpp"

namespace {

TEST(MergeOverlap, TestOverlapRight)
{
    std::vector<std::pair<int,int>> intervals { {9,10}, {2,7}, {1,3} };
    Interval::Print("Original Intervals:", intervals, std::cout);
    auto result = Interval::MergeOverlap(intervals);
    Interval::Print("Merged Overlaps:", result, std::cout);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].first, 1);
    EXPECT_EQ(result[0].second, 7);
    EXPECT_EQ(result[1].first, 9);
    EXPECT_EQ(result[1].second, 10);
}

TEST(MergeOverlap, TestOverlapLeft)
{
    std::vector<std::pair<int,int>> intervals { {9,10}, {-5,2}, {1,3} };
    Interval::Print("Original Intervals:", intervals, std::cout);
    auto result = Interval::MergeOverlap(intervals);
    Interval::Print("Merged Overlaps:", result, std::cout);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].first, -5);
    EXPECT_EQ(result[0].second, 3);
    EXPECT_EQ(result[1].first, 9);
    EXPECT_EQ(result[1].second, 10);
}

TEST(MergeOverlap, TestOverlapSubsumed)
{
    std::vector<std::pair<int,int>> intervals { {9,10}, {1,3}, {0,6} };
    Interval::Print("Original Intervals:", intervals, std::cout);
    auto result = Interval::MergeOverlap(intervals);
    Interval::Print("Merged Overlaps:", result, std::cout);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].first, 0);
    EXPECT_EQ(result[0].second, 6);
    EXPECT_EQ(result[1].first, 9);
    EXPECT_EQ(result[1].second, 10);
}

TEST(MergeOverlap, TestOverlapEqualRightBoundary)
{
    std::vector<std::pair<int,int>> intervals { {9,10}, {1,3}, {3,5} };
    Interval::Print("Original Intervals:", intervals, std::cout);
    auto result = Interval::MergeOverlap(intervals);
    Interval::Print("Merged Overlaps:", result, std::cout);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].first, 1);
    EXPECT_EQ(result[0].second, 5);
    EXPECT_EQ(result[1].first, 9);
    EXPECT_EQ(result[1].second, 10);
}

TEST(MergeOverlap, TestOverlapEqualLeftBoundary)
{
    std::vector<std::pair<int,int>> intervals { {9,10}, {1,3}, {0,1} };
    Interval::Print("Original Intervals:", intervals, std::cout);
    auto result = Interval::MergeOverlap(intervals);
    Interval::Print("Merged Overlaps:", result, std::cout);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].first, 0);
    EXPECT_EQ(result[0].second, 3);
    EXPECT_EQ(result[1].first, 9);
    EXPECT_EQ(result[1].second, 10);
}

TEST(MergeOverlap, TestNoOverlap)
{
    std::vector<std::pair<int,int>> intervals { {5,7}, {9,10}, {1,3} };
    Interval::Print("Original Intervals:", intervals, std::cout);
    auto result = Interval::MergeOverlap(intervals);
    Interval::Print("Merged Overlaps:", result, std::cout);
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0].first, 1);
    EXPECT_EQ(result[0].second, 3);
    EXPECT_EQ(result[1].first, 5);
    EXPECT_EQ(result[1].second, 7);
    EXPECT_EQ(result[2].first, 9);
    EXPECT_EQ(result[2].second, 10);
}

}
