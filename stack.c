/*
	Implementation of Stack 

	Author: Shyam Kumar
*/

#include <stdio.h>
#include <stdlib.h>

struct stack {

	int info;
	struct stack *next;

}*top;

void push( int );
int pop();
void display();

int main(int argc, char const *argv[])
{
	int op, num;

	while(1) {
		printf("\n_________Operations on Stack__________");
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nEnter your option: ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("\nEnter the data you want to push:");
				scanf("%d",&num);
				push( num );
				break;
			case 2:
				num = pop( top );
				if( num != -1 )
					printf("\nPopped Element: %d",num);
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

void push( int data ) {
	/* This function pushes data on stack */

	/* Allocating the memory for new node */
	struct stack *ptr = (struct stack *)malloc( sizeof( struct stack ) );

	/* Putting the data in the node */
	ptr->info = data;

	/* next pointer of new node will point to the seconde node */
	ptr->next = top;

	/* new node will be top */
	top = ptr;

	return;
}

int pop() {
	/* This function pops data from stack */

	int data;

	if( top == NULL ) {
		printf("\nStack Underflow!!");
		return -1;
	}

	struct stack *ptr;

	/* ptr is used to free the memory */
	ptr = top;

	/* Copying the data for sending */
	data = ptr->info;

	/* Now top will be next node */
	top = top->next;

	free(ptr);
	return data;
}

void display() {
	/* This function is used to display the top */

	if( top == NULL ) {
		printf("\nStack is empty.");
		return;
	}

	struct stack *ptr;
	ptr = top;
	printf("\nPrinting the stack: ");

	while( ptr != NULL ) {
		printf("%d ",ptr->info);
		ptr = ptr->next;
	}
	return;
}
