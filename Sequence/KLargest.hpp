#pragma once

#include <vector>
#include "../Heap/MinHeap.hpp"

namespace Sequence
{

std::vector<int> KLargest(const std::vector<int>& sequence, size_t K)
{
    std::vector<int> result;
    Heap::MinHeap<int> minHeap;
    for (auto i : sequence)
    {
        if (minHeap.size() < K)
        {
            minHeap.add(i);
        }
        else if (i > minHeap.getMin())
        {
            minHeap.removeMin();
            minHeap.add(i);
        }
    }
    while (!minHeap.empty())
    {
        result.push_back(minHeap.getMin());
        minHeap.removeMin();
    }
    return result;
}

}
