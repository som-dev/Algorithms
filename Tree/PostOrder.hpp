#pragma once

#include <vector>

namespace Tree
{

template <typename NodeType>
void GetPostOrder(const typename NodeType::Ptr& node, std::vector<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    GetPostOrder<NodeType>(node->left, nodes);
    GetPostOrder<NodeType>(node->right, nodes);
    nodes.push_back(node);
}

}
