//Program in C for Heap Sort
#include <stdio.h>
// Function prototypes for heap sort
void heapSort(int[], int);
void heapify(int[], int, int);
void buildMaxHeap(int[], int);
void swap(int*, int*);
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
    // Call heap sort function
    heapSort(a, n);
    // Display data items after sorting
    printf("The data items after sorting: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
// Function to perform heap sort
void heapSort(int a[], int n) 
{
    // Build a max heap
    buildMaxHeap(a, n);
    // Heap sort
    for (int i = n - 1; i > 0; i--) 
    {
        // Swap the root (maximum value) with the last element
        swap(&a[0], &a[i]);
        // Heapify the reduced heap
        heapify(a, i, 0);
    }
}
// Function to build a max heap
void buildMaxHeap(int a[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(a, n, i);
    }
}
// Function to heapify a subtree rooted with node i
void heapify(int a[], int n, int i) 
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child
    // If left child is larger than root
    if (left < n && a[left] > a[largest]) 
    {
        largest = left;
    }
    // If right child is larger than largest so far
    if (right < n && a[right] > a[largest]) 
    {
        largest = right;
    }
    // If largest is not root
    if (largest != i) 
    {
        swap(&a[i], &a[largest]);
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}
// Function to swap two elements
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
