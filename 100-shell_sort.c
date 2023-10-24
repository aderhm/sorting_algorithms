#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	size_t n, i, j;
	int tmp;

	if (!array || !size)
		return;

	n = 1;
	while (n < size)
		n = n * 3 + 1;
	n = (n - 1) / 3;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > n - 1 && array[j - n] > tmp; j -= n)
				array[j] = array[j - n];
			array[j] = tmp;
		}
		print_array(array, size);
		n = (n - 1) / 3;
	}
}
