#pragma once

#include <stack>

namespace LinkedList
{

template <typename NodeType>
void ReverseInPlaceWithStorage(typename NodeType::Ptr& head)
{
    std::stack<typename NodeType::Ptr> stack;
    auto node = head;
    while (node != nullptr)
    {
        stack.push(node);
        node = node->next;
    }
    typename NodeType::Ptr newhead = nullptr;
    if (!stack.empty())
    {
        newhead = stack.top();
        stack.pop();
        node = newhead;
        while (!stack.empty())
        {
            node->next = stack.top();
            stack.pop();
            node = node->next;
        }
        node->next = nullptr;
    }
    head = newhead;
}

template <typename NodeType>
void ReverseInPlace(typename NodeType::Ptr& head)
{
    typename NodeType::Ptr prev = nullptr;
    typename NodeType::Ptr next = nullptr;
    auto current = head;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

}
