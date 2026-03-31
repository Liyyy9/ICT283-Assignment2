// ===============================================================
// MenuHandler.h
//      Manages user interaction and menu-driven weather data analysis
//      Handles input validation and calculations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef MENUHANDLER_H_INCLUDED
#define MENUHANDLER_H_INCLUDED

#include "WeatherRecord.h"
#include "WeatherRecordCollection.h"

#include <iostream>

using std::string;

//---------------------------------------------------------------------------------
/**
 * @class MenuHandler
 * @brief Manages user menu interaction and weather data analysis
 *
 * Provides menu display, user input handling, and coordinates
 * statistical calculations on weather records. Supports four menu
 * options: wind speed analysis, temperature analysis, solar radiation
 * calculations, and combined report export.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 28/02/2026 Liyana Afiqah, Initial Implementation
 *
 * @version 02
 * @date 31/03/2026 Liyana Afiqah, Updated to integrate Map/BST data structure
 *
 */
 //---------------------------------------------------------------------------------

class MenuHandler
{
public:
    /**
     * @brief Displays the main menu with all available options
     *
     * Prints the menu to standard output
     * showing all available choices (1-5).
     *
     * @return void
     */
    void ShowMenu() const;

    /**
     * @brief Processes user menu choice and executes corresponding analysis
     *
     * Routes the user's menu selection to the appropriate analysis function.
     * Prompts for required parameters (month/year) and calls the relevant
     * calculation function.
     *
     * @param choice The menu choice selected by user (1-5)
     * @param data Reference to the WeatherRecordLog containing all weather records
     *
     * @return void
     */
    void HandleChoice(int choice, const WeatherRecordCollection &data);

    /**
     * @brief Calculates and displays the mean wind speed and standard deviation for a specific month
     *
     * Filters the WeatherRecordCollection by specified month and year.
     * If data exists, it performs InOrder traversal of the BST to collect wind speeds, calculates
     * mean and sample standard deviation of wind speeds, and outputs them to console in km/h
     *
     * @param month The month to analyse (1-12)
     * @param year The year to analyse
     * @param data The collection containing weather records organised by year and month
     *
     * @return void
     */
    void WindAvgStdDev_Choice1(int month, int year, const WeatherRecordCollection &data);

    /**
     * @brief Analyses average ambient temperature and standard deviation for each month of a year
     *
     * Loops through all 12 months, filtering dataset for each month and year.
     * Calculates and displays mean and sample standard deviation of ambient temperatures
     * for each month in the specified year.
     *
     * @param year The year to analyse
     * @param data The collection containing weather records organised by year and month
     *
     * @return void
     */
    void AmbientTempAvgStdDev_Choice2(int year, const WeatherRecordCollection &data);

    /**
     * @brief Calculates total solar radiation in kWh/m^2 for each month of a year
     *
     * Loops through all 12 months, filtering dataset for each month and year.
     * Sums solar radiation values for each month and converts to kWh/m^2 by dividing by 6000.
     *
     * @param year The year to analyse
     * @param data The collection containing weather records organised by year and month
     *
     * @return void
     */
    void DisplaysPCC_Choice3(int year, const WeatherRecordCollection &data);

    /**
     * @brief Generates comprehensive weather report and exports to CSV file
     *
     * Calculates and displays average wind speed, ambient temperature,
     * and solar radiation for each month of the specified year.
     * Exports results to WindTempSolar.csv in format:
     * Month,AvgWind(StdevWind),AvgTemp(StdevTemp),SolarRadiation
     *
     * @param year The year to analyse
     * @param data The collection containing weather records organised by year and month
     *
     * @return void
     */
    void DisplayAllFindings_Choice4(int year, const WeatherRecordCollection &data);

};

#endif // MENUHANDLER_H_INCLUDED
