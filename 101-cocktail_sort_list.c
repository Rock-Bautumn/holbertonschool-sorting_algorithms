#include "sort.h"

/**
 * listSize - Find the number of nodes in a linked list
 * @list: The linked list head node
 * Return: The quantity of nodes in the linked list
*/
size_t listSize(listint_t **list)
{
	size_t size = 0;
	listint_t *this_node;

	if (list == NULL || *list == NULL)
		return (0);

	for (this_node = *list; this_node; this_node = this_node->next)
		size++;

	return (size);
}

/**
 * get_dlist_addr - Get the address of the itemth node of a doubly linked list
 * @list: The doubly linked list
 * @item: The position index of the node to retrieve the address of
 * Return: The address of the itemth node of the doubly linked list
*/
listint_t *get_dlist_addr(listint_t **list, size_t item)
{
	listint_t *node = NULL;
	size_t index = 0;

	if (list == NULL || item > listSize(list) - 1)
		return (NULL);

	for (node = *list; node != NULL && index < item; node = node->next, index++)
		;

	return (node);
}

/**
 * list_n - Return the value of the n saved at the itemth position of the list
 * @list: The doubly linked list
 * @item: The position of the item to retrieve the value of n for
 * Return: The value n stored in the node at position number item of the list
*/

int list_n(listint_t **list, size_t item)
{
	listint_t *node = NULL;
	size_t index = 0;

	if (list == NULL || item > listSize(list) - 1)
		return (INT_MIN);

	for (node = *list; node != NULL && index < item; node = node->next, index++)
		;

	return (node->n);
}

/**
 * dlist_swap - Swap the adjacent nodes of a doubly linked list
 * @list: The doubly linked list
 * @item: The position index of the focused node to swap
 * @direction: The direction the cocktail sort is going
 * Return: void
*/

void dlist_swap(listint_t **list, size_t item, bool direction)
{
	listint_t *focus_node, *swap_node, *left_node, *right_node;

	focus_node = get_dlist_addr(list, item);

	if (direction == UP)
	{
		swap_node = focus_node->next;
		left_node = focus_node->prev;
		right_node = swap_node->next;
		if (swap_node == NULL)
			return;
		if (left_node == NULL)
			*list = swap_node;
		else
			left_node->next = swap_node;
		focus_node->prev = swap_node;
		focus_node->next = right_node;
		swap_node->prev = left_node;
		swap_node->next = focus_node;
		if (right_node)
			right_node->prev = focus_node;
	}
	else
	{
		swap_node = focus_node->prev;
		left_node = swap_node->prev;
		right_node = focus_node->next;
		if (swap_node == NULL)
			return;
		if (left_node == NULL)
			*list = focus_node;
		else
			left_node->next = focus_node;
		swap_node->prev = focus_node;
		swap_node->next = right_node;
		focus_node->prev = left_node;
		focus_node->next = swap_node;
		right_node->prev = swap_node;
	}
}

/**
 * cocktail_sort_list - Perform a cocktail shaker style sort on a doubly
 * linked list
 * @list: The doubly linked list to sort
 * Return: void
*/
void cocktail_sort_list(listint_t **list)
{
	size_t size, lower = 0, upper, pos = 0;
	char flip = false;

	if (list == NULL || *list == NULL)
		return;

	size = listSize(list);
	if (size < 2)
		return;

	for (upper = size - 1; upper >= size / 2; flip = !flip)
	{
		if (!flip)
		{
			for (pos = lower; pos < upper; pos++)
			{
				if (list_n(list, pos) > list_n(list, pos + 1))
				{
					dlist_swap(list, pos, UP);
					print_list(*list);
				}
			}
			lower++;
		}
		else
		{
			for (pos = upper; pos > lower - 1; pos--)
				if (list_n(list, pos) < list_n(list, pos - 1))
				{
					dlist_swap(list, pos, DOWN);
					print_list(*list);
				}
			upper--;
		}
	}
}
