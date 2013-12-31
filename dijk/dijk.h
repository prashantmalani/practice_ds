#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<limits.h>

#define NUM_VERTICES	7

/*
 * Each entry of the adjancency list contains the index, edge and next entry.
 * If there is no next, then point to NULL.
 */
struct adj_t {
	int index;
	int edge;
	struct adj_t *next;
};

struct heap_t {
	int index;
	int dist;
};

struct final_t {
	int dist;
	int parent;
};

void add_edge(int index, int val, struct adj_t **head);

void print_adj_list(struct adj_t *head);

void init_heap(int index_src, struct heap_t heap[], int len);
void init_weight_array(int index_src, struct final_t fin[], int len);
struct heap_t extract_min(struct heap_t heap[], int *len);
void decrease_key(int index, struct heap_t heap[], int len, int new_val);
