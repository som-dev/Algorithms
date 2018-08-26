#pragma once

#include <vector>
#include <stack>

namespace Histogram
{

// The span of a stock’s price on a given day i is defined as the maximum number
// of consecutive days just before the given day, for which the price of the
// stock on the current day is less than or equal to its price on the given day.

std::vector<int> StockSpan(const std::vector<int>& prices)
{
    std::vector<int> spans(prices.size());
    std::stack<size_t> higherPriceIndex;
    // start scanning each day's price
    for (size_t i = 0; i < prices.size(); ++i)
    {
        // remove all indexes (days) where price was less than or equal to
        // the current price
        while (!higherPriceIndex.empty() && prices[i] >= prices[higherPriceIndex.top()])
            higherPriceIndex.pop();
        // calculate the number of days until the price got higher
        int higherIndex = -1;
        if (!higherPriceIndex.empty())
            higherIndex = higherPriceIndex.top();
        spans[i] = i - higherIndex;
        // push this day's price onto stack
        higherPriceIndex.push(i);
    }
    return spans;
}

}
