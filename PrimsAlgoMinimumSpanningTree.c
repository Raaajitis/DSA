#include <stdio.h>

#define MAX 10
#define INF 9999

// Find minimum key vertex
int minKey(int key[], int mstSet[], int n) {

    int min = INF, index = -1;

    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }

    return index;
}

// Prim’s MST Algorithm
void primMST(int graph[MAX][MAX], int n) {

    int parent[MAX];   // Store MST
    int key[MAX];      // Minimum weights
    int mstSet[MAX];   // Track included vertices

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    // Build MST
    for (int count = 0; count < n - 1; count++) {

        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {

            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    printf("Edges in Prim's MST:\n");

    for (int i = 1; i < n; i++) {
        printf("%d - %d  Weight: %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {

    int n = 3;

    int graph[MAX][MAX] = {
        {0,1,4},
        {1,0,2},
        {4,2,0}
    };

    primMST(graph, n);

    return 0;
}
