#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <utility>

namespace Interval
{

void Print(const std::string& title, const std::vector<std::pair<int,int>>& intervals, std::ostream& out)
{
    out << title << std::endl;
    for (auto interval : intervals)
    {
        out << "(" << interval.first << "," << interval.second << ") ";
    }
    out << std::endl;
}

}
