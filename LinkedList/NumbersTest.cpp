#include "gtest/gtest.h"

#include "SinglyLinkedNode.hpp"
#include "Numbers.hpp"
#include "Print.hpp"

namespace {

using NodeType = LinkedList::SinglyLinkedNode<int>;

TEST(Numbers, Sum1)
{
    auto lhs                                       = NodeType::Create(1);
    lhs->next                                      = NodeType::Create(8);
    lhs->next->next                                = NodeType::Create(4);
    lhs->next->next->next                          = NodeType::Create(2);

    auto rhs                                       = NodeType::Create(1);
    rhs->next                                      = NodeType::Create(2);
    rhs->next->next                                = NodeType::Create(4);
    rhs->next->next->next                          = NodeType::Create(9);

    LinkedList::Print<NodeType>("Lhs: ", lhs, std::cout);
    LinkedList::Print<NodeType>("Rhs: ", rhs, std::cout);
    auto sum = LinkedList::Sum<NodeType>(lhs, rhs);
    LinkedList::Print<NodeType>("Sum: ", sum, std::cout);

    EXPECT_EQ(sum->data,                            3);
    EXPECT_EQ(sum->next->data,                      0);
    EXPECT_EQ(sum->next->next->data,                9);
    EXPECT_EQ(sum->next->next->next->data,          1);
}

TEST(Numbers, Sum2)
{
    auto lhs                                       = NodeType::Create(2);
    lhs->next                                      = NodeType::Create(4);
    lhs->next->next                                = NodeType::Create(8);
    lhs->next->next->next                          = NodeType::Create(1);

    auto rhs                                       = NodeType::Create(9);
    rhs->next                                      = NodeType::Create(4);
    rhs->next->next                                = NodeType::Create(2);
    rhs->next->next->next                          = NodeType::Create(1);

    LinkedList::Print<NodeType>("Lhs: ", lhs, std::cout);
    LinkedList::Print<NodeType>("Rhs: ", rhs, std::cout);
    auto sum = LinkedList::Sum<NodeType>(lhs, rhs);
    LinkedList::Print<NodeType>("Sum: ", sum, std::cout);

    EXPECT_EQ(sum->data,                            1);
    EXPECT_EQ(sum->next->data,                      1);
    EXPECT_EQ(sum->next->next->data,                9);
    EXPECT_EQ(sum->next->next->next->data,          0);
    EXPECT_EQ(sum->next->next->next->next->data,    2);
}

}
