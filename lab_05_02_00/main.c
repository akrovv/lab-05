#include <stdio.h>
#include <stddef.h>
#include "my_file.h"

#define COUNT_ARGS_ERROR 1

int main(int argc, char **argv) 
{
    FILE *f = NULL;
    double result_means;

    if (argc < 2 || argc > 2)
        return COUNT_ARGS_ERROR;

    if (!is_correct_name(*(argv + 1)))
        return FILE_OPEN_ERROR;

    result_means = arithmetic_means(f, *(argv + 1));

    if (isnan(result_means))
        return EMPTY_FLOAT_DIGITS_ERROR;

    printf("%6lf\n", closest_digit(f, *(argv + 1), result_means));    

    return EXIT_SUCCESS;
}
