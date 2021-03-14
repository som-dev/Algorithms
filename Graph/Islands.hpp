#pragma once

#include "Matrix.hpp"
#include <queue>
#include <utility>

namespace Graph
{

bool IsLand(const Matrix<int>& matrix, size_t i, size_t j)
{
    return !(i >= matrix.rows() || j >= matrix.cols()
        || matrix[i][j] == 0);
}

bool HasVisited(Matrix<bool>& visitedNodes, size_t i, size_t j)
{
    return visitedNodes[i][j] == 1;
}

void IslandCountDFSHelper(const Matrix<int>& matrix,
                          Matrix<bool>& visitedNodes,
                          size_t i, size_t j)
{
    if (IsLand(matrix, i, j) && !HasVisited(visitedNodes, i, j))
    {
        visitedNodes[i][j] = true;
        IslandCountDFSHelper(matrix, visitedNodes, i-1, j-1);
        IslandCountDFSHelper(matrix, visitedNodes, i-1, j);
        IslandCountDFSHelper(matrix, visitedNodes, i-1, j+1);
        IslandCountDFSHelper(matrix, visitedNodes, i,   j-1);
        IslandCountDFSHelper(matrix, visitedNodes, i,   j+1);
        IslandCountDFSHelper(matrix, visitedNodes, i+1, j-1);
        IslandCountDFSHelper(matrix, visitedNodes, i+1, j);
        IslandCountDFSHelper(matrix, visitedNodes, i+1, j+1);
    }
}

size_t IslandCountDFS(const Matrix<int>& matrix)
{
    size_t result = 0;
    Matrix<bool> visitedNodes(matrix.rows(), matrix.cols(), false);
    for (size_t i = 0; i < matrix.rows(); ++i)
    {
        for (size_t j = 0; j < matrix.cols(); ++j)
        {
            if (IsLand(matrix, i, j) && !HasVisited(visitedNodes, i, j))
            {
                ++result;
                IslandCountDFSHelper(matrix, visitedNodes, i, j);
            }
        }
    }
    return result;
}

void IslandCountBFSHelper(const Matrix<int>& matrix,
                          Matrix<bool>& visitedNodes,
                          size_t i, size_t j)
{
    std::queue<std::pair<size_t, size_t>> unvisited;
    unvisited.push(std::make_pair(i, j));
    while(!unvisited.empty())
    {
        visitedNodes[i][j] = true;
        auto& ij = unvisited.front();
        i = ij.first;
        j = ij.second;
        unvisited.pop();
        static std::vector<std::pair<size_t, size_t>> neighbors = 
            { {-1,-1}, {-1,0}, {-1,1}, {0,-1},
              {0,1}, {1,-1}, {1,0}, {1,1} };
        for (auto& neighbor : neighbors)
        {
            auto m = i + neighbor.first;
            auto n = j + neighbor.second;
            if (IsLand(matrix, m, n) && !HasVisited(visitedNodes, m, n))
            {
                unvisited.push(std::make_pair(m, n));
            }
        }
    }
}

size_t IslandCountBFS(const Matrix<int>& matrix)
{
    size_t result = 0;
    Matrix<bool> visitedNodes(matrix.rows(), matrix.cols(), false);
    for (size_t i = 0; i < matrix.rows(); ++i)
    {
        for (size_t j = 0; j < matrix.cols(); ++j)
        {
            if (IsLand(matrix, i, j) && !HasVisited(visitedNodes, i, j))
            {
                ++result;
                IslandCountBFSHelper(matrix, visitedNodes, i, j);
            }
        }
    }
    return result;
}

}
