#pragma once

#include <string>
#include <iostream>

namespace LinkedList
{

template <typename NodeType>
void Print(const std::string& title, const typename NodeType::Ptr& head, std::ostream& out)
{
    out << title << std::endl;
    for (auto node = head; node != nullptr; node = node->next)
    {
        out << node->data << " ";
    }
    out << std::endl;
}

}
