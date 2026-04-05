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
 *
 * @version 03
 * @date 03/03/2026 Liyana Afiqah, Assignment 2: Implemented insertion via mid point of Vector
 *
 * @version 04
 * @date 03/03/2026 Liyana Afiqah, Assignment 2: Refactored to use typedef
 */
 //-------------------------------------------------------------------------------------------

class WeatherRecordCollection
{

public:
    /**
     * @name Data Hierarchy Type Definitions
     * @brief Definitions that map the nested storage structure to a physical filing system analogy.
     *
     * The hierarchy is organized as follows:
     * - YearCabinet (Outer Map): Represents the entire filing cabinet, where each "Drawer" is indexed by a Year (int).
     * - MonthDrawer (Inner Map): Represents a single year's drawer, containing 12 "Folders" indexed by Month (int).
     * - RecordFolder (BST):Represents a specific month's folder. It stores individual WeatherRecord "files"
     * sorted by the BST's internal ordering (Date/Time).
     *
     */
    typedef Bst<WeatherRecord> RecordFolder;
    typedef Map<int, RecordFolder> MonthDrawer;
    typedef Map<int, MonthDrawer> YearCabinet;

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
     * @brief Recursively inserts records from a sorted vector into the collection.
     *
     * Uses a binary-search-like approach to pick the midpoint of the vector
     * as the insertion root. This ensures the underlying BST remains balanced
     * when processing sorted data, maintaining O(log n) search times.
     *
     * @param fileRecords The vector containing the sorted weather records.
     * @param low The starting index of the current range.
     * @param high The ending index of the current range.
     */
    void InsertFromMidPoint(Vector<WeatherRecord>& fileRecords, int low, int high);

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
     * @brief Retrieves the entire weather record inventory.
     *
     * Returns a constant reference to the YearCabinet map/data structure
     * containing all stored weather data.
     *
     * @return const YearCabinet& Reference to the internal inventory.
     */
     const YearCabinet& GetInventory() const;

private:

    /**
     * @brief Hierarchical storage for weather records.
     *
     * The structure follows a nested organisation:
     * Outer Map Key (int): The Year (acting as a 'drawer').
     * Inner Map Key (int): The Month (acting as a 'folder').
     * Value: A BST containing WeatherRecord objects for that specific month and year.
     */
    YearCabinet m_inventory;
};

#endif // WEATHERRECORDCOLLECTION_H_INCLUDED
