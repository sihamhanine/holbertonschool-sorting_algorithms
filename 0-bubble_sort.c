#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * bubble_sort - Function  that sorts an array of
 * integers in ascending order
 * @array: the array to print
 * @size: the size of array
 */ 
void bubble_sort(int *array, size_t size)
{
  int temp;
  size_t i, k;
  if (array == NULL || size == 0)
    {
      return;
    }
  i = 0;
  while (i < size)
    {
      for (k = 0; k < size - 1; k++)
	{
	  if (array[k] > array[k + 1])
	    {
	      temp = array[k];
	      array[k] = array[k + 1];
	      array[k + 1] = temp;
	      print_array(array, size);
	    }
	}
      i++;
    }
}
