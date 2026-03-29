// ===============================================================
// Math.cpp
//      Calculates statistical measures for weather data
//      Computes mean and sample standard deviation for wind (km/h) and temperature (degrees C)
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 08
// ===============================================================

#include <cmath>
#include "Math.h"
#include "WeatherRecord.h"

// Calculates the mean of the specified dataset column
// Wind speed values are converted from m/s to km/h by multiplying by 3.6
// Returns 0.0 if the vector is empty or column is invalid

// TO DO: To pass a vector of floats or double instead, not a vector of weatherrecords
double Math::CalculateMean(const Vector<double> &data)
{
    int n = data.Size();
    if (n == 0)
    {
        return 0.0;
    }

    double sum = 0.0;
    double mean = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }

    mean = sum / n;

    return mean;
}

// Calculates the sample standard deviation of the specified dataset column
// Computes using the formula: SD = sqrt(sum of (x - mean)^2 / (n - 1))
// Uses n-1 denominator for sample standard deviation
double Math::CalculateSD(const Vector<double> &data, double mean)
{
    int n = data.Size();
    if (n <= 1)
    {
        return 0.0;
    }

    double std_dev = 0.0;
    double numeratorSum = 0.0;

    for (int i = 0; i < n; i++)
    {
        double diff = data[i] - mean;
        numeratorSum += diff * diff;
    }

    double denominator = numeratorSum / (n - 1);

    std_dev = sqrt(denominator);

    return std_dev;
}

double Math::CalculateSPCC(const Vector<double> &v1, const Vector<double> &v2)
{
    // Check if size between two vectors are the same
    if(v1.Size() != v2.Size() || v1.Size() == 0)
    {
        return 0.0;
    }

    int size = v1.Size();

    // part 1: mean of x and y
    double xMean = CalculateMean(v1);
    double yMean = CalculateMean(v2);

    // part 2: sum of part 5 (numerator)
        // part 3: x-x_ and x-x_2
        // part 4: y-y_ and y-y_2
        // part 5: x-x_ * y-y_
        // part 6: sum of part 2 square
        // part 7: sum of part 3 squared
    double xDiff = 0.0;
    double yDiff = 0.0;
    double sumXDiffSq = 0.0;
    double sumYDiffSq = 0.0;
    double sumxMinusXBarSq = 0.0;
    double sumyMinusYBarSq = 0.0;

    double numerator = 0.0;
    double denominator = 0.0;

    for(int i = 0; i < size; i++)
    {
        // Calculate x-x bar and y-y bar
        xDiff = v1[i] - xMean;
        yDiff = v2[i] - yMean;

        // Numerator = Sum up x-x bar * y-y bar
        numerator += xDiff * yDiff;

        // Sum up the squares for the denominator
        sumXDiffSq += (xDiff * xDiff);
        sumYDiffSq += (yDiff * yDiff);

    }

    // part 8: sqrt part 6 * part 7
    denominator = sqrt(sumXDiffSq * sumYDiffSq);

    if(denominator == 0)
    {
        return 0.0;
    }

    // part 9: r = num/den
    double r = numerator / denominator;

    return r;
}

double Math::CalculateMAD(const Vector<double> &data)
{
    // Check if dataset is empty
    if(data.Size() == 0)
    {
        return 0.0;
    }

    // 1. Calculate mean of dataset
    double datasetMean = CalculateMean(data);
    int size = data.Size();

    double diff = 0.0;          // x - mean
    double numerator = 0.0;

    for(int i = 0; i < size; i++)
    {
        diff = data[i] - datasetMean;

        // Takes the absolute value of diff; avoiding negatives
        if(diff < 0)
        {
            diff = -diff;
        }

        numerator += diff;
    }

    double MAD = numerator / size;

    return MAD;
}



