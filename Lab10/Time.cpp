// ===============================================================
// Time.cpp
//      Store and manage time information (hour, minutes)
//      Validates time input and provides formatted I/O
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================

#include "Time.h"
#include "Utilities.h"

using std::endl;

// Default Constructor
// Initialises time to 12:30
Time::Time()
{
    m_hour = 12;
    m_mins = 30;
}

// Parameterised Constructor
// Initialises time with the provided hour and minute values
Time::Time(int hour, int mins)
{
    if (IsValidTime(hour, mins))
    {
        m_hour = hour;
        m_mins = mins;
    }
    else
    {
        m_hour = 12;
        m_mins = 30;
    }
}

// Getter: Returns the hour value
int Time::GetHour() const
{
    return m_hour;
}

// Setter: Sets the hour value
void Time::SetHour(int hour)
{
    m_hour = hour;
}

// Getter: Returns the minute value
int Time::GetMins() const
{
    return m_mins;
}

// Setter: Sets the minute value
void Time::SetMins(int mins)
{
    m_mins = mins;
}
