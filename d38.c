//Deque Operations
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(Deque* dq, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = dq->front;

    if (dq->front != NULL)
        dq->front->prev = temp;
    else
        dq->rear = temp;

    dq->front = temp;
    dq->size++;
}

void push_back(Deque* dq, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = dq->rear;

    if (dq->rear != NULL)
        dq->rear->next = temp;
    else
        dq->front = temp;

    dq->rear = temp;
    dq->size++;
}

void pop_front(Deque* dq) {
    if (dq->front == NULL) return;

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

void pop_back(Deque* dq) {
    if (dq->rear == NULL) return;

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

int front(Deque* dq) {
    if (dq->front == NULL) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if (dq->rear == NULL) return -1;
    return dq->rear->data;
}

int empty(Deque* dq) {
    return dq->size == 0;
}

int size(Deque* dq) {
    return dq->size;
}

void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

void display(Deque* dq) {
    Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    push_back(dq, 30);

    display(dq);

    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));
    printf("Size: %d\n", size(dq));

    pop_front(dq);
    pop_back(dq);

    display(dq);

    clear(dq);
    printf("Empty: %d\n", empty(dq));

    return 0;
}