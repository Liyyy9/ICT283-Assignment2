// ===============================================================
// CSVHeaderReader.h
//      Reads CSV file headers and identifies column indices
//      Matches column names to their positions in the CSV file
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================

#ifndef CSVHEADERREADER_H_INCLUDED
#define CSVHEADERREADER_H_INCLUDED
#include <iostream>

using std::ifstream;

//---------------------------------------------------------------------------------
/**
 * @class CSVHeaderReader
 * @brief Reads CSV file headers and identifies column indexes
 *
 * Parses the first line of a CSV file to find specific columns.
 * Searches for DATE_TIME_COLUMN (WAST), SPEED_COLUMN (S), AMBIENT_TEMP_COLUMN "T" and SOLAR_RAD_COLUMN "SR" columns.
 * Returns the column indexes for use when reading data rows.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 18/02/2026 Liyana Afiqah, Initial Implementation
 */

class CSVHeaderReader
{
public:
    /**
     * @brief Reads the header line from a CSV file and identifies column indexes for all required columns
     *
     * Parses the first line of the CSV to find WAST (date/time), S (speed), T (ambient temperature),
     * and SR (solar radiation) columns. Sets the provided index references to their column positions.
     *
     * @param infile Reference to the input file stream positioned at the header
     * @param dateTimeIndex Reference to store the index of the WAST column
     * @param speedIndex Reference to store the index of the S column
     * @param ambientTempIndex Reference to store the index of the T column
     * @param solarRadIndex Reference to store the index of the SR column
     *
     * @return true if all required columns are found, false otherwise
     */
    bool ReadHeader(ifstream &infile, int &dateTimeIndex, int &speedIndex, int &ambientTempIndex, int &solarRadIndex);
};

#endif // CSVHEADERREADER_H_INCLUDED
