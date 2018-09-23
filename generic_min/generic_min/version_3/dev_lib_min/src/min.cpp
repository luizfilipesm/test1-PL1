/*!
 * \file min.cpp
 * The lib source file.
 */

#include "../include/min.h"

const void *min( const void* first, const void* last, std::size_t size, MinCompare cmp )
{
    // Helper pointer that traverses the range.
    // We need to convert it from void to byte so we can apply pointer arithmetic.
    const byte *it = static_cast< const byte *>( first );

    // Loop Invariant(LI): The smallest pointer should always point to the first smallest element condidering all the elements **before** the `it` pointer.
    const byte *smallest = it; // LI is true, because the first element is the smallest so far.

    // Advance the current pointer. Remember to jump the correct amount of bytes.
    it += size;

    // Traverse the entire range.
    while( it != last )
    {
        // Check whether the current element is smaller than the smallest so far.
        if ( cmp( it, smallest ) ) // The same as: *it < *smallest ?
            smallest = it; // update pointer to smallest element so far.
        // Advance the current pointer. Remember to jump the correct amount of bytes.
        it += size;
    }
    // LI is true here also.

    return smallest;
}

