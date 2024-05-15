#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
void enqueue(int queue[], int *front, int *rear, int *count) 
{
    if (*count == MAX) 
    {
        printf("\nQueue is Full");
    } 
    else 
    {
        printf("\nEnter element: ");
        scanf("%d", &queue[*rear]);
        *rear = (*rear + 1) % MAX;
        (*count)++;
    }
}
void dequeue(int queue[], int *front, int *count) 
{
    if (*count == 0) 
    {
        printf("\nQueue is empty");
    } 
    else 
    {
        printf("\nDeleted Element is %d", queue[*front]);
        *front = (*front + 1) % MAX;
        (*count)--;
    }
}
void display(int queue[], int front, int rear, int count) 
{
    if (count == 0) 
    {
        printf("\nQueue is Empty");
    } 
    else 
    {
        printf("\nQueue Elements are:\n");
        int i;
        for (i = 0; i < count; i++) 
        {
            printf("%d\n", queue[(front + i) % MAX]);
        }
    }
}
int main() 
{
    int queue[MAX];
    int choice = 1, front = 0, rear = 0, count = 0;
    printf("Circular Queue using Array\n");
    printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT");
    while (true) 
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                enqueue(queue, &front, &rear, &count);
                break;
            case 2:
                dequeue(queue, &front, &count);
                break;
            case 3:
                display(queue, front, rear, count);
                break;
            case 4:
                return 0;
            default:
                printf("Wrong Choice: please see the options above.");
        }
    }
    return 0;
}
