#include <stdio.h>

#define MAX 10
#define INF 9999

// Find node with minimum distance
int minDistance(int dist[], int visited[], int n) {

    int min = INF, index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

// Dijkstra Algorithm
void dijkstra(int graph[MAX][MAX], int source, int n) {

    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Main loop
    for (int count = 0; count < n - 1; count++) {

        int u = minDistance(dist, visited, n);

        visited[u] = 1;

        // Update distances of neighbours
        for (int v = 0; v < n; v++) {

            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Shortest distances from node %d:\n", source);

    for (int i = 0; i < n; i++) {
        printf("To node %d = %d\n", i, dist[i]);
    }
}

int main() {

    int n = 3;

    // Weighted adjacency matrix
    int graph[MAX][MAX] = {
        {0,1,4},
        {1,0,2},
        {4,2,0}
    };

    dijkstra(graph, 0, n);

    return 0;
}
