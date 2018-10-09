#include "gtest/gtest.h"

#include "Islands.hpp"

namespace {

TEST(Islands, IslandCount)
{
    std::vector<std::vector<int>> matrix
        = {{1, 1, 0, 0, 0},
           {0, 1, 0, 0, 1},
           {1, 0, 0, 1, 1},
           {0, 0, 0, 0, 0},
           {1, 0, 1, 0, 1}};
    auto result = Graph::IslandCountDFS(matrix);
    std::cout << "Number of islands is " << result << std::endl;
    EXPECT_EQ(result, 5);
}

}
