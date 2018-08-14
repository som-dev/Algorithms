#pragma once

template <typename NodeType>
size_t CalculateHeight(const typename NodeType::Ptr& node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + std::max(CalculateHeight<NodeType>(node->left), CalculateHeight<NodeType>(node->right));
}
