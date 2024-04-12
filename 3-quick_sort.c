#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* swap - Function that swap 2 int values
* @array: the array of integer to sort
* @a: the pointer to integer to swap
* @b: the pointer to integer to swap to
* @size: the size of array
*/
void swap(int *array, int *a, int *b, size_t size)
{
if (*a != *b)
{
*a = *a + *b;
*b = *a - *b;
*a = *a - *b;
print_array((const int *)array, size);
}
}

/**
* lomuto_partition - partitions the array
* @array: the array of integer to sort
* @size: the size of array
* @bas: the low index of the sort range
* @haut: the hight index of the sort range
* Return: size_t
*/
size_t lomuto_partition(int *array, ssize_t bas, ssize_t haut, size_t size)
{
int i, j, pivot = array[haut];
for (i = j = bas; j < haut; j++)
{
if (array[j] < pivot)
{
swap(array, &array[j], &array[i], size);
i++;
}
}
swap(array, &array[i], &array[haut], size);
return (i);
}
/**
* quicksort - Function that partitionning via lomuto
* @array: the array of integer to sort
* @size: the size of array
* @bas: the low index of the sort range
* @haut: the hight index of the sort range
*/
void quicksort(int *array, ssize_t bas, ssize_t haut, size_t size)
{
if (bas < haut)
{
size_t p = lomuto_partition(array, bas, haut, size);
quicksort(array, bas, p - 1, size);
quicksort(array, p + 1, haut, size);
}
}

/**
* quick_sort - Function that sorts an array of
* integers in ascending order
* @array: the array to print
* @size: the size of array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size == 0)
return;
quicksort(array, 0, size - 1, size);
}
