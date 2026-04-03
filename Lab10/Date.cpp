// ===============================================================
// Date.cpp
//      Store and manage date information (day, month, year)
//      Converts numeric month values to month names
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================
#include "Date.h"
#include "Utilities.h"

using std::cout;

// Default Constructor
// Initialises date to 1/1/1800
// Using member initialisation list to fix -Weffc++ warnings
Date::Date() : m_day(1), m_month(1), m_year(1800) {}

// Parameterised Constructor
// Initialises date with the provided day, month, and year values
Date::Date(int day, int month, int year)
    : m_day(1), m_month(1), m_year(1800)        // Fix -Weffc++ warnings
{
    if(IsValidDate(day, month, year))
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
}

// Getter: Returns the day value
int Date::GetDay() const
{
    return m_day;
}

// Setter: Sets the day value
void Date::SetDay(int day)
{
    m_day = day;
}

// Getter: Returns the month value
int Date::GetMonth() const
{
    return m_month;
}

// Setter: Sets the month value
void Date::SetMonth(int month)
{
    m_month = month;
}

// Getter: Returns the year value
int Date::GetYear() const
{
    return m_year;
}

// Setter: Sets the year value
void Date::SetYear(int year)
{
    m_year = year;
}

// Operator: Less-than Comparison (<)
// Purpose: Compare two dates (year -> month -> day)
//          Returns true if left date is earlier than right date
bool operator<(const Date& left, const Date& right)
{
    // Compare years first
    if(left.GetYear() != right.GetYear())
    {
        return left.GetYear() < right.GetYear();
    }

    // Years are equal, compare months
    if(left.GetMonth() != right.GetMonth())
    {
        return left.GetMonth() < right.GetMonth();
    }

    // Years and months are equal, compare days
    return left.GetDay() < right.GetDay();
}

// Operator: Equality Comparison (==)
// Purpose: Check if two dates are identical
//          Returns true if both dates are the same
bool operator==(const Date& left, const Date& right)
{
    return left.GetDay() == right.GetDay() &&
           left.GetMonth() == right.GetMonth() &&
           left.GetYear() == right.GetYear();
}
