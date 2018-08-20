#pragma once

#include <memory>

namespace LinkedList
{

template <typename T>
struct SinglyLinkedNode
{
    using Ptr = std::shared_ptr<SinglyLinkedNode>;

    T data;
    Ptr next;

    SinglyLinkedNode(const T& t) : data(t) { };

    static Ptr Create(const T& t)
    {
        return Ptr(new SinglyLinkedNode(t));
    }
};

}
