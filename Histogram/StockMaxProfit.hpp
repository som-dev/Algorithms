#pragma once

#include <vector>
#include <stack>

namespace Histogram
{

struct Transaction
{
    int    maxProfit;
    size_t buyIndex;
    size_t sellIndex;
    Transaction() : maxProfit(0), buyIndex(0), sellIndex(0) { };
};

Transaction StockMaxProfitOneTransaction(const std::vector<int>& prices)
{
    Transaction transaction;
    size_t minIndex = 0;
    for (size_t i = 1; i < prices.size(); ++i)
    {
        if (prices[i] < prices[minIndex])
            minIndex = i;
        int delta = prices[i] - prices[minIndex];
        if (delta > transaction.maxProfit)
        {
            transaction.maxProfit = delta;
            transaction.buyIndex = minIndex;
            transaction.sellIndex = i;
        }
    }
    return transaction;
}

std::vector<Transaction> StockMaxProfitMultipleTransactions(const std::vector<int>& prices)
{
    std::vector<Transaction> transactions;
    Transaction transaction;
    size_t minIndex = 0;
    for (size_t i = 1; i < prices.size(); ++i)
    {
        if (prices[i] < prices[i-1])
        {
            if (transaction.maxProfit > 0)
            {
                transactions.push_back(transaction);
                transaction.maxProfit = 0;
            }
            minIndex = i;
        }
        if (prices[i] < prices[minIndex])
            minIndex = i;
        int delta = prices[i] - prices[minIndex];
        if (delta > transaction.maxProfit)
        {
            transaction.maxProfit = delta;
            transaction.buyIndex = minIndex;
            transaction.sellIndex = i;
        }
    }
    return transactions;
}

}
