#include <stdio.h>
#include <stdlib.h>
#include <name_string.h>
#include <string_vector.h>

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

char *read_line(FILE *file, int *eof_reached)
{
    char *lineBuffer = malloc(sizeof(char) * MAX_STR_SIZE + 1);

    int ch = getc(file);
    int count = 0;
    while((ch != '\n') && (ch != EOF))
    {
        if(count == MAX_STR_SIZE)
        {
            fprintf(stderr,
                    "Encounted name that is too long. Max name length is %d!\n",
                    MAX_STR_SIZE);
            exit(2);
        }
        lineBuffer[count] = (char)ch;
        count++;
        ch = getc(file);
    }
    if(ch == EOF)
    {
        *eof_reached = 1;
    }
    lineBuffer[count] = '\0';
    return lineBuffer;
}

void read_file_into_vector(FILE *file, string_vector *vector)
{
    if(!file || !vector)
    {
        fprintf(stderr, "Invalid File Or Memory Error\n");
        return;
    }
    int eof_reached = 0;
    while(!eof_reached)
    {
        char *line = read_line(file, &eof_reached);
        string *str = create_from_cstr(line);
        free(line);

        strip(str);
        if(str->len == 0)
        {
            destroy_string(str);
            continue;
        }
        vector_add(vector, str);
    }
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: name_sort <input_file>\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");

    string_vector *vector = create_vector(0);
    read_file_into_vector(file, vector);

    perform_length_alphabet_sort(vector);
    vector_print(vector);
    return 0;
}
