#include <stdio.h>

#define MAX 10

int visited[MAX];

// DFS function
void dfs(int graph[MAX][MAX], int start, int n) {

    printf("%d ", start);
    visited[start] = 1;

    // Visit all adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            dfs(graph, i, n);
        }
    }
}

int main() {

    int n = 5;

    // Adjacency Matrix
    int graph[MAX][MAX] = {
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {0,1,0,1,0}
    };

    printf("DFS Traversal: ");
    dfs(graph, 0, n);

    return 0;
}
