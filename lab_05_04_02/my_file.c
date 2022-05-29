#include "my_file.h"

void file_print_info(items_t item)
{
    printf("%s\n", item.name);
    printf("%s\n", item.manf);
    printf("%"PRIu32, item.price);
    printf("\n");
    printf("%"PRIu32, item.quantity);
    printf("\n");
}

int items_scan(items_t *item)
{
    if (!scanf("%s", item->name))
        return EXIT_FAILURE;
    if (!scanf("%s", item->manf))
        return EXIT_FAILURE;
    if (!scanf("%"SCNu32, &item->price))
        return EXIT_FAILURE;
    if (!scanf("%"SCNu32, &item->quantity))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int file_size(FILE *f, int *size)
{
    if (fseek(f, 0, SEEK_END) != 0)
        return EXIT_FAILURE;

    int rc = ftell(f);

    if (rc <= 0)
        return EXIT_FAILURE;

    *size = rc / sizeof(items_t);

    return fseek(f, 0, SEEK_SET);;
}

int get_item_by_pos(FILE *f, int pos, items_t *item)
{
    if (fseek(f, pos * sizeof(items_t), SEEK_SET) == 0)
        if (fread(item, sizeof(items_t), 1, f) == 1)
            return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int put_item_by_pos(FILE *f, int pos, items_t *item)
{
    if (fseek(f, pos * sizeof(items_t), SEEK_SET) == 0)
        if (fwrite(item, sizeof(items_t), 1, f) == 1)
            return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int file_insert_bin(FILE *f_src, FILE *f_dst)
{
    items_t item;

    int size;

    if (file_size(f_src, &size))
        return SIZE_FILE_ERROR;

    for (int i = 0; i < size; i++)
    {
        if (get_item_by_pos(f_src, i, &item))
            return FILE_GET_ERROR;
        file_print_info(item);
        if (fwrite(&item, sizeof(items_t), 1, f_dst) != 1)
            return FILE_WRITE_ERROR;
    }
    
    return EXIT_SUCCESS;
}

int file_sort_bin(FILE *f)
{
    int size;

    items_t item1, item2;

    if (file_size(f, &size))
        return SIZE_FILE_ERROR;

    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
        {
            if (get_item_by_pos(f, i, &item1) || get_item_by_pos(f, j, &item2))
                return FILE_GET_ERROR;

            if (is_greater_item(item2, item1))
                if (put_item_by_pos(f, j, &item1) || put_item_by_pos(f, i, &item2))
                    return FILE_PUT_ERROR;
        }
    return EXIT_SUCCESS;
}

int is_greater_item(items_t item1, items_t item2)
{
    return item1.price > item2.price || (item1.price == item2.price && item1.quantity > item2.quantity);
}

int file_find_print_str(FILE *f, char subs[])
{
    bool flag = false;
    int subs_len = strlen(subs);
    int size;
    items_t item;

    if (subs_len == 0)
        return ZERO_LEN_ERROR;

    if (file_size(f, &size))
        return SIZE_FILE_ERROR;

    for (int i = 0; i < size; i++)
    {
        if (get_item_by_pos(f, i, &item))
            return FILE_GET_ERROR;
    
        int name_len = strlen(item.name);
        if (name_len >= subs_len)
        {
            int diff_len = name_len - subs_len;
            if (!strcmp(item.name + diff_len, subs))
            {
                flag = true;
                file_print_info(item);
            }
        }
    }

    if (flag)
        return EXIT_SUCCESS;

    return NO_SUBS_ERROR;
}

int insert_items(FILE *f, items_t item)
{
    items_t item1;
    int i;
    int size;

    if (file_size(f, &size))
        return SIZE_FILE_ERROR;

    for (i = 0; i < size; ++i)
    {
        get_item_by_pos(f, i, &item1);

        if ((is_greater_item(item, item1)))
            break;
    }

    for (int j = size - 1; j >= i; j--)
    {
        get_item_by_pos(f, j, &item1);
        put_item_by_pos(f, j + 1, &item1);
    }

    put_item_by_pos(f, i, &item);

    return EXIT_SUCCESS;
}
































