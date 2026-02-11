#include <stdio.h>

#define MAX 10

int visited[MAX];
int stack[MAX];
int top = -1;

// Push into stack
void push(int value) {
    stack[++top] = value;
}

// DFS for Topological Sort
void topoDFS(int graph[MAX][MAX], int node, int n) {

    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            topoDFS(graph, i, n);
        }
    }

    // Push after visiting all neighbours
    push(node);
}

int main() {

    int n = 6;

    // Directed Graph (DAG)
    int graph[MAX][MAX] = {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,0,0},
        {0,1,0,0,0,0},
        {1,0,1,0,0,0}
    };

    // Run DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoDFS(graph, i, n);
        }
    }

    printf("Topological Order: ");

    // Print stack in reverse order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
