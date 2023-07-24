#include "sort.h"

/**
 * swap_nodes - swaps the positions of the two nodes in the list.
 *
 * @left: left node.
 * @right: right node.
 */
void swap_nodes(listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers,
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted, *temp;

	if (!list || !(*list))
		return;

	unsorted = (*list)->next;

	while (unsorted)
	{
		temp = unsorted->next;

		while (unsorted->prev && unsorted->n < unsorted->prev->n)
		{
			swap_nodes(unsorted->prev, unsorted);

			if (!unsorted->prev)
				*list = unsorted;

			print_list(*list);
		}

		unsorted = temp;
	}
}
