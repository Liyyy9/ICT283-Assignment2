// ===============================================================
// CSVLoaderTest.cpp
//      Comprehensive testing of CSVLoader functionality
//      Test CSV file loading, data parsing, and error handling
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "CSVLoader.h"
#include "WeatherRecordCollection.h"
#include "Utilities.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running CSVLoader Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Successful CSV Load --------
    // Verify that CSV file loads successfully and returns non-empty collection
    cout << "--- Test 1 (Successful CSV Load) ---" << endl;
    CSVLoader loader;
    WeatherRecordCollection weather_data = loader.LoadAllCSV();

    AssertEqual("Collection is not empty", weather_data.Size() > 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Record Data Integrity --------
    // Verify that loaded records contain valid data
    cout << "--- Test 2 (Record Data Integrity) ---" << endl;

    bool hasValidDate = false;
    bool hasValidSpeed = false;
    bool hasValidTemp = false;
    bool hasValidSolarRad = false;

    // Check first record for data validity
    if (weather_data.Size() > 0)
    {
        WeatherRecord firstRecord = weather_data[0];

        // Check date validity (should be between 2014-2016 for this dataset)
        hasValidDate = (firstRecord.GetDate().GetYear() >= 2014 && firstRecord.GetDate().GetYear() <= 2016);

        // Check speed validity (realistic wind speed: 0-25 m/s)
        hasValidSpeed = (firstRecord.GetSpeed() >= 0 && firstRecord.GetSpeed() <= 25);

        // Check temperature validity (realistic ambient temp: -10 to 50 degrees C)
        hasValidTemp = (firstRecord.GetAmbTemp() >= -10 && firstRecord.GetAmbTemp() <= 50);

        // Check solar radiation validity (realistic: 0-1000)
        hasValidSolarRad = (firstRecord.GetSolarRad() >= 0 && firstRecord.GetSolarRad() <= 1000);
    }

    AssertEqual("First record has valid date", hasValidDate, passCount, failCount);
    AssertEqual("First record has valid wind speed", hasValidSpeed, passCount, failCount);
    AssertEqual("First record has valid ambient temperature", hasValidTemp, passCount, failCount);
    AssertEqual("First record has valid solar radiation", hasValidSolarRad, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Time Information --------
    // Verify that time information is loaded correctly
    cout << "--- Test 3 (Time Information Loading) ---" << endl;

    bool hasValidHour = false;
    bool hasValidMinutes = false;

    if (weather_data.Size() > 0)
    {
        WeatherRecord firstRecord = weather_data[0];
        hasValidHour = (firstRecord.GetTime().GetHour() >= 0 && firstRecord.GetTime().GetHour() <= 23);
        hasValidMinutes = (firstRecord.GetTime().GetMins() >= 0 && firstRecord.GetTime().GetMins() <= 59);
    }

    AssertEqual("First record has valid hour", hasValidHour, passCount, failCount);
    AssertEqual("First record has valid minutes", hasValidMinutes, passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "       Total: " << (passCount + failCount) << endl
         << endl;

    cout << "Total records loaded: " << weather_data.Size() << endl << endl;

    cout << "==== End of CSVLoader Test Cases ====" << endl;

    return 0;
}
