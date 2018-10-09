#pragma once

#include <vector>
#include <string>
#include <algorithm>

namespace Sequence
{

int Combine(int a, int b)
{
    int multiplier = 1;
    while (multiplier < b) multiplier *= 10;
    return a * multiplier + b;
}

std::string LargestNumber(std::vector<int> sequence)
{
    std::string result;
    std::sort(sequence.begin(), sequence.end(),
        [](int a, int b)
        {
            auto ab = Combine(a,b);
            auto ba = Combine(b,a);
            return ab > ba;
        });

    for (auto num : sequence)
    {
        result += std::to_string(num);
    }
    return result;
}

}
