#include "sort.h"

void swap(int *a, int*b);

int partition(int *array, size_t size, int left, int right);

void lomuto_sort(int *array, size_t size, int left, int right);

/**
 *
 *
 *
 *
 *
 *
 */

int partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 *
 *
 *
 *
 */

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 *
 *
 *
 *
 *
 *
 */

void quick_sort(int *array, size_t size)
{
	if(!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
