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
static int len_heap = NUM_VERTICES;
static struct heap_t heap[NUM_VERTICES];

/* Store the final indices, their weights and parents */
static struct final_t weights[NUM_VERTICES];

/* Initialize the adjancency list for a sample graph */
void init_edges()
{

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

void initialize_data_structures(int source)
{
	init_edges();

	/* We assume 3 is the source */
	init_heap(source, heap, len_heap);

	/* Also initialize final array */
	init_weight_array(source, weights, len_heap);
}

void do_dijkstra(int source)
{

	struct heap_t cur_min;
	struct adj_t *cur_ver;
	int index, new_weight;

	/* All the initializations are already done */
	while (len_heap > 0) {

		/*
		 * Get the least and add it's values to
		 * weights array.
		 */
		cur_min = extract_min(heap, &len_heap);
		index = cur_min.index;
		weights[index].dist = cur_min.dist;

		/*
		 * We expect the parents to already be set
		 * when we update the distances of each vertex
		 */

		/* Traverse through the elements adj list and
		 * update the weights in heap,and parents in the
		 * final array.
		 */
		for (cur_ver = list[index]; cur_ver != NULL; cur_ver= cur_ver->next) {
			new_weight = weights[index].dist +
				cur_ver->edge;

			/* If the new route is shorter, update */
			if (new_weight < weights[cur_ver->index].dist) {
				/* Update parent in final array */
				weights[cur_ver->index].parent = index;

				/* Update dist in final array */
				weights[cur_ver->index].dist = new_weight;

				/* Update heap */
				decrease_key(cur_ver->index, heap, len_heap, new_weight);

			}

		}
	}

}

int main()
{
	struct heap_t min;


	initialize_data_structures(3);
	do_dijkstra(3);
	print_fin_array(weights, NUM_VERTICES);

	return 0;
}
