#include "sort.h"


/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	for (i = 0; i < size; i++)
	{
		size_t min = i;

		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = array[i];

			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
