/* Dijkstra's algorithm implementation
 *
 * Helper functions and data structure
 * routines.
 *
 * Author: Prashant Malani <p.malani@gmail.com>
 * Date  : 12/31/2013
 */

#include "dijk.h"

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
