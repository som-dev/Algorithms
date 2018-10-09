#include "gtest/gtest.h"

#include "SmallestWindowSubstring.hpp"

namespace {

TEST(SmallestWindowSubstring, Test1)
{
    std::string str = "this is a test string";
    std::string letters = "tist";
    auto result = Sequence::SmallestWindowSubstring(str, letters);
    std::cout << "Smallest Substring: " << result << std::endl;
    EXPECT_EQ(result, "t stri");
}

TEST(SmallestWindowSubstring, Test2)
{
    std::string str = "forksandforks";
    std::string letters = "ndk";
    auto result = Sequence::SmallestWindowSubstring(str, letters);
    std::cout << "Smallest Substring: " << result << std::endl;
    EXPECT_EQ(result, "ksand");
}

TEST(SmallestWindowSubstring, NoMatch)
{
    std::string str = "this is a test string";
    std::string letters = "tisz";
    auto result = Sequence::SmallestWindowSubstring(str, letters);
    std::cout << "Smallest Substring: " << result << std::endl;
    EXPECT_EQ(result, "");
}

TEST(SmallestWindowSubstring, Beginning)
{
    std::string str = "this is a test string";
    std::string letters = "this";
    auto result = Sequence::SmallestWindowSubstring(str, letters);
    std::cout << "Smallest Substring: " << result << std::endl;
    EXPECT_EQ(result, "this");
}

TEST(SmallestWindowSubstring, End)
{
    std::string str = "this is a test string";
    std::string letters = "ring";
    auto result = Sequence::SmallestWindowSubstring(str, letters);
    std::cout << "Smallest Substring: " << result << std::endl;
    EXPECT_EQ(result, "ring");
}

}
