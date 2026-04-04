// ===================================================================
// CollectU.h
//      Collector class to store data retrieved from BST via fpointer
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===================================================================

#include "Date.h"
#include "Vector.h"
#include "WeatherRecord.h"

#ifndef COLLECTU_H_INCLUDED
#define COLLECTU_H_INCLUDED

/**
 * @class CollectU
 * @brief Collector class to store data retrieved from BST via function pointer
 *
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 31/03/2026, Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 01/04/2026, Liyana Afiqah, Collect functions for weather variables
 */

 class CollectU
 {
 public:
    /**
     * @brief Callback function to collect Wind Speed
     * @param record The WeatherRecord to extract data from
     */
     static void CollectWindSpeed(const WeatherRecord& record);

     /**
     * @brief Callback function to collect Ambient Temperature
     * @param record The WeatherRecord to extract data from
     */
     static void CollectAmbientTemp(const WeatherRecord& record);

     /**
     * @brief Callback function to collect Solar Radiation
     * @param record The WeatherRecord to extract data from
     */
     static void CollectSolarRad(const WeatherRecord& record);

    /**
     * @brief Returns the number of elements collected
     * @return int - size of the internal vector
     */
     int size() const;

    /**
     * @brief Provides indexed access to collected data
     * @param k Index of the element
     * @return double& Reference to the stored value
     */
     double& operator[](int k);

     /**
     * @brief Provides access to the internal vector for Math calculation
     * @return Vector<double>& Reference to the collection
     */
     Vector<double>& GetCollection();

     /**
     * @brief Clears the internal storage for the next collection
     */
     void clear();

 private:
    static Vector<double> A;      /// Storage for collected numeric data
 };

#endif // COLLECTU_H_INCLUDED
