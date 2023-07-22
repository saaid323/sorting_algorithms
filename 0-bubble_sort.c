#include "sort.h"

/**
 * swap - swap j and i
 * @a: array
 * @i: integer
 * @j: integer
 * @n: sie of array a
 */
void swap(int a[], int i, int j, int n)
{
	int temp = a[j];

	a[j] = a[i];
	a[i] = temp;
	print_array(a, n);
}

/**
 * bubble_sort - sorts array
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1, size);
			}
		}
	}
}

