// ===============================================================
// WeatherRecord.cpp
//      Manages individual wind record with date, time, and speed
//      Implements getters, setters, and speed unit conversion
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - lab 08
// ===============================================================

#include "WeatherRecord.h"

// Default Constructor
// Initialises speed to 0.0f, ambTemp to 0.0f, and solarRad to 0
WeatherRecord::WeatherRecord()
{
    speed = 0.0f;
    ambTemp = 0.0f;
    solarRad = 0;
}

// Parameterised Constructor
// Initialises with provided date, time, speed, ambient temperature, and solar radiation values
WeatherRecord::WeatherRecord(const Date &date, const Time &time, float s, float amb, int sr)
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

bool WeatherRecord::operator<(const WeatherRecord& other) const
{
    if(this->d < other.d)
    {
        return true;
    }
    if(other.d < this->d)
    {
        return false;
    }

    return (this->t < other.t);
}

bool WeatherRecord::operator==(const WeatherRecord& other) const
{
    if(!(this->d == other.d))
    {
        return false;
    }

    return (this->t == other.t);
}
