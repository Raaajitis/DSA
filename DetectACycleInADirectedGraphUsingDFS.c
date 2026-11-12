#include <stdio.h>

#define V 4

int dfsCycle(int graph[V][V],
             int vertex,
             int visited[],
             int recursionStack[]) {

    visited[vertex] = 1;
    recursionStack[vertex] = 1;

    for (int neighbor = 0;
         neighbor < V;
         neighbor++) {

        if (graph[vertex][neighbor] == 1) {

            // Unvisited neighbor
            if (!visited[neighbor]) {

                if (dfsCycle(graph,
                             neighbor,
                             visited,
                             recursionStack)) {

                    return 1;
                }
            }

            // Neighbor belongs to current DFS path
            else if (recursionStack[neighbor]) {

                return 1;
            }
        }
    }

    // Remove vertex from current DFS path
    recursionStack[vertex] = 0;

    return 0;
}

int containsCycle(int graph[V][V]) {

    int visited[V] = {0};
    int recursionStack[V] = {0};

    for (int i = 0; i < V; i++) {

        if (!visited[i]) {

            if (dfsCycle(graph,
                         i,
                         visited,
                         recursionStack)) {

                return 1;
            }
        }
    }

    return 0;
}

int main() {

    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 0, 0}
    };

    if (containsCycle(graph)) {

        printf("Cycle detected.\n");

    } else {

        printf("No cycle detected.\n");
    }

    return 0;
}