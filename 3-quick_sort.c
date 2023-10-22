#include "sort.h"

/**
 * partition - Partition an array.
 * @array: The array to be partitioned.
 * @start: First element in @array
 * @end: Last element in @array
 * @size: Number of elements in @array
 *
 * Return: The index where the array will be partitioned.
 */
int partition(int *array, int start, int end, size_t size)
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

	print_array(array, size);

	return (partitionIndex);
}

/**
 * _qsort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @start: First element in @array
 * @end: Last element in @array
 * @size: Number of elements in @array
 *
 * Return: void.
 */
void _qsort(int *array, int start, int end, size_t size)
{
	int partitionIndex;

	if (start < end)
	{
		partitionIndex = partition(array, start, end, size);
		_qsort(array, start, partitionIndex - 1, size);
		_qsort(array, partitionIndex + 1, end, size);
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
	if (!array || size < 2)
		return;

	_qsort(array, 0, size - 1, size);
}
