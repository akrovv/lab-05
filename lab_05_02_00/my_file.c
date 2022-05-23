#include <stdio.h>
#include "my_file.h"

bool is_correct_name(char str[])
{
	return (fopen(str, "r") == NULL) ? false : true;
}

double arithmetic_means(FILE *f, char str[])
{
	double tmp;
	double sum = 0.0;
	size_t quantity = 0;

	f = fopen(str, "r");

	while (fscanf(f, "%lf", &tmp) == 1)	
	{
		sum += tmp; 
		quantity++;
	}

	fclose(f);

	return sum / quantity;
}

// Функция ищет число максимально близкое к среднему арифметическому

double closest_digit(FILE *f, char str[], double means)
{
	double max_difference;
	double tmp;
	double max;

	f = fopen(str, "r");

	fscanf(f, "%lf", &max);

	max_difference = fabs(means - max);

	while (fscanf(f, "%lf", &tmp) == 1)
	{
		if (fabs(means - tmp) < max_difference)
		{
			max_difference = fabs(means - tmp);
			max = tmp;
		}
	}

	fclose(f);

	return max;
}
