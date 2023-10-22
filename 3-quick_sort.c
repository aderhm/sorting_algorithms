#include "sort.h"

/**
 * partition - Partition an array.
 * @array: The array to be partitioned.
 * @start: First element in @array
 * @end: Last element in @array
 *
 * Return: The index where the array will be partitioned.
 */
int partition(int *array, int start, int end)
{
	int pivot, partitionIndex, i, tmp;

	pivot = array[end];
	partitionIndex = start;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			tmp = array[i];
			array[i] = array[partitionIndex];
			array[partitionIndex] = tmp;
			partitionIndex++;
		}
	}

	tmp = array[partitionIndex];
	array[partitionIndex] = array[end];
	array[end] = tmp;

	print_array(array, sizeof(array) + 2);

	return (partitionIndex);
}

/**
 * _qsort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @start: First element in @array
 * @end: Last element in @array
 *
 * Return: void.
 */
void _qsort(int *array, int start, int end)
{
	int partitionIndex;

	if (start < end)
	{
		partitionIndex = partition(array, start, end);
		_qsort(array, start, partitionIndex - 1);
		_qsort(array, partitionIndex + 1, end);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1);
}
