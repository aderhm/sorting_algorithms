#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, selected_index;
	int tmp;

	for (i = 0; i < size; i++)
	{
		selected_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[selected_index] > array[j])
				selected_index = j;
		}

		if (i != selected_index)
		{
			tmp = array[i];
			array[i] = array[selected_index];
			array[selected_index] = tmp;
			print_array(array, size);
		}
	}
}
