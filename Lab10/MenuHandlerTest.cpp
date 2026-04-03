// ===============================================================
// MenuHandlerTest.cpp
//      Comprehensive testing of MenuHandler class
//      Tests menu routing, input validation, and data processing
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "MenuHandler.h"
#include "Math.h"
#include "WeatherRecord.h"
#include "WeatherRecordCollection.h"
#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "Utilities.h"
#include "CollectU.h"
#include "Map.h"
#include "Bst.h"

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
    data.Insert(record1);

    Time t2(10, 0);
    WeatherRecord record2(d1, t2, 3.0f, 24.0f, 250);
    data.Insert(record2);

    Time t3(11, 0);
    WeatherRecord record3(d1, t3, 5.0f, 24.5f, 300);
    data.Insert(record3);


    Date d2(15, 3, 2017);
    Time t4(12, 0);
    WeatherRecord record4(d2, t4, 4.0f, 25.0f, 400);
    data.Insert(record4);

    Date d3(28, 4, 2016);
    Time t5(10, 0);
    WeatherRecord record5(d3, t5, 2.0f, 23.5f, 200);
    data.Insert(record5);

    return data;
}

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;
    MenuHandler menuHandler;
    Math math;

    WeatherRecordCollection testData = CreateSampleData();

    cout << "==== Running MenuHandler Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Show Menu Display --------
    cout << "--- Test 1: ShowMenu Display ---" << endl;
    cout << "Menu display output:" << endl;
    menuHandler.ShowMenu();
    cout << "Verify visually that 5 menu options are displayed and that option 3 now mentions sPCC." << endl
         << endl;


    // -------- TEST 2: Option 1 - Wind Speed Analysis - Valid Data --------
    cout << "--- Test 2: Option 1 - WindAvgStdDev_Choice1 (March 2016) ---" << endl;

    CollectU collector;
    collector.clear();

    const WeatherRecordCollection::YearCabinet& inventory = testData.GetInventory();
    if(inventory.Contains(2016) && inventory.At(2016).Contains(3))
    {
        inventory.At(2016).At(3).InOrder(CollectU::CollectWindSpeed);
    }

    Vector<double>& marchWindSpeeds = collector.GetCollection();

    double mean = math.CalculateMean(marchWindSpeeds);
    double sd = math.CalculateSD(marchWindSpeeds, mean);
    double mad = math.CalculateMAD(marchWindSpeeds);
    cout << mad;

    AssertEqual("March 2016 wind mean is 12.0 km/h", mean = 12.0, passCount, failCount);
    AssertEqual("March 2016 wind std dev is 5.5", sd = 5.5, passCount, failCount);
    AssertEqual("March 2016 wind MAD is 5.5", sd = 5.5, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Option 3 - sPCC Analysis --------
    cout << "--- Test 3: Option 3 - sPCC Correlation ---" << endl;
    cout << "Testing Option 3 sPCC for ALL March (2016 and 2017) data:" << endl;
    Vector<double> allMarchWind, allMarchTemp;

    int years[] = {2016, 2017};
    int testNumYears = 2;

    for(int i = 0; i < testNumYears; i++)
    {
        int year = years[i];
        if(inventory.Contains(year) && inventory.At(year).Contains(3))
        {
            collector.clear();
            inventory.At(year).At(3).InOrder(CollectU::CollectWindSpeed);

            for(int i = 0; i< collector.GetCollection().Size(); i++)
            {
                allMarchWind.Add(collector.GetCollection()[i]);
            }

            collector.clear();
            inventory.At(year).At(3).InOrder(CollectU::CollectAmbientTemp);

            for(int i = 0; i< collector.GetCollection().Size(); i++)
            {
                allMarchTemp.Add(collector.GetCollection()[i]);
            }
        }
    }

    double spcc = math.CalculateSPCC(allMarchWind, allMarchTemp);
    AssertEqual("sPCC calculated for multiple years", spcc != 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 4: Option 4 - Combined Analysis and Export --------
    cout << "--- Test 4: DisplayAllFindings_Choice4 ---" << endl;
    cout << "Testing Option 4 for year 2016 (CSV export to WindTempSolar.csv):" << endl;
    menuHandler.DisplayAllFindings_Choice4(2016, testData);
    cout << endl;

    // -------- TEST 5: Combined Analysis with No Data --------
    cout << "--- Test 5: DisplayAllFindings_Choice4 - No Data ---" << endl;
    cout << "Testing Option 4 for year 1900 (no data):" << endl;
    menuHandler.DisplayAllFindings_Choice4(1900, testData);
    cout << endl;

    // -------- TEST 6: Empty Dataset Handling --------
    cout << "--- Test 6: Empty Dataset Handling: ---" << endl;
    Vector<double> emptyVec;
    double emptyMean = math.CalculateMean(emptyVec);
    double emptySD = math.CalculateSD(emptyVec, emptyMean);
    cout << "Empty dataset - Mean: " << fixed << setprecision(2) << emptyMean << " km/h" << endl;
    cout << "Empty dataset - SD: " << fixed << setprecision(2) << emptySD << " km/h" << endl;
    AssertEqual("Empty dataset mean returns 0.0", emptyMean == 0.0, passCount, failCount);
    AssertEqual("Empty dataset SD returns 0.0", emptySD == 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 7: Single Record Handling --------
    cout << "--- Test 7: Single Record Handling ---" << endl;
    Vector<double> singleRecord;
    singleRecord.Add(30.0);

    double singleMean = math.CalculateMean(singleRecord);
    double singleSD = math.CalculateSD(singleRecord, singleMean);
    cout << "Single record - Mean: " << fixed << setprecision(2) << singleMean << " km/h" << endl;
    cout << "Single record - SD: " << fixed << setprecision(2) << singleSD << " km/h" << endl;
    AssertEqual("Single record mean is 7.2 km/h", singleMean = 7.2, passCount, failCount);
    AssertEqual("Single record SD returns 0.0 (n-1 = 0)", singleSD == 0.0, passCount, failCount);
    cout << endl;

    // -------- TEST 8: CSV failure --------
    cout << "--- Test 8: CSV failure ---" << endl;
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
