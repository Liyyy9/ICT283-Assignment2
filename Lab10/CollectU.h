// ===================================================================
// CollectU.h
//      Collector class to store data retrieved from BST via fpointer
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 10
// ===================================================================

#include "Date.h"
#include "Vector.h"


#ifndef COLLECTU_H_INCLUDED
#define COLLECTU_H_INCLUDED

/**
 * @file CollectU
 * @brief Collector class to store data retrieved from BST via fpointer
 */

 class CollectU
 {
 public:
    /**
     * @brief Callback function
     */
     static void Collect(const Date& data);

    /**
     * @brief Size getter
     */
     int size() const;

    /**
     * @brief operator for accessign collected data
     * @param k Index of the element
     * @return Date& Reference to the Date object
     */
     Date& operator[](int k);

     void clear();

 private:
    static Vector<Date> A;      /// Storage for collected Date objects
 };

#endif // COLLECTU_H_INCLUDED
