#include <stdio.h>
#include "my_file.h"

int process(FILE *f, int *max_pos)
{
	int i = 1;
	int max;
	int num;

	if (f == NULL)
		return ERROR_FILE_OPEN;

	if (fscanf(f, "%d", &max) == 1)
	{
		*max_pos = i;
		while (fscanf(f, "%d", &num) == 1)
		{
			i++;
			if (num > max)
			{
				max = num;
				*max_pos = i;
			}
		}
		return EXIT_SUCCESS;
	}

	return ERROR_EMPTY_MAX;
}
