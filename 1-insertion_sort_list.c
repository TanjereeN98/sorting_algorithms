#include "sort.h"
#include <stdbool.h>
/**
 * insert - used to insert a node into the list with sorted order
 *
 * @list: the head of the list
 * @tail: the tail of the list
 * @node: the node to be insrted
 */
void insert(listint_t **list, listint_t **tail, listint_t *node)
{
	listint_t *curr;
	
	if (!(*list) || !list || !(*tail) || !tail)
		return;
	if (node->n < (*list)->n)
	{
		node->prev = NULL;
		node->next = *list;
		(*list)->prev = node;
		*list = node;
		return;
	}
	if (node->n > (*tail)->n)
	{
		node->next = NULL;
		node->prev = *tail;
		(*tail)->next = node;
		*tail = node;
		return;
	}
	curr = *list;
	while (curr->next && curr->next->n < node->n)
	{
		curr = curr->next;
	}
	node->next = curr->next;
	curr->next->prev = node;
	curr->next = node;
	node->prev = curr;
}

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: the list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_tail, *unsorted, *temp;

	sorted_tail = *list;
	unsorted = (*list)->next;

	while (unsorted)
	{
		temp = unsorted;
		unsorted = unsorted->next;
		insert(list, &sorted_tail, temp);
	}
}
