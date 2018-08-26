#include "gtest/gtest.h"

#include "StockMaxProfit.hpp"
#include "Print.hpp"

namespace {

TEST(StockMaxProfit, SingleTransaction1)
{
    std::vector<int> prices {2, 3, 10, 6, 4, 8, 1};
    Histogram::Print("Stock Prices:", prices, std::cout);
    auto transaction = Histogram::StockMaxProfitOneTransaction(prices);
    std::cout << "Max profit is: " << transaction.maxProfit
        << " buy on " << transaction.buyIndex
        << " sell on " << transaction.sellIndex << std::endl;
    EXPECT_EQ(transaction.maxProfit, 8);
    EXPECT_EQ(transaction.buyIndex, 0);
    EXPECT_EQ(transaction.sellIndex, 2);
}

TEST(StockMaxProfit, SingleTransaction2)
{
    std::vector<int> prices {7, 9, 5, 6, 3, 2};
    Histogram::Print("Stock Prices:", prices, std::cout);
    auto transaction = Histogram::StockMaxProfitOneTransaction(prices);
    std::cout << "Max profit is: " << transaction.maxProfit
        << " buy on " << transaction.buyIndex
        << " sell on " << transaction.sellIndex << std::endl;
    EXPECT_EQ(transaction.maxProfit, 2);
    EXPECT_EQ(transaction.buyIndex, 0);
    EXPECT_EQ(transaction.sellIndex, 1);
}

TEST(StockMaxProfit, MultipleTransactions1)
{
    std::vector<int> prices {5, 12, 14, 16, 13, 4, 15, 18, 17};
    Histogram::Print("Stock Prices:", prices, std::cout);
    auto transactions = Histogram::StockMaxProfitMultipleTransactions(prices);
    for (auto transaction : transactions)
    {
        std::cout << "Max profit is: " << transaction.maxProfit
            << " buy on " << transaction.buyIndex
            << " sell on " << transaction.sellIndex << std::endl;
    }
    ASSERT_EQ(transactions.size(), 2);
    EXPECT_EQ(transactions[0].maxProfit, 11);
    EXPECT_EQ(transactions[0].buyIndex, 0);
    EXPECT_EQ(transactions[0].sellIndex, 3);
    EXPECT_EQ(transactions[1].maxProfit, 14);
    EXPECT_EQ(transactions[1].buyIndex, 5);
    EXPECT_EQ(transactions[1].sellIndex, 7);
}

TEST(StockMaxProfit, MultipleTransactions2)
{
    std::vector<int> prices {10, 9, 8, 7, 6, 5, 4};
    Histogram::Print("Stock Prices:", prices, std::cout);
    auto transactions = Histogram::StockMaxProfitMultipleTransactions(prices);
    for (auto transaction : transactions)
    {
        std::cout << "Max profit is: " << transaction.maxProfit
            << " buy on " << transaction.buyIndex
            << " sell on " << transaction.sellIndex << std::endl;
    }
    ASSERT_EQ(transactions.size(), 0);
}

}
