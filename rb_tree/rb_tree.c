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
	new_node->p = nil_node; /* This has to be assigned after insertion */
	new_node->col = RED;

	return new_node;
}

/* Rotate left helper function:
 *
 *              A
 *	      /    \
 *	     a      B
 *	          /   \
 *	         b    c
 *
 * Becomes :
 *             B
 *          /	  \
 *         A	   c
 *       /   \
 *      a     b
 *
 */
void rotate_left(struct node *x)
{
	struct node *y = x->p;
	if(IS_LEFT_CHILD(y))
		y->p->l = x;
	else
		y->p->r = x;
	x->p = y->p;
	y->r = x->l;
	y->r->p = y;
	x->l = y;
	y->p = x;
}

/* Rotate right helper function:
 *
 *              A
 *	      /    \
 *	     B     a
 *	   /   \
 *	   b    c
 *
 * Becomes :
 *             B
 *          /	  \
 *         A	   a
 *       /   \
 *      b     c
 *
 */
void rotate_right(struct node *x)
{
	struct node *y = x->p;
	if(IS_LEFT_CHILD(y))
		y->p->l = x;
	else
		y->p->r = x;
	x->p = y->p;
	y->l = x->r;
	y->l->p = y;
	x->r = y;
	y->p = x;
}


/* Insert function:
 * Create a new node.
 * Traverse the tree to perform a normal binary search tree insert,
 * then perform the rotations, to ensure that the RB tree property doesn't get violated
 */
void insert(struct node **root, int val)
{
	struct node *new_node = create_node(val);
	struct node *par = NULL, *cur = NULL;
	struct node *x,*y;

	if (*root == NULL) {
		/* Edge case where tree is empty */
		*root = new_node;
		new_node->col = BLACK; /* RB tree property : root is black */
		return;
	}

	/* First insert the node */
	par = (*root)->p;
	cur = *root;
	while (!IS_NIL(cur)) {
		if (val > cur->val) {
			par = cur;
			cur = cur->r;
		} else {
			par = cur;
			cur = cur->l;
		}
	}

	new_node->p = par;
	if (par->val > new_node->val)
		par->l = new_node;
	else
		par->r = new_node;

	/* Do the balancing and rotation here */

        /* If there is no grand parent, then we exit immediately */
        if (IS_NIL(new_node->p->p))
		return;

	/* Continue doing rotation and balancing while x is not root and x is not a black node */
	x = new_node;
	while (!IS_NIL(x->p) && IS_RED(x)) {

		if (IS_LEFT_CHILD(x->p)) {
			/* Case A: parent is left child */
			y = x->p->p->r ; /* Right uncle */
			if (IS_RED(y)) {
				/* Re colour */
				x->p->p->col = RED;
				x->p->col = BLACK;
				y->col = BLACK;
			} else {
				/* Case 2:X is the right child :ZIG ZAG */
				if (!IS_LEFT_CHILD(x)) {
					/* Rotate left */
					rotate_left(x);
				}

				/* Case 3: x is the left child : ZIG ZIG.
				 * Note: Case 2 becomes case 3, therfore no else */
				if (IS_LEFT_CHILD(x)) {
					/* Right rotate parent and re colour */
					rotate_right(x->p);

					/* Perform recoloring. make the parent black, and the
					 * new right child red */
					x->p->col = BLACK;
					x->p->r->col = RED;
				}

			}

		} else {
			/*
			 * Case B : parent is right child. This is the symmetric
			 * opposite of the first case.
			 */
			y = x->p->p->l ; /* left uncle */
			if (IS_RED(y)) {
				/* Re colour */
				x->p->p->col = RED;
				x->p->col = BLACK;
				y->col = BLACK;
			} else {
				/* Case 2: X is the left child :ZIG ZAG */
				if (IS_LEFT_CHILD(x)) {
					/* Rotate left */
					rotate_right(x);
				}

				/* Case 3: x is the right child : ZIG ZIG.
				 * Note: Case 2 becomes case 3, therfore no else */
				if (!IS_LEFT_CHILD(x)) {
					/* Right rotate parent and re colour */
					rotate_left(x->p);

					/* Perform recoloring. make the parent black, and the
					 * new right child red */
					x->p->col = BLACK;
					x->p->r->col = RED;
				}
			}
		}
		x = x->p->p;

	}

	if (IS_NIL(x->p)) {
		x->col = BLACK;
		*root = x
	}
}

void print_in_order(struct node *node)
{
	if (IS_NIL(node))
		return;

	print_in_order(node->l);
	printf("%d(%s) ", node->val,IS_RED(node) ? "R" : "B");
	print_in_order(node->r);
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

	insert(&root, 10);
	insert(&root, 5);
	insert(&root, 20);

        print_in_order(root);

	return 0;
}
