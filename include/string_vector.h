#ifndef NAMESORT_STRING_VECTOR_H
#define NAMESORT_STRING_VECTOR_H

#include <name_string.h>

/*
 * Simple vector implementation for our strings
 *
 * Vectors assume complete ownership of the items they handle, so when the
 * vector is destroyed, all of its strings will be destroyed with it.
 */
typedef struct str_vector
{
    string **array;
    uint32 size;
    uint32 _capacity;
} string_vector;

string_vector *create_vector(uint32 capacity);
void vector_add(string_vector *vector, string *str);
void vector_print(string_vector *vector);
void destroy_vector(string_vector *vector);

#endif //NAMESORT_STRING_VECTOR_H
