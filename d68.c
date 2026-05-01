//Topological Sort (Kahnâ€™s BFS Algorithm)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int V) {
    int i, j;
    int topo[MAX];
    int count = 0;

    // Step 1: Calculate indegree
    for (i = 0; i < V; i++) {
        indegree[i] = 0;
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Enqueue nodes with indegree 0
    for (i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    // Step 3: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != V) {
        printf("Cycle detected! Topological sort not possible\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for (i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int V = 6;

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Example edges
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V);

    return 0;
}