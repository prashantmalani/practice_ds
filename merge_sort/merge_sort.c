/* Merge Sort C implementation
 *
 * Author : Prashant Malani <p.malani@gmail.com>
 * Date : 5/1/2014
 *
 * This implementation uses a secondary array for storage
 */
#include<stdio.h>
#include<stdlib.h>


void merge_sort(int a[], int b[], int l, int r)
{
	int m;
	int k, i, j;

	if (l >= r)
		return;

	m = (l + r) / 2;
	merge_sort(a, b, l, m);
	merge_sort(a, b, m + 1, r);
	i = l;
	j = m + 1;

	/* Merge the sorted halves into aux array b */
	for (k = l; k <= r; k++) {
		if (i > m || j > r)
			break;
		if (a[i] < a[j]) {
			b[k] = a[i];
			i++;
		} else {
			b[k] = a[j];
			j++;
		}
	}

	/*
	 * In case one sub array ended prematurely, fill b with
	 * remaining elements from other subarray.
	 */
	if (i > m) {
		while (j <= r)
			b[k++] = a[j++];
	} else if (j > r) {
		while (i <= m)
			b[k++] = a[i++];
	}

	/* Transfer the contents back into main array a */
	for (i = l; i <= r; i++)
		a[i] = b[i];
}

int main()
{

	int a[] = {12, 5, 456, 3, 11, 12, 9};
	int n = sizeof(a) / sizeof(a[0]);

	int *b = malloc(n * sizeof(a));
	int i;
	merge_sort(a, b, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	free(b);
	return 0;
}
