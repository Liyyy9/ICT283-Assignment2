// ===============================================================
// WeatherRecord.cpp
//      Manages individual wind record with date, time, and speed
//      Implements getters, setters, and speed unit conversion
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "WeatherRecord.h"

// Default Constructor
// Initialises speed to 0.0f, ambTemp to 0.0f, and solarRad to 0
// Using member initialisation list to fix -Weffc++ warnings
WeatherRecord::WeatherRecord() : d(1,1,1800), t(12,30), speed(0.0f), ambTemp(0.0f), solarRad(0){}

// Parameterised Constructor
// Initialises with provided date, time, speed, ambient temperature, and solar radiation values
WeatherRecord::WeatherRecord(const Date &date, const Time &time, float s, float amb, int sr)
    : d(1,1,1800), t(12,30), speed(0.0f), ambTemp(0.0f), solarRad(0)        // Fix -Weffc++ warnings
{
    d = date;
    t = time;
    speed = s;
    ambTemp = amb;
    solarRad = sr;
}

// Getter: Returns the date
Date WeatherRecord::GetDate() const
{
    return d;
}

// Setter: Sets the date
void WeatherRecord::SetDate(const Date &date)
{
    d = date;
}

// Getter: Returns the time
Time WeatherRecord::GetTime() const
{
    return t;
}

// Setter: Sets the time
void WeatherRecord::SetTime(const Time &time)
{
    t = time;
}

// Getter: Returns wind speed in meters per second
float WeatherRecord::GetSpeed() const
{
    return speed;
}

// Getter: Returns wind speed in kilometers per hour
// Converts from m/s to km/h by multiplying by 3.6
float WeatherRecord::GetSpeedKmH() const
{
    return speed * 3.6f;
}

// Setter: Sets the wind speed in meters per second
void WeatherRecord::SetSpeed(float s)
{
    speed = s;
}

// Getter: Returns ambient temperature
float WeatherRecord::GetAmbTemp() const
{
    return ambTemp;
}

// Setter: Sets ambient temperature
void WeatherRecord::SetAmbTemp(float amb)
{
    ambTemp = amb;
}

// Getter: Returns solar radiation
int WeatherRecord::GetSolarRad() const
{
    return solarRad;
}

// Setter: Sets solar radiation
void WeatherRecord::SetSolarRad(int sr)
{
    solarRad = sr;
}

// Operator < to check WeatherRecord time stamp less than other
bool WeatherRecord::operator<(const WeatherRecord& other) const
{
    // Compare Dates
    if(this->d < other.d)
    {
        return true;
    }
    if(other.d < this->d)
    {
        return false;
    }

    // If dates are the same, compare Time
    return (this->t < other.t);
}

// Operator < to check WeatherRecord time stamp same as the other
bool WeatherRecord::operator==(const WeatherRecord& other) const
{
    // if Dates are not the same, records are not equal
    if(!(this->d == other.d))
    {
        return false;
    }

    // If Date matches, check Time
    return (this->t == other.t);
}
