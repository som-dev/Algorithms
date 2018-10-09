#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "MaxAncestorDifference.hpp"
#include "PrintPretty.hpp"
#include "PrintNodes.hpp"

namespace
{

using NodeType = Tree::BinaryNode<int>;

NodeType::Ptr CreateTree()
{
    auto root                  = NodeType::Create(8);
    root->left                 = NodeType::Create(3);
    root->left->left           = NodeType::Create(1);
    root->left->right          = NodeType::Create(6);
    root->left->right->left    = NodeType::Create(4);
    root->left->right->right   = NodeType::Create(7);
    root->right                = NodeType::Create(10);
    root->right->right         = NodeType::Create(14);
    root->right->right->left   = NodeType::Create(13);
    return root;
}

TEST(MaxAncestorDifference, Test1)
{
    auto root = CreateTree();
    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);
    auto result = Tree::MaxAncestorDifference<NodeType>(root);
    std::cout << "Max difference is " << result << std::endl;
    EXPECT_EQ(result, 7);
}

TEST(MaxAncestorDifference, Test2)
{
    auto root = CreateTree();
    root->right->right->right = NodeType::Create(-4);
    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);
    auto result = Tree::MaxAncestorDifference<NodeType>(root);
    std::cout << "Max difference is " << result << std::endl;
    EXPECT_EQ(result, 18);
}

}
