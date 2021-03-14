#include "gtest/gtest.h"

#include "Islands.hpp"

namespace {

TEST(Islands, IslandDFSCount)
{
    Matrix<int> matrix
        = {{1, 1, 0, 0, 0},
           {0, 1, 0, 0, 1},
           {1, 0, 0, 1, 1},
           {0, 0, 0, 0, 0},
           {1, 0, 1, 0, 1}};
    auto result = Graph::IslandCountDFS(matrix);
    std::cout << "Number of islands is " << result << std::endl;
    EXPECT_EQ(result, 5);
}

TEST(Islands, IslandBFSCount)
{
    Matrix<int> matrix
        = {{1, 1, 0, 0, 0},
           {0, 1, 0, 0, 1},
           {1, 0, 0, 1, 1},
           {0, 0, 0, 0, 0},
           {1, 0, 1, 0, 1}};
    auto result = Graph::IslandCountBFS(matrix);
    std::cout << "Number of islands is " << result << std::endl;
    EXPECT_EQ(result, 5);
}

}
