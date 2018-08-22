/* Circular Linked List Implementation
	Functions: 
		1. Create
		2. Insert
		3. Delete 
		4. Display
		
	Note: Insert and Delete functions considers all the cases like 
	inserting/deletion at the begining, in between and at the end.
	The choice will depend on the position user enters. 
	
	Author: Shyam Kumar
*/

#include <stdio.h>
#include <stdlib.h>

/* Counts the number of element in the circular linked list */
int count_elem = 0;

struct node {
	int data;
	struct node *next;
}*last;

void create( int num ) {
	/* This function creates the circular linked list 
		It is similar to insertion at the end */

	/* Allocating memory for new node */
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	/* Putting the data in the node */
	tmp->data = num;

	/* Increasing the counter */
	count_elem++;

	/* If the circular linked list is empty */
	if( last == NULL ) {
		last = tmp;
		last->next = last;
		return;
	}

	/* If the circular linked list is not empty */
	/* New node will point to the first node of the list */
	tmp->next = last->next;

	/* last node will point to the new node */
	last->next = tmp;

	/* New node will become the last node of the list */
	last = tmp;

	return;
}

void insert( int num, int pos ) {
	/* This function inserts node in circular linked list 
		at any position. This function considers 3 cases:
		1. Insert at begining(pos = 1), 2. Insert in between, 
		3. Insert at end */

	struct node *q;
	int i;

	/* Allocating the memory for new node */
	struct node *tmp = (struct node*)malloc(sizeof(struct node ));

	/* Putting the data in the node */
	tmp->data = num;

	/* Increasing the counter */
	count_elem++;

	/* Insertion at the begining */
	if( pos == 0 ) {
		tmp->next = last->next;
		last->next = tmp;
		return;
	}

	/* Insertion in between */
	/* q points to the first node */
	q = last->next;

	/* Moving to the node after which new node is to 
		be inserted */
	for( i = 0; i < pos-1; i++ )
		q = q->next;

	/* New node will point to the next node of the previous(q) node */
	tmp->next = q->next;

	/* Previous node will point to the new node */
	q->next = tmp;

	/* Insertion at the end */
	if( q == last )
		last = tmp;
	return;
}

void delete( int pos ) {
	/* This function deletes the node at the specified position */

	struct node *q, *tmp;
	int i;

	/* If there is only one element in the list */
	if( last->next == last ) {
		tmp = last;
		last = NULL;
		free(tmp);
		count_elem--;
	}

	/* q points to the first node */
	q = last->next;

	/* Deletion at the begining */
	if( pos == 1 )
		q = last;

	/* Moving to the node after which new node is to 
		be deleted */
	for(i = 0; i < pos-2; i++) 
		q = q->next;

	/* tmp points to the node to be deleted */
	tmp = q->next;

	/* The node(q) after which new node is to be 
		inserted will point to the new node(tmp) */
	q->next = tmp->next;

	/* Deletion at the end */
	if( tmp == last )
		last = q;
	free(tmp);
	count_elem--;
	return;
}

void display() {
	/* This function displays the circular linked list */

	/* If the list is empty */
	if( last == NULL ) {
		printf("\nThe list is empty..");
		return;
	}

	struct node *q; 
	printf("\n\nCircular Linked list :");

	/* q points to the first node */
	q = last->next;

	/* This loop prints all elements except the last element */
	while( q != last ) {
		printf("%d ",q->data);
		q = q->next;
	}

	/* Printing the last node */
	printf("%d",last->data);
	printf("\nTotal number of element in the list %d", count_elem);
	return;
}

int main(int argc, char const *argv[])
{
	int op, num, pos, n, i;
	last = NULL;

	while(1) {
		printf("\n\n\n______Operations on Circular Linked List________\n");
		printf("\n1. Create");
		printf("\n2. Insert");
		printf("\n3. Delete");
		printf("\n4. Display");
		printf("\n5. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&op);
		switch(op) {
			case 1:
				printf("\nEnter the number of elements to be inserted:");
				scanf("%d",&n);
				for( i = 0; i < n; i++ ) {
					printf("\nEnter element %d:",i);
					scanf("%d",&num);
					create( num );
				}
				break;
			case 2:

				/* If the list is empty */
				if( last == NULL ) {
					printf("\nThe circular lined list is empty");
					break;
				}

				printf("\nEnter the element to be inserted:");
				scanf("%d",&num);
				printf("\nEnter the position of element after which new node to be inserted (0 for begining):");
				scanf("%d",&pos);

				/* If the position entered is not valid */
				if( pos < 0 || pos > count_elem ) {
					printf("\nWrong index!!");
					break;
				}

				insert( num, pos );
				break;
			case 3:
				if( last == NULL ) {
					printf("\n____Underflow...");
					break;
				}
				printf("\nEnter the position of the element to be deleted:");
				scanf("%d",&pos);

				/* If the position entered is not valid */
				if( pos < 1 || pos > count_elem ) {
					printf("\nWrong index!!");
					break;
				}

				delete( pos );
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("You have entered wrong choice..");
		}		
	}
	return 0;
}
