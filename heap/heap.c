/*
 * HeapSort C Implementation
 *
 * Author : Prashant Malani <p.malani@gmail.com>
 * Date : 02/03/2014
 *
 * Heap is implemented as an array
 */
#include <stdio.h>
#include <stdlib.h>

/* Helper routine */
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * Heap implementation routine used in both heap construction
 * and heapsort.
 */
void heapify(int index, int a[], int len)
{
	int l,r,high;
	l = 2 * index + 1;
	r = 2 * index + 2;
	high = index;
	if (l < len && a[l] > a[high])
		high = l;
	if (r < len && a[r] > a[high])
		high = r;
	if (high != index) {
		swap(&a[high], &a[index]);
		heapify(high, a, len);
	}
	return;
}

void construct_heap(int arr[], int len)
{
	int i;
	for (i = (len - 1) / 2; i >= 0; i--)
		heapify(i, arr, len);
}

void do_heapsort(int a[], int len)
{
	int i = len - 1;
	while (i > 0) {
		/*
		 * Swap first element with last, move to the top, reduce length,
		 * the call heapify on new length array.
		 */
		swap(&a[0], &a[i]);
		i--;
		heapify(0, a, i);
	}
}

int main()
{
	int arr[] = {34, -3, 1983, -12342, 883, 74 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;

	construct_heap(arr, len);
	do_heapsort(arr, len);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
