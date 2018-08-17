#include "gtest/gtest.h"

#include "SinglyLinkedNode.hpp"
#include "ReverseEveryK.hpp"
#include "Print.hpp"
#include <list>

TEST(ReverseEveryK, Test)
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
    ReverseEveryKWithStorage<NodeType>(head, 3, nodes);
    std::cout << std::endl << "Reverse Every K With Storage: " << std::endl;
    for (auto node : nodes)
    {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    ReverseEveryKWithStorageInPlace<NodeType>(head, 3);
    std::cout << std::endl << "Reverse Every K With Storage In Place: " << std::endl;
    Print<NodeType>(head, std::cout);

    head = ReverseEveryKInPlace<NodeType>(head, 3);
    std::cout << std::endl << "Reverse Every K In Place: " << std::endl;
    Print<NodeType>(head, std::cout);
}
