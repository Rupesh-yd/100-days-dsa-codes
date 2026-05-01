//Dijkstraâ€™s Algorithm (Shortest Path)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for priority queue node
typedef struct {
    int vertex;
    int distance;
} Node;

// Min Heap
Node heap[MAX];
int size = 0;

// Swap function
void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].distance > heap[i].distance) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].distance < heap[smallest].distance)
        smallest = left;
    if (right < size && heap[right].distance < heap[smallest].distance)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].distance = d;
    heapifyUp(size);
    size++;
}

// Extract min
Node pop() {
    Node root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Check if heap empty
int isEmpty() {
    return size == 0;
}

// Graph using adjacency matrix
int graph[MAX][MAX];

void dijkstra(int V, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        Node current = pop();
        int u = current.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    push(v, dist[v]);
                }
            }
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("To %d -> %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5;

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    // Example graph (weighted)
    graph[0][1] = 10;
    graph[0][4] = 5;
    graph[1][2] = 1;
    graph[1][4] = 2;
    graph[2][3] = 4;
    graph[3][0] = 7;
    graph[3][2] = 6;
    graph[4][1] = 3;
    graph[4][2] = 9;
    graph[4][3] = 2;

    dijkstra(V, 0);

    return 0;
}