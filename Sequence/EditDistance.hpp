#pragma once

#include <string>
#include <algorithm>

namespace Sequence
{

int EditDistanceRecursiveHelper(const std::string& str1, const std::string& str2, size_t len1, size_t len2)
{
    if (len1 == 0)
    {
        // no more characters in str1 so insert remaining characters in str2
        return len2;
    }
    else if (len2 == 0)
    {
        // no more characters in str2 so insert remaining characters in str1
        return len1;
    }
    else if (str1[len1-1] == str2[len2-1])
    {
        // last characters match so it is the same edit distance as both
        // strings with last character of each removed
        return EditDistanceRecursiveHelper(str1, str2, len1-1, len2-1);
    }
    else
    {
        // last characters do not match so we have three options:
        // 1) remove a character from str1
        auto tryRemove = EditDistanceRecursiveHelper(str1, str2, len1-1, len2);
        // 2) insert a character in str1
        auto tryInsert = EditDistanceRecursiveHelper(str1, str2, len1, len2-1);
        // 2) replace a character in str1
        auto tryReplace = EditDistanceRecursiveHelper(str1, str2, len1-1, len2-1);
        // now we want minimal edit distance so take one operation + the smallest
        // remaining result of the substrings
        return 1 + std::min({tryRemove, tryInsert, tryReplace});
    }
}

int EditDistanceRecursive(const std::string& str1, const std::string& str2)
{
    return EditDistanceRecursiveHelper(str1, str2, str1.length(), str2.length());
}

int EditDistanceDynamic(const std::string& str1, const std::string& str2)
{
    std::vector<std::vector<int>> editDistances(str1.length()+1, std::vector<int>(str2.length()+1));

    for (size_t len1 = 0; len1 <= str1.length(); ++len1)
    {
        for (size_t len2 = 0; len2 <= str2.length(); ++len2)
        {
            if (len1 == 0)
            {
                editDistances[len1][len2] = len2;
            }
            else if (len2 == 0)
            {
                editDistances[len1][len2] = len1;
            }
            else if (str1[len1-1] == str2[len2-1])
            {
                editDistances[len1][len2] = editDistances[len1-1][len2-1];
            }
            else
            {
                auto tryRemove = editDistances[len1-1][len2];
                auto tryInsert = editDistances[len1][len2-1];
                auto tryReplace = editDistances[len1-1][len2-1];
                editDistances[len1][len2] = 1 + std::min({tryRemove, tryInsert, tryReplace});
            }
        }
    }
    return editDistances[str1.length()][str2.length()];
}

}
