#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/*
 * Each entry of the adjancency list contains the index, edge and next entry.
 * If there is no next, then point to NULL.
 */
struct adj_t {
	int index;
	int edge;
	struct adj_t *next;
};

void add_edge(int index, int val, struct adj_t **head);

void print_adj_list(struct adj_t *head);
