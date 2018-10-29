#pragma once

#include <vector>

namespace Tree
{

template <typename NodeType>
void GetLeftBoundary(const typename NodeType::Ptr& node, std::vector<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    if (node->left)
    {
        nodes.push_back(node);
        GetLeftBoundary<NodeType>(node->left, nodes);
    }
    else if (node->right)
    {
        nodes.push_back(node);
        GetLeftBoundary<NodeType>(node->right, nodes);
    }
    // else node->left and node->right are nullptr so skip leaf
}

template <typename NodeType>
void GetRightBoundary(const typename NodeType::Ptr& node, std::vector<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    if (node->right)
    {
        GetRightBoundary<NodeType>(node->right, nodes);
        nodes.push_back(node);
    }
    else if (node->left)
    {
        GetRightBoundary<NodeType>(node->left, nodes);
        nodes.push_back(node);
    }
    // else node->left and node->right are nullptr so skip leaf
}

template <typename NodeType>
void GetLeaves(const typename NodeType::Ptr& node, std::vector<typename NodeType::Ptr>& nodes)
{
    if (node == nullptr) return;
    GetLeaves<NodeType>(node->left, nodes);
    if (node->left == nullptr && node->right == nullptr)
    {
        nodes.push_back(node);
    }
    GetLeaves<NodeType>(node->right, nodes);
}

// combination of algorithms:
// 1) print root
// 1) print the left boundary (pre-order style)
// 2) print the leaves from left (in-order style)
// 3) print the leaves from right (in-order style)
// 3) print the right boundary (post-order style)
template <typename NodeType>
void GetBoundaryOrder(const typename NodeType::Ptr& root, std::vector<typename NodeType::Ptr>& nodes)
{
    nodes.push_back(root);
    GetLeftBoundary<NodeType>(root->left, nodes);
    GetLeaves<NodeType>(root->left, nodes);
    GetLeaves<NodeType>(root->right, nodes);
    GetRightBoundary<NodeType>(root->right, nodes);
}

}
