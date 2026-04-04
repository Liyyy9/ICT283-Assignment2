// ===================================================================
// WeatherStatsCollector.cpp
//      Collector class to store data retrieved from BST via fpointer
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===================================================================

#include "WeatherStatsCollector.h"
#include "Utilities.h"
#include "Vector.h"

#include <iostream>

using std::cout;
using std::endl;

// Initialise static member
Vector<double> WeatherStatsCollector::m_collection;

// Extracts the wind speed in km/h from a weather record and adds it to the collection
void WeatherStatsCollector::CollectWindSpeed(const WeatherRecord& record)
{
    m_collection.Add(record.GetSpeedKmH());
}

// Extracts the ambient temperature from a weather record and adds it to the collection
void WeatherStatsCollector::CollectAmbientTemp(const WeatherRecord& record)
{
    m_collection.Add(record.GetAmbTemp());
}

// Extracts the solar radiation from a weather record and adds it to the collection
void WeatherStatsCollector::CollectSolarRad(const WeatherRecord& record)
{
    m_collection.Add(record.GetSolarRad());
}

// Returns the size of the collection
int WeatherStatsCollector::size() const
{
    return m_collection.Size();
}

// Indexed access to the collection
double& WeatherStatsCollector::operator[](int k)
{
    return WeatherStatsCollector::m_collection[k];
}

// Returns the entire collection
Vector<double>& WeatherStatsCollector::GetCollection()
{
    return m_collection;
}

// Clears the collection
void WeatherStatsCollector::clear()
{
    m_collection.Clear();
}
