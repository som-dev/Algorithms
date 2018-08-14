#pragma once

#include "Tree.hpp"
#include <list>

template <typename NodeType>
void GetPreOrder(const typename NodeType::Ptr& node, std::list<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    nodes.push_back(node);
    GetPreOrder<NodeType>(node->left, nodes);
    GetPreOrder<NodeType>(node->right, nodes);
}
