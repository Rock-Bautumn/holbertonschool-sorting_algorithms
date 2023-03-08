#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sort an int array using the Knuth sequence
 * @array: The array to sort
 * @size: The size of the array
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	int gap = 1, left, right, this_item;

	/* Find the initial gap size */
	while (gap <= (int) (size - 1) / 9)
		gap = 3 * gap + 1;

	/* Iterate through the array with varying gaps */
	for (; gap >= 1; gap = gap / 3)
	{
		for (right = gap; right < (int) size; right++)
		{
			this_item = array[right];
			/*
			 * This for loop requires multiple lines to comply
			 * with Betty style requirements due to meaningful
			 * variable names
			*/
			for (left = right - gap;
			left >= 0 && this_item < array[left];
			left = left - gap)
				array[left + gap] = array[left];
			array[left + gap] = this_item;
		}

		print_array(array, size);
	}

}
