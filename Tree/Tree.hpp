#pragma once

#include <memory>
#include <iostream>

template <typename T>
struct Node
{
    using Ptr = std::shared_ptr<Node>;

    T data;
    Ptr left;
    Ptr right;

    Node(const T& t) : data(t) { };

    static Ptr Create(const T& t)
    {
        return Ptr(new Node(t));
    }
};
