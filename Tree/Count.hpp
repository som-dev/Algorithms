#pragma once

namespace Tree
{

template <typename NodeType>
size_t CalculateCount(const typename NodeType::Ptr& node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + CalculateCount<NodeType>(node->left) + CalculateCount<NodeType>(node->right);
}

}
