#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace Histogram
{

template <typename T>
void Print(const std::string& title, const std::vector<T>& vec, std::ostream& out)
{
    const size_t width = 3;
    out << title << std::endl;
    auto max = *(std::max_element(vec.begin(), vec.end()));
    for (T level = max; level > 0; --level)
    {
        out << "       ";
        for (auto i : vec)
        {
            out << ((i >= level) ? "|X|" : "   ");
        }
        out << std::endl;
    }
    out << "-------";
    for (size_t i = 0; i < vec.size(); ++i)
        out << std::setw(width) << std::setfill('-') << "";
    out << std::setfill(' ');
    out << std::endl;
    out << "Value: ";
    for (auto i : vec)
    {
        out << std::setw(width) << i;
    }
    out << std::endl;
    out << "-------";
    for (size_t i = 0; i < vec.size(); ++i)
        out << std::setw(width) << std::setfill('-') << "";
    out << std::setfill(' ');
    out << std::endl;
    out << "Index: ";
    for (size_t i = 0; i < vec.size(); ++i)
        out << std::setw(width) << i;
    out << std::endl;
}

}
