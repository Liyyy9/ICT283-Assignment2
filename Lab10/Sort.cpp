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

void Sort::Split(int low, int high, Vector<WeatherRecord>& records, int& pivotIndex)
{

    int mid = low + (high - low) / 2;

    WeatherRecord tempRecord = records[mid];
    records[mid] = records[high];
    records[high] = tempRecord;

    WeatherRecord pValue = records[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(records[j] < pValue || records[j] == pValue)
        {
            i++;
            WeatherRecord tempRecord;
            tempRecord = records[i];
            records[i] = records[j];
            records[j] = tempRecord;
        }
    }

    WeatherRecord finalTemp;
    finalTemp = records[i + 1];
    records[i + 1] = records[high];
    records[high] = finalTemp;

    pivotIndex = i + 1;
}
