#pragma once

#include "ICache.hpp"
#include <list>
#include <unordered_map>
#include <utility>

namespace Cache
{

template<typename KeyType, typename ValueType>
class LruCache : public ICache<KeyType, ValueType>
{
public:

    LruCache(size_t sizeLimit)
        : m_sizeLimit(sizeLimit)
        , m_Cache()
        , m_PositionInCache()
    {

    }

    virtual bool get(const KeyType& key, ValueType& value) override
    {
        bool found = false;
        if (findItemInCacheAndPushToFront(key))
        {
            found = true;
            auto& keyValuePair = m_Cache.front();
            value = std::get<Value>(keyValuePair);
        }
        return found;
    }

    virtual void set(const KeyType& key, const ValueType& value) override
    {
        if (findItemInCacheAndPushToFront(key))
        {
            auto& keyValuePair = m_Cache.front();
            std::get<Value>(keyValuePair) = value;
        }
        else // item not in cache
        {
            if (m_Cache.size() >= m_sizeLimit)
            {
                evictOldestItemInCache();
            }
            m_Cache.emplace_front(key, value);
            m_PositionInCache[key] = m_Cache.begin();
        }
    }

    virtual size_t size() const override
    {
        return m_Cache.size();
    }

protected:

    void evictOldestItemInCache()
    {
        auto keyValuePair = m_Cache.back();
        m_PositionInCache.erase(std::get<Key>(keyValuePair));
        m_Cache.pop_back();
    }

    bool findItemInCacheAndPushToFront(const KeyType& key)
    {
        bool found = false;
        auto iter = m_PositionInCache.find(key);
        if (iter != m_PositionInCache.end())
        {
            found = true;
            auto cachePosition = iter->second;
            m_Cache.push_front(*cachePosition);
            m_Cache.erase(cachePosition);
            m_PositionInCache[key] = m_Cache.begin();
        }
        return found;
    }

    size_t m_sizeLimit;

    enum keyValuePairIndex { Key = 0, Value = 1 };

    using keyValuePair_t = typename std::pair<KeyType, ValueType>;

    using keyValueContainer_t = typename std::list<keyValuePair_t>;

    keyValueContainer_t m_Cache;

    using PositionContainer_t = std::unordered_map<KeyType, typename keyValueContainer_t::iterator>;

    PositionContainer_t m_PositionInCache;

};

}
