// ===============================================================
// Sort.h
//      Implements the QuickSort algorithm for WeatherRecord data
//      Optimised for pre-sorted inputs by selecting the middle
//      element as the pivot to maintain O(n log n) efficiency.
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "WeatherRecord.h"
#include "Vector.h"

//---------------------------------------------------------------------------------
/**
 * @class Sort
 * @brief Provides sorting utility for WeatherRecord data using QuickSort
 *
 * Implements an optimised QuickSort algorithm to arrange WeatherRecord
 * objects. To handle pre-sorted data efficiently and maintain O(n log n)
 * performance, the algorithm begins partitioning from the middle of the range.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 31/03/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 03/04/2026 Liyana Afiqah, Optimised pivot selection for sorted files
 *
 */
 //---------------------------------------------------------------------------------
class Sort
{
public:

     /**
     * @brief Recursively divides the vector into sub-sections to perform the sort.
     *
     * @param low    The starting index of the sub-section
     * @param high   The ending index of the sub-section
     * @param records The vector of WeatherRecord objects to be sorted
     */
    void ExecuteSort(int low, int high, Vector<WeatherRecord>& records);

    /**
     * @brief Partitions the vector around a pivot. Optimised to select the middle element to prevent O(n^2)
     * performance degradation on already sorted datasets.
     *
     * @return void
     */
    void Split(int low, int high, Vector<WeatherRecord>& records, int& pivotIndex);
};

#endif // SORT_H_INCLUDED
