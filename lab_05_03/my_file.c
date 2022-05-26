#include "my_file.h"

#define N_MAX 1000

int create_binary_file(FILE *f, char digits[])
{
	if (f == NULL)
		return FILE_OPEN_ERROR;

	if (!atoi(digits))
		return INCORRECT_DIGIT_ERROR;

	int digit = atoi(digits);

	srand(time(NULL));

	for (int i = 0; i < digit; i++)
	{
		int rc = rand() % N_MAX;
		if (fwrite(&rc, sizeof(int), 1, f) != 1)
			return FILE_WRITE_ERROR;
	}

	return EXIT_SUCCESS;
}

int file_size(FILE *f, int *size)
{
	if (fseek(f, 0L, SEEK_END) != 0)
		return EXIT_FAILURE;

	int rc = ftell(f);

	if (rc <= 0 || rc % (long) sizeof(int) != 0)
		return EXIT_FAILURE;

	*size = rc;

	return fseek(f, 0L, SEEK_SET);
}

int print_binary_file(FILE *f)
{
	if (f == NULL)
		return FILE_OPEN_ERROR;

	int size;
	int num;

	if (!fseek(f, 0L, SEEK_SET))
	{
		if (!file_size(f, &size))
		{
			for (int i = 0; i < size / (int) sizeof(int); i++)
				if (fread(&num, sizeof(int), 1, f) == 1)
					printf("%d\n", num);
				else
					break;

			return EXIT_SUCCESS;
		}
		return SIZE_FILE_ERROR;
	}
	return FILE_SEEK_ERROR;
}

int get_number_by_pos(FILE *f, int pos, int *num)
{
	if (fseek(f, pos * sizeof(int), SEEK_SET) == 0)
		if (fread(num, sizeof(int), 1, f) == 1)
			return EXIT_SUCCESS;

	return EXIT_FAILURE;
}

int put_number_by_pos(FILE *f, int pos, int num)
{
	if (fseek(f, pos * sizeof(int), SEEK_SET) == 0)
		if (fwrite(&num, sizeof(int), 1, f) == 1)
			return EXIT_SUCCESS;

	return EXIT_FAILURE;
}

int sort_binary_file(FILE *f)
{
	if (f == NULL)
		return FILE_OPEN_ERROR;

	int size;
	if (file_size(f, &size))
		return SIZE_FILE_ERROR;

	int len = size / (int) sizeof(int);

	for (int i = 0; i < len; i++)
	{
		int num1, num2;
		for (int j = 0; j < len - 1; j++)
		{
			if (get_number_by_pos(f, j, &num1) || get_number_by_pos(f, j + 1, &num2))
				return FILE_SORT_ERROR;	
		
			if (num1 > num2)
				if (put_number_by_pos(f, j + 1, num1) || put_number_by_pos(f, j, num2))
					return FILE_SORT_ERROR;
		}
	}

	return EXIT_SUCCESS;
}











