#pragma once

#include <list>

template <typename NodeType>
void GetInOrder(const typename NodeType::Ptr& node, std::list<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    GetInOrder<NodeType>(node->left, nodes);
    nodes.push_back(node);
    GetInOrder<NodeType>(node->right, nodes);
}
