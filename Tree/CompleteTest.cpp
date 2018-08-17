#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "Complete.hpp"
#include "PrettyPrint.hpp"

TEST(IsComplete, Test)
{
    using NodeType = BinaryNode<int>;
    auto root                  = NodeType::Create(20);
    root->left                 = NodeType::Create(8);
    root->left->left           = NodeType::Create(4);
    root->left->right          = NodeType::Create(12);
    root->left->right->left    = NodeType::Create(10);
    root->left->right->right   = NodeType::Create(14);
    root->right                = NodeType::Create(22);
    root->right->right         = NodeType::Create(25);

    PrintPretty<NodeType>(root, 1, 0, std::cout);

    std::cout << std::endl << "Is Complete (recursive): " << IsCompleteRecusrive<NodeType>(root) << std::endl;
    std::cout << std::endl << "Is Complete (iterative): " << IsCompleteIterative<NodeType>(root) << std::endl;

    // now complete the tree
    root->left->left->left     = NodeType::Create(1);
    root->left->left->right    = NodeType::Create(2);
    root->right->left          = NodeType::Create(3);

    PrintPretty<NodeType>(root, 1, 0, std::cout);

    std::cout << std::endl << "Is Complete (recursive): " << IsCompleteRecusrive<NodeType>(root) << std::endl;
    std::cout << std::endl << "Is Complete (iterative): " << IsCompleteIterative<NodeType>(root) << std::endl;
}
