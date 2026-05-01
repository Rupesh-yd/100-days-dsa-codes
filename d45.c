//Height of a Binary Tree
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue for level order construction
struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* curr = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Function to find height (recursive)
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    printf("%d\n", height(root));

    return 0;
}