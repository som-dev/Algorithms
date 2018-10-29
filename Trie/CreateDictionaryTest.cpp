#include "gtest/gtest.h"
#include "CreateDictionary.hpp"
#include "../Misc/WordList.hpp"

namespace Trie
{

Node<char>::Ptr CreateDictionary(const std::vector<std::string>& wordList)
{
    auto masterNode = Node<char>::Create();
    // iterate through each word in the word list, adding them to the trie
    for (auto word : wordList)
    {
        auto currentNode = masterNode;
        // iterate through each letter in word, navigating the trie downwards towards a leaf
        for (auto letter : word)
        {
            // check to make sure a child node with the letter exists
            auto iter = currentNode->children.find(letter);
            if (iter == currentNode->children.end())
            {
                // child node representing the letter does not exist so create and insert it.
                auto newNode = Node<char>::Create(letter);
                newNode->parent = currentNode;
                iter = currentNode->children.insert(std::make_pair(letter, newNode)).first;
            }
            // navigate down to the child
            currentNode = iter->second;
        }
        // we have reached the end of the word so increment the node count to represent this word
        ++currentNode->count;
    }
    return masterNode;
}

}

namespace
{

TEST(LoadWordListTest, SimpleTest)
{
    auto trieDictionary = Trie::CreateDictionary(Misc::WordList);
    EXPECT_TRUE(Trie::Contains<Trie::Node<char>>(trieDictionary, "badge"));
    EXPECT_FALSE(Trie::Contains<Trie::Node<char>>(trieDictionary, "badger"));
}

TEST(LoadWordListTest, TestAllWords)
{
    auto trieDictionary = Trie::CreateDictionary(Misc::WordList);
    for (auto word : Misc::WordList)
    {
        EXPECT_TRUE(Trie::Contains<Trie::Node<char>>(trieDictionary, word));
    }
}

}
