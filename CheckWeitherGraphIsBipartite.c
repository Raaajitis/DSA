#include <stdio.h>

#define V 4

int isBipartite(int graph[V][V]) {

    int color[V];

    // -1 means not colored
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    int queue[V];

    // Check every component
    for (int start = 0; start < V; start++) {

        if (color[start] != -1) {
            continue;
        }

        int front = 0;
        int rear = 0;

        color[start] = 0;
        queue[rear++] = start;

        while (front < rear) {

            int current = queue[front++];

            for (int neighbor = 0;
                 neighbor < V;
                 neighbor++) {

                if (graph[current][neighbor] == 1) {

                    // Neighbor has not been colored
                    if (color[neighbor] == -1) {

                        color[neighbor] =
                            1 - color[current];

                        queue[rear++] = neighbor;
                    }

                    // Same colors on adjacent vertices
                    else if (color[neighbor] ==
                             color[current]) {

                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

int main() {

    int graph[V][V] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (isBipartite(graph)) {

        printf("The graph is bipartite.\n");

    } else {

        printf("The graph is not bipartite.\n");
    }

    return 0;
}