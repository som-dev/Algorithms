#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "IsBst.hpp"
#include "PrintPretty.hpp"

TEST(IsBst, Test1)
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
    root->right->left          = NodeType::Create(1);

    Tree::PrintPretty<NodeType>("Non-BST Tree:", root, 1, 0, std::cout);

    std::cout << std::endl << "Is BST: " << Tree::IsBst<NodeType>(root) << std::endl;
    EXPECT_FALSE(Tree::IsBst<NodeType>(root));

    root->right->left->data = 21;

    Tree::PrintPretty<NodeType>("BST Tree", root, 1, 0, std::cout);

    std::cout << std::endl << "Is BST: " << Tree::IsBst<NodeType>(root) << std::endl;
    EXPECT_TRUE(Tree::IsBst<NodeType>(root));
}
