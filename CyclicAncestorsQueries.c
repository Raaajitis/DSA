#include <stdio.h>

#define MAXN 100005
#define LOG 18

int up[MAXN][LOG];
int depth[MAXN];
int value[MAXN];
int parent[MAXN];

int kthAncestor(int u, int k) {

    for (int i = 0; i < LOG; i++) {

        if (k & (1 << i))
            u = up[u][i];
    }

    return u;
}

int main() {

    int n, q;

    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++)
        scanf("%d", &value[i]);

    parent[1] = 1;

    for (int i = 2; i <= n; i++)
        scanf("%d", &parent[i]);

    depth[1] = 0;

    for (int i = 2; i <= n; i++)
        depth[i] = depth[parent[i]] + 1;

    for (int i = 1; i <= n; i++)
        up[i][0] = parent[i];

    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    while (q--) {

        int u, k;

        scanf("%d%d", &u, &k);

        int cycle = depth[u] + 1;

        k %= cycle;

        int ans = kthAncestor(u, k);

        printf("%d\n", value[ans]);
    }

    return 0;
}