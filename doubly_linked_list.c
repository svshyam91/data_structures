/* Implementation of Doubly linked list 
	Functions: 
		1. Create
		2. Insert at begining 
		3. Insert in Between
		4. Delete at begining
		5. Delete in Between
		6. Delete at End
		7. Display
	Author - Shyam Kumar
	
*/

#include <stdio.h>
#include <stdlib.h>

int count_elem = 0;

/* Declaring the structure of doubly linked list */
struct node {
	struct node *prev;
	int data;
	struct node *next;
}*start;


void create( int num ) {
	/* This function creates a doubly linked list
		This is similar to insertion at the end. */

	struct node *ptr;

	/* Allocating memory for new node */
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	/* Inserting the data in the new node */
	tmp->data = num;

	/* Increase the counter */
	count_elem++;

	/* When the insertion is performed at the end then 
		the next pointer of that new node will be NULL */
	tmp->next = NULL;

	/* If the doubly linked list is empty */
	if( start == NULL ) {
		/* Since the inserted new node is the only node in the
			list, therefore the next pointer of that node will be NULL */
		tmp->prev = NULL;

		/* start will point to the newly inserted node */
		start = tmp;
		return;
	}

	/* If the doubly linked list is not empty */

	/* Moving to the last node of the list */
	ptr = start;
	while( ptr->next != NULL ) 
		ptr = ptr->next;

	/* Next pointer of last node will point to the new node */
	ptr->next = tmp;
	return;
}

void insert_at_beg( int num ) {
	/* This function inserts a node at the begining */

	if( start == NULL ) {
		printf("\nList is empty.\nPlease create the list.");
		return;
	}

	/* Allocating memory for new node */
	struct node *tmp = (struct node*)malloc(sizeof(struct node));

	/* Inserting the data */
	tmp->data = num;

	/* Increasing the counter */
	count_elem++;

	/* Previous pointer of new node will be NULL */
	tmp->prev = NULL;

	/* Next pointer of new node will point to the node which is 
		currently pointed by start */
	tmp->next = start;

	/* The previous pointer of first node before insertion will 
		after insertion point to the new node */
	start->prev = tmp;

	/* Now start will point to the new node */
	start = tmp;

	return;
}

void insert_in_betw( int num, int pos ) {
	/* This function inserts a node in between */

	if( start == NULL ) {
		printf("\nList is empty.\nPlease create list.");
		return;
	}

	struct node *ptr;
	int i;

	/* Allocating memory for new node */
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	/* Inserting the data */
	tmp->data = num;

	/* Increasing the counter */
	count_elem++;

	/* Moving to the node after which new node is to be inserted 
		After the loop ptr will point to that node */
	ptr = start;
	for( i = 0; i < pos-2; i++ ) 
		ptr = ptr->next;

	/* next pointer of new node will point to the next node of ptr */
	tmp->next = ptr->next;

	/* prev pointer of new node will point to the ptr */
	tmp->prev = ptr;

	/* Insertion at the end */
	if( ptr->next != NULL ) {
		/* current next node of the ptr node will point to the new node */
		ptr->next->prev = tmp;
	}
	
	/* next pointer of ptr will point to the next node */
	ptr->next = tmp;

	return;
}

void del_at_beg() {

	/* If the list is empty */
	if( start == NULL ) {
		printf("List is empty..");
		return;
	}

	struct node *ptr;
	/* ptr points to the start node */
	ptr = start;

	/* Now, start points to the next node */
	start = ptr->next;

	/* Making the previous pointer of start to NULL */
	start->prev = NULL;

	free(ptr);

	/* Decreasing the counter */
	count_elem--;

	return;
}

void del_in_betw( int pos ) {
	/* This function deletes the in between the doubly linked list */

	struct node *ptr, *tmp;
	int i;
	ptr = start;

	/* Moving to the node after which the node is to be deleted */
	for( i= 0; i < pos-2; i++ ) 
		ptr = ptr->next;

	/* tmp will point to the node to be deleted */
	tmp = ptr->next;

	/* Next pointer of ptr will point to the next pointer of tmp after deletion */
	ptr->next = tmp->next;

	/* Previous pointer of the next node after tmp will point to the ptr */
	tmp->next->prev = ptr;

	free(tmp);

	/* Decreasing the counter */
	count_elem--;
	return;

}

void del_at_end() {
	/* This function deletes the node at the end */

	/* If the list is empty */
	if( start == NULL ) {
		printf("\nList is empty..");
		return;
	}

	/* If there is only one node */
	if( count_elem == 1 ) {
		printf("\nThere is only one node. Try deletion at begining.");
		return;
	}

	struct node *ptr, *tmp;
	ptr = start;

	/* Moving to the previous node before the last node */
	while( ptr->next->next != NULL ) 
		ptr = ptr->next;

	/* tmp will point to the last node */
	tmp = ptr->next;

	/* Now ptr will be last node */
	ptr->next = NULL;
	free(tmp);

	/* Decreasing the counter */
	count_elem--;
	return;
}

void display() {
	/* This function displays the linked list */

	/* If the list is empty */
	if( start == NULL ) {
		printf("\nList is empty..");
		return;
	}

	struct node *ptr;

	printf("\nList:");
	/* Scanning the list and display the data*/
	ptr = start;
	while( ptr != NULL ) {
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}

	return;
}


int main(int argc, char const *argv[])
{
	start = NULL;

	int op, n, i, num, pos;
	while(1) {
		printf("\n\n\t\t______Doubly Linked List______");
		printf("\n1. Create ");
		printf("\n2. Insert at begining ");
		printf("\n3. Insert in between ");
		printf("\n4. Delete at begining ");
		printf("\n5. Delete in between ");
		printf("\n6. Delete at end ");
		printf("\n7. Display ");
		printf("\n8. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("\nEnter the number of elements to be inserted:");
				scanf("%d",&n);
				for(i = 0; i < n; i++ ) {
					printf("\nEnter the element %d:",i);
					scanf("%d",&num);
					create(num);
				}
				break;

			case 2:
				printf("\nEnter the node to be inserted:");
				scanf("%d",&num);
				insert_at_beg(num);
				break;

			case 3:
				printf("\nEnter the node to be inserted:");
				scanf("%d",&num);
				printf("\nEnter the position of the node to be inserted:");
				scanf("%d",&pos);

				if( pos < 1 || pos > count_elem+1 ) {
					printf("\nWrong Index..");
					break;
				}
				insert_in_betw(num, pos);
				break;

			case 4:
				del_at_beg();
				break;

			case 5:
				/* If the list is empty */
				if( start == NULL ) {
					printf("List is empty..");
					break;
				}
				printf("\nEnter the position of the element to be deleted:");
				scanf("%d",&pos);

				if( pos < 2 || pos >= count_elem ) {
					printf("\nWrong Index..");
					break;
				}
				del_in_betw(pos);
				break;

			case 6:
				del_at_end();
				break;

			case 7:
				display();
				break;

			case 8:
				exit(0);

			default:
				printf("\nYou have entered wrong choice...");
				break;
		}
	}
	return 0;
}
