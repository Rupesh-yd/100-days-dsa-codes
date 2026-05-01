//Topological Sort (DFS)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;

// Push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int v, int visited[], int adj[MAX][MAX], int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological Sort
void topologicalSort(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    // Print in reverse order (stack pop)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n = 6;

    int adj[MAX][MAX] = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(adj, n);

    return 0;
}