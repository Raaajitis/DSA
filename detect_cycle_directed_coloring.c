// File: detect_cycle_directed_coloring.c
#include <stdio.h>

int graph[20][20];
int visited[20];
int n;

int dfs(int node) {
    visited[node] = 1; // visiting

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (visited[i] == 1) 
                return 1; // back-edge

            if (visited[i] == 0 && dfs(i))
                return 1;
        }
    }

    visited[node] = 2;
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++)
        if (visited[i] == 0)
            if (dfs(i))
                return 1;
    return 0;
}

int main() {
    n = 4;
    int g[4][4] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {1,0,0,0}  // creates a cycle
    };

    // copy
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=g[i][j];

    if (hasCycle()) printf("Cycle Found\n");
    else printf("No Cycle\n");

    return 0;
}