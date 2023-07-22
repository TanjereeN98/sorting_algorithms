#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t iMin, j, i = 0;
	int temp;

	if (!array)
		return;
	for (i = 0 ; i < size - 1 ; i++)
	{
		iMin = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[iMin] > array[j])
				iMin = j;
		}
		temp = array[i];
		array[i] = array[iMin];
		array[iMin] = temp;
		print_array(array, size);
	}
}
