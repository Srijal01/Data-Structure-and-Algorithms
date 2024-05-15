//Program in C for Bubble Sort
#include <stdio.h>
// Function prototype for bubble sort
void bubbleSort(int[], int);
int main() 
{
    int n;
    int a[100], i;
    // Input number of data items
    printf("Enter number of data items: \n");
    scanf("%d", &n);
    // Input data items
    printf("Enter %d data items: \n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    // Display data items before sorting
    printf("The data items before sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    // Call bubble sort function
    bubbleSort(a, n);
    printf("\n");
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}
// Function to perform bubble sort
void bubbleSort(int a[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            // Swap if the current element is greater than the next element
            if (a[j] > a[j + 1]) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
