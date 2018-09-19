/*
	Implementation of Queue 

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>

/* Structure of Queue */
struct queue {

	int info;
	struct queue *next;

}*front,*rear;

/* Declaration of functions */
void insert( int );
int delete();
void display();

int main(int argc, char const *argv[])
{
	int op, num;

	while(1) {
		printf("\n_______Operations on Queue__________");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&op);
		switch(op) {
			case 1:
				printf("\nEnter the element to insert in Queue:");
				scanf("%d",&num);
				insert( num );
				break;
			case 2: 
				num = delete();
				if( num != -1 )
					printf("\nElement Deleted: %d",num);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default: 
				printf("\nYou have entered wrong choice...");
				break;
		}
	}
	return 0;
}

void insert( int data ) {
	/* This function inserts element in the queue */

	/* Creating a node */
	struct queue *tmp = (struct queue *)malloc( sizeof( struct queue ) );

	/* Inserting the data into the node */
	tmp->info = data;

	/* Node inserted will be last node. So, next pointer will be NULL */
	tmp->next = NULL;

	/* If Queue is empty */
	if( front == NULL )
		front = tmp;
	else
		rear->next = tmp;

	/* Making inserted node as rear as insertion is at the end. */
	rear = tmp;
	return;
}

int delete() {
	/* This function deletes a node from the Queue */

	int data;
	/* If the Queue is empty */
	if( front == NULL ) {
		printf("\nQueue Underflow!!");
		return -1;
	}

	struct queue *tmp;
	tmp = front;
	data = tmp->info;
	front = front->next;
	return data;
}

void display() {
	/* This function displays the Queue */

	if( front == NULL ) {
		printf("\nQueue is empty. ");
		return;
	}

	/* tmp is a temporary variable for displaying Queue */
	struct queue *tmp;
	tmp = front;

	printf("\nQueue: ");
	while( tmp != NULL ) {
		printf("%d ", tmp->info );
		tmp = tmp->next;
	}

	return;
}
