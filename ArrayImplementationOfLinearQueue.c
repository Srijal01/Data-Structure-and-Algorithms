//Program in C for array implementation of linear queue 
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void main()
{
	int queue[MAX], ch = 1, front = 0, rear = 0, i, j = 1;
	printf("Queue using Array");
	printf("\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT");
	while (ch) 
	{
		printf("\nEnter the Choice:");
		scanf("%d", &ch);
		switch (ch) 
		{
			case 1:
				if (rear == MAX) // x is MAX
				printf("\n Queue is Full");
				else 
				{
					printf("\n Enter no %d:", j++); // Enter no 1
					scanf("%d", &queue[rear++]); // initially rear=0 then increment
				}
				break;
			case 2:
				if (front == rear) 
				{
					printf("\n Queue is empty");
				}
				else 
				{
					printf("\n Deleted Element is %d", queue[front++]);
				}
				break;
			case 3:
				printf("\nQueue Elements are:\n ");
				if (front == rear)
				printf("\n Queue is Empty");
				else 
				{
					for (i = front; i < rear; i++) 
					{
						printf("%d", queue[i]);
						printf("\n");
					}
				}
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong Choice: please see the options above.");
		}
	}
}

