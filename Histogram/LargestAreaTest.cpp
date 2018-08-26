#include "gtest/gtest.h"

#include "LargestArea.hpp"
#include "Print.hpp"

namespace {

TEST(LargestArea, AreaInMiddle)
{
    std::vector<int> histogram {6, 2, 5, 4, 5, 1, 6};
    Histogram::Print("Histogram:", histogram, std::cout);
    auto area = Histogram::LargestArea(histogram);
    std::cout << "Max area is: " << area.maxArea
        << " (from " << area.leftIndex
        << " to " << area.rightIndex << ")" << std::endl;
    EXPECT_EQ(area.maxArea, 12);
    EXPECT_EQ(area.leftIndex, 2);
    EXPECT_EQ(area.rightIndex, 4);
}

TEST(LargestArea, EqualHeightBarsInArea)
{
    std::vector<int> histogram {1, 2, 3, 4, 5, 3, 3, 2};
    Histogram::Print("Histogram:", histogram, std::cout);
    auto area = Histogram::LargestArea(histogram);
    std::cout << "Max area is: " << area.maxArea
        << " (from " << area.leftIndex
        << " to " << area.rightIndex << ")" << std::endl;
    EXPECT_EQ(area.maxArea, 15);
    EXPECT_EQ(area.leftIndex, 2);
    EXPECT_EQ(area.rightIndex, 6);
}

TEST(LargestArea, EntireLength)
{
    std::vector<int> histogram {6, 1, 4, 3, 4, 1, 1, 1, 1, 6};
    Histogram::Print("Histogram:", histogram, std::cout);
    auto area = Histogram::LargestArea(histogram);
    std::cout << "Max area is: " << area.maxArea
        << " (from " << area.leftIndex
        << " to " << area.rightIndex << ")" << std::endl;
    EXPECT_EQ(area.maxArea, 10);
    EXPECT_EQ(area.leftIndex, 0);
    EXPECT_EQ(area.rightIndex, 9);
}

}
