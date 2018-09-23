#include "gbsearch.h"

typedef unsigned char byte;


void* gbsearch( const void *key, const void *ptr, size_t count, size_t size,
               bool (*comp)(const void*, const void*) )
{
    size_t left{0};
    size_t right{count-1}; // [left;right]

    byte *A = (byte*) ptr;

    // Enquanto houver elementos no range para serem investigados.
    while( left <= right )
    {
        size_t mid = (left+right)/2;

        //if( ptr[mid] == key ) return mid;
        // if ( ! comp( ptr[mid], key ) and ! comp( key, ptr[mid] ) ) return mid;:e 
        if ( not comp( (A + mid*size) , key) and
             not comp( key, (A + mid*size) ) ) // A[mid] == key
            return A + mid*size;
        // else if ( key < A[mid] )
        else if  ( comp( key, (A + mid*size))) right = mid-1; // go left
        else left = mid+1; // go left.
    }

    return nullptr;
}