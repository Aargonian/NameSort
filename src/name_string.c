//
// Created by Aargo on 10/6/2019.
//

#include <name_string.h>
#include <stdlib.h>

string *create_from_cstr(const char *str)
{
    string *new_str = (string *) malloc(sizeof(string));
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
    new_str->c_str = (char *) malloc(sizeof(char) * size + 1);
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

static int is_whitespace(char c)
{
    if(c == ' ' || c == '\t' || c == '\n' || c == '\v')
    {
        return 1;
    }
    return 0;
}

string *strip(string *str)
{
    //Sanity check
    if(!str || !str->c_str || str->len == 0)
    {
        return str;
    }
    //Strip the left side
    strlen_t lstrip_index = 0;
    for(strlen_t index = 0; index < str->len; index++)
    {
        if(is_whitespace(str->c_str[index]))
        {
            lstrip_index++;
        }
        else
        {
            break;
        }
    }

    //Find right side strip index
    strlen_t rstrip_index = str->len;
    for(strlen_t index = str->len - 1; index >= 0; index--)
    {
        if(is_whitespace(str->c_str[index]))
        {
            rstrip_index--;
        }
        else
        {
            break;
        }
    }

    if(lstrip_index == rstrip_index)
    {
        free(str->c_str);
        str->c_str = NULL;
        str->len = 0;
    }
    else
    {
        strlen_t chop_off = lstrip_index + (str->len - rstrip_index);
        char *new = malloc(sizeof(char) * (str->len - chop_off + 1));
        for(strlen_t index = lstrip_index; index < rstrip_index; index++)
        {
            new[index - lstrip_index] = str->c_str[index];
        }
        new[rstrip_index - lstrip_index] = '\0';
        free(str->c_str);
        str->c_str = new;
        str->len -= chop_off;
    }
    return str;
}

int compare_on_length(const string *str, const string *other)
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
    return (char) (c + 32);
}

int compare_on_alphabet(const string *str, const string *other)
{
    strlen_t min_len = min(str->len, other->len);
    for(strlen_t index = 0; index < min_len; index++)
    {
        char str_lower_char = lowercase(str->c_str[index]);
        char other_lower_char = lowercase(other->c_str[index]);
        if(str_lower_char < other_lower_char)
        {
            return -1;
        }
        else if(str_lower_char > other_lower_char)
        {
            return 1;
        }
    }
    //Only difference is length
    return compare_on_length(str, other);
}