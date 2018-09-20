/*
	Implementation of Circular Queue

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>
#define N 5		// Size of the Queue

/* Global declaration of FRONT and REAR */
int FRONT = -1, REAR = -1;

/* Function Prototypes */
void insert( int*, int  );
int delete( int* );
void display( int* );

int main(int argc, char const *argv[])
{
	int c_queue[N], op, num;

	while(1) {
		printf("\n___________Operations on Circular Queue__________");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&op);
		switch(op) {
			case 1:
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&num);
				insert( c_queue, num );
				break;
			case 2: 
				num = delete( c_queue );
				if( num != -1 )
					printf("\nDeleted element: %d",num);
				break;
			case 3: 
				display( c_queue );
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

void insert( int *c_queue, int num ) {
	/* This function inserts an element in the Queue */

	/* If Queue is already full */
	if( ( FRONT == 0 && REAR == N-1 ) || ( FRONT == REAR+1 ) ) {
		printf("\nQueue Overflow!!");
		return;
	}

	/* If Queue is fully empty */
	if( FRONT == -1 ) {
		FRONT = 0;
		REAR = 0;
	}
	else if( REAR == N-1 ) 
		REAR = 0;
	else {

		/* Incrementing REAR for adding element */
		REAR = REAR + 1;
	}

	/* Inserting an element's data in Queue */
	c_queue[REAR] = num;
	return;
}

int delete( int *c_queue ) {
	/* This function deletes an element from Queue */

	int num;

	/* If Queue is empty */
	if( FRONT == -1 ) {
		printf("\nQueue Overflow!!");
		return -1;
	}

	/* If the element to be deleted is the last element */
	if( FRONT == N-1 ) {
		num = c_queue[FRONT];
		FRONT = 0;
	} 

	/* If there is only one element in the Queue*/
	else if( FRONT == REAR ) {
		num = c_queue[FRONT];
		FRONT = -1;
		REAR = -1;
	}
	else {
		num = c_queue[FRONT];
		FRONT = FRONT + 1;
	}

	return num;
}

void display( int *c_queue ) {
	int i;

	if( FRONT == -1 ) {
		printf("\nQueue is empty.. ");
		return;
	}
	//printf("\nFRONT = %d\tREAR = %d",FRONT, REAR);
	printf("\nCircular Queue: ");

	if( FRONT <= REAR ) {
		for( i = FRONT; i <= REAR; i++ ) {

			printf("%d ",c_queue[i]);
		}
	}
	else {
		for( i = FRONT; i <= N-1; i++ ) {

			printf("%d ",c_queue[i]);
		}
		for( i = 0; i <= REAR; i++ ) {

			printf("%d",c_queue[i]);
		}		

	}
	return; 
}
