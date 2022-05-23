#ifndef __MY_FILE_H__

#define __MY_FILE_H__

#include <stdio.h>
#include <stdlib.h>

#define COUNT_ARGS_ERROR 1
#define ARG_POS_ERROR 2
#define FILE_OPEN_ERROR 3
#define SIZE_FILE_ERROR 4
#define FILE_SORT_ERROR 5
#define FILE_SEEK_ERROR 6

int create_binary_file(FILE *f);
int print_binary_file(FILE *f);
int file_size(FILE *f, int *size);
int get_number_by_pos(FILE *f, int pos, int *num);
int put_number_by_pos(FILE *f, int pos, int num);
int sort_binary_file(FILE *f);

#endif
