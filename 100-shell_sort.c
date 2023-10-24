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
	size_t n;
	int i, tmp;

	n = 1;
	while (n < size)
		n = n * 3 + 1;

	while (n >= 1)
	{
		for (i = 0; n < size; i++)
		{
			if (array[i] > array[n])
			{
				tmp = array[i];
				array[i] = array[n];
				array[n] = tmp;
				print_array(array, size);
			}
			n++;
		}
		n -= (i + 1);
	}
}
