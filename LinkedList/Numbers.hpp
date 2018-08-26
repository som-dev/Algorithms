#pragma once

#include <stack>
#include "Reverse.hpp"

namespace LinkedList
{

template <typename NodeType>
typename NodeType::Ptr Sum(const typename NodeType::Ptr& lhsHead, const typename NodeType::Ptr& rhsHead)
{
    typename NodeType::Ptr sumHead = nullptr;
    typename NodeType::Ptr sumCurrent = nullptr;
    auto lhs = lhsHead;
    ReverseInPlace<NodeType>(lhs);
    auto rhs = rhsHead;
    ReverseInPlace<NodeType>(rhs);
    int carry = 0;
    while (lhs != nullptr || rhs != nullptr || carry > 0)
    {
        int sum = 0;
        if (carry > 0)
        {
            sum += 1;
            carry = 0;
        }
        if (lhs)
        {
            sum += lhs->data;
            lhs = lhs->next;
        }
        if (rhs)
        {
            sum += rhs->data;
            rhs = rhs->next;
        }
        if (sum >= 10)
        {
            carry = 1;
            sum %= 10;
        }
        auto sumNewNode = NodeType::Create(sum);
        if (sumHead == nullptr)
            sumHead = sumNewNode;
        if (sumCurrent != nullptr)
            sumCurrent->next = sumNewNode;
        sumCurrent = sumNewNode;
    }
    ReverseInPlace<NodeType>(sumHead);
    return sumHead;
}

}
