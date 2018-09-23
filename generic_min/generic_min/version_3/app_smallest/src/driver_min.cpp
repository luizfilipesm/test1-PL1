/*!
 * \file driver_min.cpp
 * This is the driver application that tests the generic int(),
 * calling it on arrays of different types and with varying comparison function.
 */

#include "../include/driver_min.h"
#include "../include/min.h"

/// Overloading extractor operator to support the Food type. Return a string representation for a food.
std::ostream& operator<<( std::ostream& os, const Food & f )
{
    os << std::left << "<\"" << std::setw(12) << f.name << "\""
        << ", cal=" << std::setw(4) << f.calories
        << ", sug=" << std::setw(6) << std::fixed << std::setprecision(1) << f.sugar
        << ", fib=" << f.fiber
        << ">";
    return os;
}

/// Extracting the array information to a stream.
std::string print_int( const int* first, const int* last )
{
    std::ostringstream oss;
    while( first != last )
        oss << *first++ << " ";

    return oss.str();
}

/// Extracting the array information to a stream.
std::string print_food( const Food* first, const Food* last )
{
    std::ostringstream oss;
    while( first != last )
        oss << *first++ << "\n";

    return oss.str();
}

/// Returns true if the first food has less SUGAR than the second food.
bool compare_sugar( const void * a, const void * b )
{
    return static_cast<const Food *>(a)->sugar < static_cast<const Food*>(b)->sugar ;
}

/// Returns true if the first food has less FIBER than the second food.
bool compare_fiber( const void * a, const void * b )
{
    return static_cast<const Food *>(a)->fiber   <  static_cast< const Food *>(b)->fiber ;
}

/// Returns true if the first food has less CALORIES than the second food.
bool compare_calories( const void * a, const void * b )
{
    return static_cast<const Food *>(a)->calories < static_cast<const Food *>(b)->calories ;
}

/// Returns true if the first food is healthier (i.e. less sugar, less calories, more fiber) than the second food.
bool compare_healthness( const void * a, const void * b )
{
    return static_cast<const Food *>(a)->calories < static_cast<const Food *>(b)->calories and
           static_cast<const Food *>(a)->sugar    < static_cast<const Food *>(b)->sugar and
           static_cast<const Food *>(a)->fiber    > static_cast<const Food *>(b)->fiber ;
}


/// Returns true if the first integer is less than the second integer.
bool compare_ints( const void * a, const void * b )
{
    return *static_cast<const int *>(a) < *static_cast<const int*>(b);
}

int main( void )
{
    // A simple array of integers.
    int A[] { 5, 6, 2, 1, 3, 7, 4 };

    // A simple array of Food.
    Food bag[] {
          { food_t::NATURAL,   "orange",        47,  9.f,   2.4f },
          { food_t::NATURAL,   "orange juice",  45,  8.f,   0.2f },
          { food_t::PROCESSED, "regular coke",  139, 10.9f, 0.f },
          { food_t::PROCESSED, "fried egg",     196, 1.1f,  0.f },
          { food_t::NATURAL,   "banana",        89,  12.f,  2.6f },
          { food_t::PROCESSED, "white bread",   256, 5.f,   2.7f }
        };

    // Prints out the integer array.
    std::cout << ">>> A = [" << print_int(std::begin(A), std::end(A)) << "]" << std::endl;
    // Find the smallest element.
    auto result =  (const int *) min( std::begin(A), std::end(A), sizeof(int), compare_ints );
    // Print the smallest found.
    std::cout << ">>> The smallest element in A is \"" << *result << "\"" << std::endl;

    std::cout << std::endl << std::endl;


    // Just prints out the list of food in the bag.
    std::cout << ">>> Bag: \n" << print_food(std::begin(bag), std::end(bag)) << std::endl;

    // NOTE THAT ALL CALLS TO MIN IS TO THE SAME FUNCTION, min(), CHANGING ONLY THE 4TH PARAMETER.
    // Find the smallest element based on calories.
    auto result2 =  (const Food *)min( std::begin(bag), std::end(bag), sizeof(Food), compare_calories );
    // Print the smallest found.
    std::cout << ">>> The least caloric food in the bag is \"" << *result2 << "\"" << std::endl;

    // Find the smallest element based on sugar.
    auto result3 =  (const Food *)min( std::begin(bag), std::end(bag), sizeof(Food), compare_sugar );
    // Print the smallest found.
    std::cout << ">>> The food lowest in sugar in the bag is \"" << *result3 << "\"" << std::endl;

    // Find the smallest element based on fiber.
    auto result4 =  (const Food *)min( std::begin(bag), std::end(bag), sizeof(Food), compare_fiber );
    // Print the smallest found.
    std::cout << ">>> The food with the least amount of fiber in the bag is \"" << *result4 << "\"" << std::endl;

    // Find the smallest element based on fiber.
    auto result5 =  (const Food *)min( std::begin(bag), std::end(bag), sizeof(Food), compare_healthness );
    // Print the smallest found.
    std::cout << ">>> The healthiest food in the bag is \"" << *result5 << "\"" << std::endl;

    return EXIT_SUCCESS;
}
