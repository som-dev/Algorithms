#pragma once

#include <vector>

namespace Misc
{

size_t Total(const std::string& symbols, const std::string& ops, size_t i, size_t j);
size_t False(const std::string& symbols, const std::string& ops, size_t i, size_t j);

size_t True(const std::string& symbols, const std::string& ops, size_t i, size_t j)
{
    if (i == j && symbols[i] == 'T') return 1;
    if (i == j && symbols[i] == 'F') return 0;
    auto result = 0;
    for (size_t k = i; k < j; ++k)
    {
        auto op = ops[k];
        {
            if (op == '&')
                result += True(symbols, ops, i, k) * True(symbols, ops, k+1, j);
            if (op == '|')
                result += Total(symbols, ops, i, k) * Total(symbols, ops, k+1, j) - False(symbols, ops, i, k) * False(symbols, ops, k+1, j);
            if (op == '^')
                result += True(symbols, ops, i, k) * False(symbols, ops, k+1, j) + False(symbols, ops, i, k) * True(symbols, ops, k+1, j);
        }
    }
    return result;
}

size_t False(const std::string& symbols, const std::string& ops, size_t i, size_t j)
{
    if (i == j && symbols[i] == 'T') return 0;
    if (i == j && symbols[i] == 'F') return 1;
    auto result = 0;
    for (size_t k = i; k < j; ++k)
    {
        auto op = ops[k];
        {
            if (op == '&')
                result += Total(symbols, ops, i, k) * Total(symbols, ops, k+1, j) - True(symbols, ops, i, k) * True(symbols, ops, k+1, j);
            if (op == '|')
                result += False(symbols, ops, i, k) * False(symbols, ops, k+1, j);
            if (op == '^')
                result += True(symbols, ops, i, k) * True(symbols, ops, k+1, j) + False(symbols, ops, i, k) * False(symbols, ops, k+1, j);
        }
    }
    return result;
}

size_t Total(const std::string& symbols, const std::string& ops, size_t i, size_t j)
{
    return True(symbols, ops, i, j) + False(symbols, ops, i, j);
}

size_t BooleanParenthesis(const std::string& symbols, const std::string& ops)
{
    return True(symbols, ops, 0, symbols.length()-1);
}

}
