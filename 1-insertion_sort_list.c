#include "sort.h"

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node1: Pointer to the first node to swap.
 * @node2: Pointer to the second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
		}
		current = next;
	}
}
