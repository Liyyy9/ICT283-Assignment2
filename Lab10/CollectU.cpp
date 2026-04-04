// ===================================================================
// CollectU.cpp
//      Collector class to store data retrieved from BST via fpointer
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===================================================================

#include "CollectU.h"
#include "Utilities.h"
#include "Vector.h"

#include <iostream>

using std::cout;
using std::endl;

// Initialise static member
Vector<double> CollectU::A;

// Extracts the wind speed in km/h from a weather record and adds it to the collection
void CollectU::CollectWindSpeed(const WeatherRecord& record)
{
    A.Add(record.GetSpeedKmH());
}

// Extracts the ambient temperature from a weather record and adds it to the collection
void CollectU::CollectAmbientTemp(const WeatherRecord& record)
{
    A.Add(record.GetAmbTemp());
}

// Extracts the solar radiation from a weather record and adds it to the collection
void CollectU::CollectSolarRad(const WeatherRecord& record)
{
    A.Add(record.GetSolarRad());
}

// Returns the size of the collection
int CollectU::size() const
{
    return A.Size();
}

// Indexed access to the collection
double& CollectU::operator[](int k)
{
    return CollectU::A[k];
}

// Returns the entire collection
Vector<double>& CollectU::GetCollection()
{
    return A;
}

// Clears the collection
void CollectU::clear()
{
    A.Clear();
}
