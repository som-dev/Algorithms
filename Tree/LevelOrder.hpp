#pragma once

#include "Height.hpp"
#include <vector>
#include <queue>

namespace Tree
{

template <typename NodeType>
void GetLevel(const typename NodeType::Ptr& node, size_t level, std::vector<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr)
    {
        return;
    }
    else if (level == 1)
    {
        nodes.push_back(node);
    }
    else
    {
        GetLevel<NodeType>(node->left, level - 1, nodes);
        GetLevel<NodeType>(node->right, level - 1, nodes);
    }
}

template <typename NodeType>
void GetLevelOrderRecursive(const typename NodeType::Ptr& root, std::vector<typename NodeType::Ptr>& nodes)
{
    size_t height = CalculateHeight<NodeType>(root);
    for (size_t i = 1; i <= height; ++i)
    {
        std::vector<typename NodeType::Ptr> levelNodes;
        GetLevel<NodeType>(root, i, levelNodes);
        nodes.insert(nodes.end(), levelNodes.begin(), levelNodes.end());
    }
}

template <typename NodeType>
void GetLevelOrderIterative(const typename NodeType::Ptr& root, std::vector<typename NodeType::Ptr>& nodes)
{
    std::queue<typename NodeType::Ptr> queue;
    queue.push(root);
    while (!queue.empty())
    {
        auto& front = queue.front();
        nodes.push_back(front);
        if (front->left != nullptr)  queue.push(front->left);
        if (front->right != nullptr) queue.push(front->right);
        queue.pop();
    }
}

}
