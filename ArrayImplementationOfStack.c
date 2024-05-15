//Program in C to array implementation of stack
#include<stdio.h>
#include<conio.h>
int stack[100],i,j,ch=0,n,top=-1;
void push();
void pop();
void display();
void main()
{
	printf("Enter the number of elements in the stack: ");
	scanf("%d",&n);
	printf("*******Stack Operations*******");
	printf("\n-------------------------------\n");
	while(ch != 4)
	{
		printf("Choose one from the below options:\n");
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting.....");
				break;
			default:
				printf("Please enter valid choice...");
		}
	};
}
void push()
{
	int val;
	if(top==n)
	printf("\nOverflow");
	else
	{
		printf("Enter the value: ");
		scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}
void pop()
{
	if(top==-1)
	printf("Underflow");
	else
	top=top-1;
}
void display()
{
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	if(top==-1)
	{
		printf("Stack is empty.");
	}
}
