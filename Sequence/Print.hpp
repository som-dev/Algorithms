#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace Sequence
{

template <typename T>
void Print(const std::string& title, const std::vector<T>& vec, std::ostream& out)
{
    out << title << std::endl;
    if (vec.empty())
    {
        out << "Empty";
    }
    else
    {
        out << "Value: ";
        for (auto i : vec)
            out << std::setw(2) << i << " ";
        out << std::endl;
        out << "       ";
        for (size_t i = 0; i < vec.size(); ++i)
            out << "---";
        out << std::endl;
        out << "Index: ";
        for (size_t i = 0; i < vec.size(); ++i)
            out << std::setw(2) << i << " ";
    }
    out << std::endl;
}

}
