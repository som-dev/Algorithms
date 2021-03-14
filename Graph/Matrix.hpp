#pragma once
template <typename T>
class Matrix
{
public:
    Matrix(std::initializer_list<std::initializer_list<T>> rows)
    {
        for (auto& row : rows)
        {
            std::vector<T> newrow;
            for (auto& item : row)
                newrow.push_back(item);
            m_rows.push_back(newrow);
        }
    }
    Matrix(size_t rows, size_t cols, const T& initial_value)
    {
        for (size_t i = 0; i < rows; ++i)
        {
            std::vector<T> newrow;
            for (size_t j = 0; j < rows; ++j)
                newrow.push_back(initial_value);
            m_rows.push_back(newrow);
        }
    }
    const std::vector<T>& operator[](size_t n) const
    {
        return m_rows[n];
    }
    std::vector<T>& operator[](size_t n)
    {
        return m_rows[n];
    }
    size_t rows() const
    {
        return m_rows.size();
    }
    size_t cols() const
    {
        return m_rows[0].size();
    }
private:
    std::vector<std::vector<T>> m_rows;
};