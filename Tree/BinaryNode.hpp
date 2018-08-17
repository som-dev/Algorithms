#pragma once

#include <memory>

template <typename T>
struct BinaryNode
{
    using Ptr = std::shared_ptr<BinaryNode>;

    T data;
    Ptr left;
    Ptr right;

    BinaryNode(const T& t) : data(t) { };

    static Ptr Create(const T& t)
    {
        return Ptr(new BinaryNode(t));
    }
};
