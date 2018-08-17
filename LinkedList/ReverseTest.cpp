#include "gtest/gtest.h"

#include "SinglyLinkedNode.hpp"
#include "Reverse.hpp"
#include "Print.hpp"
#include <list>

TEST(Reverse, Test)
{
    using NodeType = SinglyLinkedNode<int>;
    auto head                                       = NodeType::Create(20);
    head->next                                      = NodeType::Create(8);
    head->next->next                                = NodeType::Create(4);
    head->next->next->next                          = NodeType::Create(12);
    head->next->next->next->next                    = NodeType::Create(10);
    head->next->next->next->next->next              = NodeType::Create(14);
    head->next->next->next->next->next->next        = NodeType::Create(22);
    head->next->next->next->next->next->next->next  = NodeType::Create(25);

    Print<NodeType>(head, std::cout);

    std::list<typename NodeType::Ptr> nodes;
    ReverseWithStorage<NodeType>(head, nodes);
    std::cout << std::endl << "Reverse With Storage: " << std::endl;
    for (auto node : nodes)
    {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    ReverseInPlaceWithStorage<NodeType>(head);
    std::cout << std::endl << "Reverse In Place With Storage: " << std::endl;
    Print<NodeType>(head, std::cout);

    ReverseInPlace<NodeType>(head);
    std::cout << std::endl << "Reverse In Place: " << std::endl;
    Print<NodeType>(head, std::cout);

}
