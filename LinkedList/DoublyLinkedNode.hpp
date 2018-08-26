#pragma once

#include <memory>

namespace LinkedList
{

template <typename T>
struct DoublyLinkedNode
{
    using Ptr = std::shared_ptr<DoublyLinkedNode>;

    T data;
    Ptr next;
    Ptr prev;

    DoublyLinkedNode(const T& t) : data(t) { };

    static Ptr Create(const T& t)
    {
        return Ptr(new DoublyLinkedNode(t));
    }
};

}
