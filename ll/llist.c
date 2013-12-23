/* C Implementation of a Linked List
 *
 * Author: Prashant Malani
 * Date : 23/12/2013
 *
 * Provide implementation for a linked list, with insert,
 * delete and traversal operations.
 *
 * Also run a test main program, which adds a few nodes, and then
 * deletes a few, printing the list after every operation.
 */
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
	if (!head) {
		printf("Empty list\n");
		return;
	}
	for (cur = head; cur; cur=cur->next)
		printf("%d ", cur->val);
	printf("\n");
}

/* We traverse the linked list to find the element.
 * Keep track of the prev node.
 * Return -1 if element doesn't exist
 */
int delete(struct node **head, int val)
{
	struct node *cur, *prev;
	cur = *head;
	prev = NULL;
	while (cur != NULL && cur->val != val) {
		prev = cur;
		cur =cur->next;
	}

	/* Element not found, (either element doesn't exist, or empty list */
	if (cur == NULL) {
		printf("ERROR: Element doesn't exist\n");
		return -1;
	}

			/* Check the case where element was head */
			if (prev == NULL) {
				*head = cur->next;
				free(cur);
			} else {
				prev->next = cur->next;
				free(cur);
			}
	return 0;
}

int main()
{

	/* Setup an initial list*/
	create_node(&head, 3);
	create_node(&head, 4);
	create_node(&head, 5);
	create_node(&head, 6);
	create_node(&head, 7);
	create_node(&head, 8);
	print_list(head);
	delete(&head, -10);
	print_list(head);
	delete(&head, 5);
	print_list(head);
	delete(&head, 3);
	print_list(head);
	delete(&head, 8);
	print_list(head);
	return 0;
}
