/* Binary Tree C implementation
 *
 * Author: Prashant Malani <p.malani@gmail.com>
 * Date : 1/29/2014
 *
 * This is not a balanced representation.
 * We don't provide the parent link to each node, and leaves have NULL as their parent.
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
struct node *get_successor(struct node *s)
{
	struct node *cur = s->r;
	while (cur->l)
		cur = cur->l;
	return cur;
}

void delete(struct node **root, int val)
{

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
	return 0;

}
