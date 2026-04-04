// ===============================================================
// WeatherRecordCollectionTest.cpp
//      Comprehensive testing of WeatherRecordCollection functionality
//      Test hierarchical Map-of-Maps-of-BSTs record management
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "WeatherRecordCollection.h"
#include "WeatherRecord.h"
#include "Date.h"
#include "Time.h"
#include "Utilities.h"
#include "Map.h"
#include "Bst.h"
#include "WeatherStatsCollector.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::abs;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;
    WeatherStatsCollector collector;

    cout << "==== Running WeatherRecordCollection Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Collection Initialization --------
    // Verify that a new collection starts empty
    cout << "--- Test 1: Collection Initialization ---" << endl;
    WeatherRecordCollection collection;

    AssertEqual("New collection has 0 years", collection.GetYearCount() == 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Hierarchical Insertion --------
    // Verify that inserting records creates the correct Map structure
    cout << "--- Test 2: Hierarchical Insertion ---" << endl;

    // Record 1: March 2016
    WeatherRecord record1(Date(15, 3, 2016), Time(10, 30), 5.5f, 22.1f, 450);
    // Record 2: March 2016
    WeatherRecord record2(Date(16, 3, 2016), Time(11, 00), 6.0f, 23.0f, 500);
    // Record 3: April 2017
    WeatherRecord record3(Date(1, 4, 2017), Time(12, 00), 4.0f, 20.0f, 300);

    collection.Insert(record1);
    collection.Insert(record2);
    collection.Insert(record3);

    const WeatherRecordCollection::YearCabinet& inv = collection.GetInventory();

    AssertEqual("Collection has 2 unique years (2016, 2017)", collection.GetYearCount() == 2, passCount, failCount);
    AssertEqual("Year 2016 exists in Map", inv.Contains(2016), passCount, failCount);
    AssertEqual("Year 2017 exists in Map", inv.Contains(2017), passCount, failCount);
    cout << endl;

    // -------- TEST 3: Month Map Integrity --------
    cout << "--- Test 3: Month Map Integrity ---" << endl;

    bool march2016Exists = inv.At(2016).Contains(3);
    bool april2017Exists = inv.At(2017).Contains(4);
    bool april2016DoesNotExist = !inv.At(2016).Contains(4);

    AssertEqual("March (3) exists in 2016 drawer", march2016Exists, passCount, failCount);
    AssertEqual("April (4) exists in 2017 drawer", april2017Exists, passCount, failCount);
    AssertEqual("April (4) does NOT exist in 2016", april2016DoesNotExist, passCount, failCount);
    cout << endl;

    // -------- TEST 4: BST Storage and Traversal --------
    // Use WeatherStatsCollector to verify that both records were stored in the March 2016 BST
    cout << "--- Test 4: BST Storage and Traversal ---" << endl;

    collector.clear();
    inv.At(2016).At(3).InOrder(WeatherStatsCollector::CollectWindSpeed);

    Vector<double>& marchSpeeds = collector.GetCollection();

    cout << marchSpeeds[1];
    AssertEqual("March 2016 BST contains 2 records", marchSpeeds.Size() == 2, passCount, failCount);
    AssertEqual("First speed in BST is 19.8", abs(marchSpeeds[0]- 19.8) < 0.01, passCount, failCount);
    AssertEqual("Second speed in BST is 21.6", abs(marchSpeeds[1]- 21.6) < 0.01, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Data Integrity (Search) --------
    cout << "--- Test 5: Data Integrity via BST Search ---" << endl;

    WeatherRecord searchTarget(Date(1, 4, 2017), Time(12, 00), 4.0f, 20.0f, 300);

    bool found = inv.At(2017).At(4).Search(searchTarget);
    AssertEqual("Search successfully found April 2017 record in BST", found, passCount, failCount);
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
