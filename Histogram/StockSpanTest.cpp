#include "gtest/gtest.h"

#include "StockSpan.hpp"
#include "Print.hpp"

namespace {

TEST(StockSpan, Test1)
{
    std::vector<int> prices {20, 16, 12, 14, 12, 15, 17};
    Histogram::Print("Stock Prices:", prices, std::cout);
    auto span = Histogram::StockSpan(prices);
    Histogram::Print("Stock Span:", span, std::cout);
    ASSERT_EQ(span.size(), prices.size());
    EXPECT_EQ(span[0], 1);
    EXPECT_EQ(span[1], 1);
    EXPECT_EQ(span[2], 1);
    EXPECT_EQ(span[3], 2);
    EXPECT_EQ(span[4], 1);
    EXPECT_EQ(span[5], 4);
    EXPECT_EQ(span[6], 6);
}

TEST(StockSpan, Test2)
{
    std::vector<int> prices {8, 4, 5, 9, 12, 8};
    Histogram::Print("Stock Prices:", prices, std::cout);
    auto span = Histogram::StockSpan(prices);
    Histogram::Print("Stock Span:", span, std::cout);
    ASSERT_EQ(span.size(), prices.size());
    EXPECT_EQ(span[0], 1);
    EXPECT_EQ(span[1], 1);
    EXPECT_EQ(span[2], 2);
    EXPECT_EQ(span[3], 4);
    EXPECT_EQ(span[4], 5);
    EXPECT_EQ(span[5], 1);
}

}
