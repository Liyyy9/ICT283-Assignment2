// ===============================================================
// WeatherRecord.h
//      Manages individual wind record with date, time, and speed
//      Provides getters, setters, and speed unit conversion
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================

#ifndef WEATHERRECORD_H_INCLUDED
#define WEATHERRECORD_H_INCLUDED

#include "Date.h"
#include "Time.h"
#include "Vector.h"

//---------------------------------------------------------------------------------
/**
 * @class WeatherRecord
 * @brief Encapsulates a single weather data record
 *
 * A class that represents a complete weather observation containing:
 * - Date information (day, month, year)
 * - Time information (hour, minutes)
 * - Wind speed measurement with unit conversion support
 * - Ambient Temperature information
 * - Solar Radiation information
 *
 * Provides methods to access and modify weather data.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 18/02/2026 Liyana Afiqah, Initial Implementation
 */
class WeatherRecord
{
public:
    /**
     * @brief Default constructor - initialises wind record
     *
     * Creates a WeatherRecord object with default values.
     * Speed is initialized to 0.0f.
     * Ambient temperature is initialized to 0.0f.
     * Solar Radiation is initialized to 0.
     *
     * @return void
     */
    WeatherRecord();

    /**
     * @brief Parameterised constructor - initialises with provided values
     *
     * Creates a WeatherRecord object with specified date, time, speed, ambient temperature, and solar radiation values.
     *
     * @param date Reference to Date object
     * @param time Reference to Time object
     * @param s Wind speed in meters per second (m/s)
     * @param amb Ambient Temperature
     * @param sr Solar Radiation
     *
     * @return void
     */
    WeatherRecord(const Date &date, const Time &time, float s, float amb, int sr);

    /**
     * @brief Getter - returns the date
     *
     * @return The Date object
     */
    Date GetDate() const;

    /**
     * @brief Setter - sets the date
     *
     * @param date Reference to Date object to set
     *
     * @return void
     */
    void SetDate(const Date &date);

    /**
     * @brief Getter - returns the time
     *
     * @return The Time object
     */
    Time GetTime() const;

    /**
     * @brief Setter - sets the time
     *
     * @param time Reference to Time object to set
     *
     * @return void
     */
    void SetTime(const Time &time);

    /**
     * @brief Getter - returns wind speed in meters per second
     *
     * @return Wind speed in m/s
     */
    float GetSpeed() const;

    /**
     * @brief Getter - returns wind speed converted to kilometers per hour
     *
     * Converts from m/s to km/h by multiplying by 3.6
     *
     * @return Wind speed in km/h
     */
    float GetSpeedKmH() const;

    /**
     * @brief Setter - sets the wind speed in meters per second
     *
     * @param s Wind speed value in m/s
     *
     * @return void
     */
    void SetSpeed(float s);

    /**
     * @brief Getter - returns ambient temperature
     *
     * @return Ambient Temperature
     */
    float GetAmbTemp() const;

    /**
     * @brief Setter - sets the ambient temperature
     *
     * @param amb Ambient Temperature value
     *
     * @return void
     */
    void SetAmbTemp(float amb);

    /**
     * @brief Getter - returns solar radiation
     *
     * @return Solar Radiation
     */
    int GetSolarRad() const;

    /**
     * @brief Setter - sets the solar radiation value
     *
     * @param sr Solar Radiation value
     *
     * @return void
     */
    void SetSolarRad(int sr);

    bool operator<(const WeatherRecord& other) const;

private:
    Date d;        /// Date of the wind measurement
    Time t;        /// Time of the wind measurement
    float speed;   /// Wind speed in meters per second (m/s)
    float ambTemp; /// Ambient temperature measurement
    int solarRad;  /// Solar radiation temperature
};

#endif // WEATHERRECORD_H_INCLUDED
