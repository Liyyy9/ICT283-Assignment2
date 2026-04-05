// ===============================================================
// CSVLoader.cpp
//      Loads and parses CSV weather data files
//      Manages file I/O and data processing
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "CSVLoader.h"
#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "CSVHeaderReader.h"
#include "Math.h"
#include "WeatherRecord.h"
#include "WeatherRecordCollection.h"
#include "MenuHandler.h"
#include "Constants.h"
#include "Utilities.h"
#include "Sort.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

// Loads CSV weather data and returns populated collection
// Reads the filename from data_source.txt, opens the CSV file, parses the header
// to identify column positions, and iterates through all records.
// Extracts date, time, wind speed, ambient temperature, and solar radiation values.
// Converts text values to appropriate numeric types and creates WeatherRecord objects.
// Returns a complete WeatherRecordCollection containing all successfully parsed records.
// Returns an empty collection if file cannot be opened or header cannot be read.
WeatherRecordCollection CSVLoader::LoadAllCSV()
{
    CSVHeaderReader headerReader;
    int fileCount = 0;
    int total = 0;
    int recordsInThisFile;

    // Reading data_source.txt for file name
    string dataSource = "data_source.txt";
    ifstream source(PATH + dataSource);

    if (!source)
    {
        cout << "Error opening: " << PATH << dataSource << endl;
        return WeatherRecordCollection();
    }

    Vector<WeatherRecord> fileRecords;

    // Create one collection for all data read from multiple files
    WeatherRecordCollection weather_data;

    // Extracting file name from data_source.txt
    string infileName;
    while (getline(source, infileName))
    {
        fileRecords.Clear();
        recordsInThisFile = 0;

        if (infileName.empty())
        {
            cout << dataSource << " does not contain a file name." << endl;
            return WeatherRecordCollection();
        }

        // Reading and opening the file found in data_source.txt
        ifstream infile(PATH + infileName);

        // Check if file opened successfully
        // Skips to next file if unable to open
        if (!infile)
        {
            cout << "Error opening: " << infileName << "\n"
                 << endl;
            continue;
        }

        // Read header and get column indexes for date/time, speed, ambient temperature, solar radiation
        int dateTimeIndex;
        int speedIndex;
        int ambientTempIndex;
        int solarRadIndex;

        if (!headerReader.ReadHeader(infile, dateTimeIndex, speedIndex, ambientTempIndex, solarRadIndex))
        {
            cout << "Required columns not found\n";
            return WeatherRecordCollection();
        }

        // Read each line from the CSV file one at a time
        string line;
        cout << "Loading data. Please wait..." << endl;

        while (getline(infile, line))
        {
            // Variables to hold individual fields from the CSV
            string field = "";
            int currentCol = 0;

            string dateTimeStr = "";
            string speedStr = "";
            string ambTempStr = "";
            string solradStr = "";

            // Go through each character in the line
            // When we hit a comma or end of line, save the field
            // Change int to size_t to satisfy -Wsign-compare warning
            for (size_t i = 0; i <= line.length(); i++)
            {
                if (i == line.length() || line[i] == COMMA_DELIMITER)
                {
                    // Check which column this field belongs to
                    // and save it to the correct variable
                    if (currentCol == dateTimeIndex)
                    {
                        dateTimeStr = field;
                    }

                    if (currentCol == speedIndex)
                    {
                        speedStr = field;
                    }

                    if (currentCol == ambientTempIndex)
                    {
                        ambTempStr = field;
                    }

                    if (currentCol == solarRadIndex)
                    {
                        solradStr = field;
                    }

                    // Reset for the next field
                    field = "";
                    currentCol++;
                }
                else
                {
                    // Add this character to the current field
                    field += line[i];
                }
            }

            // Skip rows that are missing data
            if (dateTimeStr.empty() || speedStr.empty() || speedStr == "N/A" || ambTempStr.empty() || solradStr.empty())
            {
                continue;
            }

            // Create temporary objects to hold date and time
            stringstream ss(dateTimeStr);
            Date tempDate;
            Time tempTime;

            // Convert text numbers to actual numbers
            float speed = 0.0f;
            speed = stof(speedStr); // Speed from text to decimal

            float amb = 0.0f;
            amb = stof(ambTempStr); // Temperature from text to decimal

            int sr = stoi(solradStr); // Solar radiation from text to whole number

            // Parse the date and time from the string
            ss >> tempDate;
            ss >> tempTime;

            // Create a new weather record and add it to our collection
            WeatherRecord record(tempDate, tempTime, speed, amb, sr);

            fileRecords.Add(record);

            recordsInThisFile++;
        }

        Sort sorter;
        sorter.ExecuteSort(0, fileRecords.Size() - 1, fileRecords);

        weather_data.InsertFromMidPoint(fileRecords, 0, fileRecords.Size() - 1);

        // Close the file when we're done reading
        infile.close();
        // Tell the user how many records were loaded
        cout << "Records loaded: " << recordsInThisFile << " from " << infileName << endl
             << endl;
        total += recordsInThisFile;
        fileCount++;
    }

    source.close();

    // Tell the user how many records were loaded
    cout << "Total records loaded: " << total << " from " << fileCount << " files.\n"
         << endl
         << endl;

    return weather_data;
}
