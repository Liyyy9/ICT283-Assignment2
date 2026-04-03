// ===============================================================
// DateTest.cpp
//      Comprehensive testing of Date class
//      Test constructors, getters, setters, helper function and
//      I/O operations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================
#include "Date.h"
#include "Utilities.h"
#include "CSVHeaderReader.h"
#include "Vector.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::max;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running Date Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Default Constructor --------
    // Verify that default constructor initialises date to 1/1/1800
    cout << "--- Test 1: Default Constructor ---" << endl;
    Date myDate;
    cout << "Constructed Default Date object: myDate" << endl
         << endl;
    AssertEqual("Default day is 1", myDate.GetDay() == 1, passCount, failCount);
    AssertEqual("Default month is 1", myDate.GetMonth() == 1, passCount, failCount);
    AssertEqual("Default year is 1800", myDate.GetYear() == 1800, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Parameterised Constructor --------
    // Verify that default parameterised constructor correctly initialises to provided values
    cout << "--- Test 2: Parameterised Constructor ---" << endl;
    Date myDate2(30, 6, 2016);
    cout << "Constructed Parameterised Date object: myDate2" << endl
         << endl;
    AssertEqual("Day is 30", myDate2.GetDay() == 30, passCount, failCount);
    AssertEqual("Month is 6", myDate2.GetMonth() == 6, passCount, failCount);
    AssertEqual("Year is 2016", myDate2.GetYear() == 2016, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Output Stream Operator --------
    // Verify that ostream operator formats date correctly (DD MonthName YYYY)
    cout << "--- Test 3: << operator ---" << endl;
    cout << "Default:" << endl;
    cout << myDate << endl;

    cout << "Parameterised:" << endl;
    cout << myDate2 << endl
         << endl;

    // -------- TEST 4: Getter Methods --------
    // Verify that getter methods return correct values
    cout << "--- Test 4: Getters ---" << endl;
    AssertEqual("myDate2.GetDay() returns 30", myDate2.GetDay() == 30, passCount, failCount);
    AssertEqual("myDate2.GetMonth() returns 6", myDate2.GetMonth() == 6, passCount, failCount);
    AssertEqual("myDate2.GetYear() returns 2016", myDate2.GetYear() == 2016, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Setter Methods --------
    // Verify that setter methods correctly update date values
    cout << "--- Test 5: Setters ---" << endl;
    cout << "Before setting : " << endl;
    cout << myDate << endl;

    myDate.SetDay(16);
    myDate.SetMonth(10);
    myDate.SetYear(2015);

    AssertEqual("Day set to 16", myDate.GetDay() == 16, passCount, failCount);
    AssertEqual("Month set to 10", myDate.GetMonth() == 10, passCount, failCount);
    AssertEqual("Year set to 2015", myDate.GetYear() == 2015, passCount, failCount);
    cout << endl;

    cout << "After setting  : " << endl;
    cout << myDate << endl;

    // -------- TEST 6: GetMonthName Helper Function --------
    // Verify that GetMonthName correctly converts month numbers (1-12) to month names
    cout << "--- Test 6: GetMonthName ---" << endl;
    AssertEqual("GetMonthName(1) returns January", GetMonthName(1) == "January", passCount, failCount);
    AssertEqual("GetMonthName(6) returns June", GetMonthName(6) == "June", passCount, failCount);
    AssertEqual("GetMonthName(12) returns December", GetMonthName(12) == "December", passCount, failCount);
    AssertEqual("GetMonthName(2) returns February", GetMonthName(2) == "February", passCount, failCount);
    cout << endl;

    // -------- TEST 7: IsLeapYear Helper Function --------
    // Verify that IsLeapYear correctly identifies a leap year
    cout << "--- Test 7: IsLeapYear ---" << endl;

    AssertEqual("2024 is a leap year", IsLeapYear(2024) == true, passCount, failCount);
    AssertEqual("2000 is a leap year", IsLeapYear(2000) == true, passCount, failCount);
    AssertEqual("1900 is NOT a leap year", IsLeapYear(1900) == false, passCount, failCount);
    AssertEqual("2023 is NOT a leap year", IsLeapYear(2023) == false, passCount, failCount);
    cout << endl;

    // -------- TEST 8: GetDaysInMonth Helper Function --------
    // Verify that GetDaysInMonth correctly returns days in a month, taking leap years into account
    cout << "--- Test 8: GetDaysInMonth ---" << endl;

    AssertEqual("February 2024 returns 29", GetDaysInMonth(2, 2024) == 29, passCount, failCount);
    AssertEqual("February 2023 returns 28", GetDaysInMonth(2, 2023) == 28, passCount, failCount);
    AssertEqual("April 2026 returns 30", GetDaysInMonth(4, 2026) == 30, passCount, failCount);
    AssertEqual("December 2026 returns 31", GetDaysInMonth(12, 2026) == 31, passCount, failCount);
    cout << endl;

    // -------- TEST 9: IsValidDate Helper Function --------
    // Verify that IsValidDate correctly identifies invalid dates
    cout << "--- Test 9: IsValidDate ---" << endl;

    AssertEqual("29 Feb 2024 is a valid date", IsValidDate(29, 2, 2024) == true, passCount, failCount);
    AssertEqual("29 Feb 2023 is NOT a valid date", IsValidDate(29, 2, 2023) == false, passCount, failCount);
    AssertEqual("31 April 2026 is NOT a valid date", IsValidDate(31, 4, 2026) == false, passCount, failCount);
    AssertEqual("32 December 2026 is NOT a valid date", IsValidDate(32, 12, 2026) == false, passCount, failCount);
    AssertEqual("15 August 2026 is a valid date", IsValidDate(15, 8, 2026) == true, passCount, failCount);
    AssertEqual("31 March 2026 is a valid date", IsValidDate(31, 3, 2026) == true, passCount, failCount);
    cout << endl;

    // -------- TEST 10: Comparison Operators (< and ==) --------
    // Verify that the comparison operators correctly identify earlier,
    // later, and identical dates.
    cout << "--- Test 10: Comparison Operators ---" << endl;

    Date earlyDate(1, 1, 2010);
    Date middleDate(15, 6, 2015);
    Date middleDateCopy(15, 6, 2015);
    Date lateDate(31, 12, 2020);
    Date differentDay(16, 6, 2015);
    Date differentMonth(15, 7, 2015);

    // Testing Equality (==)
    AssertEqual("Identical dates are equal", (middleDate == middleDateCopy) == true, passCount, failCount);
    AssertEqual("Different dates are NOT equal", (earlyDate == lateDate) == false, passCount, failCount);
    AssertEqual("Different days are NOT equal", (middleDate == differentDay) == false, passCount, failCount);

    // Testing Less-Than (<)
    AssertEqual("2010 < 2015 (Year check)", (earlyDate < middleDate) == true, passCount, failCount);
    AssertEqual("2020 is NOT < 2015", (lateDate < middleDate) == false, passCount, failCount);
    AssertEqual("June < July (Month check)", (middleDate < differentMonth) == true, passCount, failCount);
    AssertEqual("Day 15 < Day 16 (Day check)", (middleDate < differentDay) == true, passCount, failCount);
    AssertEqual("Same dates are NOT < each other", (middleDate < middleDateCopy) == false, passCount, failCount);

    cout << endl;

    // -------- TEST 11: CSV Header Reading - WAST, S, T, and SR Columns --------
    // Verify that CSV header reader correctly identifies WAST (date/time), S (speed),
    // T (ambient temperature), and SR (solar radiation) column indexes
    // Reads header in CSV file and tests parsing of date/time and speed values
    cout << "--- Test 11: CSV Header - WAST, S, T and SR ---" << endl;
    ifstream metadataFile("data/MetData-31-3b.csv");

    // Check if metadata file exists and can be opened
    if (metadataFile)
    {
        // Create CSV header reader and read column indexes
        CSVHeaderReader reader;
        Vector<string> vector;

        int wastIndex = -1;
        int speedIndex = -1;
        int ambIndex = -1;
        int solradIndex = -1;

        bool headerRead = reader.ReadHeader(metadataFile, wastIndex, speedIndex, ambIndex, solradIndex);
        AssertEqual("Header read successfully", headerRead == true, passCount, failCount);
        AssertEqual("WAST column index found", wastIndex >= 0, passCount, failCount);
        AssertEqual("S column index found", speedIndex >= 0, passCount, failCount);
        AssertEqual("T column index found", ambIndex >= 0, passCount, failCount);
        AssertEqual("SR column index found", solradIndex >= 0, passCount, failCount);
        cout << endl;

        // Read first data line and parse columns
        if (headerRead && wastIndex >= 0 && speedIndex >= 0 && ambIndex >= 0 && solradIndex >= 0)
        {
            string dataLine;
            if (getline(metadataFile, dataLine))
            {
                // Parse CSV line by comma delimiter
                stringstream ss(dataLine);
                string token;
                Vector<string> columns;
                while (getline(ss, token, ','))
                {
                    columns.Insert(token, columns.Size());
                }

                // Verify we can access WAST, S, T, and SR columns
                int maxIndex = max(max(wastIndex, speedIndex), max(ambIndex, solradIndex));
                AssertEqual("Data line has enough columns", columns.Size() > maxIndex, passCount, failCount);

                if (columns.Size() > maxIndex)
                {
                    // Verify WAST column contains date/time format
                    string wastValue = columns[wastIndex];
                    AssertEqual("WAST contains date separator", wastValue.find('/') != string::npos, passCount, failCount);
                    AssertEqual("WAST contains time separator", wastValue.find(':') != string::npos, passCount, failCount);

                    // Verify S column contains numeric speed value
                    string speedValue = columns[speedIndex];
                    AssertEqual("S value is not empty", speedValue.length() > 0, passCount, failCount);
                    AssertEqual("S value starts with digit", isdigit(speedValue[0]), passCount, failCount);

                    // Verify T column contains numeric temperature value
                    string ambValue = columns[ambIndex];
                    AssertEqual("T value is not empty", ambValue.length() > 0, passCount, failCount);
                    AssertEqual("T value starts with digit or minus", isdigit(ambValue[0]) || ambValue[0] == '-', passCount, failCount);

                    // Verify SR column contains numeric solar radiation value
                    string solradValue = columns[solradIndex];
                    AssertEqual("SR value is not empty", solradValue.length() > 0, passCount, failCount);
                    AssertEqual("SR value starts with digit", isdigit(solradValue[0]), passCount, failCount);
                }
            }
            else
            {
                cout << "FAIL : Could not read data line from file" << endl;
                failCount++;
            }
        }

        metadataFile.close();
        cout << endl;
    }
    else
    {
        cout << "FAIL : Metadata file not found" << endl;
        failCount++;
    }
    cout << endl;

    // -------- TEST SUMMARY --------
    // Display overall test results
    cout << "==== TEST SUMMARY ====" << endl;
    cout << "  Passed : " << passCount << endl;
    cout << "  Failed : " << failCount << endl;
    cout << "  Total  : " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of Date Test Cases ====" << endl;

    return 0;
}
