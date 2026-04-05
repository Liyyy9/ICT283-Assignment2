// ===============================================================
// Sort.cpp
//      Implements the QuickSort algorithm for WeatherRecord data
//      Optimised for pre-sorted inputs by selecting the middle
//      element as the pivot to maintain O(n log n) efficiency.
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "Sort.h"
#include "WeatherRecord.h"
#include "Date.h"
#include "Vector.h"

#include <iostream>

void Sort::ExecuteSort(int low, int high, Vector<WeatherRecord>& records)
{
    // Continue recursion as long as the sub-section has at least two elements
    if(low < high)
    {
        int pivotIndex;

        // Partition the data and get the index of the pivot's final position
        Split(low, high, records, pivotIndex);

        // Recursively sort the left side (smaller elements)
        ExecuteSort(low, pivotIndex - 1, records);

        // Recursively sort the right side (larger elements)
        ExecuteSort(pivotIndex + 1, high, records);
    }
}

void Sort::Split(int low, int high, Vector<WeatherRecord>& records, int& pivotIndex)
{
    // Start in the middle of the range to select the pivot to avoid O(n^2) complexity.
    int mid = low + (high - low) / 2;

    WeatherRecord pivot = records[mid];
    int index1 = low;
    int index2 = high;

    // Rearrange elements based on their relationship to the pivot value
    while(index1 < index2)
    {
        // Move from the left until we find an element larger than the pivot
        while(index1 < index2 && !(pivot < records[index1]))
        {
            index1++;
        }

        // Move from the right until we find an element smaller than the pivot
        while(index1 < index2 && pivot < records[index2])
        {
            index2--;
        }

        // If the indices haven't met, swap the misplaced elements
        if(index1 < index2)
        {
            WeatherRecord temp = records[index1];
            records[index1] = records[index2];
            records[index2] = temp;
        }
    }

    // Move the pivot one down from index2 and swap
    pivotIndex = index2 - 1;
    WeatherRecord temp = records[low];
    records[low] = records[pivotIndex];
    records[pivotIndex] = temp;
}
