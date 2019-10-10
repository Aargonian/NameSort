#ifndef NAMESORT_STRING_VECTOR_H
#define NAMESORT_STRING_VECTOR_H

#include <stdint.h>
#include <name_string.h>

#define MIN_VEC_SIZE 8

//stdint guarantees the least types, unlike the standard uint32_t;
typedef uint_least32_t uint32;

//Simple vector implementation for our strings
typedef struct str_vector
{
    string **array;
    uint32 size;
    uint32 _capacity;
} string_vector;

string_vector *create_vector(uint32 capacity);
void vector_add(string_vector *vector, string *str);
void vector_print(string_vector *vector);

#endif //NAMESORT_STRING_VECTOR_H
