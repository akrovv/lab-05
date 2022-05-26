/*
Основным типом данных для работы с числами был выбран int.
Типом данных для работы со строкой был выбран char **.
Алгоритм сортировки - сортировка пузырьком.
Направление упорядочивания - сверху вниз (от наименьшего до наибольшего).
*/

#include <string.h>
#include "my_file.h"

int main(int argc, char **argv) 
{
    if (argc < 3)
        return COUNT_ARGS_ERROR;

    if (strcmp(argv[1], "c") == 0 && atoi(argv[2]) && argc == 4)
    {
        FILE *new_f;
        int result;

        new_f = fopen(argv[3], "wb");
        result = create_binary_file(new_f, argv[2]);

        if (result == FILE_OPEN_ERROR)
            return FILE_OPEN_ERROR;

        fclose(new_f);

        if (result == FILE_WRITE_ERROR)
            return FILE_WRITE_ERROR;
        else if (result == INCORRECT_DIGIT_ERROR)
            return INCORRECT_DIGIT_ERROR;
    }
    else if (strcmp(argv[1], "p") == 0 && argc == 3)
    {
        FILE *read_f;

        read_f = fopen(argv[2], "rb");

        int result = print_binary_file(read_f);

        if (result == FILE_OPEN_ERROR)
            return FILE_OPEN_ERROR;

        fclose(read_f);

        if (result == FILE_SEEK_ERROR)
            return FILE_SEEK_ERROR;
        else if (result == SIZE_FILE_ERROR)
            return SIZE_FILE_ERROR;
    }
    else if (strcmp(argv[1], "s") == 0 && argc == 3)
    {
        FILE *sort_f;

        sort_f = fopen(argv[2], "r+b");

        int result = sort_binary_file(sort_f);

        if (result == FILE_OPEN_ERROR)
            return FILE_OPEN_ERROR;

        fclose(sort_f);

        if (result == FILE_SORT_ERROR)
            return FILE_SORT_ERROR;
        else if (result == SIZE_FILE_ERROR)
            return SIZE_FILE_ERROR;
    }
    else
        return ARG_POS_ERROR;

    return EXIT_SUCCESS;
}












