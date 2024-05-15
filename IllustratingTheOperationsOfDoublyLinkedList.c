//Program in C illustrating the operations of Doubly Linked List.
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};
void insert(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
void display(struct Node* node) 
{
    while (node != NULL) 
	{
        printf("%d ", node->data);
        node = node->next;
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
    printf("Doubly Linked List: ");
    display(head);
    return 0;
}
