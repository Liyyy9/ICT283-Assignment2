// ===============================================================
// CSVLoader.h
//      Loads and parses CSV weather data files
//      Manages file I/O and data processing
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef CSVLOADER_H_INCLUDED
#define CSVLOADER_H_INCLUDED

#include "WeatherRecordCollection.h"

//--------------------------------------------------------------------------------------
/**
 * @class CSVLoader
 * @brief Handles CSV file loading and weather data parsing
 *
 * A specialised class responsible for all file I/O and CSV parsing operations.
 * Encapsulates the logic for reading CSV weather files, parsing headers and records,
 * converting text data to numeric values, and populating a WeatherRecordCollection.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 28/02/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 09/03/2026 Liyana Afiqah, Refactored to read multiple files
 *
 * @version 03
 * @date 31/03/2026 Liyana Afiqah, Assignment 2: Updated to work with Map-based collection
 */
 //--------------------------------------------------------------------------------------

class CSVLoader
{
public:
    /**
     * @brief Loads CSV weather data and returns a hierarchically populated collection
     *
     * Reads file names from data_source.txt, opens the CSV file, parses the header
     * to identify column positions, and iterates through all records. For each record,
     * extracts date, time, wind speed, ambient temperature, and solar radiation values.
     * Converts text values to appropriate numeric types and creates WeatherRecord objects.
     * For each valid record, a WeatherRecord object is created and inserted into the
     * WeatherRecordCollection, which organises the data into a nested Map/BST structure
     *
     * @return WeatherRecordCollection - A collection organised by Year and Month containing
     * all successfully parsed weather records.
     */
    WeatherRecordCollection LoadAllCSV();
};

#endif // CSVLOADER_H_INCLUDED
