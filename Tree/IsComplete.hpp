#pragma once

#include "Count.hpp"
#include <queue>

namespace Tree
{

template <typename NodeType>
bool IsCompleteHelper(const typename NodeType::Ptr& node, size_t index, size_t count)
{
    if (node == nullptr)
        return true;
    else if (index >= count)
        return false;
    else
        return IsCompleteHelper<NodeType>(node->left, index*2 + 1, count) && IsCompleteHelper<NodeType>(node->right, index*2 + 2, count);
}

template <typename NodeType>
bool IsCompleteRecusrive(const typename NodeType::Ptr& root)
{
    return IsCompleteHelper<NodeType>(root, 0, CalculateCount<NodeType>(root));
}

template <typename NodeType>
bool IsCompleteIterative(const typename NodeType::Ptr& root)
{
    std::queue<typename NodeType::Ptr> queue;
    queue.push(root);
    bool nonFullNodeSeen = false;
    while (!queue.empty())
    {
        auto front = queue.front();
        queue.pop();
        if (front->left)
        {
            if (nonFullNodeSeen)
                return false;
            else
                queue.push(front->left);
        }
        else nonFullNodeSeen = true;
        if (front->right)
        {
            if (nonFullNodeSeen)
                return false;
            else
                queue.push(front->right);
        }
        else nonFullNodeSeen = true;
    }
    return true;
}

}
