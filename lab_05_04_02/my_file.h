#ifndef __MY_FILE_H__

#define __MY_FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdbool.h>

#define COUNT_ARGS_ERROR 1
#define FILE_OPEN_ERROR 2
#define SIZE_FILE_ERROR 3
#define FILE_SORT_ERROR 4
#define FILE_SEEK_ERROR 5
#define STR_INPUT_ERROR 6
#define FILE_WRITE_ERROR 7
#define FILE_GET_ERROR 8
#define FILE_PUT_ERROR 9
#define STR_SCAN_ERROR 10
#define TOO_LONG_STR_ERROR 11
#define EMPTY_STR_ERROR 12
#define SCAN_ERROR 13
#define ZERO_LEN_ERROR 14
#define NO_SUBS_ERROR 15
#define FILE_ADD_ERROR 16
#define FILE_FIND_ERROR 17
#define FILE_INSERT_ERROR 18

#define N_L 31
#define M_L 16
#define MAX_STR_LEN 32

typedef struct
{
	char name[N_L];
	char manf[M_L];
	uint32_t price;
	uint32_t quantity;
} items_t;

int file_size(FILE *f, int *size);
int get_item_by_pos(FILE *f, int pos, items_t *item);
int file_insert_bin(FILE *f_src, FILE *f_dst);
int file_sort_bin(FILE *f);
void print_file(FILE *f);
int file_find_print_str(FILE *f, char subs[]);
void file_print_info(items_t item);
void swap_items(FILE *f, int new_pos, int old_pos);
int insert_items(FILE *f, items_t item);
int items_scan(items_t *item);
int is_greater_item(items_t item1, items_t item2);

#endif
