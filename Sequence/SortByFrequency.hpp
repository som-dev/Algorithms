#pragma once

#include <vector>
#include <algorithm>
#include <map>
#include <utility>

namespace Sequence
{

std::vector<int> SortByFrequency(std::vector<int> sequence)
{
    std::vector<int> result;
    if (!sequence.empty())
    {

        std::map<int, size_t> elemFrequency;
        for (auto elem : sequence)
        {
            auto iter = elemFrequency.find(elem);
            if (iter == elemFrequency.end())
            {
                iter = elemFrequency.insert(std::make_pair(elem, 0)).first;
            }
            ++(iter->second);
        }
        std::map<size_t, std::vector<int>> elemsByCount;
        for (auto pair : elemFrequency)
        {
            for (size_t i = 0; i < pair.second; ++i)
            {
                elemsByCount[pair.second].push_back(pair.first);
            }
        }

        for (auto pair : elemsByCount)
        {
            result.insert(result.end(), pair.second.begin(), pair.second.end());
        }
    }
    return result;
}

}
