#include <stdio.h>
#include <limits.h>

#define V 4

int findMinimumVertex(int distance[],
                      int visited[]) {

    int minimum = INT_MAX;
    int vertex = -1;

    for (int i = 0; i < V; i++) {

        if (!visited[i] &&
            distance[i] < minimum) {

            minimum = distance[i];
            vertex = i;
        }
    }

    return vertex;
}

void dijkstra(int graph[V][V], int source) {

    int distance[V];
    int visited[V];

    for (int i = 0; i < V; i++) {

        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int count = 0; count < V; count++) {

        int u =
            findMinimumVertex(distance, visited);

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] != 0 &&
                distance[u] != INT_MAX) {

                int newDistance =
                    distance[u] + graph[u][v];

                if (newDistance < distance[v]) {

                    distance[v] = newDistance;
                }
            }
        }
    }

    printf("Vertex\tShortest Distance\n");

    for (int i = 0; i < V; i++) {

        printf("%d\t", i);

        if (distance[i] == INT_MAX) {
            printf("Unreachable\n");
        }
        else {
            printf("%d\n", distance[i]);
        }
    }
}

int main() {

    int graph[V][V] = {

        {0, 4, 1, 0},
        {4, 0, 0, 1},
        {1, 0, 0, 2},
        {0, 1, 2, 0}

    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}