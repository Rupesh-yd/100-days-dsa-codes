//Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, x, count = 0;
    struct Node *head = NULL, *temp = NULL, *newnode;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &x);
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }
    return 0;
}