#include "sort.h"

/**
 * shell_sort - sorts an array of integers,
 * in ascending order using the Shell sort.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	if (!array)
	{
		return;
	}

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		size_t i;

		for (i = gap; i < size; i++)
		{
			int temp = array[i];
			size_t j;

			for (j = i; j >= gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);
		gap /= 3;
	}
}
