// ===============================================================
// MapTest.cpp
//      Unit test for the custom Map wrapper class
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "Map.h"
#include "Date.h"
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

    cout << "==== Running Map Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Basic Insertion and Size --------
    cout << "--- Test 1 (Insertion & Size) ---" << endl;
    Map<int, string> yearMap;

    yearMap[2023] = "Data for 2023";
    yearMap[2024] = "Data for 2024";
    yearMap[2025] = "Data for 2025";

    AssertEqual("Map correctly stores 3 elements", yearMap.Size() == 3, passCount, failCount);
    AssertEqual("Retrieval: Key 2023 matches value", yearMap[2023] == "Data for 2023", passCount, failCount);
    cout << endl;

    // -------- TEST 2: Search Logic (Contains) --------
    cout << "--- Test 2 (Search Implementation: Contains) ---" << endl;

    AssertEqual("Search: Successfully found existing key 2024", yearMap.Contains(2024), passCount, failCount);
    AssertEqual("Search: Correctly missed non-existent key 1990", yearMap.Contains(1990) == false, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Update and Duplicate Key Logic --------
    cout << "--- Test 3 (Update/Overwrite Logic) ---" << endl;

    yearMap[2023] = "Updated Data";
    AssertEqual("Map updated value for existing key", yearMap[2023] == "Updated Data", passCount, failCount);
    AssertEqual("Size remains 3 after update", yearMap.Size() == 3, passCount, failCount);
    cout << endl;

    // -------- TEST 4: Clear() --------
    cout << "--- Test 4 (Clear Logic) ---" << endl;

    yearMap.Clear();
    AssertEqual("Map size is 0 after Clear()", yearMap.Size() == 0, passCount, failCount);
    AssertEqual("Contains returns false after Clear()", yearMap.Contains(2023) == false, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Using Different Key/Value Types --------
    cout << "--- Test 5 (Template Flexibility) ---" << endl;
    Map<string, double> rainMap;
    rainMap["January"] = 15.5;

    AssertEqual("Template works with String keys", rainMap.Contains("January"), passCount, failCount);
    AssertEqual("Template works with Double values", rainMap["January"] == 15.5, passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ===" << endl;
    cout << "Total Passed : " << passCount << endl;
    cout << "Total Failed : " << failCount << endl;
    cout << "       Total : " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of Map Test Cases ====" << endl;

    return 0;
}
