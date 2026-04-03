#include "Sort.h"
#include "WeatherRecord.h"
#include "Date.h"
#include "Vector.h"

#include <iostream>

void Sort::ExecuteSort(int low, int high, Vector<WeatherRecord>& records)
{
    if(low < high)
    {
        int pivotIndex;
        Split(low, high, records, pivotIndex);
        ExecuteSort(low, pivotIndex - 1, records);
        ExecuteSort(pivotIndex + 1, high, records);
    }
}

void Sort::Split(int low, int high, Vector<WeatherRecord>& records, int& pivotIndex)
{
    // Sorting from middle since files are sorted
    int mid = low + (high - low) / 2;

    WeatherRecord pivot = records[mid];
    int index1 = low;
    int index2 = high;

    while(index1 < index2)
    {
        while(index1 < index2 && !(pivot < records[index1]))
        {
            index1++;
        }
        while(index1 < index2 && pivot < records[index2])
        {
            index2--;
        }

        if(index1 < index2)
        {
            WeatherRecord temp = records[index1];
            records[index1] = records[index2];
            records[index2] = temp;
        }
    }
    pivotIndex = index2 - 1;
    WeatherRecord temp = records[low];
    records[low] = records[pivotIndex];
    records[pivotIndex] = temp;
}
