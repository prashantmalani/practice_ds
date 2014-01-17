/*
 * Resolve a path with ".." and "." into it's absolute path name
 *
 * Author: Prashant Malani <p.malani@gmail.com>
 * Date: 17/1/2014
 *
 * Usage: ./path_make <path>
 */
#include <string.h>
#include <stdio.h>

/*
 * Ideally we would like to use a linked list to store the entities of the path name
 * but in the interest of time, we use an array
 */
static char comp_arr[20][30];
static int cur_tail;

static void back_track(void)
{
	cur_tail--;

}

static void add_comp(const char *str)
{
	strcpy(comp_arr[cur_tail++], str);
	return;
}

/*
 * main logic.
 * If component is a ".", don't do anything.
 * If it's a "..", back track one entry.
 * For everything else, add the entry to the end of our "list"
 */
int main(int argc, char *argv[])
{
	char *cur_comp;
	int i;

	if (argc != 2) {
		printf("Usage is ./path_make <string>\n");
		return 0;
	}

	cur_comp = strtok(argv[1], "/");
	while (cur_comp) {
		if (!strcmp(cur_comp,"..")) {
			back_track();
		} else if (strcmp(cur_comp, ".")) {
			add_comp(cur_comp);
		}
		cur_comp = strtok(NULL, "/");
	}

	printf("\n/");

	for (i = 0; i < cur_tail-1; i++)
		printf("%s/", comp_arr[i]);

	printf("%s\n", comp_arr[i]);
	return 0;
}
