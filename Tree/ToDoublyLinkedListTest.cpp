#include "gtest/gtest.h"

#include "BinaryNode.hpp"
#include "ToDoublyLinkedList.hpp"
#include "PrintPretty.hpp"

namespace
{
using NodeType = Tree::BinaryNode<int>;

NodeType::Ptr CreateTree()
{
    auto root                  = NodeType::Create(10);
    root->left                 = NodeType::Create(12);
    root->left->left           = NodeType::Create(25);
    root->left->right          = NodeType::Create(30);
    root->right                = NodeType::Create(15);
    root->right->left          = NodeType::Create(36);
    return root;
}

void Verify(const NodeType::Ptr& head)
{
    EXPECT_EQ(head->data, 25);
    EXPECT_EQ(head->right->data, 12);
    EXPECT_EQ(head->right->right->data, 30);
    EXPECT_EQ(head->right->right->right->data, 10);
    EXPECT_EQ(head->right->right->right->right->data, 36);
    EXPECT_EQ(head->right->right->right->right->right->data, 15);
    EXPECT_EQ(head->right->right->right->right->right->right, nullptr);
    auto tail = head->right->right->right->right->right;
    EXPECT_EQ(tail->data, 15);
    EXPECT_EQ(tail->left->data, 36);
    EXPECT_EQ(tail->left->left->data, 10);
    EXPECT_EQ(tail->left->left->left->data, 30);
    EXPECT_EQ(tail->left->left->left->left->data, 12);
    EXPECT_EQ(tail->left->left->left->left->left->data, 25);
    EXPECT_EQ(tail->left->left->left->left->left->left, nullptr);
}

void Print(const std::string& title, const NodeType::Ptr& head, std::ostream& out)
{
    out << title << std::endl;
    auto tail = head;
    for (auto node = head; node != nullptr; node = node->right)
    {
        out << node->data << " ";
        if (node->right == nullptr) tail = node;
    }
    out << std::endl;
    for (auto node = tail; node != nullptr; node = node->left)
    {
        out << node->data << " ";
    }
    out << std::endl;
}

TEST(ToDoublyLinkedList, ToDoublyLinkedListPrependHead)
{
    auto root = CreateTree();
    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);
    auto head = Tree::ToDoublyLinkedListPrependHead<NodeType>(root);
    Print("DoublyLinkedList:", head, std::cout);
    Verify(head);
}

TEST(ToDoublyLinkedList, ToDoublyLinkedListLastVisited)
{
    auto root = CreateTree();
    Tree::PrintPretty<NodeType>("Tree:", root, 1, 0, std::cout);
    auto head = Tree::ToDoublyLinkedListLastVisited<NodeType>(root);
    Print("DoublyLinkedList:", head, std::cout);
    Verify(head);
}


}
