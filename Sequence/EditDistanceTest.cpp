#include "gtest/gtest.h"

#include "EditDistance.hpp"

namespace {

TEST(EditDistance, RecursiveSingleReplace)
{
    std::string s1 = "cut";
    std::string s2 = "cat";
    auto result = Sequence::EditDistanceRecursive(s1, s2);
    std::cout << "Edit Distance of " << s1 << " and " << s2 << " is " << result << std::endl;
    EXPECT_EQ(result, 1);
}

TEST(EditDistance, RecursiveSingleAdd)
{
    std::string s1 = "greek";
    std::string s2 = "gretek";
    auto result = Sequence::EditDistanceRecursive(s1, s2);
    std::cout << "Edit Distance of " << s1 << " and " << s2 << " is " << result << std::endl;
    EXPECT_EQ(result, 1);
}

TEST(EditDistance, RecursiveMultiple)
{
    std::string s1 = "saturday";
    std::string s2 = "sunday";
    auto result = Sequence::EditDistanceRecursive(s1, s2);
    std::cout << "Edit Distance of " << s1 << " and " << s2 << " is " << result << std::endl;
    EXPECT_EQ(result, 3);
}

TEST(EditDistance, RecursiveLarge)
{
    std::string s1 = "dlsklsja";
    std::string s2 = "fdsakklfdslk";
    auto result = Sequence::EditDistanceRecursive(s1, s2);
    std::cout << "Edit Distance of " << s1 << " and " << s2 << " is " << result << std::endl;
    EXPECT_EQ(result, 8);
}

TEST(EditDistance, DynamicSingleReplace)
{
    std::string s1 = "cut";
    std::string s2 = "cat";
    auto result = Sequence::EditDistanceDynamic(s1, s2);
    std::cout << "Edit Distance of " << s1 << " and " << s2 << " is " << result << std::endl;
    EXPECT_EQ(result, 1);
}

TEST(EditDistance, DynamicSingleAdd)
{
    std::string s1 = "greek";
    std::string s2 = "gretek";
    auto result = Sequence::EditDistanceDynamic(s1, s2);
    std::cout << "Edit Distance of " << s1 << " and " << s2 << " is " << result << std::endl;
    EXPECT_EQ(result, 1);
}

TEST(EditDistance, DynamicLarge)
{
    std::string s1 = "dlsklsja";
    std::string s2 = "fdsakklfdslk";
    auto result = Sequence::EditDistanceDynamic(s1, s2);
    std::cout << "Edit Distance of " << s1 << " and " << s2 << " is " << result << std::endl;
    EXPECT_EQ(result, 8);
}


}
