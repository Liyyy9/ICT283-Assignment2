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

void CollectU::CollectWindSpeed(const WeatherRecord& record)
{
    A.Add(record.GetSpeedKmH());
}

void CollectU::CollectAmbientTemp(const WeatherRecord& record)
{
    A.Add(record.GetAmbTemp());
}

void CollectU::CollectSolarRad(const WeatherRecord& record)
{
    A.Add(record.GetSolarRad());
}

int CollectU::size() const
{
    return A.Size();
}

double& CollectU::operator[](int k)
{
    return CollectU::A[k];
}

Vector<double>& CollectU::GetCollection()
{
    return A;
}

void CollectU::clear()
{
    A.Clear();
}
