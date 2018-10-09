#pragma once

#include <vector>
#include <algorithm>

namespace Sequence
{

std::vector<int> SumOfPairs(std::vector<int> sequence, int targetSum)
{
    std::vector<int> result;
    std::sort(sequence.begin(), sequence.end());
    size_t leftPos = 0;
    size_t rightPos = sequence.size() - 1;
    while (leftPos < rightPos)
    {
        auto sum = sequence[leftPos] + sequence[rightPos];
        if (targetSum == sum)
        {
            result.push_back(sequence[leftPos]);
            result.push_back(sequence[rightPos]);
            break;
        }
        else if (sum < targetSum)
        {
            ++leftPos;
        }
        else // sum > targetSum
        {
            --rightPos;
        }
    }
    return result;
}

}
