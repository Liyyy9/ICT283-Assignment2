// ===============================================================
// Time.h
//      Manages time information with hour and minute values
//      Provides validation and formatted I/O
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

//---------------------------------------------------------------------------------
/**
 * @class Time
 * @brief Manages time information with hour and minute values
 *
 * Stores a time as two separate integer values (hour, minute).
 * Times are read from input streams in the format HH:MM.
 * Times are output in the format: HH:MM with leading zeros for minutes.
 * Validates time input, checks valid ranges (0-23 hours, 0-59 minutes).
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 17/02/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 26/02/2026 Liyana Afiqah, Moved I/O operators into Utilities
 */

class Time
{
public:
    /**
     * @brief Default constructor - initialises time to 12:30
     *
     * Creates a Time object with default values
     * Hour = 12, Minutes = 30
     *
     * @return void
     */
    Time();

    /**
     * @brief Parameterised constructor - initialises time with provided values
     *
     * Creates a Time object with specified hour and minute values.
     * Validates input before setting values; defaults to 12:30 if invalid.
     *
     * @param hour The hour value (0-23)
     * @param mins The minute value (0-59)
     *
     * @return void
     */
    Time(int hour, int mins);

    /**
     * @brief Getter - returns the hour value
     *
     * @return The hour value (0-23)
     */
    int GetHour() const;

    /**
     * @brief Setter - sets the hour value
     *
     * @param hour The hour value to set (0-23)
     *
     * @return void
     */
    void SetHour(int hour);

    /**
     * @brief Getter - returns the minute value
     *
     * @return The minute value (0-59)
     */
    int GetMins() const;

    /**
     * @brief Setter - sets the minute value
     *
     * @param mins The minute value to set (0-59)
     *
     * @return void
     */
    void SetMins(int mins);

    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;

private:
    int m_hour;
    int m_mins;
};

#endif // TIME_H_INCLUDED
