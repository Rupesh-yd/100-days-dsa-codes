//Polynomial Using Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->exp > 1)
            printf("%dx^%d", temp->coeff, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%d", temp->coeff);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node* poly = NULL;
    int n, coeff, exp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    printPolynomial(poly);
    return 0;
}