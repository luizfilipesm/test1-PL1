/*!
 * \file driver_min.h
 * This application header.
 */

#ifndef _DRIVER_MIN_H_
#define _DRIVER_MIN_H_

#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>

//=== New type

enum food_t : int { NATURAL=0, PROCESSED=1 };

/// Represents a food
struct Food {
    // Nutrition facts per 100g.
    food_t type;
    std::string name;
    int calories; // per 100g
    float sugar; // per 100g
    float fiber;
};

/// Overloading extractor operator to support the Food type. Return a string representation for a food.
std::ostream& operator<<( std::ostream& , const Food & );
std::string print_int( const int*, const int* );
std::string print_food( const Food*, const Food* );
bool compare_sugar( const void*, const void* );
bool compare_calories( const void*, const void* );
bool compare_fiber( const void*, const void* );

#endif
