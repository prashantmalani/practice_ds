/* Find combinations of a string
 * Author: Prashant Malani <p.malani@gmail.com>
 * Date : 01/04/2014
 *
 * Usage: ./a.out <string>
 */
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


void do_comb(char *buf, char *str, int cur_ind, int n, int beg_iter)
{

	int i;

	if (beg_iter == n) {
		return;
	}

	for (i = beg_iter; i < n; i++) {

		buf[cur_ind] = str[i];
		buf[cur_ind + 1] = '\0';
		printf("%s\n", buf);
		do_comb(buf, str, cur_ind + 1, n, i + 1);
	}
}


int main(int argc, char **argv)
{

	char *str, *buf;
	int n;
	int i;

	if (argc != 2) {
		printf("Insufficient arguments. Usage = ./a.out <string>\n");
		return -1;
	}

	n = strlen(argv[1]);
	str = argv[1];
	buf = malloc(sizeof(char) * (n+1));

	do_comb(buf, str, 0, n, 0);

	free(buf);
	return 0;

}
