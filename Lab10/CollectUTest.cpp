// ===============================================================
// CollectUTest.cpp
//       Comprehensive testing of CollectU class
//       Tests static collection, indexing, and clearing logic
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "CollectU.h"
#include "Date.h"
#include "Utilities.h"
#include "Vector.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running CollectU Test Cases ====" << endl << endl;

    CollectU collector;

    // -------- TEST 1: Initial State --------
    cout << "--- Test 1: Initial State ---" << endl;
    AssertEqual("Initial size should be 0", collector.size() == 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Static Collection - CollectWindSpeed --------
    cout << "--- Test 2: Collect Logic (CollectWindSpeed) ---" << endl;
    WeatherRecord record1;
    WeatherRecord record2;
    WeatherRecord record3;
    WeatherRecord record4;
    WeatherRecord record5;

    record1.SetSpeed(5.0);
    record2.SetSpeed(6.0);
    record3.SetSpeed(3.0);
    record4.SetSpeed(4.0);
    record5.SetSpeed(6.0);

    CollectU::CollectWindSpeed(record1);
    CollectU::CollectWindSpeed(record2);
    CollectU::CollectWindSpeed(record3);
    CollectU::CollectWindSpeed(record4);
    CollectU::CollectWindSpeed(record5);

    AssertEqual("Size should be 5", collector.size() == 5, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Static Collection - CollectAmbientTemp --------
    cout << "--- Test 3: Collect Logic (CollectAmbientTemp) ---" << endl;
    collector.clear();

    record1.SetAmbTemp(30.4);
    record2.SetAmbTemp(30.4);
    record3.SetAmbTemp(30.4);
    record4.SetAmbTemp(30.4);
    record5.SetAmbTemp(30.4);

    CollectU::CollectAmbientTemp(record1);
    CollectU::CollectAmbientTemp(record2);
    CollectU::CollectAmbientTemp(record3);
    CollectU::CollectAmbientTemp(record4);
    CollectU::CollectAmbientTemp(record5);

    AssertEqual("Size should be 5", collector.size() == 5, passCount, failCount);
    cout << endl;

    // -------- TEST 4: Static Collection - CollectSolarRad --------
    cout << "--- Test 4: Collect Logic (CollectSolarRad) ---" << endl;
    collector.clear();

    record1.SetSolarRad(100);
    record2.SetSolarRad(100);
    record3.SetSolarRad(100);
    record4.SetSolarRad(100);
    record5.SetSolarRad(100);

    CollectU::CollectSolarRad(record1);
    CollectU::CollectSolarRad(record2);
    CollectU::CollectSolarRad(record3);
    CollectU::CollectSolarRad(record4);
    CollectU::CollectSolarRad(record5);

    AssertEqual("Size should be 5", collector.size() == 5, passCount, failCount);
    cout << endl;

   // -------- TEST 5: Access via Operator[] --------
    cout << "--- Test 5: Operator[] ---" << endl;
    int retrieved = collector[0];
    cout << "Expected: " << record1.GetSolarRad() << " | Retrieved: " << retrieved << endl;

    // Check if the first collected date matches
    AssertEqual("First element should be 100",(retrieved == 100), passCount, failCount);
    cout << endl;

    // -------- TEST 6: Static Persistence Test --------
    cout << "--- Test 6: Static Persistence ---" << endl;
    CollectU secondCollector;
    AssertEqual("New object instance should still see size 5",
                secondCollector.size() == 5, passCount, failCount);
    cout << endl;

    // -------- TEST 7: Size --------
    cout << "--- Test 7: Size() ---" << endl;
    WeatherRecord record6;
    record6.SetSolarRad(200);

    CollectU::CollectSolarRad(record6);

    AssertEqual("Size should be 6 after adding", collector.size() == 6, passCount, failCount);
    cout << endl;

    // -------- TEST 8: Clear Logic --------
    cout << "--- Test 8: Clear() ---" << endl;
    collector.clear();
    AssertEqual("Size after clear should be 0", collector.size() == 0, passCount, failCount);

    // Verify it affected other instances too
    AssertEqual("Second instance should also be cleared",
                secondCollector.size() == 0, passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "      Total : " << (passCount + failCount) << endl << endl;

    cout << "==== End of CollectU Test Cases ===" << endl;

    return 0;
}
