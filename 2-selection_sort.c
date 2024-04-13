#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
* selection_sort - sorts an array of integers using
* the selection sort algorithm.
* @array: the array of integers to be sorted
* @size: the size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		k = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}

		if (k != i)
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}
