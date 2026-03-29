// ===============================================================
// Main.cpp
//      Reads CSV weather data and processes wind records
//      Calculates mean and standard deviation of wind speeds
//      Identifies records matching average wind speed
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 10
// ===============================================================

#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "CSVHeaderReader.h"
#include "Math.h"
#include "WeatherRecord.h"
#include "WeatherRecordCollection.h"
#include "MenuHandler.h"
#include "Constants.h"
#include "Utilities.h"
#include "CSVLoader.h"
#include "Bst.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;
using std::cin;

int main()
{
    // Initialize CSV header reader, Menu Handler
    CSVLoader loader;

    WeatherRecordCollection weather_data = loader.LoadAllCSV();

    if(weather_data.Size() == 0)
    {
        cout << "Failed to load data\n";
        return -1;
    }

    // Variable to store the user's menu choice
    MenuHandler menu;
    int choice = 0;

    // Keep showing the menu until the user chooses to exit (option 5)
    do
    {
        menu.ShowMenu();

        cout << "Enter your choice: ";

        // Check if the input is a valid number
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n"
                 << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Handle the user's choice and pass the weather data
        menu.HandleChoice(choice, weather_data);

    } while (choice != 5); // Exit when user chooses option 5

    return 0;
}

