#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int V) {

    visited[node] = 1;

    for (int i = 0; i < V; i++) {

        if (adj[node][i]) {

            if (!visited[i]) {
                if (dfs(i, node, V))
                    return 1;
            }
            else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

int hasCycle(int V) {

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V))
                return 1;
        }
    }
    return 0;
}

int main() {

    int V = 3;

    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][0] = adj[0][2] = 1;

    if (hasCycle(V))
        printf("Cycle Exists\n");
    else
        printf("No Cycle\n");

    return 0;
}