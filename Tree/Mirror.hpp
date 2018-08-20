#pragma once

#include <algorithm>

namespace Tree
{

template <typename NodeType>
void Mirror(const typename NodeType::Ptr& node)
{
    if (node == nullptr) return;
    std::swap(node->left, node->right);
    Mirror<NodeType>(node->left);
    Mirror<NodeType>(node->right);
}

}
