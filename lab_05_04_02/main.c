#include "my_file.h"

#define ARG_POS_ERROR 53

int main(int argc, char **argv)
{
    if (argc <  2 || argc > 4)
        return COUNT_ARGS_ERROR;

    if (argc == 4 && strcmp(argv[1], "sb") == 0)
    {
        FILE *f_src;
        FILE *f_dst;

        f_src = fopen(argv[2], "rb");
        f_dst = fopen(argv[3], "wb+");

        if (f_src == NULL || f_dst == NULL)
            return FILE_OPEN_ERROR;

        int result = file_insert_bin(f_src, f_dst);
        if (result)
        {
            fclose(f_dst);
            fclose(f_src);
            return FILE_INSERT_ERROR;
        }

        fclose(f_src);

        result = file_sort_bin(f_dst);

        if (result)
        {
            fclose(f_dst);
            return FILE_SORT_ERROR;
        }

        fclose(f_dst);
    }
    else if (argc == 4 && strcmp(argv[1], "fb") == 0)
    {
        FILE *f;

        f = fopen(argv[2], "rb");

        if (f == NULL)
            return FILE_OPEN_ERROR;

        int result = file_find_print_str(f, argv[3]);

        if (result)
        {
            fclose(f);
            return FILE_FIND_ERROR;
        }
        fclose(f);
    }
    else if (argc == 3 && strcmp(argv[1], "ab") == 0)
    {
        FILE *f;
        items_t item;
        memset(&item, 0, sizeof(items_t));

        f = fopen(argv[2], "rb+");
        
        if (f == NULL)
            return FILE_OPEN_ERROR;

        if (items_scan(&item))
            return SCAN_ERROR;

        int result = insert_items(f, item);

        if (result)
        {
            fclose(f);
            return FILE_ADD_ERROR;    
        }    
        fclose(f);
    }
    else 
        return ARG_POS_ERROR;

    return EXIT_SUCCESS;
}


