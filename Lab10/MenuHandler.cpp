// ===============================================================
// MenuHandler.cpp
//      Manages user interaction and menu-driven weather data analysis
//      Handles input validation and orchestrates calculations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "MenuHandler.h"
#include "Math.h"
#include "WeatherRecord.h"
#include "WeatherRecordCollection.h"
#include "Date.h"
#include "Vector.h"
#include "Utilities.h"
#include "CollectU.h"

#include <iomanip>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ofstream;
using std::setprecision;

// Displays the weather data menu with all available options
void MenuHandler::ShowMenu() const
{
    cout << "==== Weather Data Menu ====" << endl
         << endl;
    cout << "1. Average wind speed and standard deviation for this wind speed for a specified month and year." << endl;
    cout << "2. Average ambient air temperature and standard deviation for each month of a specified year." << endl;
    cout << "3. Sample Pearson Correlation Coefficient (sPCC) for all variables for a specified month" << endl;
    cout << "4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m^2 for each month of a specified year and export findings to WindTempSolar.csv." << endl;
    cout << "5. Exit program" << endl;
    cout << endl;
    cout << "==== End of Weather Data Menu ====" << endl
         << endl;
}

// Routes user menu choice to appropriate analysis function
// Prompts for month/year as required and calls corresponding handler
void MenuHandler::HandleChoice(int choice, const WeatherRecordCollection &data)
{
    int month = 0;
    int year = 0;

    switch (choice)
    {
    case 1:
        // Choice 1: Wind speed analysis for specific month and year
        month = ValidMonthInput(month);

        cout << "Enter year: ";
        cin >> year;

        cout << endl;

        WindAvgStdDev_Choice1(month, year, data);

        break;

    case 2:
        // Choice 2: Temperature analysis for all months of a year
        cout << "Enter year: ";
        cin >> year;

        cout << endl;

        AmbientTempAvgStdDev_Choice2(year, data);

        break;

    case 3:
        // Choice 3: Display sPCC combinations for specified month of all years
        month = ValidMonthInput(month);

        cout << endl;

        DisplaysPCC_Choice3(month, data);

        break;

    case 4:
        // Choice 4: Combined analysis and CSV export for all months of a year
        cout << "Enter year: ";
        cin >> year;

        DisplayAllFindings_Choice4(year, data);

        break;

    case 5:
        // Choice 5: Exit program
        cout << "Exiting program. Goodbye!\n"
             << endl;
        break;

    default:
        // Invalid menu selection
        cout << "Invalid choice! Please try again.\n"
             << endl;
        break;
    }
}

// Analyses wind speed for a specific month and year
// Filters dataset by month and year, then calculates mean and sample standard deviation in km/h
// Displays "No Data" message if no records found for the specified month/year
void MenuHandler::WindAvgStdDev_Choice1(int month, int year, const WeatherRecordCollection &data)
{
    Math math;
    CollectU collector;

    // Ensure that storage is empty
    collector.clear();

    // Retrieve the nested map structure
    const Map<int, Map<int, Bst<WeatherRecord>>>& inventory = data.GetInventory();

    // Check if the specific year and month keys exist in the inventory
    if(inventory.Contains(year) && inventory.At(year).Contains(month))
    {
        // Traverses the BST for the specific month/year and populates the collection
        inventory.At(year).At(month).InOrder(CollectU::CollectWindSpeed);

        Vector<double>& results = collector.GetCollection();

        // Compute statistical calculations
        double mean = math.CalculateMean(results);
        double sd = math.CalculateSD(results, mean);

        // Display output
        cout << GetMonthName(month) << " " << year << ": " << '\n'
             << "Average speed: " << fixed << setprecision(1) << mean << " km/h\n"
             << "Sample stdev: " << fixed << setprecision(1) << sd << endl
             << endl;
    }
    else
    {
        // Handle cases where no data matches input
        cout << GetMonthName(month) << " " << year << ": No Data" << endl
             << endl;
    }

    cout << endl;
}


// Analyses ambient temperature for each month of a specified year
// Loops through all 12 months, filtering dataset for each month and year
// Calculates and displays mean and sample standard deviation in degrees C for each month
// Displays "No Data" message for months with no records
void MenuHandler::AmbientTempAvgStdDev_Choice2(int year, const WeatherRecordCollection &data)
{
    Math math;
    CollectU collector;

    const Map<int, Map<int, Bst<WeatherRecord>>>& inventory = data.GetInventory();

    cout << year << endl;

    if(!inventory.Contains(year))
    {
        cout << "No data for this year" << endl;
        return;
    }

    // Iterate through all 12 months
    for (int month = 1; month <= 12; month++)
    {
        // Ensure that storage is empty
        collector.clear();

        const Map<int, Bst<WeatherRecord>>& monthMap = inventory.At(year);

        if(monthMap.Contains(month))
        {
            const Bst<WeatherRecord>& monthBst = monthMap.At(month);

            monthBst.InOrder(CollectU::CollectAmbientTemp);

            Vector<double>& results = collector.GetCollection();

            if(results.Size() > 0)
            {
                double mean = math.CalculateMean(results);
                double sd = math.CalculateSD(results, mean);

                cout << GetMonthName(month) << ": "
                 << "average: " << fixed << setprecision(1) << mean << " degrees C, "
                 << "stdev: " << fixed << setprecision(1) << sd << endl;
            }
            else
            {
                cout << GetMonthName(month) << ": No Data" << endl;
            }
        }
        else
        {
            cout << GetMonthName(month) << ": No Data" << endl;
        }
    }

    cout << endl;
}

// Analyses sPCC combinations for specified month of all years
// Loops through all years, filtering dataset for specified month
void MenuHandler::DisplaysPCC_Choice3(int month, const WeatherRecordCollection &data)
{
    Math math;
    CollectU collector;
    const Map<int, Map<int, Bst<WeatherRecord>>>& inventory = data.GetInventory();

    cout << "The combinations are:\n"
         << "\ta) S_T: Average Wind Speed (S) and Ambient Air Temperature (T)\n"
         << "\tb) S_R: Average Wind Speed (S) and Solar Radiation (R)\n"
         << "\tc) T_R: Ambient Air Temperature (T) and Solar Radiation (R)\n"
         << endl;

    Vector<double> windS;
    Vector<double> tempT;
    Vector<double> solarR;

    collector.clear();
    for(Map<int, Map<int, Bst<WeatherRecord>>>::const_iterator it = inventory.begin(); it != inventory.end(); ++it)
    {
        const Map<int, Bst<WeatherRecord>>& monthMap = it->second;
        if(monthMap.Contains(month))
        {
            monthMap.At(month).InOrder(CollectU::CollectWindSpeed);
        }
    }
    windS = collector.GetCollection();

    collector.clear();
    for(Map<int, Map<int, Bst<WeatherRecord>>>::const_iterator it = inventory.begin(); it != inventory.end(); ++it)
    {
        const Map<int, Bst<WeatherRecord>>& monthMap = it->second;
        if(monthMap.Contains(month))
        {
            monthMap.At(month).InOrder(CollectU::CollectAmbientTemp);
        }
    }
    tempT = collector.GetCollection();

    collector.clear();
    for(Map<int, Map<int, Bst<WeatherRecord>>>::const_iterator it = inventory.begin(); it != inventory.end(); ++it)
    {
        const Map<int, Bst<WeatherRecord>>& monthMap = it->second;
        if(monthMap.Contains(month))
        {
            monthMap.At(month).InOrder(CollectU::CollectSolarRad);
        }
    }
    solarR = collector.GetCollection();

    cout << "Sample Pearson Correlation Coefficient for " << GetMonthName(month) << endl;

    if(windS.Size() < 2)
    {
        cout << "S_T: No data" << endl;
        cout << "S_R: No data" << endl;
        cout << "T_R: No data" << endl;

    }
    else
    {
        double s_t = math.CalculateSPCC(windS, tempT);
        double s_r = math.CalculateSPCC(windS, solarR);
        double t_r = math.CalculateSPCC(tempT, solarR);

        cout << fixed << setprecision(2);
        cout << "S_T: " << s_t << endl;
        cout << "S_R: " << s_r << endl;
        cout << "T_R: " << t_r << endl;
    }

    cout << endl;
}

// Generates comprehensive weather report for all months of a year
// Calculates wind speed, temperature, and solar radiation statistics
// Displays results to console and exports to WindTempSolar.csv
// Format: Month,AvgWind(StdevWind),AvgTemp(StdevTemp),SolarRadiation
void MenuHandler::DisplayAllFindings_Choice4(int year, const WeatherRecordCollection &data)
{
    Math math;
    CollectU collector;

    const Map<int, Map<int, Bst<WeatherRecord>>>& inventory = data.GetInventory();

    // Open output file for CSV export
    string exportFileName = "WindTempSolar.csv";
    ofstream ofile(exportFileName);
    if (!ofile)
    {
        cout << "Error writing output file WindTempSolar.csv\n";
        return;
    }

    cout << year << endl;
    // Write year header
    ofile << year << "\n";

    bool dataLoaded = false;

    if(!inventory.Contains(year))
    {
        cout << "No Data" << endl;
        ofile << "No Data" << endl;
        return;
    }

    const Map<int, Bst<WeatherRecord>>& monthMap = inventory.At(year);

    Vector<double> windSpeeds;
    Vector<double> ambientTemps;
    Vector<double> solarRad;

    // Iterate through all 12 months
    for (int month = 1; month <= 12; month++)
    {
        collector.clear();

        if(monthMap.Contains(month))
        {
            const Bst<WeatherRecord>& monthBst = monthMap.At(month);

            monthBst.InOrder(CollectU::CollectWindSpeed);
            windSpeeds = collector.GetCollection();

            collector.clear();

            monthBst.InOrder(CollectU::CollectAmbientTemp);
            ambientTemps = collector.GetCollection();

            collector.clear();

            monthBst.InOrder(CollectU::CollectSolarRad);
            solarRad = collector.GetCollection();

            // Calculate wind speed statistics
            double avgWind = math.CalculateMean(windSpeeds);
            double sdWind = math.CalculateSD(windSpeeds, avgWind);
            double madWind = math.CalculateMAD(windSpeeds);

            // Calculate temperature statistics
            double avgTemp = math.CalculateMean(ambientTemps);
            double sdTemp = math.CalculateSD(ambientTemps, avgTemp);
            double madTemp = math.CalculateMAD(ambientTemps);

            // Calculate solar radiation total
            double monthlySolarRadiationSum = 0.0;
            for (int i = 0; i < solarRad.Size(); i++)
            {
                monthlySolarRadiationSum += solarRad[i];
            }

            // Convert to kWh/m^2 by dividing by 6000
            double totalkWhm2 = monthlySolarRadiationSum / 6000;

            // Output to console and file in same format
            cout << GetMonthName(month) << ","
                 << fixed << setprecision(1)
                 << avgWind << "(" << sdWind << "," << madWind << "),"
                 << avgTemp << "(" << sdTemp << "," << madTemp <<  "),"
                 << totalkWhm2 << endl;

            ofile << GetMonthName(month) << ","
                  << fixed << setprecision(1)
                  << avgWind << "(" << sdWind << " " << madWind << "),"
                  << avgTemp << "(" << sdTemp << "" << madTemp <<  "),"
                  << totalkWhm2 << endl;

            dataLoaded = true;
        }
    }

    // Handle case where no data exists for the specified year
    if (dataLoaded)
    {
        cout << "\nData successfully exported to: " << exportFileName << endl;
    }

    cout << endl;
}
