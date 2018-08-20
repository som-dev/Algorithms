#pragma once

#include <cstddef>
#include <vector>
#include <stdexcept>

namespace Heap
{

template <typename T>
class MinHeap
{
public:
    void add(T element)
    {
        size_t index = m_items.size();
        m_items.emplace_back(element);
        heapifyUpward(index);
    }

    T getMin() const
    {
        if (m_items.size() > 0)
            return m_items[0];
        else
            throw std::out_of_range("heap is empty");
    }

    void removeMin()
    {
        size_t size = m_items.size();
        if (size > 0)
        {
            std::swap(m_items[0], m_items[size-1]);
            m_items.pop_back();
        }
        if (size > 1)
        {
            heapifyDownward(0);
        }
    }

    size_t size() const
    {
        return m_items.size();
    }

protected:

    size_t getParentIndex(size_t index)
    {
        return (index-1) / 2;
    }

    size_t getLeftChildIndex(size_t index)
    {
        return index * 2 + 1;
    }

    size_t getRightChildIndex(size_t index)
    {
        return index * 2 + 2;
    }

    void heapifyDownward(size_t index)
    {
        size_t maxIndex = m_items.size() - 1;
        while (index < maxIndex)
        {
            size_t leftChildIndex = getLeftChildIndex(index);
            size_t rightChildIndex = getRightChildIndex(index);

            if (leftChildIndex <= maxIndex && rightChildIndex <= maxIndex &&
                m_items[index] > m_items[leftChildIndex] && m_items[index] > m_items[rightChildIndex])
            {
                size_t smallerIndex = m_items[leftChildIndex] <= m_items[rightChildIndex] ? leftChildIndex : rightChildIndex;
                std::swap(m_items[smallerIndex], m_items[index]);
                index = smallerIndex;
            }
            else if (leftChildIndex <= maxIndex && m_items[index] > m_items[leftChildIndex])
            {
                std::swap(m_items[leftChildIndex], m_items[index]);
                index = leftChildIndex;
            }
            else if (rightChildIndex <= maxIndex && m_items[index] > m_items[rightChildIndex])
            {
                std::swap(m_items[rightChildIndex], m_items[index]);
                index = rightChildIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyUpward(size_t index)
    {
        while (index > 0)
        {
            size_t parentIndex = getParentIndex(index);
            if (m_items[index] < m_items[parentIndex])
            {
                std::swap(m_items[parentIndex], m_items[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    std::vector<T> m_items;
};

}
