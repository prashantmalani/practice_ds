/*
 * Quick sort C implementation.
 *
 * Author : Prashant Malani<p.malani@gmail.com>
 * Date : 02/01/2014
 *
 * Should work on all integers.
 * We assume the pivot to always be the right most element. This
 * can obviously be changed according to the requirements,
 * but a right pivot is just more convenient.
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* The recursive call to quicksort */
void quicksort(int arr[], int  l, int r)
{
	int pivot;
	int i, j;
	int partition;
	/* Base case to end the recursion */
	if (l >= r)
		return;
	i = l - 1;
	j = r + 1;
	pivot = arr[l];

	while (1) {
		while (arr[--j] > pivot);
		while (arr[++i] < pivot);

		if (i < j) {
			swap(&arr[i], &arr[j]);
		} else {
			partition = j;
			break;
		}
	}

	quicksort(arr, l, partition);
	quicksort(arr, partition + 1, r);
}

int main()
{
	/* Test input */
	int arr[] = {45, 8, 475, -34, 18, 999, 45, -435};
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;
	quicksort(arr, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
