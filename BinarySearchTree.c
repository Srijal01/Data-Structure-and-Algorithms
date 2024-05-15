//Program in C to perform various operations in Binary Search Tree (BST)
#include <stdio.h>
#include <stdlib.h>
// Structure for a node of BST
struct Node 
{
    int key;
    struct Node *left, *right;
};
// Function prototypes
struct Node* createNode(int);
struct Node* insert(struct Node*, int);
struct Node* deleteNode(struct Node*, int);
struct Node* search(struct Node*, int);
struct Node* minValueNode(struct Node*);
struct Node* maxValueNode(struct Node*);
void inorder(struct Node*);
int main() 
{
    struct Node* root = NULL;
    int choice, key;
    // Menu for various operations
    do 
    {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. In-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key found\n");
                else
                    printf("Key not found\n");
                break;
            case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else
                    printf("Minimum element: %d\n", minValueNode(root)->key);
                break;
            case 5:
                if (root == NULL)
                    printf("Tree is empty\n");
                else
                    printf("Maximum element: %d\n", maxValueNode(root)->key);
                break;
            case 6:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
    return 0;
}
// Function to create a new node
struct Node* createNode(int key) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to insert a key in BST
struct Node* insert(struct Node* root, int key) 
{
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}
// Function to delete a key from BST
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
// Function to search for a key in BST
struct Node* search(struct Node* root, int key) 
{
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
// Function to find node with minimum key value in BST
struct Node* minValueNode(struct Node* node) 
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
// Function to find node with maximum key value in BST
struct Node* maxValueNode(struct Node* node) 
{
    struct Node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}
// Function for in-order traversal of BST
void inorder(struct Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
