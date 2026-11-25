#include <stdio.h>

#define V 5

int timer = 0;

void findBridgesDFS(
    int graph[V][V],
    int current,
    int parent,
    int visited[],
    int discovery[],
    int low[]) {

    visited[current] = 1;

    discovery[current] = timer;
    low[current] = timer;

    timer++;

    for (int neighbor = 0;
         neighbor < V;
         neighbor++) {

        if (graph[current][neighbor] == 0) {
            continue;
        }

        // Do not immediately return to parent
        if (neighbor == parent) {
            continue;
        }

        if (!visited[neighbor]) {

            findBridgesDFS(
                graph,
                neighbor,
                current,
                visited,
                discovery,
                low
            );

            // Update low value
            if (low[neighbor] < low[current]) {

                low[current] = low[neighbor];
            }

            // Bridge condition
            if (low[neighbor] >
                discovery[current]) {

                printf("%d - %d\n",
                       current,
                       neighbor);
            }
        }

        else {

            // Back edge
            if (discovery[neighbor] <
                low[current]) {

                low[current] =
                    discovery[neighbor];
            }
        }
    }
}

void findBridges(int graph[V][V]) {

    int visited[V] = {0};
    int discovery[V];
    int low[V];

    timer = 0;

    printf("Bridges in the graph:\n");

    for (int i = 0; i < V; i++) {

        if (!visited[i]) {

            findBridgesDFS(
                graph,
                i,
                -1,
                visited,
                discovery,
                low
            );
        }
    }
}

int main() {

    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    findBridges(graph);

    return 0;
}