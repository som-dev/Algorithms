#pragma once

#include <vector>
#include <stack>

namespace Sequence
{

std::vector<int> NextLargerElement(const std::vector<int>& sequence)
{
    std::vector<int> result(sequence.size(), -1); // -1 to indicate not found
    std::stack<int> stack;
    // start from far end and work backwards
    for (size_t i = sequence.size()-1; i < sequence.size(); --i)
    {
        // find the most recent larger value on the stack
        // if it exists.  It is okay to pop the smaller ones
        // because our current entry will be larger making them useless.
        while (!stack.empty() && stack.top() <= sequence[i])
            stack.pop();
        // now check if there is a larger value
        if (!stack.empty() && stack.top() > sequence[i])
            result[i] = stack.top();
        // push this value onto the stack
        stack.push(sequence[i]);
    }
    return result;
}

}
