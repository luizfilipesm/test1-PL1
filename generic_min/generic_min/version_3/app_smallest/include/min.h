/*!
 * \file min.h
 * The header for the min() function and aliases.
 */

#ifndef _MIN_H_
#define _MIN_H_

#include <cstdlib> // need for std::size_t

//=== Function prototypes ===

/// An alias to make the prototype easier to understand.
typedef bool (*MinCompare)( const void *, const void * );

/// An alias to allow for pointer arithmetic.
typedef unsigned char byte;

/// Finds and returns the first occurrence of the minimum element in the range, based on a comparison function.
/*!
 * \param first Address of the beginning of the range on which the operation takes place.
 * \param last Address of the location past-the-end of the range on which the operation takes place.
 * \size The size, in bytes, of an item of the range.
 * \cmp A comparison function that returns true if the first argumento is **less** than the second, based on a criteria defined by the client. Otherwise, the function returns false.
 *
 * \return A pointer to the address of the first occurrence of the minimum element in the range.
 */
const void * min( const void *first, const void *last, std::size_t size, MinCompare cmp );

#endif
