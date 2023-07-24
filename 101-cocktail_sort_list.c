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
 * loop_forward - _
 *
 * @list: _
 * @temp: _
 * @sorted: _
*/
void loop_forward(listint_t **list, listint_t **temp, bool *sorted)
{
	while ((*temp)->next)
	{
		if ((*temp)->n > (*temp)->next->n)
		{
			listint_t *n = (*temp)->next;

			swap_nodes(*temp, n);

			if (!n->prev)
				*list = n;

			*sorted = false;
			print_list(*list);
		}
		else
			*temp = (*temp)->next;
	}
}

/**
 * loop_backward - _
 *
 * @list: _
 * @temp: _
 * @sorted: _
*/
void loop_backward(listint_t **list, listint_t **temp, bool *sorted)
{
	while ((*temp)->prev)
	{
		if ((*temp)->n < (*temp)->prev->n)
		{
			listint_t *p = (*temp)->prev;

			swap_nodes(p, *temp);

			if (!(*temp)->prev)
				*list = *temp;

			*sorted = false;
			print_list(*list);
		}
		else
			*temp = (*temp)->prev;
	}
}

/**
 * cocktail_sort_list - sorts a linked list of integers in ascending order,
 * using the Cocktail shaker sort algorithm.
 *
 * @list: a pointer to the list to be sorted.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	bool sorted = false;

	if (!list || !(*list))
		return;

	temp = *list;

	while (!sorted)
	{
		sorted = true;

		loop_forward(list, &temp, &sorted);
		loop_backward(list, &temp, &sorted);
	}
}
