#pragma once

#include <vector>

namespace Tree
{

template <typename NodeType>
void GetInOrder(const typename NodeType::Ptr& node, std::vector<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    GetInOrder<NodeType>(node->left, nodes);
    nodes.push_back(node);
    GetInOrder<NodeType>(node->right, nodes);
}

}
