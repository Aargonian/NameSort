#include <stdio.h>
#include <stdlib.h>

#include <file_io.h>

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
        string *str = strip(create_from_cstr(line));
        free(line);
        if(str->len == 0)
        {
            destroy_string(str);
            continue;
        }
        vector_add(vector, str);
    }
}