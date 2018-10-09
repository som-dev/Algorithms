#pragma once

#include <vector>
#include <deque>

namespace Sequence
{

std::vector<int> SlidingWindowMax(const std::vector<int>& sequence, size_t K)
{
    std::vector<int> result;
    // Create a deque that stores indexes of sequence elements.
    // The queue will store indexes of "useful" elements in every window
    // and it will maintain decreasing order of values from front to rear
    std::deque<size_t> deque(K);

    // process the first K elements
    size_t i = 0;
    for ( ; i < K; ++i)
    {
        // For each element, the previous smaller elements are pointless so
        // we can remove them
        while ( !deque.empty() && sequence[i] >= sequence[deque.back()])
        {
            deque.pop_back();
        }
        deque.push_back(i);
    }

    // process remaining elements
    for ( ; i < sequence.size(); ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window
        result.push_back(sequence[deque.front()]);

        // Remove the elements which are now past the new sliding window
        size_t leftWindowIndex = i - K;
        while ( !deque.empty() && deque.front() <= leftWindowIndex)
        {
            deque.pop_front();
        }

        // For each element, the previous smaller elements are pointless so
        // we can remove them
        while ( !deque.empty() && sequence[i] >= sequence[deque.back()])
        {
            deque.pop_back();
        }
        deque.push_back(i);
    }

    // The element at the front of the queue is the largest element of
    // the last window
    result.push_back(sequence[deque.front()]);
    return result;
}

}
