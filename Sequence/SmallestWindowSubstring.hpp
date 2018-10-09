#pragma once

#include <string>
#include <algorithm>
#include <vector>
#include <limits>

namespace Sequence
{

std::string SmallestWindowSubstring(const std::string& str, const std::string& pattern)
{
    std::string result;
    if (pattern.length() > str.length())
    {
        return result;
    }

    std::vector<size_t> strCharOccurrence(256, 0);
    std::vector<size_t> patternCharOccurrence(256, 0);

    for (size_t i = 0; i < pattern.size(); ++i)
    {
        patternCharOccurrence[pattern[i]] += 1;
    }

    size_t leftIndexOfCurrentWindow = 0;
    size_t rightIndexOfCurrentWindow = 0;

    auto currentWindowSize = [&] { return rightIndexOfCurrentWindow - leftIndexOfCurrentWindow + 1; };

    size_t leftIndexOfMinWindow = 0;
    size_t rightIndexOfMinWindow = std::numeric_limits<size_t>::max()-1;

    auto minWindowSize = [&] { return rightIndexOfMinWindow - leftIndexOfMinWindow + 1; };

    bool foundMinWindow = false;
    auto updateMinWindowSize = [&]
    {
        leftIndexOfMinWindow = leftIndexOfCurrentWindow;
        rightIndexOfMinWindow = rightIndexOfCurrentWindow;
        foundMinWindow = true;
    };

    size_t matchedLetters = 0;

    // start growing the right side of the window
    for (rightIndexOfCurrentWindow = 0; rightIndexOfCurrentWindow < str.length(); ++rightIndexOfCurrentWindow)
    {
        char currentChar = str[rightIndexOfCurrentWindow];
        strCharOccurrence[currentChar] += 1;
        if (strCharOccurrence[currentChar] <= patternCharOccurrence[currentChar])
        {
            ++matchedLetters;
        }

        if (matchedLetters == pattern.length())
        {
            // see if this is a new smallest window
            if (currentWindowSize() < minWindowSize())
            {
                updateMinWindowSize();
            }

            // now try to shrink the left side of the window
            do
            {
                char leftChar = str[leftIndexOfCurrentWindow++];
                strCharOccurrence[leftChar] -= 1;
                if (strCharOccurrence[leftChar] >= patternCharOccurrence[leftChar] ||
                       patternCharOccurrence[leftChar] == 0)
                {
                    // see if this is a new smallest window
                    if (currentWindowSize() < minWindowSize())
                    {
                        updateMinWindowSize();
                    }
                }
                else
                {
                    break;
                }
            } while (leftIndexOfCurrentWindow < rightIndexOfCurrentWindow);
            --matchedLetters;
        }
    }
    if (foundMinWindow)
    {
        result = str.substr(leftIndexOfMinWindow, minWindowSize());
    }
    return result;
}

}
