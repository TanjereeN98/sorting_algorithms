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
	int temp, flag = 0;

	if (!array || size < 1)
		return;
	for (i = 0 ; i < size ; i++)
	{
		iMin = i;
		for (j = i + 1 ; j < size; j++)
		{
			if (array[iMin] > array[j])
			{
				iMin = j;
				flag = 1;
			}
		}
		temp = array[i];
		array[i] = array[iMin];
		array[iMin] = temp;
		if (flag)
			print_array(array, size);
		flag = 0;
	}
}
