//Find Intersection Point of Two Linked Lists
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    }
    else {
        while (diff--) head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}
int main() {
    int n, m, i, x;
    struct Node *head1 = NULL, *head2 = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head1, x);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        insertEnd(&head2, x);
    }
    struct Node* temp1 = head1;
    while (temp1->data != 30)
        temp1 = temp1->next;

    struct Node* temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp1;  // intersection created
    struct Node* result = findIntersection(head1, head2);
    if (result != NULL)
        printf("%d", result->data);
    else
        printf("No Intersection");
    return 0;
}