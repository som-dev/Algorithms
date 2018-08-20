#pragma once

#include <vector>

namespace Tree
{

template <typename NodeType>
void GetPreOrder(const typename NodeType::Ptr& node, std::vector<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    nodes.push_back(node);
    GetPreOrder<NodeType>(node->left, nodes);
    GetPreOrder<NodeType>(node->right, nodes);
}

}
