//Cycle Detection in Directed Graph
#include <stdio.h>
#include <stdbool.h>

#define V 4

bool dfs(int node, bool visited[], bool recStack[], int graph[V][V]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {  // edge exists
            if (!visited[i] && dfs(i, visited, recStack, graph))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

bool hasCycle(int graph[V][V]) {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, graph))
                return true;
        }
    }
    return false;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},  // cycle: 0 → 1 → 2 → 0
        {0, 0, 0, 0}
    };

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}