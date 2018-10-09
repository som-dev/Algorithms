#pragma once

#include <stack>
#include <unordered_map>

namespace LinkedList
{

template <typename NodeType>
void RemoveLoopWithHash(typename NodeType::Ptr ptr)
{
    std::unordered_map<typename NodeType::Ptr, bool> hashmap;
    //auto ptr = head;
    typename NodeType::Ptr prev = nullptr;
    while (ptr != nullptr)
    {
        if (hashmap.find(ptr) == hashmap.end())
        {
            hashmap[ptr] = true;
            prev = ptr;
            ptr = ptr->next;
        }
        else
        {
            prev->next = nullptr;
            break;
        }
    }
}

template <typename NodeType>
void RemoveLoopFloyd(typename NodeType::Ptr head)
{
    typename NodeType::Ptr slowPtr = head;
    typename NodeType::Ptr fastPtr = head;

    // detect the loop
    do
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    while (slowPtr != fastPtr);

    // use floyd's algorithm
    typename NodeType::Ptr prev = nullptr;
    slowPtr = head;
    // slow the fast down to the same rate as slow and when they meet
    // we have reached the beginning
    while (slowPtr != fastPtr)
    {
        std::cout << slowPtr->data << ",";
        std::cout << fastPtr->data << "\n";
        prev = fastPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    prev->next = nullptr;

}

}
