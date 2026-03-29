// ===============================================================
// WeatherRecordTest.cpp
//      Comprehensive testing of WeatherRecord class
//      Test constructors, getters, setters, and unit conversion
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 1
// ===============================================================

#include "WeatherRecord.h"
#include "Date.h"
#include "Time.h"
#include "Utilities.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running WeatherRecord Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Default Constructor --------
    // Verify that default constructor initialises all fields to default values
    cout << "--- Test 1 (Default Constructor) ---" << endl;
    WeatherRecord record1;
    cout << "Constructed Default WeatherRecord object: record1" << endl
         << endl;

    AssertEqual("Default wind speed is 0.0", record1.GetSpeed() == 0.0f, passCount, failCount);
    AssertEqual("Default ambient temperature is 0.0", record1.GetAmbTemp() == 0.0f, passCount, failCount);
    AssertEqual("Default solar radiation is 0", record1.GetSolarRad() == 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Parameterised Constructor --------
    // Verify that parameterised constructor correctly initialises all fields
    cout << "--- Test 2 (Parameterised Constructor) ---" << endl;
    Date myDate(15, 6, 2016);
    Time myTime(14, 30);
    WeatherRecord record2(myDate, myTime, 5.5f, 28.3f, 650);
    cout << "Constructed Parameterised WeatherRecord object: record2" << endl
         << endl;

    AssertEqual("Speed is 5.5 m/s", record2.GetSpeed() == 5.5f, passCount, failCount);
    AssertEqual("Ambient temperature is 28.3", record2.GetAmbTemp() == 28.3f, passCount, failCount);
    AssertEqual("Solar radiation is 650", record2.GetSolarRad() == 650, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Date Getter and Setter --------
    // Verify that date getter and setter work correctly
    cout << "--- Test 3 (Date Getter and Setter) ---" << endl;
    Date retrievedDate = record2.GetDate();
    cout << "Original Date: " << retrievedDate << endl;
    AssertEqual("GetDate returns correct date day", retrievedDate.GetDay() == 15, passCount, failCount);
    AssertEqual("GetDate returns correct date month", retrievedDate.GetMonth() == 6, passCount, failCount);
    AssertEqual("GetDate returns correct date year", retrievedDate.GetYear() == 2016, passCount, failCount);

    Date newDate(25, 12, 2017);
    record2.SetDate(newDate);
    Date retrievedNewDate = record2.GetDate();
    AssertEqual("SetDate updates date correctly (day)", retrievedNewDate.GetDay() == 25, passCount, failCount);
    AssertEqual("SetDate updates date correctly (month)", retrievedNewDate.GetMonth() == 12, passCount, failCount);
    AssertEqual("SetDate updates date correctly (year)", retrievedNewDate.GetYear() == 2017, passCount, failCount);
    cout << endl;

    // -------- TEST 4: Time Getter and Setter --------
    // Verify that time getter and setter work correctly
    cout << "--- Test 4 (Time Getter and Setter) ---" << endl;
    Time retrievedTime = record2.GetTime();
    AssertEqual("GetTime returns correct hour", retrievedTime.GetHour() == 14, passCount, failCount);
    AssertEqual("GetTime returns correct minute", retrievedTime.GetMins() == 30, passCount, failCount);

    Time newTime(18, 45);
    record2.SetTime(newTime);
    Time retrievedNewTime = record2.GetTime();
    AssertEqual("SetTime updates hour correctly", retrievedNewTime.GetHour() == 18, passCount, failCount);
    AssertEqual("SetTime updates minute correctly", retrievedNewTime.GetMins() == 45, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Speed Getter and Setter (m/s) --------
    // Verify that wind speed getter and setter work in m/s
    cout << "--- Test 5 (Speed Getter and Setter - m/s) ---" << endl;
    float retrievedSpeed = record2.GetSpeed();
    cout << "Current speed: " << fixed << setprecision(2) << retrievedSpeed << " m/s" << endl;
    AssertEqual("GetSpeed returns correct value 5.5 m/s", retrievedSpeed == 5.5f, passCount, failCount);

    record2.SetSpeed(8.3f);
    float newSpeed = record2.GetSpeed();
    cout << "After SetSpeed(8.3): " << fixed << setprecision(2) << newSpeed << " m/s" << endl;
    AssertEqual("SetSpeed updates speed correctly to 8.3 m/s", newSpeed == 8.3f, passCount, failCount);
    cout << endl;

    // -------- TEST 6: Speed Unit Conversion (m/s to km/h) --------
    // Verify that speed conversion from m/s to km/h is correct (multiply by 3.6)
    cout << "--- Test 6 (Speed Unit Conversion - m/s to km/h) ---" << endl;
    WeatherRecord record3(myDate, myTime, 2.5f, 25.0f, 500);
    float speedMs = record3.GetSpeed();
    float speedKmH = record3.GetSpeedKmH();
    float expectedKmH = 2.5f * 3.6f; // 9.0 km/h
    cout << "Speed: " << fixed << setprecision(2) << speedMs << " m/s" << endl;
    cout << "Converted to km/h: " << fixed << setprecision(2) << speedKmH << " km/h" << endl;
    cout << "Expected: " << fixed << setprecision(2) << expectedKmH << " km/h" << endl;
    AssertEqual("2.5 m/s converts to 9.0 km/h", speedKmH = 9.0, passCount, failCount);
    cout << endl;

    // -------- TEST 7: Ambient Temperature Getter and Setter --------
    // Verify that ambient temperature getter and setter work correctly
    cout << "--- Test 7 (Ambient Temperature Getter and Setter) ---" << endl;
    float retrievedTemp = record2.GetAmbTemp();
    cout << "Current ambient temperature: " << fixed << setprecision(1) << retrievedTemp << endl;
    AssertEqual("GetAmbTemp returns correct value 28.3", record2.GetAmbTemp() == 28.3f, passCount, failCount);

    record2.SetAmbTemp(32.5f);
    float newTemp = record2.GetAmbTemp();
    cout << "After SetAmbTemp(32.5): " << fixed << setprecision(1) << newTemp << endl;
    AssertEqual("SetAmbTemp updates temperature correctly to 32.5", newTemp == 32.5f, passCount, failCount);
    cout << endl;

    // -------- TEST 8: Solar Radiation Getter and Setter --------
    // Verify that solar radiation getter and setter work correctly
    cout << "--- Test 8 (Solar Radiation Getter and Setter) ---" << endl;
    int retrievedRad = record2.GetSolarRad();
    cout << "Current solar radiation: " << retrievedRad << endl;
    AssertEqual("GetSolarRad returns correct value 650", retrievedRad == 650, passCount, failCount);

    record2.SetSolarRad(750);
    int newRad = record2.GetSolarRad();
    cout << "After SetSolarRad(750): " << newRad << endl;
    AssertEqual("SetSolarRad updates radiation correctly to 750", newRad == 750, passCount, failCount);
    cout << endl;

    // -------- TEST 9: Zero Values --------
    // Verify handling of zero values for speed and temperatures
    cout << "--- Test 9 (Zero Values) ---" << endl;
    WeatherRecord record5(myDate, myTime, 0.0f, 0.0f, 0);
    AssertEqual("Zero speed m/s returns 0.0", record5.GetSpeed() == 0.0f, passCount, failCount);
    AssertEqual("Zero speed converts to 0.0 km/h", record5.GetSpeedKmH() == 0.0f, passCount, failCount);
    AssertEqual("Zero ambient temperature returns 0.0", record5.GetAmbTemp() == 0.0f, passCount, failCount);
    AssertEqual("Zero solar radiation returns 0", record5.GetSolarRad() == 0, passCount, failCount);
    cout << endl;

    // -------- TEST 10: Negative Values --------
    // Verify handling of negative values (valid for temperature)
    cout << "--- Test 10 (Negative Values) ---" << endl;
    WeatherRecord record6(myDate, myTime, 3.0f, -5.2f, 100);
    AssertEqual("Negative ambient temperature handled correctly", record6.GetAmbTemp() == -5.2f, passCount, failCount);
    record6.SetAmbTemp(-15.0f);
    AssertEqual("SetAmbTemp with negative value works", record6.GetAmbTemp() == -15.0f, passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ====" << endl;
    cout << "Total Passed: " << passCount << endl;
    cout << "Total Failed: " << failCount << endl;
    cout << "       Total: " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of WeatherRecord Test Cases ====" << endl;

    return 0;
}
