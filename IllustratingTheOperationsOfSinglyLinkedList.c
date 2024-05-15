//Program in C illustrating the operations of Singly Linked List.
#include <stdio.h>
#include <stdlib.h>
#include <process.h> 	//for exit(1)
struct node
{
	int info;
	struct node *next;
};
typedef struct node NodeType;
NodeType *first, *last;
int i;
void insert_atFirst(int);
void insert_givenPosition(int);
void insert_atLast(int);
void delete_first();
void delete_last();
void delete_nthnode();
void display();
int getSize();
void main()
{
	first = NULL;
	last = NULL;
	int choice;
	int item;
	do
	{
		printf("\nMenu\n1.insert first\n2.insert at given position\n3.insert at last\n4.Delete first node\n5.delete last node\n6.delete nt node\n7.display\n8.SizeofList\n");
		printf("Enter your choice:\t");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("Enter item to be inserted at first \n");
				scanf("%d", &item);
				insert_atFirst(item);
			break;
			case 2:
				printf("Enter item to be inserted at given position \n");
				scanf("%d", &item);
				insert_givenPosition(item);
			break;
			case 3:
				printf("Enter item to be inserted at last \n");
				scanf("%d", &item);
				insert_atLast(item);
			break;
			case 4:
				delete_first();	
			break;
			case 5:
				delete_last();
			break;
			case 6:
				delete_nthnode();
			break;
			case 7:
				display();
			break;
			case 8:
				printf("No. of nodes=%d\n", getSize());
			break;
			default:
				printf("Invalid Choice\n");
		}
	} while (choice < 9);
}
void insert_atFirst(int item)
{
	NodeType *NewNode;
	NewNode = (NodeType *)malloc(sizeof(NodeType));
	NewNode->info = item;
	if (first == NULL)
	{ 								// if inserting in an empty list with no nodes
		NewNode->next = NULL;
		first = NewNode;
		last = NewNode;
	}
	else 
	{
		NewNode->next = first;
		first = NewNode;
	}
}
void insert_givenPosition(int item)
{
	int position, i;
	NodeType *NewNode, *temp;
	NewNode = (NodeType *)malloc(sizeof(NodeType));
	NewNode->info = item;
	printf("Enter a position of node at which you want to insert:\n");
	scanf("%d", &position);
	if (first == NULL)
	{ 							// if inserting in an empty list with no nodes
		first = NewNode;
		last = NewNode;
	}
	else 
	{
		temp = first;
		for (i = 1; i < position - 1; i++)
		{
			temp = temp->next;
		}
		NewNode->next = temp->next;
		temp->next = NewNode;
	}
}
void insert_atLast(int item)
{
	NodeType *NewNode;
	NewNode = (NodeType *)malloc(sizeof(NodeType));
	NewNode->info = item;
	NewNode->next = NULL;
	if (first == NULL)
	{ 							// if inserting in an empty list with no nodes
		first = NewNode;
		last = NewNode;
	}
	else
	{
		last->next = NewNode;
		last = NewNode;
	}
}
void delete_first()
{
	NodeType *temp;
	if (first == NULL)
	{
		printf("Deletion not done\n");
		return;
	}
	else
	{
		temp = first;
		first = first->next;
		free(temp); 		// de-allocate from memory as well.
	}
}
void delete_last()
{
	NodeType *prevnode = first;
	NodeType *temp = first->next;
	while (temp->next != NULL)
	{
		prevnode = prevnode->next;
		temp = temp->next;
	}
	prevnode->next = NULL;
	free(temp);
}
void delete_nthnode()
{
	NodeType *temp, *hold;
	int pos, i;
	if (first == NULL) // no node created
	{
		printf("Deletion not done\n");
		return;
	}
	else
	{
		temp = first;
		printf("Enter position\n");
		scanf("%d", &pos);
		for (i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		hold = temp->next;
		temp->next = hold->next;
		free(hold);
	}
}
void display()
{
	NodeType *temp;
	temp = first;
	if (first == NULL)
	{
		printf("Empty Linked List\n");
		exit(1);
	}
	else
	{
 		while(temp != NULL)
		{
			printf("%d\t", temp->info);
			temp = temp->next;
		}
	}
}
int getSize()
{
	NodeType *temp;
	temp = first;
	int count = 0;
	if (first == NULL)
	{
		printf("Empty Linked List\n");
		exit(1);
	}
	else
	{
		while (temp != NULL)
		{
			printf("%d\t", temp->info);
			temp = temp->next;
			count++;
		}
	}
	return count;
}
