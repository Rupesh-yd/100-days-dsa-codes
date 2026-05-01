//Binary Tree Construction (Level Order)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue implementation
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}

// Function to build tree using level order
struct Node* buildTree() {
    int value;
    
    printf("Enter root value: ");
    scanf("%d", &value);

    struct Node* root = createNode(value);
    enqueue(root);

    while (front <= rear) {
        struct Node* temp = dequeue();

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &leftVal);

        if (leftVal != -1) {
            temp->left = createNode(leftVal);
            enqueue(temp->left);
        }

        printf("Enter right child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &rightVal);

        if (rightVal != -1) {
            temp->right = createNode(rightVal);
            enqueue(temp->right);
        }
    }

    return root;
}

int main() {
    struct Node* root = buildTree();
    printf("Binary Tree constructed successfully.\n");
    return 0;
}