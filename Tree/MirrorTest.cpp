#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "Mirror.hpp"
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

void VerifyMirror(const NodeType::Ptr& root)
{
    EXPECT_EQ(root->data,                       20);
    EXPECT_EQ(root->right->data,                8);
    EXPECT_EQ(root->right->right->data,         4);
    EXPECT_EQ(root->right->left->data,          12);
    EXPECT_EQ(root->right->left->right->data,   10);
    EXPECT_EQ(root->right->left->left->data,    14);
    EXPECT_EQ(root->left->data,                 22);
    EXPECT_EQ(root->left->left->data,           25);
}

TEST(Mirror, Mirror)
{
    auto root = CreateTree();
    Tree::PrintPretty<NodeType>("Original Tree:", root, 1, 0, std::cout);
    Tree::Mirror<NodeType>(root);
    Tree::PrintPretty<NodeType>("Mirror Tree:", root, 1, 0, std::cout);
    VerifyMirror(root);
}

}
