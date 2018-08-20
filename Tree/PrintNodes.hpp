#pragma once

#include <string>
#include <iostream>

namespace Tree
{

template <typename NodeType>
void PrintNodes(const std::string& title, const std::vector<typename NodeType::Ptr>& nodes, std::ostream& out)
{
    out << title << std::endl;
    for (auto node : nodes)
    {
        out << node->data << " ";
    }
    out << std::endl;
}

}
