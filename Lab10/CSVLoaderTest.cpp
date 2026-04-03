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
#include "Map.h"
#include "Bst.h"

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
    cout << "--- Test 1: Successful CSV Load ---" << endl;
    CSVLoader loader;
    WeatherRecordCollection weather_data = loader.LoadAllCSV();

    AssertEqual("Collection is not empty", weather_data.GetYearCount() > 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Data Integrity via Search --------
    cout << "--- Test 2: Data Integrity via Search ---" << endl;

    bool foundRecord = false;

    if(weather_data.GetYearCount() > 0)
    {
        const WeatherRecordCollection::YearCabinet& inventory = weather_data.GetInventory();

        int testYear = 2007;
        int testMonth = 2;

        if(inventory.Contains(testYear) && inventory.At(testYear).Contains(testMonth))
        {
            const WeatherRecordCollection::RecordFolder& recordFolder = inventory.At(testYear).At(testMonth);

            WeatherRecord target;

            Date date(25,2,2007);
            Time time(22,10);
            target.SetDate(date);
            target.SetTime(time);

            foundRecord = recordFolder.Search(target);
        }
    }

    AssertEqual("Specific record found in BST", foundRecord, passCount, failCount);

    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "       Total: " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of CSVLoader Test Cases ====" << endl;

    return 0;
}
