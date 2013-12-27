/* C Implementation of a Red Black Tree
 *
 * Author: Prashant Malani
 * Date : 23/12/2013
 *
 * Provide implementation for a Red-Black, with insert,
 * delete and traversal (inorder).
 *
 */
#include "rb_tree.h"

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

	/* If the parent is not red, we don't need to insert anything, as the RB property
	 * will be maintained */
	if (!IS_RED(new_node->p))
		return;

	/* Continue doing rotation and balancing while x is not root and x is not a black node */
	x = new_node;
	while (!IS_NIL(x->p) && IS_RED(x)) {

		/* If we have reached the children of the root (which is black, we should end
		 */
		if (IS_NIL(x->p->p))
			break;

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
					/* x is now the parent, and we will perform rotate right on it */

				} else {
					/* we want to do the rotate right on the parent */
					x = x->p;
				}

				/* Case 3: x is the left child : ZIG ZIG.
				 * Right rotate parent and re colour */
				rotate_right(x);

				/* Perform recoloring. make the parent black, and the
				 * new right child red */
				x->col = BLACK;
				x->r->col = RED;
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
					/* Rotate right */
					rotate_right(x);
				} else {
					x = x->p;
				}

				/* Case 3: x is the right child : ZIG ZIG.
				 * Note: Case 2 becomes case 3, therfore no else */
				/* Right rotate parent and re colour */
				rotate_left(x);

				/* Perform recoloring. make the parent black, and the
				 * new right child red */
				x->col = BLACK;
				x->l->col = RED;
			}
		}

		/* Some edge cases */
		if (x->p->p)
			x = x->p->p;
		else
			break;
	}

	/*
	 * If you have reached the root, while traversal, and by change it's color became red,
	 * the revert the color to black.
	 */
	if (IS_NIL(x->p)) {
		*root = x;
	}
	(*root)->col = BLACK;

}

void print_in_order(struct node *node)
{
	if (IS_NIL(node))
		return;

	print_in_order(node->l);
	printf("%d(%s) ", node->val,IS_RED(node) ? "R" : "B");
	print_in_order(node->r);
}

struct node *search(struct node *cur, int val)
{
	if (cur->val == val)
		return cur;

	if (val < cur->val && !IS_NIL(cur->l))
		return search(cur->l, val);
	else if (val > cur->val && !IS_NIL(cur->r))
		return search(cur->r, val);
	else {
		printf("Element not found\n");
		return NULL;
	}
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
	insert(&root, 8);
	insert(&root, 4);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 30);
	insert(&root, 25);

        print_in_order(root);

	return 0;
}
