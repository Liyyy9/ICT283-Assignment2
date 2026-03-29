// ===============================================================
// UtilitiesTest.cpp
//      Comprehensive testing of Utilities functions
//      Test month name conversion, leap year checking,
//      days in month calculation, and date/time validation
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 1
// ===============================================================

#include "Utilities.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running Utilities Test Cases ====" << endl
         << endl;

    // -------- TEST 1: GetMonthName --------
    // Verify that month numbers are correctly converted to month names
    cout << "--- Test 1 (GetMonthName) ---" << endl;
    AssertEqual("Month 1 is January", GetMonthName(1) == "January", passCount, failCount);
    AssertEqual("Month 2 is February", GetMonthName(2) == "February", passCount, failCount);
    AssertEqual("Month 6 is June", GetMonthName(6) == "June", passCount, failCount);
    AssertEqual("Month 12 is December", GetMonthName(12) == "December", passCount, failCount);
    cout << endl;

    // -------- TEST 2: IsLeapYear --------
    // Verify leap year calculation following the rules:
    // - Divisible by 400: leap year
    // - Divisible by 100: NOT leap year
    // - Divisible by 4: leap year
    // - Otherwise: NOT leap year
    cout << "--- Test 2 (IsLeapYear) ---" << endl;
    AssertEqual("1800 is not a leap year", IsLeapYear(1800) == false, passCount, failCount);
    AssertEqual("1900 is not a leap year", IsLeapYear(1900) == false, passCount, failCount);
    AssertEqual("2000 is a leap year", IsLeapYear(2000) == true, passCount, failCount);
    AssertEqual("2004 is a leap year", IsLeapYear(2004) == true, passCount, failCount);
    AssertEqual("2016 is a leap year", IsLeapYear(2016) == true, passCount, failCount);
    AssertEqual("2023 is not a leap year", IsLeapYear(2023) == false, passCount, failCount);
    AssertEqual("2400 is a leap year", IsLeapYear(2400) == true, passCount, failCount);
    cout << endl;

    // -------- TEST 3: GetDaysInMonth --------
    // Verify the number of days in each month (accounting for leap years)
    cout << "--- Test 3 (GetDaysInMonth) ---" << endl;
    AssertEqual("January has 31 days", GetDaysInMonth(1, 2016) == 31, passCount, failCount);
    AssertEqual("April has 30 days", GetDaysInMonth(4, 2016) == 30, passCount, failCount);
    AssertEqual("February 2016 (leap year) has 29 days", GetDaysInMonth(2, 2016) == 29, passCount, failCount);
    AssertEqual("February 2017 (not leap year) has 28 days", GetDaysInMonth(2, 2017) == 28, passCount, failCount);
    AssertEqual("December has 31 days", GetDaysInMonth(12, 2016) == 31, passCount, failCount);
    AssertEqual("June has 30 days", GetDaysInMonth(6, 2016) == 30, passCount, failCount);
    AssertEqual("November has 30 days", GetDaysInMonth(11, 2023) == 30, passCount, failCount);
    cout << endl;

    // -------- TEST 4: IsValidDate --------
    // Verify date validation for various valid and invalid dates
    cout << "--- Test 4 (IsValidDate) ---" << endl;
    AssertEqual("1/1/1800 is valid", IsValidDate(1, 1, 1800) == true, passCount, failCount);
    AssertEqual("30/6/2016 is valid", IsValidDate(30, 6, 2016) == true, passCount, failCount);
    AssertEqual("29/2/2000 is valid (leap year)", IsValidDate(29, 2, 2000) == true, passCount, failCount);
    AssertEqual("29/2/2001 is invalid (not leap year)", IsValidDate(29, 2, 2001) == false, passCount, failCount);
    AssertEqual("31/4/2016 is invalid (April has 30 days)", IsValidDate(31, 4, 2016) == false, passCount, failCount);
    AssertEqual("0/1/2016 is invalid (day 0)", IsValidDate(0, 1, 2016) == false, passCount, failCount);
    AssertEqual("32/1/2016 is invalid (day 32)", IsValidDate(32, 1, 2016) == false, passCount, failCount);
    AssertEqual("1/0/2016 is invalid (month 0)", IsValidDate(1, 0, 2016) == false, passCount, failCount);
    AssertEqual("1/13/2016 is invalid (month 13)", IsValidDate(1, 13, 2016) == false, passCount, failCount);
    cout << endl;

    // -------- TEST 5: IsValidTime --------
    // Verify time validation for valid and invalid times
    cout << "--- Test 5 (IsValidTime) ---" << endl;
    AssertEqual("12:30 is valid", IsValidTime(12, 30) == true, passCount, failCount);
    AssertEqual("0:0 is valid", IsValidTime(0, 0) == true, passCount, failCount);
    AssertEqual("23:59 is valid", IsValidTime(23, 59) == true, passCount, failCount);
    AssertEqual("24:0 is invalid (hour > 23)", IsValidTime(24, 0) == false, passCount, failCount);
    AssertEqual("9:60 is invalid (minute > 59)", IsValidTime(9, 60) == false, passCount, failCount);
    AssertEqual("-1:30 is invalid (negative hour)", IsValidTime(-1, 30) == false, passCount, failCount);
    AssertEqual("12:-1 is invalid (negative minute)", IsValidTime(12, -1) == false, passCount, failCount);
    cout << endl;

    // -------- TEST 6: IsValidMonth --------
    // Verify month input validation for valid and invalid input
    cout << "--- Test 6 (IsValidMonth) ---" << endl;
    AssertEqual("1 is valid", IsValidMonth(1) == true, passCount, failCount);
    AssertEqual("12 is valid", IsValidMonth(12) == true, passCount, failCount);
    AssertEqual("6 is valid", IsValidMonth(6) == true, passCount, failCount);
    AssertEqual("-1 is invalid", IsValidMonth(-1) == false, passCount, failCount);
    AssertEqual("13 is invalid", IsValidMonth(13) == false, passCount, failCount);
    cout << endl;

    // -------- TEST 7: Edge Cases --------
    // Verify edge cases for date validation
    cout << "--- Test 7 (Edge Cases) ---" << endl;
    AssertEqual("31/12/2016 is valid (last day of year)", IsValidDate(31, 12, 2016) == true, passCount, failCount);
    AssertEqual("1/1/0 is valid (year 0)", IsValidDate(1, 1, 0) == true, passCount, failCount);
    AssertEqual("30/2/2000 is invalid (February has max 29 days)", IsValidDate(30, 2, 2000) == false, passCount, failCount);
    AssertEqual("31/3/2023 is valid (March has 31 days)", IsValidDate(31, 3, 2023) == true, passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "       Total: " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of Utilities Test Cases ====" << endl;

    return 0;
}
