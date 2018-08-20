#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "VerticalOrder.hpp"
#include "PrintPretty.hpp"
#include "PrintNodes.hpp"

namespace
{
using NodeType = Tree::BinaryNode<int>;

NodeType::Ptr CreateTree()
{
    auto root                  = NodeType::Create(20);
    root->left                 = NodeType::Create(8);
    root->left->left           = NodeType::Create(4);
    root->left->right          = NodeType::Create(12);
    root->left->right->left    = NodeType::Create(10);
    root->left->right->right   = NodeType::Create(14);
    root->right                = NodeType::Create(22);
    root->right->right         = NodeType::Create(25);
    return root;
}

void VerifyVertical(const std::vector<NodeType::Ptr>& nodes)
{
    EXPECT_EQ(nodes.size(), 8);
    EXPECT_EQ(nodes[0]->data, 4);
    EXPECT_EQ(nodes[1]->data, 8);
    EXPECT_EQ(nodes[2]->data, 10);
    EXPECT_EQ(nodes[3]->data, 20);
    EXPECT_EQ(nodes[4]->data, 12);
    EXPECT_EQ(nodes[5]->data, 14);
    EXPECT_EQ(nodes[6]->data, 22);
    EXPECT_EQ(nodes[7]->data, 25);
}

TEST(Tree, VerticalOrder)
{
    auto root = CreateTree();
    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);

    std::vector<NodeType::Ptr> nodes;
    Tree::GetVerticalOrder<NodeType>(root, nodes);
    Tree::PrintNodes<NodeType>("Vertical Order:", nodes, std::cout);
    VerifyVertical(nodes);
}

TEST(Tree, VerticalOrder2)
{
    auto root = CreateTree();
    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);
    std::vector<NodeType::Ptr> nodes;
    Tree::GetVerticalOrder2<NodeType>(root, nodes);
    Tree::PrintNodes<NodeType>("Vertical Order 2:", nodes, std::cout);
    VerifyVertical(nodes);
}

}
