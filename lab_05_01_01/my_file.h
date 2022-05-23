#ifndef __MY_FILE_H__

#define __MY_FILE_H__

#include <stdbool.h>
#include <stdlib.h>

#define FILE_OPEN_ERROR -1
#define EMPTY_ANSWER_ERROR -2

int process(FILE *f, int *pre_max, int *max);

#endif
