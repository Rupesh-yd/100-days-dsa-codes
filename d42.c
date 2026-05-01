//Reverse a Queue Using Stack
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int N;
    scanf("%d", &N);

    int queue[MAX];
    int stack[MAX];
    int top = -1;

    // Input queue elements
    for(int i = 0; i < N; i++){
        scanf("%d", &queue[i]);
    }

    // Push queue elements into stack
    for(int i = 0; i < N; i++){
        stack[++top] = queue[i];
    }

    // Pop from stack back to queue
    int index = 0;
    while(top >= 0){
        queue[index++] = stack[top--];
    }

    // Print reversed queue
    for(int i = 0; i < N; i++){
        printf("%d ", queue[i]);
    }

    return 0;
}