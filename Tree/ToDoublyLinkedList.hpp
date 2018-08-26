#pragma once

namespace Tree
{

template <typename NodeType>
void ToDoublyLinkedListHelper(typename NodeType::Ptr node, typename NodeType::Ptr& head)
{
    if (node == nullptr) return;
    ToDoublyLinkedListHelper<NodeType>(node->right, head);
    node->right = head;
    if (head != nullptr)
    {
        head->left = node;
    }
    head = node;
    ToDoublyLinkedListHelper<NodeType>(node->left, head);
}

template <typename NodeType>
typename NodeType::Ptr ToDoublyLinkedListPrependHead(typename NodeType::Ptr& root)
{
    typename NodeType::Ptr head = nullptr;
    ToDoublyLinkedListHelper<NodeType>(root, head);
    return head;
}

template <typename NodeType>
void ToDoublyLinkedListHelperLastVisited(typename NodeType::Ptr node, typename NodeType::Ptr& lastVisited)
{
    if (node == nullptr) return;
    ToDoublyLinkedListHelper<NodeType>(node->left, lastVisited);
    if (lastVisited != nullptr)
        lastVisited->right = node;
    node->left = lastVisited;
    lastVisited = node;
    ToDoublyLinkedListHelper<NodeType>(node->right, lastVisited);
}

template <typename NodeType>
typename NodeType::Ptr ToDoublyLinkedListLastVisited(typename NodeType::Ptr& root)
{
    typename NodeType::Ptr lastVisited = nullptr;
    ToDoublyLinkedListHelper<NodeType>(root, lastVisited);
    while (lastVisited->left != nullptr)
    {
        lastVisited = lastVisited->left;
    }
    return lastVisited;
}

}
