/*!
 * \file driver_min.cpp
 * This is the initial version.
 */

#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>

//=== Function prototypes ===
const int *min_int( const int*, const int*  );
std::string print_int( const int*, const int* );



/// Extracting the array information to a stream.
std::string print_int( const int* first, const int* last )
{
    std::ostringstream oss;
    while( first != last )
        oss << *first++ << " ";

    return oss.str();
}

/// Find and return the first occurence of the smallest element in a range of integers.
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



/// The application.
int main( void )
{
    // A simple array of integers.
    int A[] { 5, 6, 2, 1, 3, 7, 4 };

    // Prints out the integer array.
    std::cout << ">>> A = [" << print_int(std::begin(A), std::end(A)) << "]" << std::endl;
    // Find the smallest element.
    auto result =  min_int( std::begin(A), std::end(A) );
    // Print the smallest found.
    std::cout << ">>> The smallest element in A is \"" << *result << "\"" << std::endl;

    return EXIT_SUCCESS;
}
