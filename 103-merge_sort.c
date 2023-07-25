#include "sort.h"

/**
 * merge - merges array
 * @array: array of integers
 * @left: array of integers
 * @left_size: size of left array
 * @right: array of integers
 * @right_size: size of right array
 */
void merge(int *array, int *left, int left_size, int *right, int right_size, size_t size)
{
	int i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right: ");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k++] = left[i++];
		}
		else
		{
			array[k++] = right[j++];
		}
	}
	while (i < left_size)
	{
		array[k++] = left[i++];
	}
	while (j < right_size)
	{
		array[k++] = right[j++];
	}
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort: sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int mid = size / 2;
	int *left = (int *)malloc(mid * sizeof(int));
	int *right = (int *)malloc((size - mid) * sizeof(int));
	int i;
	size_t j;

	if (size <= 1)
	{
		return;
	}
	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}
	for (i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (j = mid; j < size; j++)
	{
		right[j - mid] = array[j];
	}
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, mid, right, size - mid, size);
	free(left);
	free(right);
}
