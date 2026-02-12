#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Edge structure
struct Edge {
    int u, v, w;
};

// Find parent (Union-Find)
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

// Union function
void unionSet(int parent[], int a, int b) {
    int rootA = findParent(parent, a);
    int rootB = findParent(parent, b);
    parent[rootA] = rootB;
}

// Sort edges by weight
void sortEdges(struct Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal Algorithm
void kruskalMST(struct Edge edges[], int v, int e) {

    int parent[MAX];

    // Initialize parent array
    for (int i = 0; i < v; i++)
        parent[i] = i;

    sortEdges(edges, e);

    printf("Edges in Kruskal's MST:\n");

    for (int i = 0; i < e; i++) {

        int u = edges[i].u;
        int v2 = edges[i].v;

        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v2);

        // If no cycle, include edge
        if (rootU != rootV) {
            printf("%d - %d  Weight: %d\n", u, v2, edges[i].w);
            unionSet(parent, rootU, rootV);
        }
    }
}

int main() {

    int vertices = 3;
    int edgesCount = 3;

    struct Edge edges[] = {
        {0, 1, 1},
        {1, 2, 2},
        {0, 2, 4}
    };

    kruskalMST(edges, vertices, edgesCount);

    return 0;
}
