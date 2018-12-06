#pragma once

#include <set>
#include <vector>

namespace Sequence
{

void SubsetsHelper(std::set<int>& sequence, std::set<std::set<int>>& results)
{
    auto iter = std::find(results.begin(), results.end(), sequence);
    if (iter != results.end()) return;
    results.insert(sequence);
    if (sequence.empty()) return;
    auto sequenceCopy = sequence;
    for (auto i : sequence)
    {
        sequenceCopy.erase(i);
        SubsetsHelper(sequenceCopy, results);
        sequenceCopy.insert(i);
    }
}

std::set<std::set<int>> Subsets(const std::set<int>& sequence)
{
    std::set<std::set<int>> results;
    auto seq = sequence;
    SubsetsHelper(seq, results);
    return results;
}

}
