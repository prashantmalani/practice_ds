/* Binary Tree C implementation
 *
 * Author: Prashant Malani <p.malani@gmail.com>
 * Date : 1/29/2014
 *
 * This is not a balanced representation.
 * We don't provide the parent link to each node, and leaves have NULL as their parent.
 * NOTE: We assume distinct keys in this implementation.
 */

#include<stdlib.h>
#include<stdio.h>

struct node {
	int data;
	struct node *l;
	struct node *r;
};

struct node *root;

/* Alloc memory for a new node and return a ptr to it */
struct node *new_node(int val)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->l = temp->r = NULL;
	temp->data = val;
	return temp;
}

/* Given a value, create a node, and insert it correctly in the tree */
void insert_node(int val, struct node **root)
{
	struct node *nnode = new_node(val);
	struct node *cur = *root;
	struct node *parent = NULL;

	if (!*root) {
		*root = nnode;
		return;
	}

	while (cur) {
		parent = cur;
		if (val > cur->data)
			cur = cur->r;
		else
			cur = cur->l;
	}

	if (val > parent->data)
		parent->r = nnode;
	else
		parent->l = nnode;
}

/* Returns the smallest node which is greater than s*/
struct node *get_successor(struct node *s, struct node **parent_successor)
{
	struct node *cur = s->r;
	struct node *parent = s;
	while (cur->l) {
		parent = cur;
		cur = cur->l;
	}
	*parent_successor = parent;
	return cur;
}



void delete(struct node **root, int val)
{
	struct node *parent_cur = NULL;
	struct node *cur = *root;
	struct node *splice, *splice_parent;
	struct node *x;

	/* Find the node */
	while (cur->data != val && cur != NULL) {
		parent_cur = cur;
		if (val > cur->data)
			cur = cur->r;
		else
			cur = cur->l;
	}

	if (!cur) {
		printf("Element %d not found!\n", val);
		return;
	}

	/* Parent_cur stores the parent, and cur stores the node to be deleted */

	/* Find the node to be spliced out */
	if (!cur->l || !cur->r) {
		splice = cur;
		splice_parent = parent_cur;
	} else {
		splice = get_successor(cur, &splice_parent);
	}

	/* Find the child of splice, which will be connected to "splice's parent" */
	if (splice->l)
		x = splice->l;
	else
		x = splice->r;

	if (x) {
		/* Is splice a left child ? */
		if (splice_parent->l == splice)
			splice_parent->l = x;
		else
			splice_parent->r = x;
	} else {
		/*
		 * There is no child to connect to splice's parent, so just NULL out out the link
		 * between splice_parent and splice
		 */
		if (splice_parent->l == splice)
			splice_parent->l = NULL;
		else
			splice_parent->r = NULL;
	}


	/*
	 * If the node itself wasn't spliced out, we should update it's value
	 * with that of the spliced out node.
	 */
	if (splice != cur)
		cur->data = splice->data;

	/* Free remaining memory */
	free(splice);
}

void print_in_order(struct node *root)
{
	if (!root)
		return;

	print_in_order(root->l);
	printf("%d ", root->data);
	print_in_order(root->r);
}

int main()
{
	insert_node(20, &root);
	insert_node(10, &root);
	insert_node(30, &root);
	insert_node(5, &root);
	insert_node(15, &root);

	printf("\n");
	print_in_order(root);
	printf("\n");

	delete(&root, 20);

	printf("\n");
	print_in_order(root);
	printf("\n");
	return 0;
}
