#pragma once

#include <utility>
#include <algorithm>

namespace Interval
{

std::vector<std::pair<int,int>> MergeOverlap(const std::vector<std::pair<int,int>>& intervals)
{
    std::vector<std::pair<int,int>> result;
    if (intervals.empty()) return result;

    auto sortedIntervals = intervals;
    std::sort(sortedIntervals.begin(), sortedIntervals.end(),
        [](const std::pair<int,int>& a, const std::pair<int,int>& b)
        {
            return a.first < b.first;
        });

    result.push_back(sortedIntervals[0]);
    for (size_t i = 1; i < sortedIntervals.size(); ++i)
    {
        const auto& currentInterval = sortedIntervals[i];
        auto& lastInterval = result.back();
        if (currentInterval.first > lastInterval.second)
        {
            result.push_back(currentInterval);
        }
        else
        {
            if (currentInterval.second > lastInterval.second)
            {
                lastInterval.second = currentInterval.second;
            }
        }
    }
    return result;
}

}
