#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "IsComplete.hpp"
#include "PrintPretty.hpp"

namespace
{

using NodeType = Tree::BinaryNode<int>;

NodeType::Ptr CreateIncompleteTree()
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

NodeType::Ptr CreateCompleteTree()
{
    auto root                  = NodeType::Create(20);
    root->left                 = NodeType::Create(8);
    root->left->left           = NodeType::Create(4);
    root->left->right          = NodeType::Create(12);
    root->left->right->left    = NodeType::Create(10);
    root->left->right->right   = NodeType::Create(14);
    root->right                = NodeType::Create(22);
    root->right->right         = NodeType::Create(25);
    root->left->left->left     = NodeType::Create(1);
    root->left->left->right    = NodeType::Create(2);
    root->right->left          = NodeType::Create(3);
    return root;
}

TEST(IsComplete, IncompleteRecursive)
{
    auto root = CreateIncompleteTree();
    Tree::PrintPretty<NodeType>("Incomplete Tree:", root, 1, 0, std::cout);
    auto result = Tree::IsCompleteRecusrive<NodeType>(root);
    std::cout << std::endl << "Is Complete (recursive): " << result << std::endl;
    EXPECT_FALSE(result);
}

TEST(IsComplete, IncompleteIterative)
{
    auto root = CreateIncompleteTree();
    Tree::PrintPretty<NodeType>("Incomplete Tree:", root, 1, 0, std::cout);
    auto result = Tree::IsCompleteIterative<NodeType>(root);
    std::cout << std::endl << "Is Complete (iterative): " << Tree::IsCompleteIterative<NodeType>(root) << std::endl;
    EXPECT_FALSE(result);
}

TEST(IsComplete, CompleteRecursive)
{
    auto root = CreateCompleteTree();
    Tree::PrintPretty<NodeType>("Complete Tree:", root, 1, 0, std::cout);
    auto result = Tree::IsCompleteRecusrive<NodeType>(root);
    std::cout << std::endl << "Is Complete (recursive): " << result << std::endl;
    EXPECT_TRUE(result);
}

TEST(IsComplete, CompleteIterative)
{
    auto root = CreateCompleteTree();
    Tree::PrintPretty<NodeType>("Complete Tree:", root, 1, 0, std::cout);
    auto result = Tree::IsCompleteIterative<NodeType>(root);
    std::cout << std::endl << "Is Complete (iterative): " << Tree::IsCompleteIterative<NodeType>(root) << std::endl;
    EXPECT_TRUE(result);
}

}
