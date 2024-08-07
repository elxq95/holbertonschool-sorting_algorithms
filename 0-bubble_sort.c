#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array to be printed
 * @size: size of the the array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped != 1)
		break;
	}
}
