#include "sort.h"

void swap(int *a, int *b);

int partition(int *array, size_t size, int left, int right);

void lomuto_sort(int *array, size_t size, int left, int right);

/**
 * partition - creates a partition for sorting
 * @array: pointer to the array
 * @size: size of the array
 * @left: left most index of the given partition array
 * @right: right most index of the given partition array
 *
 * Return: int, index of the new partition.
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
 * swap - swaps two ints inside an array
 * @a: first int
 * @b: second int
 *
 * Return: void, returns a null void pointer
 */

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * lomuto_sort - lomuto partition scheme sort
 * @array: pointer to array to sort
 * @size: size of the array
 * @left: left most index of the array to sort
 * @right: right most index of the array to sort
 *
 * Return: void, returns a null void pointer
 */

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
 * quick_sort - sorts an array using quick sort, lomuto partition scheme
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void, returns a null void pointer
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
