//Program in C illustrating the operations of Circular Linked List.
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
void insert(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;
    if (*head_ref != NULL) 
	{
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = new_node;
    } 
	else
        new_node->next = new_node;
    *head_ref = new_node;
}
void display(struct Node* head) 
{
    struct Node* temp = head;
    if (head != NULL) 
	{
        do 
		{
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
int main() 
{
    struct Node* head = NULL;
    int num, choice;
    do 
	{
        printf("Enter a number to insert: ");
        scanf("%d", &num);
        insert(&head, num);
        printf("Do you want to insert another number? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    } while (choice == 1);
    printf("Circular Linked List: ");
    display(head);
    return 0;
}
