#pragma once

namespace Tree
{

template <typename NodeType>
bool Contains(const typename NodeType::Ptr& node, const typename NodeType::DataType& value)
{
    typename NodeType::Ptr curr = node;
    while (curr != nullptr)
    {
        if (curr->data == value) return true;
        if (curr->data > value)  curr = curr->left;
        else                     curr = curr->right;
    }
    return false;
}

template <typename NodeType>
bool ContainsRecursive(const typename NodeType::Ptr& node, const typename NodeType::DataType& value)
{
    if (node == nullptr)    return false;
    if (node->data < value) return ContainsRecursive<NodeType>(node->right, value);
    if (node->data > value) return ContainsRecursive<NodeType>(node->left, value);
    return true; // node->data == value
}

}
