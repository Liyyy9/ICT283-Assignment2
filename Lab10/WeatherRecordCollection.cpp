// ===============================================================
// WeatherRecordCollection.cpp
//      Manages a collection of weather records
//      Provides dynamic storage and access operations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================
#include "WeatherRecordCollection.h"
#include "WeatherRecord.h"

// Default constructor implementation - initialises empty collection
// Initialises the internal Vector to manage weather records.
WeatherRecordCollection::WeatherRecordCollection() {}

// Insert implementation - adds record at specified position
void WeatherRecordCollection::Insert(const WeatherRecord &record, int index)
{
    records.Insert(record, index);
}

// Size implementation - returns current number of records
int WeatherRecordCollection::Size() const
{
    return records.Size();
}

// Operator[] implementation - provides indexed access
WeatherRecord WeatherRecordCollection::operator[](int index) const
{
    return records[index];
}
