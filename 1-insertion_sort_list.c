#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Function that swaps two nodes of a linked list
 * @a: the address of the first node
 * @b: the address of the second node
 */
void swap(listint_t *a, listint_t *b)
{
if (a == NULL || b == NULL)
return;
if (a->prev != NULL)
a->prev->next = b;
if (b->next != NULL)
b->next->prev = a;
a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}

/**
 * insertion_sort_list - Function that sorts a doubly linked
 * list of integers in ascending order
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
listint_t *current = (*list)->next;
while (current != NULL)
{
listint_t *ptr = current;
current = current->next;
while (ptr != NULL && ptr->prev != NULL)
{
if (ptr->prev->n > ptr->n)
{
swap(ptr->prev, ptr);
if (ptr->prev == NULL)
*list = ptr;
print_list(*list);
}
else
ptr = ptr->prev;
}
}
}
