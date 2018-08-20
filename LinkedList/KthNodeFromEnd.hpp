#pragma once

namespace LinkedList
{

template <typename NodeType>
typename NodeType::Ptr KthNodeFromEnd(const typename NodeType::Ptr& head, size_t K)
{
    auto currentNode = head;
    typename NodeType::Ptr trailingNode = nullptr;
    size_t i = 0;
    while (currentNode != nullptr && i < K)
    {
        currentNode = currentNode->next;
        ++i;
    }
    if (currentNode != nullptr)
    {
        trailingNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
            trailingNode = trailingNode->next;
        }
    }
    return trailingNode;
}

}
