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
    if (argc != 3)
        return COUNT_ARGS_ERROR;

    if (strcmp(argv[1], "c") == 0)
    {
        FILE *new_f;
        new_f = fopen(argv[2], "wb");
        if (create_binary_file(new_f) == FILE_OPEN_ERROR)
            return FILE_OPEN_ERROR;
        fclose(new_f);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        FILE *read_f;
        read_f = fopen(argv[2], "rb");
        int result = print_binary_file(read_f);
        if (result == FILE_OPEN_ERROR)
            return FILE_OPEN_ERROR;
        fclose(read_f);
        if (result == FILE_SEEK_ERROR)
            return FILE_SEEK_ERROR;
    }
    else if (strcmp(argv[1], "s") == 0)
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

















