#pragma once

#include "Tree.hpp"
#include <list>
#include <map>

template <typename NodeType>
void GetVerticalOrderHelper(const typename NodeType::Ptr& node, int horizontalLevel, std::map<int, std::list<typename NodeType::Ptr>>& verticals)
{
    if (node == nullptr) return;
    verticals[horizontalLevel].push_back(node);
    GetVerticalOrderHelper<NodeType>(node->left, horizontalLevel-1, verticals);
    GetVerticalOrderHelper<NodeType>(node->right, horizontalLevel+1, verticals);
}

template <typename NodeType>
void GetVerticalOrder(const typename NodeType::Ptr& node, std::list<typename NodeType::Ptr>& nodes)
{
    std::map<int, std::list<typename NodeType::Ptr>> verticals;
    GetVerticalOrderHelper<NodeType>(node, 0, verticals);
    for (auto pair : verticals)
    {
        nodes.splice(nodes.end(), pair.second);
    }
}

template <typename NodeType>
void GetMinMaxHorizontalDistance(const typename NodeType::Ptr& node, int currentHorizontalLevel, int& minHorizontalLevel, int& maxHorizontalLevel)
{
    if (node == nullptr) return;
    minHorizontalLevel = std::min(currentHorizontalLevel, minHorizontalLevel);
    maxHorizontalLevel = std::max(currentHorizontalLevel, maxHorizontalLevel);
    GetMinMaxHorizontalDistance<NodeType>(node->left, currentHorizontalLevel-1, minHorizontalLevel, maxHorizontalLevel);
    GetMinMaxHorizontalDistance<NodeType>(node->right, currentHorizontalLevel+1, minHorizontalLevel, maxHorizontalLevel);
}

template <typename NodeType>
void GetVerticalLine(const typename NodeType::Ptr& node, int horizontalLevel, std::list<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    if (horizontalLevel == 0) nodes.push_back(node);
    GetVerticalLine<NodeType>(node->left, horizontalLevel+1, nodes);
    GetVerticalLine<NodeType>(node->right, horizontalLevel-1, nodes);
}

template <typename NodeType>
void GetVerticalOrder2(const typename NodeType::Ptr& node, std::list<typename NodeType::Ptr>& nodes)
{
    int minHorizontalLevel = 0;
    int maxHorizontalLevel = 0;
    GetMinMaxHorizontalDistance<NodeType>(node, 0, minHorizontalLevel, maxHorizontalLevel);
    for (int level = minHorizontalLevel; level <= maxHorizontalLevel; ++level)
    {
        std::list<typename NodeType::Ptr> verticalNodes;
        GetVerticalLine<NodeType>(node, level, verticalNodes);
        nodes.splice(nodes.end(), verticalNodes);
    }
}
