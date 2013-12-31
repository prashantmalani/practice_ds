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

/* Make the first element in the heap have distance 0,
 * and index = index_src (index of chosen source),
 * fill in the rest of the entries with the remaining indices,
 * and INT_MAX length.
 */
void init_heap(int index_src, struct heap_t heap[], int len)
{
	int i;
	int ind = 0;

	heap[ind].index = index_src;
	heap[ind].dist = 0;
	ind++;

	for (i = 0; i < len; i++) {
		if (i != index_src) {
			heap[ind].index = i;
			heap[ind].dist = INT_MAX;
			ind++;
		}
	}
}

/*
 * Init the final weights array.
 * the index of source node has 0 weight and -1 parent,
 * and all the others have INT_MAX weight
 */
void init_weight_array(int index_src, struct final_t fin[], int len)
{
	int i;

	fin[index_src].dist = 0;
	fin[index_src].parent = -1;

	for (i = 0; i < len; i++) {
		if (i != index_src) {
			fin[i].dist = INT_MAX;
			fin[i].parent = -1;
		}
	}
}

void min_heapify(int ind, struct heap_t heap[], int len)
{
	int l = 2 * ind + 1;
	int r = 2 * ind + 2;
	int ind_min = ind;
	if (l < len && heap[l].dist < heap[ind_min].dist)
		ind_min = l;
	if (r < len && heap[r].dist < heap[ind_min].dist)
		ind_min = r;

	if (ind_min != ind) {
		/* Swap */
		struct heap_t temp = heap[ind];
		heap[ind] = heap[ind_min];
		heap[ind_min] = temp;

		/* Call min_heapify on ind_min */
		min_heapify(ind_min, heap, len);
	}
}

/* Get the lowest element in the heap, and re-heapify the array */
struct heap_t extract_min(struct heap_t heap[], int *len)
{
	struct heap_t ret = heap[0];

	/* Put the bottom most element at the top */
	heap[0] = heap[*len-1];

	(*len)--;

	/* Min Heapify */
	min_heapify(0, heap, *len);

	return ret;

}

/* Decrease the key of the heap entry with "index". And then re-heapify.
 * Ideally, we would like the lookup into the heap to be O(1), but for the
 * sake of simplicity, we just traverse the array to find the entry.
 *
 * NOTE!!: We have to ensure that the values of the indices in the heap are in sync with the values in the final array.
 * It's suggested to batch the update of both together.
 */
void decrease_key(int index, struct heap_t heap[], int len, int new_val)
{
	int i = 0;
	int parent;
	struct heap_t temp;

	/* Find the heap entry corresp. to the index */
	for (i; i < len && (heap[i].index != index); i++);

	/* Update value */
	heap[i].dist = new_val;

	/* Update heap as required */
	while (i > 0) {
		parent = i / 2;
		if (heap[parent].dist > heap[i].dist) {
			temp = heap[parent];
			heap[parent] = heap[i];
			heap[i] = temp;
			i = parent;
		} else {
			break;
		}
	}
}
