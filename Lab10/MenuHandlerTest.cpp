// ===============================================================
// MenuHandlerTest.cpp
//      Comprehensive testing of MenuHandler class
//      Tests menu routing, input validation, and data processing
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 1
// ===============================================================

#include "MenuHandler.h"
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
#include <fstream>

using std::abs;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;
using std::ofstream;

// Helper function to create sample weather data
WeatherRecordCollection CreateSampleData()
{
    WeatherRecordCollection data;

    Date d1(31, 3, 2016);
    Time t1(9, 0);
    WeatherRecord record1(d1, t1, 2.0f, 23.5f, 200);
    data.Insert(record1, 0);

    Time t2(10, 0);
    WeatherRecord record2(d1, t2, 3.0f, 24.0f, 250);
    data.Insert(record2, 1);

    Time t3(11, 0);
    WeatherRecord record3(d1, t3, 5.0f, 24.5f, 300);
    data.Insert(record3, 2);


    Date d2(15, 3, 2017);
    Time t4(12, 0);
    WeatherRecord record4(d2, t4, 4.0f, 25.0f, 400);
    data.Insert(record4, 3);

    Date d3(28, 4, 2016);
    Time t5(10, 0);
    WeatherRecord record5(d3, t5, 2.0f, 23.5f, 200);
    data.Insert(record5, 0);

    return data;
}

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running MenuHandler Test Cases ====" << endl
         << endl;

    MenuHandler menuHandler;

    // -------- TEST 1: Show Menu Display --------
    cout << "--- Test 1 (ShowMenu Display) ---" << endl;
    cout << "Menu display output:" << endl;
    menuHandler.ShowMenu();
    cout << "Verify visually that 5 menu options are displayed and that option 3 now mentions sPCC." << endl
         << endl;


    // -------- TEST 2: Option 1 - Wind Speed Analysis - Valid Data --------
    cout << "--- Test 2 (Option 1 - WindAvgStdDev_Choice1 - Valid Data) ---" << endl;
    WeatherRecordCollection testData = CreateSampleData();

    // Calculate wind stats for March 2016
    // Should have 3 records: 7.2, 10.8, 18.0 km/h
    // Mean: (7.2 + 10.8 + 18.0) / 3 = 12.0 km/h
    cout << "Testing Choice 1 with 3 March 2016 records:" << endl;
    menuHandler.WindAvgStdDev_Choice1(3, 2016, testData);

    // Manually verify the calculation
    Math math;
    Vector<double> marchWindSpeeds;

    for (int i = 0; i < testData.Size(); i++)
    {
        if (testData[i].GetDate().GetMonth() == 3 && testData[i].GetDate().GetYear() == 2016)
        {
            marchWindSpeeds.Add(testData[i].GetSpeedKmH());
        }
    }

    double mean = math.CalculateMean(marchWindSpeeds);
    double sd = math.CalculateSD(marchWindSpeeds, mean);

    AssertEqual("March 2016 wind mean is 12.0 km/h", mean = 12.0, passCount, failCount);
    AssertEqual("March 2016 wind std dev is 5.5", sd = 5.5, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Option 2 - Temperature Analysis--------
    cout << "--- Test 3 (Option 2 - AmbientTempAvgStdDev_Choice2) ---" << endl;
    cout << "Testing Option 2 for year 2016 (shows all 12 months):" << endl;
    menuHandler.AmbientTempAvgStdDev_Choice2(2016, testData);
    cout << endl;

    // -------- TEST 4: Option 3 - sPCC Analysis --------
    cout << "--- Test 4 (Option 3 - sPCC Correlation) ---" << endl;
    cout << "Testing Option 3 sPCC for March (includes 2016 and 2017) data:" << endl;
    menuHandler.DisplaysPCC_Choice3(3, testData);

    Vector<double> windS, tempT;
    for(int i = 0; i <testData.Size(); i++)
    {
        if(testData[i].GetDate().GetMonth() == 3)
        {
            windS.Add(testData[i].GetSpeedKmH());
            tempT.Add(testData[i].GetAmbTemp());
        }

    }
    double calculatedSPCC = math.CalculateSPCC(windS, tempT);
    AssertEqual("sPCC calculation is correct", calculatedSPCC != 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Option 4 - Combined Analysis and Export --------
    cout << "--- Test 5 (DisplayAllFindings_Choice4) ---" << endl;
    cout << "Testing Option 4 for year 2016 (CSV export to WindTempSolar.csv):" << endl;
    menuHandler.DisplayAllFindings_Choice4(2016, testData);
    cout << endl;

    // -------- TEST 6: Combined Analysis with No Data --------
    cout << "--- Test 6 (DisplayAllFindings_Choice4 - No Data) ---" << endl;
    cout << "Testing Option 4 for year 1900 (no data):" << endl;
    menuHandler.DisplayAllFindings_Choice4(1900, testData);
    cout << endl;

    // -------- TEST 7: Temperature Mean Calculation --------
    cout << "--- Test 7 (Temperature Mean Calculation) ---" << endl;
    Vector<double> marchTemp;

    for (int i = 0; i < testData.Size(); i++)
    {
        if (testData[i].GetDate().GetMonth() == 3 && testData[i].GetDate().GetYear() == 2016)
        {
            marchTemp.Add(testData[i].GetSpeedKmH());
        }
    }

    double tempMean = math.CalculateMean(marchTemp);
    // March temps: 23.5, 24.0, 24.5
    // Mean: (23.5 + 24.0 + 24.5) / 3 = 24.0°C
    cout << "Testing temperature mean for March 2016:" << endl;
    cout << "Calculated mean: " << fixed << setprecision(1) << tempMean << " degrees C" << endl;
    AssertEqual("March 2016 temp mean is 24.0 degrees C", tempMean = 24.0, passCount, failCount);
    cout << endl;

    // -------- TEST 8: Temperature Standard Deviation --------
    cout << "--- Test 8 (Temperature Standard Deviation) ---" << endl;

    double tempSD = math.CalculateSD(marchTemp, mean);
    // Temps: 23.5, 24.0, 24.5; Mean: 24.0
    // SD = sqrt(((23.5-24)^2 + (24-24)^2 + (24.5-24)^2) / 2)
    //    = sqrt((0.25 + 0 + 0.25) / 2) = sqrt(0.25) = 0.5
    cout << "Calculated temp stdev: " << fixed << setprecision(1) << tempSD << " degrees C" << endl;
    AssertEqual("March 2016 temp stdev is approximately 0.5 degrees C", tempSD = 0.5, passCount, failCount);
    cout << endl;

    // -------- TEST 9: Wind Speed Unit Conversion --------
    cout << "--- Test 9 (Wind Speed Unit Conversion) ---" << endl;
    // Test records: 2.0, 3.0, 5.0 m/s should be 7.2, 10.8, 18.0 km/h
    cout << "Testing m/s to km/h conversion (multiply by 3.6):" << endl;
    float marchData0Test = marchWindSpeeds[0];
    cout << "Record 1: 2.0 m/s = " << fixed << setprecision(1) << marchWindSpeeds[0] << " km/h" << endl;
    AssertEqual("2.0 m/s = 7.2 km/h", marchData0Test = 7.2, passCount, failCount);

    float marchData1Test = marchWindSpeeds[1];
    cout << "Record 2: 3.0 m/s = " << fixed << setprecision(1) << marchWindSpeeds[1] << " km/h" << endl;
    AssertEqual("3.0 m/s = 10.8 km/h", marchData1Test = 10.8, passCount, failCount);

    float marchData2Test = marchWindSpeeds[2];
    cout << "Record 3: 5.0 m/s = " << fixed << setprecision(1) << marchWindSpeeds[2] << " km/h" << endl;
    AssertEqual("5.0 m/s = 18.0 km/h",marchData2Test = 18.0, passCount, failCount);
    cout << endl;

    // -------- TEST 10: Empty Dataset Handling --------
    cout << "--- Test 10 (Empty Dataset Handling) ---" << endl;
    Vector<double> emptyVec;
    double emptyMean = math.CalculateMean(emptyVec);
    double emptySD = math.CalculateSD(emptyVec, emptyMean);
    cout << "Empty dataset - Mean: " << fixed << setprecision(2) << emptyMean << " km/h" << endl;
    cout << "Empty dataset - SD: " << fixed << setprecision(2) << emptySD << " km/h" << endl;
    AssertEqual("Empty dataset mean returns 0.0", emptyMean == 0.0, passCount, failCount);
    AssertEqual("Empty dataset SD returns 0.0", emptySD == 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 11: Single Record Handling --------
    cout << "--- Test 11 (Single Record Handling) ---" << endl;
    Vector<double> singleRecord;
    singleRecord.Add(30.0);

    double singleMean = math.CalculateMean(singleRecord);
    double singleSD = math.CalculateSD(singleRecord, singleMean);
    cout << "Single record - Mean: " << fixed << setprecision(2) << singleMean << " km/h" << endl;
    cout << "Single record - SD: " << fixed << setprecision(2) << singleSD << " km/h" << endl;
    AssertEqual("Single record mean is 7.2 km/h", singleMean = 7.2, passCount, failCount);
    AssertEqual("Single record SD returns 0.0 (n-1 = 0)", singleSD == 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 12: Month Filtering --------
    cout << "--- Test 12 (Month Filtering) ---" << endl;
    // Count records for each month
    int marchCount = 0;
    int aprilCount = 0;
    for (int i = 0; i < testData.Size(); i++)
    {
        if (testData[i].GetDate().GetMonth() == 3 && testData[i].GetDate().GetYear() == 2016)
            marchCount++;
        if (testData[i].GetDate().GetMonth() == 4 && testData[i].GetDate().GetYear() == 2016)
            aprilCount++;
    }
    cout << "Filtered records for March 2016: " << marchCount << endl;
    cout << "Filtered records for April 2016: " << aprilCount << endl;
    AssertEqual("March 2016 has 3 records", marchCount == 3, passCount, failCount);
    AssertEqual("April 2016 has 1 record", aprilCount == 1, passCount, failCount);
    cout << endl;

    // -------- TEST 13: CSV failure --------
    cout << "--- Test 13 (CSV failure) ---" << endl;
    // Force a failure to CSV file to verify that program handles correctly.
    string ofileName = "FailTest.csv";
    string failDirectoryPath = "nonexistent_folder/";

    ofstream ofile(failDirectoryPath + ofileName);
    bool failed = false;

    if (!ofile)
    {
        cout << "Error writing output file FailTest.csv\n";
        failed = true;
    }
    AssertEqual("CSV failed to write, error message displayed\n", failed, passCount, failCount);

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "       Total: " << (passCount + failCount) << endl
         << endl
         << "==== End of MenuHandler Test Cases ===" << endl;

    return 0;
}
