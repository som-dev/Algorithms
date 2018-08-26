#include "gtest/gtest.h"

#include "SinglyLinkedNode.hpp"
#include "Reverse.hpp"
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

void VerifyListReverse(const NodeType::Ptr& head)
{
    EXPECT_EQ(head->data,                                           25);
    EXPECT_EQ(head->next->data,                                     22);
    EXPECT_EQ(head->next->next->data,                               14);
    EXPECT_EQ(head->next->next->next->data,                         10);
    EXPECT_EQ(head->next->next->next->next->data,                   12);
    EXPECT_EQ(head->next->next->next->next->next->data,             4);
    EXPECT_EQ(head->next->next->next->next->next->next->data,       8);
    EXPECT_EQ(head->next->next->next->next->next->next->next->data, 20);
}

TEST(Reverse, ReverseInPlaceWithStorage)
{
    auto head = CreateList();
    LinkedList::Print<NodeType>("Original List: ", head, std::cout);
    LinkedList::ReverseInPlaceWithStorage<NodeType>(head);
    LinkedList::Print<NodeType>("Reverse In Place With Storage: ", head, std::cout);
    VerifyListReverse(head);
}

TEST(Reverse, ReverseInPlace)
{
    auto head = CreateList();
    LinkedList::Print<NodeType>("Original List:", head, std::cout);
    LinkedList::ReverseInPlace<NodeType>(head);
    LinkedList::Print<NodeType>("Reverse In Place:", head, std::cout);
    VerifyListReverse(head);
}

}
