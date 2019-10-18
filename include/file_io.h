//
// Created by Aargo on 10/17/2019.
//

#ifndef NAMESORT_FILE_IO_H
#define NAMESORT_FILE_IO_H

#include <string_vector.h>

char *read_line(FILE *file, int *eof_reached);
void read_file_into_vector(FILE *file, string_vector *vector);

#endif //NAMESORT_FILE_IO_H
