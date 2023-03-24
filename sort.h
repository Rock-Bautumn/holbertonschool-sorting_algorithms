#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum dir - The direction the cocktail sort is going
 * @UP: The cocktail sort is going from left to right
 * @DOWN: The cocktail sort is going from right to left
 */
enum dir
{UP, DOWN};

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void shell_sort(int array[], size_t size);

int list_n(listint_t **list, size_t item);



void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);


#endif /* END SORT_H */
