#include "gtest/gtest.h"

#include "Tree.hpp"
#include "LevelOrder.hpp"
#include "PrettyPrint.hpp"

TEST(LevelOrder, Test)
{
    using NodeType = Node<int>;
    auto root                  = NodeType::Create(20);
    root->left                 = NodeType::Create(8);
    root->left->left           = NodeType::Create(4);
    root->left->right          = NodeType::Create(12);
    root->left->right->left    = NodeType::Create(10);
    root->left->right->right   = NodeType::Create(14);
    root->right                = NodeType::Create(22);
    root->right->right         = NodeType::Create(25);

    PrintPretty<NodeType>(root, 1, 0, std::cout);

    std::list<typename NodeType::Ptr> nodes;
    GetLevelOrder<NodeType>(root, nodes);
    std::cout << std::endl << "Level Order: " << std::endl;
    for (auto node : nodes)
    {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

}
