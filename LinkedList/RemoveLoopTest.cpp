#include "gtest/gtest.h"

#include "SinglyLinkedNode.hpp"
#include "RemoveLoop.hpp"
#include "Print.hpp"

namespace {

using NodeType = LinkedList::SinglyLinkedNode<int>;

NodeType::Ptr CreateList()
{
    auto head                                       = NodeType::Create(1);
    head->next                                      = NodeType::Create(2);
    head->next->next                                = NodeType::Create(3);
    head->next->next->next                          = NodeType::Create(4);
    head->next->next->next->next                    = NodeType::Create(5);
    head->next->next->next->next->next              = head->next;
    return head;
}

void VerifyList(const NodeType::Ptr& head)
{
    EXPECT_EQ(head->data,                                           1);
    EXPECT_EQ(head->next->data,                                     2);
    EXPECT_EQ(head->next->next->data,                               3);
    EXPECT_EQ(head->next->next->next->data,                         4);
    EXPECT_EQ(head->next->next->next->next->data,                   5);
    EXPECT_EQ(head->next->next->next->next->next,             nullptr);
}

TEST(RemoveLoop, RemoveLoopWithHash)
{
    auto head = CreateList();
    LinkedList::RemoveLoopWithHash<NodeType>(head);
    LinkedList::Print<NodeType>("List without loop:", head, std::cout);
    VerifyList(head);
}

TEST(RemoveLoop, RemoveLoopFloyd)
{
    auto head = CreateList();
    LinkedList::RemoveLoopFloyd<NodeType>(head);
    LinkedList::Print<NodeType>("List without loop:", head, std::cout);
    VerifyList(head);
}

}
