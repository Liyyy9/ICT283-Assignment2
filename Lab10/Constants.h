// ===============================================================
// Constants.h
//      Contains all the global constants used throughout the
//      program
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

//---------------------------------------------------------------------------------

/**
 * @file Constants.h
 * @brief Global constants used throughout the weather record system
 *
 * Centralised location for all global constants including column names,
 * delimiters, file paths, and configuration values. This ensures maintainability
 * and consistency across all modules.
 *
 * @author Liyana Afiqah Binte Jazmi
 * @version 01
 * @date 18/02/2026 Liyana Afiqah, Initial Implementation (scattered throughout project)
 *
 * @version 02
 * @date 24/02/2026 Liyana Afiqah, Refactored global constants to Constants.h
 */

// Constants for column names
#define DATE_TIME_COLUMN "WAST"
#define SPEED_COLUMN "S"
#define AMBIENT_TEMP_COLUMN "T"
#define SOLAR_RAD_COLUMN "SR"

// Constants for delimiters
#define COMMA_DELIMITER ','
#define SLASH_DELIMITER '/'
#define COLON_DELIMITER ':'

// Constant path to data folder
#define PATH "data/"

// Constant for Vector initial capacity
#define INITIAL_CAPACITY 6

#endif // CONSTANTS_H_INCLUDED
