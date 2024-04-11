#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - Function that get swap of linked list
 * @a: the adress of first node
 * @b: the adress of second node
 */
void swap(listint_t *a, listint_t *b)
{
  if (a->prev != NULL)
    {
      a->prev->next = b;
    }
  if (b->next != NULL)
    {
      b->next->prev = a;
    }
  a->next = b->next;
  b->prev = a->prev;
  a->prev = b;
  b->next = a;
}

/**
 * insertion_sort_list - Function that sorts a doubly linked
 * list of integers in ascending order
 * @list: the list to print
 */
void insertion_sort_list(listint_t **list)
{
listint_t *i, *j;
 if (list == NULL || (*list) == NULL || (*list)->next == NULL)
{
return;
}
 i = (*list)->next;
while (i != NULL)
{
  j = i;
  i = i->next;
  while (j != NULL && j->prev != NULL)
    {
      if (j->prev->n > j->n)
	{
	  swap(j->prev, j);
	  if (j->prev == NULL)
	    {
	      *list = j;
	      print_list((const listint_t *)*list);
	    }
	}
      else
	j = j->prev;
    }
}
}
