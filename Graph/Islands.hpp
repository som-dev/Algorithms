#pragma once

#include <vector>

namespace Graph
{

void IslandCountDFSHelper(const std::vector<std::vector<int>>& matrix,
                          std::vector<std::vector<bool>>& visitedNodes,
                          int i, int j)
{
    if (i < 0 || j < 0 || i >= static_cast<int>(matrix.size()) || j >= static_cast<int>(matrix[0].size())
        || visitedNodes[i][j] || matrix[i][j] == 0)
    {
        return;
    }
    visitedNodes[i][j] = true;
    IslandCountDFSHelper(matrix, visitedNodes, i-1, j-1);
    IslandCountDFSHelper(matrix, visitedNodes, i-1, j);
    IslandCountDFSHelper(matrix, visitedNodes, i-1, j+1);
    IslandCountDFSHelper(matrix, visitedNodes, i, j-1);
    IslandCountDFSHelper(matrix, visitedNodes, i, j+1);
    IslandCountDFSHelper(matrix, visitedNodes, i+1, j-1);
    IslandCountDFSHelper(matrix, visitedNodes, i+1, j);
    IslandCountDFSHelper(matrix, visitedNodes, i+1, j+1);
}

size_t IslandCountDFS(const std::vector<std::vector<int>>& matrix)
{
    size_t result = 0;
    std::vector<std::vector<bool>> visitedNodes(matrix.size(), std::vector<bool>(matrix[0].size(), false));
    for (int i = 0; i < static_cast<int>(matrix.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(matrix[i].size()); ++j)
        {
            if (matrix[i][j] == 1 && !visitedNodes[i][j])
            {
                ++result;
                IslandCountDFSHelper(matrix, visitedNodes, i, j);
            }
        }
    }
    return result;
}

}
