/* Heloer functions for RB tree implementation. 
 *
 * Author: Prashant Malani
 * Date : 25/12/2013
 *
 *
 */
#include "rb_tree.h"

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
void rotate_left(struct node *x, struct node **root)
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

	/* Edge case, new x is the root?? */
	if (IS_NIL(x->p))
		*root = x;
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
void rotate_right(struct node *x, struct node **root)
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

	/* Edge case, new x is the root?? */
	if (IS_NIL(x->p))
		*root = x;
}
