#include "sort.h"
#include <stdbool.h>
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: the array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t j;
	bool sorted = false;
	size_t temp_size = size;

	if (!array)
		return;
	while (!sorted)
	{
		sorted = true;
		for (j = 0 ; j < temp_size - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				sorted = false;
			}
		}
		temp_size--;
	}
}
