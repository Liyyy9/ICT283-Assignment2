#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Vector.h"

#include <map>

using std::map;
//---------------------------------------------------------------------------------
/**
 * @class Map
 * @brief Wrapper for std::map providing minimal inteface for Year/Month indexing
 *
 * Generic template class that manages a dynamic array of type T.
 * Supports insertion and removal of elements at any position.
 * Automatically resizes the underlying array when capacity is exceeded.
 * Provides read and write access through array indexing operator.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 29/03/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 31/03/2026 Liyana Afiqah, Refactoring for Assignment 2
 */

template <class K, class T>
class Map
{
public:
    typedef typename map<K, T>::iterator iterator;
    typedef typename map<K, T>::const_iterator const_iterator;

    /**
     * @brief Default constructor - initialises
     */
    Map() {};

    /**
     * @brief Access or insert an element.
     */
    T& operator[](const K& key);

    /**
     * @brief Fills a Vector with all keys present in the map
     */
    void GetKeys(Vector<K>& keys) const;

    /**
     * @brief Checks if the key exists in the map.
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

    /// Iterator support for manual loops
    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

private:
    std::map<K, T> m_data;
};

// ===============================================================
// Implementation
// ===============================================================

// Insert/Access implementation
template <class K, class T>
T& Map<K, T>::operator[](const K& key)
{
    return m_data[key];
}

template <class K, class T>
void Map<K, T>::GetKeys(Vector<K>& keys) const
{
    keys.Clear();
    for(const_iterator it = m_data.begin(); it != m_data.end(); ++it)
    {
        keys.Add(it->first);
    }
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

// Iterators implementation
template <class K, class T>
typename Map<K, T>::iterator Map<K, T>::begin()
{
    return m_data.begin();
}

template <class K, class T>
typename Map<K, T>::const_iterator Map<K, T>::begin() const
{
    return m_data.begin();
}

template <class K, class T>
typename Map<K, T>::iterator Map<K, T>::end()
{
    return m_data.end();
}

template <class K, class T>
typename Map<K, T>::const_iterator Map<K, T>::end() const
{
    return m_data.end();
}

#endif // MAP_H_INCLUDED
