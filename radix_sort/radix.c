/*
 * Radix sort implementation for decimal ints
 *
 * Author : Prashant Malani<p.malani@gmail.com>
 * Date : 01/31/2014
 *
 * Use counting sort as the stable sort to perform radix sort
 * C gives us the handy ability to perfmon a right shift, to obtain
 * successively, the next most significant bits, although we could achieve that
 * by division + modulo operations too.
 */

/*
 * Since the actual counting sort is only performed on the last digit,
 * we know deterministically that the size of the counting array needn't
 * be greater than 10.
 */

#include <stdlib.h>
#include <stdio.h>

#define	RANGE_DIGITS 10

void counting_sort(int arr[],int len, int shift)
{
	int *c = calloc(RANGE_DIGITS, sizeof(int));
	int *b = malloc(len * sizeof(int));
	int i;
	int digit;

	for (i = 0; i < len; i++) {
		digit = (arr[i] / shift) % 10;
		c[digit]++;
	}

	for (i = 1; i < RANGE_DIGITS; i++)
		c[i] += c[i-1];

	for (i = len -1; i >= 0; i--) {
		digit = (arr[i] / shift) % 10;
		b[c[digit] - 1] = arr[i];
		c[digit]--;
	}

	for (i = 0; i < len; i++) {
		arr[i] = b[i];
	}

	free(c);
	free(b);
	return;
}

void radix_sort(int arr[], int len)
{
	int shift;
	int divide = 1;
	for (shift = 0; shift < 4; shift++) {
		counting_sort(arr, len, divide);
		divide *= 10;
	}
}

int main()
{
	int arr[] = {457, 34, 5, 2334, 184, 76};
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;

	radix_sort(arr, len);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
