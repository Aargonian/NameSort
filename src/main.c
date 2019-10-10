#include <stdio.h>
#include <stdlib.h>
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

string_vector *create_vector(uint32 capacity)
{
    if(capacity < MIN_VEC_SIZE)
    {
        capacity = MIN_VEC_SIZE;
    }
    string_vector *vec = malloc(sizeof(string_vector));
    vec->array = malloc(sizeof(string *) * capacity);
    vec->size = 0;
    vec->_capacity = capacity;
    return vec;
}

/*
 * For our particular program, we don't need the ability to remove items from
 * the vector, as we'll only ever be adding to it.
 */
void vector_add(string_vector *vector, string *str)
{
    if(vector->size == vector->_capacity)
    {
        string **new_array = malloc(sizeof(string *) * vector->_capacity * 2);
        for(uint32 index = 0; index < vector->_capacity; index++)
        {
            new_array[index] = vector->array[index];
        }
        free(vector->array);
        vector->array = new_array;
        vector->_capacity *= 2;
    }
    vector->array[vector->size] = str;
    vector->size++;
}

void print_vector(string_vector *vector)
{
    for(uint32 index = 0; index < vector->size; index++)
    {
        printf("%s", vector->array[index]->c_str);
    }
}

/*
 * Compare function to be used by qsort. Due to the implementation in the C
 * Standard Library, this function necessarily accepts void * and must cast to
 * the type it expects.
 */
int compare(const void *str1, const void *str2)
{
    const string *first = *(const string **) str1;
    const string *second = *(const string **) str2;

    int res = compare_on_length(first, second);
    if(res == 0)
    {
        return compare_on_alphabet(first, second);
    }
    return res;
}

/*
 * Sorts the passed vector with the rules that:
 * 1. Strings are sorted by length first, not alphabet.
 * 2. Strings are sorted by alphabet only if they are the same length.
 */
void perform_length_alphabet_sort(string_vector *vector)
{
    qsort((void *) vector->array, vector->size, sizeof(string *), compare);
}

int main(int argc, char **argv)
{
    char *tests[10] = {
            "What    ",
            "Where",
            "  When",
            "  Why  ",
            "How",
            "Test1",
            "Test2",
            "Anne",
            "Jill",
            "Bob"
    };

    string_vector *vector = create_vector(0);

    for(uint32 index = 0; index < 10; index++)
    {
        string *str = create_from_cstr(tests[index]);
        strip(str);
        vector_add(vector, str);
    }

    print_vector(vector);
    perform_length_alphabet_sort(vector);
    printf("\nSorted Array\n------------\n");
    print_vector(vector);

    return 0;
}
