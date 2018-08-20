#include "gtest/gtest.h"

#include "SinglyLinkedNode.hpp"
#include "ReverseEveryK.hpp"
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

void VerifyListReverseEvery3(const NodeType::Ptr& head)
{
    EXPECT_EQ(head->data,                                           4);
    EXPECT_EQ(head->next->data,                                     8);
    EXPECT_EQ(head->next->next->data,                               20);
    EXPECT_EQ(head->next->next->next->data,                         14);
    EXPECT_EQ(head->next->next->next->next->data,                   10);
    EXPECT_EQ(head->next->next->next->next->next->data,             12);
    EXPECT_EQ(head->next->next->next->next->next->next->data,       25);
    EXPECT_EQ(head->next->next->next->next->next->next->next->data, 22);
}

TEST(LinkedList, ReverseEveryKInPlaceWithStorage)
{
    auto head = CreateList();
    LinkedList::Print<NodeType>("Original List:", head, std::cout);
    LinkedList::ReverseEveryKInPlaceWithStorage<NodeType>(head, 3);
    LinkedList::Print<NodeType>("Reverse Every K With Storage In Place:", head, std::cout);
    VerifyListReverseEvery3(head);
}

TEST(LinkedList, ReverseEveryKInPlace)
{
    auto head = CreateList();
    LinkedList::Print<NodeType>("Original List:", head, std::cout);
    head = LinkedList::ReverseEveryKInPlace<NodeType>(head, 3);
    LinkedList::Print<NodeType>("Reverse Every K In Place:", head, std::cout);
    VerifyListReverseEvery3(head);
}

}
