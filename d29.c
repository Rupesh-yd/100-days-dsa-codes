//Rotate Linked List Right by k Places
#include <stdio.h>
#include <stdlib.h>

// Definition of the node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Rotate list to the right by k places
void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k == 0)
        return;

    struct Node* temp = *head;
    int count = 1;

    // Find last node and count nodes
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Make list circular
    temp->next = *head;

    // Effective rotations
    k = k % count;
    int stepsToNewHead = count - k;

    struct Node* newTail = *head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Set new head and break the circle
    *head = newTail->next;
    newTail->next = NULL;
}

// Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, value;
    struct Node* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input node values
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Input k
    scanf("%d", &k);

    // Rotate the list
    rotateRight(&head, k);

    // Output the rotated list
    printList(head);

    return 0;
}