/* C Implementation of a Red Black Tree
 *
 * Author: Prashant Malani
 * Date : 23/12/2013
 *
 * Provide implementation for a Red-Black, with insert,
 * delete and traversal (inorder).
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


enum color {
	BLACK,
	RED,
};

#define IS_RED(node) \
	(node->col == RED)

/*
 * Define the tree node.
 */
struct node {
	int val;
	struct node *l;
	struct node *r;
	struct node *p;
	enum color col;
};


struct node *root = NULL;

/* Pointer to the nil node. All leaves have this as their left and right children.
 * It is black by default.
 */
struct node *nil_node;

struct node *create_node(int val)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (!new_node)
		return NULL;

	new_node->val = val;
	/* Initialize children, parents etc. */
	new_node->l = nil_node;
	new_node->r = nil_node;
	new_node->p = NULL; /* This has to be assigned after insertion */
	new_node->col = RED;

	return new_node;
}

/* Insert function:
 * Create a new node.
 * Traverse the tree to perform a normal binary search tree insert,
 * then perform the rotations, to ensure that the RB tree property doesn't get violated
 */
void insert(struct node **root, int val)
{
	/* GLORIOUS CODE GOES HERE */
}

int main()
{
	/* Initialize the nil node */
	nil_node = malloc(sizeof(struct node));
	if (!nil_node) {
		printf("ERROR; can't initialize nil_node. BT creation will fail\n");
		return -1;
	}

	nil_node->l = NULL;
	nil_node->r = NULL;
	nil_node->p = NULL; /*We really don't care whether the node has a parent or not */
	nil_node->col = BLACK;
	nil_node->val = 0xDEADBEEF;

	return 0;
}
