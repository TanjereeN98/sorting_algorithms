#include "sort.h"

/**
 * swap - swaps the positions of the two nodes in the list.
 *
 * @green: first node.
 * @red: second node.
 */
void swap(listint_t *green, listint_t *red)
{
	if (green->prev)
		green->prev->next = red;

	if (red->next)
		red->next->prev = green;

	green->next = red->next;
	red->prev = green->prev;

	red->next = green;
	green->prev = red;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers,
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *red, *temp;

	if (!(*list) || !list)
		return;

	red = (*list)->next;

	while (red)
	{
		temp = red->next;

		while (red->prev && red->n < red->prev->n)
		{
			swap(red->prev, red);

			if (!red->prev)
				*list = red;

			print_list(*list);
		}

		red = temp;
	}
}
