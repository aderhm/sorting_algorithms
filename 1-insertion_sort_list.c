#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Doubly linked list.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *templist, *tempnode;

	if (!list)
		return;

	templist = *list;

	while (templist)
	{
		while (templist->next && (templist->n > templist->next->n))
		{

			tempnode = templist->next;
			templist->next = tempnode->next;
			tempnode->prev = templist->prev;

			if (templist->prev)
				templist->prev->next = tempnode;

			if (tempnode->next)
				tempnode->next->prev = templist;

			templist->prev = tempnode;
			tempnode->next = templist;

			if (tempnode->prev)
				templist = tempnode->prev;
			else
				*list = tempnode;

			print_list(*list);
		}
		templist = templist->next;
	}
}
