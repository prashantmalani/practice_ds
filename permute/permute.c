/* Find permutations of a string
 * Author: Prashant Malani <p.malani@gmail.com>
 * Date : 01/04/2014
 *
 * Usage: ./a.out <string>
 */
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


void do_permute(char *buf, char *str, int cur_ind, int n, int skip_arr[])
{

	int i;

	if (cur_ind == n) {
		buf[cur_ind] = '\0';
		printf("%s\n", buf);
		return;
	}

	for (i = 0; i < n; i++) {
		if (!skip_arr[i]) {
			buf[cur_ind] = str[i];

			/* Mark it as used,so that recursive calls don't use it */
			skip_arr[i] = 1;
			do_permute(buf, str, cur_ind + 1, n, skip_arr);

			/*
			 * Once all recursive calls with this letter in this position are done
			 * free it up for later use.
			 */
			skip_arr[i] = 0;
		}
	}
}


int main(int argc, char **argv)
{

	char *str, *buf;
	int n;
	int i;
	int *skip_arr;

	if (argc != 2) {
		printf("Insufficient arguments. Usage = ./a.out <string>\n");
		return -1;
	}

	n = strlen(argv[1]);
	str = argv[1];
	buf = malloc(sizeof(char) * (n+1));

	skip_arr = calloc(n, sizeof(int));

	do_permute(buf, str, 0, n, skip_arr);

	free(buf);
	free(skip_arr);
	return 0;

}
