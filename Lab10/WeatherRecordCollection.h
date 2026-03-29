// ===============================================================
// WeatherRecordCollection.h
//      Manages a collection of weather records
//      Provides dynamic storage and access operations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - lab 08
// ===============================================================

#ifndef WEATHERRECORDCOLLECTION_H_INCLUDED
#define WEATHERRECORDCOLLECTION_H_INCLUDED

#include "Vector.h"
#include "WeatherRecord.h"
#include "Bst.h"

//---------------------------------------------------------------------------------
/**
 * @class WeatherRecordCollection
 * @brief Manages a collection of weather records
 *
 * A container class that encapsulates a Vector<WeatherRecord> for managing
 * a dynamic collection of weather record objects. Provides a clean interface
 * for inserting, accessing, and querying weather records.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 28/02/2026 Liyana Afiqah, Initial Implementation
 */
class WeatherRecordCollection
{

public:
    /**
     * @brief Default constructor - initialises empty collection
     *
     * Creates a WeatherRecordCollection object with no records.
     * The internal vector is initialised with default capacity.
     *
     * @return void
     */
    WeatherRecordCollection();

    /**
     * @brief Inserts a weather record at specified position
     *
     * Adds a new weather record to the collection at the specified index.
     * Records at and after the specified position are shifted right.
     *
     * @param record Reference to the WeatherRecord object to insert
     * @param index Position where the record should be inserted
     *
     * @return void
     */
    void Insert(const WeatherRecord &record, int index);

    /**
     * @brief Returns the number of records in the collection
     *
     * @return int - The current number of weather records stored in the collection
     */
    int Size() const;

    /**
     * @brief Accesses a weather record at specified position
     *
     * Provides direct access to a weather record at the specified index
     * using array subscript notation.
     *
     * @param index Position of the record to access
     *
     * @return WeatherRecord - A copy of the weather record at the specified position
     */
    WeatherRecord operator[](int index) const;

private:
    /**
     * @brief Internal storage for weather records
     *
     * A dynamic array container that manages the actual weather record objects.
     */
    Vector<WeatherRecord> records;
};

#endif // WEATHERRECORDCOLLECTION_H_INCLUDED
