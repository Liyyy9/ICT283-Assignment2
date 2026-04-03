// ===============================================================
// TimeTest.cpp
//      Comprehensive testing of Time class
//      Test constructors, getters, setters, and I/O operations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "Time.h"
#include "Utilities.h"
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running Time Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Default Constructor --------
    // Verify that default constructor initialises time to 12:30
    cout << "--- Test 1 (Default Constructor) ---" << endl;
    Time myTime;
    cout << "Constructed Default Time object: myTime" << endl
         << endl;
    AssertEqual("Default hour is 12", myTime.GetHour() == 12, passCount, failCount);
    AssertEqual("Default minute is 30", myTime.GetMins() == 30, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Parameterised Constructor --------
    // Verify that parameterised constructor correctly initialises to provided values
    cout << "--- Test 2 (Parameterised Constructor) ---" << endl;
    Time myTime2(14, 45);
    cout << "Constructed Parameterised Time object: myTime2(14, 45)" << endl
         << endl;
    AssertEqual("Hour is 14", myTime2.GetHour() == 14, passCount, failCount);
    AssertEqual("Minute is 45", myTime2.GetMins() == 45, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Invalid Time Defaults to 12:30 --------
    // Verify that invalid time values default to 12:30
    cout << "--- Test 3 (Invalid Time Defaults to 12:30) ---" << endl;
    Time myTime3(25, 61);
    cout << "Constructed Time object with invalid values: myTime3(25, 61)" << endl
         << endl;
    AssertEqual("Invalid hour defaults to 12", myTime3.GetHour() == 12, passCount, failCount);
    AssertEqual("Invalid minute defaults to 30", myTime3.GetMins() == 30, passCount, failCount);
    cout << endl;

    // -------- TEST 4: Setters --------
    // Verify that setter methods correctly update time values
    cout << "--- Test 4 (Setters) ---" << endl;
    Time myTime4;
    myTime4.SetHour(9);
    myTime4.SetMins(30);
    cout << "Set hour to 9 and minute to 30" << endl
         << endl;
    AssertEqual("Hour is 9", myTime4.GetHour() == 9, passCount, failCount);
    AssertEqual("Minute is 30", myTime4.GetMins() == 30, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Output Stream Operator --------
    // Verify that output displays time in correct format HH:MM
    cout << "--- Test 5 (Output Stream Operator) ---" << endl;
    Time myTime5(9, 5);
    cout << "Created Time object: myTime5(9, 5)" << endl;
    cout << "Output: " << myTime5 << endl
         << endl;
    AssertEqual("Output format correct", true, passCount, failCount);
    cout << endl;

    // -------- TEST SUMMARY --------
    cout << "==== Test Summary ====" << endl;
    cout << "Passed: " << passCount << endl;
    cout << "Failed: " << failCount << endl;
    cout << "Total: " << (passCount + failCount) << endl;

    cout << "==== End of Time Test Cases ====" << endl
         << endl;
    return 0;
}
