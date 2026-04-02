#include "Sort.h"
#include "WeatherRecord.h"
#include "Date.h"
#include "Vector.h"

#include <iostream>

void Sort::ExecuteSort(int low, int high, Vector<WeatherRecord>& records)
{
    if(low < high && high-low >= 2)
    {
        int pivotIndex;
        Split(low, high, records, pivotIndex);

        ExecuteSort(low, pivotIndex - 1, records);
        ExecuteSort(pivotIndex + 1, high, records);
    }
    else if (high - low == 1)
    {
        if(records[high] < records[low])
        {
            WeatherRecord tempRecord;
            tempRecord = records[high];
            records[high] = records[low];
            records[low] = tempRecord;
        }
    }
}

void Split(int low, int high, Vector<WeatherRecord)& records, int& pivotIndex)
{
    WeatherRecord pValue = records[low];
    int index1 = low;
    int index2 = high;

    while(index1 < index2)
    {
        while(!(pValue < records[index1]) && index1 < index2)
        {
            index1++;
        }

        while(pValue < records[index2] && index2 > index1)
        {
            index2--;
        }

        if(index1 < index2)
        {
            WeatherRecord tempRecord;
            tempRecord = records[index2];
            records[index2] = records[index1];
            records[index1] = tempRecord;
        }
    }
    pivotIndex = index2 - 1;

    WeatherRecord tempRecord;
    tempRecord = records[low];
    records[low] = records[pivotIndex];
    records[pivotIndex] = tempRecord;
}
