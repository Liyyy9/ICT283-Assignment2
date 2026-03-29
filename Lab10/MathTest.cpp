// ===============================================================
// MathTest.cpp
//      Comprehensive testing of Math class
//      Test Mean, SD, sPCC, and MAD calculations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 10
// ===============================================================

#include "Math.h"
#include "WeatherRecord.h"
#include "WeatherRecordCollection.h"
#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "Utilities.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

void PrintDate(const Date& d)
{
    cout << "Date: " << d << endl;
}

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;
    Math math;

    cout << "==== Running Math Test Cases ====" << endl
         << endl;

    // -------- TEST 1: CalculateMean --------
    cout << "--- Test 1 (CalculateMean - Basic Data) ---" << endl;
    Vector<double> v1;
    v1.Add(10.0);
    v1.Add(20.0);
    v1.Add(30.0);

    double mean1 = math.CalculateMean(v1);
    cout << "Single record with speed 2.0 m/s" << endl;
    cout << "Data: {10, 20, 30}, Calculated Mean: " << fixed << setprecision(2) << mean1 << endl;
    AssertEqual("Mean of 10, 20, 30 is 20.0", mean1 == 20.0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: CalculateMean - Empty Vector --------
    cout << "--- Test 2 (CalculateMean - Multiple Records) ---" << endl;
    Vector<double> emptyVec;
    double meanEmpty = math.CalculateMean(emptyVec);

    double mean2 = math.CalculateMean(emptyVec);
    AssertEqual("Mean of empty vector is 0.0", meanEmpty == 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 3: CalculateSD - Two Records --------
    // Verify standard deviation calculation with two records
    cout << "--- Test 3 (CalculateSD - Two Records) ---" << endl;
    Vector<double> v2;
    v2.Add(10.0);
    v2.Add(20.0);
    double mean3 = math.CalculateMean(v2);
    double sd3 = math.CalculateSD(v2, mean3);

    cout << "Data: {10, 20}, Calculated SD: " << sd3 << endl;
    AssertEqual("SD is approximately 7.07", (sd3 > 7.07 && sd3 < 7.08), passCount, failCount);
    cout << endl;

    // -------- TEST 4: CalculateSD - Single Record --------
    // Verify standard deviation with single record (should return 0.0)
    cout << "--- Test 4 (CalculateSD - Single Record) ---" << endl;
    Vector<double> v3;
    v3.Add(50.0);

    double sd4 = math.CalculateSD(v3, 50.0);
    cout << "Single record SD: " << fixed << setprecision(2) << sd4 << " km/h" << endl;
    AssertEqual("SD of single record is 0.0", sd4 == 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 5: sPCC - Perfect Positive Correlation --------
    // Verify sPCC returns ~1.0 for perfectly correlated data
    cout << "--- Test 5 (sPCC - Perfect Positive) ---" << endl;
    Vector<double> v4;
    Vector<double> v5;

    for(int i = 1; i <= 5; i++) {
        v4.Add(i);              // {1,2,3,4,5}
        v5.Add(i * 10);         // {10,20,30,40,50}
    }

    double result5 = math.CalculateSPCC(v4, v5);
    cout << "Calculated sPCC: " << fixed << setprecision(2) << result5 << endl;
    AssertEqual("Perfect positive correlation is 1.0", result5 > 0.99, passCount, failCount);
    cout << endl;

    // -------- TEST 6: sPCC - Perfect Negative Correlation --------
    // Verify sPCC returns ~-1.0 for inversely correlated data
    cout << "--- Test 6 (sPCC - Perfect Negative) ---" << endl;
    Vector<double> v6;
    for(int i = 1; i <= 5; i++) {
        v6.Add(static_cast<double>(60 - (i * 10))); // {50, 40, 30, 20, 10}
    }
    double result6 = math.CalculateSPCC(v4, v6);
    cout << "Calculated sPCC: " << fixed << setprecision(2) << result6 << endl;
    AssertEqual("Perfect negative correlation is -1.0", result6 < -0.99, passCount, failCount);
    cout << endl;

    // -------- TEST 7: sPCC - Size Mismatch --------
    // Verify sPCC handles vectors of different lengths (should return 0.0 or handle error)
    cout << "--- Test 7 (sPCC - Size Mismatch) ---" << endl;
    v6.Add(100.0);                                  // Make v6 size 6, v4 is size 5

    double result7 = math.CalculateSPCC(v4, v6);
    cout << "Result for mismatch: " << result7 << endl;
    AssertEqual("sPCC of mismatched sizes returns 0.0", result7 == 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 8: MAD - Mean Absolute Deviation --------
    // Verify MAD calculation: Mean of {10, 20, 30} is 20.
    // Abs: |10-20|=10, |20-20|=0, |30-20|=10. Mean of {10, 0, 10} = 6.67
    cout << "--- Test 8 (CalculateMAD) ---" << endl;
    Vector<double> vMAD;
    vMAD.Add(10.0);
    vMAD.Add(20.0);
    vMAD.Add(30.0);
    double resultMAD = math.CalculateMAD(vMAD);
    cout << "Data: {10, 20, 30}, Calculated MAD: " << fixed << setprecision(2) << resultMAD << endl;
    AssertEqual("MAD is approximately 6.67", (resultMAD > 6.66 && resultMAD < 6.67), passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "      Total : " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of Math Test Cases ===" << endl;

    return 0;
}
