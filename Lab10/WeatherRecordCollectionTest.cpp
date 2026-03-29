// ===============================================================
// WeatherRecordCollectionTest.cpp
//      Comprehensive testing of WeatherRecordCollection functionality
//      Test dynamic array operations and record management
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 1
// ===============================================================

#include "WeatherRecordCollection.h"
#include "WeatherRecord.h"
#include "Date.h"
#include "Time.h"
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

    cout << "==== Running WeatherRecordCollection Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Collection Initialization --------
    // Verify that a new collection starts empty
    cout << "--- Test 1 (Collection Initialization) ---" << endl;
    WeatherRecordCollection collection;

    AssertEqual("New collection is empty (size = 0)", collection.Size() == 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Single Record Insertion --------
    // Verify that a single record can be inserted and retrieved
    cout << "--- Test 2 (Single Record Insertion) ---" << endl;

    Date date1(15, 3, 2016);
    Time time1(10, 30);
    WeatherRecord record1(date1, time1, 5.5f, 22.1f, 450);

    collection.Insert(record1, 0);

    AssertEqual("Collection size is 1 after insertion", collection.Size() == 1, passCount, failCount);
    AssertEqual("Retrieved record has correct day", collection[0].GetDate().GetDay() == 15, passCount, failCount);
    AssertEqual("Retrieved record has correct month", collection[0].GetDate().GetMonth() == 3, passCount, failCount);
    AssertEqual("Retrieved record has correct year", collection[0].GetDate().GetYear() == 2016, passCount, failCount);
    AssertEqual("Retrieved record has correct wind speed", collection[0].GetSpeed() == 5.5f, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Multiple Record Insertion --------
    // Verify that multiple records can be inserted sequentially
    cout << "--- Test 3 (Multiple Record Insertion) ---" << endl;

    Date date2(16, 3, 2016);
    Time time2(11, 0);
    WeatherRecord record2(date2, time2, 6.2f, 23.5f, 500);

    Date date3(17, 3, 2016);
    Time time3(11, 30);
    WeatherRecord record3(date3, time3, 4.8f, 21.2f, 480);

    collection.Insert(record2, collection.Size());
    collection.Insert(record3, collection.Size());

    AssertEqual("Collection size is 3 after three insertions", collection.Size() == 3, passCount, failCount);
    AssertEqual("Second record has correct day", collection[1].GetDate().GetDay() == 16, passCount, failCount);
    AssertEqual("Third record has correct day", collection[2].GetDate().GetDay() == 17, passCount, failCount);
    cout << endl;

    // -------- TEST 4: Data Integrity --------
    // Verify that all record fields are preserved correctly
    cout << "--- Test 4 (Data Integrity) ---" << endl;

    bool record1Intact = (collection[0].GetSpeed() == 5.5f &&
                          collection[0].GetAmbTemp() == 22.1f &&
                          collection[0].GetSolarRad() == 450);

    bool record2Intact = (collection[1].GetSpeed() == 6.2f &&
                          collection[1].GetAmbTemp() == 23.5f &&
                          collection[1].GetSolarRad() == 500);

    bool record3Intact = (collection[2].GetSpeed() == 4.8f &&
                          collection[2].GetAmbTemp() == 21.2f &&
                          collection[2].GetSolarRad() == 480);

    AssertEqual("First record data is intact", record1Intact, passCount, failCount);
    AssertEqual("Second record data is intact", record2Intact, passCount, failCount);
    AssertEqual("Third record data is intact", record3Intact, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Time Information --------
    // Verify that time information is preserved in collection
    cout << "--- Test 5 (Time Information Preservation) ---" << endl;

    bool record1TimeValid = (collection[0].GetTime().GetHour() == 10 &&
                             collection[0].GetTime().GetMins() == 30);

    bool record2TimeValid = (collection[1].GetTime().GetHour() == 11 &&
                             collection[1].GetTime().GetMins() == 0);

    bool record3TimeValid = (collection[2].GetTime().GetHour() == 11 &&
                             collection[2].GetTime().GetMins() == 30);

    AssertEqual("First record time is correct", record1TimeValid, passCount, failCount);
    AssertEqual("Second record time is correct", record2TimeValid, passCount, failCount);
    AssertEqual("Third record time is correct", record3TimeValid, passCount, failCount);
    cout << endl;

    // -------- TEST 6: Operator[] Access --------
    // Verify that operator[] provides correct access to records
    cout << "--- Test 6 (Operator[] Access) ---" << endl;

    WeatherRecord retrievedRecord = collection[1];

    AssertEqual("Operator[] returns correct record (day)", retrievedRecord.GetDate().GetDay() == 16, passCount, failCount);
    AssertEqual("Operator[] returns correct record (speed)", retrievedRecord.GetSpeed() == 6.2f, passCount, failCount);
    AssertEqual("Operator[] returns correct record (temp)", retrievedRecord.GetAmbTemp() == 23.5f, passCount, failCount);
    cout << endl;

    // -------- TEST 7: Collection Size Tracking --------
    // Verify that size is accurately tracked with operations
    cout << "--- Test 7 (Size Tracking) ---" << endl;

    WeatherRecordCollection newCollection;
    AssertEqual("Empty collection has size 0", newCollection.Size() == 0, passCount, failCount);

    newCollection.Insert(record1, 0);
    AssertEqual("Collection size is 1 after 1 insertion", newCollection.Size() == 1, passCount, failCount);

    newCollection.Insert(record2, 1);
    AssertEqual("Collection size is 2 after 2 insertions", newCollection.Size() == 2, passCount, failCount);

    newCollection.Insert(record3, 2);
    AssertEqual("Collection size is 3 after 3 insertions", newCollection.Size() == 3, passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "       Total: " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of WeatherRecordCollection Test Cases ====" << endl;

    return 0;
}
