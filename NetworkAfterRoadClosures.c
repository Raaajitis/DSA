#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u;
    int v;
} Edge;

int findRoot(int *parent, int node) {
    if (parent[node] != node) {
        parent[node] = findRoot(parent, parent[node]);
    }

    return parent[node];
}

int unite(
    int *parent,
    int *size,
    int first,
    int second
) {
    int rootFirst = findRoot(parent, first);
    int rootSecond = findRoot(parent, second);

    if (rootFirst == rootSecond) {
        return 0;
    }

    if (size[rootFirst] < size[rootSecond]) {
        int temporary = rootFirst;
        rootFirst = rootSecond;
        rootSecond = temporary;
    }

    parent[rootSecond] = rootFirst;
    size[rootFirst] += size[rootSecond];

    return 1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = malloc((m + 1) * sizeof(Edge));

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    int q;
    scanf("%d", &q);

    int *removedRoads = malloc(q * sizeof(int));
    char *willBeRemoved = calloc(m + 1, sizeof(char));

    for (int i = 0; i < q; i++) {
        scanf("%d", &removedRoads[i]);
        willBeRemoved[removedRoads[i]] = 1;
    }

    int *parent = malloc((n + 1) * sizeof(int));
    int *size = malloc((n + 1) * sizeof(int));
    int *answer = malloc(q * sizeof(int));

    for (int city = 1; city <= n; city++) {
        parent[city] = city;
        size[city] = 1;
    }

    int components = n;

    /*
     * Add every road that remains after all closures.
     */
    for (int i = 1; i <= m; i++) {
        if (!willBeRemoved[i]) {
            if (unite(
                    parent,
                    size,
                    edges[i].u,
                    edges[i].v
                )) {
                components--;
            }
        }
    }

    /*
     * Reverse the closures and add roads back.
     */
    for (int i = q - 1; i >= 0; i--) {
        /*
         * This is the component count after closure i.
         */
        answer[i] = components;

        int roadIndex = removedRoads[i];

        if (unite(
                parent,
                size,
                edges[roadIndex].u,
                edges[roadIndex].v
            )) {
            components--;
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", answer[i]);
    }

    free(edges);
    free(removedRoads);
    free(willBeRemoved);
    free(parent);
    free(size);
    free(answer);

    return 0;
}