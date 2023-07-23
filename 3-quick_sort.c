#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: Always 0
 */

void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}

/**
 * quickSort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @start: start index of the array
 * @end: end index of the array
 */

void quickSort(int *array, int start, int end, size_t size)
{
	int Pindex;

	if (start < end)
	{
		Pindex = partition(array, start, end, size);
		quickSort(array, start, Pindex - 1, size);
		quickSort(array, Pindex + 1, end, size);
	}
}

/**
 * partition - partitione the array using Lomuto partition scheme.
 *
 * @arr: the array to be partitioned
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: Pivot index
 */

int partition(int *arr, int start, int end, size_t size)
{
	int pivot, i, Pindex;

	Pindex = start;
	pivot = arr[end];
	for (i = start; i < end ; i++)
	{
		if (arr[i] < pivot)
		{
			if (arr[i] != arr[Pindex])
			{
				swap(&arr[i], &arr[Pindex]);
				print_array(arr, size);
			}
			Pindex++;
		}
	}
	if (arr[Pindex] != arr[end])
	{
		swap(&arr[Pindex], &arr[end]);
		print_array(arr, size);
	}
	return (Pindex);
}

/**
 * swap - Swaps the values of two integers using pointers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}
