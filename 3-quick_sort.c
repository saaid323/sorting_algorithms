#include "sort.h"

/**
 * swap - swaps integers
 * @a: array
 * @x: integer
 * @y: integer
 */
void swap(int a[], int x, int y)
{
	int temp = a[x];

	a[x] = a[y];
	a[y] = temp;
}

/**
 * partition - partition array and get the pivot index
 * @a: array
 * @lo: first index
 * @hi: last index
 * @n: size of array
 * Return: returns pivot point
 */
int partition(int a[], int lo, int hi, size_t n)
{
	int pivot = a[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j < hi; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(a, i, j);
		}
	}
	i++;
	swap(a, i, hi);
	print_array(a, n);
	return (i);
}

/**
 * quicksort_recursion- Sorts a (portion of an) array, divides it into
 * partitions, then sorts those
 * @a: array
 * @lo: first index
 * @hi: last index
 * @n: size of n
 */
void quicksort_recursion(int a[], int lo, int hi, size_t n)
{
	if (lo >= hi || lo < 0)
		return;
	if (lo < hi)
	{
		int p = partition(a, lo, hi, n);

		quicksort_recursion(a, lo, p - 1, n);
		quicksort_recursion(a, p + 1, hi, n);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1, size);
}
