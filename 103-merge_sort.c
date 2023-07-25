#include "sort.h"

/**
 * merge - merges array
 * @array: array of integers
 * @left: array of integers
 * @left_size: size of left array
 * @right: array of integers
 * @right_size: size of right array
 * @size: size of array
 */
void merge(int *array, int *left, int left_size, int *right, int right_size,
		size_t size)
{
	int i = 0, j = 0, k = 0;
	int *temp = malloc((left_size + right_size) * sizeof(int));

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	if (temp == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			temp[k++] = left[i++];
		}
		else
		{
			temp[k++] = right[j++];
		}
	}
	while (i < left_size)
	{
		temp[k++] = left[i++];
	}
	while (j < right_size)
	{
		temp[k++] = right[j++];
	}
	for (i = 0; i < left_size + right_size; i++)
	{
		array[i] = temp[i];
	}
	printf("Done: ");
	print_array(array, size);
	free(temp);
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int mid = size / 2;
	int *left = array;
	int *right = array + mid;

	if (size <= 1)
	{
		return;
	}
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, mid, right, size - mid, size);
}
