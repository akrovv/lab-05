#include <stdio.h>
#include "my_file.h"

int main(void) 
{
    int pre_max;
    int max;
    FILE *f = stdin;
    int result = process(f, &pre_max, &max);

    if (result == FILE_OPEN_ERROR)
        return FILE_OPEN_ERROR;
    else if (result == EMPTY_ANSWER_ERROR)
        return EMPTY_ANSWER_ERROR;

    printf("%d\n", max);
    printf("%d\n", pre_max);

    return EXIT_SUCCESS;
}
