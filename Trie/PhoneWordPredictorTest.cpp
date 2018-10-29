#include "gtest/gtest.h"

#include "CreateDictionary.hpp"
#include "../Misc/PhoneDigitToLetters.hpp"
#include "../Misc/WordList.hpp"
#include <queue>
#include <algorithm>
#include <functional>

namespace {

std::string MakeWord(Trie::Node<char>::Ptr node)
{
    std::string word;
    // iterate back up the trie via parent field
    // the trie has a master node which should be skipped
    while (node != nullptr && node->parent != nullptr)
    {
        word.push_back(node->value);
        node = node->parent;
    }
    // we have the letters but we appened to end backwards so reverse the string
    std::reverse(word.begin(), word.end());
    return word;
}

std::vector<std::string> GetWordsFromPhoneNumber(const std::string& numbers,
                                                 Trie::Node<char>::Ptr trieDictionary)
{
    std::vector<std::string> results;
    if (numbers.empty()) return results;

    auto currentNode = trieDictionary;

    std::queue<Trie::Node<char>::Ptr> nodeProcessingQueue;
    nodeProcessingQueue.push(currentNode);

    // first find all nodes that match the provided numbers
    for (auto number : numbers)
    {
        // get the possible letters for this phone digit
        auto possibleLetters = Misc::PhoneDigitToLetters.equal_range(number);

        // take all nodes in queue and store them in a temporary queue
        std::queue<Trie::Node<char>::Ptr> lastIterationNodesQueue;
        nodeProcessingQueue.swap(lastIterationNodesQueue);
        // iterate through each node and add the new children to the main queue
        while (!lastIterationNodesQueue.empty())
        {
            currentNode = lastIterationNodesQueue.front();
            lastIterationNodesQueue.pop();
            for (auto iter = possibleLetters.first; iter != possibleLetters.second; ++iter)
            {
                auto letter = std::tolower(iter->second);
                try
                {
                    auto childNode = currentNode->children.at(letter);
                    nodeProcessingQueue.push(childNode);
                }
                catch (std::out_of_range& ex)
                {
                    // there are no words with the provided letter so skip
                }
            }
        }
    }
    // now we have all children that represent possible prefix words,
    // perform a level-order search of all child nodes and add them to results
    // if the node represents a word
    while (!nodeProcessingQueue.empty())
    {
        currentNode = nodeProcessingQueue.front();
        nodeProcessingQueue.pop();
        if (currentNode->count > 0)
        {
            results.push_back(MakeWord(currentNode));
        }
        for (auto child : currentNode->children)
        {
            nodeProcessingQueue.push(child.second);
        }
    }
    return results;
}

void Print(const std::vector<std::string>& words)
{
    std::cout << "Words = { ";
    for (auto word : words)
    {
        std::cout << word << " ";
    }
    std::cout << "}" << std::endl << words.size() << " total words" << std::endl;
}

void ValidateWordsInResults(const std::vector<std::string>& results, std::function<bool (const std::string& word)> isWordValid)
{
    for (auto word : results)
    {
        EXPECT_TRUE(isWordValid(word));
    }
    for (auto word : Misc::WordList)
    {
        bool foundWordInresults = std::find(results.begin(), results.end(), word) != results.end();
        if (isWordValid(word))
        {
            EXPECT_TRUE(foundWordInresults);
        }
        else
        {
            EXPECT_FALSE(foundWordInresults);
        }
    }
}

TEST(PhoneWordPredictor, Test1Digit)
{
    auto trieDictionary = Trie::CreateDictionary(Misc::WordList);
    auto results = GetWordsFromPhoneNumber("9", trieDictionary);
    Print(results);
    auto isWordValid = [](const std::string& word)
    {
        return word[0] == 'w' || word[0] == 'x' || word[0] == 'y' || word[0] == 'z';
    };
    ValidateWordsInResults(results, isWordValid);
}

TEST(PhoneWordPredictor, Test3Digits)
{
    auto trieDictionary = Trie::CreateDictionary(Misc::WordList);
    auto results = GetWordsFromPhoneNumber("227", trieDictionary);
    Print(results);
    auto isWordValid = [](const std::string& word)
    {
        return (word[0] == 'a' || word[0] == 'b' || word[0] == 'c')
            && (word[1] == 'a' || word[1] == 'b' || word[1] == 'c')
            && (word[2] == 'p' || word[2] == 'q' || word[2] == 'r' || word[2] == 's');
    };
    ValidateWordsInResults(results, isWordValid);
}

TEST(PhoneWordPredictor, Test5Digits)
{
    auto trieDictionary = Trie::CreateDictionary(Misc::WordList);
    auto results = GetWordsFromPhoneNumber("22723", trieDictionary);
    Print(results);
    auto isWordValid = [](const std::string& word)
    {
        return (word[0] == 'a' || word[0] == 'b' || word[0] == 'c')
            && (word[1] == 'a' || word[1] == 'b' || word[1] == 'c')
            && (word[2] == 'p' || word[2] == 'q' || word[2] == 'r' || word[2] == 's')
            && (word[3] == 'a' || word[3] == 'b' || word[3] == 'c')
            && (word[4] == 'd' || word[4] == 'e' || word[4] == 'f');
    };
    ValidateWordsInResults(results, isWordValid);
}

}
