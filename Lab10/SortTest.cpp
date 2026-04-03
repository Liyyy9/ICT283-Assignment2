// ===============================================================
// SortTest.cpp
//       Comprehensive testing of Sort class
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "Sort.h"
#include "Date.h"
#include "Utilities.h"
#include "WeatherRecord.h"
#include "Date.h"
#include "Time.h"
#include "Vector.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations
bool IsSorted(Vector<WeatherRecord>& records, int low, int high);
void PrintRecords(Vector<WeatherRecord>& records);

// Helper function to check if vector is sorted
bool IsSorted(Vector<WeatherRecord>& records, int low, int high)
{
    for(int i = low; i < high; i++)
    {
        if(records[high] < records[i])
        {
            return false;
        }
    }
    return true;
}

// Helper function to print record's Dates
void PrintRecords(Vector<WeatherRecord>& records)
{
    for(int i = 0; i < records.Size(); i++)
    {
        cout << "Record " << i+1 << ": " << records[i].GetDate() << "\n";
    }
}
// single element, two elements unsorted, multiple unsorted, already sorted, reverse sorted
int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running Sort Test Cases ====" << endl << endl;

    Sort sorter;
    Vector<WeatherRecord> records;

    // -------- TEST 1: Single element --------
    cout << "--- Test 1 (Single Element) ---" << endl;

    WeatherRecord record1(Date(4,4,2026),Time(12,10),6,30,100);
    cout << "--- Records ---\n";
    records.Add(record1);
    PrintRecords(records);

    sorter.ExecuteSort(0,0, records);

    AssertEqual("Single element sort", IsSorted(records,0,0), passCount, failCount);
    cout << endl;

    // -------- TEST 2: Two elements unsorted --------
    cout << "--- Test 2 (Two Unsorted Elements) ---" << endl;

    WeatherRecord record2(Date(10,3,2026),Time(9,53),7,28,104);
    records.Add(record2);

    PrintRecords(records);

    sorter.ExecuteSort(0,0, records);

    AssertEqual("Two unsorted element is now sorted", IsSorted(records,0,0), passCount, failCount);
    cout << endl;

    // -------- TEST 3: Multiple unsorted elements--------
    cout << "--- Test 3 (Multiple Unsorted Elements) ---" << endl;

    WeatherRecord record3(Date(10,3,2026),Time(2,30),7,28,104);
    WeatherRecord record4(Date(11,12,2024),Time(3,40),7,28,104);
    WeatherRecord record5(Date(15,5,2020),Time(7,18),7,28,104);

    records.Add(record3);
    records.Add(record4);
    records.Add(record5);

    PrintRecords(records);

    sorter.ExecuteSort(0,0, records);

    AssertEqual("Multiple unsorted element is now sorted", IsSorted(records,0,0), passCount, failCount);
    cout << endl;

    // -------- TEST 4: Multiple SORTED elements--------
    cout << "--- Test 4 (Multiple SORTED Elements) ---" << endl;
    records.Clear();

    WeatherRecord record6(Date(1,1,2026),Time(2,30),7,28,104);
    WeatherRecord record7(Date(2,2,2026),Time(3,40),7,28,104);
    WeatherRecord record8(Date(3,3,2026),Time(7,18),7,28,104);
    WeatherRecord record9(Date(4,4,2026),Time(3,40),7,28,104);
    WeatherRecord record10(Date(5,5,2026),Time(7,18),7,28,104);

    records.Add(record6);
    records.Add(record7);
    records.Add(record8);
    records.Add(record9);
    records.Add(record10);

    PrintRecords(records);

    sorter.ExecuteSort(0,0, records);

    AssertEqual("Multiple SORTED element is now sorted", IsSorted(records,0,0), passCount, failCount);
    cout << endl;

    // -------- TEST 5: Multiple SORTED elements--------
    cout << "--- Test 5 (Multiple Reverse SORTED Elements) ---" << endl;
    records.Clear();

    WeatherRecord record11(Date(5,5,2026),Time(7,18),7,28,104);
    WeatherRecord record12(Date(4,4,2026),Time(3,40),7,28,104);
    WeatherRecord record13(Date(3,3,2026),Time(7,18),7,28,104);
    WeatherRecord record14(Date(2,2,2026),Time(3,40),7,28,104);
    WeatherRecord record15(Date(1,1,2026),Time(2,30),7,28,104);

    records.Add(record11);
    records.Add(record12);
    records.Add(record13);
    records.Add(record14);
    records.Add(record15);

    PrintRecords(records);

    sorter.ExecuteSort(0,0, records);

    AssertEqual("Multiple SORTED element is now sorted", IsSorted(records,0,0), passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "      Total : " << (passCount + failCount) << endl << endl;

    cout << "==== End of Sort Test Cases ===" << endl;

    return 0;
}
