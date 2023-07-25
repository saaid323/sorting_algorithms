#include "sort.h"

/**
 * swap - swaps two integers
 * @a: integer
 * @b: integer
 * @arr: array of integers
 * @n: size of arr
 */
void swap(int *a, int *b, int arr[], size_t n)
{
	int temp = *a;

	*a = *b;
	*b = temp;
	print_array(arr, n);
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			int temp = array[i];
			size_t j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
