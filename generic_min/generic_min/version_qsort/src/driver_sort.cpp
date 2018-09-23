/*!
 * \file driver_sort.cpp
 * This app sorts arrays with qsort().
 */

#include <cstdlib>

#include "../include/driver_sort.h"

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

// TODO: change function to be compatble with qsort()
bool compare_sugar( const void * a, const void * b )
{
    return static_cast<const Food *>(a)->sugar < static_cast<const Food*>(b)->sugar ;
}


// TODO: change function to be compatble with qsort()
bool compare_fiber( const void * a, const void * b )
{
    return static_cast<const Food *>(a)->fiber   <  static_cast< const Food *>(b)->fiber ;
}

/// Returns -1 if the first food has less fiber than the second food, 0  if the are the same, +1 otherwise.
// TODO: change function to be compatble with qsort()
bool compare_calories( const void * a, const void * b )
{
    return static_cast<const Food *>(a)->calories < static_cast<const Food *>(b)->calories ;
}


int compare_ints( const void * aa, const void * bb )
{
    const int *a = static_cast< const int *> (aa);
    const int *b = static_cast< const int *> (bb);
    if ( *a < *b ) return -1;
    else if ( *a > *b ) return 1;
    else return 0;
}

int main( void )
{
    // A simple array of integers.
    int A[] { 5, 6, 2, 1, 3, 7, 4 };
    constexpr std::size_t length = sizeof A / sizeof *A;

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
    //qsort( A, sizeof(A)/sizeof(A[0]), sizeof(A[0]), compare_ints );
    std::qsort( A, length, sizeof *A, compare_ints );
    std::cout << ">>> A (AFTER SORTING) = [" << print_int(std::begin(A), std::end(A)) << "]" << std::endl;

    std::cout << std::endl << std::endl;


    // Just prints out the list of food in the bag.
    std::cout << ">>> Bag: \n" << print_food(std::begin(bag), std::end(bag)) << std::endl;
    // TODO: call qsort() here!
    // qsort(...)
    std::cout << ">>> Bag (AFTER SORTING): \n" << print_food(std::begin(bag), std::end(bag)) << std::endl;


    return EXIT_SUCCESS;
}
