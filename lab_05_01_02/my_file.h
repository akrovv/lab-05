#ifndef __MY_FILE_H__

#define __MY_FILE_H__

#include <stdbool.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -1
#define ERROR_EMPTY_MAX -2

int process(FILE *f, int *max_pos);

#endif
