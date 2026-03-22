#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];

int dfs(int node, int V) {

    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {

        if (adj[node][i]) {

            if (!visited[i] && dfs(i, V))
                return 1;

            else if (recStack[i])
                return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int canFinish(int V) {

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V))
                return 0;
        }
    }
    return 1;
}

int main() {

    int V = 2;

    adj[1][0] = 1;
    adj[0][1] = 1; // creates cycle

    if (canFinish(V))
        printf("Possible to finish all courses\n");
    else
        printf("Not Possible (Cycle detected)\n");

    return 0;
}