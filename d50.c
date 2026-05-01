//BST Search
#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BST Search Function
struct Node* searchBST(struct Node* root, int key) {
    // Base case
    if (root == NULL || root->data == key) {
        return root;
    }

    // If key is smaller, search left
    if (key < root->data) {
        return searchBST(root->left, key);
    }

    // If key is greater, search right
    return searchBST(root->right, key);
}

// Example usage
int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);

    int key = 7;

    struct Node* result = searchBST(root, key);

    if (result != NULL)
        printf("Element found: %d\n", result->data);
    else
        printf("Element not found\n");

    return 0;
}