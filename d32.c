//Push and Pop in Stack
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Push operation */
void push(int value) {
    if (top == MAX - 1) {
        return; // Stack overflow (ignored for this problem)
    }
    stack[++top] = value;
}

/* Pop operation */
void pop() {
    if (top == -1) {
        return; // Stack underflow (ignored for this problem)
    }
    top--;
}

int main() {
    int n, m, i, x;

    // Read number of elements to push
    scanf("%d", &n);

    // Push n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Read number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}