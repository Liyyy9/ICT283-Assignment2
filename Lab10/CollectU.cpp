// ===================================================================
// CollectU.cpp
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 10
// ===================================================================

#include "CollectU.h"
#include "Utilities.h"

#include <iostream>

using std::cout;
using std::endl;

// Initialise static members
Vector<Date> CollectU::A;

void CollectU::Collect(const Date& data)
{
    // Trace message
    cout << "Collecting element #" << A.Size()
         << " : " << data << endl;

    A.Add(data);
}

int CollectU::size() const
{
    return A.Size();
}

Date& CollectU::operator[](int k)
{
    return A[k];
}

void CollectU::clear()
{
    A.Clear();
}
