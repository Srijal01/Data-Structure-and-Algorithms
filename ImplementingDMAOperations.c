//Program in C implementing DMA operations.
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int *ptr;
    int size, i;
    			// Malloc
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    ptr = (int*)malloc(size * sizeof(int));
    if (ptr == NULL) 
	{
        printf("Memory allocation failed!");
        return 0;
    }
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) 
	{
        scanf("%d", &ptr[i]);
    }
    printf("Array elements using malloc:\n");
    for (i = 0; i < size; i++) 
	{
        printf("%d ", ptr[i]);
    }
    printf("\n");
    			// Calloc
    int *ptr2;
    int size2;
    printf("Enter the size of the array: ");
    scanf("%d", &size2);
    ptr2 = (int*)calloc(size2, sizeof(int));
    if (ptr2 == NULL) 
	{
        printf("Memory allocation failed!");
        return 0;
    }
    printf("Array elements using calloc:\n");
    for (i = 0; i < size2; i++) 
	{
        printf("%d ", ptr2[i]);
    }
    printf("\n");
    			// Realloc
    int newSize;
    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);
    ptr = (int*)realloc(ptr, newSize * sizeof(int));
    if (ptr == NULL) 
	{
        printf("Memory reallocation failed!");
        return 0;
    }
    printf("Enter the new elements of the array:\n");
    for (i = 0; i < newSize; i++) 
	{
        scanf("%d", &ptr[i]);
    }
    printf("Array elements after reallocation:\n");
    for (i = 0; i < newSize; i++) 
	{
        printf("%d ", ptr[i]);
    }
    printf("\n");
    				// Free
    free(ptr);
    free(ptr2);
    return 0;
}
