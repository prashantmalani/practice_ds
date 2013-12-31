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

struct adj_t *list[7];


void add_edge(int index, int val, struct adj_t **head)
{
	struct adj_t *new = malloc(sizeof(struct adj_t));
	new->index = index;
	new->edge = val;
	new->next = *head;
	*head = new;
}

void print_adj_list(struct adj_t *head)
{
	struct adj_t *cur;
	for (cur = head; cur != NULL; cur=cur->next)
		printf("ind = %d, edge = %d \t", cur->index, cur->edge);

	printf("\n");
}

int main()
{
	/* Initialize the adjancency list for a sample graph */

	/* Vertex A */
	add_edge(5, 4, &list[0]);

	/* Vertex B */
	add_edge(0, 2, &list[1]);
	add_edge(6, 2, &list[1]);

	/* Vertex C */
	add_edge(1, 3, &list[2]);

	/* Vertex D */
	add_edge(4, 1, &list[3]);
	add_edge(2, 2, &list[3]);

	/* Vertex E */
	add_edge(5, 3, &list[4]);
	add_edge(6, 2, &list[4]);

	/* Vertex F */
	add_edge(6, 1, &list[5]);

	/* Vertex G */
	add_edge(0, 1, &list[6]);
	add_edge(5, 1, &list[6]);
	add_edge(3, 3, &list[6]);
	add_edge(2, 4, &list[6]);


	print_adj_list(list[0]);
	print_adj_list(list[1]);
	print_adj_list(list[2]);
	print_adj_list(list[3]);
	print_adj_list(list[4]);
	print_adj_list(list[5]);
	print_adj_list(list[6]);




	return 0;
}
