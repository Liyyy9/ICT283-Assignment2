#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "WeatherRecord.h"
#include "Vector.h"

class Sort
{
public:
    void ExecuteSort(int low, int high, Vector<WeatherRecord>& records);

    void Split(int low, int high, Vector<WeatherRecord)& records, int& pivotIndex);
};

#endif // SORT_H_INCLUDED
