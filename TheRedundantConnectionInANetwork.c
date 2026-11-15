#include <stdio.h>

#define MAX 100

int parent[MAX];
int rankValue[MAX];

void initialize(int n) {

    for (int i = 1; i <= n; i++) {

        parent[i] = i;
        rankValue[i] = 0;
    }
}

int findParent(int node) {

    if (parent[node] != node) {

        // Path compression
        parent[node] =
            findParent(parent[node]);
    }

    return parent[node];
}

int unionNodes(int u, int v) {

    int rootU = findParent(u);
    int rootV = findParent(v);

    // Already in same component
    if (rootU == rootV) {
        return 0;
    }

    // Union by rank
    if (rankValue[rootU] < rankValue[rootV]) {

        parent[rootU] = rootV;

    } else if (rankValue[rootU] > rankValue[rootV]) {

        parent[rootV] = rootU;

    } else {

        parent[rootV] = rootU;
        rankValue[rootU]++;
    }

    return 1;
}

void findRedundantConnection(
    int edges[][2],
    int edgeCount,
    int n) {

    initialize(n);

    for (int i = 0; i < edgeCount; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionNodes(u, v)) {

            printf("Redundant connection: %d - %d\n",
                   u, v);

            return;
        }
    }

    printf("No redundant connection exists.\n");
}

int main() {

    int n = 5;

    int edges[][2] = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 5},
        {4, 5}
    };

    int edgeCount =
        sizeof(edges) / sizeof(edges[0]);

    findRedundantConnection(
        edges,
        edgeCount,
        n
    );

    return 0;
}