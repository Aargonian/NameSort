//
// Created by Aargo on 10/6/2019.
//

#include <name_string.h>
#include <stdlib.h>

string *create_from_cstr(const char *str)
{
    string *new_str = (string *)malloc(sizeof(string));
    if(!str)
    {
        //The passed c string is a null or invalid pointer.
        new_str->c_str = NULL;
        new_str->len = 0;
        return new_str;
    }

    strlen_t index; //Declare outside of loop for reuse
    strlen_t size = 0;
    for(index = 0; index < MAX_STR_SIZE && str[index] != '\0'; index++)
    {
        size++;
    }

    //Make sure to +1 for the null byte at the end
    new_str->c_str = (char *)malloc(sizeof(char)*size + 1);
    for(index = 0; index < size && *str != '\0'; index++)
    {
        new_str->c_str[index] = str[index];
    }
    new_str->c_str[index] = '\0';
    new_str->len = index; //Note that len does not include the null byte
    return new_str;
}

void destroy_string(string *str)
{
    if(str)
    {
        if(str->c_str)
        {
            free(str->c_str);
        }
        str->c_str = 0;
    }
    free(str);
}

string *concatenate_string(string *str, string *other)
{
    if(!str || !other)
        return NULL;
    if(str->len + other->len > MAX_STR_SIZE)
        return NULL;

    strlen_t total_len = str->len + other->len;

    string *new_str = (string *)malloc(sizeof(string));
    new_str->c_str = (char *)malloc(sizeof(char)*total_len + 1);
    new_str->len = total_len;

    for(strlen_t index = 0; index < str->len; index++)
    {
        new_str->c_str[index] = str->c_str[index];
    }
    for(strlen_t index = 0; index < other->len; index++)
    {
        new_str->c_str[index+str->len] = other->c_str[index];
    }
    new_str->c_str[total_len] = '\0';
    return new_str;
}

int compare_on_length(string *str, string *other)
{
    if(str->len < other->len)
    {
        return -1;
    }
    else if(str->len > other->len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 * This function takes advantage of the fact that in ASCII, a-z and A-Z are
 * always 32 values apart. This will NOT work for other character sets, but few
 * systems use anything other than ASCII and Unicode. This happens to work with
 * Unicode characters as well, but that is merely a happy accident of the spec.
 *
 * If compiling on a EBCDIC system or anything else that uses a different
 * default character encoding, you'll need to either chance this code or
 * re-encode all text.
 */
static char lowercase(char c)
{
    if(c < 'A' || c > 'Z')
    {
        return c;
    }
    return (char)(c-32);
}

int compare_on_alphabet(string *str, string *other)
{
    strlen_t min_len = min(str->len, other->len);
    for(strlen_t index = 0; index < min_len; index++)
    {
        char str_lower_char = lowercase(str->c_str[index]);
        char other_lower_char = lowercase(other->c_str[index]);
        if(str_lower_char < other_lower_char)
            return -1;
        else if(str_lower_char > other_lower_char)
            return 1;
    }
    //Only difference is length
    return compare_on_length(str, other);
}