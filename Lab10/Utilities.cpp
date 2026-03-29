// ===============================================================
// Utilities.cpp
//      Utilities implementation file providing date/time formatting,
//      validation functions, input handling, and testing helpers
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 09
// ===============================================================
#include "Utilities.h"
#include "Constants.h"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// Helper Function: Converts numeric month (1-12) to a month name
// Returns month name as a string (e.g. 1 -> "January"
string GetMonthName(int monthNum)
{
    string monthNames[12] = {"January", "February", "March", "April",
                             "May", "June", "July", "August", "September",
                             "October", "November", "December"};

    return monthNames[monthNum - 1];
}

// Helper Function: Checks if a given year is a leap year
// A leap year is divisible by 400, OR divisible by 4 but NOT by 100
// Returns true if leap year, false otherwise
bool IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Helper Function: Returns the number of days in a given month
// Accounts for leap years when calculating February days
// January, March, May, July, August, October, December: 31 days
// April, June, September, November: 30 days
// February: 28 days (or 29 if leap year)
int GetDaysInMonth(int month, int year)
{
    if (month == 2)
    {
        if (IsLeapYear(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }

    return 31;
}

// Helper Function: Validates if a date is valid
// Checks if month is 1-12, day is within valid range for that month, and year is non-negative
// Returns true if date is valid, false otherwise
bool IsValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > GetDaysInMonth(month, year))
        return false;
    if (year < 0)
        return false;

    return true;
}

// Helper Function: Validates if a time is valid
// Checks if hour is 0-23 and minutes is 0-59
// Returns true if time is valid, false otherwise
bool IsValidTime(int hour, int mins)
{
    if (hour < 0 || hour > 23)
        return false;
    if (mins < 0 || mins > 59)
        return false;

    return true;
}

// Helper Function: Validates if a month is valid
// Checks if month is between 1 and 12
// Returns true if month is valid, false otherwise
bool IsValidMonth(int month)
{
    return (month >= 1 && month <= 12);
}
// Validates and retrieves integer input within specified range
// Prompts user for month input and validates it falls within 1-12
// Handles invalid input (non-numeric) and out-of-range values
// Reprompts user until valid input is received
int ValidMonthInput(int month)
{
    bool validInput = false;

    while (!validInput)
    {
        cout << "Enter month (1 - 12): ";

        // Check if input parsing failed (non-numeric input)
        if (!(cin >> month))
        {
            cout << "Invalid input. Please enter a numeric value.\n"
                 << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Check if value is within acceptable range
        if (!IsValidMonth(month))
        {
            cout << "Invalid input. Please enter a number between 1 and 12\n"
                 << endl;
            continue;
        }

        validInput = true;
    }

    return month;
}

// Helper Function for testing - tracks pass/fail results
// Compares a test condition result and outputs pass or fail message.
// Increments the appropriate counter (passCount or failCount) based on the result.
void AssertEqual(string testName, bool condition, int &passCount, int &failCount)
{
    if (condition)
    {
        cout << "  PASS : " << testName << endl;
        passCount++;
    }
    else
    {
        cout << "  FAIL : " << testName << endl;
        failCount++;
    }
}

// Input Stream Operator
// Reads date in format: DD/MM/YYYY (e.g. 22/12/1997)
// Uses DELIMETER '/' to separate components and tempStr to hold each value
istream &operator>>(istream &input, Date &date)
{
    input >> std::ws;

    string tempStr;
    int day, month, year;

    getline(input, tempStr, SLASH_DELIMITER); // day

    if (tempStr.empty())
    return input;

    day = stoi(tempStr);

    getline(input, tempStr, SLASH_DELIMITER); //month
    month = stoi(tempStr);

    getline(input, tempStr, ' '); // year
    year = stoi(tempStr);

    // Validate date input before setting
    if (IsValidDate(day, month, year))
    {
        date.SetDay(day);
        date.SetMonth(month);
        date.SetYear(year);
    }
    else
    {
        date.SetDay(1);
        date.SetMonth(1);
        date.SetYear(1800);
    }

    // Display formatted data for verification
    string monthNumToName = GetMonthName(date.GetMonth());

    return input;
}

// Output Stream Operator
// Displays data in formatted form: DD MonthName YYYY (e.g. 22 December 1997)
// Converts numeric month to month name for output
ostream &operator<<(ostream &os, const Date &date)
{
    string monthNumToName = GetMonthName(date.GetMonth());

    os << date.GetDay() << " " << monthNumToName << " " << date.GetYear();

    return os;
}

// Input Stream Operator
// Reads time in format: HH:MM (e.g. 14:30)
// Uses DELIMITER ':' to separate hour and minute components
istream &operator>>(istream &input, Time &time)
{
    input >> std::ws;

    string tempStr;
    int hour, mins;

    getline(input, tempStr, COLON_DELIMITER);
    hour = stoi(tempStr);

    getline(input, tempStr);
    mins = stoi(tempStr);

    if (IsValidTime(hour, mins))
    {
        time.SetHour(hour);
        time.SetMins(mins);
    }
    else
    {
        time.SetHour(12);
        time.SetMins(30);
    }

    return input;
}

// Output Stream Operator
// Displays time in formatted form: HH:MM (e.g. 14:30)
// Ensures minutes are always displayed with two digits (leading zero if needed)
ostream &operator<<(ostream &os, const Time &time)
{
    os << time.GetHour() << ":";

    if (time.GetMins() < 10)
    {
        os << "0";
    }
    os << time.GetMins();

    return os;
}
