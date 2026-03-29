#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <map>

    /**
     * @class Map
     * @brief A minimal wrapper for std::map to provide key-value association.
     * * Justification: Wraps STL map to encapsulate implementation details.
     */
template <class K, class T>
class Map
{
public:
    /**
     * @brief Access or insert an element.
     * Justification: Simple approach for both retrieval and insertion.
     */
    T& operator[](const K& key);

    /**
     * @brief Checks if the key exists in the map.
     * Justification: Prevents accidental insertion of default values by client code.
     */
    bool Contains(const K& key) const;

    /**
     * @brief Returns number of elements.
     */
    int Size() const;

    /**
     * @brief Clears all entries.
     */
    void Clear();

private:
    std::map<K, T> m_data;
};

// Insert/Access implementation
template <class K, class T>
T& Map<K, T>::operator[](const K& key)
{
    return m_data[key];
}

// Search implementation
template <class K, class T>
bool Map<K, T>::Contains(const K& key) const
{
    return m_data.find(key) != m_data.end();
}

template <class K, class T>
int Map<K, T>::Size() const
{
    return m_data.size();
}

template <class K, class T>
void Map<K, T>::Clear()
{
    m_data.clear();
}

#endif // MAP_H_INCLUDED
