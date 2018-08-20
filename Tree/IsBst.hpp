#pragma once

#include <limits>

namespace Tree
{

template <typename NodeType>
bool IsBstHelper(const typename NodeType::Ptr& node, int currentMin, int currentMax)
{
    if (node == nullptr) return true;
    return node->data >= currentMin
        && node->data <= currentMax
        && IsBstHelper<NodeType>(node->left, currentMin, node->data)
        && IsBstHelper<NodeType>(node->right, node->data, currentMax);
}

template <typename NodeType>
bool IsBst(const typename NodeType::Ptr& root)
{
    return IsBstHelper<NodeType>(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

}
