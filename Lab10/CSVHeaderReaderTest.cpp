// ===============================================================
// CSVHeaderReaderTest.cpp
//      Comprehensive testing of CSVHeaderReader class
//      Test header reading and column index identification
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 1
// ===============================================================

#include "CSVHeaderReader.h"
#include "Utilities.h"

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ofstream;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running CSVHeaderReader Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Valid CSV Header with All Required Columns --------
    // Verify reading a valid CSV header with WAST, S, T, and SR columns
    cout << "--- Test 1 (Valid CSV Header with All Required Columns) ---" << endl;

    ofstream testFile1("CSVheader_testfile1.csv");
    testFile1 << "WAST,S,T,SR" << endl;
    testFile1.close();

    CSVHeaderReader reader1;
    int dateTimeIdx1 = -1, speedIdx1 = -1, tempIdx1 = -1, radIdx1 = -1;
    ifstream infile1("CSVheader_testfile1.csv");
    bool result1 = reader1.ReadHeader(infile1, dateTimeIdx1, speedIdx1, tempIdx1, radIdx1);
    infile1.close();

    cout << "Testing header: WAST,S,T,SR" << endl;
    cout << "Result: " << (result1 ? "true" : "false") << endl;
    cout << "WAST index: " << dateTimeIdx1 << ", S index: " << speedIdx1 << ", T index: " << tempIdx1 << ", SR index: " << radIdx1 << endl;
    AssertEqual("ReadHeader returns true for valid header", result1 == true, passCount, failCount);
    AssertEqual("WAST column found at index 0", dateTimeIdx1 == 0, passCount, failCount);
    AssertEqual("S column found at index 1", speedIdx1 == 1, passCount, failCount);
    AssertEqual("T column found at index 2", tempIdx1 == 2, passCount, failCount);
    AssertEqual("SR column found at index 3", radIdx1 == 3, passCount, failCount);
    cout << endl;

    // -------- TEST 2: CSV Header with Columns in Different Order --------
    // Verify correct column index identification regardless of order
    cout << "--- Test 2 (CSV Header with Columns in Different Order) ---" << endl;
    ofstream testFile2("CSVheader_testfile2.csv");
    testFile2 << "S,WAST,SR,T" << endl;
    testFile2.close();

    CSVHeaderReader reader2;
    int dateTimeIdx2 = -1, speedIdx2 = -1, tempIdx2 = -1, radIdx2 = -1;
    ifstream infile2("CSVheader_testfile2.csv");
    bool result2 = reader2.ReadHeader(infile2, dateTimeIdx2, speedIdx2, tempIdx2, radIdx2);
    infile2.close();

    cout << "Testing header: S,WAST,SR,T" << endl;
    cout << "Result: " << (result2 ? "true" : "false") << endl;
    cout << "WAST index: " << dateTimeIdx2 << ", S index: " << speedIdx2 << ", T index: " << tempIdx2 << ", SR index: " << radIdx2 << endl;
    AssertEqual("ReadHeader returns true for reordered columns", result2 == true, passCount, failCount);
    AssertEqual("WAST column found at index 1", dateTimeIdx2 == 1, passCount, failCount);
    AssertEqual("S column found at index 0", speedIdx2 == 0, passCount, failCount);
    AssertEqual("SR column found at index 2", radIdx2 == 2, passCount, failCount);
    AssertEqual("T column found at index 3", tempIdx2 == 3, passCount, failCount);
    cout << endl;

    // -------- TEST 3: CSV Header with Extra Columns --------
    // Verify correct identification of required columns with extra columns present
    cout << "--- Test 3 (CSV Header with Extra Columns) ---" << endl;
    ofstream testFile3("CSVheader_testfile3.csv");
    testFile3 << "WAST,ExtraCol1,S,ExtraCol2,T,SR,ExtraCol3" << endl;
    testFile3.close();

    CSVHeaderReader reader3;
    int dateTimeIdx3 = -1, speedIdx3 = -1, tempIdx3 = -1, radIdx3 = -1;
    ifstream infile3("CSVheader_testfile3.csv");
    bool result3 = reader3.ReadHeader(infile3, dateTimeIdx3, speedIdx3, tempIdx3, radIdx3);
    infile3.close();

    cout << "Testing header: WAST,ExtraCol1,S,ExtraCol2,T,SR,ExtraCol3" << endl;
    cout << "Result: " << (result3 ? "true" : "false") << endl;
    AssertEqual("ReadHeader returns true with extra columns", result3 == true, passCount, failCount);
    AssertEqual("WAST found at correct index", dateTimeIdx3 == 0, passCount, failCount);
    AssertEqual("S found at correct index", speedIdx3 == 2, passCount, failCount);
    AssertEqual("T found at correct index", tempIdx3 == 4, passCount, failCount);
    AssertEqual("SR found at correct index", radIdx3 == 5, passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ===" << endl;
    cout << "Total Passed : " << passCount << endl;
    cout << "Total Failed : " << failCount << endl;
    cout << "       Total : " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of CSVHeaderReader Test Cases ====" << endl;

    return 0;
}
