#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include "Height.hpp"

namespace Tree
{

// Print the arm branches (eg, /    \ ) on a line
template <typename NodeType>
void PrintBranches(size_t branchLen, size_t nodeSpaceLen, size_t startLen, size_t nodesInThisLevel, const std::deque<typename NodeType::Ptr>& nodesQueue, std::ostream& out)
{
    auto iter = nodesQueue.begin();
    for (size_t i = 0; i < nodesInThisLevel / 2; i++)
    {
        out << ((i == 0) ? std::setw(startLen-1) : std::setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
        out << std::setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
    }
    out << std::endl;
}

// Print the branches and node (eg, ___10___ )
template <typename NodeType>
void PrintNodes(size_t branchLen, size_t nodeSpaceLen, size_t startLen, size_t nodesInThisLevel, const std::deque<typename NodeType::Ptr>& nodesQueue, std::ostream& out)
{
    auto iter = nodesQueue.begin();
    for (size_t i = 0; i < nodesInThisLevel; i++, iter++)
    {
        out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? std::setfill('_') : std::setfill(' '));
        out << std::setw(branchLen+2);
        if (*iter) out << (*iter)->data;
        else out << "";
        out << ((*iter && (*iter)->right) ? std::setfill('_') : std::setfill(' ')) << std::setw(branchLen) << "" << std::setfill(' ');
    }
    out << std::endl;
}

// Print the leaves only (just for the bottom row)
template <typename NodeType>
void PrintLeaves(size_t indentSpace, size_t level, size_t nodesInThisLevel, const std::deque<typename NodeType::Ptr>& nodesQueue, std::ostream& out)
{
    auto iter = nodesQueue.begin();
    for (size_t i = 0; i < nodesInThisLevel; i++, iter++)
    {
        out << ((i == 0) ? std::setw(indentSpace+2) : std::setw(2*level+2));
        if (*iter) out << (*iter)->data;
        else out << "";
    }
    out << std::endl;
}

// Pretty formatting of a binary tree to the output stream
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
template <typename NodeType>
void PrintPretty(const std::string& title, const typename NodeType::Ptr& root, size_t level, size_t indentSpace, std::ostream& out)
{
    out << title << std::endl;
    size_t h = CalculateHeight<NodeType>(root);
    size_t nodesInThisLevel = 1;

    size_t branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
    size_t nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
    size_t startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to prsize_t of each level (for the left most node of each level only)

    std::deque<typename NodeType::Ptr> nodesQueue;
    nodesQueue.push_back(root);
    for (size_t r = 1; r < h; r++)
    {
        PrintBranches<NodeType>(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;
        startLen = branchLen + (3-level) + indentSpace;
        PrintNodes<NodeType>(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

        for (size_t i = 0; i < nodesInThisLevel; i++)
        {
            auto currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode)
            {
                nodesQueue.push_back(currNode->left);
                nodesQueue.push_back(currNode->right);
            }
            else
            {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        nodesInThisLevel *= 2;
    }
    PrintBranches<NodeType>(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    PrintLeaves<NodeType>(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

}
