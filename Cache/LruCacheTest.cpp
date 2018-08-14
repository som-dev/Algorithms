#include "gtest/gtest.h"

#include "LruCache.hpp"

TEST(LruCache, Test)
{
    const size_t cacheSize = 3;
    LruCache<size_t, std::string> lruCache(cacheSize);
    std::string value;

    // cache is empty

    lruCache.set(1, "one");
    EXPECT_TRUE(lruCache.get(1, value));
    EXPECT_EQ(value, "one");
    lruCache.set(2, "two");
    EXPECT_TRUE(lruCache.get(2, value));
    EXPECT_EQ(value, "two");
    lruCache.set(3, "three");
    EXPECT_TRUE(lruCache.get(3, value));
    EXPECT_EQ(value, "three");

    // cache is now 3,2,1

    lruCache.set(4, "four");
    EXPECT_TRUE(lruCache.get(4, value));
    EXPECT_EQ(value, "four");

    // cache is now 4,3,2

    EXPECT_FALSE(lruCache.get(1, value));
    EXPECT_TRUE(lruCache.get(2, value));
    EXPECT_EQ(value, "two");
    EXPECT_TRUE(lruCache.get(3, value));
    EXPECT_EQ(value, "three");

    // cache is now 3,2,4

    lruCache.set(5, "five");
    EXPECT_TRUE(lruCache.get(5, value));
    EXPECT_EQ(value, "five");

    // cache is now 5,3,2

    EXPECT_FALSE(lruCache.get(1, value));
    EXPECT_TRUE(lruCache.get(2, value));
    EXPECT_EQ(value, "two");
    EXPECT_TRUE(lruCache.get(3, value));
    EXPECT_EQ(value, "three");
    EXPECT_FALSE(lruCache.get(4, value));
    EXPECT_TRUE(lruCache.get(5, value));
    EXPECT_EQ(value, "five");

    // cache is now 5,3,2

    lruCache.set(3, "3");
    EXPECT_TRUE(lruCache.get(3, value));
    EXPECT_EQ(value, "3");

    // cache is now 3,5,2

    lruCache.set(6, "six");
    EXPECT_TRUE(lruCache.get(6, value));
    EXPECT_EQ(value, "six");

    // cache is now 6,3,5

    EXPECT_FALSE(lruCache.get(1, value));
    EXPECT_FALSE(lruCache.get(2, value));
    EXPECT_TRUE(lruCache.get(3, value));
    EXPECT_EQ(value, "3");
    EXPECT_FALSE(lruCache.get(4, value));
    EXPECT_TRUE(lruCache.get(5, value));
    EXPECT_EQ(value, "five");
    EXPECT_TRUE(lruCache.get(6, value));
    EXPECT_EQ(value, "six");
}
