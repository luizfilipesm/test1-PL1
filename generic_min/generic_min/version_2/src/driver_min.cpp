/*!
 * \file driver_min.cpp
 * This is the second version.
 */

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
std::ostream& operator<<( std::ostream& os, const Food & f )
{
    os << std::left << "<\"" << std::setw(12) << f.name << "\""
        << ", cal=" << std::setw(4) << f.calories
        << ", sug=" << std::setw(6) << std::fixed << std::setprecision(1) << f.sugar
        << ", fib=" << f.fiber
        << ">";
    return os;
}


//=== Function prototypes ===

std::string print_int( const int*, const int* );
std::string print_food( const Food*, const Food* );
const int *min_int( const int*, const int*  );
const Food *min_food( const Food*, const Food* );
bool compare_sugar( const Food*, const Food* );
bool compare_calories( const Food*, const Food* );
bool compare_fiber( const Food*, const Food* );




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

/// Find and return the first occurrence of the samllest element in the range [first;last).
const int *min_int( const int* first, const int* last )
{
    // This pointer traverses the range.
    const int *it = first;

    // Loop Invariant: this pointer should always point to the smallest element throughout the execution.
    const int *smallest = first++; // The first is the smallest so far.

    // Traverse the range
    while( it != last )
    {
        // Check whether the current element is smaller than the smallest so far.
        if ( *it < *smallest )
            smallest = it; // update pointer to smallest element so far.
        it++; // Advance to the next element in the range.
    }

    return smallest;
}

/// Find and return the first occurrence of the least caloric food in the range [first;last).

/// Returns true if the first food has less sugar than the second food.
bool compare_sugar( const Food * a, const Food * b )
{
    return a->sugar < b->sugar ;
}

/// Returns true if the first food has less fiber than the second food.
bool compare_fiber( const Food * a, const Food * b )
{
    return a->fiber < b->fiber ;
}

/// Returns true if the first food has less fiber than the second food.
bool compare_calories( const Food * a, const Food * b )
{
    return a->calories < b->calories ;
}


// Note o ponteiro para função como terceiro argumento.
const Food *min_food( const Food* first, const Food* last, bool (*cmp)( const Food *, const Food * ) )
{
    // This pointer traverses the range.
    const Food *it = first;

    // Loop Invariant: this pointer should always point to the smallest element throughout the execution.
    const Food *smallest = first++; // The first is the smallest so far.

    // Traverse the range
    while( it != last )
    {
        // Check whether the current element is smaller than the smallest so far.
        if ( cmp( it, smallest ) )
            smallest = it; // update pointer to smallest element so far.
        it++; // Advance to the next element in the range.
    }

    return smallest;
}


int main( void )
{
    // A simple array of integers.
    int A[] { 5, 6, 2, 1, 3, 7, 4 };

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
    auto result =  min_int( std::begin(A), std::end(A) );
    // Print the smallest found.
    std::cout << ">>> The smallest element in A is \"" << *result << "\"" << std::endl;

    std::cout << std::endl << std::endl;


    // Just prints out the list of food in the bag.
    std::cout << ">>> Bag: \n" << print_food(std::begin(bag), std::end(bag)) << std::endl;

    // NOTE THAT ALL CALLS TO MIN IS TO THE SAME FUNCTION, min_food(), CHANGING ONLY THE 3RD PARAMETER.
    // Find the smallest element.
    auto result2 =  min_food( std::begin(bag), std::end(bag), compare_calories );
    // Print the smallest found.
    std::cout << ">>> The least caloric food in the bag is \"" << *result2 << "\"" << std::endl;

    // Find the smallest element.
    auto result3 =  min_food( std::begin(bag), std::end(bag), compare_sugar );
    // Print the smallest found.
    std::cout << ">>> The food lowest in sugar in the bag is \"" << *result3 << "\"" << std::endl;

    // Find the smallest element.
    auto result4 =  min_food( std::begin(bag), std::end(bag), compare_fiber );
    // Print the smallest found.
    std::cout << ">>> The food with the least amount of fiber in the bag is \"" << *result4 << "\"" << std::endl;

    return EXIT_SUCCESS;
}
