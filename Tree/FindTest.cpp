#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "Find.hpp"
#include "PrintPretty.hpp"
#include "PrintNodes.hpp"

namespace
{

TEST(Find, Find)
{
    using NodeType = Tree::BinaryNode<int>;
    auto root                  = NodeType::Create(20);
    root->left                 = NodeType::Create(8);
    root->left->left           = NodeType::Create(4);
    root->left->right          = NodeType::Create(12);
    root->left->right->left    = NodeType::Create(10);
    root->left->right->right   = NodeType::Create(14);
    root->right                = NodeType::Create(22);
    root->right->right         = NodeType::Create(25);

    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);

    EXPECT_TRUE(Tree::Contains<NodeType>(root, 20));
    EXPECT_TRUE(Tree::Contains<NodeType>(root, 8));
    EXPECT_TRUE(Tree::Contains<NodeType>(root, 4));
    EXPECT_TRUE(Tree::Contains<NodeType>(root, 12));
    EXPECT_TRUE(Tree::Contains<NodeType>(root, 10));
    EXPECT_TRUE(Tree::Contains<NodeType>(root, 14));
    EXPECT_TRUE(Tree::Contains<NodeType>(root, 22));
    EXPECT_TRUE(Tree::Contains<NodeType>(root, 25));
    EXPECT_FALSE(Tree::Contains<NodeType>(root, 0));
    EXPECT_FALSE(Tree::Contains<NodeType>(root, 21));
}

TEST(Find, FindEmpty)
{
    using NodeType = Tree::BinaryNode<int>;
    NodeType::Ptr root = nullptr;

    EXPECT_FALSE(Tree::Contains<NodeType>(root, 0));
    EXPECT_FALSE(Tree::Contains<NodeType>(root, 21));
}

TEST(Find, FindRecursive)
{
    using NodeType = Tree::BinaryNode<int>;
    auto root                  = NodeType::Create(20);
    root->left                 = NodeType::Create(8);
    root->left->left           = NodeType::Create(4);
    root->left->right          = NodeType::Create(12);
    root->left->right->left    = NodeType::Create(10);
    root->left->right->right   = NodeType::Create(14);
    root->right                = NodeType::Create(22);
    root->right->right         = NodeType::Create(25);

    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);

    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 20));
    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 8));
    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 4));
    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 12));
    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 10));
    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 14));
    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 22));
    EXPECT_TRUE(Tree::ContainsRecursive<NodeType>(root, 25));
    EXPECT_FALSE(Tree::ContainsRecursive<NodeType>(root, 0));
    EXPECT_FALSE(Tree::ContainsRecursive<NodeType>(root, 21));
}

TEST(Find, FindEmptyRecurisve)
{
    using NodeType = Tree::BinaryNode<int>;
    NodeType::Ptr root = nullptr;

    EXPECT_FALSE(Tree::ContainsRecursive<NodeType>(root, 0));
    EXPECT_FALSE(Tree::ContainsRecursive<NodeType>(root, 21));
}

}
