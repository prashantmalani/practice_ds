/* Dijkstra's algorithm implementation
 * We use adjacency lists to maintain edge info
 * We also use min heaps to keep track of the closest
 * next vertex.
 *
 * Author: Prashant Malani <p.malani@gmail.com>
 * Date  : 12/31/2013
 */
#include "dijk.h"

/* Adjacency list pointer array */
struct adj_t *list[NUM_VERTICES];

/* Heap structure */
int len_heap = NUM_VERTICES;
struct heap_t heap[NUM_VERTICES];

void init_edges()
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

}

int main()
{
	struct heap_t min;

	init_edges();

	/* We assume 3 is the source */
	init_heap(3, heap, len_heap);
	min = extract_min(heap, &len_heap);
	return 0;
}
