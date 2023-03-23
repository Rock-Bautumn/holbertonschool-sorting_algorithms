#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * is_doubly_linked - Check if a doubly linked list is corectly linked
 *
 * @list: Pointer to the first node of the list to check
 *
 * Return: 1 if the list is correctly formated, 0 otherwise
 */
int is_doubly_linked(const listint_t *list)
{
	const listint_t *prev;

	prev = list ? list->prev : NULL;
	while (list)
	{
		if (list->prev != prev)
			return (0);
		prev = list;
		list = list->next;
	}
	return (1);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {98, 95, 92, 91, 87, 84, 79, 68, 62, 47, 41, 39, 34, 32, 31, 22, 21, 20, 2, 1};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	cocktail_sort_list(&list);
	printf("\n");
	print_list(list);
	if (!is_doubly_linked(list))
	{
		printf("The list is not correctly doubly linked !\n");
		return (1);
	}
	return (0);
}
