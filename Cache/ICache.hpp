#pragma once

template<typename KeyType, typename ValueType>
class ICache
{
public:
    virtual ~ICache() { };

    virtual bool get(const KeyType& key, ValueType& value) = 0;

    virtual void set(const KeyType& key, const ValueType& value) = 0;

    virtual size_t size() const = 0;
};
