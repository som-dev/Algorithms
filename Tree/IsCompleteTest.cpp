#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "IsComplete.hpp"
#include "PrintPretty.hpp"

TEST(Tree, IsComplete)
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

    Tree::PrintPretty<NodeType>("Incomplete Tree:", root, 1, 0, std::cout);

    std::cout << std::endl << "Is Complete (recursive): " << Tree::IsCompleteRecusrive<NodeType>(root) << std::endl;
    EXPECT_FALSE(Tree::IsCompleteRecusrive<NodeType>(root));
    std::cout << std::endl << "Is Complete (iterative): " << Tree::IsCompleteIterative<NodeType>(root) << std::endl;
    EXPECT_FALSE(Tree::IsCompleteIterative<NodeType>(root));

    // now complete the tree
    root->left->left->left     = NodeType::Create(1);
    root->left->left->right    = NodeType::Create(2);
    root->right->left          = NodeType::Create(3);

    Tree::PrintPretty<NodeType>("Complete Tree", root, 1, 0, std::cout);

    std::cout << std::endl << "Is Complete (recursive): " << Tree::IsCompleteRecusrive<NodeType>(root) << std::endl;
    EXPECT_TRUE(Tree::IsCompleteRecusrive<NodeType>(root));
    std::cout << std::endl << "Is Complete (iterative): " << Tree::IsCompleteIterative<NodeType>(root) << std::endl;
    EXPECT_TRUE(Tree::IsCompleteIterative<NodeType>(root));
}
