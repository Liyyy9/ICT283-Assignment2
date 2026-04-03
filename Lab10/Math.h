// ===============================================================
// Math.h
//      Calculates statistical measures for weather data
//      Computes mean and sample standard deviation for wind (km/h) and temperature (degrees C)
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include "Date.h"
#include "Time.h"
#include "Vector.h"

//---------------------------------------------------------------------------------
/**
 * @class Math
 * @brief Calculates statistical measures for weather data
 *
 * Provides generic methods to compute mean and sample standard deviation
 * for wind speed (km/h) and ambient temperature (degrees C) from a collection of weather data.
 * Wind speed values are converted from m/s as needed during calculation.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 18/02/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 23/02/2026 Liyana Afiqah, Generalising formulaes
 *
 * @version 03
 * @date 09/03/2026 Liyana Afiqah, Refactored to accept vector of floats instead of vector of weatherrecords
 *
 * @version 04
 * @date 15/03/2026 Liyana Afiqah, Added sPCC function
 */

class Math
{
public:
    /**
     * @brief Calculates the mean of the specified dataset column
     *
     * Iterates through all records and computes the average of the specified column.
     * Accepts column parameter: "wind" (converted to km/h) or "temp" (in degrees C).
     * Wind speed values are converted from m/s to km/h by multiplying by 3.6.
     *
     * @param data Reference to the vector containing weather data
     *
     * @return The mean of the specified column, or 0.0 if vector is empty or column is invalid
     */
    double CalculateMean(const Vector<double> &data);

    /**
     * @brief Calculates the sample standard deviation of the specified dataset column
     *
     * Computes the sample standard deviation using the formula:
     * SD = sqrt(sum of (x - mean)^2 / (n - 1))
     * Accepts column parameter: "wind" (in km/h) or "temp" (in degrees C).
     * Uses n-1 denominator for unbiased sample standard deviation.
     *
     * @param data Reference to the vector containing weather data
     * @param mean The pre-calculated mean of the specified column
     *
     * @return The sample standard deviation of the specified column, or 0.0 if vector has fewer than 2 elements or column is invalid
     */
    double CalculateSD(const Vector<double> &data, double mean);

    double CalculateSPCC(const Vector<double> &v1, const Vector<double> &v2);

    double CalculateMAD(const Vector<double> &data);
};

#endif // MATH_H_INCLUDED
