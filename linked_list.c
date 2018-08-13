// Implementation of linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}*start;


void create( int num ) {
	/* This function creates the linked list and inserts the 
	element at the end of the linked list */

	struct node *ptr;
	/* Allocating memory for new node */
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	/* Putting the data in the node */
	tmp->data = num;

	/* New node will be last node */
	tmp->next = NULL;

	/* If the linked list is empty */
	if( start == NULL ) {
		start = tmp;
		return;
	}

	/* If the linked list is not empty
		Move to the last node */
	ptr = start;
	while( ptr->next != NULL ) 
		ptr = ptr->next;

	/* Linking the last node to the new node */
	ptr->next = tmp;

	return;
}

void insert_at_beg( int num ) {
	/* This function inserts new node at the begining */

	/* Allocating memory for new node */
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	/* Putting the data in the node */
	tmp->data = num;

	/* New node now points to the node which was pointed
		by start */
	tmp->next = start;

	/* start now points to the new node */
	start = tmp;

	return;
}

void insert_in_betw( int num, int pos ) {
	/* This function inserts node at other positions except at begining
		It also considers the case of insertion at the end. */

	/* If the linked list is empty then do nothing */
	if( start == NULL ) {
		printf("\n The linked list is empty.");
		return;
	}

	struct node *prev;
	int i;
	/* Allocating memory for new node */
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	/* Putting data in the new node */
	tmp->data = num;

	/* Moving to the node after which new node is to be inserted */
	prev = start;
	for( i = 0; i < pos-1; i++ ) {
		prev = prev->next;
	}

	/* Changing the pointers */
	tmp->next = prev->next;
	prev->next = tmp;

	return;
}

void del_at_beg( void ) {
	/* This function deletes the node at the begining */

	/* If the linked list is empty then return*/
	if( start == NULL ) {
		printf("\nThe linked list is empty");
		return;
	}

	struct node *tmp;
	/* tmp variable points to the first node of the linked list */
	tmp = start;

	/* start node points to the next node of the start node */
	start = start->next;

	/* free the memory of the deleted node */
	free(tmp);
	return;
}

void del_in_betw( int pos ) {
	/* This function deletes node at other positions except at begining
		It also considers the case of deletion at the end. */

	/* If the linked list is empty then return */
	if( start == NULL ) {
		printf("\nThe linked list is empty");
		return;
	}
	struct node *prev, *tmp;
	int i;

	/* prev pointer points to the previous node  */
	prev = start;
	for( i = 0; i < pos-2; i++ )
		prev = prev->next;

	/* tmp node points to the node to be deleted 
		which is the next node of prev */
	tmp = prev->next;

	/* prev node is linked to the next node of the deleted node */
	prev->next = tmp->next;

	/* free the memory of the deleted node */
	free(tmp);
	return;
}

int search_list( int num ) {
	/* This function searches the element in the linked list */

	/* If the linked list is empty then return -1 */
	if( start == NULL ) {
		printf("\nThe linked list is empty");
		return -1;
	}

	struct node *tmp = start;
	int i = 0;

	/* Looping through all the elements in the linked list */
	while( tmp != NULL ) {

		/* Comparing the data of the node to the search number,
			if matches then return the location of that node */
		if( tmp->data == num )
			return i;
		tmp = tmp->next;
		i++;
	}

	/* If not found then return -1 */
	return -1;
}

void reverse_list() {
	/* This function reverses the linked list */

	/* If the linked list contains no or one element then return */
	if( start == NULL || start->next == NULL )
		return;

	struct node *p, *q, *r;

	p = start;
	q = p->next;
	r = q->next;

	/* The first node becomes last node so it points to NULL*/
	p->next = NULL;

	/* Second node points to the first node */
	q->next = p;

	/* Looping through the list and reversing the pointers */
	while( r != NULL ) {

		/* Shifting the pointers one step ahead */
		p = q;
		q = r;
		r = r->next;

		/* q now points to the p */
		q->next = p;
	}
	/* After the loop ends r points to NULL and q points to the last node 
		which will be first node */
	start = q;

	return;
}


void display() {
	/* This function displays the linked list */

	/* If the list is empty */
	if( start == NULL ) {
		printf("\n The list is empty..");
		return;
	}

	struct node *ptr;
	ptr = start;
	printf("\nPrinting the linked list:");
	while( ptr != NULL ) {
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}

	return;
}

int main( int argc, char const *argv[] )
{
	int op, num, pos, i, n;
	start = NULL;

	while(1) {
		printf("\n\n\t\t________Operations on Linked List___________\n");
		printf("\n1. Create a linked list:");
		printf("\n2. Insert at Begining");
		printf("\n3. Insert in Between ( or last )");
		printf("\n4. Deletion at Begining");
		printf("\n5. Deletion in Between");
		printf("\n6. Searching");
		printf("\n7. Reverse the linked list");
		printf("\n8. Display");
		printf("\n9. Exit");
		printf("\nEnter your option:");
		scanf("%d",&op);
		switch(op) {
			case 1:
				printf("\nEnter the number of elements:");
				scanf("%d",&n);
				for( i = 0; i < n; i++ ) {
					printf("\nEnter the element %d:",i);
					scanf("%d",&num);
					create(num);
				}
				break;
			case 2:
				printf("\nEnter the element to be inserted:");
				scanf("%d",&num);
				insert_at_beg(num);
				break;
			case 3:
				printf("\nEnter the element to be inserted:");
				scanf("%d",&num);
				printf("\nEnter the position after which you want to\
					insert the element (>1):");
				scanf("%d",&pos);
				insert_in_betw(num, pos);
				 break;
			case 4:
				del_at_beg();
				break;
			case 5:
				printf("\nEnter the position of the element to be deleted (>1):");
				scanf("%d",&pos);
				del_in_betw(pos);
				break;
			case 6:
				printf("\nEnter the element to be searched:");
				scanf("%d",&num);
				pos = search_list(num);
				if( pos > -1 ) 
					printf("\nElement found at location %d", pos+1);
				else 
					printf("\nElement not found in the list.");
				break;
			case 7:
				reverse_list();
				break;
			case 8: 
				display();
				break;
			case 9:
				exit(0);
			default:
				printf("\nYou have entered wrong option..\n");
				exit(0);
		}
	}
	return 0;
}
