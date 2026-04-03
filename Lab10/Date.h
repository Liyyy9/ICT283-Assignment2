// ===============================================================
// Date.h
//      Manages date information with day, month, and year values
//      Provides conversion to month names and formatted I/O
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include "Time.h"

using std::string;
using std::istream;
using std::ostream;

//---------------------------------------------------------------------------------
    /**
     * @class Date
     * @brief Manages date information with day, month, and year values
     *
     * Stores a date as three separate integer values (day, month, year).
     * Dates are read from input streams in the format DD/MM/YYYY.
     * Dates are output in the format: DD MonthName YYYY.
     * Converts numeric month values (1-12) to month names.
     * Validates date input, checks days in month, and leap year
     *
     * @author Liyana Afiqah Binte Jazmi
     * @version 01
     * @date 15/02/2026 Liyana Afiqah, Initial Implementation (Copied from Lab 4)
     *
     * @version 02
     * @date 26/02/2026 Liyana Afiqah, Moved I/O operators into Utilities
     *
     * @version 03
     * @date 13/03/2026 Liyana Afiqah, Included comparison assignments
     */

class Date
{
public:

    /**
     * @brief Default constructor - initialises date to 1/1/1800
     *
     * Creates a Date object with default values
     * Day = 1, Month = 1, Year = 1800
     *
     * @return void
     */
    Date();

    /**
     * @brief  Parameterised constructor - initialises date with provided values
     *
     * Creates a Date object with specified day, month, and year.
     *
     * @param  day - Day of month (1-31)
     * @param  month - Month value (1-12)
     * @param  year - Year value (e.g., 2020)
     * @return void
     */
    Date( int day, int month, int year);

    /**
     * @brief  Returns the day value
     *
     * @return int - Day of month
     */
    int GetDay() const;

    /**
     * @brief  Sets the day value
     *
     * @param  day - New day value (1-31)
     * @return void
     */
    void SetDay(int day);

    /**
     * @brief  Returns the month value as integer
     *
     * @return int - Month value (1-12)
     */
    int GetMonth() const;

    /**
     * @brief  Sets the month value
     *
     * @param  month - New month value (1-12)
     * @return void
     */
    void SetMonth(int month);

    /**
     * @brief  Returns the year value
     *
     * @return int - Year value
     */
    int GetYear() const;

    /**
     * @brief  Sets the year value
     *
     * @param  year - New year value
     * @return void
     */
    void SetYear(int year);

private:
    /// Day value
    int m_day;

    /// Month value
    int m_month;

    /// Year value
    int m_year;

};

//---------------------------------------------------------------------------------

/**
 * @brief Comparison operator for less-than
 * Compares two Date objects: order by year, then month, then day
 * @param left First date to compare
 * @param right Second date to compare
 * @return true if left date is earlier than right date
 */
bool operator<(const Date& left, const Date& right);

/**
 * @brief Equality operator
 * Checks if two Date objects represent the same date
 * @param left First date to compare
 * @param right Second date to compare
 * @return true if both dates are identical
 */
bool operator==(const Date& left, const Date& right);
#endif
