//Mirror a Binary Tree
#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Mirror the binary tree
void mirrorTree(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    mirrorTree(root);

    inorder(root);

    return 0;
}