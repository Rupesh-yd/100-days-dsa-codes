//Graph Representation Using Adjacency Matrix
#include <stdio.h>

#define MAX 100

int main() {
    int adj[MAX][MAX];
    int n, m, i, j, u, v;
    int isDirected;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Choose graph type
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &isDirected);

    // Initialize adjacency matrix with 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(!isDirected) {
            adj[v][u] = 1;
        }
    }

    // Output adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}