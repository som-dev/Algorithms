#pragma once

#include "Tree.hpp"
#include <list>

template <typename NodeType>
void GetPostOrder(const typename NodeType::Ptr& node, std::list<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    GetPostOrder<NodeType>(node->left, nodes);
    GetPostOrder<NodeType>(node->right, nodes);
    nodes.push_back(node);
}
