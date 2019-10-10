//
// Created by Aaron on 10/10/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <string_vector.h>

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

void vector_print(string_vector *vector)
{
    for(uint32 index = 0; index < vector->size; index++)
    {
        printf("%s\n", vector->array[index]->c_str);
    }
}

void destroy_vector(string_vector *vector)
{
    if(vector)
    {
        if(vector->array)
        {
            for(uint32 index = 0; index < vector->size; index++)
            {
                if(vector->array[index])
                {
                    free(vector->array[index]);
                    vector->array[index] = NULL;
                }
            }
            free(vector->array);
            vector->array = NULL;
        }
        free(vector);
    }
}