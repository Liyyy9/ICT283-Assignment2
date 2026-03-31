// ===============================================================
// WeatherRecordCollection.h
//      Manages a collection of weather records using a Nested map
//      Storage: Year(Map) -> Month(Map) -> Records(BST)
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef WEATHERRECORDCOLLECTION_H_INCLUDED
#define WEATHERRECORDCOLLECTION_H_INCLUDED

#include "Vector.h"
#include "WeatherRecord.h"
#include "Bst.h"
#include "Map.h"

//-------------------------------------------------------------------------------------------
/**
 * @class WeatherRecordCollection
 * @brief Manages a collection of weather records using a Nested map (Year -> Month -> BST)
 *
 * Provides a hierachical storage system for efficient data retrieval. Records are sorted by the internal
 * BST within each month.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 28/02/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 31/03/2026, Liyana Afiqah, Assignment 2: Refactored to implement Nested Map structure
 */
 //-------------------------------------------------------------------------------------------

class WeatherRecordCollection
{

public:
    /**
     * @brief Default constructor - initialises empty collection
     */
    WeatherRecordCollection();

    /**
     * @brief Inserts a weather record into the hierarchical storage
     *
     * Uses the record's date to find the correct Year and Month (folder) location and inserts
     * the record into the corresponding BST
     *
     * @param record Reference to the WeatherRecord object to insert
     *
     * @return void
     */
    void Insert(const WeatherRecord &record);

    /**
     * @brief Returns the total number of years (drawer) in the collection
     *
     * @return int - Number of unique years stored
     */
    int GetYearCount() const;

    /**
     * @brief Clears all years, months, and records from the collection
     */
    void Clear();

    /**
     * @brief Provides a read-only access to the internal storage
     *
     * @return const map reference to the inventory
     */
     const Map<int, Map<int, Bst<WeatherRecord>>>& GetInventory() const;

private:

    /**
     * @brief Hierarchical storage for weather records.
     *
     * The structure follows a nested organisation:
     * Outer Map Key (int): The Year (acting as a 'drawer').
     * Inner Map Key (int): The Month (acting as a 'folder').
     * Value: A BST containing WeatherRecord objects for that specific month and year.
     */
    Map<int, Map<int, Bst<WeatherRecord>>> m_inventory;
};

#endif // WEATHERRECORDCOLLECTION_H_INCLUDED
