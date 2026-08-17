#include <stdio.h>

#define MAXN 100005

typedef struct {
    int to;
    int strength;
    int next;
} Edge;

Edge edges[2 * MAXN];
int head[MAXN];
int edgeCount = 0;

int answer[MAXN];

void addEdge(int u, int v, int strength) {
    edges[edgeCount].to = v;
    edges[edgeCount].strength = strength;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

void dfs(int u, int parent, int minStrength) {

    /*
     * For the root, there is no bridge on its path.
     */
    if (u == 1)
        answer[u] = -1;
    else
        answer[u] = minStrength + 1;

    for (int e = head[u]; e != -1; e = edges[e].next) {

        int v = edges[e].to;

        if (v == parent)
            continue;

        int newMin = minStrength;

        if (edges[e].strength < newMin)
            newMin = edges[e].strength;

        dfs(v, u, newMin);
    }
}

int main() {

    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < n - 1; i++) {

        int u, v, strength;

        scanf("%d %d %d", &u, &v, &strength);

        addEdge(u, v, strength);
        addEdge(v, u, strength);
    }

    /*
     * Start with a very large minimum strength.
     */
    dfs(1, 0, 1000000000);

    for (int i = 1; i <= n; i++) {

        if (answer[i] == -1)
            printf("Never\n");
        else
            printf("%d\n", answer[i]);
    }

    return 0;
}