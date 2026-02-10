#include <stdio.h>

#define MAX 10

int visited[MAX];

// DFS traversal
void dfs(int graph[MAX][MAX], int node, int n) {

    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, i, n);
        }
    }
}

int main() {

    int n = 4;

    // Graph with 2 connected components
    int graph[MAX][MAX] = {
        {0,1,0,0},
        {1,0,0,0},
        {0,0,0,1},
        {0,0,1,0}
    };

    int components = 0;

    // Check each node
    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            components++;
            dfs(graph, i, n);
        }
    }

    printf("Connected Components: %d", components);

    return 0;
}
