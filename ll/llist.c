#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


/*
 * Define the linked list node.
 */
struct node {
	int val;
	struct node *next;
};


struct node *head = NULL;

int create_node(struct node **head, int val)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (!new_node)
		return -1;
	new_node->val = val;

	new_node->next = *head;
	*head = new_node;

	return 0;
}

void print_list(struct node *head)
{
	struct node *cur;
	for (cur = head; cur; cur=cur->next)
		printf("%d ", cur->val);
	printf("\n");
}

int main()
{

	/* Setup an initial list*/
	create_node(&head, 3);
	create_node(&head, 4);
	create_node(&head, 5);
	print_list(head);
	return 0;
}
