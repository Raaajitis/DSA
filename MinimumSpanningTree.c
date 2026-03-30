#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, weight;
};

int parent[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Edge edges[], int V, int E) {

    qsort(edges, E, sizeof(struct Edge), compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;

    for (int i = 0; i < E; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("Edge: %d - %d\n", u, v);
            totalCost += edges[i].weight;
            unionSet(u, v);
        }
    }

    printf("Total Cost: %d\n", totalCost);
}

int main() {

    struct Edge edges[] = {
        {0,1,4}, {0,2,3}, {1,2,1},
        {1,3,2}, {2,3,4}
    };

    int V = 4;
    int E = 5;

    kruskal(edges, V, E);

    return 0;
}