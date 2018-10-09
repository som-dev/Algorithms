#pragma once

#include <limits>

namespace Tree
{

template <typename NodeType>
int MaxAncestorDifferenceHelper(const typename NodeType::Ptr& node, int& difference)
{
    if (node == nullptr)
    {
        return std::numeric_limits<int>::max();
    }
    else
    {
        auto leftMin = MaxAncestorDifferenceHelper<NodeType>(node->left, difference);
        auto rightMin = MaxAncestorDifferenceHelper<NodeType>(node->right, difference);
        auto min = std::min(leftMin, rightMin);
        if (node->data < min)
        {
            min = node->data;
        }
        auto diff = node->data - min;
        if (diff > difference)
        {
            difference = diff;
        }
        return min;
    }
}

template <typename NodeType>
int MaxAncestorDifference(const typename NodeType::Ptr& root)
{
    int diff = std::numeric_limits<int>::lowest();
    MaxAncestorDifferenceHelper<NodeType>(root, diff);
    return diff;
}

}
