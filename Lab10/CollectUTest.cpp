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
    cout << "--- Test 1 (Initial State) ---" << endl;
    AssertEqual("Initial size should be 0", collector.size() == 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Static Collection (Simulating BST Callback) --------
    cout << "--- Test 2 (Collect Logic) ---" << endl;
    Date d1(1, 1, 2020);
    Date d2(15, 6, 2021);

    // BST callback
    CollectU::Collect(d1);
    CollectU::Collect(d2);

    AssertEqual("Size after 2 collections should be 2", collector.size() == 2, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Access via Operator[] --------
    cout << "--- Test 3 (Operator[]) ---" << endl;
    Date retrieved = collector[0];
    cout << "Expected: " << d1 << " | Retrieved: " << retrieved << endl;

    // Check if the first collected date matches
    AssertEqual("First element should be 01 January 2020",
                (retrieved.GetDay() == 1 && retrieved.GetYear() == 2020),
                passCount, failCount);
    cout << endl;

    // -------- TEST 4: Static Persistence Test --------
    cout << "--- Test 4 (Static Persistence) ---" << endl;
    CollectU secondCollector;
    AssertEqual("New object instance should still see size 2",
                secondCollector.size() == 2, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Clear Logic --------
    cout << "--- Test 5 (Clear) ---" << endl;
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
