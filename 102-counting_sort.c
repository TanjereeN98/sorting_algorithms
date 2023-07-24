#include "sort.h"

/**
 * maximum - returns maximum integer in an array.
 *
 * @array: the array.
 * @size: the size of the array.
 *
 * Return: maximum integer in the array.
*/
int maximum(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order,
 * using the Counting sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
*/
void counting_sort(int *array, size_t size)
{
	int max, *counting_array, *sorted_array, i;

	if (!array || size < 2)
		return;

	max = maximum(array, size);
	counting_array = malloc(sizeof(int) * (max + 1));
	sorted_array = malloc(sizeof(int) * size);

	if (!counting_array || !sorted_array)
	{
		free(counting_array);
		free(sorted_array);
		return;
	}

	for (i = 0; i <= max; i++)
		counting_array[i] = 0;

	for (i = 0; i < (int) size; i++)
		counting_array[array[i]]++;

	for (i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];

	print_array(counting_array, (max + 1));

	for (i = 0; i < (int) size; i++)
	{
		counting_array[array[i]]--;
		sorted_array[counting_array[array[i]]] = array[i];
	}

	for (i = 0; i < (int) size; i++)
		array[i] = sorted_array[i];

	free(counting_array);
	free(sorted_array);
}
