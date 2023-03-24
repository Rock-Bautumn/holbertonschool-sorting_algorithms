#include "sort.h"


/**
 * maxIntInArray - Finds the largest number in an array of integers
 * @arr: The array to search through
 * @n: The number of digits of the array (to look through on the left side)
 * Return: The largest number from the array
*/

int maxIntInArray(int arr[], size_t n)
{
	size_t i;
	int max = arr[0];

	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * strict_print_array - Print the array without a newline at the end
 * @array: The array to print
 * @size: The size of the array
 * Return: void
*/

void strict_print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
}

/**
 * count_print - A fussy way of printing the count array
 * @array: The sorted array
 * @size: The size of the sorted array
 * Return: void
*/

void count_print(int *array, size_t size)
{
	size_t index = 0, comma = 0;

	for (; index < size; index++)
	{
		while (array[index] > 0)
		{
			if (comma > 0)
				printf(", ");
			printf("%ld", index);
			array[index]--;
			comma++;
		}
	}
}

/**
 * counting_sort - Stable sort of integers in array without using comparisons
 * @array: The array to sort
 * @size: The size of the array
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
	size_t index, keys;
	int *sorted, *count;

	if (!array || size < 2)
		return;

	keys = maxIntInArray(array, size);

	count = malloc(sizeof(int) * (keys + 1));
	if (!count)
		return;

	sorted = malloc(sizeof(int) * (keys + 1));
	if (!sorted)
		return;

	for (index = 0; index < size; index++)
		count[array[index]]++;
	for (index = 1; index <= keys; index++)
		count[index] += count[index - 1];
	for (index = size - 1; ; index--)
	{
		sorted[--count[array[index]]] = array[index];
		if (index == 0)
			break;
	}
	for (index = 0; index < size; index++)
		array[index] = sorted[index];


	strict_print_array(count + 1, keys);
	printf(", %ld\n", size);
	free(sorted);
	free(count);
}
