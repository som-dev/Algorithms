#pragma once

#include <stack>
#include <list>
#include "Reverse.hpp"

template <typename NodeType>
void ReverseEveryKWithStorage(const typename NodeType::Ptr& head, size_t K, std::list<typename NodeType::Ptr>& nodes)
{
    std::stack<typename NodeType::Ptr> stack;
    auto node = head;
    size_t k = K;
    while (node != nullptr)
    {
        stack.push(node);
        node = node->next;
        --k;
        if (k == 0)
        {
            k = K;
            while (!stack.empty())
            {
                nodes.push_back(stack.top());
                stack.pop();
            }
        }
    }
    while (!stack.empty())
    {
        nodes.push_back(stack.top());
        stack.pop();
    }
}

template <typename NodeType>
void ReverseEveryKWithStorageInPlace(typename NodeType::Ptr& head, size_t K)
{
    std::stack<typename NodeType::Ptr> stack;
    auto currentNode = head;
    typename NodeType::Ptr topNode = nullptr;
    typename NodeType::Ptr prevNode = nullptr;
    while (currentNode != nullptr)
    {
        size_t k = 0;
        for (; currentNode != nullptr && k < K; ++k)
        {
            stack.push(currentNode);
            currentNode = currentNode->next;
        }
        while (!stack.empty())
        {
            topNode = stack.top();
            if (prevNode == nullptr)
            {
                head = topNode;
                prevNode = topNode;
            }
            else
            {
                prevNode->next = topNode;
                prevNode = prevNode->next;
            }
            stack.pop();
        }
    }
    topNode->next = nullptr;
}

template <typename NodeType>
typename NodeType::Ptr ReverseEveryKInPlace(typename NodeType::Ptr& head, size_t K)
{
    typename NodeType::Ptr prevNode = nullptr;
    typename NodeType::Ptr nextNode = nullptr;
    auto currentNode = head;
    size_t k = 0;
    for (; currentNode != nullptr && k < K; ++k)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    if (nextNode != nullptr)
    {
        head->next = ReverseEveryKInPlace<NodeType>(currentNode, K);
    }
    return prevNode;
}
