#include "gtest/gtest.h"

#include "SinglyLinkedNode.hpp"
#include "KthNodeFromEnd.hpp"
#include "Print.hpp"

namespace {

using NodeType = LinkedList::SinglyLinkedNode<int>;

NodeType::Ptr CreateList()
{
    auto head                                       = NodeType::Create(20);
    head->next                                      = NodeType::Create(8);
    head->next->next                                = NodeType::Create(4);
    head->next->next->next                          = NodeType::Create(12);
    head->next->next->next->next                    = NodeType::Create(10);
    head->next->next->next->next->next              = NodeType::Create(14);
    head->next->next->next->next->next->next        = NodeType::Create(22);
    head->next->next->next->next->next->next->next  = NodeType::Create(25);
    return head;
}

TEST(LinkedList, KthNodeFromEnd)
{
    auto head = CreateList();
    LinkedList::Print<NodeType>("Original List:", head, std::cout);
    size_t K = 0;
    NodeType::Ptr expectedNode = head->next->next->next->next->next->next->next;
    auto actualNode = LinkedList::KthNodeFromEnd<NodeType>(head, K);
    std::cout << K << " from end: " << actualNode->data << std::endl;
    EXPECT_EQ(actualNode, expectedNode);

    K = 4;
    expectedNode = head->next->next->next;
    actualNode = LinkedList::KthNodeFromEnd<NodeType>(head, K);
    std::cout << K << " from end: " << actualNode->data << std::endl;
    EXPECT_EQ(actualNode, expectedNode);

    K = 7;
    expectedNode = head;
    actualNode = LinkedList::KthNodeFromEnd<NodeType>(head, K);
    std::cout << K << " from end: " << actualNode->data << std::endl;
    EXPECT_EQ(actualNode, expectedNode);

    K = 8;
    expectedNode = nullptr;
    actualNode = LinkedList::KthNodeFromEnd<NodeType>(head, K);
    EXPECT_EQ(actualNode, expectedNode);
}

}
