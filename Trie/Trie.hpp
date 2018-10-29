#pragma once

#include <memory>
#include <map>

namespace Trie
{

template <typename T>
struct Node
{
    using Ptr = std::shared_ptr<Node>;

    size_t count;
    T value;
    std::map<T, Ptr> children;
    Ptr parent;

    Node() : count(0) { };

    Node(const T& val) : count(0), value(val) { };

    static Ptr Create()
    {
        return std::make_shared<Node<T>>();
    }
    static Ptr Create(const T& value)
    {
        return std::make_shared<Node<T>>(value);
    }

};

template <typename NodeType>
bool Contains(typename NodeType::Ptr masterNode, const std::string& str)
{
    if (str.empty()) return false;
    auto currentNode = masterNode;
    for (auto letter : str)
    {
        try
        {
            currentNode = currentNode->children.at(letter);
        }
        catch (std::out_of_range& ex)
        {
            return false;
        }
        if (currentNode == nullptr)
        {
            return false;
        }
    }
    return currentNode->count > 0;
}

}
