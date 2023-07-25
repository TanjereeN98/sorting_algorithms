#include "sort.h"

/**
 * merge - merges two sorted arrays.
 *
 * @merging_array: the merging array.
 * @merging_array_size: the size of the merging array.
 * @left: the first array.
 * @left_size: the size of the first array.
 * @right: the second array.
 * @right_size: the size of the second array.
*/
void merge(
	int *merging_array,
	size_t merging_array_size,
	int *left,
	size_t left_size,
	int *right,
	size_t right_size
)
{
	size_t l = 0, r = 0, m = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	if (merging_array_size < left_size + right_size)
		return;

	for (; l < left_size && r < right_size; m++)
	{
		if (left[l] <= right[r])
		{
			merging_array[m] = left[l];
			l++;
		}
		else
		{
			merging_array[m] = right[r];
			r++;
		}
	}

	if (l == left_size)
	{
		for (; r < right_size; m++, r++)
			merging_array[m] = right[r];
	}

	if (r == right_size)
	{
		for (; l < left_size; m++, l++)
			merging_array[m] = left[l];
	}

	printf("[Done]: ");
	print_array(merging_array, left_size + right_size);
}

/**
 * _merge_sort - _
 *
 * @merging_array: _
 * @array: _
 * @size: _
*/
void _merge_sort(
	int *merging_array,
	int *array,
	size_t size
)
{
	int *left, *right;
	size_t left_size, right_size, i;

	if (size <= 1)
		return;

	left = array;
	left_size = size / 2;
	right = &array[left_size];
	right_size = size - left_size;

	_merge_sort(merging_array, left, left_size);
	_merge_sort(merging_array, right, right_size);

	merge(
		merging_array,
		size,
		left,
		left_size,
		right,
		right_size
	);

	for (i = 0; i < size; i++)
		array[i] = merging_array[i];
}

/**
 * merge_sort - sorts an array of integers in ascending order,
 * using the Merge sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
*/
void merge_sort(int *array, size_t size)
{
	int *merging_array;

	if (!array || size < 2)
		return;

	merging_array = malloc(sizeof(int) * size);

	if (!merging_array)
		return;

	_merge_sort(merging_array, array, size);

	free(merging_array);
}
