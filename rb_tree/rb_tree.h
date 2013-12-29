/* rb_tree.h
 *
 * Header file to include some initial declarations and headers
 * for RED BLACK tree implementation.
 *
 * Author: Prashant Malani
 * Date : 25/12/2013
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


enum color {
	BLACK,
	RED,
};

/* Pointer to the nil node. All leaves have this as their left and right children.
 * It is black by default.
 */
struct node *nil_node;

/* Some helper macros */
#define IS_RED(node) \
	(node->col == RED)

#define IS_NIL(node) \
	(node == nil_node)

#define IS_LEFT_CHILD(node) \
	(node->p->l == node)
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

void rotate_left(struct node *x);
void rotate_right(struct node *x);
