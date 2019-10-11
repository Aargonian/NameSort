// Created by Aaron on 10/6/2019.

#ifndef TEST_NAME_STRING_H
#define TEST_NAME_STRING_H

#include <stdint.h>

#define MAX_STR_SIZE 255
typedef uint_least8_t strlen_t;

/*
 * C Doesn't define any standard string structure, so we'll make a simple one of
 * our own. This string struct currently only support ascii character strings,
 * so names using international characters currently won't work correctly.
 *
 * Name strings are arbitrarily capped at a length of 255, as that should fit
 * almost all reasonable names. The 256th value is reserved for the null byte.
 * In the off chance that this struct is ever initiated with a string larger
 * than 255 characters, the string shall be truncated to make room for the null
 * byte.
 */
typedef struct NAME_STR
{
    char *c_str;
    strlen_t len;
} string;

string *create_from_cstr(const char *str);
void destroy_string(string *str);
string *strip(string *str);

int compare_on_length(const string *str, const string *other);
int compare_on_alphabet(const string *str, const string *other);

#endif
