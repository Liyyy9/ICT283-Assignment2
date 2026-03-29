// ===============================================================
// CSVHeaderReader.cpp
//      Reads CSV file headers and identifies column indices
//      Matches column names (WAST, S) to their positions
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================

#include "CSVHeaderReader.h"
#include "Constants.h"

#include <fstream>
#include <string>

using std::ifstream;
using std::string;

// Reads the header line from CSV file and identifies column indexes for date/time and speed
// Parses the first line to find WAST (date/time), S (speed), T(ambient temp), and SR (solar radiation) columns
// Returns true if both columns are found, false otherwise
bool CSVHeaderReader::ReadHeader(ifstream &infile, int &dateTimeIndex, int &speedIndex, int &ambientTempIndex, int &solarRadIndex)
{
    string headerLine;

    if (!getline(infile, headerLine))
    {
        return false;
    }

    dateTimeIndex = -1;
    speedIndex = -1;
    ambientTempIndex = -1;
    solarRadIndex = -1;

    string token = "";
    int colIndex = 0;

    for (int i = 0; i <= (int)headerLine.length(); i++)
    {
        if (i == headerLine.length() || headerLine[i] == COMMA_DELIMITER)
        {
            if (token == DATE_TIME_COLUMN)
            {
                dateTimeIndex = colIndex;
            }

            if (token == SPEED_COLUMN)
            {
                speedIndex = colIndex;
            }

            if (token == AMBIENT_TEMP_COLUMN)
            {
                ambientTempIndex = colIndex;
            }

            if (token == SOLAR_RAD_COLUMN)
            {
                solarRadIndex = colIndex;
            }

            token = "";
            colIndex++;
        }
        else
        {
            token += headerLine[i];
        }
    }

    return (dateTimeIndex != -1 && speedIndex != -1 && ambientTempIndex != -1 && solarRadIndex != -1);
}
