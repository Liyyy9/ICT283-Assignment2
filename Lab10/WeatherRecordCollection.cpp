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

// Insertion by using the middle element of a sorted list
void WeatherRecordCollection::InsertFromMidPoint(Vector<WeatherRecord>& fileRecords, int low, int high)
{
    // Return early if range invalid
    if(low > high)
    {
        return;
    }

    // Calculate the middle index to use as the "root" of the current sub-section
    int mid = low + (high - low) / 2;

    // Insert the middle element first to keep the BST balanced
    this->Insert(fileRecords[mid]);

    // Recursively handle the left half (elements smaller than mid)
    InsertFromMidPoint(fileRecords, low, mid - 1);

    // Recursively handle the right half (elements larger than mid)
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

// Returns a read-only reference to the internal record collection
const WeatherRecordCollection::YearCabinet& WeatherRecordCollection::GetInventory() const
{
    return m_inventory;
}
