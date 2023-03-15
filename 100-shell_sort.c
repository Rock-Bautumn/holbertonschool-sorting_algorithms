#include <stdio.h>
#include "sort.h"

/**
 * swap_array_items - Swap the items of an int array
 * @array: The int array that contains the items to swap
 * @item1: The first item of the array to swap
 * @item2: The second item of the array to swap
 * Return: void
*/
void swap_array_items(int *array, size_t item1, size_t item2)
{
	int temp;

	if (array == NULL)
		return;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * shell_sort - Sort an int array using the Knuth sequence
 * @array: The array to sort
 * @size: The size of the array
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, outer, inner;

	/* check if we can sort the array */
	if (array == NULL || size < 2)
		return;

	/* Find our initial gap */

	while (gap <= size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (outer = 0; outer < size - gap; outer++)
		{
			for (inner = outer + gap; inner >= gap; inner--)
			{
				if (array[inner - gap] > array[inner])
					swap_array_items(array, inner, inner - gap);

				if (inner == 0)
					break;
			}
		}
		print_array(array, size);
	}
}
