#include <stdio.h>
#include "my_file.h"

int main(void) 
{
    int pos;
    FILE *f = stdin;
    int result = process(f, &pos);

    if (result == ERROR_FILE_OPEN)
        return ERROR_FILE_OPEN;
    else if (result == ERROR_EMPTY_MAX)
        return ERROR_EMPTY_MAX;

    printf("%d\n", pos);

    fclose(f);

    return EXIT_SUCCESS;
}
