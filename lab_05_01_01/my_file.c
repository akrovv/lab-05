#include <stdio.h>
#include "my_file.h"

int process(FILE *f, int *pre_max, int *max)
{
	int tmp;

	if (f == NULL)
		return FILE_OPEN_ERROR;

	if (fscanf(f, "%d", pre_max) == 1 && fscanf(f, "%d", max) == 1)
	{
		if (*pre_max > *max)
		{
			tmp = *pre_max;
			*pre_max = *max;
			*max = tmp;
		}
		while (fscanf(f, "%d", &tmp) == 1)
		{
			bool flag = false;
			if (tmp > *max)
			{	
				flag = true;
				*pre_max = *max;
				*max = tmp;
			}
			if (tmp > *pre_max && !flag)
				*pre_max = tmp;
		}
		return EXIT_SUCCESS;
	}

	return EMPTY_ANSWER_ERROR;
}
