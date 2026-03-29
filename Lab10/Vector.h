
// ===============================================================
// Vector.h
//      Template vector class for dynamic array management
//      Provides Insert, Remove, and access operations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <vector>

using std::vector;
//---------------------------------------------------------------------------------
/**
 * @class Vector
 * @brief Template vector class for dynamic array management
 *
 * Generic template class that manages a dynamic array of type T.
 * Supports insertion and removal of elements at any position.
 * Automatically resizes the underlying array when capacity is exceeded.
 * Provides read and write access through array indexing operator.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 13/02/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 08/03/2026 Liyana Afiqah, Refactoring for Lab 8, using STL Vector
 */

template <class T>
class Vector
{
public:
    /**
     * @brief Default constructor - initialises empty vector
     *
     * @return void
     */
    Vector() {};

    /**
     * @brief Parameterised constructor - initialises vector with specified size
     *
     * Creates a Vector object with specified size only if n is valid
     *
     * @param n The initial size of the vector
     *
     * @return void
     */
    Vector(int n);

    /**
     * @brief Destructor - deallocates dynamic memory
     *
     * Frees the dynamically allocated array memory.
     *
     * @return void
     */
    ~Vector() {};

     /**
     * @brief Inserts an element at specified position - Create operation
     *
     * Inserts a new element at the specified position and shifts existing elements.
     * Automatically resizes if capacity is exceeded.
     * Valid position range: 0 to Size (inclusive).
     *
     * @param data Reference to the data to insert
     * @param pos Position where data should be inserted
     *
     * @return bool - true if insertion successful, false if position is out of range
     */
    bool Insert(const T &data, int pos);        // Create

    /**
     * @brief Removes an element at specified position - Delete operation
     *
     * Removes the element at the specified position and shifts remaining elements.
     * Valid position range: 0 to Size-1 (inclusive).
     *
     * @param pos Position of element to remove
     *
     * @return bool - true if removal successful, false if position is out of range
     */
    bool Remove(int pos);                       // Delete

    /**
     * @brief Appends an element at the end
     *
     * @return bool - true if append successful
     */
    bool Add(const T& data);                    // Append

    /**
     * @brief Reads element at specified position - Read operation
     *
     * Provides const access to the element at specified position.
     *
     * @param pos Position of element to read
     *
     * @return const reference to the element at specified position
     */
    const T &operator[](int pos) const;         // Read

    /**
     * @brief Accesses element at specified position for modification - Update operation
     *
     * Provides non-const access to the element at specified position.
     *
     * @param pos Position of element to access
     *
     * @return Reference to the element at specified position
     */
    T &operator[](const int &pos);              // Update

    /**
     * @brief Returns the number of elements in the vector
     *
     * @return int - The current size of the vector
     */
    int Size() const;

    /**
     * @brief Clears all elements from the vector
     *
     * Sets size to 0 without deallocating memory.
     * Capacity remains unchanged.
     *
     * @return void
     */
    void Clear();

private:

    vector<T> m_vector;
};

// Parameterised Constructor
template <class T>
Vector<T>::Vector(int n)
{
    if(n > 0)      // if valid size
    {
        m_vector.resize(n);
    }
}

// Size implementation - returns current number of elements
template <class T>
int Vector<T>::Size() const
{
    return m_vector.size();
}

// Insert implementation - inserts element at specified position
template <class T>
bool Vector<T>::Insert(const T &data, int pos)
{

    if(pos < 0 || pos > Size())
    {
        return false;
    }
    else if (pos == Size())
    {
        m_vector.push_back(data);
    }
    else
    {
        m_vector.insert(m_vector.begin() + pos, data);
    }
    return true;
}

// Append - append element at end
template <class T>
bool Vector<T>::Add(const T& data)
{
    return Insert(data, Size());
}

// Remove implementation - removes element at specified position
template <class T>
bool Vector<T>::Remove(int pos)
{
    if (pos < 0 || pos >= Size())
    {
        return false;
    }

    m_vector.erase(m_vector.begin() + pos);
    return true;
}

// Read implemetation
template <class T>
const T &Vector<T>::operator[](int pos) const
{
    return m_vector[pos];
}

// Update implementation
template <class T>
T &Vector<T>::operator[](const int &pos)
{
    return m_vector[pos];
}

// Clear implementation
template <class T>
void Vector<T>::Clear()
{
    m_vector.clear();
}

#endif // VECTOR_H_INCLUDED

