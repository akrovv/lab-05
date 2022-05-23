#ifndef __MY_FILE_H__

#define __MY_FILE_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define FILE_OPEN_ERROR 2
#define EMPTY_FLOAT_DIGITS_ERROR 3

bool is_correct_name(char str[]);
double arithmetic_means(FILE *f, char str[]);
double closest_digit(FILE *f, char str[], double means);

#endif
