// ===============================================================
// Utilities.h
//      Utilities file providing date/time formatting, validation
//      functions, input handling, and testing helpers
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 09
// ===============================================================

#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include <string>

#include "Date.h"
#include "Time.h"

using std::string;

/**
 * @file Utilities.h
 * @brief  Utility functions for date and time operations and validation
 *
 * Provides helper functions for working with dates, including month name conversion,
 * leap year checking, determining days in a month, and validating date values.\n
 * These utility functions are used by the Date class and other components to handle
 * date-related calculations and formatting.\n
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 15/02/2026 Liyana Afiqah, Initial Implementation (Copied from Lab 4)
 *
 * @version 02
 * @date 26/02/2026 Liyana Afiqah, Moved I/O operators into Utilities
 *
 * @version 03
 * @date 28/02/2026 Liyana Afiqah, Added ValidMonthInput function for month input validation
 */

/**
 * @brief  Converts numeric month to month name string
 *
 * Helper function that maps numeric month values (1-12) to their
 * corresponding month names (January, February, etc.).
 *
 * @param  monthNum - Month number (1-12)
 * @return string - Month name (e.g., "January", "December")
 */
string GetMonthName(int monthNum);

/**
 * @brief  Checks if a given year is a leap year
 *
 * Determines if the provided year is a leap year using the following rules:
 * - Years divisible by 400 are leap years
 * - Years divisible by 100 are NOT leap years
 * - Years divisible by 4 are leap years
 * - All other years are NOT leap years
 *
 * @param  year - Year value to check
 * @return bool - true if the year is a leap year, false otherwise
 */
bool IsLeapYear(int year);

/**
 * @brief  Returns the number of days in a given month
 *
 * Calculates the number of days in the specified month, taking leap years into account.
 * - January, March, May, July, August, October, December: 31 days
 * - April, June, September, November: 30 days
 * - February: 28 days (or 29 if leap year)
 *
 * @param  month - Month value (1-12)
 * @param  year - Year value (used to determine leap year for February)
 * @return int - Number of days in the specified month
 * @see IsLeapYear()
 */
int GetDaysInMonth(int month, int year);

/**
 * @brief  Validates if a date is valid
 *
 * Checks if the provided day, month, and year values form a valid date.
 * Validates that:
 * - Month is between 1 and 12
 * - Day is between 1 and the maximum days in that month
 * - Year is non-negative
 *
 * @param  day - Day of month to validate (1-31)
 * @param  month - Month value to validate (1-12)
 * @param  year - Year value to validate
 * @return bool - true if the date is valid, false otherwise
 * @see GetDaysInMonth()
 */
bool IsValidDate(int day, int month, int year);

/**
 * @brief  Validates if a time is valid
 *
 * Checks if the provided hour and minute values form a valid time.
 * Validates that:
 * - Hour is between 0 and 23
 * - Minutes is between 0 and 59
 *
 * @param  hour - Hour value to validate (0-23)
 * @param  mins - Minute value to validate (0-59)
 *
 * @return bool - true if the time is valid, false otherwise
 */
bool IsValidTime(int hour, int mins);

/**
 * @brief Validates if a month value is within valid range
 *
 * Checks if the provided month value is between 1 and 12 (inclusive).
 * Used to validate month input before accepting it from the user.
 *
 * @param month - Month value to validate (1-12)
 *
 * @return bool - true if month is valid (1-12), false otherwise
 */
bool IsValidMonth(int month);

/**
 * @brief Validates and retrieves user month input within range of 1-12
 *
 * Prompts user for integer input and validates it falls within
 * the range 1 to 12. Handles invalid input (non-numeric) and
 * out-of-range values with error messages and reprompts until valid
 * input is received.
 *
 * @param month - Month value entered by user (1-12)
 *
 * @return int - The validated user input value
 */
int ValidMonthInput(int month);

/**
 * @brief Helper function for unit testing - tracks pass/fail results
 *
 * Compares a test condition result and outputs pass or fail message.
 * Increments the appropriate counter (passCount or failCount) based on the result.
 * Used by test files to validate function behavior and track test statistics.
 *
 * @param testName - Description of the test being performed
 * @param condition - Boolean result of the assertion (true = pass, false = fail)
 * @param passCount - Reference to counter for passed tests (incremented if condition is true)
 * @param failCount - Reference to counter for failed tests (incremented if condition is false)
 *
 * @return void
 */
void AssertEqual(string testName, bool condition, int &passCount, int &failCount);
//---------------------------------------------------------------------------------

/**
 * @brief  Input stream operator for reading date from input
 *
 * Reads date in format DD/MM/YYYY from input stream.
 * Uses '/' as delimiter between date components.
 * Automatically converts string values to integers.
 *
 * @param  input - Input stream to read from
 * @param  date - Date object to store read values
 * @return istream& - Reference to input stream
 * @pre Input stream must contain valid date format (DD/MM/YYYY)
 * @post date object is populated with read values
 *
 * @see Date
 */
istream &operator>>(istream &input, Date &date);

/**
 * @brief  Output stream operator for displaying date
 *
 * Writes date in formatted form: DD MonthName YYYY (e.g., 30 December 2020)
 * Converts numeric month to month name for human-readable output.
 *
 * @param  os - Output stream to write to
 * @param  date - Date object to output
 * @return ostream& - Reference to output stream
 * @post Formatted date written to output stream
 *
 * @see Date
 */
ostream &operator<<(ostream &os, const Date &date);

/**
 * @brief Input stream operator - reads time from input stream
 *
 * Reads time in format: HH:MM (e.g. 14:30)
 * Uses DELIMITER ':' to separate hour and minute components.
 * Validates time input before setting; defaults to 12:30 if invalid.
 *
 * @param input Reference to the input stream
 * @param time Reference to the Time object to populate
 *
 * @return Reference to the input stream
 */
istream &operator>>(istream &input, Time &time);

/**
 * @brief Output stream operator - displays time in formatted form
 *
 * Displays time in formatted form: HH:MM (e.g. 14:30)
 * Ensures minutes are always displayed with two digits (leading zero if needed).
 *
 * @param os Reference to the output stream
 * @param time Reference to the Time object to display
 *
 * @return Reference to the output stream
 */
ostream &operator<<(ostream &os, const Time &time);

#endif // DATEUTILITIES_H_INCLUDED
