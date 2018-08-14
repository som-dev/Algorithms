#pragma once

#include "Tree.hpp"
#include "Height.hpp"
#include <list>

template <typename NodeType>
void GetLevel(const typename NodeType::Ptr& node, size_t level, std::list<typename NodeType::Ptr>& nodes)
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
void GetLevelOrder(const typename NodeType::Ptr& root, std::list<typename NodeType::Ptr>& nodes)
{
    size_t height = CalculateHeight<NodeType>(root);
    for (size_t i = 1; i <= height; ++i)
    {
        std::list<typename NodeType::Ptr> levelNodes;
        GetLevel<NodeType>(root, i, levelNodes);
        nodes.splice(nodes.end(), levelNodes);
    }
}
