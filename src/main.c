#include <stdio.h>
#include <stdlib.h>
#include <file_io.h>
#include <name_string.h>
#include <string_vector.h>

#define ASCENDING 1
#define DESCENDING 0

// Nasty global variable needed here as there is no other way to pass state to the compare function.
// This variable should be kept static so no other unit may see it.
static int global_sort_order = ASCENDING;

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
    if(0 == res)
    {
        return compare_on_alphabet(first, second);
    }

    // The user may have requested we sort in the other direction on length
    if(global_sort_order == DESCENDING)
    {
        res = -res;
    }
    return res;
}

/*
 * Sorts the passed vector with the rules that:
 * 1. Strings are sorted by length first, not alphabet.
 * 2. Strings are sorted by alphabet only if they are the same length.
 */
void perform_length_alphabet_sort(string_vector *vector, int ascending)
{
    if(!ascending)
    {
        global_sort_order = DESCENDING;
    }
    qsort((void *) vector->array, vector->size, sizeof(string *), compare);
}

void print_usage()
{
    fprintf(stderr, "Usage: name_sort [-d|--descending] <input_file>\n");
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        print_usage();
        return 1;
    }

    int ascending = 1;
    int double_dash_found = 0;
    string *long_descending_option = create_from_cstr("descending");

    //Parse our command line options
    size_t option_index;
    for(option_index = 1; option_index < argc && argv[option_index][0] == '-' && !double_dash_found; option_index++)
    {
        switch(argv[option_index][1]) {
            case 'd': ascending = 0; break;
            case '-':
                if(argv[2] == '\0') {
                    //Double Dash with no other characters is traditional unix symbol of no more options, so we stop.
                    double_dash_found = 1;
                } else {
                    string *option = create_from_cstr(argv[2]); //Pass in the remainder of the string
                    if(compare_on_alphabet(option, long_descending_option) == 0)
                    {
                        ascending = 1;
                    }
                    else
                    {
                        print_usage();
                        return 1;
                    }
                }
                break;
            default:
                print_usage();
                return 1;
        }
    }

    // At the end of our loop, option_index should be pointing to all non-option arguments. In this case it should
    // only be one argument.
    if(option_index != argc-1)
    {
        print_usage();
        return 1;
    }
    char *input_file = argv[option_index];
    FILE *file = fopen(input_file, "r");
    string_vector *vector = create_vector(0);
    read_file_into_vector(file, vector);
    perform_length_alphabet_sort(vector, ascending);
    vector_print(vector);
    destroy_vector(vector);
    fclose(file);
    return 0;
}
