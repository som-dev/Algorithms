#pragma once

#include <vector>
#include <stack>

namespace Histogram
{

struct Area
{
    int    maxArea;
    size_t leftIndex;
    size_t rightIndex;
    Area() : maxArea(0), leftIndex(0), rightIndex(0) { };
};

Area LargestArea(const std::vector<int>& histogram)
{
    Area maxArea;
    Area currentArea;
    std::stack<size_t> rightmostHigherBarIndex;
    size_t i = 0;
    while (i < histogram.size())
    {
        if (rightmostHigherBarIndex.empty()
            || histogram[rightmostHigherBarIndex.top()] < histogram[i])
        {
            // bars are increasing, and therefore potential higher areas can be
            // calculated so push the bar indexes onto a stack to keep track of them
            rightmostHigherBarIndex.push(i++);
        }
        else
        {
            // the bar decreases from the right-most highest bar, therefore
            // we have found a righthand side edge for the previous bar on the stack
            // get the previous highest bar
            auto currentIndex = rightmostHigherBarIndex.top();
            rightmostHigherBarIndex.pop();
            // calculate the area of this bar
            //   height is the height of the bar
            //   left index is the index just after the next highest bar in the stack (or zero if none)
            //   right index is the bar before the one we identified as a decrease in height
            auto currentHeight = histogram[currentIndex];
            currentArea.leftIndex = !rightmostHigherBarIndex.empty() ? rightmostHigherBarIndex.top() + 1 : 0;
            currentArea.rightIndex = i - 1;
            currentArea.maxArea = currentHeight * (currentArea.rightIndex - currentArea.leftIndex + 1);
            // update the max is higher
            if (currentArea.maxArea > maxArea.maxArea)
                maxArea = currentArea;
        }
    }
    // calculate remaining areas from right-most highest bars
    while (!rightmostHigherBarIndex.empty())
    {
        // basically same logic as above
        auto currentIndex = rightmostHigherBarIndex.top();
        rightmostHigherBarIndex.pop();
        auto currentHeight = histogram[currentIndex];
        currentArea.leftIndex = !rightmostHigherBarIndex.empty() ? rightmostHigherBarIndex.top() + 1 : 0;
        currentArea.rightIndex = i - 1;
        currentArea.maxArea = currentHeight * (currentArea.rightIndex - currentArea.leftIndex + 1);
        if (currentArea.maxArea > maxArea.maxArea)
            maxArea = currentArea;
    }
    return maxArea;
}

}
