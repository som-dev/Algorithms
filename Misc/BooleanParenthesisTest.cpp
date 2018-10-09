#include "gtest/gtest.h"

#include "BooleanParenthesis.hpp"

namespace {

TEST(BooleanParenthesis, Test1)
{
    std::string symbols = "TFT";
    std::string operators = "^&";
    auto result = Misc::BooleanParenthesis(symbols, operators);
    std::cout << "Number of trues is " << result << std::endl;
    EXPECT_EQ(result, 2);
}

TEST(BooleanParenthesis, Test2)
{
    std::string symbols = "TFF";
    std::string operators = "^|";
    auto result = Misc::BooleanParenthesis(symbols, operators);
    std::cout << "Number of trues is " << result << std::endl;
    EXPECT_EQ(result, 2);
}

TEST(BooleanParenthesis, Test3)
{
    std::string symbols = "TTFT";
    std::string operators = "|&^";
    auto result = Misc::BooleanParenthesis(symbols, operators);
    std::cout << "Number of trues is " << result << std::endl;
    EXPECT_EQ(result, 4);
}

}
