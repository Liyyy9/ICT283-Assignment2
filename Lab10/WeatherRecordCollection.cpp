// ===============================================================
// WeatherRecordCollection.cpp
//      Manages a collection of weather records using a Nested map
//      Storage: Year(Map) -> Month(Map) -> Records(BST)
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "WeatherRecordCollection.h"
#include "WeatherRecord.h"
#include "Map.h"

// Default constructor implementation
// Using member initialisation list to fix -Weffc++ warnings
WeatherRecordCollection::WeatherRecordCollection() : m_inventory() {}

// Hierarchical Insert implementation
void WeatherRecordCollection::Insert(const WeatherRecord &record)
{
    int year = record.GetDate().GetYear();
    int month = record.GetDate().GetMonth();

    m_inventory[year][month].Insert(record);
}

void WeatherRecordCollection::InsertFromMidPoint(Vector<WeatherRecord>& fileRecords, int low, int high)
{
    if(low > high)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    this->Insert(fileRecords[mid]);
    InsertFromMidPoint(fileRecords, low, mid - 1);
    InsertFromMidPoint(fileRecords, mid + 1, high);
}

// GetYearCount implementation - returns total number of Year (Drawers)
int WeatherRecordCollection::GetYearCount() const
{
    return m_inventory.Size();
}

// Clears the entire collection
void WeatherRecordCollection::Clear()
{
    m_inventory.Clear();
}

const Map<int, Map<int, Bst<WeatherRecord>>>& WeatherRecordCollection::GetInventory() const
{
    return m_inventory;
}
