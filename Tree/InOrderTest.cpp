#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "InOrder.hpp"
#include "PrettyPrint.hpp"

TEST(InOrder, Test)
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

    std::list<NodeType::Ptr> nodes;
    GetInOrder<NodeType>(root, nodes);
    std::cout << std::endl << "In Order: " << std::endl;
    for (auto node : nodes)
    {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;
}
