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

double dispersion_point(FILE *f, char str[], double means)
{
	double sum = 0.0;
	double tmp;
	size_t quantity = 0;

	f = fopen(str, "r");

	while (fscanf(f, "%lf", &tmp) == 1)
	{
		sum += (tmp - means) * (tmp - means); 
		quantity++;
	}

	fclose(f);

	return sum / quantity;
}
