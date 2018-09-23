#ifndef _GBSEARCH_H_
#define _GBSEARCH_H_

#include <cstdlib> // size_t

void* gbsearch( const void *key, const void *ptr, size_t count, size_t size,
               bool (*comp)(const void*, const void*) );

#endif