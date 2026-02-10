#include <stdio.h>

#define MAX 10

int visited[MAX];

// DFS function to detect cycle
int isCycleDFS(int graph[MAX][MAX], int node, int parent, int n) {

    visited[node] = 1;

    for (int i = 0; i < n; i++) {

        // If edge exists
        if (graph[node][i] == 1) {

            // If not visited, do DFS
            if (!visited[i]) {
                if (isCycleDFS(graph, i, node, n))
                    return 1;
            }

            // If visited and not parent → cycle found
            else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {

    int n = 4;

    // Graph with cycle
    int graph[MAX][MAX] = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0}
    };

    if (isCycleDFS(graph, 0, -1, n))
        printf("Cycle Detected in Graph");
    else
        printf("No Cycle in Graph");

    return 0;
}
